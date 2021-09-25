/*====================================================================
 * ultralog.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/**************************************************************************
 *
 *  $Revision: 1.6 $
 *  $Date: 1997/02/11 08:39:05 $
 *  $Source: /hosts/gate3/exdisk2/cvs/N64OS/Master/cvsmdev2/PR/include/ultralog.h,v $
 *
 **************************************************************************/

#ifndef __log__
#define __log__

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#define OS_LOG_MAX_ARGS         16
#define OS_LOG_MAGIC            0x20736a73
#define OS_LOG_FLOAT(x)         (*(int *) &(x))
#define OS_LOG_VERSION          1
    
typedef struct {
    u32 magic;          /* log identifier                       */
    u32 len;            /* length of log data + log structure   */
    u32 *base;          /* starting addr array                  */
    s32 startCount;     /* read offset from dataBase            */
    s32 writeOffset;    /* write offset from dataBase           */
} OSLog;

typedef struct {
    u32 magic;
    u32 timeStamp;
    u16 argCount;
    u16 eventID;
} OSLogItem;

typedef struct {
    u32 magic;          /* log identifier */
    u32 version;        /* 1 */
} OSLogFileHdr;

void    osCreateLog(OSLog *log, u32 *base, s32 len);
void    osLogEvent(OSLog *log, s16 code, s16 numArgs, ...);
void    osFlushLog(OSLog *log);
u32	osLogFloat(f32);

extern void osDelay(int count);

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif
