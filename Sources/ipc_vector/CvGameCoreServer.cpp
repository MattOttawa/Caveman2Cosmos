#include "stdafx.h"
#include "ClassFactory.h"
#include "IPCVector.h"
//#include "Registry.h"
#include <assert.h>
#include <objbase.h>

ULONG g_ServerLocks = 0;
ULONG g_Components  = 0;

extern HMODULE hIPCVector;
extern GUID CLSID_IPCVector;

DWORD dwRegCO;

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	hIPCVector = (HMODULE)hInstance;

	CoInitialize(NULL);
	IPCVector* pIFace = new IPCVector();
	HRESULT hr = CoRegisterClassObject(CLSID_IPCVector, (IUnknown*)pIFace, CLSCTX_LOCAL_SERVER, REGCLS_SINGLEUSE, &dwRegCO);
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