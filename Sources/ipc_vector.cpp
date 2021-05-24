#include "CvGameCoreDLL.h"
//#include "..\\Server\\ClassFactory.h"
#include "..\\Proxy\\IIPCVector.h"
#include "..\\Proxy\\IIPCVector_i.c"
#include "ipc.h"
#include "ipc_vector.h"
#include <objbase.h>

#pragma comment( lib, "Ole32.lib" )

const GUID CLSID_IPCVector = { 0x6942e971, 0x6f95, 0x44bc, { 0xb3, 0xa9, 0xef, 0xd2, 0x70, 0xeb, 0x39, 0xc9 } };
extern const GUID IID_IIPCVector;

void ipc_vector::init()
{
	CoInitialize(NULL);
	ipc::registerProxyDll("DllRegisterServer");
	HRESULT hr = CoGetClassObject(CLSID_IPCVector, CLSCTX_LOCAL_SERVER, NULL, IID_IIPCVector, (void**)&m_interface);
	//HRESULT hr = CoCreateInstance(CLSID_IPCVector, NULL, CLSCTX_LOCAL_SERVER, IID_IIPCVector, (void**)&m_interface);
	FAssert(SUCCEEDED(hr));
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