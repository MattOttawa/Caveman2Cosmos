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

template <class Index_T, class Value_T, Value_T defaultValue>
class IDValueMap
{
	typedef std::pair<Index_T, Value_T> Pair_t;

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
		foreach_(const Pair_t& pair, m_map)
		{
			pStream->Write(pair.first);
			pStream->Write(pair.second);
		}
	}

	typedef bst::function<void (std::vector<Pair_t>&, const Index_T&, const Value_T&, const CvString*)> Func_t;

	void read(CvXMLLoadUtility* pXML, const wchar_t* szRootTagName, Func_t func)
	{
		if (pXML->TryMoveToXmlFirstChild(szRootTagName))
		{
			m_map.clear();
			if (pXML->TryMoveToXmlFirstChild())
			{
				CvString szTextVal;
				do
				{
					if (pXML->TryMoveToXmlFirstChild())
					{
						pXML->GetXmlVal(szTextVal);
						const Index_T& type = static_cast<Index_T>(GC.getOrCreateInfoTypeForString(szTextVal));
						Value_T value = defaultValue;
						pXML->GetNextXmlVal(&value);
						func(m_map, type, value, szTextVal);

						pXML->MoveToXmlParent();
					}
				} while (pXML->TryMoveToXmlNextSibling());
				pXML->MoveToXmlParent();
			}
			pXML->MoveToXmlParent();
		}
	}

	void copyNonDefaults(const IDValueMap<Index_T, Value_T, defaultValue>& source)
	{
		foreach_(const Pair_t& pair, source[])
		{
			const Index_T& type = pair.first;
			if (getValue(type) == defaultValue)
			{
				m_map.push_back(std::make_pair(type, pair.second));
			}
		}
	}

	void copyNonDefaultDelayedResolution(const IDValueMap<Index_T, Value_T, defaultValue>& source)
	{
		const size_t iNum = source.size();
		m_map.resize(iNum);
		for (size_t i = 0; i < iNum; i++)
		{
			Pair_t& pair = m_map[i];
			const Pair_t& sourcePair = source.m_map[i];
			pair.second = sourcePair.second;
			GC.copyNonDefaultDelayedResolution(pair.first, sourcePair.first);
		}
	}

	//void removeDelayedResolution()
	//{
	//	for (size_t i = 0; i < size(); i++)
	//		GC.removeDelayedResolution(m_map[i].first);
	//}

	void getCheckSum(uint32_t& iSum) const
	{
		foreach_(const Pair_t& pair, m_map)
			CheckSum(iSum, pair);
	}

	Value_T getValue(const Index_T& type) const
	{
		foreach_(const Pair_t& pair, m_map)
			if (pair.first == type)
				return pair.second;
		return defaultValue;
	}

	bool hasValue(const Index_T& type) const
	{
		foreach_(const Pair_t& pair, m_map)
			if (pair.first == type)
				return true;
		return false;
	}

	Pair_t& operator[](int index) const { return m_map[index]; }

	const std::vector<const Pair_t*>& operator*() const { return m_map; }

	const std::vector<Pair_t>& range() const { return m_map; }
	size_t size() const { return m_map.size(); }

protected:
	std::vector<Pair_t> m_map;
};


template <class Index_T, class Value_T>
void addPair(std::vector<std::pair<Index_T, Value_T>*>& map, const Index_T& type, const Value_T& value, const CvString* string)
{
	map.push_back(std::make_pair(type, value));
}

template <class Index_T, class Value_T>
void addPairWithDelayedResolution(std::vector<std::pair<Index_T, Value_T>*>& map, const Index_T& type, const Value_T& value, const CvString* string)
{
	const size_t num = map.size();
	map.push_back(std::make_pair(type, value));
	GC.addDelayedResolution((int*)&map[num].first, string);
}


//extern int g_iPercentDefault;
//extern int g_iModifierDefault;

//typedef IDValueMap<int, int, g_iPercentDefault> IDValueMapPercent;
//typedef IDValueMap<int, int, g_iModifierDefault> IDValueMapModifier;

typedef IDValueMap<int, int, 100> IDValueMapPercent;
typedef IDValueMap<int, int, 100> IDValueMapModifier;

#endif
