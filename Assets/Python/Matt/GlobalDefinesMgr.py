##  $Header:
##------------------------------------------------------------------------------------------------
##
##  FILE:	GlobalDefinesMgr.py
##
##  PURPOSE: Civ4 game variables system.
##
##------------------------------------------------------------------------------------------------
from CvPythonExtensions import *
import SystemPaths as SP
import os.path
import codecs
import CvUtil


def verifyModDir(szModPath):
    git_directory = os.path.join(szModPath, "git_directory.txt")
    if os.path.isfile(git_directory):
        pFile = open(git_directory)
        szModPath = pFile.read().rstrip("\n")
        pFile.close()
    return szModPath

g_szModPath = verifyModDir(SP.modDir)


def getFile(szFileName, purpose = "r"):
	""" Wrapper for Python's open method. """
	return codecs.open(os.path.join(g_szModPath, szFileName), purpose, 'utf-8')


def buildCache():
	""" Create lists of variable names and corresponding values. """
	lVarsINT    = []
	lVarsFLOAT  = []
	lVarsSTRING = []
	lVarsBOOL   = []

	VS = CyVariableSystem()
	loopVar = VS.getFirstVariableName()
	while loopVar:
		szDataType = VS.getVariableType(loopVar)

		if szDataType == "int":
			lVarsINT.append(GlobalDefine(loopVar, VS.getValueInt(loopVar)))

		elif szDataType == "float":
			lVarsFLOAT.append(GlobalDefine(loopVar, VS.getValueFloat(loopVar)))

		elif szDataType == "string":
			lVarsSTRING.append(GlobalDefine(loopVar, VS.getValueString(loopVar)))

		else:
			try:
				lVarsBOOL.append(GlobalDefine(loopVar, bool(VS.getValueInt(loopVar))))
			except:
				CvUtil.sendImmediateMessage("Unsupported data type for global define: %s (%s)" %(loopVar, szDataType))

		loopVar = VS.getNextVariableName()

	return (lVarsINT, lVarsFLOAT, lVarsSTRING, lVarsBOOL)


class GlobalDefine:
	""" Abstract class of a global define. """
	def __init__(self, szName, value, bHardcode = False):
		self.szName = szName
		self.value = value
		self.bHardcode = bHardcode

	def hardcodeValue(self, pMgr):
		if self.bHardcode:
			pMgr.addHardcodeDefine("#define DEF_%s %s\n" %(self.szName, self.value))
		return self.bHardcode


def writeDefines():
	""" Write sources files for the global defines. """
	lVarsINT, lVarsFLOAT, lVarsSTRING, lVarsBOOL = buildCache()
	pDllClassMgr = DllClassMgr("GameConstants")

	for loopVar in lVarsINT:
		if not loopVar.hardcodeValue(pDllClassMgr):
			pDllClassMgr.addMember(loopVar.szName, "int", "i", "INT", getIntegerType(loopVar.value))

	for loopVar in lVarsFLOAT:
		if not loopVar.hardcodeValue(pDllClassMgr):
			pDllClassMgr.addMember(loopVar.szName, "float", "f", "FLOAT", "float")

	for loopVar in lVarsSTRING:
		if not loopVar.hardcodeValue(pDllClassMgr):
			pDllClassMgr.addMember(loopVar.szName, "const char*", "sz", "STRING", "const char*")

	for loopVar in lVarsBOOL:
		if not loopVar.hardcodeValue(pDllClassMgr):
			pDllClassMgr.addMember(loopVar.szName, "bool", "b", "BOOL", "bool")

	pDllClassMgr.writeFiles()
	CvUtil.sendImmediateMessage("Done re-writing the global defines source files.")


def getIntegerType(int):
	""" Look for a type modifier that uses less bytes while still being sufficient to hold int. """
	MAX_CHAR = 127
	MAX_SHORT = 32767
	if int < 0:
		if int > -MAX_CHAR:		return "int8_t"
		if int > -MAX_SHORT:	return "int16_t"
	else:
		if int < MAX_CHAR:		return "int8_t"
		if int < MAX_CHAR * 2:	return "uint8_t"
		if int < MAX_SHORT:		return "int16_t"
		if int < MAX_SHORT * 2:	return "uint16_t"

	return "int32_t"


class DllClassMgr:
	""" Create a class for runtime modifiable variables. """
	def __init__(self, szClassName):
		self.szClassName = "Cv" + szClassName
		self.szConstructor = "%s::%s() :\n" %(self.szClassName, self.szClassName)
		self.szCacheFunction = "void %s::cacheGlobalDefinesXml()\n{\n" %(self.szClassName)
		self.szPublicMethods = ""
		self.szMethodHeaders = ""
		self.szVariableHeaders = ""
		self.szMacroDefines = ""
		self.szHardcodeDefines = ""

		self.cppFile = getFile(self.szClassName + ".cpp", "w")
		self.cppFile.write("#include \"CvGameCoreDLL.h\"\n\n")

		self.hFile = getFile(self.szClassName + ".h", "w")
		self.hFile.write("#pragma once\n\n")
		self.hFile.write("#ifndef CIV4_GAME_DEFINES_H\n")
		self.hFile.write("#define CIV4_GAME_DEFINES_H\n\n")
		self.hFile.write("class %s\n{\n" %(self.szClassName))
		self.hFile.write("public:\n")
		self.hFile.write("\t%s();\n" %(self.szClassName))
		self.hFile.write("\tvoid cacheGlobalDefinesXML();\n\n")

	def addHardcodeDefine(self, szLine):
		self.szHardcodeDefines += szLine

	def addMember(self, szName, szDataType, prefix, szAllCapsName, szModifiedType):
		self.szConstructor += "m_%s%s(getDefine%s(\"%s\")),\n" %(prefix, szName, szAllCapsName, szName)

		self.szCacheFunction += "\tm_%s%s = getDefine%s(\"%s\");\n" %(prefix, szName, szAllCapsName, szName)

		self.szPublicMethods += "void %s::set%s(%s %sValue) {\n" %(self.szClassName, szName, szDataType, prefix)
		self.szPublicMethods += "\tm_%s%s = %sValue;\n" %(prefix, szName, prefix)
		self.szPublicMethods += "}\n\n"

		self.szPublicMethods += "%s %s::get%s() const {\n" %(szDataType, self.szClassName, szName)
		self.szPublicMethods += "\treturn m_%s%s;\n" %(prefix, szName)
		self.szPublicMethods += "}\n\n"

		self.szMethodHeaders += "\tvoid set%s(%s %sValue);\n" %(szName, szDataType, prefix)
		self.szMethodHeaders += "\t%s get%s() const;\n\n" %(szDataType, szName)

		self.szVariableHeaders += "\t%s m_%s%s;\n" %(szModifiedType, prefix, szName)

		self.szMacroDefines += "#define DEF_%s GC.getGameDefines().get%s()\n" %(szName, szName)

	def writeFiles(self):
		self.cppFile.write(self.szConstructor[0:len(self.szConstructor) -3] + "{}\n\n")
		self.cppFile.write(self.szCacheFunction + "}\n\n")
		self.cppFile.write(self.szPublicMethods)
		self.cppFile.close()

		self.hFile.write(self.szMethodHeaders)
		self.hFile.write("\nprotected:\n" + self.szVariableHeaders)
		self.hFile.write("};\n#endif\n\n")

		self.hFile.write(self.szMacroDefines + "\n")
		self.hFile.write(self.szHardcodeDefines + "\n")
		hardcodeGameOptions(self.hFile)
		self.hFile.close()


def hardcodeGameOptions(pFile):
	GC = CyGlobalContext()
	GAME = CyGame()
	numOptions = GC.getNumGameOptionInfos()

	a_bIncludeOption = []
	a_bAddRuntimeCheck = []
	for i in range(numOptions):
		a_bIncludeOption.append(True)
		a_bAddRuntimeCheck.append(True)

	for loopOption in range(numOptions):
		szName = GC.getGameOptionInfo(loopOption).getType()
		if a_bIncludeOption[i]:# and GAME.isOption(loopOption):
			pFile.write("#define INCLUDE_%s\n" %(szName))
			if a_bAddRuntimeCheck[i]:
				pFile.write("#define %s GC.getGame().isOption(\"%s\")\n" %(szName, szName))
			else:
				pFile.write("#define %s true\n" %(szName))

"""
	DllExport bool isMPOption(MultiplayerOptionTypes eIndex) const;
	void setMPOption(MultiplayerOptionTypes eIndex, bool bEnabled);

	int getModderGameOption(ModderGameOptionTypes eIndex) const;
	bool isModderGameOption(ModderGameOptionTypes eIndex) const;
	void setModderGameOption(ModderGameOptionTypes eIndex, bool bNewValue);
	void setModderGameOption(ModderGameOptionTypes eIndex, int iNewValue);
"""
