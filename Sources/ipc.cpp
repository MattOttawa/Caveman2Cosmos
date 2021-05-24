#include "CvGameCoreDLL.h"
#include "..\\Server\\ClassFactory.h"
#include "..\\Proxy\\IIPCVector.h"
#include "..\\Proxy\\IIPCVector_i.c"
#include "ipc.h"
#include <objbase.h>

#pragma comment( lib, "Ole32.lib" )

extern const GUID CLSID_IPCVector;
extern const GUID IID_IIPCVector;

namespace ipc
{
	IIPCVector* g_pClassFactory = NULL;

	void init()
	{
		CoInitialize(NULL);
		registerProxyDll("DllRegisterServer");
		HRESULT hr = CoGetClassObject(CLSID_IPCVector, CLSCTX_LOCAL_SERVER, NULL, IID_IIPCVector, (void**)&g_pClassFactory);
		//HRESULT hr = CoCreateInstance(CLSID_IPCVector, NULL, CLSCTX_LOCAL_SERVER, IID_IIPCVector, (void**)&g_pClassFactory);
		FAssert(SUCCEEDED(hr));
	}

	void uninit()
	{
		g_pClassFactory->Release();
		CoFreeUnusedLibraries();
		registerProxyDll("DllUnregisterServer");
	}

	void registerProxyDll(const char* szFunc)
	{
		const HANDLE hDll = LoadLibrary((getModDir() + "//Assets//CvGameCoreServerProxy.dll").c_str());
		FAssert(INVALID_HANDLE_VALUE != hDll);

		const FARPROC pProc = GetProcAddress((HINSTANCE)hDll, szFunc);
		FAssert(pProc);

		const HRESULT hr = (*pProc)();
		FAssert(SUCCEEDED(hr));

		FreeLibrary((HINSTANCE)hDll);
	}
}