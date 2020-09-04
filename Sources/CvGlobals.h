#pragma once

// CvGlobals.h
// ReplacementStep: search down here for 'CvInfoReplacements'

#ifndef CIV4_GLOBALS_H
#define CIV4_GLOBALS_H

//
// 'global' vars for Civ IV.  singleton class.
// All globals and global types should be contained in this class
//

class FProfiler;
class CvDLLUtilityIFaceBase;
class CvRandom;
class CvGameAI;
class CMessageControl;
class CvDropMgr;
class CMessageQueue;
class CvSetupData;
class CvInitCore;
class CvMessageCodeTranslator;
class CvPortal;
class CvStatsReporter;
class CvDLLInterfaceIFaceBase;
class CvDiplomacyScreen;
class CMPDiplomacyScreen;
class FMPIManager;
class FAStar;
class CvInterface;
class FVariableSystem;
class CvMap;
class CvMapExternal;
class CvViewport;
class CvInterfaceModeInfo;
class CvWorldInfo;
class CvClimateInfo;
class CvSeaLevelInfo;
class CvColorInfo;
class CvPlayerColorInfo;
class CvAdvisorInfo;
class CvRouteModelInfo;
class CvRiverModelInfo;
class CvWaterPlaneInfo;
class CvTerrainPlaneInfo;
class CvCameraOverlayInfo;
class CvAnimationPathInfo;
class CvAnimationCategoryInfo;
class CvEntityEventInfo;
class CvEffectInfo;
class CvAttachableInfo;
class CvUnitFormationInfo;
class CvLandscapeInfo;
class CvTerrainInfo;
class CvBonusClassInfo;
class CvBonusInfo;
class CvFeatureInfo;
class CvCivilizationInfo;
class CvLeaderHeadInfo;
class CvTraitInfo;
class CvCursorInfo;
class CvThroneRoomCamera;
class CvThroneRoomInfo;
class CvThroneRoomStyleInfo;
class CvSlideShowInfo;
class CvSlideShowRandomInfo;
class CvWorldPickerInfo;
class CvSpaceShipInfo;
class CvUnitInfo;
class CvSpawnInfo;
class CvSpecialUnitInfo;
class CvInfoBase;
class CvYieldInfo;
class CvCommerceInfo;
class CvRouteInfo;
class CvImprovementInfo;
class CvGoodyInfo;
class CvBuildInfo;
class CvHandicapInfo;
class CvGameSpeedInfo;
class CvTurnTimerInfo;
class CvProcessInfo;
class CvVoteInfo;
class CvProjectInfo;
class CvBuildingInfo;
class CvSpecialBuildingInfo;
class CvActionInfo;
class CvMissionInfo;
class CvControlInfo;
class CvCommandInfo;
class CvAutomateInfo;
class CvPromotionInfo;
class CvTechInfo;
class CvReligionInfo;
class CvCorporationInfo;
class CvSpecialistInfo;
class CvCivicOptionInfo;
class CvCivicInfo;
class CvDiplomacyInfo;
class CvEraInfo;
class CvHurryInfo;
class CvEmphasizeInfo;
class CvUpkeepInfo;
class CvCultureLevelInfo;
class CvVictoryInfo;
class CvQuestInfo;
class CvGameOptionInfo;
class CvMPOptionInfo;
class CvForceControlInfo;
class CvPlayerOptionInfo;
class CvGraphicOptionInfo;
class CvTutorialInfo;
class CvEventTriggerInfo;
class CvEventInfo;
class CvEspionageMissionInfo;
class CvUnitArtStyleTypeInfo;
class CvVoteSourceInfo;
class CvMainMenuInfo;
class CvPropertyInfo;
class CvOutcomeInfo;
class CvUnitCombatInfo;
//TB Promotion Line Mod begin
class CvPromotionLineInfo;
//TB Promotion Line Mod end
class CvMapCategoryInfo;
class CvIdeaClassInfo;
class CvIdeaInfo;
class CvInvisibleInfo;
//class CvTraitOptionEditsInfo;
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 10/24/07                                MRGENIE      */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
// MLF loading
class CvModLoadControlInfo;
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 END                                                  */
/************************************************************************************************/

/*********************************/
/***** Parallel Maps - Begin *****/
/*********************************/
class CvMapInfo;
class CvMapSwitchInfo;
/*******************************/
/***** Parallel Maps - End *****/
/*******************************/

#include "CvInfoReplacements.h"
#include "GlobalDefines.h"
#include <stack>

extern CvDLLUtilityIFaceBase* g_DLL;
extern CvGlobals* gGlobals;

class CvGlobals
{
	friend class CvXMLLoadUtility;
public:

	// singleton accessor
	DllExport inline static CvGlobals& getInstance() { return *gGlobals; }

	CvGlobals();
	virtual ~CvGlobals();

	DllExport void init();
	DllExport void uninit();
	void clearTypesMap();

	DllExport CvDiplomacyScreen* getDiplomacyScreen() 		{ return m_diplomacyScreen; }
	DllExport CMPDiplomacyScreen* getMPDiplomacyScreen() 	{ return m_mpDiplomacyScreen; }
	DllExport FMPIManager*& getFMPMgrPtr()	 				{ return m_pFMPMgr; }
	DllExport CvPortal& getPortal() 						{ return *m_portal; }
	DllExport CvSetupData& getSetupData() 					{ return *m_setupData; }
	DllExport CvInitCore& getInitCore() 					{ return *m_initCore; }
	DllExport CvInitCore& getLoadedInitCore() 				{ return *m_loadedInitCore; }
	DllExport CvInitCore& getIniInitCore() 					{ return *m_iniInitCore; }
	DllExport CvMessageCodeTranslator& getMessageCodes() 	{ return *m_messageCodes; }
	DllExport CvStatsReporter& getStatsReporter() 			{ return *m_statsReporter; }
	DllExport CvInterface& getInterface() 					{ return *m_interface; }
	DllExport CvInterface* getInterfacePtr() 				{ return m_interface; }

/*********************************/
/***** Parallel Maps - Begin *****/
/*********************************/
	DllExport inline CvMap& getMap();
	inline const CvMap& getMap() const;
	CvViewport* getCurrentViewport() const;
	int	getViewportSizeX() const;
	int	getViewportSizeY() const;
	int getViewportSelectionBorder() const;
	int getViewportCenteringBorder() const;
	CvMapExternal& getMapExternal() const;

	bool bugInitCalled() const;
	void enableMultiMaps() { m_bMultimapsEnabled = true; }
	bool multiMapsEnabled() const;
	bool viewportsEnabled() const;
	bool getReprocessGreatWallDynamically() const;
	int getNumMapInfos() const;
	int getNumMapSwitchInfos() const;
	CvMapInfo& getMapInfo(MapTypes eMap) const;
	CvMapSwitchInfo& getMapSwitchInfo(MapSwitchTypes eMapSwitch) const;

	void switchMap(MapTypes eMap);
	CvMap& getMapByIndex(MapTypes eIndex) const;
	int getNumMaps() const { return m_maps.size(); }
	void updateMaps();
	void initializeMap(MapTypes eMap);
	bool mapInitialized(MapTypes eMap) const;
	void clearSigns();
	void reprocessSigns();
	void setResourceLayer(bool bOn);
	bool getResourceLayer() const;
/*******************************/
/***** Parallel Maps - End *****/
/*******************************/

	inline const CvGameAI& getGame() const 			{ return *m_game; }
	DllExport inline CvGameAI& getGame()			{ return *m_game; }
	DllExport CvGameAI* getGamePointer() 			{ return m_game; }
	DllExport CvRandom& getASyncRand() 				{ return *m_asyncRand; }
	DllExport CMessageQueue& getMessageQueue()		{ return *m_messageQueue; }
	DllExport CMessageQueue& getHotMessageQueue()	{ return *m_hotJoinMsgQueue; }
	DllExport CMessageControl& getMessageControl()	{ return *m_messageControl; }
	DllExport CvDropMgr& getDropMgr() 				{ return *m_dropMgr; }
	DllExport FAStar& getPathFinder() 				{ return *m_pathFinder; }
	DllExport FAStar& getInterfacePathFinder() 		{ return *m_interfacePathFinder; }
	DllExport FAStar& getStepFinder() 				{ return *m_stepFinder; }
	DllExport FAStar& getRouteFinder() 				{ return *m_routeFinder; }
	DllExport FAStar& getBorderFinder() 			{ return *m_borderFinder; }
	DllExport FAStar& getAreaFinder() 				{ return *m_areaFinder; }
	DllExport FAStar& getPlotGroupFinder() 			{ return *m_plotGroupFinder; }

	DllExport std::vector<CvInterfaceModeInfo*>& getInterfaceModeInfos();
	DllExport CvInterfaceModeInfo& getInterfaceModeInfo(InterfaceModeTypes e);

	DllExport bool& getLogging() 					{ return m_bLogging; }
	DllExport bool& getRandLogging() 				{ return m_bRandLogging; }
	DllExport bool& getSynchLogging() 				{ return m_bSynchLogging; }
	DllExport bool& overwriteLogs() 				{ return m_bOverwriteLogs; }

	inline bool	getIsInPedia() const 				{ return m_bIsInPedia; }
	inline void	setIsInPedia(bool bNewValue) 		{ m_bIsInPedia = bNewValue; }

	DllExport int* getPlotDirectionX();
	DllExport int* getPlotDirectionY();
	DllExport int* getPlotCardinalDirectionX();
	DllExport int* getPlotCardinalDirectionY();
	int* getCityPlotX() const;
	int* getCityPlotY() const;
	int* getCityPlotPriority() const;
	int getXYCityPlot(int i, int j) const;
	DirectionTypes* getTurnLeftDirection() const;
	DirectionTypes getTurnLeftDirection(int i) const;
	DirectionTypes* getTurnRightDirection() const;
	DirectionTypes getTurnRightDirection(int i) const;
	DllExport DirectionTypes getXYDirection(int i, int j);

	//
	// Global Infos
	// All info type strings are upper case and are kept in this hash map for fast lookup
	//

	// returns the infos index, use this when searching for an info type string
	DllExport int getInfoTypeForString(const char* szType, bool hideAssert = false) const;
	void LogMissingType(const char* szType) const;
	bool hasInfoTypeForString(const char* szType, bool hideAssert = false) const;
	void setInfoTypeFromString(const char* szType, int idx);
	void logInfoTypeMap(const char* tagMsg = "");
	DllExport void infoTypeFromStringReset();
	void addToInfosVectors(void *infoVector);
	DllExport void infosReset();
	int getOrCreateInfoTypeForString(const char* szType);

	void addDelayedResolution(int* pType, CvString szString);
	CvString* getDelayedResolution(int* pType);
	void removeDelayedResolution(int* pType);
	void copyNonDefaultDelayedResolution(int* pTypeSelf, int* pTypeOther);
	template<class T>
	void copyNonDefaultDelayedResolutionVector(std::vector<T>& aTarget, std::vector<T>& aSource)
	{
		std::stack<CvString> aszTemp;
		std::vector<T>::iterator it = aTarget.end(), it2 = aSource.begin();
		while (it > aTarget.begin())
		{
			it--;
			aszTemp.push(*getDelayedResolution(&*it));
			removeDelayedResolution(&*it);
		}
		aTarget.insert(aTarget.end(), aSource.begin(), aSource.end());
		it = aTarget.begin(); // because insert() invalidates the previous iterator
		while (aszTemp.size())
		{
			addDelayedResolution(&*it++, aszTemp.top());
			aszTemp.pop();
		}
		while (it2 != aSource.end())
		{
			addDelayedResolution(&*it++, *getDelayedResolution(&*it2++));
		}
	}
	void resolveDelayedResolution();

	DllExport int getNumWorldInfos();
	DllExport CvWorldInfo& getWorldInfo(WorldSizeTypes e);

	DllExport int getNumClimateInfos();
	DllExport CvClimateInfo& getClimateInfo(ClimateTypes e);

	DllExport int getNumSeaLevelInfos();
	DllExport CvSeaLevelInfo& getSeaLevelInfo(SeaLevelTypes e);

	DllExport CvColorInfo& getColorInfo(ColorTypes e);
	int getNumColorInfos() const;

	DllExport int getNumPlayerColorInfos();
	DllExport CvPlayerColorInfo& getPlayerColorInfo(PlayerColorTypes e);

	int getNumAdvisorInfos() const;
	CvAdvisorInfo& getAdvisorInfo(AdvisorTypes e) const;

	DllExport int getNumHints();
	DllExport CvInfoBase& getHints(int i);

	int getNumMainMenus() const;
	DllExport CvMainMenuInfo& getMainMenus(int i);
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 10/30/07                            MRGENIE          */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
	// MLF loading
	void resetModLoadControlVector();
	int getModLoadControlVectorSize() const;
	void setModLoadControlVector(const char* szModule);
	CvString getModLoadControlVector(int i) const;

	int getTotalNumModules() const;
	void setTotalNumModules();
	int getNumModLoadControlInfos() const;
	CvModLoadControlInfo& getModLoadControlInfos(int i) const;
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 END                                                  */
/************************************************************************************************/
/************************************************************************************************/
/* XML_MODULAR_ART_LOADING                 10/26/07                            MRGENIE          */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
	void setModDir(const char* szModDir);
	std::string getModDir() const;
	std::string m_cszModDir;
/************************************************************************************************/
/* XML_MODULAR_ART_LOADING                 END                                                  */
/************************************************************************************************/

	DllExport int getNumRouteModelInfos();
	DllExport CvRouteModelInfo& getRouteModelInfo(int i);

	DllExport int getNumRiverModelInfos();
	DllExport CvRiverModelInfo& getRiverModelInfo(int i);

	int getNumWaterPlaneInfos() const;
	DllExport CvWaterPlaneInfo& getWaterPlaneInfo(int i);

	DllExport int getNumTerrainPlaneInfos();
	DllExport CvTerrainPlaneInfo& getTerrainPlaneInfo(int i);

	DllExport int getNumCameraOverlayInfos();
	DllExport CvCameraOverlayInfo& getCameraOverlayInfo(int i);

	int getNumAnimationPathInfos() const;
	DllExport CvAnimationPathInfo& getAnimationPathInfo(AnimationPathTypes e);

	int getNumAnimationCategoryInfos() const;
	DllExport CvAnimationCategoryInfo& getAnimationCategoryInfo(AnimationCategoryTypes e);

	int getNumEntityEventInfos() const;
	DllExport CvEntityEventInfo& getEntityEventInfo(EntityEventTypes e);

	int getNumEffectInfos() const;
	DllExport CvEffectInfo& getEffectInfo(int i);

	int getNumAttachableInfos() const;
	DllExport CvAttachableInfo& getAttachableInfo(int i);

	DllExport int getNumUnitFormationInfos();
	DllExport CvUnitFormationInfo& getUnitFormationInfo(int i);

	int getNumLandscapeInfos() const;
	DllExport CvLandscapeInfo& getLandscapeInfo(int iIndex);
	DllExport int getActiveLandscapeID();
	DllExport void setActiveLandscapeID(int iLandscapeID);

	DllExport int getNumTerrainInfos();
	DllExport CvTerrainInfo& getTerrainInfo(TerrainTypes eTerrainNum);

	int getNumBonusClassInfos() const;
	CvBonusClassInfo& getBonusClassInfo(BonusClassTypes eBonusNum) const;

	DllExport int getNumBonusInfos();
	const std::vector<CvBonusInfo*>& getBonusInfos() const;
	DllExport CvBonusInfo& getBonusInfo(BonusTypes eBonusNum);

	DllExport int getNumFeatureInfos();
	DllExport CvFeatureInfo& getFeatureInfo(FeatureTypes eFeatureNum);

	DllExport int& getNumPlayableCivilizationInfos();
	DllExport int& getNumAIPlayableCivilizationInfos();
	DllExport int getNumCivilizationInfos();
	DllExport CvCivilizationInfo& getCivilizationInfo(CivilizationTypes eCivilizationNum);

	DllExport int getNumLeaderHeadInfos();
	DllExport CvLeaderHeadInfo& getLeaderHeadInfo(LeaderHeadTypes eLeaderHeadNum);

	int getNumTraitInfos() const;
	CvTraitInfo& getTraitInfo(TraitTypes eTraitNum) const;

	DllExport int getNumCursorInfos();
	DllExport CvCursorInfo& getCursorInfo(CursorTypes eCursorNum);

	int getNumThroneRoomCameras() const;
	DllExport CvThroneRoomCamera& getThroneRoomCamera(int iIndex);

	int getNumThroneRoomInfos() const;
	DllExport CvThroneRoomInfo& getThroneRoomInfo(int iIndex);

	DllExport int getNumThroneRoomStyleInfos();
	DllExport CvThroneRoomStyleInfo& getThroneRoomStyleInfo(int iIndex);

	DllExport int getNumSlideShowInfos();
	DllExport CvSlideShowInfo& getSlideShowInfo(int iIndex);

	DllExport int getNumSlideShowRandomInfos();
	DllExport CvSlideShowRandomInfo& getSlideShowRandomInfo(int iIndex);

	DllExport int getNumWorldPickerInfos();
	DllExport CvWorldPickerInfo& getWorldPickerInfo(int iIndex);

	DllExport int getNumSpaceShipInfos();
	DllExport CvSpaceShipInfo& getSpaceShipInfo(int iIndex);

	int getNumUnitInfos() const;
	CvUnitInfo& getUnitInfo(UnitTypes eUnitNum) const;

	int getNumSpawnInfos() const;
	CvSpawnInfo& getSpawnInfo(SpawnTypes eSpawnNum) const;

	int getNumSpecialUnitInfos() const;
	CvSpecialUnitInfo& getSpecialUnitInfo(SpecialUnitTypes eSpecialUnitNum) const;

	int getNumConceptInfos() const;
	CvInfoBase& getConceptInfo(ConceptTypes e) const;

	int getNumNewConceptInfos() const;
	CvInfoBase& getNewConceptInfo(NewConceptTypes e) const;

	int getNumPropertyInfos() const;
	CvPropertyInfo& getPropertyInfo(PropertyTypes ePropertyNum) const;

	int getNumOutcomeInfos() const;
	CvOutcomeInfo& getOutcomeInfo(OutcomeTypes eOutcomeNum) const;

	int iStuckUnitID;
	int iStuckUnitCount;

	bool isXMLLogging() const;
	void setXMLLogging(bool bNewVal);

	void updateReplacements();

#define DECLARE_GET_METHOD(dataType, VAR) \
	dataType get##VAR() const { return m_##VAR; }
	DO_FOR_EACH_INT_GLOBAL_DEFINE(DECLARE_GET_METHOD)
	DO_FOR_EACH_ENUM_GLOBAL_DEFINE(DECLARE_GET_METHOD)
	DO_FOR_EACH_FLOAT_GLOBAL_DEFINE(DECLARE_GET_METHOD)

#define DECLARE_BOOL_GET_METHOD(dataType, VAR) \
	dataType is##VAR() const { return m_##VAR; }
	DO_FOR_EACH_BOOL_GLOBAL_DEFINE(DECLARE_BOOL_GET_METHOD)

	int getNumCityTabInfos() const;
	CvInfoBase& getCityTabInfo(CityTabTypes e) const;

	int getNumCalendarInfos() const;
	CvInfoBase& getCalendarInfo(CalendarTypes e) const;

	int getNumSeasonInfos() const;
	CvInfoBase& getSeasonInfo(SeasonTypes e) const;

	int getNumMonthInfos() const;
	CvInfoBase& getMonthInfo(MonthTypes e) const;

	int getNumDenialInfos() const;
	CvInfoBase& getDenialInfo(DenialTypes e) const;

	int getNumInvisibleInfos() const;
	CvInvisibleInfo& getInvisibleInfo(InvisibleTypes e) const;

	int getNumVoteSourceInfos() const;
	CvVoteSourceInfo& getVoteSourceInfo(VoteSourceTypes e) const;

	int getNumUnitCombatInfos() const;
	CvUnitCombatInfo& getUnitCombatInfo(UnitCombatTypes e) const;

	CvInfoBase& getDomainInfo(DomainTypes e) const;

	int getNumPromotionLineInfos() const;
	CvPromotionLineInfo& getPromotionLineInfo(PromotionLineTypes e) const;

	int getNumMapCategoryInfos() const;
	CvMapCategoryInfo& getMapCategoryInfo(MapCategoryTypes e) const;

	int getNumIdeaClassInfos() const;
	CvIdeaClassInfo& getIdeaClassInfo(IdeaClassTypes e) const;

	int getNumIdeaInfos() const;
	CvIdeaInfo& getIdeaInfo(IdeaTypes e) const;

	CvInfoBase& getUnitAIInfo(UnitAITypes eUnitAINum) const;

	//	Koshling - added internal registration of supported UnitAI types, not reliant
	//	on external definition in XML
private:
	void registerUnitAI(const char* szType, int enumVal);
	void registerMission(const char* szType, int enumVal);
public:
	void registerUnitAIs();
	void registerAIScales();
	void registerGameObjects();
	void registerGOMs();
	void registerRelations();
	void registerAttributes();
	void registerTags();
	void registerPropertySources();
	void registerPropertyInteractions();
	void registerPropertyPropagators();
	void registerMissions();

	CvInfoBase& getAttitudeInfo(AttitudeTypes eAttitudeNum) const;

	CvInfoBase& getMemoryInfo(MemoryTypes eMemoryNum) const;

	int getNumGameOptionInfos() const;
	DllExport CvGameOptionInfo& getGameOptionInfo(GameOptionTypes eGameOptionNum);

	int getNumMPOptionInfos() const;
	DllExport CvMPOptionInfo& getMPOptionInfo(MultiplayerOptionTypes eMPOptionNum);

	int getNumForceControlInfos() const;
	CvForceControlInfo& getForceControlInfo(ForceControlTypes eForceControlNum) const;

	DllExport CvPlayerOptionInfo& getPlayerOptionInfo(PlayerOptionTypes ePlayerOptionNum);

	DllExport CvGraphicOptionInfo& getGraphicOptionInfo(GraphicOptionTypes eGraphicOptionNum);

	CvYieldInfo& getYieldInfo(YieldTypes eYieldNum) const;

	CvCommerceInfo& getCommerceInfo(CommerceTypes eCommerceNum) const;

	DllExport int getNumRouteInfos();
	CvRouteInfo& getRouteInfo(RouteTypes eRouteNum) const;

	DllExport int getNumImprovementInfos();
	DllExport CvImprovementInfo& getImprovementInfo(ImprovementTypes eImprovementNum);

	int getNumGoodyInfos() const;
	CvGoodyInfo& getGoodyInfo(GoodyTypes eGoodyNum) const;

	int getNumBuildInfos() const;
	DllExport CvBuildInfo& getBuildInfo(BuildTypes eBuildNum);

	DllExport int getNumHandicapInfos();
	DllExport CvHandicapInfo& getHandicapInfo(HandicapTypes eHandicapNum);

	DllExport int getNumGameSpeedInfos();
	DllExport CvGameSpeedInfo& getGameSpeedInfo(GameSpeedTypes eGameSpeedNum);

	DllExport int getNumTurnTimerInfos();
	DllExport CvTurnTimerInfo& getTurnTimerInfo(TurnTimerTypes eTurnTimerNum);

	int getNumProcessInfos() const;
	CvProcessInfo& getProcessInfo(ProcessTypes e) const;

	int getNumVoteInfos() const;
	CvVoteInfo& getVoteInfo(VoteTypes e) const;

	int getNumProjectInfos() const;
	CvProjectInfo& getProjectInfo(ProjectTypes e) const;

	int getNumBuildingInfos() const;
	CvBuildingInfo& getBuildingInfo(BuildingTypes eBuildingNum) const;

	int getNumSpecialBuildingInfos() const;
	CvSpecialBuildingInfo& getSpecialBuildingInfo(SpecialBuildingTypes eSpecialBuildingNum) const;

	DllExport int getNumActionInfos();
	DllExport CvActionInfo& getActionInfo(int i);

	int getNumMissionInfos() const;
	DllExport CvMissionInfo& getMissionInfo(MissionTypes eMissionNum);

	CvControlInfo& getControlInfo(ControlTypes eControlNum) const;

	CvCommandInfo& getCommandInfo(CommandTypes eCommandNum) const;

	int getNumAutomateInfos() const;
	CvAutomateInfo& getAutomateInfo(int iAutomateNum) const;

	int getNumPromotionInfos() const;
	CvPromotionInfo& getPromotionInfo(PromotionTypes ePromotionNum) const;
	typedef bst::function<bool(const CvPromotionInfo*, PromotionTypes)> PromotionPredicateFn;
	PromotionTypes findPromotion(PromotionPredicateFn predicateFn) const;

	int getNumTechInfos() const;
	CvTechInfo& getTechInfo(TechTypes eTechNum) const;

	int getNumReligionInfos() const;
	CvReligionInfo& getReligionInfo(ReligionTypes eReligionNum) const;

	int getNumCorporationInfos() const;
	CvCorporationInfo& getCorporationInfo(CorporationTypes eCorporationNum) const;

	int getNumSpecialistInfos() const;
	CvSpecialistInfo& getSpecialistInfo(SpecialistTypes eSpecialistNum) const;

	int getNumCivicOptionInfos() const;
	CvCivicOptionInfo& getCivicOptionInfo(CivicOptionTypes eCivicOptionNum) const;

	int getNumCivicInfos() const;
	CvCivicInfo& getCivicInfo(CivicTypes eCivicNum) const;

	int getNumDiplomacyInfos() const;
	CvDiplomacyInfo& getDiplomacyInfo(int iDiplomacyNum) const;

	DllExport int getNumEraInfos();
	DllExport CvEraInfo& getEraInfo(EraTypes eEraNum);

	int getNumHurryInfos() const;
	CvHurryInfo& getHurryInfo(HurryTypes eHurryNum) const;

	int getNumEmphasizeInfos() const;
	CvEmphasizeInfo& getEmphasizeInfo(EmphasizeTypes eEmphasizeNum) const;

	int getNumUpkeepInfos() const;
	CvUpkeepInfo& getUpkeepInfo(UpkeepTypes eUpkeepNum) const;

	int getNumCultureLevelInfos() const;
	CvCultureLevelInfo& getCultureLevelInfo(CultureLevelTypes eCultureLevelNum) const;

	DllExport int getNumVictoryInfos();
	DllExport CvVictoryInfo& getVictoryInfo(VictoryTypes eVictoryNum);

	int getNumQuestInfos() const;
	CvQuestInfo& getQuestInfo(int iIndex) const;

	int getNumTutorialInfos() const;
	CvTutorialInfo& getTutorialInfo(int i) const;

	int getNumEventTriggerInfos() const;
	CvEventTriggerInfo& getEventTriggerInfo(EventTriggerTypes eEventTrigger) const;

	int getNumEventInfos() const;
	CvEventInfo& getEventInfo(EventTypes eEvent) const;

	int getNumEspionageMissionInfos() const;
	CvEspionageMissionInfo& getEspionageMissionInfo(EspionageMissionTypes eEspionageMissionNum) const;

	int getNumUnitArtStyleTypeInfos() const;
	CvUnitArtStyleTypeInfo& getUnitArtStyleTypeInfo(UnitArtStyleTypes eUnitArtStyleTypeNum) const;

	//
	// Global Types
	// All type strings are upper case and are kept in this hash map for fast lookup
	// The other functions are kept for convenience when enumerating, but most are not used
	//
	DllExport int getTypesEnum(const char* szType) const;				// use this when searching for a type
	void setTypesEnum(const char* szType, int iEnum);

	int& getNumEntityEventTypes();
	CvString*& getEntityEventTypes();
	CvString& getEntityEventTypes(EntityEventTypes e);

	int& getNumAnimationOperatorTypes();
	CvString*& getAnimationOperatorTypes();
	CvString& getAnimationOperatorTypes(AnimationOperatorTypes e);

	CvString*& getFunctionTypes();
	CvString& getFunctionTypes(FunctionTypes e);

	int& getNumFlavorTypes();
	CvString*& getFlavorTypes();
	CvString& getFlavorTypes(FlavorTypes e);

	DllExport int& getNumArtStyleTypes();
	CvString*& getArtStyleTypes();
	DllExport CvString& getArtStyleTypes(ArtStyleTypes e);

	int& getNumCitySizeTypes();
	CvString*& getCitySizeTypes();
	CvString& getCitySizeTypes(int i);

	CvString*& getContactTypes();
	CvString& getContactTypes(ContactTypes e);

	CvString*& getDiplomacyPowerTypes();
	CvString& getDiplomacyPowerTypes(DiplomacyPowerTypes e);

	CvString*& getAutomateTypes();
	CvString& getAutomateTypes(AutomateTypes e);

	CvString*& getDirectionTypes();
	CvString& getDirectionTypes(AutomateTypes e);

	DllExport int& getNumFootstepAudioTypes();
	CvString*& getFootstepAudioTypes();
	CvString& getFootstepAudioTypes(int i);
	int getFootstepAudioTypeByTag(const CvString strTag) const;

	CvString*& getFootstepAudioTags();
	DllExport CvString& getFootstepAudioTags(int i) const;

	const CvString& getCurrentXMLFile() const;
	void setCurrentXMLFile(const TCHAR* szFileName);

	DllExport FVariableSystem* getDefinesVarSystem() { return m_VarSystem; }
	void cacheEnumGlobals();
	void cacheGlobals();

	void setGraphicalDetailPagingEnabled(bool bEnabled);
	bool getGraphicalDetailPagingEnabled() const;
	int getGraphicalDetailPageInRange() const;

	bool getDefineBOOL(const char* szName) const;
	DllExport int getDefineINT(const char* szName) const;
	DllExport float getDefineFLOAT(const char* szName) const;
	DllExport const char* getDefineSTRING(const char* szName) const;

	void setDefineINT( const char * szName, int iValue, bool bUpdate = true);
	void setDefineFLOAT( const char * szName, float fValue, bool bUpdate = true );
	void setDefineSTRING( const char * szName, const char * szValue, bool bUpdate = true );

	DllExport float getPLOT_SIZE();

	// This determines how many starting civs can be chosen in the custom game staging room screen.
	// Currently it allows you to add more civs than there are civ slots.
	// If this is reduced to the correct number, the city bar and city graphics for the neanderthal NPC will never be updated as the exe doesn't understand that their cities exist.
	DllExport int getMaxCivPlayers() const	{ return MAX_PLAYERS-1; }

	int getMAX_PC_PLAYERS() const		{ return MAX_PC_PLAYERS; }
	int getMAX_PLAYERS() const			{ return MAX_PLAYERS; }
	int getMAX_PC_TEAMS() const			{ return MAX_PC_TEAMS; }
	int getMAX_TEAMS() const			{ return MAX_TEAMS; }
	int getBARBARIAN_PLAYER() const		{ return BARBARIAN_PLAYER; }
	int getBARBARIAN_TEAM() const		{ return BARBARIAN_TEAM; }
	int getNEANDERTHAL_PLAYER() const	{ return NEANDERTHAL_PLAYER; }
	int getNEANDERTHAL_TEAM() const		{ return NEANDERTHAL_TEAM; }
	int getBEAST_PLAYER() const			{ return BEAST_PLAYER; }
	int getBEAST_TEAM() const			{ return BEAST_TEAM; }
	int getPREDATOR_PLAYER() const		{ return PREDATOR_PLAYER; }
	int getPREDATOR_TEAM() const		{ return PREDATOR_TEAM; }
	int getPREY_PLAYER() const			{ return PREY_PLAYER; }
	int getPREY_TEAM() const			{ return PREY_TEAM; }
	int getINSECT_PLAYER() const		{ return INSECT_PLAYER; }
	int getINSECT_TEAM() const			{ return INSECT_TEAM; }
	int getNPC4_PLAYER() const			{ return NPC4_PLAYER; }
	int getNPC4_TEAM() const			{ return NPC4_TEAM; }
	int getNPC3_PLAYER() const			{ return NPC3_PLAYER; }
	int getNPC3_TEAM() const			{ return NPC3_TEAM; }
	int getNPC2_PLAYER() const			{ return NPC2_PLAYER; }
	int getNPC2_TEAM() const			{ return NPC2_TEAM; }
	int getNPC1_PLAYER() const			{ return NPC1_PLAYER; }
	int getNPC1_TEAM() const			{ return NPC1_TEAM; }
	int getNPC0_PLAYER() const			{ return NPC0_PLAYER; }
	int getNPC0_TEAM() const			{ return NPC0_TEAM; }

	CvDLLUtilityIFaceBase* getDLLIFace() const { return g_DLL; }		// inlined for perf reasons, do not use outside of dll
	DllExport CvDLLUtilityIFaceBase* getDLLIFaceNonInl();
	DllExport void setDLLProfiler(FProfiler* prof);
	FProfiler* getDLLProfiler() const;
	DllExport void enableDLLProfiler(bool bEnable);
	bool isDLLProfilerEnabled() const;
	const char* alternateProfileSampleName() const;

	DllExport bool IsGraphicsInitialized() const;
	DllExport void SetGraphicsInitialized(bool bVal);

	// for caching
	DllExport bool readBuildingInfoArray(FDataStreamBase* pStream);
	DllExport void writeBuildingInfoArray(FDataStreamBase* pStream);

	DllExport bool readTechInfoArray(FDataStreamBase* pStream);
	DllExport void writeTechInfoArray(FDataStreamBase* pStream);

	DllExport bool readUnitInfoArray(FDataStreamBase* pStream);
	DllExport void writeUnitInfoArray(FDataStreamBase* pStream);

	DllExport bool readLeaderHeadInfoArray(FDataStreamBase* pStream);
	DllExport void writeLeaderHeadInfoArray(FDataStreamBase* pStream);

	DllExport bool readCivilizationInfoArray(FDataStreamBase* pStream);
	DllExport void writeCivilizationInfoArray(FDataStreamBase* pStream);

	DllExport bool readPromotionInfoArray(FDataStreamBase* pStream);
	DllExport void writePromotionInfoArray(FDataStreamBase* pStream);

	DllExport bool readDiplomacyInfoArray(FDataStreamBase* pStream);
	DllExport void writeDiplomacyInfoArray(FDataStreamBase* pStream);

	DllExport bool readCivicInfoArray(FDataStreamBase* pStream);
	DllExport void writeCivicInfoArray(FDataStreamBase* pStream);

	DllExport bool readHandicapInfoArray(FDataStreamBase* pStream);
	DllExport void writeHandicapInfoArray(FDataStreamBase* pStream);

	DllExport bool readBonusInfoArray(FDataStreamBase* pStream);
	DllExport void writeBonusInfoArray(FDataStreamBase* pStream);

	DllExport bool readImprovementInfoArray(FDataStreamBase* pStream);
	DllExport void writeImprovementInfoArray(FDataStreamBase* pStream);

	DllExport bool readEventInfoArray(FDataStreamBase* pStream);
	DllExport void writeEventInfoArray(FDataStreamBase* pStream);

	DllExport bool readEventTriggerInfoArray(FDataStreamBase* pStream);
	DllExport void writeEventTriggerInfoArray(FDataStreamBase* pStream);

	//
	// additional accessors for initting globals
	//
	DllExport void setDLLIFace(CvDLLUtilityIFaceBase* pDll);
	DllExport void setInterface(CvInterface* pVal);
	DllExport void setDiplomacyScreen(CvDiplomacyScreen* pVal);
	DllExport void setMPDiplomacyScreen(CMPDiplomacyScreen* pVal);
	DllExport void setMessageQueue(CMessageQueue* pVal);
	DllExport void setHotJoinMessageQueue(CMessageQueue* pVal);
	DllExport void setMessageControl(CMessageControl* pVal);
	DllExport void setSetupData(CvSetupData* pVal);
	DllExport void setMessageCodeTranslator(CvMessageCodeTranslator* pVal);
	DllExport void setDropMgr(CvDropMgr* pVal);
	DllExport void setPortal(CvPortal* pVal);
	DllExport void setStatsReport(CvStatsReporter* pVal);
	DllExport void setPathFinder(FAStar* pVal);
	DllExport void setInterfacePathFinder(FAStar* pVal);
	DllExport void setStepFinder(FAStar* pVal);
	DllExport void setRouteFinder(FAStar* pVal);
	DllExport void setBorderFinder(FAStar* pVal);
	DllExport void setAreaFinder(FAStar* pVal);
	DllExport void setPlotGroupFinder(FAStar* pVal);

	void setIsBug(bool bIsBug);

	unsigned int getAssetCheckSum();

	void deleteInfoArrays();
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 11/30/07                                MRGENIE      */
/*                                                                                              */
/* Savegame compatibility                                                                       */
/************************************************************************************************/
	void doResetInfoClasses(int iNumSaveGameVector, std::vector<CvString> m_aszSaveGameVector);
	void StoreExeSettings();
	void LoadExeSettings();
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 END                                                  */
/************************************************************************************************/

	DllExport int getNUM_ENGINE_DIRTY_BITS() const		{ return NUM_ENGINE_DIRTY_BITS; }
	DllExport int getNUM_INTERFACE_DIRTY_BITS() const	{ return NUM_INTERFACE_DIRTY_BITS; }
	DllExport int getNUM_YIELD_TYPES() const			{ return NUM_YIELD_TYPES; }
	DllExport int getNUM_FORCECONTROL_TYPES() const		{ return NUM_FORCECONTROL_TYPES; }
	DllExport int getNUM_INFOBAR_TYPES() const			{ return NUM_INFOBAR_TYPES; }
	DllExport int getNUM_HEALTHBAR_TYPES() const		{ return NUM_HEALTHBAR_TYPES; }
	DllExport int getNUM_LEADERANIM_TYPES() const		{ return NUM_LEADERANIM_TYPES; }

	DllExport int getNumDirections() const				{ return NUM_DIRECTION_TYPES; }
	DllExport int getNumGameOptions() const				{ return getNumGameOptionInfos(); }
	DllExport int getNumMPOptions() const				{ return NUM_MPOPTION_TYPES; }
	DllExport int getNumSpecialOptions() const			{ return NUM_SPECIALOPTION_TYPES; }
	DllExport int getNumGraphicOptions() const			{ return NUM_GRAPHICOPTION_TYPES; }
	DllExport int getNumTradeableItems() const			{ return NUM_TRADEABLE_ITEMS; }
	DllExport int getNumBasicItems() const				{ return NUM_BASIC_ITEMS; }
	DllExport int getNumTradeableHeadings() const		{ return NUM_TRADEABLE_HEADINGS; }
	DllExport int getNumPlayerOptionInfos() const		{ return NUM_PLAYEROPTION_TYPES; }
	DllExport int getMaxNumSymbols() const				{ return MAX_NUM_SYMBOLS; }
	DllExport int getNumGraphicLevels() const			{ return NUM_GRAPHICLEVELS; }

	//
	///////////////// BEGIN global defines
	// THESE ARE READ-ONLY
	//
	DllExport int getMAX_PLOT_LIST_ROWS()			{ return m_MAX_PLOT_LIST_ROWS; }
	DllExport int getUNIT_MULTISELECT_MAX()			{ return m_UNIT_MULTISELECT_MAX; }
	DllExport int getEVENT_MESSAGE_TIME()			{ return m_EVENT_MESSAGE_TIME; }
	DllExport float getCAMERA_MIN_YAW()				{ return m_CAMERA_MIN_YAW; }
	DllExport float getCAMERA_MAX_YAW()				{ return m_CAMERA_MAX_YAW; }
	DllExport float getCAMERA_FAR_CLIP_Z_HEIGHT()	{ return m_CAMERA_FAR_CLIP_Z_HEIGHT; }
	DllExport float getCAMERA_MAX_TRAVEL_DISTANCE()	{ return m_CAMERA_MAX_TRAVEL_DISTANCE; }
	DllExport float getCAMERA_START_DISTANCE()		{ return m_CAMERA_START_DISTANCE; }
	DllExport float getAIR_BOMB_HEIGHT()			{ return m_AIR_BOMB_HEIGHT; }
	DllExport float getCAMERA_SPECIAL_PITCH()		{ return m_CAMERA_SPECIAL_PITCH; }
	DllExport float getCAMERA_MAX_TURN_OFFSET()		{ return m_CAMERA_MAX_TURN_OFFSET; }
	DllExport float getCAMERA_MIN_DISTANCE()		{ return m_CAMERA_MIN_DISTANCE; }
	DllExport float getCAMERA_UPPER_PITCH()			{ return m_CAMERA_UPPER_PITCH; }
	DllExport float getCAMERA_LOWER_PITCH()			{ return m_CAMERA_LOWER_PITCH; }
	DllExport float getFIELD_OF_VIEW()				{ return m_FIELD_OF_VIEW; }
	DllExport float getSHADOW_SCALE()				{ return m_SHADOW_SCALE; }
	DllExport float getUNIT_MULTISELECT_DISTANCE()	{ return m_UNIT_MULTISELECT_DISTANCE; }
	DllExport int getUSE_FINISH_TEXT_CALLBACK()		{ return m_USE_FINISH_TEXT_CALLBACK; }
	DllExport int getMAX_CIV_PLAYERS()				{ return MAX_PC_PLAYERS; }

	////////////// END DEFINES //////////////////

protected:
	bool m_bGraphicsInitialized;
	bool m_bDLLProfiler;
	bool m_bLogging;
	bool m_bRandLogging;
	bool m_bSynchLogging;
	bool m_bOverwriteLogs;

	FMPIManager* m_pFMPMgr;
	CvRandom* m_asyncRand;
	CvGameAI* m_game;
	CMessageQueue* m_messageQueue;
	CMessageQueue* m_hotJoinMsgQueue;
	CMessageControl* m_messageControl;
	CvSetupData* m_setupData;
	CvInitCore* m_iniInitCore;
	CvInitCore* m_loadedInitCore;
	CvInitCore* m_initCore;
	CvMessageCodeTranslator * m_messageCodes;
	CvDropMgr* m_dropMgr;
	CvPortal* m_portal;
	CvStatsReporter * m_statsReporter;
	CvInterface* m_interface;
	CvDiplomacyScreen* m_diplomacyScreen;
	CMPDiplomacyScreen* m_mpDiplomacyScreen;
	FAStar* m_pathFinder;
	FAStar* m_interfacePathFinder;
	FAStar* m_stepFinder;
	FAStar* m_routeFinder;
	FAStar* m_borderFinder;
	FAStar* m_areaFinder;
	FAStar* m_plotGroupFinder;

/*********************************/
/***** Parallel Maps - Begin *****/
/*********************************/
	std::vector<CvMap*> m_maps;
	bool	m_bResourceLayerOn;
/*******************************/
/***** Parallel Maps - End *****/
/*******************************/

	int* m_aiPlotDirectionX;	// [NUM_DIRECTION_TYPES];
	int* m_aiPlotDirectionY;	// [NUM_DIRECTION_TYPES];
	int* m_aiPlotCardinalDirectionX;	// [NUM_CARDINALDIRECTION_TYPES];
	int* m_aiPlotCardinalDirectionY;	// [NUM_CARDINALDIRECTION_TYPES];
	int* m_aiCityPlotX;	// [NUM_CITY_PLOTS];
	int* m_aiCityPlotY;	// [NUM_CITY_PLOTS];
	int* m_aiCityPlotPriority;	// [NUM_CITY_PLOTS];
	int m_aaiXYCityPlot[CITY_PLOTS_DIAMETER][CITY_PLOTS_DIAMETER];

	DirectionTypes* m_aeTurnLeftDirection;	// [NUM_DIRECTION_TYPES];
	DirectionTypes* m_aeTurnRightDirection;	// [NUM_DIRECTION_TYPES];
	DirectionTypes m_aaeXYDirection[DIRECTION_DIAMETER][DIRECTION_DIAMETER];

	std::vector<CvInterfaceModeInfo*> m_paInterfaceModeInfo;

	/***********************************************************************************************************************
	Globals loaded from XML
	************************************************************************************************************************/

	// Hash function for zero terminated strings.
	struct SZStringHash {
		enum { // parameters for hash table
			bucket_size = 4, // 0 < bucket_size
			min_buckets = 4096,
		};
		typedef const char* Key;

		// Hashing from https://create.stephan-brumme.com/fnv-hash/
		static const size_t Prime = 0x01000193; //   16777619
		static const size_t Seed = 0x811C9DC5;  // 2166136261

		// hash a single byte
		static inline size_t fnv1a(unsigned char oneByte, size_t hash = Seed)
		{
			return (oneByte ^ hash) * Prime;
		}

		// hash a block of memory
		static inline size_t fnv1a(const void* data, size_t numBytes, size_t hash = Seed)
		{
			assert(data);
			const unsigned char* ptr = (const unsigned char*)data;
			while (numBytes--)
				hash = fnv1a(*ptr++, hash);
			return hash;
		}

		size_t operator()(const Key& key) const
		{
			return fnv1a(key, strlen(key));
		}

		bool operator()(const Key& key1, const Key& key2) const
		{
			return strcmp(key1, key2) > 0;
		}
	};

	// all type strings are upper case and are kept in this hash map for fast lookup, Moose
	typedef stdext::hash_map<const char* /* type */, int /* info index */, SZStringHash> InfosMap;
	InfosMap m_infosMap;
	std::vector<std::vector<CvInfoBase *> *> m_aInfoVectors;

	int m_iLastTypeID; // last generic type ID assigned (for type strings that do not have an assigned info class)

	// AIAndy: Delayed resolution of type strings
	typedef std::map<int*,std::pair<CvString,CvString> > DelayedResolutionMap;
	DelayedResolutionMap m_delayedResolutionMap;

	std::vector<CvColorInfo*> m_paColorInfo;
	std::vector<CvPlayerColorInfo*> m_paPlayerColorInfo;
	std::vector<CvAdvisorInfo*> m_paAdvisorInfo;
	std::vector<CvInfoBase*> m_paHints;
	std::vector<CvMainMenuInfo*> m_paMainMenus;
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 10/30/07                            MRGENIE          */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
	// MLF loading
	std::vector<CvString> m_paModLoadControlVector;
	std::vector<CvModLoadControlInfo*> m_paModLoadControls;
	int m_iTotalNumModules;

/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 END                                                  */
/************************************************************************************************/
	std::vector<CvTerrainInfo*> m_paTerrainInfo;
	CvInfoReplacements<CvTerrainInfo> m_TerrainInfoReplacements;
	std::vector<CvLandscapeInfo*> m_paLandscapeInfo;
	int m_iActiveLandscapeID;
	std::vector<CvWorldInfo*> m_paWorldInfo;
	CvInfoReplacements<CvWorldInfo> m_WorldInfoReplacements;
	std::vector<CvClimateInfo*> m_paClimateInfo;
	std::vector<CvSeaLevelInfo*> m_paSeaLevelInfo;
	std::vector<CvYieldInfo*> m_paYieldInfo;
	std::vector<CvCommerceInfo*> m_paCommerceInfo;
	std::vector<CvRouteInfo*> m_paRouteInfo;
	CvInfoReplacements<CvRouteInfo> m_RouteInfoReplacements;
	std::vector<CvFeatureInfo*> m_paFeatureInfo;
	CvInfoReplacements<CvFeatureInfo> m_FeatureInfoReplacements;
	std::vector<CvBonusClassInfo*> m_paBonusClassInfo;
	CvInfoReplacements<CvBonusClassInfo> m_BonusClassInfoReplacements;
	std::vector<CvBonusInfo*> m_paBonusInfo;
	CvInfoReplacements<CvBonusInfo> m_BonusInfoReplacements;
	std::vector<CvImprovementInfo*> m_paImprovementInfo;
	CvInfoReplacements<CvImprovementInfo> m_ImprovementInfoReplacements;
	std::vector<CvGoodyInfo*> m_paGoodyInfo;
	std::vector<CvBuildInfo*> m_paBuildInfo;
	CvInfoReplacements<CvBuildInfo> m_BuildInfoReplacements;
	std::vector<CvHandicapInfo*> m_paHandicapInfo;
	CvInfoReplacements<CvHandicapInfo> m_HandicapInfoReplacements;
	std::vector<CvGameSpeedInfo*> m_paGameSpeedInfo;
	CvInfoReplacements<CvGameSpeedInfo> m_GameSpeedInfoReplacements;
	std::vector<CvTurnTimerInfo*> m_paTurnTimerInfo;
	std::vector<CvCivilizationInfo*> m_paCivilizationInfo;
	CvInfoReplacements<CvCivilizationInfo> m_CivilizationInfoReplacements;
	int m_iNumPlayableCivilizationInfos;
	int m_iNumAIPlayableCivilizationInfos;
	std::vector<CvLeaderHeadInfo*> m_paLeaderHeadInfo;
	CvInfoReplacements<CvLeaderHeadInfo> m_LeaderHeadInfoReplacements;
	std::vector<CvTraitInfo*> m_paTraitInfo;
	CvInfoReplacements<CvTraitInfo> m_TraitInfoReplacements;
	std::vector<CvCursorInfo*> m_paCursorInfo;
	std::vector<CvThroneRoomCamera*> m_paThroneRoomCamera;
	std::vector<CvThroneRoomInfo*> m_paThroneRoomInfo;
	std::vector<CvThroneRoomStyleInfo*> m_paThroneRoomStyleInfo;
	std::vector<CvSlideShowInfo*> m_paSlideShowInfo;
	std::vector<CvSlideShowRandomInfo*> m_paSlideShowRandomInfo;
	std::vector<CvWorldPickerInfo*> m_paWorldPickerInfo;
	std::vector<CvSpaceShipInfo*> m_paSpaceShipInfo;
	std::vector<CvProcessInfo*> m_paProcessInfo;
	CvInfoReplacements<CvProcessInfo> m_ProcessInfoReplacements;
	std::vector<CvVoteInfo*> m_paVoteInfo;
	std::vector<CvProjectInfo*> m_paProjectInfo;
	CvInfoReplacements<CvProjectInfo> m_ProjectInfoReplacements;
	std::vector<CvBuildingInfo*> m_paBuildingInfo;
	CvInfoReplacements<CvBuildingInfo> m_BuildingInfoReplacements;
	std::vector<CvSpecialBuildingInfo*> m_paSpecialBuildingInfo;
	CvInfoReplacements<CvSpecialBuildingInfo> m_SpecialBuildingInfoReplacements;
	std::vector<CvUnitInfo*> m_paUnitInfo;
	CvInfoReplacements<CvUnitInfo> m_UnitInfoReplacements;
	std::vector<CvSpawnInfo*> m_paSpawnInfo;
	CvInfoReplacements<CvSpawnInfo> m_SpawnInfoReplacements;
	std::vector<CvSpecialUnitInfo*> m_paSpecialUnitInfo;
	std::vector<CvInfoBase*> m_paConceptInfo;
	std::vector<CvInfoBase*> m_paNewConceptInfo;
	std::vector<CvInfoBase*> m_paCityTabInfo;
	std::vector<CvInfoBase*> m_paCalendarInfo;
	std::vector<CvInfoBase*> m_paSeasonInfo;
	std::vector<CvInfoBase*> m_paMonthInfo;
	std::vector<CvInfoBase*> m_paDenialInfo;
	std::vector<CvInvisibleInfo*> m_paInvisibleInfo;
	std::vector<CvVoteSourceInfo*> m_paVoteSourceInfo;
	std::vector<CvUnitCombatInfo*> m_paUnitCombatInfo;
	std::vector<CvPromotionLineInfo*> m_paPromotionLineInfo;
	std::vector<CvMapCategoryInfo*> m_paMapCategoryInfo;
	std::vector<CvIdeaClassInfo*> m_paIdeaClassInfo;
	std::vector<CvIdeaInfo*> m_paIdeaInfo;
	std::vector<CvInfoBase*> m_paDomainInfo;
	std::vector<CvInfoBase*> m_paUnitAIInfos;
	std::vector<CvInfoBase*> m_paAttitudeInfos;
	std::vector<CvInfoBase*> m_paMemoryInfos;
	std::vector<CvInfoBase*> m_paFeatInfos;
	std::vector<CvGameOptionInfo*> m_paGameOptionInfos;
	std::vector<CvMPOptionInfo*> m_paMPOptionInfos;
	std::vector<CvForceControlInfo*> m_paForceControlInfos;
	std::vector<CvPlayerOptionInfo*> m_paPlayerOptionInfos;
	std::vector<CvGraphicOptionInfo*> m_paGraphicOptionInfos;
	std::vector<CvSpecialistInfo*> m_paSpecialistInfo;
	CvInfoReplacements<CvSpecialistInfo> m_SpecialistInfoReplacements;
	std::vector<CvEmphasizeInfo*> m_paEmphasizeInfo;
	std::vector<CvUpkeepInfo*> m_paUpkeepInfo;
	std::vector<CvCultureLevelInfo*> m_paCultureLevelInfo;
	CvInfoReplacements<CvCultureLevelInfo> m_CultureLevelInfoReplacements;
	std::vector<CvReligionInfo*> m_paReligionInfo;
	CvInfoReplacements<CvReligionInfo> m_ReligionInfoReplacements;
	std::vector<CvCorporationInfo*> m_paCorporationInfo;
	CvInfoReplacements<CvCorporationInfo> m_CorporationInfoReplacements;
	std::vector<CvActionInfo*> m_paActionInfo;
	std::vector<CvMissionInfo*> m_paMissionInfo;
	std::vector<CvControlInfo*> m_paControlInfo;
	std::vector<CvCommandInfo*> m_paCommandInfo;
	std::vector<CvAutomateInfo*> m_paAutomateInfo;
	std::vector<CvPromotionInfo*> m_paPromotionInfo;
	CvInfoReplacements<CvPromotionInfo> m_PromotionInfoReplacements;
	std::vector<CvTechInfo*> m_paTechInfo;
	CvInfoReplacements<CvTechInfo> m_TechInfoReplacements;
	std::vector<CvCivicOptionInfo*> m_paCivicOptionInfo;
	std::vector<CvCivicInfo*> m_paCivicInfo;
	CvInfoReplacements<CvCivicInfo> m_CivicInfoReplacements;
	std::vector<CvDiplomacyInfo*> m_paDiplomacyInfo;
	std::vector<CvEraInfo*> m_aEraInfo;
	CvInfoReplacements<CvEraInfo> m_EraInfoReplacements;
	std::vector<CvHurryInfo*> m_paHurryInfo;
	std::vector<CvVictoryInfo*> m_paVictoryInfo;
	std::vector<CvRouteModelInfo*> m_paRouteModelInfo;
	std::vector<CvRiverModelInfo*> m_paRiverModelInfo;
	std::vector<CvWaterPlaneInfo*> m_paWaterPlaneInfo;
	std::vector<CvTerrainPlaneInfo*> m_paTerrainPlaneInfo;
	std::vector<CvCameraOverlayInfo*> m_paCameraOverlayInfo;
	std::vector<CvAnimationPathInfo*> m_paAnimationPathInfo;
	std::vector<CvAnimationCategoryInfo*> m_paAnimationCategoryInfo;
	std::vector<CvEntityEventInfo*> m_paEntityEventInfo;
	std::vector<CvUnitFormationInfo*> m_paUnitFormationInfo;
	std::vector<CvEffectInfo*> m_paEffectInfo;
	std::vector<CvAttachableInfo*> m_paAttachableInfo;
	std::vector<CvQuestInfo*> m_paQuestInfo;
	std::vector<CvTutorialInfo*> m_paTutorialInfo;
	std::vector<CvEventTriggerInfo*> m_paEventTriggerInfo;
	CvInfoReplacements<CvEventTriggerInfo> m_EventTriggerInfoReplacements;
	std::vector<CvEventInfo*> m_paEventInfo;
	CvInfoReplacements<CvEventInfo> m_EventInfoReplacements;
	std::vector<CvEspionageMissionInfo*> m_paEspionageMissionInfo;
	std::vector<CvUnitArtStyleTypeInfo*> m_paUnitArtStyleTypeInfo;
	std::vector<CvPropertyInfo*> m_paPropertyInfo;
	std::vector<CvOutcomeInfo*> m_paOutcomeInfo;
/*********************************/
/***** Parallel Maps - Begin *****/
/*********************************/
	std::vector<CvMapInfo*> m_paMapInfo;
	std::vector<CvMapSwitchInfo*> m_paMapSwitchInfo;
/*******************************/
/***** Parallel Maps - End *****/
/*******************************/

	//////////////////////////////////////////////////////////////////////////
	// GLOBAL TYPES
	//////////////////////////////////////////////////////////////////////////

	// all type strings are upper case and are kept in this hash map for fast lookup, Moose
	typedef stdext::hash_map<std::string /* type string */, int /*enum value */> TypesMap;
	TypesMap m_typesMap;

	// XXX These are duplicates and are kept for enumeration convenience - most could be removed, Moose
	CvString *m_paszEntityEventTypes;
	int m_iNumEntityEventTypes;

	CvString *m_paszAnimationOperatorTypes;
	int m_iNumAnimationOperatorTypes;

	CvString* m_paszFunctionTypes;

	CvString* m_paszFlavorTypes;
	int m_iNumFlavorTypes;

	CvString *m_paszArtStyleTypes;
	int m_iNumArtStyleTypes;

	CvString *m_paszCitySizeTypes;
	int m_iNumCitySizeTypes;

	CvString *m_paszContactTypes;

	CvString *m_paszDiplomacyPowerTypes;

	CvString *m_paszAutomateTypes;

	CvString *m_paszDirectionTypes;

	CvString *m_paszFootstepAudioTypes;
	int m_iNumFootstepAudioTypes;

	CvString *m_paszFootstepAudioTags;

	CvString m_szCurrentXMLFile;

	FVariableSystem* m_VarSystem;

#define DECLARE_MEMBER_VAR(dataType, VAR) \
	dataType m_##VAR;
	DO_FOR_EACH_GLOBAL_DEFINE(DECLARE_MEMBER_VAR)

	bool m_bXMLLogging;

	float m_fPLOT_SIZE;

	bool m_bMultimapsEnabled;
	bool m_bViewportsEnabled;
	int	m_iViewportFocusBorder;
	int m_iViewportSizeX;
	int m_iViewportSizeY;
	int m_iViewportCenterOnSelectionCenterBorder;
	bool m_bGraphicalDetailPagingEnabled;

	const char* m_szAlternateProfilSampleName;
	FProfiler* m_Profiler;
	CvString m_szDllProfileText;
/************************************************************************************************/
/* BETTER_BTS_AI_MOD                      02/21/10                                jdog5000      */
/*                                                                                              */
/* Efficiency, Options                                                                          */
/************************************************************************************************/
public:
	int getDefineINT( const char * szName, const int iDefault ) const;

// BBAI Options
public:
	bool getBBAI_AIR_COMBAT() const;
	bool getBBAI_HUMAN_VASSAL_WAR_BUILD() const;
	bool getBBAI_HUMAN_AS_VASSAL_OPTION() const;

protected:
	bool m_bBBAI_AIR_COMBAT;
	bool m_bBBAI_HUMAN_VASSAL_WAR_BUILD;
	bool m_bBBAI_HUMAN_AS_VASSAL_OPTION;

// Tech Diffusion
public:
	bool getTECH_DIFFUSION_ENABLE() const;

protected:
	bool m_bTECH_DIFFUSION_ENABLE;
/************************************************************************************************/
/* BETTER_BTS_AI_MOD                       END                                                  */
/************************************************************************************************/
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 11/30/07                                MRGENIE      */
/*                                                                                              */
/* Savegame compatibility                                                                       */
/************************************************************************************************/
	int* m_iStoreExeSettingsCommerceInfo;
	int* m_iStoreExeSettingsYieldInfo;
	int* m_iStoreExeSettingsReligionInfo;
	int* m_iStoreExeSettingsCorporationInfo;
	int* m_iStoreExeSettingsBonusInfo;
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 END                                                  */
/************************************************************************************************/

	bool m_bSignsCleared;
	bool m_bIsInPedia;
};

//
// helpers
//
#define GC CvGlobals::getInstance()
#define gDLL g_DLL

#ifndef FIXED_MISSION_NUMBER
#define NUM_MISSION_TYPES (GC.getNumMissionInfos())
#endif

#endif

/**********************************************************************

File:		BugMod.h
Author:		EmperorFool
Created:	2009-01-22

Defines common constants and functions for use throughout the BUG Mod.

		Copyright (c) 2009 The BUG Mod. All rights reserved.

**********************************************************************/

#pragma once

#ifndef BUG_MOD_H
#define BUG_MOD_H

// name of the Python module where all the BUG functions that the DLL calls must live
// MUST BE A BUILT-IN MODULE IN THE ENTRYPOINTS FOLDER
// currently CvAppInterface
#define PYBugModule				PYCivModule

// Increment this by 1 each time you commit new/changed functions/constants in the Python API.
#define BUG_DLL_API_VERSION		6

// Used to signal the BULL saved game format is used
#define BUG_DLL_SAVE_FORMAT		64

// These are display-only values, and the version should be changed for each release.
#define BUG_DLL_NAME			L"BULL"
#define BUG_DLL_VERSION			L"1.3"
#define BUG_DLL_BUILD			L"219"

#endif