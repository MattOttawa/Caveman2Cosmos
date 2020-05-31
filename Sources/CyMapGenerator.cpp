#include "CvGameCoreDLL.h"
#include "CvMapGenerator.h"
#include "CyMapGenerator.h"
#include "CyPlot.h"

//
// Python wrapper class for CvMapGenerator
//

CyMapGenerator::CyMapGenerator() : m_pMapGenerator(CvMapGenerator::GetInstance()) {}


void CyMapGenerator::doRiver(const CyPlot& kStartPlot, CardinalDirectionTypes eCardinalDirection)
{
	m_pMapGenerator.doRiver(kStartPlot.getPlot(), eCardinalDirection);
}

void CyMapGenerator::addFeatures()
{
	m_pMapGenerator.addFeatures();
}

void CyMapGenerator::addBonuses()
{
	m_pMapGenerator.addBonuses();
}

void CyMapGenerator::generatePlotTypes()
{
	m_pMapGenerator.generatePlotTypes();
}

void CyMapGenerator::generateTerrain()
{
	m_pMapGenerator.generateTerrain();
}

void CyMapGenerator::setPlotTypes(boost::python::list& listPlotTypes)
{
	int* paiPlotTypes = NULL;
	gDLL->getPythonIFace()->putSeqInArray(listPlotTypes.ptr() /*src*/, &paiPlotTypes /*dst*/);
	m_pMapGenerator.setPlotTypes(paiPlotTypes);
	delete [] paiPlotTypes;
}
