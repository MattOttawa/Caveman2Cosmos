#pragma once

//  $Header:
//------------------------------------------------------------------------------------------------
//
//  FILE:    IDValueMap.h
//
//  PURPOSE: A simple mapping from ID to value as a
//
//------------------------------------------------------------------------------------------------
#ifndef IDVALUEMAP_H
#define IDVALUEMAP_H

class cvInternalGlobals;
class CvXMLLoadUtility;

// The maps are assumed to be small, so a vector of pairs is used
template <class Index_T, class Value_T, Value_T defaultValue>
class IDValueMap
{
public:
	typedef IDValueMap<Index_T, Value_T, defaultValue>	map_t;
	typedef std::pair<Index_T, Value_T>					pair_t;

	// Call this method with the XML set to the parent node
	void read(CvXMLLoadUtility* pXML)
	{
		CvString szTextVal;
		m_map.clear();
		if (pXML->TryMoveToXmlFirstChild())
		{
			do
			{
				if (pXML->TryMoveToXmlFirstChild())
				{
					pXML->GetXmlVal(szTextVal);
					Value_T val = defaultValue;
					pXML->GetNextXmlVal(&val);
					setValue((Index_T)GC.getOrCreateInfoTypeForString(szTextVal), val);

					pXML->MoveToXmlParent();
				}
			} while (pXML->TryMoveToXmlNextSibling());
			pXML->MoveToXmlParent();
		}
	}

	void copyNonDefaults(map_t* pMap, CvXMLLoadUtility* pXML)
	{
		for (unsigned int i = 0; i < pMap->m_map.size(); i++)
		{
			bool bNotFound = true;
			const Index_T iID = pMap->m_map[i].first;
			for (unsigned int j = 0; j < m_map.size(); j++)
			{
				if (iID == m_map[j].first)
				{
					bNotFound = false;
					break;
				}
			}
			if (bNotFound)
			{
				m_map.push_back(std::make_pair(iID, pMap->m_map[i].second));
			}
		}
	}

	Value_T getValue(Index_T iID) const
	{
		foreach_(const pair_t& pair, m_map)
			if (pair.first == iID)
				return pair.second;
		return defaultValue;
	}

	void setValue(Index_T iID, Value_T val)
	{
		for (unsigned int i = 0; i < m_map.size(); i++)
		{
			if (m_map[i].first == iID)
			{
				m_map[i].second = val;
				return;
			}
		}
		m_map.push_back(std::make_pair(iID, val));
	}

	typedef typename std::vector<pair_t>::iterator        iterator;
	typedef typename std::vector<pair_t>::const_iterator  const_iterator;

	iterator begin() { return m_map.begin(); }
	iterator end()   { return m_map.end(); }

	const_iterator begin() const { return m_map.begin(); }
	const_iterator end() const   { return m_map.end(); }

protected:
	std::vector<pair_t> m_map;
};

typedef IDValueMap<int, int, 100> IDValueMapPercent;
typedef IDValueMap<int, int, 0> IDValueMapModifier;

#endif
