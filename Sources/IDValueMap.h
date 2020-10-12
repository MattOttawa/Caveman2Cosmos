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

class CvXMLLoadUtility;

// ValueType will usually be int, only value types that are supported by FDataStreamBase as overloaded read and write will work without template specialization
// The maps are assumed to be small, so a vector of pairs is used
template <class IndexType, class Value_T, Value_T defaultValue>
class IDValueMap
{
	typedef std::pair<IndexType, Value_T> Pair_t;

public:
	void read(FDataStreamBase* pStream)
	{
		size_t iSize = 0;
		pStream->Read(&iSize);
		m_map.resize(iSize);
		foreach_(Pair_t& pair, m_map)
		{
			pStream->Read(&pair.first);
			pStream->Read(&pair.second);
		}
	}

	void write(FDataStreamBase* pStream)
	{
		pStream->Write(m_map);
		foreach_(const Pair_t pair, m_map)
		{
			pStream->Write(pair.first);
			pStream->Write(pair.second);
		}
	}

	void read(CvXMLLoadUtility* pXML, const wchar_t* szRootTagName)
	{
		if (pXML->TryMoveToXmlFirstChild(szRootTagName))
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
						const IndexType iID = static_cast<IndexType>(GC.getOrCreateInfoTypeForString(szTextVal));
						Value_T val = defaultValue;
						pXML->GetNextXmlVal(&val);
						m_map.push_back(std::make_pair(iID, val));

						pXML->MoveToXmlParent();
					}
				} while (pXML->TryMoveToXmlNextSibling());
				pXML->MoveToXmlParent();
			}
			pXML->MoveToXmlParent();
		}
	}

	void copyNonDefaults(const IDValueMap<IndexType, Value_T, defaultValue>& pMap)
	{
		foreach_(const Pair_t otherPair, pMap.m_map)
		{
			const IndexType otherID = otherPair.first;
			if (getValue(otherID) == defaultValue)
			{
				m_map.push_back(std::make_pair(otherID, otherPair.second));
			}
		}
	}

	void copyNonDefaultDelayedResolution(const IDValueMap<IndexType, Value_T, defaultValue>& pMap)
	{
		if (size() == 0)
		{
			const size_t iNum = pMap.size();
			m_map.resize(iNum);
			for (size_t i = 0; i < iNum; i++)
			{
				m_map[i].second = pMap.m_map[i].second;
				GC.copyNonDefaultDelayedResolution(m_map[i].first, pMap.m_map[i].first);
			}
		}
	}

	void removeDelayedResolution()
	{
		for (size_t i = 0; i < size(); i++)
			GC.removeDelayedResolution(m_map[i].first);
	}

	void getCheckSum(uint32_t& iSum) const
	{
		foreach_(const Pair_t pair, m_map)
		{
			CheckSum(iSum, pair);
			//CheckSum(iSum, pair.first);
			//CheckSum(iSum, pair.second);
		}
	}

	Value_T getValue(IndexType iID) const
	{
		foreach_(const Pair_t pair, m_map)
			if (pair.first == iID)
				return pair.second;
		return defaultValue;
	}

	bool hasValue(IndexType iID) const
	{
		foreach_(const Pair_t pair, m_map)
			if (pair.first == iID)
				return true;
		return false;
	}

	Pair_t& operator[](int index) const { return m_map[index]; }

	//std::vector<Pair_T>::const_iterator begin() const
	//{
	//	return m_map.begin();
	//}

	//std::vector<Pair_T>::const_iterator end() const
	//{
	//	return m_map.end();
	//}

	const Pair_t begin() const
	{
		return static_cast<const Pair_t>(m_map.begin());
	}

	const Pair_t end() const
	{
		return static_cast<const Pair_t>(m_map.end());
	}

	const std::vector<Pair_t> data() const
	{
		return m_map;
	}

	size_t size() const
	{
		return m_map.size();
	}

protected:
	std::vector<Pair_t> m_map;
};


#define DECLARE_PAIR_STRUCT(className, firstDataType, firstGetMethod, secondDataType, secondGetMethod) \
																	\
	struct className												\
	{																\
	public:															\
		className(firstDataType id, secondDataType value)			\
			: m_id(id), m_value(value) { }							\
																	\
		firstDataType firstGetMethod() const { return m_id; }		\
		secondDataType secondGetMethod() const { return m_value; }	\
																	\
		firstDataType getID() const { return m_id; }				\
		secondDataType getValue() const { return m_value; }			\
																	\
	protected:														\
		firstDataType m_id;											\
		secondDataType m_value;										\
	};																\
																	\
	typedef std::vector<className> className##Array;

/*
DECLARE_PAIR_STRUCT(UnitCombatModifier, UnitCombatTypes, getUnitCombat, int, getModifier)
DECLARE_PAIR_STRUCT(TechModifier, TechTypes, getTech, int, getModifier)
DECLARE_PAIR_STRUCT(TerrainModifier, TerrainTypes, getTerrain, int, getModifier)
DECLARE_PAIR_STRUCT(FeatureModifier, FeatureTypes, getFeature, int, getModifier)
DECLARE_PAIR_STRUCT(BuildModifier, BuildTypes, getBuild, int, getModifier)
DECLARE_PAIR_STRUCT(BonusModifier, BonusTypes, getBonus, int, getModifier)
DECLARE_PAIR_STRUCT(ImprovementModifier, ImprovementTypes, getImprovement, int, getModifier)
*/
//extern int g_iPercentDefault;
//extern int g_iModifierDefault;

//typedef IDValueMap<int, int, g_iPercentDefault> IDValueMapPercent;
//typedef IDValueMap<int, int, g_iModifierDefault> IDValueMapModifier;

typedef IDValueMap<int, int, 100> IDValueMapPercent;
typedef IDValueMap<int, int, 100> IDValueMapModifier;

#endif
