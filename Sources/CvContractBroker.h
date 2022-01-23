#pragma once

#ifndef CvContractBroker_h__
#define CvContractBroker_h__

#include "CvUnitSelectionCriteria.h"

class CvCity;
class CvUnit;

//	Define this to have cities advertise units needs and tender for the business of building them
#define	USE_UNIT_TENDERING

//	Capability flags - may be ORd together
enum unitCapabilities
{
	NO_UNITCAPABILITIES					= 0,
	DEFENSIVE_UNITCAPABILITIES			= 1 << 0,
	OFFENSIVE_UNITCAPABILITIES			= 1 << 1,
	WORKER_UNITCAPABILITIES				= 1 << 2,
	HEALER_UNITCAPABILITIES				= 1 << 3
};
DECLARE_FLAGS(unitCapabilities);

//	Structures used to hold work requests and looking-for-work unit info
struct workRequest
{
	int						iPriority;
	unitCapabilities		eUnitFlags;
	UnitAITypes				eAIType;
	UnitTypes				eUnitType;
	int						iAtX;
	int						iAtY;
	int						iMaxPath;
	int						iUnitId;
	int						iWorkRequestId;
	int						iRequiredStrengthTimes100;
	bool					bFulfilled;
	CvUnitSelectionCriteria	criteria;
};

struct advertisingUnit
{
	int					iUnitId;
	UnitTypes			eUnitType;
	int					iDefensiveValue;
	int					iOffensiveValue;
	bool				bIsWorker;
	bool				bIsHealer;
	int					iAtX;
	int					iAtY;
	int					iContractedWorkRequest;
	int					iMatchedToRequestSeqThisPlot;
	int					iMatchedToRequestSeqAnyPlot;
	int					iMinPriority;
};

struct cityTender
{
	int					iCityId;
	int					iMinPriority;
};

//	Highest priority city builds have this priority and work down from there
#define	CITY_BUILD_PRIORITY_CEILING				900
#define	MINIMUM_CAPITAL_DEFENDER_PRIORITY		800
#define HIGHEST_PRIORITY_ESCORT_PRIORITY		600
#define MINIMUM_CITY_DEFENDER_PRIORITY			500
#define HIGH_PRIORITY_ESCORT_PRIORITY			400
#define	CITY_NO_WORKERS_WORKER_PRIORITY			300
#define FLOATING_DEFENDER_REQUEST_PRIORITY_MAX	200
#define LOW_PRIORITY_ESCORT_PRIORITY			100

//
//	The CvContractBroker abstracts a communication that allows 'idle' units to advertise themselves
//	as 'looking for work', and for requests for units to be placed with priority and criteria.  This
//	allows for cooperative behavior without both parties needing to be fully aware of the logic, and
//	reduces the need for searching when a unit looks for the best activity to undertake, which helps
//	performance
//
//	Intended usage is in a 2-pass process (from CvUnitAI::AI_update()).  In the unit's activity choice AI
//	it should:
//		1)	If it has high priority work determined directly by its own unit AI push that mission
//		2)	If no high priority work advertise itself with this broker as available for work and return
//			from AI_update() with no mission pushed (which measn it'll get called again once all the units
//			have been cycled through)
//		3)	On the second call ask for the best work from this broker and if provided push a mission
//			to do what is asked of it (move to a location, join a group being current options)
//		4)	If no suitable work is available continue with its own unit AI for low priority actions
//

struct WorkParams
{
	WorkParams()
		: iPriority(-1)
		, eUnitFlags(NO_UNITCAPABILITIES)
		, iAtX(-1)
		, iAtY(-1)
		, pJoinUnit(nullptr)
		, eAIType(NO_UNITAI)
		, iUnitStrength(-1)
		, iMaxPath(MAX_INT)
		, pArea(nullptr)
	{}

	// priority should be in the range 0-1000 ideally
	WorkParams& priority(int priority) { this->iPriority = iPriority; return *this; }
	// unitCaps indicate the type(s) of unit sought
	WorkParams& unitCaps(unitCapabilities unitCaps) { this->eUnitFlags = unitCaps; return *this; }
	// <x,y> is *roughly* where the work will be
	WorkParams& atPosition(int x, int y) { this->iAtX = x; this->iAtX = y; return *this; }
	template < class PositionalObject_ >
	WorkParams& atPosition(const PositionalObject_& obj) { this->iAtX = obj.getX(); this->iAtX = obj.getY(); return *this; }
	template < class PositionalObject_ >
	WorkParams& atPosition(const PositionalObject_* obj) { this->iAtX = obj->getX(); this->iAtX = obj->getY(); return *this; }

	// joinUnit may be nullptr but if not it is a request to join that unit's group
	WorkParams& joinUnit(CvUnit* joinUnit) { this->pJoinUnit = joinUnit; return atPosition(joinUnit); }
	WorkParams& AIType(UnitAITypes AIType) { this->eAIType = AIType; return *this; }
	WorkParams& unitStrength(int unitStrength) { this->iUnitStrength = unitStrength; return *this; }
	WorkParams& criteria(CvUnitSelectionCriteria criteria) { this->pCriteria = criteria; return *this; }
	WorkParams& maxPathLength(int maxPathLength) { this->iMaxPath = maxPathLength; return *this; }
	WorkParams& inArea(CvArea* area) { this->pArea = area; return *this; }
	

	int iPriority;
	unitCapabilities eUnitFlags;
	int iAtX;
	int iAtY;
	CvUnit* pJoinUnit;
	UnitAITypes eAIType;
	int iUnitStrength;
	bst::optional<CvUnitSelectionCriteria> pCriteria;
	int iMaxPath;
	CvArea* pArea;
};

class CvContractBroker : bst::noncopyable
{
public:
	CvContractBroker();
	virtual ~CvContractBroker();

	//	Initialize
	void init(PlayerTypes eOwner);

	//	Delete all work requests and looking for work records
	void reset();

	//	Note a unit looking for work
	void lookingForWork(const CvUnit* pUnit, int iMinPriority = 0);

	//	Unit fulfilled its work and is no longer advertising as available
	void removeUnit(const CvUnit* pUnit);

	//	Make a work request
	//		iPriority should be in the range 0-1000 ideally
	//		eUnitFlags indicate the type(s) of unit sought
	//		(iAtX,iAtY) is (roughly) where the work will be
	//		pJoinUnit may be NULL but if not it is a request to join that unit's group
	void advertiseWork(const WorkParams& params);

	//	Advertise a tender to build units
	//		iMinPriority indicates the lowest priority request this tender is appropriate for
	void advertiseTender(const CvCity* pCity, int iMinPriority);

	//	Find out how many requests have already been made for units of a specified AI type
	//	This is used by cities requesting globally needed units like settlers to avoid multiple
	//	tenders all occurring at once
	int numRequestsOutstandingAtCity(UnitAITypes eUnitAI) const;
	int numRequestsOutstandingAtPlot(UnitAITypes eUnitAI, const CvPlot* pPlot) const;
	// Compares against non default values of params (other than criteria which is currently ignored)
	int numRequestsOutstanding(const WorkParams& params) const;

	//	Make a contract
	//	This will attempt to make the best contracts between currently
	//	advertising units and work, then search the resulting set for the work
	//	of the requested unit
	//	returns true if a contract is made along with the details of what to do
	bool makeContract(CvUnit* pUnit, int& iAtX, int& iAtY, CvUnit*& pJoinUnit, bool bThisPlotOnly);

	void finalizeTenderContracts();

private:
	const workRequest*	findWorkRequest(int iWorkRequestId) const;
	advertisingUnit*	findBestUnit(const workRequest& request, bool bThisPlotOnly);
	CvUnit*				findUnit(int iUnitId) const;
	int					lowerPartiallyFulfilledRequestPriority(int iPreviousPriority, int iPreviousRequestStrength, int iStrengthProvided) const;
	UnitValueFlags		unitCapabilities2UnitValueFlags(unitCapabilities eCapabilities) const;

	std::vector<workRequest>		m_workRequests;
	std::vector<advertisingUnit>	m_advertisingUnits;
	std::vector<cityTender>			m_advertisingTenders;
	stdext::hash_set<int>			m_contractedUnits;
	int								m_iNextWorkRequestId;
	PlayerTypes						m_eOwner;
};

#endif // CvContractBroker_h__
