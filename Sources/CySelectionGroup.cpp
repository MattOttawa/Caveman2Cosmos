#include "CvGameCoreDLL.h"
#include "CvSelectionGroup.h"
#include "CyArea.h"
#include "CyPlot.h"
#include "CySelectionGroup.h"
#include "CyUnit.h"

//
// Python wrapper class for CySelectionGroup
//

CySelectionGroup::CySelectionGroup() : m_pSelectionGroup(NULL)
{}

CySelectionGroup::CySelectionGroup(CvSelectionGroup* pSelectionGroup) : m_pSelectionGroup(pSelectionGroup)
{}

void CySelectionGroup::pushMission(MissionTypes eMission, int iData1, int iData2, int iFlags, bool bAppend, bool bManual, MissionAITypes eMissionAI, CyPlot* pMissionAIPlot, CyUnit* pMissionAIUnit)
{
	if (m_pSelectionGroup)
		m_pSelectionGroup->pushMission(eMission, iData1, iData2, iFlags, bAppend, bManual, eMissionAI, pMissionAIPlot->getPlot(), pMissionAIUnit->getUnit());
}

bool CySelectionGroup::canStartMission(int iMission, int iData1, int iData2, CyPlot* pPlot, bool bTestVisible)
{
	return m_pSelectionGroup ? m_pSelectionGroup->canStartMission(iMission, iData1, iData2, pPlot->getPlot(), bTestVisible) : false;
}

bool CySelectionGroup::isHuman()
{
	return m_pSelectionGroup ? m_pSelectionGroup->isHuman() : false;
}

int CySelectionGroup::baseMoves()
{
	return m_pSelectionGroup ? m_pSelectionGroup->baseMoves() : -1;
}

bool CySelectionGroup::isWaiting()
{
	return m_pSelectionGroup ? m_pSelectionGroup->isWaiting() : false;
}

bool CySelectionGroup::isFull()
{
	return m_pSelectionGroup ? m_pSelectionGroup->isFull() : false;
}

bool CySelectionGroup::hasMoved()
{
	return m_pSelectionGroup ? m_pSelectionGroup->hasMoved() : false;
}

bool CySelectionGroup::canMoveInto(CyPlot* pPlot, bool bAttack)
{
	return m_pSelectionGroup ? m_pSelectionGroup->canMoveInto(pPlot->getPlot(), bAttack) : false;
}

bool CySelectionGroup::canMoveOrAttackInto(CyPlot* pPlot, bool bDeclareWar)
{
	return m_pSelectionGroup ? m_pSelectionGroup->canMoveOrAttackInto(pPlot->getPlot(), bDeclareWar) : false;
}

bool CySelectionGroup::canFight()
{
	return m_pSelectionGroup ? m_pSelectionGroup->canFight() : false;
}

bool CySelectionGroup::isInvisible(int /*TeamTypes*/ eTeam)
{
	return m_pSelectionGroup ? m_pSelectionGroup->isInvisible((TeamTypes) eTeam) : false;
}

CyPlot* CySelectionGroup::plot()
{
	return m_pSelectionGroup ? new CyPlot( m_pSelectionGroup->plot() ) : NULL;
}

CyArea* CySelectionGroup::area()
{
	return m_pSelectionGroup ? new CyArea( m_pSelectionGroup->area() ) : NULL;
}

bool CySelectionGroup::readyToMove(bool bAny)
{
	return m_pSelectionGroup ? m_pSelectionGroup->readyToMove(bAny) : false;
}

int CySelectionGroup::getID()
{
	return m_pSelectionGroup ? m_pSelectionGroup->getID() : -1;
}

int /*PlayerTypes*/ CySelectionGroup::getOwner()
{
	return m_pSelectionGroup ? m_pSelectionGroup->getOwner() : -1;
}

int /*TeamTypes*/ CySelectionGroup::getTeam()
{
	return m_pSelectionGroup ? (TeamTypes) m_pSelectionGroup->getTeam() : -1;
}

int /*ActivityTypes*/ CySelectionGroup::getActivityType()
{
	return m_pSelectionGroup ? (ActivityTypes) m_pSelectionGroup->getActivityType() : -1;
}

void CySelectionGroup::setActivityType(int /*ActivityTypes*/ eNewValue)
{
	if (m_pSelectionGroup)
		m_pSelectionGroup->setActivityType((ActivityTypes) eNewValue);
}

int /*AutomateTypes*/ CySelectionGroup::getAutomateType() 
{
	return m_pSelectionGroup ? (AutomateTypes) m_pSelectionGroup->getAutomateType() : -1;
}

bool CySelectionGroup::isAutomated()
{
	return m_pSelectionGroup ? m_pSelectionGroup->isAutomated() : false;
}

void CySelectionGroup::setAutomateType(int /*AutomateTypes*/ eNewValue)
{
	if (m_pSelectionGroup)
		m_pSelectionGroup->setAutomateType((AutomateTypes) eNewValue);
}

int CySelectionGroup::getNumUnits()
{
	return m_pSelectionGroup ? m_pSelectionGroup->getNumUnits() : -1;
}

int CySelectionGroup::getLengthMissionQueue()
{
	return m_pSelectionGroup ? m_pSelectionGroup->getLengthMissionQueue() : -1;
}

CyUnit* CySelectionGroup::getHeadUnit()
{
	return m_pSelectionGroup ? new CyUnit(m_pSelectionGroup->getHeadUnit()) : NULL;
}

int CySelectionGroup::getMissionType(int iNode)
{
	return m_pSelectionGroup ? m_pSelectionGroup->getMissionType(iNode) : -1;
}

int CySelectionGroup::getMissionData1(int iNode)
{
	return m_pSelectionGroup ? m_pSelectionGroup->getMissionData1( iNode ) : -1;
}
