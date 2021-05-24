#pragma once

#include "IIPCVector.h"
#include <vector>

class IPCVector : public IIPCVector
{
public:
	IPCVector();
	~IPCVector();

	// IUnknown
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv);

	virtual ULONG STDMETHODCALLTYPE AddRef();
	virtual ULONG STDMETHODCALLTYPE Release();

	// IPCVector
	virtual HRESULT STDMETHODCALLTYPE getAt(int index, int* r);
	virtual HRESULT STDMETHODCALLTYPE size(int* r);
	virtual HRESULT STDMETHODCALLTYPE push_back(int value); 

protected:
	long m_lRef; // Reference count
	std::vector<int> m_vector;
};