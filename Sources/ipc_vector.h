#pragma once

//#include "stdafx.h"
#include <objbase.h>
#include "..\\ipc_vector\\IIPCVector.h"

// {6942E971-6F95-44BC-B3A9-EFD270EB39C9}
//GUID CLSID_IPCVector = { 0x6942e971, 0x6f95, 0x44bc, { 0xb3, 0xa9, 0xef, 0xd2, 0x70, 0xeb, 0x39, 0xc9 } };

class ipc_vector
{
public:
	void init();
	void uninit();

	int operator[](int index) const {
		int r = 0;
		m_interface->getAt(index, &r);
		return r;
	}

	int size() const {
		int r = 0;
		m_interface->size(&r);
		return r;
	}

	void push_back(int value) {
		m_interface->push_back(value);
	}

protected:
	IIPCVector* m_interface;
};