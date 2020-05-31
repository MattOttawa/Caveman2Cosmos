#pragma once

#ifndef CyMapGenerator_h
#define CyMapGenerator_h

//
// Python wrapper class for CvMapGenerator
//

class CvMapGenerator;
class CyPlot;

class CyMapGenerator
{	
public:
	CyMapGenerator();

	bool isNone() const { return false; }

	void doRiver(const CyPlot& kStartPlot, CardinalDirectionTypes eCardinalDirection);
	void addFeatures();
	void addBonuses();

	void generatePlotTypes();
	void generateTerrain();

	void setPlotTypes(boost::python::list& listPlotTypes);

protected:
	CvMapGenerator& m_pMapGenerator;
};

#endif	// CyMapGenerator_h
