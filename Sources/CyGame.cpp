#include "CvGameCoreDLL.h"
#include "CvGameAI.h"
#include "CvInitCore.h"
#include "CyCity.h"
#include "CyDeal.h"
#include "CyGame.h"
#include "CyPlot.h"
#include "CyReplayInfo.h"
#include "CvReplayInfo.h"

//
// Python wrapper class for CvGame
//

CyGame::CyGame() : m_pGame(reinterpret_cast<CvGame&>(GC.getGame())) {}

CyGame::CyGame(CvGame& pGame) : m_pGame(pGame) {}


int CyGame::getCurrentMap() const
{
	return m_pGame.getCurrentMap();
}

bool CyGame::isMultiplayer() const
{
	return GC.getInitCore().getMultiplayer();
}

void CyGame::updateScore(bool bForce)
{
	m_pGame.updateScore(bForce);
}

void CyGame::selectedCitiesGameNetMessage(int eMessage, int iData2, int iData3, int iData4, bool bOption, bool bAlt, bool bShift, bool bCtrl)
{
	m_pGame.selectedCitiesGameNetMessage(eMessage, iData2, iData3, iData4, bOption, bAlt, bShift, bCtrl);
}

int CyGame::getSymbolID(int iSymbol) const
{
	return gDLL->getInterfaceIFace()->getSymbolID(iSymbol);
}

int CyGame::getProductionPerPopulation(int /*HurryTypes*/ eHurry) const
{
	return m_pGame.getProductionPerPopulation((HurryTypes) eHurry);
}

int CyGame::getAdjustedPopulationPercent(int /*VictoryTypes*/ eVictory) const
{
	return m_pGame.getAdjustedPopulationPercent((VictoryTypes) eVictory);
}

int CyGame::getAdjustedLandPercent(int /*VictoryTypes*/ eVictory) const
{
	return m_pGame.getAdjustedLandPercent((VictoryTypes) eVictory);
}

bool CyGame::isChooseElection(int /*VoteTypes*/ eVote) const
{
	return m_pGame.isChooseElection((VoteTypes) eVote);
}

bool CyGame::isTeamVoteEligible(int /*TeamTypes*/ eTeam, int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame.isTeamVoteEligible((TeamTypes) eTeam, (VoteSourceTypes)eVoteSource);
}

int CyGame::countPossibleVote(int /*VoteTypes*/ eVote, int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame.countPossibleVote((VoteTypes) eVote, (VoteSourceTypes)eVoteSource);
}

int CyGame::getVoteRequired(int /*VoteTypes*/ eVote, int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame.getVoteRequired((VoteTypes)eVote, (VoteSourceTypes) eVoteSource);
}

int CyGame::getSecretaryGeneral(int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame.getSecretaryGeneral((VoteSourceTypes) eVoteSource);
}

bool CyGame::canHaveSecretaryGeneral(int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame.canHaveSecretaryGeneral((VoteSourceTypes) eVoteSource);
}

int CyGame::getVoteSourceReligion(int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame.getVoteSourceReligion((VoteSourceTypes) eVoteSource);
}

int CyGame::countCivPlayersAlive() const
{
	return m_pGame.countCivPlayersAlive();
}

int CyGame::countCivPlayersEverAlive() const
{
	return m_pGame.countCivPlayersEverAlive();
}

int CyGame::countCivTeamsAlive() const
{
	return m_pGame.countCivTeamsAlive();
}

int CyGame::countCivTeamsEverAlive() const
{
	return m_pGame.countCivTeamsEverAlive();
}

int CyGame::countKnownTechNumTeams(int /*TechTypes*/ eTech) const
{
	return m_pGame.countKnownTechNumTeams((TechTypes) eTech);
}

int CyGame::countReligionLevels(int /*ReligionTypes*/ eReligion) const
{
	return m_pGame.countReligionLevels((ReligionTypes) eReligion);
}

int CyGame::countCorporationLevels(int /*CorporationTypes*/ eCorporation) const
{
	return m_pGame.countCorporationLevels((CorporationTypes) eCorporation);
}

int CyGame::calculateReligionPercent(int /*ReligionTypes*/ eReligion) const
{
	return m_pGame.calculateReligionPercent((ReligionTypes) eReligion);
}

int CyGame::goldenAgeLength() const
{
	return m_pGame.goldenAgeLength();
}

int CyGame::getCurrentEra() const
{
	return m_pGame.getCurrentEra();
}

int CyGame::getActiveTeam() const
{
	return m_pGame.getActiveTeam();
}

int /* CivilizationTypes */ CyGame::getActiveCivilizationType() const
{
	return m_pGame.getActiveCivilizationType();
}

bool CyGame::isNetworkMultiPlayer() const
{
	return m_pGame.isNetworkMultiPlayer();
}

bool CyGame::isGameMultiPlayer() const
{
	return m_pGame.isGameMultiPlayer();
}

bool CyGame::isModem() const
{
	return m_pGame.isModem();
}

void CyGame::setModem(bool bModem)
{
	m_pGame.setModem(bModem);
}

int CyGame::getNumHumanPlayers() const
{
	return m_pGame.getNumHumanPlayers();
}

int CyGame::getGameTurn() const
{
	return m_pGame.getGameTurn();
}

void CyGame::setGameTurn(int iNewValue)
{
	m_pGame.setGameTurn(iNewValue);
}

int CyGame::getTurnYear(int iGameTurn) const
{
	return m_pGame.getTurnYear(iGameTurn);
}

int CyGame::getGameTurnYear() const
{
	return m_pGame.getGameTurnYear();
}

int CyGame::getElapsedGameTurns() const
{
	return m_pGame.getElapsedGameTurns();
}

int CyGame::getMaxTurns() const
{
	return m_pGame.getMaxTurns();
}

void CyGame::changeMaxTurns(int iChange)
{
	m_pGame.changeMaxTurns(iChange);
}

int CyGame::getMaxCityElimination() const
{
	return m_pGame.getMaxCityElimination();
}

void CyGame::setMaxCityElimination(int iNewValue)
{
	m_pGame.setMaxCityElimination(iNewValue);
}

int CyGame::getNumAdvancedStartPoints() const
{
	return m_pGame.getNumAdvancedStartPoints();
}

int CyGame::getStartTurn() const
{
	return m_pGame.getStartTurn();
}

int CyGame::getStartYear() const
{
	return m_pGame.getStartYear();
}

void CyGame::setStartYear(int iNewValue)
{
	m_pGame.setStartYear(iNewValue);
}

int CyGame::getEstimateEndTurn() const
{
	return m_pGame.getEstimateEndTurn();
}

void CyGame::setEstimateEndTurn(int iNewValue)
{
	m_pGame.setEstimateEndTurn(iNewValue);
}

int CyGame::getMinutesPlayed() const
{
	return m_pGame.getMinutesPlayed();
}

int CyGame::getTargetScore() const
{
	return m_pGame.getTargetScore();
}

void CyGame::setTargetScore(int iNewValue)
{
	m_pGame.setTargetScore(iNewValue);
}

int CyGame::getNumCities() const
{
	return m_pGame.getNumCities();
}

int CyGame::getTotalPopulation() const
{
	return m_pGame.getTotalPopulation();
}

int CyGame::getTradeRoutes() const
{
	return m_pGame.getTradeRoutes();
}

void CyGame::changeTradeRoutes(int iChange)
{
	m_pGame.changeTradeRoutes(iChange);
}

void CyGame::changeNoNukesCount(int iChange)
{
	m_pGame.changeNoNukesCount(iChange);
}

int CyGame::getSecretaryGeneralTimer(int iVoteSource) const
{
	return m_pGame.getSecretaryGeneralTimer((VoteSourceTypes)iVoteSource);
}

int CyGame::getVoteTimer(int iVoteSource) const
{
	return m_pGame.getVoteTimer((VoteSourceTypes)iVoteSource);
}

int CyGame::getNukesExploded() const
{
	return m_pGame.getNukesExploded();
}

void CyGame::changeNukesExploded(int iChange)
{
	m_pGame.changeNukesExploded(iChange);
}

int CyGame::getMaxPopulation() const
{
	return m_pGame.getMaxPopulation();
}

int CyGame::getMaxLand() const
{
	return m_pGame.getMaxLand();
}

int CyGame::getMaxTech() const
{
	return m_pGame.getMaxTech();
}

int CyGame::getMaxWonders() const
{
	return m_pGame.getMaxWonders();
}

int CyGame::getInitPopulation() const
{
	return m_pGame.getInitPopulation();
}

int CyGame::getInitLand() const
{
	return m_pGame.getInitLand();
}

int CyGame::getInitTech() const
{
	return m_pGame.getInitTech();
}

int CyGame::getInitWonders() const
{
	return m_pGame.getInitWonders();
}

int CyGame::getAIAutoPlay(int iPlayer) const
{
	return m_pGame.getAIAutoPlay((PlayerTypes)iPlayer);
}

void CyGame::setAIAutoPlay(int iPlayer, int iNewValue)
{
	m_pGame.setAIAutoPlay((PlayerTypes)iPlayer, iNewValue);
}

bool CyGame::isForcedAIAutoPlay(int iPlayer) const
{
	return m_pGame.isForcedAIAutoPlay((PlayerTypes)iPlayer);
}

void CyGame::setForcedAIAutoPlay(int iPlayer, int iNewValue, bool bForced)
{
	m_pGame.setForcedAIAutoPlay((PlayerTypes)iPlayer, iNewValue, bForced);
}

bool CyGame::isDiploVote(int /*VoteSourceTypes*/ eVoteSource) const
{
	return m_pGame.isDiploVote((VoteSourceTypes)eVoteSource);
}

bool CyGame::isDebugMode() const
{
	return m_pGame.isDebugMode();
}

void CyGame::toggleDebugMode()
{
	m_pGame.toggleDebugMode();
}

int CyGame::getPitbossTurnTime() const
{
	return m_pGame.getPitbossTurnTime();
}

bool CyGame::isHotSeat() const
{
	return m_pGame.isHotSeat();
}

bool CyGame::isPbem() const
{
	return m_pGame.isPbem();
}

bool CyGame::isPitboss() const
{
	return m_pGame.isPitboss();
}

bool CyGame::isFinalInitialized() const
{
	return m_pGame.isFinalInitialized();
}

int /*PlayerTypes*/ CyGame::getActivePlayer() const
{
	return m_pGame.getActivePlayer();
}

void CyGame::setActivePlayer(int /*PlayerTypes*/ eNewValue, bool bForceHotSeat)
{
	m_pGame.setActivePlayer((PlayerTypes)eNewValue, bForceHotSeat);
}

int CyGame::getPausePlayer() const
{
	return m_pGame.getPausePlayer();
}

bool CyGame::isPaused() const
{
	return m_pGame.isPaused();
}

bool CyGame::getStarshipLaunched(int playaID) const
{
	return m_pGame.getStarshipLaunched(playaID);
}

bool CyGame::getDiplomaticVictoryAchieved(int playaID) const
{
	return m_pGame.getDiplomaticVictoryAchieved(playaID);
}

int /*VictoryTypes*/ CyGame::getVictory() const
{
	return m_pGame.getVictory();
}

int /*GameStateTypes*/ CyGame::getGameState() const
{
	return m_pGame.getGameState();
}

int /* HandicapTypes */ CyGame::getHandicapType() const
{
	return m_pGame.getHandicapType();
}

CalendarTypes CyGame::getCalendar() const
{
	return m_pGame.getCalendar();
}

int /*EraTypes*/ CyGame::getStartEra() const
{
	return m_pGame.getStartEra();
}

int /*GameSpeedTypes*/ CyGame::getGameSpeedType() const
{
	return m_pGame.getGameSpeedType();
}

int /*PlayerTypes*/ CyGame::getRankPlayer(int iRank) const
{
	return m_pGame.getRankPlayer(iRank);
}

int CyGame::getPlayerRank(int /*PlayerTypes*/ ePlayer) const
{
	return m_pGame.getPlayerRank((PlayerTypes)ePlayer);
}

int CyGame::getPlayerScore(int /*PlayerTypes*/ ePlayer) const
{
	return m_pGame.getPlayerScore((PlayerTypes)ePlayer);
}

int /*TeamTypes*/ CyGame::getRankTeam(int iRank) const
{
	return m_pGame.getRankTeam(iRank);
}

int CyGame::getTeamScore(int /*TeamTypes*/ eTeam) const
{
	return m_pGame.getTeamScore((TeamTypes)eTeam);
}

bool CyGame::isOption(int /*GameOptionTypes*/ eIndex) const
{
	return m_pGame.isOption((GameOptionTypes)eIndex);
}

void CyGame::setOption(int /*GameOptionTypes*/ eIndex, bool bEnabled)
{
	m_pGame.setOption((GameOptionTypes)eIndex, bEnabled);
}

bool CyGame::isMPOption(int /*MultiplayerOptionTypes*/ eIndex) const
{
	return m_pGame.isMPOption((MultiplayerOptionTypes)eIndex);
}

bool CyGame::isForcedControl(int /*ForceControlTypes*/ eIndex) const
{
	return m_pGame.isForcedControl((ForceControlTypes)eIndex);
}

bool CyGame::isUnitMaxedOut(int /*UnitTypes*/ eIndex, int iExtra) const
{
	return m_pGame.isUnitMaxedOut((UnitTypes)eIndex, iExtra);
}

bool CyGame::isBuildingMaxedOut(int /*BuildingTypes*/ eIndex, int iExtra) const
{
	return m_pGame.isBuildingMaxedOut((BuildingTypes)eIndex, iExtra);
}

int CyGame::getProjectCreatedCount(int /*ProjectTypes*/ eIndex) const
{
	return m_pGame.getProjectCreatedCount((ProjectTypes) eIndex);
}

int CyGame::getReligionGameTurnFounded(int /*ReligionTypes*/ eIndex) const
{
	return m_pGame.getReligionGameTurnFounded((ReligionTypes) eIndex);
}

bool CyGame::isReligionSlotTaken(int /*ReligionTypes*/ eIndex) const
{
	return m_pGame.isReligionSlotTaken((ReligionTypes) eIndex);
}

int CyGame::getCorporationGameTurnFounded(int /*CorporationTypes*/ eIndex) const
{
	return m_pGame.getCorporationGameTurnFounded((CorporationTypes) eIndex);
}

bool CyGame::isCorporationFounded(int /*CorporationTypes*/ eIndex) const
{
	return m_pGame.isCorporationFounded((CorporationTypes) eIndex);
}

bool CyGame::isVotePassed(int /*VoteTypes*/ eIndex) const
{
	return m_pGame.isVotePassed((VoteTypes)eIndex);
}

bool CyGame::isVictoryValid(int /*VictoryTypes*/ eIndex) const
{
	return m_pGame.isVictoryValid((VictoryTypes)eIndex);
}

bool CyGame::isInAdvancedStart() const
{
	return m_pGame.isInAdvancedStart();
}

CyCity* CyGame::getHolyCity(int /*ReligionTypes*/ eIndex) const
{
	return new CyCity(m_pGame.getHolyCity((ReligionTypes) eIndex));
}

void CyGame::setHolyCity(int /*ReligionTypes*/ eIndex, CyCity* pNewValue, bool bAnnounce)
{
	m_pGame.setHolyCity((ReligionTypes) eIndex, pNewValue->getCity(), bAnnounce);
}

void CyGame::clearHolyCity(int /*ReligionTypes*/ eIndex)
{
	m_pGame.setHolyCity((ReligionTypes) eIndex, NULL, false);
}

CyCity* CyGame::getHeadquarters(int /*CorporationTypes*/ eIndex) const
{
	return new CyCity(m_pGame.getHeadquarters((CorporationTypes) eIndex));
}

void CyGame::setHeadquarters(int /*CorporationTypes*/ eIndex, CyCity* pNewValue, bool bAnnounce)
{
	m_pGame.setHeadquarters((CorporationTypes) eIndex, pNewValue->getCity(), bAnnounce);
}

void CyGame::clearHeadquarters(int /*CorporationTypes*/ eIndex)
{
	m_pGame.setHeadquarters((CorporationTypes) eIndex, NULL, false);
}

std::string CyGame::getScriptData() const
{
	return m_pGame.getScriptData();
}

void CyGame::setScriptData(std::string szNewValue)
{
	m_pGame.setScriptData(szNewValue);
}

void CyGame::setName(TCHAR* szNewValue)
{
	m_pGame.setName(szNewValue);
}

std::wstring CyGame::getName() const
{
	return m_pGame.getName();
}

int CyGame::getIndexAfterLastDeal() const
{
	return m_pGame.getIndexAfterLastDeal();
}

int CyGame::getNumDeals() const
{
	return m_pGame.getNumDeals();
}

CyDeal* CyGame::getDeal(int iID) const
{
	return new CyDeal(m_pGame.getDeal(iID));
}

CvRandom& CyGame::getMapRand() const
{
	return m_pGame.getMapRand();
}

CvRandom& CyGame::getSorenRand() const
{
	return m_pGame.getSorenRand();
}

int CyGame::getSorenRandNum(int iNum, TCHAR* pszLog) const
{
	return m_pGame.getSorenRandNum(iNum, pszLog);
}

bool CyGame::GetWorldBuilderMode() const				// remove once CvApp is exposed
{
	return gDLL->GetWorldBuilderMode();
}

bool CyGame::isPitbossHost() const				// remove once CvApp is exposed
{
	return gDLL->IsPitbossHost();
}

int CyGame::getCurrentLanguage() const				// remove once CvApp is exposed
{
	return gDLL->getCurrentLanguage();
}

void CyGame::setCurrentLanguage(int iNewLanguage)			// remove once CvApp is exposed
{
	gDLL->setCurrentLanguage(iNewLanguage);
}

int CyGame::getReplayMessageTurn(int i) const
{
	return m_pGame.getReplayMessageTurn(i);
}

std::wstring CyGame::getReplayMessageText(int i) const
{
	return m_pGame.getReplayMessageText(i);
}

uint CyGame::getNumReplayMessages() const
{
	return m_pGame.getNumReplayMessages();
}

CyReplayInfo* CyGame::getReplayInfo() const
{
	return new CyReplayInfo(m_pGame.getReplayInfo());
}

bool CyGame::hasSkippedSaveChecksum() const
{
	return m_pGame.hasSkippedSaveChecksum();
}

void CyGame::saveReplay(int iPlayer)
{
	m_pGame.saveReplay((PlayerTypes)iPlayer);
}

void CyGame::addPlayer(int eNewPlayer, int eLeader, int eCiv, bool bSetAlive)
{
	m_pGame.addPlayer((PlayerTypes)eNewPlayer, (LeaderHeadTypes)eLeader, (CivilizationTypes)eCiv, bSetAlive);
}

void CyGame::changeHumanPlayer(int eOldHuman, int eNewHuman)
{
	m_pGame.changeHumanPlayer((PlayerTypes)eOldHuman, (PlayerTypes)eNewHuman);
}

void CyGame::log(TCHAR* str)
{
	m_pGame.logMsg(str);
}

void CyGame::addReplayMessage(int /*ReplayMessageTypes*/ eType, int /*PlayerTypes*/ ePlayer, std::wstring pszText, int iPlotX, int iPlotY, int /*ColorTypes*/ eColor)
{
	m_pGame.addReplayMessage((ReplayMessageTypes)eType, (PlayerTypes)ePlayer, pszText, iPlotX, iPlotY, (ColorTypes)eColor);
}

void CyGame::drawBattleEffects()
{
	m_pGame.drawBattleEffects();
}

int CyGame::getCultureThreshold(int eLevel) const
{
	return m_pGame.getCultureThreshold((CultureLevelTypes) eLevel);
}

void CyGame::setPlotExtraYield(int iX, int iY, int /*YieldTypes*/ eYield, int iExtraYield)
{
	m_pGame.setPlotExtraYield(iX, iY, (YieldTypes)eYield, iExtraYield);
}

bool CyGame::isCivEverActive(int /*CivilizationTypes*/ eCivilization) const
{
	return m_pGame.isCivEverActive((CivilizationTypes)eCivilization);
}

bool CyGame::isLeaderEverActive(int /*LeaderHeadTypes*/ eLeader) const
{
	return m_pGame.isLeaderEverActive((LeaderHeadTypes)eLeader);
}

bool CyGame::isEventActive(int /*EventTriggerTypes*/ eTrigger) const
{
	return m_pGame.isEventActive((EventTriggerTypes)eTrigger);
}

void CyGame::doControl(int iControl)
{
	m_pGame.doControl((ControlTypes) iControl);
}

void CyGame::saveGame(std::string fileName) const
{
	gDLL->getEngineIFace()->SaveGame((CvString &)fileName, SAVEGAME_NORMAL);
}

bool CyGame::cheatCodesEnabled() const
{
	return gDLL->getChtLvl() > 0;
}

void CyGame::setModderGameOption(int /*ModderGameOptionTypes*/ eIndex, int iNewValue)
{
	m_pGame.setModderGameOption((ModderGameOptionTypes)eIndex, iNewValue);
}

int CyGame::getXResolution() const
{
	return m_pGame.getXResolution();
}

int CyGame::getYResolution() const
{
	return m_pGame.getYResolution();
}

bool CyGame::canEverResearch(int iTech) const
{
	return m_pGame.canEverResearch((TechTypes)iTech);
}

bool CyGame::canEverConstruct(int iBuilding) const
{
	return m_pGame.canEverConstruct((BuildingTypes)iBuilding);
}

bool CyGame::canEverSpread(int iCorporation) const
{
	return m_pGame.canEverSpread((CorporationTypes)iCorporation);
}

const char* CyGame::getC2CVersion() const
{
	return GC.getDefineSTRING("C2C_VERSION");
}
