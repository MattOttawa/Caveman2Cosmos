## AutoSave
from CvPythonExtensions import CyGlobalContext
GC = CyGlobalContext()
GAME = GC.getGame()
MAP = GC.getMap()
import TextUtil
        


def remove_diacritics(in_text):
    # Table des remplacements (caract�res + codes explicites)
    #print "Start remove_diacritics for %s" % in_text
    #print "%s" % str(type(in_text))
    text = u''
    try :
		text = in_text.encode("utf-8")
    except :
		text = in_text.encode("ascii", "ignore")
    #print "%s" % text
    text = text.replace('�', 'a').replace('�', 'a').replace('�', 'a').replace('�', 'a').replace('�', 'a').replace('�', 'a')
    #print "%s" % text
    text = text.replace('�', 'c')
    text = text.replace('�', 'e').replace('�', 'e').replace('�', 'e').replace('�', 'e')
    text = text.replace('�', 'i').replace('�', 'i').replace('�', 'i')
    text = text.replace('�', 'o').replace('�', 'o').replace('�', 'o').replace('�', 'o').replace('�', 'o')
    text = text.replace('�', 'u').replace('�', 'u').replace('�', 'u').replace('�', 'u')
    text = text.replace('�', 'y')
    text = text.replace('�', 'n')

    text = text.replace('�', 'A').replace('�', 'A').replace('�', 'A').replace('�', 'A').replace('�', 'A').replace('�', 'A')
    text = text.replace('�', 'C')
    text = text.replace('�', 'E').replace('�', 'E').replace('�', 'E').replace('�', 'E')
    text = text.replace('�', 'I').replace('�', 'I').replace('�', 'I')
    text = text.replace('�', 'O').replace('�', 'O').replace('�', 'O').replace('�', 'O').replace('�', 'O')
    text = text.replace('�', 'U').replace('�', 'U').replace('�', 'U').replace('�', 'U')
    text = text.replace('�', 'Y')
    text = text.replace('�', 'N')

    #print "%s" % text
    return text
        
def cleanNpc():
	print "Cleaning NPC - for player 41 and 42..."
	iPlayer = 41
	pPlayer = GC.getPlayer(iPlayer)
	pUnit, loop = pPlayer.firstUnit(False)
	while pUnit:
		pUnit
		print "Player %d, Unit ID: %d, %s\n" % (iPlayer, pUnit.getID(), TextUtil.convertToStr(pUnit.getName()))
		pUnit.kill(False, -1)
		pUnit, loop = pPlayer.nextUnit(loop, False)
	print "Unit�s du joueur 41 supprim�es."
	
	iPlayer = 42
	pPlayer = GC.getPlayer(iPlayer)
	pUnit, loop = pPlayer.firstUnit(False)
	while pUnit:
		pUnit
		print "Player %d, Unit ID: %d, %s\n" % (iPlayer, pUnit.getID(), TextUtil.convertToStr(pUnit.getName()))
		pUnit.kill(False, -1)
		pUnit, loop = pPlayer.nextUnit(loop, False)
	print "Unit�s du joueur 42 supprim�es."
def init():
	import SystemPaths as SP
	global _saveDir, options
	_saveDir = SP.userDir + "\\Saves"
	import BugCore
	options = BugCore.game.AutoSave
	import CvEventInterface
	CvEventInterface.eventManager.addEventHandler("MapRegen", onMapRegen)
	CvEventInterface.eventManager.addEventHandler("endTurnReady", onEndTurnReady)
	CvEventInterface.eventManager.addEventHandler("GameEnd", onGameEnd)

def onMapRegen(argsList):
	autoSave("[Start]", 0)

def onEndTurnReady(argsList):
	iTurn, = argsList
	inter = options.getInterval()
	if inter > 0 and not iTurn % inter:
		autoSave("[Late]", iTurn)

def onGameEnd(argsList):
	autoSave("[End]", argsList[0])

def save(type, prefix, iTurn):

	dir = "%s\\%s\\" %(_saveDir, type)
	if prefix:
		dir += prefix + "'"
	CyPlayer = GC.getActivePlayer()

	if iTurn:
		dir += "#" + str(iTurn)
	else:
		dir += MAP.getMapScriptName()

	if options.isUsePlayerName():
		dir += '-' + CyPlayer.getName()[:8]
	else:
		dir += '-' + GC.getLeaderHeadInfo(CyPlayer.getLeaderType()).getText()[:8]

	dir += '-' + GC.getEraInfo(GAME.getCurrentEra()).getText()[:8]
	dir += '-' + GC.getGameSpeedInfo(GAME.getGameSpeedType()).getText()[:5]
	dir += '-' + GC.getWorldInfo(MAP.getWorldSize()).getText()[:5]
	dir += '-' + GC.getHandicapInfo(CyPlayer.getHandicapType()).getText()[:5]
	dir += ".CivBeyondSwordSave"

	print "before AutoSave.savename : %s" % dir

	dir = remove_diacritics(dir)

	print "after AutoSave.savename : %s" % dir
	

	
	npcclean = False
	if npcclean:
		cleanNpc()
	
	GAME.saveGame(str(dir))
	print "AutoSave.save\n\t%s" % dir

def autoSave(prefix="", iTurn=None):
	# Filter by option
	if(prefix == "[Start]" and not options.isCreateStartSave()
	or prefix == "[End]" and not options.isCreateEndSave()
	or prefix == "[Exit]" and not options.isCreateExitSave()
	or prefix == "[Late]" and not options.isCreateLateSave()
	):
		return
	if iTurn is None:
		iTurn = GAME.getGameTurn()
	# pick folder
	if GAME.isGameMultiPlayer():
		if GAME.isHotSeat():
			type = "hotseat"
		elif GAME.isPbem():
			type = "pbem"
		elif GAME.isPitboss():
			type = "pitboss"
		else:
			type = "multi"
	else:
		type = "single"
	type += "\\auto"
	save(type, prefix, iTurn)
