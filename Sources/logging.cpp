#include "CvGameCoreDLL.h"
#include "CvGlobals.h"
#include "CvInitCore.h"
#include "CvDLLIniParserIFaceBase.h"
#include "logging.h"

namespace logging
{
	void log_json_event(const char* type, const JsonValues& values)
	{
#ifndef FINAL_RELEASE
		picojson::value::object obj;
		for (std::vector<JsonValue>::const_iterator itr = values.values.begin(); itr != values.values.end(); ++itr)
		{
			obj[itr->name] = itr->value;
		}
		obj["type"] = picojson::value(type);
		logging::logMsg("EventsJson.log", picojson::value(obj).serialize().c_str());
#endif
	}

	void logMsg(const char* file, const char* msg, ...)
	{
		//if (!GC.isXMLLogging())
		//	return;

		static char buf[2048];
		_vsnprintf(buf, 2048 -4, msg, (char*)(&msg +1));
		gDLL->logMsg(file, buf, false, false);
#ifdef _DEBUG
		strcat(buf, "\n");
		OutputDebugString(buf);
#endif
	}

	void logMsgW(const char* file, const wchar_t* msg, ...)
	{
		static wchar_t buf[2048];
		_vsnwprintf(buf, 2048 -4, msg, (char*)(&msg +1));
		static char buf2[2048];
		wcstombs(buf2, buf, 2048 -4);
		gDLL->logMsg(file, buf2, false, false);
#ifdef _DEBUG
		strcat(buf2, "\n");
		OutputDebugString(buf2);
#endif
	}

	void deleteLogs()
	{
		WIN32_FIND_DATA FileInfo;
		const HANDLE hFile = FindFirstFile((getModDir() + "\\Logs\\*.*").c_str(), &FileInfo);
		if (hFile != INVALID_HANDLE_VALUE)
		{
			do {
				DeleteFile((getModDir() + "\\Logs\\" + FileInfo.cFileName).c_str());
			} while (FindNextFile(hFile, &FileInfo));
		}
	}
}
