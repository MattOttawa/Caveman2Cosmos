//
// globals.cpp
//
#include "CvGameCoreDLL.h"
#include "CvGameAI.h"
#include "CvInitCore.h"
#include "CvMapExternal.h"
#include "CvPlayerAI.h"
#include "CvRandom.h"
#include "CvTeamAI.h"
#include "CvXMLLoadUtility.h"
#include "FVariableSystem.h"
#include <time.h> 
#include <sstream>

static char gVersionString[1024] = { 0 };

// Use macro override when available. Version string might not be loaded in time for
// applying it to the mini-dump so we will use macro version string for releases
#ifndef C2C_VERSION
#	define C2C_VERSION gVersionString
#endif

#define COPY(dst, src, typeName) \
	{ \
		int iNum = sizeof(src)/sizeof(typeName); \
		dst = new typeName[iNum]; \
		for (int i =0;i<iNum;i++) \
			dst[i] = src[i]; \
	}

template <class T>
void deleteInfoArray(std::vector<T*>& array)
{
	for (std::vector<T*>::iterator it = array.begin(); it != array.end(); ++it)
	{
		SAFE_DELETE(*it);
	}

	array.clear();
}

template <class T>
bool readInfoArray(FDataStreamBase* pStream, std::vector<T*>& array, const char* szClassName)
{
	GC.addToInfosVectors(&array);

	int iSize;
	pStream->Read(&iSize);
	FAssertMsg(iSize==sizeof(T), CvString::format("class size doesn't match cache size - check info read/write functions:%s", szClassName).c_str());
	if (iSize!=sizeof(T))
		return false;
	pStream->Read(&iSize);

	deleteInfoArray(array);

	for (int i = 0; i < iSize; ++i)
	{
		array.push_back(new T);
	}

	int iIndex = 0;
	for (std::vector<T*>::iterator it = array.begin(); it != array.end(); ++it)
	{
		(*it)->read(pStream);
		GC.setInfoTypeFromString((*it)->getType(), iIndex);
		++iIndex;
	}

	return true;
}

template <class T>
bool writeInfoArray(FDataStreamBase* pStream,  std::vector<T*>& array)
{
	int iSize = sizeof(T);
	pStream->Write(iSize);
	pStream->Write(array.size());
	for (std::vector<T*>::iterator it = array.begin(); it != array.end(); ++it)
	{
		(*it)->write(pStream);
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

CvGlobals* gGlobals = NULL;
CvDLLUtilityIFaceBase* g_DLL = NULL;

int g_iPercentDefault = 100;
int g_iModifierDefault = 0;

//
// CONSTRUCTOR
//
CvGlobals::CvGlobals() 
	: m_paszEntityEventTypes(NULL)
	, m_paszAnimationOperatorTypes(NULL)
	, m_paszFunctionTypes(NULL)
	, m_paszFlavorTypes(NULL)
	, m_paszArtStyleTypes(NULL)
	, m_paszCitySizeTypes(NULL)
	, m_paszContactTypes(NULL)
	, m_paszDiplomacyPowerTypes(NULL)
	, m_paszAutomateTypes(NULL)
	, m_paszDirectionTypes(NULL)
	, m_paszFootstepAudioTypes(NULL)
	, m_paszFootstepAudioTags(NULL)
	, m_bGraphicsInitialized(false)
	, m_bLogging(false)
	, m_bRandLogging(false)
	, m_bOverwriteLogs(false)
	, m_bSynchLogging(false)
	, m_bDLLProfiler(false)
	, m_pFMPMgr(NULL)
	, m_asyncRand(NULL)
	, m_interface(NULL)
	, m_game(NULL)
	, m_messageQueue(NULL)
	, m_hotJoinMsgQueue(NULL)
	, m_messageControl(NULL)
	, m_messageCodes(NULL)
	, m_dropMgr(NULL)
	, m_portal(NULL)
	, m_setupData(NULL)
	, m_initCore(NULL)
	, m_statsReporter(NULL)
	, m_diplomacyScreen(NULL)
	, m_mpDiplomacyScreen(NULL)
	, m_pathFinder(NULL)
	, m_interfacePathFinder(NULL)
	, m_stepFinder(NULL)
	, m_routeFinder(NULL)
	, m_borderFinder(NULL)
	, m_areaFinder(NULL)
	, m_plotGroupFinder(NULL)
	, m_aiPlotDirectionX(NULL)
	, m_aiPlotDirectionY(NULL)
	, m_aiPlotCardinalDirectionX(NULL)
	, m_aiPlotCardinalDirectionY(NULL)
	, m_aiCityPlotX(NULL)
	, m_aiCityPlotY(NULL)
	, m_aiCityPlotPriority(NULL)
	, m_aeTurnLeftDirection(NULL)
	, m_aeTurnRightDirection(NULL)
	, m_Profiler(NULL)
	, m_VarSystem(NULL)
	, m_fPLOT_SIZE(0)
	, m_bMultimapsEnabled(false)
	, m_bViewportsEnabled(false)
	, m_iViewportFocusBorder(0)
	, m_iViewportCenterOnSelectionCenterBorder(5)
	, m_szAlternateProfilSampleName("")
	, m_bGraphicalDetailPagingEnabled(false)
	, m_paHints()
	/************************************************************************************************/
	/* MODULAR_LOADING_CONTROL                 10/30/07                            MRGENIE          */
	/*                                                                                              */
	/*                                                                                              */
	/************************************************************************************************/
	// MLF loading
	, m_paModLoadControlVector(NULL)
	, m_paModLoadControls(NULL)
	/************************************************************************************************/
	/* MODULAR_LOADING_CONTROL                 END                                                  */
	/************************************************************************************************/
	/************************************************************************************************/
	/* XML_MODULAR_ART_LOADING                 03/28/08                                MRGENIE      */
	/*                                                                                              */
	/*                                                                                              */
	/************************************************************************************************/
	, m_paMainMenus(NULL)
	, m_cszModDir("NONE")
	/************************************************************************************************/
	/* XML_MODULAR_ART_LOADING                 END                                                  */
	/************************************************************************************************/
	, m_bXMLLogging(false)
	/************************************************************************************************/
	/* BETTER_BTS_AI_MOD                      02/21/10                                jdog5000      */
	/*                                                                                              */
	/* Efficiency, Options                                                                          */
	/************************************************************************************************/
	// BBAI Options
	, m_bBBAI_AIR_COMBAT(false)
	, m_bBBAI_HUMAN_VASSAL_WAR_BUILD(false)
	, m_bBBAI_HUMAN_AS_VASSAL_OPTION(false)

	// Tech Diffusion
	, m_bTECH_DIFFUSION_ENABLE(false)
	/************************************************************************************************/
	/* BETTER_BTS_AI_MOD                       END                                                  */
	/************************************************************************************************/
	, m_bIsInPedia(false)
	, m_iLastTypeID(-1)
	, m_iActiveLandscapeID(0)
	// uninitialized variables bugfix
	, m_iNumPlayableCivilizationInfos(0)
	, m_iNumAIPlayableCivilizationInfos(0)
	, m_iTotalNumModules(0) // Modular loading control
	, m_iNumEntityEventTypes(0)
	, iStuckUnitID(0)
	, iStuckUnitCount(0)
	, m_iniInitCore(NULL)
	, m_loadedInitCore (NULL)
	, m_bResourceLayerOn(false)
	, m_iNumAnimationOperatorTypes(0)
	, m_iNumFlavorTypes(0)
	, m_iNumArtStyleTypes(0)
	, m_iNumCitySizeTypes(0)
	, m_iNumFootstepAudioTypes(0)
	, m_iViewportSizeX(0)
	, m_iViewportSizeY(0)
	, m_iStoreExeSettingsCommerceInfo(0)
	, m_iStoreExeSettingsYieldInfo(0)
	, m_iStoreExeSettingsReligionInfo(0)
	, m_iStoreExeSettingsCorporationInfo(0)
	, m_iStoreExeSettingsBonusInfo(0)
	, m_bSignsCleared(false)

#define ADD_INT_TO_CONSTRUCTOR(dataType, VAR) \
	, m_##VAR(0)
	DO_FOR_EACH_INT_GLOBAL_DEFINE(ADD_INT_TO_CONSTRUCTOR)
	DO_FOR_EACH_ENUM_GLOBAL_DEFINE(ADD_INT_TO_CONSTRUCTOR)
	DO_FOR_EACH_FLOAT_GLOBAL_DEFINE(ADD_INT_TO_CONSTRUCTOR)

#define ADD_BOOL_TO_CONSTRUCTOR(dataType, VAR) \
	, m_##VAR(false)
	DO_FOR_EACH_BOOL_GLOBAL_DEFINE(ADD_BOOL_TO_CONSTRUCTOR)
{
}

CvGlobals::~CvGlobals()
{
}

/************************************************************************************************/
/* MINIDUMP_MOD                           04/10/11                                terkhen       */
/*                                                                                              */
/* See http://www.debuginfo.com/articles/effminidumps.html                                      */
/************************************************************************************************/
#define MINIDUMP
#ifdef MINIDUMP

#include <dbghelp.h>
#pragma comment (lib, "dbghelp.lib")


std::string getPyTrace()
{
	std::vector<Cy::StackFrame> trace = Cy::get_stack_trace();

	std::stringstream buffer;

	for (std::vector<Cy::StackFrame>::const_iterator itr = trace.begin(); itr != trace.end(); ++itr)
	{
		if (itr != trace.begin()) buffer << "\r\n";
		buffer << CvString::format("%s.py (%d): %s", itr->filename.c_str(), itr->line, itr->code.c_str());
	}

	return buffer.str();
}

void CreateMiniDump(EXCEPTION_POINTERS *pep)
{
	_TCHAR filename[256];

	time_t rawtime;
	struct tm* timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);

	_stprintf(filename, _T("MiniDump-%s-%d%02d%02d-%02d%02d%02d.dmp"), C2C_VERSION, 1900 + timeinfo->tm_year, timeinfo->tm_mon, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

	/* Open a file to store the minidump. */
	HANDLE hFile = CreateFile(filename,
							  GENERIC_READ | GENERIC_WRITE,
							  0,
							  NULL,
							  CREATE_ALWAYS,
							  FILE_ATTRIBUTE_NORMAL,
							  NULL);

	if((hFile == NULL) || (hFile == INVALID_HANDLE_VALUE)) 
	{
		return;
	}

	/* Create the minidump. */
	MINIDUMP_EXCEPTION_INFORMATION mdei;

	mdei.ThreadId           = GetCurrentThreadId();
	mdei.ExceptionPointers  = pep;
	mdei.ClientPointers     = FALSE;

	MINIDUMP_TYPE mdt       = MiniDumpNormal;

	BOOL result = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
									hFile,
									mdt,
									(pep != NULL) ? &mdei : NULL,
									NULL,
									NULL);

	/* Close the file. */
	CloseHandle(hFile);
	std::string pyTrace = getPyTrace();
	if(!pyTrace.empty())
	{
		gDLL->logMsg("PythonCallstack.log", pyTrace.c_str(), true, false);
	}
}

LONG WINAPI CustomFilter(EXCEPTION_POINTERS *ExceptionInfo)
{
	CreateMiniDump(ExceptionInfo);
	return EXCEPTION_EXECUTE_HANDLER;
}

#endif
/************************************************************************************************/
/* MINIDUMP_MOD                                END                                              */
/************************************************************************************************/

//
// allocate
//
void CvGlobals::init()
{
	OutputDebugString("Initializing Internal Globals: Start");
/************************************************************************************************/
/* MINIDUMP_MOD                           04/10/11                                terkhen       */
/************************************************************************************************/

#ifdef MINIDUMP
	/* Enable our custom exception that will write the minidump for us. */
	SetUnhandledExceptionFilter(CustomFilter);
#endif

/************************************************************************************************/
/* MINIDUMP_MOD                                END                                              */
/************************************************************************************************/

	//
	// These vars are used to initialize the globals.
	//

	int aiPlotDirectionX[NUM_DIRECTION_TYPES] =
	{
		0,	// DIRECTION_NORTH
		1,	// DIRECTION_NORTHEAST
		1,	// DIRECTION_EAST
		1,	// DIRECTION_SOUTHEAST
		0,	// DIRECTION_SOUTH
		-1,	// DIRECTION_SOUTHWEST
		-1,	// DIRECTION_WEST
		-1,	// DIRECTION_NORTHWEST
	};

	int aiPlotDirectionY[NUM_DIRECTION_TYPES] =
	{
		1,	// DIRECTION_NORTH
		1,	// DIRECTION_NORTHEAST
		0,	// DIRECTION_EAST
		-1,	// DIRECTION_SOUTHEAST
		-1,	// DIRECTION_SOUTH
		-1,	// DIRECTION_SOUTHWEST
		0,	// DIRECTION_WEST
		1,	// DIRECTION_NORTHWEST
	};

	int aiPlotCardinalDirectionX[NUM_CARDINALDIRECTION_TYPES] =
	{
		0,	// CARDINALDIRECTION_NORTH
		1,	// CARDINALDIRECTION_EAST
		0,	// CARDINALDIRECTION_SOUTH
		-1,	// CARDINALDIRECTION_WEST
	};

	int aiPlotCardinalDirectionY[NUM_CARDINALDIRECTION_TYPES] =
	{
		1,	// CARDINALDIRECTION_NORTH
		0,	// CARDINALDIRECTION_EAST
		-1,	// CARDINALDIRECTION_SOUTH
		0,	// CARDINALDIRECTION_WEST
	};

	int aiCityPlotX[NUM_CITY_PLOTS] =
	{
		0,
		0, 1, 1, 1, 0,-1,-1,-1,
		0, 1, 2, 2, 2, 1, 0,-1,-2,-2,-2,-1,
/************************************************************************************************/
/* JOOYO_ADDON, Added by Jooyo, 06/17/09                                                        */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
		0, 1, 2, 3, 3, 3, 2, 1, 0, -1, -2, -3, -3, -3, -2, -1,
/************************************************************************************************/
/* JOOYO_ADDON                          END                                                     */
/************************************************************************************************/
	};

	int aiCityPlotY[NUM_CITY_PLOTS] =
	{
		0,
		1, 1, 0,-1,-1,-1, 0, 1,
		2, 2, 1, 0,-1,-2,-2,-2,-1, 0, 1, 2,
/************************************************************************************************/
/* JOOYO_ADDON, Added by Jooyo, 06/17/09                                                        */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
		3, 3, 2, 1, 0, -1, -2, -3, -3, -3, -2, -1, 0, 1, 2, 3,
/************************************************************************************************/
/* JOOYO_ADDON                          END                                                     */
/************************************************************************************************/
	};

	int aiCityPlotPriority[NUM_CITY_PLOTS] =
	{
		0,
		1, 2, 1, 2, 1, 2, 1, 2,
		3, 4, 4, 3, 4, 4, 3, 4, 4, 3, 4, 4,
/************************************************************************************************/
/* JOOYO_ADDON, Added by Jooyo, 06/17/09                                                        */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
		5, 6, 7, 6, 5, 6, 7, 6, 5, 6, 7, 6, 5, 6, 7, 6,
/************************************************************************************************/
/* JOOYO_ADDON                          END                                                     */
/************************************************************************************************/
	};

	int aaiXYCityPlot[CITY_PLOTS_DIAMETER][CITY_PLOTS_DIAMETER] =
	{
/************************************************************************************************/
/* JOOYO_ADDON, Added by Jooyo, 06/17/09                                                        */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
		{-1, -1, 32, 33, 34, -1, -1},
		{-1, 31, 17, 18, 19, 35, -1},
		{30, 16, 6,   7,  8, 20, 36},
		{29, 15, 5,   0,  1,  9, 21},
		{28, 14, 4,   3,  2, 10, 22},
		{-1, 27, 13, 12, 11, 23, -1},
		{-1, -1, 26, 25, 24, -1, -1},
/************************************************************************************************/
/* JOOYO_ADDON                          END                                                     */
/************************************************************************************************/
	};

	DirectionTypes aeTurnRightDirection[NUM_DIRECTION_TYPES] =
	{
		DIRECTION_NORTHEAST,	// DIRECTION_NORTH
		DIRECTION_EAST,				// DIRECTION_NORTHEAST
		DIRECTION_SOUTHEAST,	// DIRECTION_EAST
		DIRECTION_SOUTH,			// DIRECTION_SOUTHEAST
		DIRECTION_SOUTHWEST,	// DIRECTION_SOUTH
		DIRECTION_WEST,				// DIRECTION_SOUTHWEST
		DIRECTION_NORTHWEST,	// DIRECTION_WEST
		DIRECTION_NORTH,			// DIRECTION_NORTHWEST
	};

	DirectionTypes aeTurnLeftDirection[NUM_DIRECTION_TYPES] =
	{
		DIRECTION_NORTHWEST,	// DIRECTION_NORTH
		DIRECTION_NORTH,			// DIRECTION_NORTHEAST
		DIRECTION_NORTHEAST,	// DIRECTION_EAST
		DIRECTION_EAST,				// DIRECTION_SOUTHEAST
		DIRECTION_SOUTHEAST,	// DIRECTION_SOUTH
		DIRECTION_SOUTH,			// DIRECTION_SOUTHWEST
		DIRECTION_SOUTHWEST,	// DIRECTION_WEST
		DIRECTION_WEST,				// DIRECTION_NORTHWEST
	};

	DirectionTypes aaeXYDirection[DIRECTION_DIAMETER][DIRECTION_DIAMETER] =
	{
		DIRECTION_SOUTHWEST, DIRECTION_WEST,	DIRECTION_NORTHWEST,
		DIRECTION_SOUTH,     NO_DIRECTION,    DIRECTION_NORTH,
		DIRECTION_SOUTHEAST, DIRECTION_EAST,	DIRECTION_NORTHEAST,
	};

	FAssertMsg(gDLL != NULL, "Civ app needs to set gDLL");

	m_VarSystem = new FVariableSystem;
	m_asyncRand = new CvRandom;
	m_initCore = new CvInitCore;
	m_loadedInitCore = new CvInitCore;
	m_iniInitCore = new CvInitCore;

	gDLL->initGlobals();	// some globals need to be allocated outside the dll

	m_game = new CvGameAI;
	
/*********************************/
/***** Parallel Maps - Begin *****/
/*********************************/
	m_maps.push_back(new CvMap(MAP_INITIAL));
/*******************************/
/***** Parallel Maps - End *****/
/*******************************/

	CvPlayerAI::initStatics();
	CvTeamAI::initStatics();

	COPY(m_aiPlotDirectionX, aiPlotDirectionX, int);
	COPY(m_aiPlotDirectionY, aiPlotDirectionY, int);
	COPY(m_aiPlotCardinalDirectionX, aiPlotCardinalDirectionX, int);
	COPY(m_aiPlotCardinalDirectionY, aiPlotCardinalDirectionY, int);
	COPY(m_aiCityPlotX, aiCityPlotX, int);
	COPY(m_aiCityPlotY, aiCityPlotY, int);
	COPY(m_aiCityPlotPriority, aiCityPlotPriority, int);
	COPY(m_aeTurnLeftDirection, aeTurnLeftDirection, DirectionTypes);
	COPY(m_aeTurnRightDirection, aeTurnRightDirection, DirectionTypes);
	memcpy(m_aaiXYCityPlot, aaiXYCityPlot, sizeof(m_aaiXYCityPlot));
	memcpy(m_aaeXYDirection, aaeXYDirection,sizeof(m_aaeXYDirection));

	m_bSignsCleared = false;
	m_bResourceLayerOn = false;

	OutputDebugString("Initializing Internal Globals: End");
}

//
// free
//
void CvGlobals::uninit()
{
	//
	// See also CvXMLLoadUtilityInit.cpp::CleanUpGlobalVariables()
	//
	SAFE_DELETE_ARRAY(m_aiPlotDirectionX);
	SAFE_DELETE_ARRAY(m_aiPlotDirectionY);
	SAFE_DELETE_ARRAY(m_aiPlotCardinalDirectionX);
	SAFE_DELETE_ARRAY(m_aiPlotCardinalDirectionY);
	SAFE_DELETE_ARRAY(m_aiCityPlotX);
	SAFE_DELETE_ARRAY(m_aiCityPlotY);
	SAFE_DELETE_ARRAY(m_aiCityPlotPriority);
	SAFE_DELETE_ARRAY(m_aeTurnLeftDirection);
	SAFE_DELETE_ARRAY(m_aeTurnRightDirection);

	SAFE_DELETE(m_game);
	
/*********************************/
/***** Parallel Maps - Begin *****/
/*********************************/
	for (std::vector<CvMap*>::iterator it = m_maps.begin(); it != m_maps.end(); ++it)
	{
		SAFE_DELETE(*it);
	}
	m_maps.clear();
/*******************************/
/***** Parallel Maps - End *****/
/*******************************/

	CvPlayerAI::freeStatics();
	CvTeamAI::freeStatics();

	SAFE_DELETE(m_asyncRand);
	SAFE_DELETE(m_initCore);
	SAFE_DELETE(m_loadedInitCore);
	SAFE_DELETE(m_iniInitCore);
	gDLL->uninitGlobals();	// free globals allocated outside the dll
	SAFE_DELETE(m_VarSystem);

	// already deleted outside of the dll, set to null for safety
	m_messageQueue=NULL;
	m_hotJoinMsgQueue=NULL;
	m_messageControl=NULL;
	m_setupData=NULL;
	m_messageCodes=NULL;
	m_dropMgr=NULL;
	m_portal=NULL;
	m_statsReporter=NULL;
	m_interface=NULL;
	m_diplomacyScreen=NULL;
	m_mpDiplomacyScreen=NULL;
	m_pathFinder=NULL;
	m_interfacePathFinder=NULL;
	m_stepFinder=NULL;
	m_routeFinder=NULL;
	m_borderFinder=NULL;
	m_areaFinder=NULL;
	m_plotGroupFinder=NULL;

	m_typesMap.clear();
	m_aInfoVectors.clear();
}

void CvGlobals::clearTypesMap()
{
	m_typesMap.clear();
	if (m_VarSystem)
	{
		m_VarSystem->UnInit();
	}
}

std::vector<CvInterfaceModeInfo*>& CvGlobals::getInterfaceModeInfos()
{
	return m_paInterfaceModeInfo;
}

CvInterfaceModeInfo& CvGlobals::getInterfaceModeInfo(InterfaceModeTypes e)
{
	FAssertMsg(e >= 0 && e < NUM_INTERFACEMODE_TYPES, "InterfaceModeInfo index out of bounds");
	return *(m_paInterfaceModeInfo[e]);
}

int* CvGlobals::getPlotDirectionX()
{
	return m_aiPlotDirectionX;
}

int* CvGlobals::getPlotDirectionY()
{
	return m_aiPlotDirectionY;
}

int* CvGlobals::getPlotCardinalDirectionX()
{
	return m_aiPlotCardinalDirectionX;
}

int* CvGlobals::getPlotCardinalDirectionY()
{
	return m_aiPlotCardinalDirectionY;
}

int* CvGlobals::getCityPlotX() const
{
	return m_aiCityPlotX;
}

int* CvGlobals::getCityPlotY() const
{
	return m_aiCityPlotY;
}

int* CvGlobals::getCityPlotPriority() const
{
	return m_aiCityPlotPriority;
}

int CvGlobals::getXYCityPlot(int i, int j) const
{
	FAssertMsg(i >= 0 && i < CITY_PLOTS_DIAMETER, "XYCityPlot i index out of bounds");
	FAssertMsg(j >= 0 && j < CITY_PLOTS_DIAMETER, "XYCityPlot j index out of bounds");
	return m_aaiXYCityPlot[i][j];
}

DirectionTypes* CvGlobals::getTurnLeftDirection() const
{
	return m_aeTurnLeftDirection;
}

DirectionTypes CvGlobals::getTurnLeftDirection(int i) const
{
	FAssertMsg(i >= 0 && i < DIRECTION_DIAMETER, "TurnLeftDirection index out of bounds");
	return m_aeTurnLeftDirection[i];
}

DirectionTypes* CvGlobals::getTurnRightDirection() const
{
	return m_aeTurnRightDirection;
}

DirectionTypes CvGlobals::getTurnRightDirection(int i) const
{
	FAssertMsg(i >= 0 && i < DIRECTION_DIAMETER, "TurnRightDirection index out of bounds");
	return m_aeTurnRightDirection[i];
}

DirectionTypes CvGlobals::getXYDirection(int i, int j)
{
	FAssertMsg(i >= 0 && i < DIRECTION_DIAMETER, "XYDirection i index out of bounds");
	FAssertMsg(j >= 0 && j < DIRECTION_DIAMETER, "XYDirection j index out of bounds");
	return m_aaeXYDirection[i][j];
}

/*********************************/
/***** Parallel Maps - Begin *****/
/*********************************/
bool CvGlobals::multiMapsEnabled() const
{
	return m_bMultimapsEnabled;
}

bool CvGlobals::viewportsEnabled() const
{
	return m_bViewportsEnabled;
}

bool CvGlobals::getReprocessGreatWallDynamically() const
{
	return m_bViewportsEnabled || (getDefineBOOL("DYNAMIC_GREAT_WALL") != 0);
}

int CvGlobals::getNumMapInfos() const
{
	return multiMapsEnabled() ? m_paMapInfo.size() : 1;
}

int CvGlobals::getNumMapSwitchInfos() const
{
	return m_paMapSwitchInfo.size();
}

CvMapInfo& CvGlobals::getMapInfo(MapTypes eMap) const
{
	FAssertMsg(eMap > NO_MAP && eMap < GC.getNumMapInfos(), "MapInfo index out of bounds");
	return *(m_paMapInfo[eMap]);
}

CvMapSwitchInfo& CvGlobals::getMapSwitchInfo(MapSwitchTypes eMapSwitch) const
{
	FAssertMsg(eMapSwitch > NO_MAPSWITCH && eMapSwitch < GC.getNumMapSwitchInfos(), "MapSwitchInfo index out of bounds");
	return *(m_paMapSwitchInfo[eMapSwitch]);
}

void CvGlobals::updateMaps()
{
	for (int i = 1; i < GC.getNumMapInfos(); i++)
	{
		m_maps.push_back(NULL);
	}
	FAssert(m_maps.size() == GC.getNumMapInfos());
}

void CvGlobals::setResourceLayer(bool bOn)
{
	m_bResourceLayerOn = bOn;

	gDLL->getEngineIFace()->setResourceLayer(bOn);
}

bool CvGlobals::getResourceLayer() const
{
	return m_bResourceLayerOn;
}

/*******************************/
/***** Parallel Maps - End *****/
/*******************************/

int CvGlobals::getNumWorldInfos()
{
	return (int)m_paWorldInfo.size();
}

CvWorldInfo& CvGlobals::getWorldInfo(WorldSizeTypes e)
{
	FAssertMsg(e >= 0 && e < GC.getNumWorldInfos(), "WorldInfo index out of bounds");
	return *(m_paWorldInfo[e]);
}

/////////////////////////////////////////////
// CLIMATE
/////////////////////////////////////////////

int CvGlobals::getNumClimateInfos()
{
	return (int)m_paClimateInfo.size();
}

CvClimateInfo& CvGlobals::getClimateInfo(ClimateTypes e)
{
	FAssertMsg(e >= 0 && e < GC.getNumClimateInfos(), "ClimateInfo index out of bounds");
	return *(m_paClimateInfo[e]);
}

/////////////////////////////////////////////
// SEALEVEL
/////////////////////////////////////////////

int CvGlobals::getNumSeaLevelInfos()
{
	return (int)m_paSeaLevelInfo.size();
}

CvSeaLevelInfo& CvGlobals::getSeaLevelInfo(SeaLevelTypes e)
{
	FAssertMsg(e >= 0 && e < GC.getNumSeaLevelInfos(), "SeaLevelInfo index out of bounds");
	return *(m_paSeaLevelInfo[e]);
}

int CvGlobals::getNumHints()
{
	return (int)m_paHints.size();
}

CvInfoBase& CvGlobals::getHints(int i)
{
	return *(m_paHints[i]);
}

int CvGlobals::getNumMainMenus() const
{
	return (int)m_paMainMenus.size();
}

CvMainMenuInfo& CvGlobals::getMainMenus(int i)
{
	if (i >= getNumMainMenus())
	{
		return *(m_paMainMenus[0]);
	}

	return *(m_paMainMenus[i]);
}
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 10/30/07                            MRGENIE          */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
// MLF loading
void CvGlobals::resetModLoadControlVector()
{
	m_paModLoadControlVector.clear();
}

int CvGlobals::getModLoadControlVectorSize() const
{
	return (int)m_paModLoadControlVector.size();
}

void CvGlobals::setModLoadControlVector(const char* szModule)
{
	m_paModLoadControlVector.push_back(szModule);
}

CvString CvGlobals::getModLoadControlVector(int i) const
{
	return (CvString)m_paModLoadControlVector.at(i);
}

int CvGlobals::getTotalNumModules() const
{
	return m_iTotalNumModules;
}

void CvGlobals::setTotalNumModules()
{
	m_iTotalNumModules++;
}

int CvGlobals::getNumModLoadControlInfos() const
{
	return (int)m_paModLoadControls.size();
}

CvModLoadControlInfo& CvGlobals::getModLoadControlInfos(int iIndex) const
{
	FAssertMsg(iIndex >= 0 && iIndex < getNumModLoadControlInfos(), "ModLoadControlInfo index out of bounds");
	return *(m_paModLoadControls[iIndex]);
}

void CvGlobals::updateReplacements()
{
//ReplacementStep
	m_WorldInfoReplacements.updateReplacements(m_paWorldInfo);
	m_UnitInfoReplacements.updateReplacements(m_paUnitInfo);
	m_TechInfoReplacements.updateReplacements(m_paTechInfo);
	m_TraitInfoReplacements.updateReplacements(m_paTraitInfo);
	m_PromotionInfoReplacements.updateReplacements(m_paPromotionInfo);
	m_BonusClassInfoReplacements.updateReplacements(m_paBonusClassInfo);
	m_BonusInfoReplacements.updateReplacements(m_paBonusInfo);
	m_ImprovementInfoReplacements.updateReplacements(m_paImprovementInfo);
	m_BuildingInfoReplacements.updateReplacements(m_paBuildingInfo);
	m_CivicInfoReplacements.updateReplacements(m_paCivicInfo);
	m_LeaderHeadInfoReplacements.updateReplacements(m_paLeaderHeadInfo);

	m_CivilizationInfoReplacements.updateReplacements(m_paCivilizationInfo);

	m_CultureLevelInfoReplacements.updateReplacements(m_paCultureLevelInfo);

	m_EventInfoReplacements.updateReplacements(m_paEventInfo);
	m_EventTriggerInfoReplacements.updateReplacements(m_paEventTriggerInfo);
	m_ProcessInfoReplacements.updateReplacements(m_paProcessInfo);
	m_TerrainInfoReplacements.updateReplacements(m_paTerrainInfo);

	m_SpecialistInfoReplacements.updateReplacements(m_paSpecialistInfo);

	m_FeatureInfoReplacements.updateReplacements(m_paFeatureInfo);

	m_ReligionInfoReplacements.updateReplacements(m_paReligionInfo);
	m_CorporationInfoReplacements.updateReplacements(m_paCorporationInfo);

	m_RouteInfoReplacements.updateReplacements(m_paRouteInfo);
	
	m_ProjectInfoReplacements.updateReplacements(m_paProjectInfo);

	m_BuildInfoReplacements.updateReplacements(m_paBuildInfo);
	
	m_SpawnInfoReplacements.updateReplacements(m_paSpawnInfo);
	m_GameSpeedInfoReplacements.updateReplacements(m_paGameSpeedInfo);
	m_EraInfoReplacements.updateReplacements(m_aEraInfo);
	
	m_SpecialBuildingInfoReplacements.updateReplacements(m_paSpecialBuildingInfo);
	
	m_HandicapInfoReplacements.updateReplacements(m_paHandicapInfo);
//ReplacementStep: search down here for 'CvInfoReplacements'
}

/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 END                                                  */
/************************************************************************************************/
/************************************************************************************************/
/* XML_MODULAR_ART_LOADING                 10/26/07                            MRGENIE          */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
void CvGlobals::setModDir(const char* szModDir)
{
	m_cszModDir = szModDir;
}

std::string CvGlobals::getModDir() const
{
	return m_cszModDir;
}
/************************************************************************************************/
/* XML_MODULAR_ART_LOADING                 END                                                  */
/************************************************************************************************/

int CvGlobals::getNumColorInfos() const
{
	return (int)m_paColorInfo.size();
}

CvColorInfo& CvGlobals::getColorInfo(ColorTypes e)
{
	FAssertMsg(e >= 0 && e < GC.getNumColorInfos(), "ColorInfo index out of bounds");
	return *(m_paColorInfo[e]);
}


int CvGlobals::getNumPlayerColorInfos()
{
	return (int)m_paPlayerColorInfo.size();
}

CvPlayerColorInfo& CvGlobals::getPlayerColorInfo(PlayerColorTypes e)
{
	FAssertMsg(e >= 0 && e < GC.getNumPlayerColorInfos(), "PlayerColorInfo index out of bounds");
	return *(m_paPlayerColorInfo[e]);
}

int CvGlobals::getNumAdvisorInfos() const
{
	return (int)m_paAdvisorInfo.size();
}

CvAdvisorInfo& CvGlobals::getAdvisorInfo(AdvisorTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumAdvisorInfos(), "AdvisorInfo index out of bounds");
	return *(m_paAdvisorInfo[e]);
}

int CvGlobals::getNumRouteModelInfos()
{
	return (int)m_paRouteModelInfo.size();
}

CvRouteModelInfo& CvGlobals::getRouteModelInfo(int i)
{
	FAssertMsg(i >= 0 && i < GC.getNumRouteModelInfos(), "RouteModelInfo index out of bounds");
	return *(m_paRouteModelInfo[i]);
}

int CvGlobals::getNumRiverModelInfos()
{
	return (int)m_paRiverModelInfo.size();
}

CvRiverModelInfo& CvGlobals::getRiverModelInfo(int i)
{
	FAssertMsg(i >= 0 && i < GC.getNumRiverModelInfos(), "RiverModelInfo index out of bounds");
	return *(m_paRiverModelInfo[i]);
}

int CvGlobals::getNumWaterPlaneInfos() const
{
	return (int)m_paWaterPlaneInfo.size();
}

CvWaterPlaneInfo& CvGlobals::getWaterPlaneInfo(int i)
{
	FAssertMsg(i >= 0 && i < GC.getNumWaterPlaneInfos(), "WaterPlaneInfo index out of bounds");
	return *(m_paWaterPlaneInfo[i]);
}

int CvGlobals::getNumTerrainPlaneInfos()
{
	return (int)m_paTerrainPlaneInfo.size();
}

CvTerrainPlaneInfo& CvGlobals::getTerrainPlaneInfo(int i)
{
	FAssertMsg(i >= 0 && i < GC.getNumTerrainPlaneInfos(), "TerrainPlaneInfo index out of bounds");
	return *(m_paTerrainPlaneInfo[i]);
}

int CvGlobals::getNumCameraOverlayInfos()
{
	return (int)m_paCameraOverlayInfo.size();
}

CvCameraOverlayInfo& CvGlobals::getCameraOverlayInfo(int i)
{
	FAssertMsg(i >= 0 && i < GC.getNumCameraOverlayInfos(), "CameraOverlayInfo index out of bounds");
	return *(m_paCameraOverlayInfo[i]);
}

int CvGlobals::getNumAnimationPathInfos() const
{
	return (int)m_paAnimationPathInfo.size();
}

CvAnimationPathInfo& CvGlobals::getAnimationPathInfo(AnimationPathTypes e)
{
	FAssertMsg(e >= 0 && e < GC.getNumAnimationPathInfos(), "AnimationPathInfo index out of bounds");
	return *(m_paAnimationPathInfo[e]);
}

int CvGlobals::getNumAnimationCategoryInfos() const
{
	return (int)m_paAnimationCategoryInfo.size();
}

CvAnimationCategoryInfo& CvGlobals::getAnimationCategoryInfo(AnimationCategoryTypes e)
{
	FAssertMsg(e >= 0 && e < GC.getNumAnimationCategoryInfos(), "AnimationCategoryInfo index out of bounds");
	return *(m_paAnimationCategoryInfo[e]);
}

int CvGlobals::getNumEntityEventInfos() const
{
	return (int)m_paEntityEventInfo.size();
}

CvEntityEventInfo& CvGlobals::getEntityEventInfo(EntityEventTypes e)
{
	FAssertMsg(e >= 0 && e < GC.getNumEntityEventInfos(), "EntityEventInfo index out of bounds");
	return *(m_paEntityEventInfo[e]);
}

int CvGlobals::getNumEffectInfos() const
{
	return (int)m_paEffectInfo.size();
}

CvEffectInfo& CvGlobals::getEffectInfo(int i)
{
	FAssertMsg(i >= 0 && i < GC.getNumEffectInfos(), "EffectInfo index out of bounds");
	return *(m_paEffectInfo[i]);
}


int CvGlobals::getNumAttachableInfos() const
{
	return (int)m_paAttachableInfo.size();
}

CvAttachableInfo& CvGlobals::getAttachableInfo(int i)
{
	FAssertMsg(i >= 0 && i < GC.getNumAttachableInfos(), "AttachableInfo index out of bounds");
	return *(m_paAttachableInfo[i]);
}

int CvGlobals::getNumUnitFormationInfos()
{
	return (int)m_paUnitFormationInfo.size();
}

CvUnitFormationInfo& CvGlobals::getUnitFormationInfo(int i)
{
	FAssertMsg(i >= 0 && i < GC.getNumUnitFormationInfos(), "UnitFormationInfo index out of bounds");
	return *(m_paUnitFormationInfo[i]);
}

// Landscape INFOS
int CvGlobals::getNumLandscapeInfos() const
{
	return (int)m_paLandscapeInfo.size();
}

CvLandscapeInfo& CvGlobals::getLandscapeInfo(int iIndex)
{
	FAssertMsg(iIndex >= 0 && iIndex < GC.getNumLandscapeInfos(), "LandscapeInfo index out of bounds");
	return *(m_paLandscapeInfo[iIndex]);
}

int CvGlobals::getActiveLandscapeID()
{
	return m_iActiveLandscapeID;
}

void CvGlobals::setActiveLandscapeID(int iLandscapeID)
{
	m_iActiveLandscapeID = iLandscapeID;
}


int CvGlobals::getNumTerrainInfos()
{
	return (int)m_paTerrainInfo.size();
}

CvTerrainInfo& CvGlobals::getTerrainInfo(TerrainTypes eTerrainNum)
{
	FAssertMsg(eTerrainNum >= 0 && eTerrainNum < GC.getNumTerrainInfos(), "TerrainInfo index out of bounds");
	return *(m_paTerrainInfo[eTerrainNum]);
}

int CvGlobals::getNumBonusClassInfos() const
{
	return (int)m_paBonusClassInfo.size();
}

CvBonusClassInfo& CvGlobals::getBonusClassInfo(BonusClassTypes eBonusNum) const
{
	FAssertMsg(eBonusNum >= 0 && eBonusNum < GC.getNumBonusClassInfos(), "BonusClassInfo index out of bounds");
	return *(m_paBonusClassInfo[eBonusNum]);
}


int CvGlobals::getNumBonusInfos()
{
	return (int)m_paBonusInfo.size();
}

const std::vector<CvBonusInfo*>& CvGlobals::getBonusInfos() const
{
	return m_paBonusInfo;
}

CvBonusInfo& CvGlobals::getBonusInfo(BonusTypes eBonusNum)
{
	FAssertMsg(eBonusNum >= 0 && eBonusNum < GC.getNumBonusInfos(), "BonusInfo index out of bounds");
	return *(m_paBonusInfo[eBonusNum]);
}

int CvGlobals::getNumFeatureInfos()
{
	return (int)m_paFeatureInfo.size();
}

CvFeatureInfo& CvGlobals::getFeatureInfo(FeatureTypes eFeatureNum)
{
	FAssertMsg(eFeatureNum >= 0 && eFeatureNum < GC.getNumFeatureInfos(), "FeatureInfo index out of bounds");
	return *(m_paFeatureInfo[eFeatureNum]);
}

int& CvGlobals::getNumPlayableCivilizationInfos()
{
	return m_iNumPlayableCivilizationInfos;
}

int& CvGlobals::getNumAIPlayableCivilizationInfos()
{
	return m_iNumAIPlayableCivilizationInfos;
}

int CvGlobals::getNumCivilizationInfos()
{
	return (int)m_paCivilizationInfo.size();
}

CvCivilizationInfo& CvGlobals::getCivilizationInfo(CivilizationTypes eCivilizationNum)
{
	FAssertMsg(eCivilizationNum >= 0 && eCivilizationNum < GC.getNumCivilizationInfos(), "CivilizationInfo index out of bounds");
	return *(m_paCivilizationInfo[eCivilizationNum]);
}


int CvGlobals::getNumLeaderHeadInfos()
{
	return (int)m_paLeaderHeadInfo.size();
}

CvLeaderHeadInfo& CvGlobals::getLeaderHeadInfo(LeaderHeadTypes eLeaderHeadNum)
{
	FAssertMsg(eLeaderHeadNum >= 0 && eLeaderHeadNum < GC.getNumLeaderHeadInfos(), "LeaderHeadInfo index out of bounds");
	return *(m_paLeaderHeadInfo[eLeaderHeadNum]);
}


int CvGlobals::getNumTraitInfos() const
{
	return (int)m_paTraitInfo.size();
}

CvTraitInfo& CvGlobals::getTraitInfo(TraitTypes eTraitNum) const
{
	FAssertMsg(eTraitNum >= 0 && eTraitNum < GC.getNumTraitInfos(), "TraitInfo index out of bounds");
	return *(m_paTraitInfo[eTraitNum]);
}


int CvGlobals::getNumCursorInfos()
{
	return (int)m_paCursorInfo.size();
}

CvCursorInfo& CvGlobals::getCursorInfo(CursorTypes eCursorNum)
{
	FAssertMsg(eCursorNum >= 0 && eCursorNum < GC.getNumCursorInfos(), "CursorInfo index out of bounds");
	return *(m_paCursorInfo[eCursorNum]);
}

int CvGlobals::getNumThroneRoomCameras() const
{
	return (int)m_paThroneRoomCamera.size();
}

CvThroneRoomCamera& CvGlobals::getThroneRoomCamera(int iIndex)
{
	FAssertMsg(iIndex >= 0 && iIndex < GC.getNumThroneRoomCameras(), "ThroneRoomCamera index out of bounds");
	return *(m_paThroneRoomCamera[iIndex]);
}

int CvGlobals::getNumThroneRoomInfos() const
{
	return (int)m_paThroneRoomInfo.size();
}

CvThroneRoomInfo& CvGlobals::getThroneRoomInfo(int iIndex)
{
	FAssertMsg(iIndex >= 0 && iIndex < GC.getNumThroneRoomInfos(), "ThroneRoomInfo index out of bounds");
	return *(m_paThroneRoomInfo[iIndex]);
}

int CvGlobals::getNumThroneRoomStyleInfos()
{
	return (int)m_paThroneRoomStyleInfo.size();
}

CvThroneRoomStyleInfo& CvGlobals::getThroneRoomStyleInfo(int iIndex)
{
	FAssertMsg(iIndex >= 0 && iIndex < GC.getNumThroneRoomStyleInfos(), "ThroneRoomStyleInfo index out of bounds");
	return *(m_paThroneRoomStyleInfo[iIndex]);
}

int CvGlobals::getNumSlideShowInfos()
{
	return (int)m_paSlideShowInfo.size();
}

CvSlideShowInfo& CvGlobals::getSlideShowInfo(int iIndex)
{
	FAssertMsg(iIndex >= 0 && iIndex < GC.getNumSlideShowInfos(), "SlideShowInfo index out of bounds");
	return *(m_paSlideShowInfo[iIndex]);
}

int CvGlobals::getNumSlideShowRandomInfos()
{
	return (int)m_paSlideShowRandomInfo.size();
}

CvSlideShowRandomInfo& CvGlobals::getSlideShowRandomInfo(int iIndex)
{
	FAssertMsg(iIndex >= 0 && iIndex < GC.getNumSlideShowRandomInfos(), "SlideShowRandomInfo index out of bounds");
	return *(m_paSlideShowRandomInfo[iIndex]);
}

int CvGlobals::getNumWorldPickerInfos()
{
	return (int)m_paWorldPickerInfo.size();
}

CvWorldPickerInfo& CvGlobals::getWorldPickerInfo(int iIndex)
{
	FAssertMsg(iIndex >= 0 && iIndex < GC.getNumWorldPickerInfos(), "WorldPickerInfo index out of bounds");
	return *(m_paWorldPickerInfo[iIndex]);
}

int CvGlobals::getNumSpaceShipInfos()
{
	return (int)m_paSpaceShipInfo.size();
}

CvSpaceShipInfo& CvGlobals::getSpaceShipInfo(int iIndex)
{
	FAssertMsg(iIndex >= 0 && iIndex < GC.getNumSpaceShipInfos(), "SpaceShipInfo index out of bounds");
	return *(m_paSpaceShipInfo[iIndex]);
}

int CvGlobals::getNumUnitInfos() const
{
	return (int)m_paUnitInfo.size();
}

CvUnitInfo& CvGlobals::getUnitInfo(UnitTypes eUnitNum) const
{
	FAssertMsg(eUnitNum >= 0 && eUnitNum < GC.getNumUnitInfos(), "UnitInfo index out of bounds");
	return *(m_paUnitInfo[eUnitNum]);
}

int CvGlobals::getNumSpawnInfos() const
{
	return (int)m_paSpawnInfo.size();
}

CvSpawnInfo& CvGlobals::getSpawnInfo(SpawnTypes eSpawnNum) const
{
	FAssertMsg(eSpawnNum >= 0 && eSpawnNum < GC.getNumSpawnInfos(), "SpawnInfo index out of bounds");
	return *(m_paSpawnInfo[eSpawnNum]);
}

int CvGlobals::getNumSpecialUnitInfos() const
{
	return (int)m_paSpecialUnitInfo.size();
}

CvSpecialUnitInfo& CvGlobals::getSpecialUnitInfo(SpecialUnitTypes eSpecialUnitNum) const
{
	FAssertMsg(eSpecialUnitNum >= 0 && eSpecialUnitNum < GC.getNumSpecialUnitInfos(), "SpecialUnitInfo index out of bounds");
	return *(m_paSpecialUnitInfo[eSpecialUnitNum]);
}


int CvGlobals::getNumConceptInfos() const
{
	return (int)m_paConceptInfo.size();
}

CvInfoBase& CvGlobals::getConceptInfo(ConceptTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumConceptInfos(), "ConceptInfo index out of bounds");
	return *(m_paConceptInfo[e]);
}


int CvGlobals::getNumNewConceptInfos() const
{
	return (int)m_paNewConceptInfo.size();
}

CvInfoBase& CvGlobals::getNewConceptInfo(NewConceptTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumNewConceptInfos(), "NewConceptInfo index out of bounds");
	return *(m_paNewConceptInfo[e]);
}


int CvGlobals::getNumCityTabInfos() const
{
	return (int)m_paCityTabInfo.size();
}

CvInfoBase& CvGlobals::getCityTabInfo(CityTabTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumCityTabInfos(), "CityTabInfo index out of bounds");
	return *(m_paCityTabInfo[e]);
}


int CvGlobals::getNumCalendarInfos() const
{
	return (int)m_paCalendarInfo.size();
}

CvInfoBase& CvGlobals::getCalendarInfo(CalendarTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumCalendarInfos(), "CalendarInfo index out of bounds");
	return *(m_paCalendarInfo[e]);
}


int CvGlobals::getNumSeasonInfos() const
{
	return (int)m_paSeasonInfo.size();
}

CvInfoBase& CvGlobals::getSeasonInfo(SeasonTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumSeasonInfos(), "SeasonInfo index out of bounds");
	return *(m_paSeasonInfo[e]);
}


int CvGlobals::getNumMonthInfos() const
{
	return (int)m_paMonthInfo.size();
}

CvInfoBase& CvGlobals::getMonthInfo(MonthTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumMonthInfos(), "MonthInfo index out of bounds");
	return *(m_paMonthInfo[e]);
}


int CvGlobals::getNumDenialInfos() const
{
	return (int)m_paDenialInfo.size();
}

CvInfoBase& CvGlobals::getDenialInfo(DenialTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumDenialInfos(), "DenialInfo index out of bounds");
	return *(m_paDenialInfo[e]);
}


int CvGlobals::getNumInvisibleInfos() const
{
	return (int)m_paInvisibleInfo.size();
}

CvInvisibleInfo& CvGlobals::getInvisibleInfo(InvisibleTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumInvisibleInfos(), "InvisibleInfo index out of bounds");
	return *(m_paInvisibleInfo[e]);
}


int CvGlobals::getNumVoteSourceInfos() const
{
	return (int)m_paVoteSourceInfo.size();
}

CvVoteSourceInfo& CvGlobals::getVoteSourceInfo(VoteSourceTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumVoteSourceInfos(), "VoteSourceInfo index out of bounds");
	return *(m_paVoteSourceInfo[e]);
}


int CvGlobals::getNumUnitCombatInfos() const
{
	return (int)m_paUnitCombatInfo.size();
}

CvUnitCombatInfo& CvGlobals::getUnitCombatInfo(UnitCombatTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumUnitCombatInfos(), "UnitCombatInfo index out of bounds");
	return *(m_paUnitCombatInfo[e]);
}


CvInfoBase& CvGlobals::getDomainInfo(DomainTypes e) const
{
	FAssertMsg(e >= 0 && e < NUM_DOMAIN_TYPES, "DomainInfo index out of bounds");
	return *(m_paDomainInfo[e]);
}

//TB Promotion Line Mod begin
int CvGlobals::getNumPromotionLineInfos() const
{
	return (int)m_paPromotionLineInfo.size();
}

CvPromotionLineInfo& CvGlobals::getPromotionLineInfo(PromotionLineTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumPromotionLineInfos(), "PromotionLineInfo index out of bounds");
	return *(m_paPromotionLineInfo[e]);
}
//TB Promotion Line Mod end

int CvGlobals::getNumMapCategoryInfos() const
{
	return (int)m_paMapCategoryInfo.size();
}

CvMapCategoryInfo& CvGlobals::getMapCategoryInfo(MapCategoryTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumMapCategoryInfos(), "MapCategoryInfo index out of bounds");
	return *(m_paMapCategoryInfo[e]);
}

int CvGlobals::getNumIdeaClassInfos() const
{
	return (int)m_paIdeaClassInfo.size();
}

CvIdeaClassInfo& CvGlobals::getIdeaClassInfo(IdeaClassTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumIdeaClassInfos(), "IdeaClassInfo index out of bounds");
	return *(m_paIdeaClassInfo[e]);
}

int CvGlobals::getNumIdeaInfos() const
{
	return (int)m_paIdeaInfo.size();
}

CvIdeaInfo& CvGlobals::getIdeaInfo(IdeaTypes e) const
{
	FAssertMsg(e >= 0 && e < GC.getNumIdeaInfos(), "IdeaInfo index out of bounds");
	return *(m_paIdeaInfo[e]);
}
//int CvGlobals::getNumTraitOptionEditsInfos() const
//{
//	return (int)m_paTraitOptionEditsInfo.size();
//}
//
//CvTraitOptionEditsInfo& CvGlobals::getTraitOptionEditsInfo(TraitOptionEditsTypes e) const
//{
//	FAssert(e > -1);
//	FAssert(e < GC.getNumTraitOptionEditsInfos());
//	return *(m_paTraitOptionEditsInfo[e]);
//}

CvInfoBase& CvGlobals::getUnitAIInfo(UnitAITypes eUnitAINum) const
{
	FAssertMsg(eUnitAINum >= 0 && eUnitAINum < NUM_UNITAI_TYPES, "UnitAIInfo index out of bounds");
	return *(m_paUnitAIInfos[eUnitAINum]);
}

//	Koshling - added internal registration of supported UnitAI types, not reliant
//	on external definition in XML
void CvGlobals::registerUnitAI(const char* szType, int enumVal)
{
	FAssertMsg(m_paUnitAIInfos.size() == enumVal, "enumVal not expected value");

	CvInfoBase* entry = new	CvInfoBase(szType);

	m_paUnitAIInfos.push_back(entry);
	setInfoTypeFromString(szType, enumVal);
}

#define	REGISTER_UNITAI(x)	registerUnitAI(#x,x)

void CvGlobals::registerUnitAIs()
{
	//	Sadly C++ doesn't have any reflection capability so need to do this explicitly
	REGISTER_UNITAI(UNITAI_UNKNOWN);
	REGISTER_UNITAI(UNITAI_ANIMAL);
	REGISTER_UNITAI(UNITAI_SETTLE);
	REGISTER_UNITAI(UNITAI_WORKER);
	REGISTER_UNITAI(UNITAI_ATTACK);
	REGISTER_UNITAI(UNITAI_ATTACK_CITY);
	REGISTER_UNITAI(UNITAI_COLLATERAL);
	REGISTER_UNITAI(UNITAI_PILLAGE);
	REGISTER_UNITAI(UNITAI_RESERVE);
	REGISTER_UNITAI(UNITAI_COUNTER);
	REGISTER_UNITAI(UNITAI_CITY_DEFENSE);
	REGISTER_UNITAI(UNITAI_CITY_COUNTER);
	REGISTER_UNITAI(UNITAI_CITY_SPECIAL);
	REGISTER_UNITAI(UNITAI_EXPLORE);
	REGISTER_UNITAI(UNITAI_MISSIONARY);
	REGISTER_UNITAI(UNITAI_PROPHET);
	REGISTER_UNITAI(UNITAI_ARTIST);
	REGISTER_UNITAI(UNITAI_SCIENTIST);
	REGISTER_UNITAI(UNITAI_GENERAL);
	REGISTER_UNITAI(UNITAI_MERCHANT);
	REGISTER_UNITAI(UNITAI_ENGINEER);
	REGISTER_UNITAI(UNITAI_SPY);
	REGISTER_UNITAI(UNITAI_ICBM);
	REGISTER_UNITAI(UNITAI_WORKER_SEA);
	REGISTER_UNITAI(UNITAI_ATTACK_SEA);
	REGISTER_UNITAI(UNITAI_RESERVE_SEA);
	REGISTER_UNITAI(UNITAI_ESCORT_SEA);
	REGISTER_UNITAI(UNITAI_EXPLORE_SEA);
	REGISTER_UNITAI(UNITAI_ASSAULT_SEA);
	REGISTER_UNITAI(UNITAI_SETTLER_SEA);
	REGISTER_UNITAI(UNITAI_MISSIONARY_SEA);
	REGISTER_UNITAI(UNITAI_SPY_SEA);
	REGISTER_UNITAI(UNITAI_CARRIER_SEA);
	REGISTER_UNITAI(UNITAI_MISSILE_CARRIER_SEA);
	REGISTER_UNITAI(UNITAI_PIRATE_SEA);
	REGISTER_UNITAI(UNITAI_ATTACK_AIR);
	REGISTER_UNITAI(UNITAI_DEFENSE_AIR);
	REGISTER_UNITAI(UNITAI_CARRIER_AIR);
	REGISTER_UNITAI(UNITAI_MISSILE_AIR);
	REGISTER_UNITAI(UNITAI_PARADROP);
	REGISTER_UNITAI(UNITAI_ATTACK_CITY_LEMMING);
	REGISTER_UNITAI(UNITAI_PILLAGE_COUNTER);
	REGISTER_UNITAI(UNITAI_SUBDUED_ANIMAL);
	REGISTER_UNITAI(UNITAI_HUNTER);
	REGISTER_UNITAI(UNITAI_GREAT_HUNTER);
	REGISTER_UNITAI(UNITAI_GREAT_ADMIRAL);
	REGISTER_UNITAI(UNITAI_PROPERTY_CONTROL);
	REGISTER_UNITAI(UNITAI_HEALER);
	REGISTER_UNITAI(UNITAI_PROPERTY_CONTROL_SEA);
	REGISTER_UNITAI(UNITAI_HEALER_SEA);
	REGISTER_UNITAI(UNITAI_HUNTER_ESCORT);
	REGISTER_UNITAI(UNITAI_BARB_CRIMINAL);
	REGISTER_UNITAI(UNITAI_INVESTIGATOR);
	REGISTER_UNITAI(UNITAI_INFILTRATOR);
	REGISTER_UNITAI(UNITAI_SEE_INVISIBLE);
	REGISTER_UNITAI(UNITAI_SEE_INVISIBLE_SEA);
	REGISTER_UNITAI(UNITAI_ESCORT);
}

//	AIAndy - added internal registration of supported AIScale types similar to UnitAIs but without info class
#define	REGISTER_AISCALE(x)	setInfoTypeFromString(#x,x)

void CvGlobals::registerAIScales()
{
	//	Sadly C++ doesn't have any reflection capability so need to do this explicitly
	REGISTER_AISCALE(AISCALE_NONE);
	REGISTER_AISCALE(AISCALE_CITY);
	REGISTER_AISCALE(AISCALE_AREA);
	REGISTER_AISCALE(AISCALE_PLAYER);
	REGISTER_AISCALE(AISCALE_TEAM);
}

//	AIAndy: Register game object types
#define	REGISTER_GAMEOBJECT(x)	setInfoTypeFromString(#x,x)

void CvGlobals::registerGameObjects()
{
	//	Sadly C++ doesn't have any reflection capability so need to do this explicitly
	REGISTER_GAMEOBJECT(NO_GAMEOBJECT);
	REGISTER_GAMEOBJECT(GAMEOBJECT_GAME);
	REGISTER_GAMEOBJECT(GAMEOBJECT_TEAM);
	REGISTER_GAMEOBJECT(GAMEOBJECT_PLAYER);
	REGISTER_GAMEOBJECT(GAMEOBJECT_CITY);
	REGISTER_GAMEOBJECT(GAMEOBJECT_UNIT);
	REGISTER_GAMEOBJECT(GAMEOBJECT_PLOT);
}

//	AIAndy: Register game object types
#define	REGISTER_GOM(x)	setInfoTypeFromString(#x,x)

void CvGlobals::registerGOMs()
{
	//	Sadly C++ doesn't have any reflection capability so need to do this explicitly
	REGISTER_GOM(NO_GOM);
	REGISTER_GOM(GOM_BUILDING);
	REGISTER_GOM(GOM_PROMOTION);
	REGISTER_GOM(GOM_TRAIT);
	REGISTER_GOM(GOM_FEATURE);
	REGISTER_GOM(GOM_OPTION);
	REGISTER_GOM(GOM_TERRAIN);
	REGISTER_GOM(GOM_GAMESPEED);
	REGISTER_GOM(GOM_ROUTE);
	REGISTER_GOM(GOM_BONUS);
	REGISTER_GOM(GOM_UNITTYPE);
	REGISTER_GOM(GOM_TECH);
	REGISTER_GOM(GOM_CIVIC);
	REGISTER_GOM(GOM_RELIGION);
	REGISTER_GOM(GOM_CORPORATION);
	REGISTER_GOM(GOM_IMPROVEMENT);
	REGISTER_GOM(GOM_UNITCOMBAT);
	REGISTER_GOM(GOM_HANDICAP);
}

//	AIAndy: Register game object relation types
#define	REGISTER_RELATION(x)	setInfoTypeFromString(#x,x)

void CvGlobals::registerRelations()
{
	//	Sadly C++ doesn't have any reflection capability so need to do this explicitly
	REGISTER_RELATION(NO_RELATION);
	REGISTER_RELATION(RELATION_ASSOCIATED);
	REGISTER_RELATION(RELATION_TRADE);
	REGISTER_RELATION(RELATION_NEAR);
	REGISTER_RELATION(RELATION_SAME_PLOT);
	REGISTER_RELATION(RELATION_WORKING);
}

//	AIAndy: Register game object attribute types
#define	REGISTER_ATTRIBUTE(x)	setInfoTypeFromString(#x,x)

void CvGlobals::registerAttributes()
{
	//	Sadly C++ doesn't have any reflection capability so need to do this explicitly
	REGISTER_ATTRIBUTE(NO_ATTRIBUTE);
	REGISTER_ATTRIBUTE(ATTRIBUTE_POPULATION);
	REGISTER_ATTRIBUTE(ATTRIBUTE_HEALTH);
	REGISTER_ATTRIBUTE(ATTRIBUTE_HAPPINESS);
	REGISTER_ATTRIBUTE(ATTRIBUTE_PLAYERS);
	REGISTER_ATTRIBUTE(ATTRIBUTE_TEAMS);
}

//	AIAndy: Register game object tag types
#define	REGISTER_TAG(x)	setInfoTypeFromString(#x,x)

void CvGlobals::registerTags()
{
	//	Sadly C++ doesn't have any reflection capability so need to do this explicitly
	REGISTER_TAG(NO_TAG);
	REGISTER_TAG(TAG_ONLY_DEFENSIVE);
	REGISTER_TAG(TAG_SPY);
	REGISTER_TAG(TAG_FIRST_STRIKE_IMMUNE);
	REGISTER_TAG(TAG_NO_DEFENSIVE_BONUS);
	REGISTER_TAG(TAG_CAN_MOVE_IMPASSABLE);
	REGISTER_TAG(TAG_HIDDEN_NATIONALITY);
	REGISTER_TAG(TAG_BLITZ);
	REGISTER_TAG(TAG_ALWAYS_HEAL);
	REGISTER_TAG(TAG_ENEMY_ROUTE);
	REGISTER_TAG(TAG_WATER);
	REGISTER_TAG(TAG_FRESH_WATER);
	REGISTER_TAG(TAG_PEAK);
	REGISTER_TAG(TAG_HILL);
	REGISTER_TAG(TAG_FLATLAND);
	REGISTER_TAG(TAG_OWNED);
	REGISTER_TAG(TAG_CITY);
	REGISTER_TAG(TAG_ANARCHY);
	REGISTER_TAG(TAG_COASTAL);
}

//	AIAndy: Register property source types
#define	REGISTER_PROPERTYSOURCE(x)	setInfoTypeFromString(#x,x)

void CvGlobals::registerPropertySources()
{
	//	Sadly C++ doesn't have any reflection capability so need to do this explicitly
	REGISTER_PROPERTYSOURCE(NO_PROPERTYSOURCE);
	REGISTER_PROPERTYSOURCE(PROPERTYSOURCE_CONSTANT);
	REGISTER_PROPERTYSOURCE(PROPERTYSOURCE_CONSTANT_LIMITED);
	REGISTER_PROPERTYSOURCE(PROPERTYSOURCE_DECAY);
	REGISTER_PROPERTYSOURCE(PROPERTYSOURCE_ATTRIBUTE_CONSTANT);
}

//	AIAndy: Register property interaction types
#define	REGISTER_PROPERTYINTERACTION(x)	setInfoTypeFromString(#x,x)

void CvGlobals::registerPropertyInteractions()
{
	//	Sadly C++ doesn't have any reflection capability so need to do this explicitly
	REGISTER_PROPERTYINTERACTION(NO_PROPERTYINTERACTION);
	REGISTER_PROPERTYINTERACTION(PROPERTYINTERACTION_CONVERT_CONSTANT);
	REGISTER_PROPERTYINTERACTION(PROPERTYINTERACTION_INHIBITED_GROWTH);
	REGISTER_PROPERTYINTERACTION(PROPERTYINTERACTION_CONVERT_PERCENT);
}

//	AIAndy: Register property propagator types
#define	REGISTER_PROPERTYPROPAGATOR(x)	setInfoTypeFromString(#x,x)

void CvGlobals::registerPropertyPropagators()
{
	//	Sadly C++ doesn't have any reflection capability so need to do this explicitly
	REGISTER_PROPERTYPROPAGATOR(NO_PROPERTYPROPAGATOR);
	REGISTER_PROPERTYPROPAGATOR(PROPERTYPROPAGATOR_SPREAD);
	REGISTER_PROPERTYPROPAGATOR(PROPERTYPROPAGATOR_GATHER);
	REGISTER_PROPERTYPROPAGATOR(PROPERTYPROPAGATOR_DIFFUSE);
}

//	AlbertS2: Register mission types
void CvGlobals::registerMission(const char* szType, int enumVal)
{
	FAssert(m_paMissionInfo.size() == enumVal);

	CvMissionInfo* entry = new CvMissionInfo(szType);

	m_paMissionInfo.push_back(entry);
	setInfoTypeFromString(szType, enumVal);
}

#define	REGISTER_MISSION(x)	registerMission(#x,x)

void CvGlobals::registerMissions()
{
	//	Sadly C++ doesn't have any reflection capability so need to do this explicitly
	REGISTER_MISSION(MISSION_MOVE_TO);
	REGISTER_MISSION(MISSION_ROUTE_TO);
	REGISTER_MISSION(MISSION_MOVE_TO_UNIT);
	REGISTER_MISSION(MISSION_SKIP);
	REGISTER_MISSION(MISSION_SLEEP);
	REGISTER_MISSION(MISSION_FORTIFY);
	REGISTER_MISSION(MISSION_PLUNDER);
	REGISTER_MISSION(MISSION_AIRPATROL);
	REGISTER_MISSION(MISSION_SEAPATROL);
	REGISTER_MISSION(MISSION_HEAL);
	REGISTER_MISSION(MISSION_SENTRY);
	REGISTER_MISSION(MISSION_AIRLIFT);
	REGISTER_MISSION(MISSION_NUKE);
	REGISTER_MISSION(MISSION_RECON);
	REGISTER_MISSION(MISSION_PARADROP);
	REGISTER_MISSION(MISSION_AIRBOMB);
	REGISTER_MISSION(MISSION_RANGE_ATTACK);
	REGISTER_MISSION(MISSION_BOMBARD);
	REGISTER_MISSION(MISSION_PILLAGE);
	REGISTER_MISSION(MISSION_SABOTAGE);
	REGISTER_MISSION(MISSION_DESTROY);
	REGISTER_MISSION(MISSION_STEAL_PLANS);
	REGISTER_MISSION(MISSION_FOUND);
	REGISTER_MISSION(MISSION_SPREAD);
	REGISTER_MISSION(MISSION_SPREAD_CORPORATION);
	REGISTER_MISSION(MISSION_JOIN);
	REGISTER_MISSION(MISSION_CONSTRUCT);
	REGISTER_MISSION(MISSION_DISCOVER);
	REGISTER_MISSION(MISSION_HURRY);
	REGISTER_MISSION(MISSION_TRADE);
	REGISTER_MISSION(MISSION_GREAT_WORK);
	REGISTER_MISSION(MISSION_INFILTRATE);
	REGISTER_MISSION(MISSION_GOLDEN_AGE);
	REGISTER_MISSION(MISSION_BUILD);
	REGISTER_MISSION(MISSION_LEAD);
	REGISTER_MISSION(MISSION_ESPIONAGE);
	REGISTER_MISSION(MISSION_DIE_ANIMATION);
	REGISTER_MISSION(MISSION_BEGIN_COMBAT);
	REGISTER_MISSION(MISSION_END_COMBAT);
	REGISTER_MISSION(MISSION_AIRSTRIKE);
	REGISTER_MISSION(MISSION_SURRENDER);
	REGISTER_MISSION(MISSION_CAPTURED);
	REGISTER_MISSION(MISSION_IDLE);
	REGISTER_MISSION(MISSION_DIE);
	REGISTER_MISSION(MISSION_DAMAGE);
	REGISTER_MISSION(MISSION_MULTI_SELECT);
	REGISTER_MISSION(MISSION_MULTI_DESELECT);
	REGISTER_MISSION(MISSION_AIRBOMB1);
	REGISTER_MISSION(MISSION_AIRBOMB2);
	REGISTER_MISSION(MISSION_AIRBOMB3);
	REGISTER_MISSION(MISSION_AIRBOMB4);
	REGISTER_MISSION(MISSION_AIRBOMB5);
	REGISTER_MISSION(MISSION_RBOMBARD);
	REGISTER_MISSION(MISSION_FENGAGE);
	// BUG - Sentry Actions - start
#ifdef _MOD_SENTRY
	REGISTER_MISSION(MISSION_MOVE_TO_SENTRY);
	REGISTER_MISSION(MISSION_SENTRY_WHILE_HEAL);
	REGISTER_MISSION(MISSION_SENTRY_NAVAL_UNITS);
	REGISTER_MISSION(MISSION_SENTRY_LAND_UNITS);
#endif
	// BUG - Sentry Actions - end

	REGISTER_MISSION(MISSION_INQUISITION);
	REGISTER_MISSION(MISSION_CLAIM_TERRITORY);
	REGISTER_MISSION(MISSION_HURRY_FOOD);
	REGISTER_MISSION(MISSION_ESPIONAGE_SLEEP);
	REGISTER_MISSION(MISSION_GREAT_COMMANDER);
	REGISTER_MISSION(MISSION_SHADOW);
	REGISTER_MISSION(MISSION_WAIT_FOR_TECH);
	REGISTER_MISSION(MISSION_GOTO);
	REGISTER_MISSION(MISSION_PRETARGET_NUKE);
	REGISTER_MISSION(MISSION_BUTCHER);
	REGISTER_MISSION(MISSION_DIPLOMAT_ASSIMULATE_IND_PEOPLE);
	REGISTER_MISSION(MISSION_DIPLOMAT_PRAISE_IND_PEOPLE);
	REGISTER_MISSION(MISSION_DIPLOMAT_SPEAK_TO_BARBARIAN_LEADERS);
	REGISTER_MISSION(MISSION_DIPLOMAT_SPREAD_RELIGION);
	REGISTER_MISSION(MISSION_LAWYER_REMOVE_CORPORATIONS);
	REGISTER_MISSION(MISSION_JOIN_CITY_POPULATION);
	REGISTER_MISSION(MISSION_CURE);
	REGISTER_MISSION(MISSION_ESTABLISH);
	REGISTER_MISSION(MISSION_ESCAPE);
	REGISTER_MISSION(MISSION_BUILDUP);
	REGISTER_MISSION(MISSION_AUTO_BUILDUP);
	REGISTER_MISSION(MISSION_HEAL_BUILDUP);
	REGISTER_MISSION(MISSION_AMBUSH);
	REGISTER_MISSION(MISSION_ASSASSINATE);
	REGISTER_MISSION(MISSION_ENTERTAIN_CITY);
	REGISTER_MISSION(MISSION_HURRY_PRODUCTION_CARAVAN);
	REGISTER_MISSION(MISSION_CAPTIVE_UPGRADE_TO_SETTLER);
	REGISTER_MISSION(MISSION_CAPTIVE_UPGRADE_TO_GATHERER);
	REGISTER_MISSION(MISSION_CAPTIVE_UPGRADE_TO_WORKER);
	REGISTER_MISSION(MISSION_CAPTIVE_UPGRADE_TO_IMMIGRANT);
	REGISTER_MISSION(MISSION_CAPTIVE_UPGRADE_TO_STONE_THROWER);
	REGISTER_MISSION(MISSION_CAPTIVE_UPGRADE_TO_ARCHER);
	REGISTER_MISSION(MISSION_CAPTIVE_UPGRADE_TO_AXEMAN);
	REGISTER_MISSION(MISSION_CAPTIVE_UPGRADE_TO_SPEARMAN);
	REGISTER_MISSION(MISSION_CAPTIVE_UPGRADE_TO_NEANDERTHAL_WARRIOR);
	REGISTER_MISSION(MISSION_SELL_CAPTIVE);
	REGISTER_MISSION(MISSION_FREE_CAPTIVE);
	REGISTER_MISSION(MISSION_JOIN_CITY_FREED_SLAVE);
	REGISTER_MISSION(MISSION_RECORD_TALE);
	REGISTER_MISSION(MISSION_RECORD_TALE_ORAL);
	REGISTER_MISSION(MISSION_RECORD_TALE_WRITTEN);
	REGISTER_MISSION(MISSION_ANIMAL_COMBAT);
	REGISTER_MISSION(MISSION_ANIMAL_STUDY);
	REGISTER_MISSION(MISSION_ANIMAL_SACRIFICE);
	REGISTER_MISSION(MISSION_BUILD_DOMESTICATED_HERD);
	REGISTER_MISSION(MISSION_CAPTIVE_UPGRADE_TO_NEANDERTHAL_GATHERER);
	REGISTER_MISSION(MISSION_CAPTIVE_UPGRADE_TO_NEANDERTHAL_TRACKER);
}

CvInfoBase& CvGlobals::getAttitudeInfo(AttitudeTypes eAttitudeNum) const
{
	FAssert(eAttitudeNum >= 0);
	FAssert(eAttitudeNum < NUM_ATTITUDE_TYPES);
	return *(m_paAttitudeInfos[eAttitudeNum]);
}


CvInfoBase& CvGlobals::getMemoryInfo(MemoryTypes eMemoryNum) const
{
	FAssert(eMemoryNum >= 0);
	FAssert(eMemoryNum < NUM_MEMORY_TYPES);
	return *(m_paMemoryInfos[eMemoryNum]);
}


int CvGlobals::getNumGameOptionInfos() const
{
	return (int)m_paGameOptionInfos.size();
}

CvGameOptionInfo& CvGlobals::getGameOptionInfo(GameOptionTypes eGameOptionNum)
{
	FAssert(eGameOptionNum >= 0);
	FAssert(eGameOptionNum < GC.getNumGameOptionInfos());
	return *(m_paGameOptionInfos[eGameOptionNum]);
}

int CvGlobals::getNumMPOptionInfos() const
{
	return (int)m_paMPOptionInfos.size();
}

CvMPOptionInfo& CvGlobals::getMPOptionInfo(MultiplayerOptionTypes eMPOptionNum)
{
	FAssert(eMPOptionNum >= 0);
	FAssert(eMPOptionNum < GC.getNumMPOptionInfos());
	return *(m_paMPOptionInfos[eMPOptionNum]);
}

int CvGlobals::getNumForceControlInfos() const
{
	return (int)m_paForceControlInfos.size();
}

CvForceControlInfo& CvGlobals::getForceControlInfo(ForceControlTypes eForceControlNum) const
{
	FAssert(eForceControlNum >= 0);
	FAssert(eForceControlNum < GC.getNumForceControlInfos());
	return *(m_paForceControlInfos[eForceControlNum]);
}

CvPlayerOptionInfo& CvGlobals::getPlayerOptionInfo(PlayerOptionTypes ePlayerOptionNum)
{
	FAssert(ePlayerOptionNum >= 0);
	FAssert(ePlayerOptionNum < NUM_PLAYEROPTION_TYPES);
	return *(m_paPlayerOptionInfos[ePlayerOptionNum]);
}

CvGraphicOptionInfo& CvGlobals::getGraphicOptionInfo(GraphicOptionTypes eGraphicOptionNum)
{
	FAssert(eGraphicOptionNum >= 0);
	FAssert(eGraphicOptionNum < NUM_GRAPHICOPTION_TYPES);
	return *(m_paGraphicOptionInfos[eGraphicOptionNum]);
}

CvYieldInfo& CvGlobals::getYieldInfo(YieldTypes eYieldNum) const
{
	FAssert(eYieldNum > -1);
	FAssert(eYieldNum < NUM_YIELD_TYPES);
	return *(m_paYieldInfo[eYieldNum]);
}

CvCommerceInfo& CvGlobals::getCommerceInfo(CommerceTypes eCommerceNum) const
{
	FAssert(eCommerceNum > -1);
	FAssert(eCommerceNum < NUM_COMMERCE_TYPES);
	return *(m_paCommerceInfo[eCommerceNum]);
}

int CvGlobals::getNumRouteInfos()
{
	return (int)m_paRouteInfo.size();
}

CvRouteInfo& CvGlobals::getRouteInfo(RouteTypes eRouteNum) const
{
	FAssert(eRouteNum > -1);
	FAssert(eRouteNum < GC.getNumRouteInfos());
	return *(m_paRouteInfo[eRouteNum]);
}

int CvGlobals::getNumImprovementInfos()
{
	return (int)m_paImprovementInfo.size();
}

CvImprovementInfo& CvGlobals::getImprovementInfo(ImprovementTypes eImprovementNum)
{
	FAssert(eImprovementNum > -1);
	FAssert(eImprovementNum < GC.getNumImprovementInfos());
	return *(m_paImprovementInfo[eImprovementNum]);
}

int CvGlobals::getNumGoodyInfos() const
{
	return (int)m_paGoodyInfo.size();
}

CvGoodyInfo& CvGlobals::getGoodyInfo(GoodyTypes eGoodyNum) const
{
	FAssert(eGoodyNum > -1);
	FAssert(eGoodyNum < GC.getNumGoodyInfos());
	return *(m_paGoodyInfo[eGoodyNum]);
}

int CvGlobals::getNumBuildInfos() const
{
	return (int)m_paBuildInfo.size();
}

CvBuildInfo& CvGlobals::getBuildInfo(BuildTypes eBuildNum)
{
	FAssert(eBuildNum > -1);
	FAssert(eBuildNum < GC.getNumBuildInfos());
	return *(m_paBuildInfo[eBuildNum]);
}

int CvGlobals::getNumHandicapInfos()
{
	return (int)m_paHandicapInfo.size();
}

CvHandicapInfo& CvGlobals::getHandicapInfo(HandicapTypes eHandicapNum)
{
	FAssert(eHandicapNum > -1);
	FAssert(eHandicapNum < GC.getNumHandicapInfos());
	return *(m_paHandicapInfo[eHandicapNum]);
}

int CvGlobals::getNumGameSpeedInfos()
{
	return (int)m_paGameSpeedInfo.size();
}

CvGameSpeedInfo& CvGlobals::getGameSpeedInfo(GameSpeedTypes eGameSpeedNum)
{
	FAssert(eGameSpeedNum > -1);
	FAssert(eGameSpeedNum < GC.getNumGameSpeedInfos());
	return *(m_paGameSpeedInfo[eGameSpeedNum]);
}

int CvGlobals::getNumTurnTimerInfos()
{
	return (int)m_paTurnTimerInfo.size();
}

CvTurnTimerInfo& CvGlobals::getTurnTimerInfo(TurnTimerTypes eTurnTimerNum)
{
	FAssert(eTurnTimerNum > -1);
	FAssert(eTurnTimerNum < GC.getNumTurnTimerInfos());
	return *(m_paTurnTimerInfo[eTurnTimerNum]);
}

int CvGlobals::getNumProcessInfos() const
{
	return (int)m_paProcessInfo.size();
}

CvProcessInfo& CvGlobals::getProcessInfo(ProcessTypes e) const
{
	FAssert(e > -1);
	FAssert(e < GC.getNumProcessInfos());
	return *(m_paProcessInfo[e]);
}

int CvGlobals::getNumVoteInfos() const
{
	return (int)m_paVoteInfo.size();
}

CvVoteInfo& CvGlobals::getVoteInfo(VoteTypes e) const
{
	FAssert(e > -1);
	FAssert(e < GC.getNumVoteInfos());
	return *(m_paVoteInfo[e]);
}

int CvGlobals::getNumProjectInfos() const
{
	return (int)m_paProjectInfo.size();
}

CvProjectInfo& CvGlobals::getProjectInfo(ProjectTypes e) const
{
	FAssert(e > -1);
	FAssert(e < GC.getNumProjectInfos());
	return *(m_paProjectInfo[e]);
}

int CvGlobals::getNumBuildingInfos() const
{
	return (int)m_paBuildingInfo.size();
}

CvBuildingInfo& CvGlobals::getBuildingInfo(BuildingTypes eBuildingNum) const
{
	FAssert(eBuildingNum > -1);
	FAssert(eBuildingNum < GC.getNumBuildingInfos());
	return *(m_paBuildingInfo[eBuildingNum]);
}

int CvGlobals::getNumSpecialBuildingInfos() const
{
	return (int)m_paSpecialBuildingInfo.size();
}

CvSpecialBuildingInfo& CvGlobals::getSpecialBuildingInfo(SpecialBuildingTypes eSpecialBuildingNum) const
{
	FAssert(eSpecialBuildingNum > -1);
	FAssert(eSpecialBuildingNum < GC.getNumSpecialBuildingInfos());
	return *(m_paSpecialBuildingInfo[eSpecialBuildingNum]);
}

int CvGlobals::getNumActionInfos()
{
	return (int)m_paActionInfo.size();
}

CvActionInfo& CvGlobals::getActionInfo(int i)
{
	FAssertMsg(i < getNumActionInfos(), "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	return *(m_paActionInfo[i]);
}

CvMissionInfo& CvGlobals::getMissionInfo(MissionTypes eMissionNum)
{
	FAssert(eMissionNum > -1);
	FAssert(eMissionNum < NUM_MISSION_TYPES);
	return *(m_paMissionInfo[eMissionNum]);
}

CvControlInfo& CvGlobals::getControlInfo(ControlTypes eControlNum) const
{
	FAssert(eControlNum > -1);
	FAssert(eControlNum < NUM_CONTROL_TYPES);
	FAssert(!m_paControlInfo.empty());
	return *(m_paControlInfo[eControlNum]);
}

CvCommandInfo& CvGlobals::getCommandInfo(CommandTypes eCommandNum) const
{
	FAssert(eCommandNum > -1);
	FAssert(eCommandNum < NUM_COMMAND_TYPES);
	return *(m_paCommandInfo[eCommandNum]);
}

int CvGlobals::getNumAutomateInfos() const
{
	return (int)m_paAutomateInfo.size();
}

CvAutomateInfo& CvGlobals::getAutomateInfo(int iAutomateNum) const
{
	FAssertMsg(iAutomateNum < getNumAutomateInfos(), "Index out of bounds");
	FAssertMsg(iAutomateNum > -1, "Index out of bounds");
	return *(m_paAutomateInfo[iAutomateNum]);
}

int CvGlobals::getNumPromotionInfos() const
{
	return (int)m_paPromotionInfo.size();
}

CvPromotionInfo& CvGlobals::getPromotionInfo(PromotionTypes ePromotionNum) const
{
	FAssert(ePromotionNum > -1);
	FAssert(ePromotionNum < GC.getNumPromotionInfos());
	return *(m_paPromotionInfo[ePromotionNum]);
}

PromotionTypes CvGlobals::findPromotion(PromotionPredicateFn predicateFn) const
{
	for (int idx = 0; idx < static_cast<int>(m_paPromotionInfo.size()); ++idx)
	{
		if (predicateFn(m_paPromotionInfo[idx], static_cast<PromotionTypes>(idx)))
		{
			return static_cast<PromotionTypes>(idx);
		}
	}
	return static_cast<PromotionTypes>(-1);
}

int CvGlobals::getNumTechInfos() const
{
	return (int)m_paTechInfo.size();
}

CvTechInfo& CvGlobals::getTechInfo(TechTypes eTechNum) const
{
	FAssert(eTechNum > -1);
	FAssert(eTechNum < GC.getNumTechInfos());
	return *(m_paTechInfo[eTechNum]);
}

int CvGlobals::getNumReligionInfos() const
{
	return (int)m_paReligionInfo.size();
}

CvReligionInfo& CvGlobals::getReligionInfo(ReligionTypes eReligionNum) const
{
	FAssert(eReligionNum > -1);
	FAssert(eReligionNum < GC.getNumReligionInfos());
	return *(m_paReligionInfo[eReligionNum]);
}

int CvGlobals::getNumCorporationInfos() const
{
	return (int)m_paCorporationInfo.size();
}

CvCorporationInfo& CvGlobals::getCorporationInfo(CorporationTypes eCorporationNum) const
{
	FAssert(eCorporationNum > -1);
	FAssert(eCorporationNum < GC.getNumCorporationInfos());
	return *(m_paCorporationInfo[eCorporationNum]);
}

int CvGlobals::getNumSpecialistInfos() const
{
	return (int)m_paSpecialistInfo.size();
}

CvSpecialistInfo& CvGlobals::getSpecialistInfo(SpecialistTypes eSpecialistNum) const
{
	FAssert(eSpecialistNum > -1);
	FAssert(eSpecialistNum < GC.getNumSpecialistInfos());
	return *(m_paSpecialistInfo[eSpecialistNum]);
}

int CvGlobals::getNumCivicOptionInfos() const
{
	return (int)m_paCivicOptionInfo.size();
}

CvCivicOptionInfo& CvGlobals::getCivicOptionInfo(CivicOptionTypes eCivicOptionNum) const
{
	FAssert(eCivicOptionNum > -1);
	FAssert(eCivicOptionNum < GC.getNumCivicOptionInfos());
	return *(m_paCivicOptionInfo[eCivicOptionNum]);
}

int CvGlobals::getNumCivicInfos() const
{
	return (int)m_paCivicInfo.size();
}

CvCivicInfo& CvGlobals::getCivicInfo(CivicTypes eCivicNum) const
{
	FAssert(eCivicNum > -1);
	FAssert(eCivicNum < GC.getNumCivicInfos());
	return *(m_paCivicInfo[eCivicNum]);
}

int CvGlobals::getNumDiplomacyInfos() const
{
	return (int)m_paDiplomacyInfo.size();
}

CvDiplomacyInfo& CvGlobals::getDiplomacyInfo(int iDiplomacyNum) const
{
	FAssertMsg(iDiplomacyNum < getNumDiplomacyInfos(), "Index out of bounds");
	FAssertMsg(iDiplomacyNum > -1, "Index out of bounds");
	return *(m_paDiplomacyInfo[iDiplomacyNum]);
}

int CvGlobals::getNumEraInfos()
{
	return (int)m_aEraInfo.size();
}

CvEraInfo& CvGlobals::getEraInfo(EraTypes eEraNum)
{
	FAssert(eEraNum > -1);
	FAssert(eEraNum < GC.getNumEraInfos());
	return *(m_aEraInfo[eEraNum]);
}

int CvGlobals::getNumHurryInfos() const
{
	return (int)m_paHurryInfo.size();
}

CvHurryInfo& CvGlobals::getHurryInfo(HurryTypes eHurryNum) const
{
	FAssert(eHurryNum > -1);
	FAssert(eHurryNum < GC.getNumHurryInfos());
	return *(m_paHurryInfo[eHurryNum]);
}

int CvGlobals::getNumEmphasizeInfos() const
{
	return (int)m_paEmphasizeInfo.size();
}

CvEmphasizeInfo& CvGlobals::getEmphasizeInfo(EmphasizeTypes eEmphasizeNum) const
{
	FAssert(eEmphasizeNum > -1);
	FAssert(eEmphasizeNum < GC.getNumEmphasizeInfos());
	return *(m_paEmphasizeInfo[eEmphasizeNum]);
}

int CvGlobals::getNumUpkeepInfos() const
{
	return (int)m_paUpkeepInfo.size();
}

CvUpkeepInfo& CvGlobals::getUpkeepInfo(UpkeepTypes eUpkeepNum) const
{
	FAssert(eUpkeepNum > -1);
	FAssert(eUpkeepNum < GC.getNumUpkeepInfos());
	return *(m_paUpkeepInfo[eUpkeepNum]);
}

int CvGlobals::getNumCultureLevelInfos() const
{
	return (int)m_paCultureLevelInfo.size();
}

CvCultureLevelInfo& CvGlobals::getCultureLevelInfo(CultureLevelTypes eCultureLevelNum) const
{
	FAssert(eCultureLevelNum > -1);
	FAssert(eCultureLevelNum < GC.getNumCultureLevelInfos());
	return *(m_paCultureLevelInfo[eCultureLevelNum]);
}

int CvGlobals::getNumVictoryInfos()
{
	return (int)m_paVictoryInfo.size();
}

CvVictoryInfo& CvGlobals::getVictoryInfo(VictoryTypes eVictoryNum)
{
	FAssert(eVictoryNum > -1);
	FAssert(eVictoryNum < GC.getNumVictoryInfos());
	return *(m_paVictoryInfo[eVictoryNum]);
}

int CvGlobals::getNumQuestInfos() const
{
	return (int)m_paQuestInfo.size();
}

CvQuestInfo& CvGlobals::getQuestInfo(int iIndex) const
{
	FAssert(iIndex > -1);
	FAssert(iIndex < GC.getNumQuestInfos());
	return *(m_paQuestInfo[iIndex]);
}

int CvGlobals::getNumTutorialInfos() const
{
	return (int)m_paTutorialInfo.size();
}

CvTutorialInfo& CvGlobals::getTutorialInfo(int iIndex) const
{
	FAssert(iIndex > -1);
	FAssert(iIndex < GC.getNumTutorialInfos());
	return *(m_paTutorialInfo[iIndex]);
}

int CvGlobals::getNumEventTriggerInfos() const
{
	return (int)m_paEventTriggerInfo.size();
}

CvEventTriggerInfo& CvGlobals::getEventTriggerInfo(EventTriggerTypes eEventTrigger) const
{
	FAssert(eEventTrigger > -1);
	FAssert(eEventTrigger < GC.getNumEventTriggerInfos());
	return *(m_paEventTriggerInfo[eEventTrigger]);
}

int CvGlobals::getNumEventInfos() const
{
	return (int)m_paEventInfo.size();
}

CvEventInfo& CvGlobals::getEventInfo(EventTypes eEvent) const
{
	FAssert(eEvent > -1);
	FAssert(eEvent < GC.getNumEventInfos());
	return *(m_paEventInfo[eEvent]);
}

int CvGlobals::getNumEspionageMissionInfos() const
{
	return (int)m_paEspionageMissionInfo.size();
}

CvEspionageMissionInfo& CvGlobals::getEspionageMissionInfo(EspionageMissionTypes eEspionageMissionNum) const
{
	FAssert(eEspionageMissionNum > -1);
	FAssert(eEspionageMissionNum < GC.getNumEspionageMissionInfos());
	return *(m_paEspionageMissionInfo[eEspionageMissionNum]);
}

int& CvGlobals::getNumEntityEventTypes()
{
	return m_iNumEntityEventTypes;
}

CvString*& CvGlobals::getEntityEventTypes()
{
	return m_paszEntityEventTypes;
}

CvString& CvGlobals::getEntityEventTypes(EntityEventTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumEntityEventTypes());
	return m_paszEntityEventTypes[e];
}

int& CvGlobals::getNumAnimationOperatorTypes()
{
	return m_iNumAnimationOperatorTypes;
}

CvString*& CvGlobals::getAnimationOperatorTypes()
{
	return m_paszAnimationOperatorTypes;
}

CvString& CvGlobals::getAnimationOperatorTypes(AnimationOperatorTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumAnimationOperatorTypes());
	return m_paszAnimationOperatorTypes[e];
}

CvString*& CvGlobals::getFunctionTypes()
{
	return m_paszFunctionTypes;
}

CvString& CvGlobals::getFunctionTypes(FunctionTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_FUNC_TYPES);
	return m_paszFunctionTypes[e];
}

int& CvGlobals::getNumFlavorTypes()
{
	return m_iNumFlavorTypes;
}

CvString*& CvGlobals::getFlavorTypes()
{
	return m_paszFlavorTypes;
}

CvString& CvGlobals::getFlavorTypes(FlavorTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumFlavorTypes());
	return m_paszFlavorTypes[e];
}

int& CvGlobals::getNumArtStyleTypes()
{
	return m_iNumArtStyleTypes;
}

CvString*& CvGlobals::getArtStyleTypes()
{
	return m_paszArtStyleTypes;
}

CvString& CvGlobals::getArtStyleTypes(ArtStyleTypes e)
{
	FAssert(e > -1);
	FAssert(e < GC.getNumArtStyleTypes());
	return m_paszArtStyleTypes[e];
}

int CvGlobals::getNumUnitArtStyleTypeInfos() const
{
	return (int)m_paUnitArtStyleTypeInfo.size();
}

CvUnitArtStyleTypeInfo& CvGlobals::getUnitArtStyleTypeInfo(UnitArtStyleTypes eUnitArtStyleTypeNum) const
{
	FAssert(eUnitArtStyleTypeNum > -1);
	FAssert(eUnitArtStyleTypeNum < GC.getNumUnitArtStyleTypeInfos());
	return *(m_paUnitArtStyleTypeInfo[eUnitArtStyleTypeNum]);
}

int& CvGlobals::getNumCitySizeTypes()
{
	return m_iNumCitySizeTypes;
}

CvString*& CvGlobals::getCitySizeTypes()
{
	return m_paszCitySizeTypes;
}

CvString& CvGlobals::getCitySizeTypes(int i)
{
	FAssertMsg(i < getNumCitySizeTypes(), "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	return m_paszCitySizeTypes[i];
}

CvString*& CvGlobals::getContactTypes()
{
	return m_paszContactTypes;
}

CvString& CvGlobals::getContactTypes(ContactTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_CONTACT_TYPES);
	return m_paszContactTypes[e];
}

CvString*& CvGlobals::getDiplomacyPowerTypes()
{
	return m_paszDiplomacyPowerTypes;
}

CvString& CvGlobals::getDiplomacyPowerTypes(DiplomacyPowerTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_DIPLOMACYPOWER_TYPES);
	return m_paszDiplomacyPowerTypes[e];
}

CvString*& CvGlobals::getAutomateTypes()
{
	return m_paszAutomateTypes;
}

CvString& CvGlobals::getAutomateTypes(AutomateTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_AUTOMATE_TYPES);
	return m_paszAutomateTypes[e];
}

CvString*& CvGlobals::getDirectionTypes()
{
	return m_paszDirectionTypes;
}

CvString& CvGlobals::getDirectionTypes(AutomateTypes e)
{
	FAssert(e > -1);
	FAssert(e < NUM_AUTOMATE_TYPES);
	return m_paszDirectionTypes[e];
}

int CvGlobals::getNumPropertyInfos() const
{
	return (int)m_paPropertyInfo.size();
}

CvPropertyInfo& CvGlobals::getPropertyInfo(PropertyTypes ePropertyNum) const
{
	FAssert(ePropertyNum > -1);
	FAssert(ePropertyNum < GC.getNumPropertyInfos());
	return *(m_paPropertyInfo[ePropertyNum]);
}

int CvGlobals::getNumOutcomeInfos() const
{
	return (int)m_paOutcomeInfo.size();
}

CvOutcomeInfo& CvGlobals::getOutcomeInfo(OutcomeTypes eOutcomeNum) const
{
	FAssert(eOutcomeNum > -1);
	FAssert(eOutcomeNum < GC.getNumOutcomeInfos());
	return *(m_paOutcomeInfo[eOutcomeNum]);
}

int& CvGlobals::getNumFootstepAudioTypes()
{
	return m_iNumFootstepAudioTypes;
}

CvString*& CvGlobals::getFootstepAudioTypes()
{
	return m_paszFootstepAudioTypes;
}

CvString& CvGlobals::getFootstepAudioTypes(int i)
{
	FAssertMsg(i < getNumFootstepAudioTypes(), "Index out of bounds");
	FAssertMsg(i > -1, "Index out of bounds");
	return m_paszFootstepAudioTypes[i];
}

int CvGlobals::getFootstepAudioTypeByTag(const CvString strTag) const
{
	if (strTag.GetLength() > 0)
	{
		for (int i = 0; i < m_iNumFootstepAudioTypes; i++)
		{
			if (strTag.CompareNoCase(m_paszFootstepAudioTypes[i]) == 0)
			{
				return i;
			}
		}
	}
	return -1;
}

CvString*& CvGlobals::getFootstepAudioTags()
{
	return m_paszFootstepAudioTags;
}

CvString& CvGlobals::getFootstepAudioTags(int i) const
{
	static CvString* emptyString = NULL;

	if ( emptyString == NULL )
	{
		emptyString = new CvString("");
	}
	FAssertMsg(i < GC.getNumFootstepAudioTypes(), "Index out of bounds")
	FAssertMsg(i > -1, "Index out of bounds");
	return m_paszFootstepAudioTags ? m_paszFootstepAudioTags[i] : *emptyString;
}

void CvGlobals::setCurrentXMLFile(const TCHAR* szFileName)
{
	m_szCurrentXMLFile = szFileName;
}

const CvString& CvGlobals::getCurrentXMLFile() const
{
	return m_szCurrentXMLFile;
}

void CvGlobals::cacheEnumGlobals()
{
#define CACHE_ENUM_GLOBAL_DEFINE(dataType, VAR) \
	m_##VAR = getDefineINT(#VAR);
	DO_FOR_EACH_ENUM_GLOBAL_DEFINE(CACHE_ENUM_GLOBAL_DEFINE)
}

void CvGlobals::cacheGlobals()
{
	OutputDebugString("Caching Globals: Start/n");

	strcpy(gVersionString, getDefineSTRING("C2C_VERSION"));

#define CACHE_INT_GLOBAL_DEFINE(dataType, VAR) \
	m_##VAR = getDefineINT(#VAR);
	DO_FOR_EACH_INT_GLOBAL_DEFINE(CACHE_INT_GLOBAL_DEFINE)
	DO_FOR_EACH_BOOL_GLOBAL_DEFINE(CACHE_INT_GLOBAL_DEFINE)

#define CACHE_FLOAT_GLOBAL_DEFINE(dataType, VAR) \
	m_##VAR = getDefineFLOAT(#VAR);
	DO_FOR_EACH_FLOAT_GLOBAL_DEFINE(CACHE_FLOAT_GLOBAL_DEFINE)

	m_fPLOT_SIZE = getDefineFLOAT("PLOT_SIZE");
/************************************************************************************************/
/* BETTER_BTS_AI_MOD                      02/21/10                                jdog5000      */
/*                                                                                              */
/* Efficiency, Options                                                                          */
/************************************************************************************************/
// BBAI Options
	m_bBBAI_AIR_COMBAT = !(getDefineINT("BBAI_AIR_COMBAT") == 0);
	m_bBBAI_HUMAN_VASSAL_WAR_BUILD = !(getDefineINT("BBAI_HUMAN_VASSAL_WAR_BUILD") == 0);
	m_bBBAI_HUMAN_AS_VASSAL_OPTION = !(getDefineINT("BBAI_HUMAN_AS_VASSAL_OPTION") == 0);

// Tech Diffusion
	m_bTECH_DIFFUSION_ENABLE = !(getDefineINT("TECH_DIFFUSION_ENABLE") == 0);
/************************************************************************************************/
/* BETTER_BTS_AI_MOD                       END                                                  */
/************************************************************************************************/

	m_bXMLLogging = getDefineINT("XML_LOGGING_ENABLED");
	
	m_bViewportsEnabled = (getDefineINT("ENABLE_VIEWPORTS") != 0);
	m_iViewportFocusBorder = GC.getDefineINT("VIEWPORT_FOCUS_BORDER");
	m_iViewportSizeX = GC.getDefineINT("VIEWPORT_SIZE_X");
	m_iViewportSizeY = GC.getDefineINT("VIEWPORT_SIZE_Y");

	m_szAlternateProfilSampleName = getDefineSTRING("PROFILER_ALTERNATE_SAMPLE_SET_SOURCE");
	if ( m_szAlternateProfilSampleName == NULL )
	{
		m_szAlternateProfilSampleName = "";
	}

	OutputDebugString("Caching Globals: End/n");
}

/************************************************************************************************/
/* MOD COMPONENT CONTROL                   08/02/07                            MRGENIE          */
/*                                                                                              */
/* Return true/false from                                                                       */
/************************************************************************************************/
bool CvGlobals::getDefineBOOL( const char * szName ) const
{
	bool bReturn = false;
	bool success = GC.getDefinesVarSystem()->GetValue( szName, bReturn );
	//FAssertMsg( success, szName );
	return bReturn;
}
/************************************************************************************************/
/* MOD COMPONENT CONTROL                   END                                                  */
/************************************************************************************************/

/************************************************************************************************/
/* BETTER_BTS_AI_MOD                      02/21/10                                jdog5000      */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
int CvGlobals::getDefineINT( const char * szName, const int iDefault ) const
{
	int iReturn = 0;

	if( GC.getDefinesVarSystem()->GetValue( szName, iReturn ) )
	{
		return iReturn;
	}

	return iDefault;
}
/************************************************************************************************/
/* BETTER_BTS_AI_MOD                       END                                                  */
/************************************************************************************************/


int CvGlobals::getDefineINT( const char * szName ) const
{
	int iReturn = 0;
	bool success = GC.getDefinesVarSystem()->GetValue( szName, iReturn );
	//FAssertMsg( success, szName );
	return iReturn;
}

float CvGlobals::getDefineFLOAT( const char * szName ) const
{
	float fReturn = 0;
	bool success = GC.getDefinesVarSystem()->GetValue( szName, fReturn );
	//FAssertMsg( success, szName );
	return fReturn;
}

const char * CvGlobals::getDefineSTRING( const char * szName ) const
{
	const char * szReturn = NULL;
	bool success = GC.getDefinesVarSystem()->GetValue( szName, szReturn );
	//FAssertMsg( success, szName );
	return szReturn;
}
/************************************************************************************************/
/* Afforess	                  Start		 08/18/10                                               */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
void CvGlobals::setDefineINT( const char * szName, int iValue, bool bUpdate )
{
	if (getDefineINT(szName) != iValue)
	{
		if (bUpdate)
			CvMessageControl::getInstance().sendGlobalDefineUpdate(szName, iValue, -1.0f, "");
		else
			GC.getDefinesVarSystem()->SetValue( szName, iValue );
		cacheEnumGlobals();
		cacheGlobals();
	}
}

void CvGlobals::setDefineFLOAT( const char * szName, float fValue, bool bUpdate )
{
	if (getDefineFLOAT(szName) != fValue)
	{
		if (bUpdate)
			CvMessageControl::getInstance().sendGlobalDefineUpdate(szName, -1, fValue, "");
		else
			GC.getDefinesVarSystem()->SetValue( szName, fValue );
		cacheGlobals();
	}
}

void CvGlobals::setDefineSTRING( const char * szName, const char * szValue, bool bUpdate )
{
	if (getDefineSTRING(szName) != szValue)
	{
		if (bUpdate)
			CvMessageControl::getInstance().sendGlobalDefineUpdate(szName, -1, -1.0f, szValue);
		else
			GC.getDefinesVarSystem()->SetValue( szName, szValue );
		cacheGlobals(); // TO DO : we should not cache all globals at each single set
	}
}
/************************************************************************************************/
/* Afforess	                     END                                                            */
/************************************************************************************************/

float CvGlobals::getPLOT_SIZE()
{
	CvMapExternal& kMap = GC.getMapExternal();
	kMap.mapCoordinates(true);

	return m_fPLOT_SIZE;
}

void CvGlobals::setDLLProfiler(FProfiler* prof)
{
	m_Profiler = prof;
}

FProfiler* CvGlobals::getDLLProfiler() const
{
	return m_Profiler;
}

void CvGlobals::enableDLLProfiler(bool bEnable)
{
	m_bDLLProfiler = bEnable;

#ifdef USE_INTERNAL_PROFILER
	if ( bEnable )
	{
		g_bTraceBackgroundThreads = getDefineBOOL("ENABLE_BACKGROUND_PROFILING");
	}
#endif
}

bool CvGlobals::isDLLProfilerEnabled() const
{
	return m_bDLLProfiler;
}

const char* CvGlobals::alternateProfileSampleName() const
{
	return m_szAlternateProfilSampleName;
}

bool CvGlobals::readBuildingInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paBuildingInfo, "CvBuildingInfo");
}

void CvGlobals::writeBuildingInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paBuildingInfo);
}

bool CvGlobals::readTechInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paTechInfo, "CvTechInfo");
}

void CvGlobals::writeTechInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paTechInfo);
}

bool CvGlobals::readUnitInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paUnitInfo, "CvUnitInfo");
}

void CvGlobals::writeUnitInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paUnitInfo);
}

bool CvGlobals::readLeaderHeadInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paLeaderHeadInfo, "CvLeaderHeadInfo");
}

void CvGlobals::writeLeaderHeadInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paLeaderHeadInfo);
}

bool CvGlobals::readCivilizationInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paCivilizationInfo, "CvCivilizationInfo");
}

void CvGlobals::writeCivilizationInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paCivilizationInfo);
}

bool CvGlobals::readPromotionInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paPromotionInfo, "CvPromotionInfo");
}

void CvGlobals::writePromotionInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paPromotionInfo);
}

bool CvGlobals::readDiplomacyInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paDiplomacyInfo, "CvDiplomacyInfo");
}

void CvGlobals::writeDiplomacyInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paDiplomacyInfo);
}

bool CvGlobals::readCivicInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paCivicInfo, "CvCivicInfo");
}

void CvGlobals::writeCivicInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paCivicInfo);
}

bool CvGlobals::readHandicapInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paHandicapInfo, "CvHandicapInfo");
}

void CvGlobals::writeHandicapInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paHandicapInfo);
}

bool CvGlobals::readBonusInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paBonusInfo, "CvBonusInfo");
}

void CvGlobals::writeBonusInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paBonusInfo);
}

bool CvGlobals::readImprovementInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paImprovementInfo, "CvImprovementInfo");
}

void CvGlobals::writeImprovementInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paImprovementInfo);
}

bool CvGlobals::readEventInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paEventInfo, "CvEventInfo");
}

void CvGlobals::writeEventInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paEventInfo);
}

bool CvGlobals::readEventTriggerInfoArray(FDataStreamBase* pStream)
{
	return readInfoArray(pStream, m_paEventTriggerInfo, "CvEventTriggerInfo");
}

void CvGlobals::writeEventTriggerInfoArray(FDataStreamBase* pStream)
{
	writeInfoArray(pStream, m_paEventTriggerInfo);
}


//
// Global Types Hash Map
//

int CvGlobals::getTypesEnum(const char* szType) const
{
	FAssertMsg(szType, "null type string");
	TypesMap::const_iterator it = m_typesMap.find(szType);
	if (it!=m_typesMap.end())
	{
		return it->second;
	}

	FAssertMsg(strcmp(szType, "NONE")==0 || strcmp(szType, "")==0, CvString::format("type %s not found", szType).c_str());
	return -1;
}

void CvGlobals::setTypesEnum(const char* szType, int iEnum)
{
	FAssertMsg(szType, "null type string");
	FAssertMsg(m_typesMap.find(szType)==m_typesMap.end(), "types entry already exists");
	m_typesMap[szType] = iEnum;
}


void CvGlobals::deleteInfoArrays()
{
	deleteInfoArray(m_paBuildingInfo);
	deleteInfoArray(m_paSpecialBuildingInfo);

	deleteInfoArray(m_paLeaderHeadInfo);
	deleteInfoArray(m_paTraitInfo);
	deleteInfoArray(m_paCivilizationInfo);
	deleteInfoArray(m_paUnitArtStyleTypeInfo);

	deleteInfoArray(m_paVoteSourceInfo);
	deleteInfoArray(m_paHints);
	deleteInfoArray(m_paMainMenus);
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 11/01/07                            MRGENIE          */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
	// MLF loading
	m_paModLoadControlVector.clear();
	deleteInfoArray(m_paModLoadControls);
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 END                                                  */
/************************************************************************************************/
	deleteInfoArray(m_paGoodyInfo);
	deleteInfoArray(m_paHandicapInfo);
	deleteInfoArray(m_paGameSpeedInfo);
	deleteInfoArray(m_paTurnTimerInfo);
	deleteInfoArray(m_paVictoryInfo);
	deleteInfoArray(m_paHurryInfo);
	deleteInfoArray(m_paWorldInfo);
	deleteInfoArray(m_paSeaLevelInfo);
	deleteInfoArray(m_paClimateInfo);
	deleteInfoArray(m_paProcessInfo);
	deleteInfoArray(m_paVoteInfo);
	deleteInfoArray(m_paProjectInfo);
	deleteInfoArray(m_paReligionInfo);
	deleteInfoArray(m_paCorporationInfo);
	deleteInfoArray(m_paCommerceInfo);
	deleteInfoArray(m_paEmphasizeInfo);
	deleteInfoArray(m_paUpkeepInfo);
	deleteInfoArray(m_paCultureLevelInfo);

	deleteInfoArray(m_paColorInfo);
	deleteInfoArray(m_paPlayerColorInfo);
	deleteInfoArray(m_paInterfaceModeInfo);
	deleteInfoArray(m_paAdvisorInfo);
	deleteInfoArray(m_paThroneRoomCamera);
	deleteInfoArray(m_paThroneRoomInfo);
	deleteInfoArray(m_paThroneRoomStyleInfo);
	deleteInfoArray(m_paSlideShowInfo);
	deleteInfoArray(m_paSlideShowRandomInfo);
	deleteInfoArray(m_paWorldPickerInfo);
	deleteInfoArray(m_paSpaceShipInfo);

	deleteInfoArray(m_paCivicInfo);
	deleteInfoArray(m_paImprovementInfo);

	deleteInfoArray(m_paRouteInfo);
	deleteInfoArray(m_paRouteModelInfo);
	deleteInfoArray(m_paRiverModelInfo);

	deleteInfoArray(m_paWaterPlaneInfo);
	deleteInfoArray(m_paTerrainPlaneInfo);
	deleteInfoArray(m_paCameraOverlayInfo);

	deleteInfoArray(m_aEraInfo);
	deleteInfoArray(m_paEffectInfo);
	deleteInfoArray(m_paAttachableInfo);

	deleteInfoArray(m_paTechInfo);
	deleteInfoArray(m_paDiplomacyInfo);

	deleteInfoArray(m_paBuildInfo);
	deleteInfoArray(m_paUnitInfo);
	deleteInfoArray(m_paSpawnInfo);
	deleteInfoArray(m_paSpecialUnitInfo);
	deleteInfoArray(m_paSpecialistInfo);
	deleteInfoArray(m_paActionInfo);
	deleteInfoArray(m_paMissionInfo);
	deleteInfoArray(m_paControlInfo);
	deleteInfoArray(m_paCommandInfo);
	deleteInfoArray(m_paAutomateInfo);
	deleteInfoArray(m_paPromotionInfo);

	deleteInfoArray(m_paConceptInfo);
	deleteInfoArray(m_paNewConceptInfo);
	deleteInfoArray(m_paCityTabInfo);
	deleteInfoArray(m_paCalendarInfo);
	deleteInfoArray(m_paSeasonInfo);
	deleteInfoArray(m_paMonthInfo);
	deleteInfoArray(m_paDenialInfo);
	deleteInfoArray(m_paInvisibleInfo);
	deleteInfoArray(m_paUnitCombatInfo);
	//TB Promotion Line mod begin
	deleteInfoArray(m_paPromotionLineInfo);
	//TB Promotion Line mod end
	deleteInfoArray(m_paMapCategoryInfo);
	deleteInfoArray(m_paIdeaClassInfo);
	deleteInfoArray(m_paIdeaInfo);
	//deleteInfoArray(m_paTraitOptionEditsInfo);
	deleteInfoArray(m_paDomainInfo);
	deleteInfoArray(m_paUnitAIInfos);
	deleteInfoArray(m_paAttitudeInfos);
	deleteInfoArray(m_paMemoryInfos);
	deleteInfoArray(m_paGameOptionInfos);
	deleteInfoArray(m_paMPOptionInfos);
	deleteInfoArray(m_paForceControlInfos);
	deleteInfoArray(m_paPlayerOptionInfos);
	deleteInfoArray(m_paGraphicOptionInfos);

	deleteInfoArray(m_paYieldInfo);
	deleteInfoArray(m_paTerrainInfo);
	deleteInfoArray(m_paFeatureInfo);
	deleteInfoArray(m_paBonusClassInfo);
	deleteInfoArray(m_paBonusInfo);
	deleteInfoArray(m_paLandscapeInfo);

	deleteInfoArray(m_paUnitFormationInfo);
	deleteInfoArray(m_paCivicOptionInfo);
	deleteInfoArray(m_paCursorInfo);

	SAFE_DELETE_ARRAY(GC.getEntityEventTypes());
	SAFE_DELETE_ARRAY(GC.getAnimationOperatorTypes());
	SAFE_DELETE_ARRAY(GC.getFunctionTypes());
	SAFE_DELETE_ARRAY(GC.getFlavorTypes());
	SAFE_DELETE_ARRAY(GC.getArtStyleTypes());
	SAFE_DELETE_ARRAY(GC.getCitySizeTypes());
	SAFE_DELETE_ARRAY(GC.getContactTypes());
	SAFE_DELETE_ARRAY(GC.getDiplomacyPowerTypes());
	SAFE_DELETE_ARRAY(GC.getAutomateTypes());
	SAFE_DELETE_ARRAY(GC.getDirectionTypes());
	SAFE_DELETE_ARRAY(GC.getFootstepAudioTypes());
	SAFE_DELETE_ARRAY(GC.getFootstepAudioTags());
	deleteInfoArray(m_paQuestInfo);
	deleteInfoArray(m_paTutorialInfo);

	deleteInfoArray(m_paEventInfo);
	deleteInfoArray(m_paEventTriggerInfo);
	deleteInfoArray(m_paEspionageMissionInfo);

	deleteInfoArray(m_paEntityEventInfo);
	deleteInfoArray(m_paAnimationCategoryInfo);
	deleteInfoArray(m_paAnimationPathInfo);
	deleteInfoArray(m_paPropertyInfo);

	clearTypesMap();
	m_aInfoVectors.clear();
}
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 11/30/07                                MRGENIE      */
/*                                                                                              */
/* Savegame compatibility                                                                       */
/************************************************************************************************/
void CvGlobals::doResetInfoClasses(int iNumSaveGameVector, std::vector<CvString> m_aszSaveGameVector)
{
	// Store stuff being set by the exe in temp arrays
	StoreExeSettings();

	//delete obsolete InfoClasses
	deleteInfoArrays();

	// reset the ModLoadControlVector
	m_paModLoadControlVector.erase(m_paModLoadControlVector.begin(), m_paModLoadControlVector.end());

	//Load the Savegame vector to the ModLoadControlVector(being used by the enum)
	for ( int i = 0; i < iNumSaveGameVector; i++ )
	{
		m_paModLoadControlVector.push_back(m_aszSaveGameVector[i]);
	}

	//Delete InfoMap Keys
	infoTypeFromStringReset();

	//reload the new infoclasses
	CvXMLLoadUtility XMLLoadUtility;
	XMLLoadUtility.doResetGlobalInfoClasses();

	//Reload Arts with the Current MLF
	CvArtFileMgr ArtFileMgr = ArtFileMgr.GetInstance();
	ArtFileMgr.Reset();

	XMLLoadUtility.doResetInfoClasses();		// Reloads/allocs Art Defines

	// Load stuff being set by the exe from temp arrays
	LoadExeSettings();
}
void CvGlobals::StoreExeSettings()
{
	// Chars from TGA files, CommerceInfo
	m_iStoreExeSettingsCommerceInfo =  new int[NUM_COMMERCE_TYPES];
	for ( int i = 0; i < NUM_COMMERCE_TYPES; i++ )
	{
		m_iStoreExeSettingsCommerceInfo[i] = getCommerceInfo((CommerceTypes)i).getChar();
	}
	// Chars from TGA files, YieldInfo
	m_iStoreExeSettingsYieldInfo =  new int[NUM_YIELD_TYPES];
	for ( int i = 0; i < NUM_YIELD_TYPES; i++ )
	{
		m_iStoreExeSettingsYieldInfo[i] = getYieldInfo((YieldTypes)i).getChar();
	}	
	// Chars from TGA files, ReligionInfo
	m_iStoreExeSettingsReligionInfo =  new int[getNumReligionInfos()];
	for ( int i = 0; i < getNumReligionInfos(); i++ )
	{
		m_iStoreExeSettingsReligionInfo[i] = getReligionInfo((ReligionTypes)i).getChar();
	}
	// Chars from TGA files, CorporationInfo
	m_iStoreExeSettingsCorporationInfo =  new int[getNumCorporationInfos()];
	for ( int i = 0; i < getNumCorporationInfos(); i++ )
	{
		m_iStoreExeSettingsCorporationInfo[i] = getCorporationInfo((CorporationTypes)i).getChar();
	}
	// Chars from TGA files, BonusInfo
	m_iStoreExeSettingsBonusInfo =  new int[getNumBonusInfos()];
	for ( int i = 0; i < getNumBonusInfos(); i++ )
	{
		m_iStoreExeSettingsBonusInfo[i] = getBonusInfo((BonusTypes)i).getChar();
	}
}
void CvGlobals::LoadExeSettings()
{
	// Chars from TGA files, CommerceInfo
	for ( int i = 0; i < NUM_COMMERCE_TYPES; i++ )
	{
		getCommerceInfo((CommerceTypes)i).setChar(m_iStoreExeSettingsCommerceInfo[i]);
	}
	SAFE_DELETE_ARRAY(m_iStoreExeSettingsCommerceInfo);
	// Chars from TGA files, YieldInfo
	for ( int i = 0; i < NUM_YIELD_TYPES; i++ )
	{
		getYieldInfo((YieldTypes)i).setChar(m_iStoreExeSettingsYieldInfo[i]);
	}
	SAFE_DELETE_ARRAY(m_iStoreExeSettingsYieldInfo);
	// Chars from TGA files, ReligionInfo
	for ( int i = 0; i < getNumReligionInfos(); i++ )
	{
		getReligionInfo((ReligionTypes)i).setChar(m_iStoreExeSettingsReligionInfo[i]);
	}
	SAFE_DELETE_ARRAY(m_iStoreExeSettingsReligionInfo);
	// Chars from TGA files, CorporationInfo
	for ( int i = 0; i < getNumCorporationInfos(); i++ )
	{
		getCorporationInfo((CorporationTypes)i).setChar(m_iStoreExeSettingsCorporationInfo[i]);
	}
	SAFE_DELETE_ARRAY(m_iStoreExeSettingsCorporationInfo);
	// Chars from TGA files, BonusInfo
	for ( int i = 0; i < getNumBonusInfos(); i++ )
	{
		getBonusInfo((BonusTypes)i).setChar(m_iStoreExeSettingsBonusInfo[i]);
	}
	SAFE_DELETE_ARRAY(m_iStoreExeSettingsBonusInfo);
}
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 END                                                  */
/************************************************************************************************/


//
// Global Infos Hash Map
//

int CvGlobals::getInfoTypeForString(const char* szType, bool hideAssert) const
{
	FAssertMsg(szType, "null info type string");
	InfosMap::const_iterator it = m_infosMap.find(szType);
	if (it!=m_infosMap.end())
	{
		return it->second;
	}

	if(!(stricmp(szType, "NONE")==0 || strcmp(szType, "")==0) && !hideAssert && !getDefineINT(szType))
	{
		CvString szError;
		szError.Format("info type '%s' not found, Current XML file is: %s", szType, GC.getCurrentXMLFile().GetCString());
		FAssertMsg(stricmp(szType, "NONE")==0 || strcmp(szType, "")==0, szError.c_str());

		LogMissingType(szType);
	}

	return -1;
}

bool CvGlobals::hasInfoTypeForString(const char* szType, bool hideAssert) const
{
	FAssertMsg(szType, "null info type string");
	InfosMap::const_iterator it = m_infosMap.find(szType);
	if (it!=m_infosMap.end())
	{
		return true;
	}

	if(!(stricmp(szType, "NONE")==0 || strcmp(szType, "")==0) && !getDefineINT(szType))
	{
		if (!hideAssert)
		{
			CvString szError;
			szError.Format("info type '%s' not found, Current XML file is: %s", szType, GC.getCurrentXMLFile().GetCString());
			FAssertMsg2(stricmp(szType, "NONE")==0 || strcmp(szType, "")==0, szError.c_str());
		}
		LogMissingType(szType);
	}

	return false;
}

void CvGlobals::LogMissingType( const char* szType ) const
{
	CvString szError;
	szError.Format("info type '%s' not found, Current XML file is: %s", szType, GC.getCurrentXMLFile().GetCString());
	gDLL->logMsg("Xml_MissingTypes.log", szError);
}

/************************************************************************************************/
/* SORT_ALPHABET                           11/19/07                                MRGENIE      */
/*                                                                                              */
/* Rearranging the infos map                                                                    */
/************************************************************************************************/
/*
void CvGlobals::setInfoTypeFromString(const char* szType, int idx)
{
	FAssertMsg(szType, "null info type string");
#ifdef _DEBUG
	InfosMap::const_iterator it = m_infosMap.find(szType);
	int iExisting = (it!=m_infosMap.end()) ? it->second : -1;
	FAssertMsg(iExisting==-1 || iExisting==idx || strcmp(szType, "ERROR")==0, CvString::format("xml info type entry %s already exists", szType).c_str());
#endif
	m_infosMap[szType] = idx;
}
*/
void CvGlobals::setInfoTypeFromString(const char* szType, int idx)
{
	FAssertMsg(szType, "null info type string");
#ifdef _DEBUG
	OutputDebugString(CvString::format("%s -> %d\n", szType, idx).c_str());
#endif
	char* strCpy = new char[strlen(szType)+1];

	m_infosMap[strcpy(strCpy, szType)] = idx;
}

// returns the ID if it exists, otherwise assigns a new ID
int CvGlobals::getOrCreateInfoTypeForString(const char* szType)
{
	int iID = getInfoTypeForString(szType, true);
	if (iID < 0)
	{
		m_iLastTypeID++;
		iID = m_iLastTypeID;
		setInfoTypeFromString(szType, iID);
	}
	return iID;
}

void CvGlobals::logInfoTypeMap(const char* tagMsg)
{
	if (GC.isXMLLogging())
	{
		CvString szDebugBuffer;
		szDebugBuffer.Format(" === Info Type Map Dump BEGIN: %s ===", tagMsg);
		gDLL->logMsg("CvGlobals_logInfoTypeMap.log", szDebugBuffer.c_str());

		int iCnt = 0;
		std::vector<std::string> vInfoMapKeys;
		for (InfosMap::const_iterator it = m_infosMap.begin(); it != m_infosMap.end(); ++it)
		{
			std::string sKey = it->first;
			vInfoMapKeys.push_back(sKey);
		}

		std::sort(vInfoMapKeys.begin(), vInfoMapKeys.end());

		for (std::vector<std::string>::const_iterator it = vInfoMapKeys.begin(); it != vInfoMapKeys.end(); ++it)
		{
			std::string sKey = *it;
			int iVal = m_infosMap[sKey.c_str()];
			szDebugBuffer.Format(" * %i --  %s: %i", iCnt, sKey.c_str(), iVal);
			gDLL->logMsg("CvGlobals_logInfoTypeMap.log", szDebugBuffer.c_str());
			iCnt++;
		}

		szDebugBuffer.Format("Entries in total: %i", iCnt);
		gDLL->logMsg("CvGlobals_logInfoTypeMap.log", szDebugBuffer.c_str());
		szDebugBuffer.Format(" === Info Type Map Dump END: %s ===", tagMsg);
		gDLL->logMsg("CvGlobals_logInfoTypeMap.log", szDebugBuffer.c_str());
	}
}
/************************************************************************************************/
/* SORT_ALPHABET                           END                                                  */
/************************************************************************************************/

void CvGlobals::infoTypeFromStringReset()
{
	for (InfosMap::const_iterator it = m_infosMap.begin(); it != m_infosMap.end(); ++it)
	{
		delete[] it->first;
	}

	m_infosMap.clear();
}

void CvGlobals::addToInfosVectors(void *infoVector)
{
	std::vector<CvInfoBase *> *infoBaseVector = (std::vector<CvInfoBase *> *) infoVector;
	m_aInfoVectors.push_back(infoBaseVector);
}

void CvGlobals::infosReset()
{
	for(int i=0;i<(int)m_aInfoVectors.size();i++)
	{
		std::vector<CvInfoBase *> *infoBaseVector = m_aInfoVectors[i];
		for(int j=0;j<(int)infoBaseVector->size();j++)
			infoBaseVector->at(j)->reset();
	}
}
/*********************************/
/***** Parallel Maps - Begin *****/
/*********************************/

void CvGlobals::switchMap(MapTypes eMap)
{	
	//bool bInitial = false;

	GC.getMap().beforeSwitch();

	if (eMap > NO_MAP && eMap < GC.getNumMapInfos())
		GC.getGame().setCurrentMap(eMap);

	GC.getMap().afterSwitch();
}

CvViewport* CvGlobals::getCurrentViewport() const
{
	return m_maps[GC.getGame().getCurrentMap()]->getCurrentViewport();
}

int	CvGlobals::getViewportSizeX() const
{
	return GC.viewportsEnabled() ? std::min(m_iViewportSizeX, m_maps[GC.getGame().getCurrentMap()]->getGridWidth()) : m_maps[GC.getGame().getCurrentMap()]->getGridWidth();
}

int	CvGlobals::getViewportSizeY() const
{
	return GC.viewportsEnabled() ? std::min(m_iViewportSizeY, m_maps[GC.getGame().getCurrentMap()]->getGridHeight()) : m_maps[GC.getGame().getCurrentMap()]->getGridHeight();
}

int	CvGlobals::getViewportSelectionBorder() const
{
	return m_iViewportFocusBorder;
}

int	CvGlobals::getViewportCenteringBorder() const
{
	return m_iViewportCenterOnSelectionCenterBorder;
}


CvMapExternal& CvGlobals::getMapExternal() const
{
	CvViewport* currentViewport = getCurrentViewport();

	FAssert(currentViewport != NULL);

	return *(currentViewport->getProxy());
}

CvMap& CvGlobals::getMapByIndex(MapTypes eIndex) const
{
	FAssert(eIndex > NO_MAP);
	FAssert(eIndex < GC.getNumMapInfos());
	return *m_maps[eIndex];
}

void CvGlobals::clearSigns()
{
	gDLL->getEngineIFace()->clearSigns();

	m_bSignsCleared = true;
}

void CvGlobals::reprocessSigns()
{
	if ( m_bSignsCleared )
	{
		Cy::call(PYCivModule, "AddSign", Cy::Args() << (CvPlot*)NULL << NO_PLAYER << "");
		m_bSignsCleared = false;
	}
}

void CvGlobals::initializeMap(MapTypes eMap)
{
	OutputDebugString("Initializing Map: Start\n");
	while ( m_maps.size() < (size_t)eMap )
	{
		//	Sparse or out of order initialization
		m_maps.push_back(NULL);
	}

	FAssertMsg(m_maps[eMap] == NULL, "Memory leak allocating a map that already exists");

	m_maps[eMap] = new CvMap(eMap);
	OutputDebugString("Initializing Map: End\n");
}

bool CvGlobals::mapInitialized(MapTypes eMap) const
{
	return (m_maps.size() > (size_t)eMap && m_maps[eMap] != NULL);
}


/*******************************/
/***** Parallel Maps - End *****/
/*******************************/


void CvGlobals::addDelayedResolution(int *pType, CvString szString)
{
	m_delayedResolutionMap[pType] = std::make_pair(szString,  GC.getCurrentXMLFile());
	//m_delayedResolutionMap.insert(DelayedResolutionMap::value_type(pType, szString));
}

CvString* CvGlobals::getDelayedResolution(int *pType)
{
	DelayedResolutionMap::iterator it = m_delayedResolutionMap.find(pType);
	if (it == m_delayedResolutionMap.end())
	{
		return NULL;
	}
	return &(it->second.first);
}

void CvGlobals::removeDelayedResolution(int *pType)
{
	m_delayedResolutionMap.erase(pType);
}

void CvGlobals::copyNonDefaultDelayedResolution(int* pTypeSelf, int* pTypeOther)
{
	if (getDelayedResolution(pTypeSelf) == NULL)
	{
		CvString* pszOther = getDelayedResolution(pTypeOther);
		if (pszOther != NULL)
		{
			addDelayedResolution(pTypeSelf, *pszOther);
		}
	}
}
	
void CvGlobals::resolveDelayedResolution()
{
	for (DelayedResolutionMap::iterator it = m_delayedResolutionMap.begin(); it != m_delayedResolutionMap.end(); ++it)
	{
		GC.setCurrentXMLFile(it->second.second);
		*(it->first) = getInfoTypeForString(it->second.first);
	}
	m_delayedResolutionMap.clear();
}

int CvGlobals::getNumMissionInfos() const
{ 
	return (int) m_paMissionInfo.size();
}

inline CvMap& CvGlobals::getMap()
{
	return *m_maps[GC.getGame().getCurrentMap()];
}

inline const CvMap& CvGlobals::getMap() const
{
	return *m_maps[GC.getGame().getCurrentMap()];
}

bool CvGlobals::IsGraphicsInitialized() const { return m_bGraphicsInitialized; }
void CvGlobals::SetGraphicsInitialized(bool bVal) { m_bGraphicsInitialized = bVal; }
void CvGlobals::setInterface(CvInterface* pVal) { m_interface = pVal; }
void CvGlobals::setDiplomacyScreen(CvDiplomacyScreen* pVal) { m_diplomacyScreen = pVal; }
void CvGlobals::setMPDiplomacyScreen(CMPDiplomacyScreen* pVal) { m_mpDiplomacyScreen = pVal; }
void CvGlobals::setMessageQueue(CMessageQueue* pVal) { m_messageQueue = pVal; }
void CvGlobals::setHotJoinMessageQueue(CMessageQueue* pVal) { m_hotJoinMsgQueue = pVal; }
void CvGlobals::setMessageControl(CMessageControl* pVal) { m_messageControl = pVal; }
void CvGlobals::setSetupData(CvSetupData* pVal) { m_setupData = pVal; }
void CvGlobals::setMessageCodeTranslator(CvMessageCodeTranslator* pVal) { m_messageCodes = pVal; }
void CvGlobals::setDropMgr(CvDropMgr* pVal) { m_dropMgr = pVal; }
void CvGlobals::setPortal(CvPortal* pVal) { m_portal = pVal; }
void CvGlobals::setStatsReport(CvStatsReporter* pVal) { m_statsReporter = pVal; }
void CvGlobals::setPathFinder(FAStar* pVal) { m_pathFinder = pVal; }
void CvGlobals::setInterfacePathFinder(FAStar* pVal) { m_interfacePathFinder = pVal; }
void CvGlobals::setStepFinder(FAStar* pVal) { m_stepFinder = pVal; }
void CvGlobals::setRouteFinder(FAStar* pVal) { m_routeFinder = pVal; }
void CvGlobals::setBorderFinder(FAStar* pVal) { m_borderFinder = pVal; }
void CvGlobals::setAreaFinder(FAStar* pVal) { m_areaFinder = pVal; }
void CvGlobals::setPlotGroupFinder(FAStar* pVal) { m_plotGroupFinder = pVal; }
CvDLLUtilityIFaceBase* CvGlobals::getDLLIFaceNonInl() { return g_DLL; }

// BUG - BUG Info - start
static bool bBugInitCalled = false;

bool CvGlobals::bugInitCalled() const
{
	return bBugInitCalled;
}

void CvGlobals::setIsBug(bool bIsBug)
{
	bBugInitCalled = true;

	::setIsBug(bIsBug);

	bool bBUGViewportsEnabled = getBugOptionBOOL("MainInterface__EnableViewports", false);

	//	If viewports are truned on in BUG the settinsg there override those in the global defines
	if ( bBUGViewportsEnabled )
	{
		m_bViewportsEnabled = true;

		int iViewportSizeX = getBugOptionINT("MainInterface__ViewportX", 40);
		int iViewportSizeY = getBugOptionINT("MainInterface__ViewportY", 40);

		int iViewportFocusBorder = getBugOptionINT("MainInterface__ViewportAutoSwitchBorder", 2);

		//	Push them back inot the globals so that a reload of the globals cache preserves these values
		setDefineINT("ENABLE_VIEWPORTS", 1, false);
		setDefineINT("VIEWPORT_SIZE_X", iViewportSizeX, false);
		setDefineINT("VIEWPORT_SIZE_Y", iViewportSizeY, false);
		setDefineINT("VIEWPORT_FOCUS_BORDER", iViewportFocusBorder, false);
		m_iViewportCenterOnSelectionCenterBorder = getBugOptionINT("MainInterface__ViewportAutoCenterBorder", 5);

		//	This happens after the maps load on first load, so resize existing viewports
		for(int iI = 0; iI < GC.getNumMapInfos(); iI++)
		{
			for(int iJ = 0; iJ < GC.getMapByIndex((MapTypes)iI).getNumViewports(); iJ++)
			{
				GC.getMapByIndex((MapTypes)iI).getViewport(iJ)->resizeForMap();
			}
		}
	}
}
// BUG - BUG Info - end

/************************************************************************************************/
/* BETTER_BTS_AI_MOD                      02/21/10                                jdog5000      */
/*                                                                                              */
/* Efficiency, Options                                                                          */
/************************************************************************************************/
// BBAI Options
bool CvGlobals::getBBAI_AIR_COMBAT() const
{
	return m_bBBAI_AIR_COMBAT;
}

bool CvGlobals::getBBAI_HUMAN_VASSAL_WAR_BUILD() const
{
	return m_bBBAI_HUMAN_VASSAL_WAR_BUILD;
}

bool CvGlobals::getBBAI_HUMAN_AS_VASSAL_OPTION() const
{
	return m_bBBAI_HUMAN_AS_VASSAL_OPTION;
}

// Tech Diffusion
bool CvGlobals::getTECH_DIFFUSION_ENABLE() const
{
	return m_bTECH_DIFFUSION_ENABLE;
}
/************************************************************************************************/
/* BETTER_BTS_AI_MOD                       END                                                  */
/************************************************************************************************/

void CvGlobals::setXMLLogging(bool bNewVal)
{
	m_bXMLLogging = bNewVal;
}

bool CvGlobals::isXMLLogging() const
{
	return m_bXMLLogging;
}

void CvGlobals::setGraphicalDetailPagingEnabled(bool bEnabled)
{
	m_bGraphicalDetailPagingEnabled = bEnabled;
}

bool CvGlobals::getGraphicalDetailPagingEnabled() const
{
	return m_bGraphicalDetailPagingEnabled;
}

int CvGlobals::getGraphicalDetailPageInRange() const
{
	return std::max(getGame().getXResolution(), getGame().getYResolution())/150;
}

// calculate asset checksum
unsigned int CvGlobals::getAssetCheckSum()
{
	CvString szLog;
	unsigned int iSum = 0;
	for (std::vector<std::vector<CvInfoBase*> *>::iterator itOuter = m_aInfoVectors.begin(); itOuter != m_aInfoVectors.end(); ++itOuter)
	{
		for (std::vector<CvInfoBase*>::iterator itInner = (*itOuter)->begin(); itInner != (*itOuter)->end(); ++itInner)
		{
			(*itInner)->getCheckSum(iSum);
			szLog.Format("%s : %u", (*itInner)->getType(), iSum );
			gDLL->logMsg("Checksum.log", szLog.c_str());
		}
	}
	return iSum;
}

void CvGlobals::setDLLIFace(CvDLLUtilityIFaceBase* pDll)
{
	if (pDll != NULL)
	{
		FAssertMsg(g_DLL == NULL, "Dll interface already set?");

		OutputDebugString("setDLLIFace()\n");
		if (gGlobals == NULL)
		{
			OutputDebugString("Constructing internal globals\n");
			gGlobals = new CvGlobals();
		}

		g_DLL = pDll;
	}
	else
	{
		FAssertMsg(g_DLL != NULL, "Dll interface not set?");
		g_DLL = NULL;
		delete gGlobals;
	}
}
