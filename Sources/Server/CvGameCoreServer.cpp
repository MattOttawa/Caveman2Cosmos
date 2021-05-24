#include "stdafx.h"
#include "ClassFactory.h"
#include "IPCVector.h"
#include <objbase.h>
#include <assert.h>

extern const GUID IID_IIPCVector;

ULONG g_ServerLocks = 0;
ULONG g_Components  = 0;

HMODULE hIPCVector;

bool FIpcAssert(HRESULT hr)
{
	if (SUCCEEDED(hr))
		return true;
#ifdef DEBUG_
	void* pMsg;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, hr,
				  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&pMsg, 0, NULL);
	assert(false, pMsg);
	LocalFree(pMsg);
#endif
	return false;
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	hIPCVector = (HMODULE)hInstance;

	CoInitialize(NULL);
	DWORD dwRegCO;
	IPCVector* pIFace = new IPCVector();
	HRESULT hr = CoRegisterClassObject(CLSID_IPCVector, (IUnknown*)pIFace, CLSCTX_LOCAL_SERVER, REGCLS_SINGLEUSE, &dwRegCO);
	if (!FIpcAssert(hr))
	{
		CoUninitialize();
		exit(1);
	}

	// Run until a quit message is sent.
	MSG ms;
	while(GetMessage(&ms, 0, 0, 0))
	{
		TranslateMessage(&ms);
		DispatchMessage(&ms);
	}

	CoRevokeClassObject(dwRegCO);

	CoUninitialize();	
	assert(SUCCEEDED(hr));
	return 0;
}

STDAPI DllCanUnloadNow()
{
	return (g_ServerLocks == 0 && g_Components  == 0) ? S_OK : S_FALSE;
};

STDAPI DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv)
{
	HRESULT rc = E_UNEXPECTED;

	if (clsid == CLSID_IPCVector) {
		ClassFactory<IPCVector> *cf = new ClassFactory<IPCVector>();
		rc = cf->QueryInterface(iid, ppv);
		cf->Release();
	} 
	else  
		return CLASS_E_CLASSNOTAVAILABLE;

	return rc;
};