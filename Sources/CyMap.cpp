#include "CvGameCoreDLL.h"
#include "CvInitCore.h"
#include "CyArea.h"
#include "CyMap.h"
#include "CyPlot.h"

//
// Python wrapper class for CvMap 
// 

CyMap::CyMap() : m_pMap(GC.getMap()) {}


/*********************************/
/***** Parallel Maps - Begin *****/
/*********************************/
int CyMap::getType() const
{
	return m_pMap.getType();
}

CyMap& CyMap::operator=(CvMap& kMap)
{
	m_pMap = kMap;
	return *this;
}

int	CyMap::getViewportWidth() const
{
	return GC.getCurrentViewport()->getGridWidth();
}

int	CyMap::getViewportHeight() const
{
	return GC.getCurrentViewport()->getGridHeight();
}

int	CyMap::getViewportXFromMapX(int iX) const
{
	return GC.getCurrentViewport()->getViewportXFromMapX(iX);
}

int	CyMap::getViewportYFromMapY(int iY) const
{
	return GC.getCurrentViewport()->getViewportYFromMapY(iY);
}
	
bool CyMap::isInViewport(int iX, int iY) const
{
	return GC.getCurrentViewport()->isInViewport(iX, iY);
}

void CyMap::closeAdvisor(int advisorWidth, int iMinimapLeft, int iMinimapRight, int iMinimapTop, int iMinimapBottom)
{
	GC.getCurrentViewport()->closeAdvisor(advisorWidth, iMinimapLeft, iMinimapRight, iMinimapTop, iMinimapBottom);
}

void CyMap::bringIntoView(int iX, int iY, bool bLookAt, bool bForceCenter, bool bDisplayCityScreen, bool bSelectCity, bool bAddSelectedCity)
{
	GC.getCurrentViewport()->bringIntoView(iX, iY, NULL, bLookAt, bForceCenter, bDisplayCityScreen, bSelectCity, bAddSelectedCity);
}
/*******************************/
/***** Parallel Maps - End *****/
/*******************************/

void CyMap::setRevealedPlots(int /*TeamTypes*/ eTeam, bool bNewValue, bool bTerrainOnly)
{
	m_pMap.setRevealedPlots((TeamTypes) eTeam, bNewValue, bTerrainOnly);
}

void CyMap::resetRevealedPlots(int /*TeamTypes*/ eTeam)
{
	m_pMap.resetRevealedPlots((TeamTypes)eTeam);
}

void CyMap::setAllPlotTypes(int /*PlotTypes*/ ePlotType)
{
	m_pMap.setAllPlotTypes((PlotTypes) ePlotType);
}

void CyMap::verifyUnitValidPlot()
{
	m_pMap.verifyUnitValidPlot();
}

CyArea* CyMap::findBiggestArea(bool bWater) const
{
	return new CyArea(m_pMap.findBiggestArea(bWater));
}

int CyMap::getMapFractalFlags() const
{
	return m_pMap.getMapFractalFlags();
}

int CyMap::numPlots() const
{
	return m_pMap.numPlots();
}

int CyMap::plotNum(int iX, int iY) const
{
	return m_pMap.plotNum(iX, iY);
}

int CyMap::getGridWidth() const
{
	return m_pMap.getGridWidth();
}

int CyMap::getGridHeight() const
{
	return m_pMap.getGridHeight();
}

int CyMap::getLandPlots() const
{
	return m_pMap.getLandPlots();
}

int CyMap::getOwnedPlots() const
{
	return m_pMap.getOwnedPlots();
}

int CyMap::getTopLatitude() const
{
	return m_pMap.getTopLatitude();
}

int CyMap::getBottomLatitude() const
{
	return m_pMap.getBottomLatitude();
}

int CyMap::getNextRiverID() const
{
	return m_pMap.getNextRiverID();
}

void CyMap::incrementNextRiverID()
{
	m_pMap.incrementNextRiverID();
}

bool CyMap::isWrapX() const
{
	return m_pMap.isWrapX();
}

bool CyMap::isWrapY() const
{
	return m_pMap.isWrapY();
}

std::wstring CyMap::getMapScriptName() const
{
	return GC.getInitCore().getMapScriptName().GetCString();
}

WorldSizeTypes CyMap::getWorldSize() const
{
	return m_pMap.getWorldSize();
}

ClimateTypes CyMap::getClimate() const
{
	return m_pMap.getClimate();
}

SeaLevelTypes CyMap::getSeaLevel() const
{
	return m_pMap.getSeaLevel();
}

int CyMap::getNumCustomMapOptions() const
{
	return m_pMap.getNumCustomMapOptions();
}

CustomMapOptionTypes CyMap::getCustomMapOption(int iOption) const
{
	return m_pMap.getCustomMapOption(iOption);
}

int CyMap::getNumBonuses(int /*BonusTypes*/ eIndex) const
{
	return m_pMap.getNumBonuses((BonusTypes)eIndex);
}

int CyMap::getNumBonusesOnLand(int /*BonusTypes*/ eIndex) const
{
	return m_pMap.getNumBonusesOnLand((BonusTypes)eIndex);
}

CyPlot* CyMap::plotByIndex(int iIndex) const
{
	return new CyPlot(m_pMap.plotByIndex(iIndex));
}

CyPlot* CyMap::sPlotByIndex(int iIndex) const	// static version
{
	static CyPlot plot;
	plot.setPlot(m_pMap.plotByIndex(iIndex));
	return &plot;
}

CyPlot* CyMap::plot(int iX, int iY) const
{
	return new CyPlot(m_pMap.plot(iX, iY));
}

CyPlot* CyMap::sPlot(int iX, int iY) const	// static version
{
	static CyPlot p;
	p.setPlot(m_pMap.plot(iX, iY));
	return &p;
}

int CyMap::getIndexAfterLastArea() const
{
	return m_pMap.getIndexAfterLastArea();
}

int CyMap::getNumAreas() const
{
	return m_pMap.getNumAreas();
}

int CyMap::getNumLandAreas() const
{
	return m_pMap.getNumLandAreas();
}

CyArea* CyMap::getArea(int iID) const
{
	return new CyArea(m_pMap.getArea(iID));
}

void CyMap::recalculateAreas()
{
	m_pMap.recalculateAreas();
}

void CyMap::rebuild(int iGridW, int iGridH, int iTopLatitude, int iBottomLatitude, bool bWrapX, bool bWrapY, WorldSizeTypes eWorldSize, ClimateTypes eClimate, SeaLevelTypes eSeaLevel, int iNumCustomMapOptions, CustomMapOptionTypes * aeCustomMapOptions)
{
	m_pMap.rebuild(iGridW, iGridH, iTopLatitude, iBottomLatitude, bWrapX, bWrapY, eWorldSize, eClimate, eSeaLevel, iNumCustomMapOptions, aeCustomMapOptions);
}

void CyMap::updateMinimapColor()
{
	m_pMap.updateMinimapColor();
}

bool CyMap::generatePathForHypotheticalUnit(const CyPlot& kFrom, const CyPlot& kTo, int ePlayer, int eUnit, int iFlags, int iMaxTurns)
{
	return m_pMap.generatePathForHypotheticalUnit(kFrom.getPlot(), kTo.getPlot(), (PlayerTypes) ePlayer, (UnitTypes) eUnit, iFlags, iMaxTurns);
}

int CyMap::getLastPathStepNum()
{
	return m_pMap.getLastPathStepNum();
}

CyPlot* CyMap::getLastPathPlotByIndex(int index)
{
	return new CyPlot(m_pMap.getLastPathPlotByIndex(index));
}

void CyMap::resetPathDistance()
{
	m_pMap.resetPathDistance();
}

int CyMap::calculatePathDistance(const CyPlot& kSource, const CyPlot& kDest)
{
	return m_pMap.calculatePathDistance(kSource.getPlot(), kDest.getPlot());
}
