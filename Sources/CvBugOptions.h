#pragma once

/**********************************************************************

File:		CvBugOptions.h
Author:		EmperorFool
Created:	2009-01-21

Calls out to the CvAppInterface Python module to check user options.

		Copyright (c) 2009 The BUG Mod. All rights reserved.

**********************************************************************/

#ifndef BUG_OPTIONS_H
#define BUG_OPTIONS_H

bool getDefineBOOL(const char* xmlKey, bool bDefault = false);
int getDefineINT(const char* xmlKey, int iDefault = 0);
float getDefineFLOAT(const char* xmlKey, float fDefault);
const char * getDefineSTRING(const char* xmlKey, const char * szDefault);

bool getBugOptionBOOL(const char* id, bool bDefault = true);
int getBugOptionINT(const char* id, int iDefault = 0);

#endif
