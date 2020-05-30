#pragma once

#ifndef CySelectionGroup_h__
#define CySelectionGroup_h__

//
// Python wrapper class for CySelectionGroup
//

class CvSelectionGroup;
class CyPlot;
class CyArea;
class CyUnit;
//struct MissionData;

class CySelectionGroup
{
public:
	CySelectionGroup();
	explicit CySelectionGroup(CvSelectionGroup* pSelectionGroup);		// Call from C++

	CvSelectionGroup* getSelectionGroup() const { return m_pSelectionGroup;	}	// Call from C++
	bool isNone() const { return m_pSelectionGroup == NULL; }

	void pushMission(MissionTypes eMission, int iData1, int iData2, int iFlags, bool bAppend, bool bManual, MissionAITypes eMissionAI, CyPlot* pMissionAIPlot, CyUnit* pMissionAIUnit);
	bool canStartMission(int iMission, int iData1, int iData2, CyPlot* pPlot, bool bTestVisible);

	bool isHuman();
	int baseMoves();	
	bool isWaiting();
	bool isFull();
	bool hasMoved();
	bool canMoveInto(CyPlot* pPlot, bool bAttack);
	bool canMoveOrAttackInto(CyPlot* pPlot, bool bDeclareWar);
	bool canFight();
	bool isInvisible(int /*TeamTypes*/ eTeam);	

	CyPlot* plot();
	CyArea* area();

	bool readyToMove(bool bAny);

	int getID();
	int /*PlayerTypes*/ getOwner();
	int /*TeamTypes*/ getTeam();
	int /*ActivityTypes*/ getActivityType();
	void setActivityType(int /*ActivityTypes*/ eNewValue);
	int /*AutomateTypes*/ getAutomateType();
	bool isAutomated();
	void setAutomateType(int /*AutomateTypes*/ eNewValue);

	int getNumUnits();
	int getLengthMissionQueue();
	int getMissionType( int iNode );
	int getMissionData1( int iNode );
	CyUnit* getHeadUnit();

protected:
	CvSelectionGroup* m_pSelectionGroup;
};

DECLARE_PY_WRAPPER(CySelectionGroup, CvSelectionGroup*);

#endif // CySelectionGroup_h__