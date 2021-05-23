#include "stdafx.h"
#include "ClassFactory.h"
#include "IPCVector.h"
//#include "Registry.h"

ULONG g_ServerLocks = 0;
ULONG g_Components  = 0;

extern HMODULE hIPCVector;
extern GUID CLSID_IPCVector;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		hIPCVector = hModule;
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
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