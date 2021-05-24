#pragma once

namespace ipc
{
	void init();
	void uninit();

	void registerProxyDll(const char* pszFunc);
}