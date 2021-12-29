/**********************************************************************

File:		CvBugOptions.cpp
Author:		EmperorFool
Created:	2009-01-21

		Copyright (c) 2009 The BUG Mod. All rights reserved.

**********************************************************************/

#include "CvGameCoreDLL.h"
#include "CvGlobals.h"
#include "CvPython.h"
#include "FVariableSystem.h"

bool getDefineBOOL(const char* xmlKey, bool bDefault)
{
	int iResult = 0;
	if (GC.getDefinesVarSystem()->GetValue(xmlKey, iResult))
	{
		return iResult != 0;
	}
	return bDefault;
}

int getDefineINT(const char* xmlKey, int iDefault)
{
	int iResult = 0;
	if (GC.getDefinesVarSystem()->GetValue(xmlKey, iResult))
	{
		return iResult;
	}
	return iDefault;
}

float getDefineFLOAT(const char* xmlKey, float fDefault)
{
	float fResult = 0.0;
	if (GC.getDefinesVarSystem()->GetValue(xmlKey, fResult))
	{
		return fResult;
	}
	return fDefault;
}

const char * getDefineSTRING(const char* xmlKey, const char * szDefault)
{
	const char * szResult = NULL;
	if (GC.getDefinesVarSystem()->GetValue(xmlKey, szResult))
	{
		return szResult;
	}
	return szDefault;
}


bool getBugOptionBOOL(const char* id, bool bDefault)
{
	PROFILE_FUNC();

	return Cy::call<bool>("CvAppInterface", "getOptionBOOL", Cy::Args(id, bDefault));
}

int getBugOptionINT(const char* id, int iDefault)
{
	PROFILE_FUNC();

	return Cy::call<int>("CvAppInterface", "getOptionINT", Cy::Args(id, iDefault));
}
