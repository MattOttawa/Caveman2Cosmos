#pragma once

#ifndef CyMap_h
#define CyMap_h

//
// Python wrapper class for CvMap 
//

class CvMap;
class CyArea;
class CyPlot;

class CyMap
{
public:
	CyMap();

	//CvMapInterfaceBase* getMap() { return m_pMap;	}	// Call from C++
	bool isNone() const { return false; }
	
/*********************************/
/***** Parallel Maps - Begin *****/
/*********************************/
	int getType() const;
	CyMap& operator = (CvMap& kMap);

	int	getViewportWidth() const;
	int	getViewportHeight() const;
	int	getViewportXFromMapX(int iX) const;
	int	getViewportYFromMapY(int iY) const;
	bool isInViewport(int X, int Y) const;

	void closeAdvisor(int advisorWidth, int iMinimapLeft, int iMinimapRight, int iMinimapTop, int iMinimapBottom);
	void bringIntoView(int iX, int iY, bool bLookAt, bool bForceCenter, bool bDisplayCityScreen, bool bSelectCity, bool bAddSelectedCity);
/*******************************/
/***** Parallel Maps - End *****/
/*******************************/	
	
	void verifyUnitValidPlot();

	void setRevealedPlots(int /*TeamTypes*/ eTeam, bool bNewValue, bool bTerrainOnly);
	void resetRevealedPlots(int /*TeamTypes*/ eTeam);
	void setAllPlotTypes(int /*PlotTypes*/ ePlotType);

	CyArea* findBiggestArea(bool bWater) const;

	int getMapFractalFlags() const;

	int numPlots() const;
	int plotNum(int iX, int iY) const;

	int getGridWidth() const;
	int getGridHeight() const;

	int getLandPlots() const;
	int getOwnedPlots() const;

	int getTopLatitude() const;
	int getBottomLatitude() const;

	int getNextRiverID() const;
	void incrementNextRiverID();

	bool isWrapX() const;
	bool isWrapY() const;

	std::wstring getMapScriptName() const;
	WorldSizeTypes getWorldSize() const;
	ClimateTypes getClimate() const;
	SeaLevelTypes getSeaLevel() const;
	int getNumCustomMapOptions() const;
	CustomMapOptionTypes getCustomMapOption(int iOption) const;

	int getNumBonuses(int /*BonusTypes*/ eIndex) const;
	int getNumBonusesOnLand(int /*BonusTypes*/ eIndex) const;

	CyPlot* plotByIndex(int iIndex) const;
	CyPlot* sPlotByIndex(int iIndex) const;
	CyPlot* plot(int iX, int iY) const;
	CyPlot* sPlot(int iX, int iY) const;

	int getIndexAfterLastArea() const;
	int getNumAreas() const;
	int getNumLandAreas() const;
	CyArea* getArea(int iID) const;
	void recalculateAreas();

	void rebuild(int iGridW, int iGridH, int iTopLatitude, int iBottomLatitude, bool bWrapX, bool bWrapY, WorldSizeTypes eWorldSize, ClimateTypes eClimate, SeaLevelTypes eSeaLevel, int iNumCustomMapOptions, CustomMapOptionTypes * aeCustomMapOptions);
	void updateMinimapColor();

	// AIAndy: Expose path generation functionality to Python
	bool generatePathForHypotheticalUnit(const CyPlot& kFrom, const CyPlot& kTo, int /*PlayerTypes*/ ePlayer, int /*UnitTypes*/ eUnit, int iFlags, int iMaxTurns);
	int getLastPathStepNum();
	CyPlot* getLastPathPlotByIndex(int index);
	void resetPathDistance();
	int calculatePathDistance(const CyPlot& kSource, const CyPlot& kDest);

protected:
	CvMap& m_pMap;
};

#endif	// CyMap_h
