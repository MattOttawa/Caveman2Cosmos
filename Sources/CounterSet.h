#pragma once
// CounterSet.h
#ifndef COUNTER_SET_H
#define COUNTER_SET_H

#include "array.h"

class CounterSet
{
	uint16_t iNext;
	uint16_t iSize;
	seq::array<uint16_t> iArrCounters;
	seq::array<int> iArrCurrentIDs;

	void assign(const int ID, const uint16_t iValue);

	uint16_t safeCoercion(const int iValue);

  public:
	CounterSet();
	CounterSet(const int iNumCounters);
	~CounterSet();
	void init(const int iNumCounters);
	void setCount(const int ID, const int iValue);
	uint16_t getCount(const int ID);
};

#endif