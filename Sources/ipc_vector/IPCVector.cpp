#include "stdafx.h"
#include "IPCVector.h"
#include "IIPCVector_i.c"

extern ULONG g_Components;

IPCVector::IPCVector() : m_lRef(1)
{
	InterlockedIncrement((LONG*)&g_Components);
}

IPCVector::~IPCVector()
{
	InterlockedDecrement((LONG*)&g_Components);
}

HRESULT STDMETHODCALLTYPE IPCVector::QueryInterface(REFIID riid, void** ppv)
{
	if       (riid == IID_IUnknown)   *ppv = (IIPCVector*)this;
	else if  (riid == IID_IIPCVector) *ppv = (IIPCVector*)this;
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	AddRef();
    return S_OK;
}

ULONG STDMETHODCALLTYPE IPCVector::AddRef()
{
	InterlockedIncrement((LONG*)&m_lRef);

	return m_lRef;
}

ULONG STDMETHODCALLTYPE IPCVector::Release()
{
	InterlockedDecrement((LONG*)&m_lRef);

	if (m_lRef > 0)
		return m_lRef;

	delete this;
	return 0;
}

HRESULT STDMETHODCALLTYPE IPCVector::getAt(int index, int* r)
{
	*r = m_vector[index];
    return S_OK;
}

HRESULT STDMETHODCALLTYPE IPCVector::size(int* r)
{
	*r = (int)m_vector.size();
    return S_OK;
}

HRESULT STDMETHODCALLTYPE IPCVector::push_back(int value)
{
	m_vector.push_back(value);
    return S_OK;
}