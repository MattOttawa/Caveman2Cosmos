#include "CvGameCoreDLL.h"
#include "ipc_vector.h"
#include "FAssert.h"
#include "..\\ipc_vector\\Registry.h"
#include "..\\ipc_vector\\IIPCVector_i.c"
#include <objbase.h>

#pragma comment( lib, "Ole32.lib" )

extern GUID CLSID_IPCVector;
extern const GUID IID_IIPCVector;

void ipc_vector::init()
{
	CoInitialize(NULL);
	HRESULT hr = CoCreateInstance(CLSID_IPCVector, NULL, CLSCTX_INPROC_SERVER, IID_IIPCVector, (void**)&m_interface);
	FAssert(SUCCEEDED(hr));
	//HRESULT hr = CoCreateInstance(CLSID_IPCVector, NULL, CLSCTX_OUTPROC_SERVER, IID_IIPCVector, (void**)&m_interface);
	HRESULT hr2 = m_interface->QueryInterface(IID_IIPCVector, (void**)&m_interface);
	FAssert(SUCCEEDED(hr2));
}

void ipc_vector::uninit()
{
	m_interface->Release();
	CoFreeUnusedLibraries();
}

int ipc_vector::operator[](int index) const
{
	int r = 0;
	m_interface->getAt(index, &r);
	return r;
}

int ipc_vector::size() const
{
	int r = 0;
	m_interface->size(&r);
	return r;
}

void ipc_vector::push_back(int value)
{
	m_interface->push_back(value);
}