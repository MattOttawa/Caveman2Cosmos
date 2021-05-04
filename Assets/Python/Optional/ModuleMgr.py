from CvPythonExtensions import *
import SystemPaths as SP
import os
import ConfigParser

def init():
	if not os.path.isfile(getIniFilePath()):
		Parser = createIniFile()
	else:
		Parser = updateIniFile()

	initModules(Parser)

def initModules(Parser):
	for module in getModules():
		if Parser.getboolean("MODULES", module):
			call(module, "init")

def getModules():
	return (
		module[:len(module) -3]
		for module in os.listdir(os.path.join(getModDir(), "Assets", "Python", "Optional"))
		if module != __name__ + ".py"
	)

def call(module, method):
	try:
		func = getattr(__import__(module), method)
		func()
	except:
		CyPythonMgr().errorMsg("Call failed: %s.%s" %(module, method))

def createIniFile():
	Parser = ConfigParser.SafeConfigParser()
	Parser.add_section("MODULES")
	for module in getModules():
		Parser.set("MODULES", module, "1")
	writeIniFile(Parser)
	return Parser

def updateIniFile():
	modules = getModules()
	Parser = readIniFile()

	for name in Parser.options("MODULES"):
		if not name in modules:
			Parser.remove_option("MODULES", name)

	for module in modules:
		if not Parser.has_option("MODULES", module):
			Parser.set("MODULES", module, "1")

	writeIniFile(Parser)
	return Parser

def readIniFile():
	Parser = ConfigParser.SafeConfigParser()
	Parser.read()
	return Parser

def writeIniFile(Parser):
	file = open(getIniFilePath(), 'w')
	Parser.write(file)
	file.close()

def getIniFilePath():
	return os.path.join(getModDir(), "PythonModules.ini")
	#return os.path.join(SP.userSettingsDir, "PythonModules.ini")

def handleOptionChange(bValue, module):
	Parser = readIniFile()
	if bValue:
		Parser.set("MODULES", module, "1")
		call(module, "init")
	else:
		Parser.set("MODULES", module, "0")
		call(module, "uninit")

	writeIniFile(Parser)