#pragma once

#ifndef CyGameTextMgr_h
#define CyGameTextMgr_h

//
// Python wrapper class for CvGameTextMgr
//

class CyCity;
class CyDeal;
class CyUnit;

class CyGameTextMgr
{
public:
	CyGameTextMgr();

	bool isNone() const { return false; }

	std::wstring getTimeStr(int iGameTurn, bool bSave) const;
	std::wstring getDateStr(int iGameTurn, bool bSave, int /*CalendarTypes*/ eCalendar, int iStartYear, int /*GameSpeedTypes*/ eSpeed) const;
	std::wstring getInterfaceTimeStr(int /*PlayerTypes*/ iPlayer) const;
	std::wstring getGoldStr(int /*PlayerTypes*/ iPlayer) const;
	std::wstring getResearchStr(int /*PlayerTypes*/ iPlayer) const;
	std::wstring getOOSSeeds(int /*PlayerTypes*/ iPlayer) const;
	std::wstring getNetStats(int /*PlayerTypes*/ iPlayer) const;
	std::wstring getTechHelp(int iTech, bool bCivilopediaText, bool bPlayerContext, bool bStrategyText, bool bTreeInfo, int iFromTech) const;
	std::wstring getUnitHelp(int iUnit, bool bCivilopediaText, bool bStrategyText, bool bTechChooserText, const CyCity* pCity) const;
	std::wstring getSpecificUnitHelp(const CyUnit* pUnit, bool bOneLine, bool bShort) const;
	std::wstring getBuildingHelp(int iBuilding, bool bCivilopediaText, bool bStrategyText, bool bTechChooserText, const CyCity* pCity, bool bActual = false) const;
	std::wstring getProjectHelp(int iProject, bool bCivilopediaText, const CyCity* pCity) const;
	std::wstring getPromotionHelp(int iPromotion, bool bCivilopediaText) const;
	std::wstring getBonusHelp(int iBonus, bool bCivilopediaText) const;
	std::wstring getProductionHelpCity(const CyCity& kCity) const;
	std::wstring getReligionHelpCity(int iReligion, const CyCity* pCity, bool bCityScreen, bool bForceReligion, bool bForceState, bool bNoStateReligion) const;
	std::wstring getCorporationHelpCity(int iCorporation, const CyCity* pCity, bool bCityScreen, bool bForceCorporation) const;
	std::wstring getImprovementHelp(int iImprovement, bool bCivilopediaText) const;
	std::wstring getRouteHelp(int iRoute, bool bCivilopediaText) const;
	std::wstring getTerrainHelp(int iTerrain, bool bCivilopediaText) const;
	std::wstring getFeatureHelp(int iFeature, bool bCivilopediaText) const;
	std::wstring parseCivicInfo(int /*CivicTypes*/ iCivicType, bool bCivilopediaText, bool bPlayerContext, bool bSkipName) const;
	std::wstring parseReligionInfo(int /*ReligionTypes*/ iReligionType, bool bCivilopediaText) const;
	std::wstring parseCorporationInfo(int /*CorporationTypes*/ iCorporationType, bool bCivilopediaText) const;
	std::wstring parseCivInfos(int /*CivilizationTypes*/ iCivilization, bool bDawnOfMan) const;
	std::wstring parseLeaderTraits(int /*LeaderHeadTypes*/ iLeader, int /*CivilizationTypes*/ iCivilization, bool bDawnOfMan, bool bCivilopediaText) const;
	std::wstring parseTraits(int /*TraitTypes*/ eTrait, int /*CivilizationTypes*/ eCivilization, bool bDawnOfMan, bool bEffectsOnly) const;
	std::wstring getHappinessHelp() const;
	std::wstring getSpecialistHelp(int iSpecialist, bool bCivilopediaText) const;
	std::wstring buildHintsList() const;
	std::wstring getAttitudeString(int iPlayer, int iTargetPlayer) const;
	std::wstring setConvertHelp(int iPlayer, int iReligion) const;
	std::wstring setRevolutionHelp(int iPlayer) const;
	std::wstring getActiveDealsString(int iThisPlayer, int iOtherPlayer) const;
	std::wstring getDealString(const CyDeal* pDeal, int iPlayerPerspective) const;

protected:
	//CvGameTextMgr* m_pGameTextMgr;
};

#endif	// #ifndef CyGameTextMgr_h
