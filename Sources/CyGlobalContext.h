#pragma once

#ifndef CyGlobalContext_h
#define CyGlobalContext_h

//
// Python wrapper class for global vars and fxns
// Passed to Python
//

#include "CvGlobals.h"

class CyGame;
class CyMap;
class CyPlayer;
class CvRandom;
class CyTeam;

class CyGlobalContext
{
public:
	CyGlobalContext() {}
	virtual ~CyGlobalContext() {}

	static const CyGlobalContext& getInstance();

	bool isDebugBuild() const;
	CyGame& getCyGame() const;
	CyMap* getCyMap() const;
	CyPlayer* getCyPlayer(int idx) const;
	CyPlayer* getCyActivePlayer() const;
	CvRandom& getCyASyncRand() const;
	CyTeam* getCyTeam(int i) const;

/*********************************/
/***** Parallel Maps - Begin *****/
/*********************************/
	void enableMultiMaps() { GC.enableMultiMaps(); }
	bool multiMapsEnabled() const;
	void switchMap(int iMap);
	int getNumMapInfos() const;
	CvMapInfo* getMapInfo(int iMap) const;
	CyMap* getMapByIndex(int iIndex) const;
	void updateMaps();
	void initializeMap(int iMap);
	bool mapInitialized(int iMap) const;
/*******************************/
/***** Parallel Maps - End *****/
/*******************************/	

	CvEffectInfo* getEffectInfo(int i) const;
	CvTerrainInfo* getTerrainInfo(int i) const;
	CvBonusClassInfo* getBonusClassInfo(int i) const;
	CvBonusInfo* getBonusInfo(int i) const;
	CvFeatureInfo* getFeatureInfo(int i) const;
	CvCivilizationInfo* getCivilizationInfo(int idx) const;
	CvLeaderHeadInfo* getLeaderHeadInfo(int i) const;
	CvTraitInfo* getTraitInfo(int i) const;
	CvUnitInfo* getUnitInfo(int i) const;
	CvSpecialUnitInfo* getSpecialUnitInfo(int i) const;
	CvYieldInfo* getYieldInfo(int i) const;
	CvCommerceInfo* getCommerceInfo(int i) const;
	CvRouteInfo* getRouteInfo(int i) const;
	CvImprovementInfo* getImprovementInfo(int i) const;
	CvGoodyInfo* getGoodyInfo(int i) const;
	CvBuildInfo* getBuildInfo(int i) const;
	CvHandicapInfo* getHandicapInfo(int i) const;
	CvGameSpeedInfo* getGameSpeedInfo(int i) const;
	CvTurnTimerInfo* getTurnTimerInfo(int i) const;
	CvMissionInfo* getMissionInfo(int i) const;
	CvCommandInfo* getCommandInfo(int i) const;
	CvAutomateInfo* getAutomateInfo(int i) const;
	CvActionInfo* getActionInfo(int i) const;
	CvInfoBase* getUnitCombatInfo(int i) const;
	//TB Promotion Line Mod begin
	CvPromotionLineInfo* getPromotionLineInfo(int i) const;
	//TB Promotion Line Mod end
	CvMapCategoryInfo* getMapCategoryInfo(int i) const;
	CvIdeaClassInfo* getIdeaClassInfo(int i) const;
	CvIdeaInfo* getIdeaInfo(int i) const;
	//CvTraitOptionEditsInfo* getTraitOptionEditsInfo(int i) const;
	CvInfoBase* getDomainInfo(int i) const;
	CvBuildingInfo* getBuildingInfo(int i) const;
	CvCivicOptionInfo* getCivicOptionInfo(int i) const;
	CvCivicInfo* getCivicInfo(int i) const;
	CvDiplomacyInfo* getDiplomacyInfo(int i) const;
	CvProjectInfo* getProjectInfo(int i) const;
	CvVoteInfo* getVoteInfo(int i) const;
	CvProcessInfo* getProcessInfo(int i) const;
	CvSpecialistInfo* getSpecialistInfo(int i) const;
	CvReligionInfo* getReligionInfo(int i) const;
	CvCorporationInfo* getCorporationInfo(int i) const;
	CvControlInfo* getControlInfo(int i) const;
	CvTechInfo* getTechInfo(int i) const;
	CvSpecialBuildingInfo* getSpecialBuildingInfo(int i) const;
	CvPromotionInfo* getPromotionInfo(int i) const;
	CvAnimationPathInfo * getAnimationPathInfo(int i) const;
	CvEmphasizeInfo * getEmphasizeInfo(int i) const;
	CvUpkeepInfo * getUpkeepInfo(int i) const;
	CvCultureLevelInfo * getCultureLevelInfo(int i) const;
	CvEraInfo * getEraInfo(int i) const;
	CvVictoryInfo * getVictoryInfo(int i) const;
	CvWorldInfo * getWorldInfo(int i) const;
	CvClimateInfo * getClimateInfo(int i) const;
	CvSeaLevelInfo * getSeaLevelInfo(int i) const;
	CvInfoBase * getUnitAIInfo(int i) const;
	CvColorInfo* getColorInfo(int i) const;
	CvPropertyInfo* getPropertyInfo(int i) const;

	int getInfoTypeForString(const char* szInfoType) const;
	int getInfoTypeForStringWithHiddenAssert(const char* szInfoType) const;
	int getTypesEnum(const char* szType) const;

	int getNumPlayerColorInfos() const { return GC.getNumPlayerColorInfos(); }
	CvPlayerColorInfo* getPlayerColorInfo(int i) const;

	CvMainMenuInfo* getMainMenus(int i) const;
	CvInvisibleInfo* getInvisibleInfo(int i) const;
	CvVoteSourceInfo* getVoteSourceInfo(int i) const;
	CvInfoBase* getAttitudeInfo(int i) const;
	CvInfoBase* getMemoryInfo(int i) const;
	CvInfoBase* getConceptInfo(int i) const;
	CvInfoBase* getNewConceptInfo(int i) const;
	CvInfoBase* getCalendarInfo(int i) const;
	CvInfoBase* getGameOptionInfo(int i) const;
	CvInfoBase* getMPOptionInfo(int i) const;
	CvInfoBase* getForceControlInfo(int i) const;
	CvEventTriggerInfo* getEventTriggerInfo(int i) const;
	CvEventInfo* getEventInfo(int i) const;
	CvEspionageMissionInfo* getEspionageMissionInfo(int i) const;
	CvHurryInfo* getHurryInfo(int i) const;
	CvPlayerOptionInfo* getPlayerOptionInfo(int i) const;
	CvGraphicOptionInfo* getGraphicOptionInfo(int i) const;

	// ArtInfos
	CvArtInfoInterface* getInterfaceArtInfo(int i) const;
	CvArtInfoMovie* getMovieArtInfo(int i) const;
	CvArtInfoMisc* getMiscArtInfo(int i) const;
	CvArtInfoUnit* getUnitArtInfo(int i) const;
	CvArtInfoBuilding* getBuildingArtInfo(int i) const;
	CvArtInfoCivilization* getCivilizationArtInfo(int i) const;
	CvArtInfoBonus* getBonusArtInfo(int i) const;
	CvArtInfoImprovement* getImprovementArtInfo(int i) const;

	const char* getFlavorTypes(int i) const { return GC.getFlavorTypes((FlavorTypes) i); }
	const char* getArtStyleTypes(int i) const { return GC.getArtStyleTypes((ArtStyleTypes) i); }
	const char* getDiplomacyPowerTypes(int i) const { return GC.getDiplomacyPowerTypes((DiplomacyPowerTypes) i); }

	int getNumEffectInfos() const { return GC.getNumEffectInfos(); }
	int getNumTerrainInfos() const { return GC.getNumTerrainInfos(); }
	int getNumSpecialBuildingInfos() const { return GC.getNumSpecialBuildingInfos(); }
	int getNumBonusInfos() const { return GC.getNumBonusInfos(); };
	int getNumPlayableCivilizationInfos() const { return GC.getNumPlayableCivilizationInfos(); }
	int getNumCivilizatonInfos() const { return GC.getNumCivilizationInfos(); }
	int getNumLeaderHeadInfos() const { return GC.getNumLeaderHeadInfos(); }
	int getNumTraitInfos() const { return GC.getNumTraitInfos(); }
	int getNumUnitInfos() const { return GC.getNumUnitInfos(); }
	int getNumSpecialUnitInfos() const { return GC.getNumSpecialUnitInfos(); }
	int getNumRouteInfos() const { return GC.getNumRouteInfos(); }
	int getNumFeatureInfos() const { return GC.getNumFeatureInfos(); }
	int getNumImprovementInfos() const { return GC.getNumImprovementInfos(); }
	int getNumGoodyInfos() const { return GC.getNumGoodyInfos(); }
	int getNumBuildInfos() const { return GC.getNumBuildInfos(); }
	int getNumHandicapInfos() const { return GC.getNumHandicapInfos(); }
	int getNumGameSpeedInfos() const { return GC.getNumGameSpeedInfos(); }
	int getNumBuildingInfos() const { return GC.getNumBuildingInfos(); }
	int getNumUnitCombatInfos() const { return GC.getNumUnitCombatInfos(); }
	//TB Promotion Line Mod begin
	int getNumPromotionLineInfos() const { return GC.getNumPromotionLineInfos(); }
	//TB Promotion Line Mod end
	int getNumMapCategoryInfos() const { return GC.getNumMapCategoryInfos(); }
	int getNumIdeaClassInfos() const { return GC.getNumIdeaClassInfos(); }
	int getNumIdeaInfos() const { return GC.getNumIdeaInfos(); }
	//int getNumTraitOptionEditsInfos() const { return GC.getNumTraitOptionEditsInfos(); }
	int getNumAutomateInfos() const { return GC.getNumAutomateInfos(); }
	int getNumCommandInfos() const { return NUM_COMMAND_TYPES; }
	int getNumControlInfos() const { return NUM_CONTROL_TYPES; }
	int getNumMissionInfos() const { return GC.getNumMissionInfos(); }
	int getNumActionInfos() const { return GC.getNumActionInfos(); }
	int getNumPromotionInfos() const { return GC.getNumPromotionInfos(); }
	int getNumTechInfos() const { return GC.getNumTechInfos(); }
	int getNumReligionInfos() const { return GC.getNumReligionInfos(); }
	int getNumCorporationInfos() const { return GC.getNumCorporationInfos(); }
	int getNumSpecialistInfos() const { return GC.getNumSpecialistInfos(); }
	int getNumCivicInfos() const { return GC.getNumCivicInfos(); }
	int getNumDiplomacyInfos() const { return GC.getNumDiplomacyInfos(); }
	int getNumCivicOptionInfos() const { return GC.getNumCivicOptionInfos(); }
	int getNumProjectInfos() const { return GC.getNumProjectInfos(); }
	int getNumVoteInfos() const { return GC.getNumVoteInfos(); }
	int getNumProcessInfos() const { return GC.getNumProcessInfos(); }
	int getNumEmphasizeInfos() const { return GC.getNumEmphasizeInfos(); }
	int getNumHurryInfos() const { return GC.getNumHurryInfos(); }
	int getNumUpkeepInfos() const { return GC.getNumUpkeepInfos(); }
	int getNumCultureLevelInfos() const { return GC.getNumCultureLevelInfos(); }
	int getNumEraInfos() const { return GC.getNumEraInfos(); }
	int getNumVictoryInfos() const { return GC.getNumVictoryInfos(); }
	int getNumWorldInfos() const { return GC.getNumWorldInfos(); }
	int getNumSeaLevelInfos() const { return GC.getNumSeaLevelInfos(); }
	int getNumClimateInfos() const { return GC.getNumClimateInfos(); }
	int getNumConceptInfos() const { return GC.getNumConceptInfos(); }
	int getNumNewConceptInfos() const { return GC.getNumNewConceptInfos(); }
	int getNumCalendarInfos() const { return GC.getNumCalendarInfos(); }
	int getNumPlayerOptionInfos() const { return NUM_PLAYEROPTION_TYPES; }
	int getNumGameOptionInfos() const { return GC.getNumGameOptionInfos(); }
	int getNumMPOptionInfos() const { return GC.getNumMPOptionInfos(); }
	int getNumForceControlInfos() const { return GC.getNumForceControlInfos(); }
	int getNumSeasonInfos() const { return GC.getNumSeasonInfos(); }
	int getNumDenialInfos() const { return GC.getNumDenialInfos(); }
	int getNumEventTriggerInfos() const { return GC.getNumEventTriggerInfos(); }
	int getNumEventInfos() const { return GC.getNumEventInfos(); }
	int getNumEspionageMissionInfos() const { return GC.getNumEspionageMissionInfos(); }
	int getNumMainMenus() const { return GC.getNumMainMenus(); }
	int getNumInvisibleInfos() const { return GC.getNumInvisibleInfos(); }
	int getNumVoteSourceInfos() const { return GC.getNumVoteSourceInfos(); }

	// ArtInfos
	int getNumAnimationPathInfos() const { return GC.getNumAnimationPathInfos(); }
	int getNumAnimationCategoryInfos() const { return GC.getNumAnimationCategoryInfos(); }
	int getNumUnitArtStyleTypeInfos() const { return GC.getNumUnitArtStyleTypeInfos(); }

	int getNumFlavorTypes() const { return GC.getNumFlavorTypes(); }
	int getNumFootstepAudioTypes() const { return GC.getNumFootstepAudioTypes(); }

	int getNumPropertyInfos() const { return GC.getNumPropertyInfos(); }

	//////////////////////
	// Globals Defines
	//////////////////////

	int getDefineINT( const char * szName ) const { return GC.getDefineINT( szName ); }
	float getDefineFLOAT( const char * szName ) const { return GC.getDefineFLOAT( szName ); }
	void setDefineINT( const char * szName, int iValue ) { return GC.setDefineINT( szName, iValue ); }
	void setDefineFLOAT( const char * szName, float fValue ) { return GC.setDefineFLOAT( szName, fValue ); }

	bool isDCM_BATTLE_EFFECTS() const { return GC.isDCM_BATTLE_EFFECTS(); }
	bool isDCM_AIR_BOMBING() const { return GC.isDCM_AIR_BOMBING(); }
	bool isDCM_RANGE_BOMBARD() const { return GC.isDCM_RANGE_BOMBARD(); }
	bool isDCM_ATTACK_SUPPORT() const { return GC.isDCM_ATTACK_SUPPORT(); }
	bool isDCM_OPP_FIRE() const { return GC.isDCM_OPP_FIRE(); }
	bool isDCM_ACTIVE_DEFENSE() const { return GC.isDCM_ACTIVE_DEFENSE(); }
	bool isDCM_FIGHTER_ENGAGE() const { return GC.isDCM_FIGHTER_ENGAGE(); }

	bool isIDW_ENABLED() const { return GC.isIDW_ENABLED(); }
	bool isIDW_EMERGENCY_DRAFT_ENABLED() const { return GC.isIDW_EMERGENCY_DRAFT_ENABLED(); }
	bool isIDW_NO_BARBARIAN_INFLUENCE() const { return GC.isIDW_NO_BARBARIAN_INFLUENCE(); }
	bool isIDW_NO_NAVAL_INFLUENCE() const { return GC.isIDW_NO_NAVAL_INFLUENCE(); }
	bool isIDW_PILLAGE_INFLUENCE_ENABLED() const { return GC.isIDW_PILLAGE_INFLUENCE_ENABLED(); }

	bool isSS_ENABLED() const { return GC.isSS_ENABLED(); }
	bool isSS_BRIBE() const { return GC.isSS_BRIBE(); }
	bool isSS_ASSASSINATE() const { return GC.isSS_ASSASSINATE(); }

	int getMOVE_DENOMINATOR() const { return GC.getMOVE_DENOMINATOR(); }
	int getNUM_UNIT_PREREQ_OR_BONUSES() const { return GC.getNUM_UNIT_PREREQ_OR_BONUSES(); }
	int getNUM_BUILDING_PREREQ_OR_BONUSES() const { return GC.getNUM_BUILDING_PREREQ_OR_BONUSES(); }
	int getFOOD_CONSUMPTION_PER_POPULATION() const { return GC.getFOOD_CONSUMPTION_PER_POPULATION(); }
	int getMAX_PLOT_LIST_ROWS() const { return GC.getMAX_PLOT_LIST_ROWS(); }
	int getEVENT_MESSAGE_TIME() const { return GC.getEVENT_MESSAGE_TIME(); }
	int getROUTE_FEATURE_GROWTH_MODIFIER() const { return GC.getROUTE_FEATURE_GROWTH_MODIFIER(); }
	int getFEATURE_GROWTH_MODIFIER() const { return GC.getFEATURE_GROWTH_MODIFIER(); }
	int getNUM_AND_TECH_PREREQS() const { return GC.getNUM_AND_TECH_PREREQS(); }
	int getNUM_OR_TECH_PREREQS() const { return GC.getNUM_OR_TECH_PREREQS(); }
	int getLAKE_MAX_AREA_SIZE() const { return GC.getLAKE_MAX_AREA_SIZE(); }
	int getMIN_WATER_SIZE_FOR_OCEAN() const { return GC.getMIN_WATER_SIZE_FOR_OCEAN(); }
	int getMAX_CITY_DEFENSE_DAMAGE() const { return GC.getMAX_CITY_DEFENSE_DAMAGE(); }
	int getNUM_CORPORATION_PREREQ_BONUSES() const { return GC.getNUM_CORPORATION_PREREQ_BONUSES(); }

	int getMAX_PC_PLAYERS() const { return GC.getMAX_PC_PLAYERS(); }
	int getMAX_PLAYERS() const { return GC.getMAX_PLAYERS(); }
	int getMAX_PC_TEAMS() const { return GC.getMAX_PC_TEAMS(); }
	int getMAX_TEAMS() const { return GC.getMAX_TEAMS(); }
	int getBARBARIAN_PLAYER() const { return GC.getBARBARIAN_PLAYER(); }
	int getNUM_CITY_PLOTS() const { return NUM_CITY_PLOTS; }

	void setIsBug(bool bIsBug) { GC.setIsBug(bIsBug); }										// Exposed to Python
	
	void setNoUpdateDefineFLOAT( const char * szName, float fValue ) { return GC.setDefineFLOAT( szName, fValue, false ); }
};

#endif	// CyGlobalContext_h
