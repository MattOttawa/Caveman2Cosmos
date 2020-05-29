#pragma once

#ifndef CyCity_h__
#define CyCity_h__

#include <string>

#ifndef __INTELLISENSE__
#include <boost/python/tuple.hpp>
namespace python = boost::python;
#endif

//
// Python wrapper class for CvCity
//

class CvCity;
class CvProperties;
class CyPlot;
class CyArea;
class CyUnit;
struct OrderData;

class CyCity
{
public:
	CyCity();
	DllExport explicit CyCity(CvCity* pCity);		// Call from C++

	CvCity* getCity() const { return m_pCity; }	// Call from C++
	bool isNone() const { return m_pCity == NULL; }
	void kill();

	int getRevolutionIndex();
	void setRevolutionIndex(int iNewValue);
	void changeRevolutionIndex(int iChange);

	int getLocalRevIndex();
	void setLocalRevIndex(int iNewValue);

	int getRevIndexAverage() const;
	void setRevIndexAverage(int iNewValue);
	void updateRevIndexAverage();

	int getRevolutionCounter();
	void setRevolutionCounter(int iNewValue);
	void changeRevolutionCounter(int iChange);

	int getReinforcementCounter();
	void setReinforcementCounter(int iNewValue);
	void changeReinforcementCounter(int iChange);

	CyPlot* getCityIndexPlot(int iIndex);
	bool canWork(CyPlot* pPlot);
	int countNumImprovedPlots();
	int countNumWaterPlots();

	int findBaseYieldRateRank(int /*YieldTypes*/ eYield) const;
	int findYieldRateRank(int /*YieldTypes*/ eYield) const;
	int findCommerceRateRank(int /*CommerceTypes*/ eCommerce) const;

	int getMaxNumWorldWonders();
	int getMaxNumNationalWonders();

	bool canTrain(int iUnit, bool bContinue, bool bTestVisible, bool bIgnoreCost, bool bIgnoreUpgrades);
	bool canConstruct(int iBuilding, bool bContinue, bool bTestVisible, bool bIgnoreCost);
	bool canCreate(int iProject, bool bContinue, bool bTestVisible);
	bool canMaintain(int iProcess, bool bContinue);
	int getFoodTurnsLeft();
	bool isProduction();
	bool isProductionUnit();
	bool isProductionBuilding();
	bool isProductionProject();
	bool isProductionProcess();

	int getProductionExperience(int /*UnitTypes*/ eUnit);
	void addProductionExperience(CyUnit* pUnit, bool bConscript);

	int /*UnitTypes*/ getProductionUnit();
	int /*BuildingTypes*/ getProductionBuilding();
	int /*ProjectTypes*/ getProductionProject();
	int /*ProcessTypes*/ getProductionProcess();
	std::wstring getProductionName();
	std::wstring getProductionNameKey();
	int getGeneralProductionTurnsLeft();
	bool isFoodProduction();
	int getFirstUnitOrder(int /*UnitTypes*/ eUnit);
	int getNumTrainUnitAI(int /*UnitAITypes*/ eUnitAI);
	int getFirstBuildingOrder(int /*BuildingTypes*/ eBuilding);
	int getProduction();
	int getProductionNeeded();
	int getProductionTurnsLeft();
	int getUnitProductionTurnsLeft(int /*UnitTypes*/ iUnit, int iNum);
	int getBuildingProductionTurnsLeft(int /*BuildingTypes*/ iBuilding, int iNum);
	int getProjectProductionTurnsLeft(int /*ProjectTypes*/ eProject, int iNum);
	void setProduction(int iNewValue);
	void changeProduction(int iChange);
	int getProductionModifier();
	int getCurrentProductionDifference(bool bIgnoreFood, bool bOverflow);

	bool canHurry(int /*HurryTypes*/ iHurry, bool bTestVisible);
	int /*UnitTypes*/ getConscriptUnit();
	int flatConscriptAngerLength();
	bool canConscript();
	int getBonusHealth(int /*BonusTypes*/ iBonus);
	int getBonusHappiness(int /*BonusTypes*/ iBonus);
	int getBonusPower(int /*BonusTypes*/ eBonus, bool bDirty);
	int getBonusYieldRateModifier(int /*YieldTypes*/ eIndex, int /*BonusTypes*/ eBonus);
	int /* HandicapTypes */ getHandicapType();
	int /* CivilizationTypes */ getCivilizationType();
	int /*LeaderHeadTypes*/ getPersonalityType();
	int /*ArtStyleTypes*/ getArtStyleType();

	bool hasTrait(int /*TraitTypes*/ iTrait);
	bool isBarbarian();
	bool isNPC();
	bool isHominid();
	bool isHuman();
	bool isVisible(int /*TeamTypes*/ eTeam, bool bDebug);

	bool isCapital();
	bool isCoastal(int iMinWaterSize);
	bool isDisorder();
	bool isHolyCityByType(int /*ReligionTypes*/ iIndex);
	bool isHolyCity();
	bool isHeadquartersByType(int /*CorporationTypes*/ iIndex);
	int getNoMilitaryPercentAnger();
	int getWarWearinessPercentAnger();

	int getRevIndexPercentAnger();

	int unhappyLevel(int iExtra);
	int happyLevel();
	int angryPopulation(int iExtra);
	int totalFreeSpecialists();
	int goodHealth();
	int badHealth(bool bNoAngry);
	int healthRate(bool bNoAngry, int iExtra);
	int foodConsumption(bool bNoAngry, int iExtra);
	int foodDifference(bool bBottom);
	int growthThreshold();
	int productionLeft();
	int hurryGold(int /*HurryTypes*/ iHurry);
	int hurryPopulation(int /*HurryTypes*/ iHurry);
	int hurryProduction(int /*HurryTypes*/ iHurry);
	int flatHurryAngerLength();

	int getNumBuilding(int /*BuildingTypes*/ iIndex);
	bool isHasBuilding(int /*BuildingTypes*/ iIndex);		// This is a function to help modders out, since it was replaced with getNumBuildings() in the C++
	int getNumActiveBuilding(int /*BuildingTypes*/ iIndex);
	int getID();
	int getX();
	int getY();
	CyPlot* plot();
	bool isConnectedTo(CyCity* pCity);
	bool isConnectedToCapital(int /*PlayerTypes*/ ePlayer);
	CyArea* area();
	CyArea* waterArea();
	CyPlot* getRallyPlot();

	int getGameTurnFounded();
	int getGameTurnAcquired();
	int getPopulation();
	void setPopulation(int iNewValue);
	void changePopulation(int iChange);
	long getRealPopulation();

	int getHighestPopulation();
	void setHighestPopulation(int iNewValue);
	int getWorkingPopulation();
	int getSpecialistPopulation();
	int getNumGreatPeople();
	int getBaseGreatPeopleRate();
	int getGreatPeopleRate();
	void changeBaseGreatPeopleRate(int iChange);
	int getGreatPeopleRateModifier();
	int getGreatPeopleProgress();
	void changeGreatPeopleProgress(int iChange);
	int getNumWorldWonders();
	int getNumNationalWonders();
	int getNumBuildings();
	bool isGovernmentCenter();

	int getMaintenance() const;
	int getMaintenanceTimes100() const;
	int calculateDistanceMaintenance() const;
	int calculateNumCitiesMaintenance() const;
	int calculateColonyMaintenanceTimes100() const;
	int getMaintenanceModifier();
	int getWarWearinessModifier();

	int getEspionageHealthCounter();
	void changeEspionageHealthCounter(int iChange);
	int getEspionageHappinessCounter();
	void changeEspionageHappinessCounter(int iChange);

	int getBuildingHealth(int iBuilding);

	int getMilitaryHappinessUnits();
	int getBuildingHappiness(int iBuilding);
	int getReligionHappiness(int iReligion);
	int getExtraHappiness();
	int getExtraHealth();
	void changeExtraHappiness(int iChange);
	void changeExtraHealth(int iChange);
	int getHurryAngerTimer();
	void changeHurryAngerTimer(int iChange);

	int getRevRequestAngerTimer();
	void changeRevRequestAngerTimer(int iChange);
	void changeRevSuccessTimer(int iChange);

	int getConscriptAngerTimer();
	void changeConscriptAngerTimer(int iChange);
	int getDefyResolutionAngerTimer();
	void changeDefyResolutionAngerTimer(int iChange);
	int flatDefyResolutionAngerLength();
	int getHappinessTimer();
	void changeHappinessTimer(int iChange);
	bool isNoUnhappiness();

	bool isBuildingOnlyHealthy();

	int getFood();
	void setFood(int iNewValue);
	void changeFood(int iChange);
	int getFoodKept();
	int getOverflowProduction();
	void setOverflowProduction(int iNewValue);
	int getFeatureProduction();
	void setFeatureProduction(int iNewValue);
	int getMilitaryProductionModifier();
	int getSpaceProductionModifier();
	int getExtraTradeRoutes();
	void changeExtraTradeRoutes(int iChange);
	int getTradeRouteModifier();
	int getForeignTradeRouteModifier();
	int getBuildingDefense();
	int getFreeExperience();
	int getMaxAirlift();
	int getAirModifier();
	int getNukeModifier();
	bool isPower();
	bool isAreaCleanPower();
	bool isDirtyPower();
	int getDefenseDamage();
	void changeDefenseDamage(int iChange);
	int getNaturalDefense();
	int getTotalDefense(bool bIgnoreBuilding);
	int getDefenseModifier(bool bIgnoreBuilding);

	int getOccupationTimer();
	bool isOccupation();
	void setOccupationTimer(int iNewValue);
	void changeOccupationTimer(int iChange);
	bool isNeverLost();
	void setNeverLost(int iNewValue);

	int getMADIncoming();

	bool isBombarded();
	void setBombarded(int iNewValue);
	bool isDrafted();
	void setDrafted(int iNewValue);
	bool isAirliftTargeted();
	void setAirliftTargeted(int iNewValue);
	bool isCitizensAutomated();
	void setCitizensAutomated(bool bNewValue);
	bool isProductionAutomated();
	void setProductionAutomated(bool bNewValue);
	bool isWallOverride() const;
	void setWallOverride(bool bOverride);
	bool isPlundered();
	void setPlundered(bool bNewValue);
	int /*PlayerTypes*/getOwner();
	int /*TeamTypes*/getTeam();
	int /*PlayerTypes*/getPreviousOwner();
	int /*PlayerTypes*/getOriginalOwner();
	int /*CultureLevelTypes*/ getCultureLevel();
	int getCultureThreshold();
	int getSeaPlotYield(int /*YieldTypes*/ eIndex);

	int getBaseYieldRate(int /*YieldTypes*/ eIndex);
	void changeBaseYieldRate(int /*YieldTypes*/ eIndex, int iNewValue);

	int getBaseYieldRateModifier(int /*YieldTypes*/ eIndex, int iExtra);
	int getYieldRate(int /*YieldTypes*/ eIndex);
	int getYieldRateModifier(int /*YieldTypes*/ eIndex);

	int getTradeYield(int /*YieldTypes*/ eIndex);

// BUG - Fractional Trade Routes - start
#ifdef _MOD_FRACTRADE
	int calculateTradeProfitTimes100(CyCity* pCity);
#endif
// BUG - Fractional Trade Routes - end
	int calculateTradeProfit(CyCity* pCity);
	int calculateTradeYield(int /*YieldTypes*/ eIndex, int iTradeProfit);

	int getCommerceRate(int /*CommerceTypes*/ eIndex);
	int getCommerceRateTimes100(int /*CommerceTypes*/ eIndex);
	int getBaseCommerceRate(int /*CommerceTypes*/ eIndex);
	int getProductionToCommerceModifier(int /*CommerceTypes*/ eIndex);
	int getBuildingCommerceByBuilding(int /*CommerceTypes*/ eIndex, int /*BuildingTypes*/ iBuilding);
	int getSpecialistCommerce(int /*CommerceTypes*/ eIndex);
	void changeSpecialistCommerce(int /*CommerceTypes*/ eIndex, int iChange);
	int getReligionCommerceByReligion(int /*CommerceTypes*/ eIndex, int /*ReligionTypes*/ iReligion);
	int getCorporationCommerce(int /*CommerceTypes*/ eIndex);
	int getCorporationCommerceByCorporation(int /*CommerceTypes*/ eIndex, int /*CorporationTypes*/ iCorporation);
	int getCorporationYield(int /*YieldTypes*/ eIndex);
	int getCorporationYieldByCorporation(int /*YieldTypes*/ eIndex, int /*CorporationTypes*/ iCorporation);
	int getCommerceRateModifier(int /*CommerceTypes*/ eIndex);
	int getCommerceHappinessByType(int /*CommerceTypes*/ eIndex);
	int getDomainFreeExperience(int /*DomainTypes*/ eIndex);
	int getDomainProductionModifier(int /*DomainTypes*/ eIndex);

	int getBonusCommerceRateModifier(int /*CommerceTypes*/ eIndex) const;

	int getArea() const;

	bool isWeLoveTheKingDay() const;
	void setWeLoveTheKingDay(bool bWeLoveTheKingDay);
	int calculateCorporateTaxes() const;
	void changePowerCount(int iChange, bool bDirty);

	void changeEventAnger(int iChange);

	int getNumPopulationEmployed();

	int getBonusCommercePercentChanges(int eIndex, int eBuilding);

	bool isAutomatedCanBuild(int /*BuildTypes*/ eIndex);
	void setAutomatedCanBuild(int /*BuildTypes*/ eIndex, bool bNewValue);

	int getCulture(int /*PlayerTypes*/ eIndex);
	int getCultureTimes100(int /*PlayerTypes*/ eIndex);
	int countTotalCultureTimes100();
	PlayerTypes findHighestCulture();
	int calculateCulturePercent(int eIndex);
	void setCulture(int /*PlayerTypes*/ eIndex, int iNewValue, bool bPlots);
	void setCultureTimes100(int /*PlayerTypes*/ eIndex, int iNewValue, bool bPlots);
	void changeCulture(int /*PlayerTypes*/ eIndex, int iChange, bool bPlots);

	int getNumRevolts(int playerIdx);
	void changeNumRevolts(int playerIdx, int iChange);

	bool isRevealed(int /*TeamTypes*/ eIndex, bool bDebug);
	void setRevealed(int /*TeamTypes*/ eIndex, bool bNewValue);
	bool getEspionageVisibility(int /*TeamTypes*/ eIndex);
	std::wstring getName();
	std::wstring getNameForm(int iForm);
	std::wstring getNameKey();
	void setName(std::wstring szNewValue, bool bFound);
	void changeNoBonusCount(int /*BonusTypes*/ eBonus, int iChange);
	bool isNoBonus(int /*BonusTypes*/ eBonus);
	int getFreeBonus(int /*BonusTypes*/ eIndex);
	void changeFreeBonus(int /*BonusTypes*/ eIndex, int iChange);
	int getNumBonuses(int /*BonusTypes*/ iBonus);
	bool hasBonus(int /*BonusTypes */ iBonus);
	int getBuildingProduction(int /*BuildingTypes*/ iIndex);
	void setBuildingProduction(int /*BuildingTypes*/ iIndex, int iNewValue);
	int getBuildingProductionTime(int /*BuildingTypes*/ eIndex);
// BUG - Production Decay - start
	bool isBuildingProductionDecay(int /*BuildingTypes*/ eIndex);
	int getBuildingProductionDecayTurns(int /*BuildingTypes*/ eIndex);
// BUG - Production Decay - end
	int getBuildingOriginalOwner(int /*BuildingTypes*/ iIndex);
	int getBuildingOriginalTime(int /*BuildingTypes*/ iIndex);
	int getUnitProduction(int iIndex);
	void setUnitProduction(int iIndex, int iNewValue);
// BUG - Production Decay - start
	int getUnitProductionTime(int /*UnitTypes*/ eIndex);
	bool isUnitProductionDecay(int /*UnitTypes*/ eIndex);
	int getUnitProductionDecayTurns(int /*UnitTypes*/ eIndex);
// BUG - Production Decay - end
// BUG - Project Production - start
	int getProjectProduction(int /*ProjectTypes*/ iIndex);
// BUG - Project Production - end
	int getGreatPeopleUnitProgress(int /*UnitTypes*/ iIndex);
	void setGreatPeopleUnitProgress(int /*UnitTypes*/ iIndex, int iNewValue);
	void changeGreatPeopleUnitProgress(int /*UnitTypes*/ iIndex, int iChange);
	int getSpecialistCount(int /*SpecialistTypes*/ eIndex);
	int getMaxSpecialistCount(int /*SpecialistTypes*/ eIndex);
	bool isSpecialistValid(int /*SpecialistTypes*/ eIndex, int iExtra);
	int getForceSpecialistCount(int /*SpecialistTypes*/ eIndex);
	void setForceSpecialistCount(int /*SpecialistTypes*/ eIndex, int iNewValue);
	int getFreeSpecialistCount(int /*SpecialistTypes*/ eIndex);
	//	Koshling - removed direct set of free specialist count - it's HIGHLY unsafe - use changeFreeSpecialistCount
	//void setFreeSpecialistCount(int /*SpecialistTypes*/ eIndex, int iNewValue);
	void changeFreeSpecialistCount(int /*SpecialistTypes*/ eIndex, int iChange);
	int getAddedFreeSpecialistCount(int /*SpecialistTypes*/ eIndex);
	int getImprovementFreeSpecialists(int /*ImprovementTypes*/ iIndex);
	void changeImprovementFreeSpecialists(int /*ImprovementTypes*/ iIndex, int iChange);
	int getReligionInfluence(int /*ReligionTypes*/ iIndex);
	void changeReligionInfluence(int /*ReligionTypes*/ iIndex, int iChange);

	int getStateReligionHappiness(int /*ReligionTypes*/ eIndex);
	void changeStateReligionHappiness(int /*ReligionTypes*/ eIndex, int iChange);

	int getSpecialistFreeExperience() const;
	int getEspionageDefenseModifier() const;

	bool isWorkingPlot(CyPlot* pPlot);
	int getNumRealBuilding(int /*BuildingTypes*/ iIndex);
	void setNumRealBuilding(int /*BuildingTypes*/ iIndex, int iNewValue);
	bool isHasReligion(int /*ReligionTypes*/ iIndex);
	void setHasReligion(int /*ReligionTypes*/ iIndex, bool bNewValue, bool bAnnounce, bool bArrows);
	bool isHasCorporation(int /*CorporationTypes*/ iIndex);
	void setHasCorporation(int /*CorporationTypes*/ iIndex, bool bNewValue, bool bAnnounce, bool bArrows);
	bool isActiveCorporation(int /*CorporationTypes*/ eCorporation);
	CyCity* getTradeCity(int iIndex);
	int getTradeRoutes();

	void clearOrderQueue();
	void pushOrder(OrderTypes eOrder, int iData1, int iData2, bool bSave, bool bPop, bool bAppend, bool bForce);
	void popOrder(int iNum, bool bFinish, bool bChoose);
	int getOrderQueueLength();
	OrderData getOrderFromQueue(int iIndex);

	int getBuildingYieldChange(int /*BuildingTypes*/ eBuilding, int /*YieldTypes*/ eYield) const;
	void setBuildingYieldChange(int /*BuildingTypes*/ eBuilding, int /*YieldTypes*/ eYield, int iChange);
	int getBuildingCommerceChange(int /*BuildingTypes*/ eBuilding, int /*CommerceTypes*/ eCommerce) const;
	void setBuildingCommerceChange(int /*BuildingTypes*/ eBuilding, int /*CommerceTypes*/ eCommerce, int iChange);
	int getBuildingHappyChange(int /*BuildingTypes*/ eBuilding) const;
	void setBuildingHappyChange(int /*BuildingTypes*/ eBuilding, int iChange);
	int getBuildingHealthChange(int /*BuildingTypes*/ eBuilding) const;
	void setBuildingHealthChange(int /*BuildingTypes*/ eBuilding, int iChange);

	int getLiberationPlayer(bool bConquest);

	bool AI_isEmphasize(int iEmphasizeType);
	int AI_countBestBuilds(CyArea* pArea);
	int AI_cityValue();

	CvProperties* getProperties();

	bool getBuildingListFilterActive(int /*BuildingFilterTypes*/ eFilter);
	void setBuildingListFilterActive(int /*BuildingFilterTypes*/ eFilter, bool bActive);
	int /*BuildingGroupingTypes*/ getBuildingListGrouping();
	void setBuildingListGrouping(int /*BuildingGroupingTypes*/ eGrouping);
	int /*BuildingSortTypes*/ getBuildingListSorting();
	void setBuildingListSorting(int /*BuildingSortTypes*/ eSorting);
	int getBuildingListGroupNum();
	int getBuildingListNumInGroup(int iGroup);
	int /*BuildingTypes*/ getBuildingListType(int iGroup, int iPos);

	void setUnitListInvalid();
	bool getUnitListFilterActive(int /*UnitFilterTypes*/ eFilter);
	void setUnitListFilterActive(int /*UnitFilterTypes*/ eFilter, bool bActive);
	int /*UnitGroupingTypes*/ getUnitListGrouping();
	void setUnitListGrouping(int /*UnitGroupingTypes*/ eGrouping);
	int /*UnitSortTypes*/ getUnitListSorting();
	void setUnitListSorting(int /*UnitSortTypes*/ eSorting);
	int getUnitListGroupNum();
	int getUnitListNumInGroup(int iGroup);
	int /*UnitTypes*/ getUnitListType(int iGroup, int iPos);

	bool isEventOccured(int /*EventTypes*/ eEvent) const;

	std::string getScriptData() const;
	void setScriptData(std::string szNewValue);

private:
	CvCity* m_pCity;
};

DECLARE_PY_WRAPPER(CyCity, CvCity*);

#endif // CyCity_h__