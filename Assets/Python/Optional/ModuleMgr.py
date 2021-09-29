from CvPythonExtensions import *
from CvEventInterface import getEventManager
import SystemPaths as SP
import os
import ConfigParser

GAME = CyGame()

def init():
	if not os.path.isfile(getIniFilePath()):
		Parser = createIniFile()
	else:
		Parser = updateIniFile()

	GAME.log("logging ini options")
	for name in Parser.options("MODULES"):
		GAME.log(name)

	initModules(Parser)

def initModules(Parser):
	EventManager = getEventManager()
	GAME.log("logging modules")
	for module in getModules():
		GAME.log(module)
		if Parser.getboolean("MODULES", module):
			call(module, "init", EventManager)

def getModules():
	return (
		#module[:len(module) -3]
		module[:-3]
		for module in os.listdir(os.path.join(getModDir(), "Assets", "Python", "Optional"))
		if module != __name__ + ".py"
	)

def call(module, method, *args):
	try:
		func = getattr(__import__(module), method)
		func(*args)
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
			GAME.log("Removing option: %s" %name)
			Parser.remove_option("MODULES", name)

	for module in modules:
		if not Parser.has_option("MODULES", module):
			GAME.log("Adding option: %s" %module)
			Parser.set("MODULES", module, "1")

	writeIniFile(Parser)
	return Parser

def readIniFile():
	Parser = ConfigParser.SafeConfigParser()
	Parser.read(getIniFilePath())
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
		call(module, "init", getEventManager())
	else:
		Parser.set("MODULES", module, "0")
		call(module, "uninit", getEventManager())

	writeIniFile(Parser)
