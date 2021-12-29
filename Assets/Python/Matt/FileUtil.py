from CvPythonExtensions import *
import SystemPaths as SP
import os.path
import glob


def verifyModDir(szModPath):
    git_directory = os.path.join(szModPath, "git_directory.txt")
    if os.path.isfile(git_directory):
        pFile = open(git_directory)
        szModPath = pFile.read().rstrip("\n")
        pFile.close()
    return szModPath

#g_ModPath = verifyModDir(SP.modDir)


dllFiles = [
	"CyAreaInterface.cpp",
	"CyArtFileMgrInterface.cpp",
	"CyCityInterface1.cpp",
	"CyCityInterface2.cpp",
	"CyGameInterface.cpp",
	"CyGameTextMgrInterface.cpp",
	"CyGlobalContextInterface1.cpp",
	"CyGlobalContextInterface2.cpp",
	"CyGlobalContextInterface3.cpp",
	"CyGlobalContextInterface4.cpp",
	"CyHallOfFameInterface.cpp",
	"CyInfoInterface1.cpp",
	"CyInfoInterface2.cpp",
	"CyInfoInterface3.cpp",
	"CyInfoInterface4.cpp",
	"CyMapGeneratorInterface.cpp",
	"CyMapInterface.cpp",
	"CyMessageControlInterface.cpp",
	"CyPlayerInterface1.cpp",
	"CyPlayerInterface2.cpp",
	"CyPlayerInterface3.cpp",
	"CyPlotInterface1.cpp",
	#"CyPropertiesInterface.cpp",
	"CySelectionGroupInterface.cpp",
	"CyTeamInterface.cpp",
	"CyUnitInterface1.cpp"
]

def init():
	szModPath = getModDir()
	logFile = open(os.path.join(szModPath, "Assets", "Python", "Matt", "log.txt"), "w")

	PythonFiles  = getGlob(os.path.join(szModPath, "Assets", "Python"))
	PythonFiles += getGlob(os.path.join(szModPath, "PrivateMaps"))

	for fileName in dllFiles:
		path = os.path.join(szModPath, "Sources", fileName)
		pFile = open(path)
		usedFunctions = ""
		for line in pFile:
			functionName = getFunctionName(line)
			logFile.write(functionName + "\n")
			if len(functionName) == 0 or find(PythonFiles, "." + functionName + "("):
				usedFunctions += line
		pFile.close()

		newFile = open(path + ".new", "w")
		newFile.write(usedFunctions)
		newFile.close()

	logFile.close()


def getFunctionName(line):
	functionName = ""
	if line[2:7] == ".def(":
		position = 8
		while line[position] != "\"" and line[position] < len(line):
			functionName += line[position]
			position += 1
	return functionName


def getGlob(path):
	files  = glob.glob(os.path.join(path, "*.py"))
	files += glob.glob(os.path.join(path, "**", "*.py"))
	files += glob.glob(os.path.join(path, "**", "**", "*.py"))
	return files


def find(files, chars):
	for file in files:
		for line in open(file):
			if chars in line:
				return True
	return False

