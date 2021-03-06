/************************************************************
*
*	CyberLink for C
*
*	Copyright (C) Satoshi Konno 2005
*
*	File: clock.h
*
*	Revision:
*       06/07/05
*               - first release.
*
************************************************************/

#ifndef _CG_CLOCK_H_
#define _CG_CLOCK_H_

#include <cybergarage/util/ctime.h>

#ifdef  __cplusplus
extern "C" {
#endif

/****************************************
* Define
****************************************/

#define SYSTEM_TIME_BUF_LEN 128

/****************************************
* Function
****************************************/

char *GetSystemTimeString(CgTime currTime, char *buf);
char *GetDateString(CgTime currTime, char *buf);
char *GetTimeString(CgTime currTime, char *buf);
int GetSecond(CgTime currTime);

#ifdef  __cplusplus
}
#endif

#endif
