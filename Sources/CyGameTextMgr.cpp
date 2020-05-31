#include "CvGameCoreDLL.h"
#include "CvGameTextMgr.h"
#include "CyCity.h"
#include "CyDeal.h"
#include "CyGameTextMgr.h"
#include "CyUnit.h"

//
// Python wrapper class for CyGameTextMgr 
//

CyGameTextMgr::CyGameTextMgr() {}


std::wstring CyGameTextMgr::getTimeStr(int iGameTurn, bool bSave) const
{
	CvWString str;
	GAMETEXT.setTimeStr(str, iGameTurn, bSave);
	return str;
}

std::wstring CyGameTextMgr::getDateStr(int iGameTurn, bool bSave, int /*CalendarTypes*/ eCalendar, int iStartYear, int /*GameSpeedTypes*/ eSpeed) const
{
	CvWString str;
	GAMETEXT.setDateStr(str, iGameTurn, bSave, (CalendarTypes)eCalendar, iStartYear, (GameSpeedTypes)eSpeed);
	return str;
}

std::wstring CyGameTextMgr::getInterfaceTimeStr(int /*PlayerTypes*/ iPlayer) const
{
	CvWString szBuffer;
	GAMETEXT.setInterfaceTime(szBuffer, (PlayerTypes)iPlayer);
	return szBuffer;
}

std::wstring CyGameTextMgr::getGoldStr(int /*PlayerTypes*/ iPlayer) const
{
	CvWString szBuffer;
	GAMETEXT.setGoldStr(szBuffer, (PlayerTypes)iPlayer);
	return szBuffer;
}

std::wstring CyGameTextMgr::getResearchStr(int /*PlayerTypes*/ iPlayer) const
{
	CvWString szBuffer;
	GAMETEXT.setResearchStr(szBuffer, (PlayerTypes)iPlayer);
	return szBuffer;
}

std::wstring CyGameTextMgr::getOOSSeeds(int /*PlayerTypes*/ iPlayer) const
{
	CvWString szBuffer;
	GAMETEXT.setOOSSeeds(szBuffer, (PlayerTypes)iPlayer);
	return szBuffer;
}

std::wstring CyGameTextMgr::getNetStats(int /*PlayerTypes*/ iPlayer) const
{
	CvWString szBuffer;
	GAMETEXT.setNetStats(szBuffer, (PlayerTypes)iPlayer);
	return szBuffer;
}

std::wstring CyGameTextMgr::getTechHelp(int iTech, bool bCivilopediaText, bool bPlayerContext, bool bStrategyText, bool bTreeInfo, int iFromTech) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setTechHelp(szBuffer, (TechTypes)iTech, bCivilopediaText, bPlayerContext, bStrategyText, bTreeInfo, (TechTypes)iFromTech);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getUnitHelp(int iUnit, bool bCivilopediaText, bool bStrategyText, bool bTechChooserText, const CyCity* pCity) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setUnitHelp(szBuffer, (UnitTypes)iUnit, bCivilopediaText, bStrategyText, bTechChooserText, pCity ? pCity->getCity() : NULL);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getSpecificUnitHelp(const CyUnit* pUnit, bool bOneLine, bool bShort) const
{
	CvWStringBuffer szBuffer;
	if (pUnit && pUnit->getUnit())
	{
		GAMETEXT.setUnitHelp(szBuffer, pUnit->getUnit(), bOneLine, bShort);
	}
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getBuildingHelp(int iBuilding, bool bCivilopediaText, bool bStrategyText, bool bTechChooserText, const CyCity* pCity, bool bActual) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setBuildingHelpActual(szBuffer, (BuildingTypes)iBuilding, bCivilopediaText, bStrategyText, bTechChooserText, pCity ? pCity->getCity() : NULL, bActual);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getProjectHelp(int iProject, bool bCivilopediaText, const CyCity* pCity) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setProjectHelp(szBuffer, (ProjectTypes)iProject, bCivilopediaText, pCity ? pCity->getCity() : NULL);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getPromotionHelp(int iPromotion, bool bCivilopediaText) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setPromotionHelp(szBuffer, (PromotionTypes)iPromotion, bCivilopediaText);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getBonusHelp(int iBonus, bool bCivilopediaText) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setBonusHelp(szBuffer, (BonusTypes)iBonus, bCivilopediaText);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getProductionHelpCity(const CyCity& kCity) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setProductionHelp(szBuffer, *kCity.getCity());
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getReligionHelpCity(int iReligion, const CyCity* pCity, bool bCityScreen, bool bForceReligion, bool bForceState, bool bNoStateReligion) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setReligionHelpCity(szBuffer, (ReligionTypes)iReligion, pCity ? pCity->getCity() : NULL, bCityScreen, bForceReligion, bForceState, bNoStateReligion);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getCorporationHelpCity(int iCorporation, const CyCity* pCity, bool bCityScreen, bool bForceCorporation) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setCorporationHelpCity(szBuffer, (CorporationTypes)iCorporation, pCity ? pCity->getCity() : NULL, bCityScreen, bForceCorporation);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getImprovementHelp(int iImprovement, bool bCivilopediaText) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setImprovementHelp(szBuffer, (ImprovementTypes)iImprovement, NO_FEATURE, bCivilopediaText);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getRouteHelp(int iRoute, bool bCivilopediaText) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setRouteHelp(szBuffer, (RouteTypes)iRoute, bCivilopediaText);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getFeatureHelp(int iFeature, bool bCivilopediaText) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setFeatureHelp(szBuffer, (FeatureTypes)iFeature, bCivilopediaText);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getTerrainHelp(int iTerrain, bool bCivilopediaText) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setTerrainHelp(szBuffer, (TerrainTypes)iTerrain, bCivilopediaText);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::parseCivicInfo(int /*CivicTypes*/ iCivicType, bool bCivilopediaText, bool bPlayerContext, bool bSkipName) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.parseCivicInfo(szBuffer, (CivicTypes) iCivicType, bCivilopediaText, bPlayerContext, bSkipName);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::parseReligionInfo(int /*ReligionTypes*/ iReligionType, bool bCivilopediaText) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setReligionHelp(szBuffer, (ReligionTypes) iReligionType, bCivilopediaText);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::parseCorporationInfo(int /*CorporationTypes*/ iCorporationType, bool bCivilopediaText) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setCorporationHelp(szBuffer, (CorporationTypes) iCorporationType, bCivilopediaText);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::parseCivInfos(int /*CivilizationTypes*/ iCivilization, bool bDawnOfMan) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.parseCivInfos(szBuffer, (CivilizationTypes) iCivilization, bDawnOfMan);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::parseLeaderTraits(int /*LeaderHeadTypes*/ iLeader, int /*CivilizationTypes*/ iCivilization, bool bDawnOfMan, bool bCivilopediaText) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.parseLeaderTraits(szBuffer, (LeaderHeadTypes)iLeader, (CivilizationTypes) iCivilization, bDawnOfMan, bCivilopediaText);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::parseTraits(int /*TraitTypes*/ eTrait, int /*CivilizationTypes*/ eCivilization, bool bDawnOfMan, bool bEffectsOnly) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.parseTraits(szBuffer, (TraitTypes)eTrait, (CivilizationTypes)eCivilization, bDawnOfMan, bEffectsOnly);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getHappinessHelp() const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.parseHappinessHelp(szBuffer);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getSpecialistHelp(int iSpecialist, bool bCivilopediaText) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.parseSpecialistHelp(szBuffer, (SpecialistTypes) iSpecialist, NULL, bCivilopediaText);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::buildHintsList() const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.buildHintsList(szBuffer);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getAttitudeString(int iPlayer, int iTargetPlayer) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.getAttitudeString(szBuffer, (PlayerTypes)iPlayer, (PlayerTypes) iTargetPlayer);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::setConvertHelp(int iPlayer, int iReligion) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setConvertHelp(szBuffer, (PlayerTypes)iPlayer, (ReligionTypes) iReligion);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::setRevolutionHelp(int iPlayer) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.setRevolutionHelp(szBuffer, (PlayerTypes)iPlayer);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getActiveDealsString(int iThisPlayer, int iOtherPlayer) const
{
	CvWStringBuffer szBuffer;
	GAMETEXT.getActiveDealsString(szBuffer, (PlayerTypes)iThisPlayer, (PlayerTypes)iOtherPlayer);
	return szBuffer.getCString();
}

std::wstring CyGameTextMgr::getDealString(const CyDeal* pDeal, int iPlayerPerspective) const
{
	CvWStringBuffer szBuffer;
	if (pDeal && pDeal->getDeal())
	{
		GAMETEXT.getDealString(szBuffer, *pDeal->getDeal(), (PlayerTypes)iPlayerPerspective);
	}
	return szBuffer.getCString();
}
