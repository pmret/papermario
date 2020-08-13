
/*====================================================================
 * os.h
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

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: os.h,v $
        $Revision: 1.167 $
        $Date: 1999/01/18 13:17:43 $
 *---------------------------------------------------------------------*/

#ifndef _OS_H_
#define	_OS_H_

#include <PR/os_thread.h>
#include <PR/os_message.h>
#include <PR/os_exception.h>
#include <PR/os_tlb.h>
#include <PR/os_pi.h>
#include <PR/os_vi.h>
#include <PR/os_ai.h>
#include <PR/os_si.h>
#include <PR/os_time.h>
#include <PR/os_cont.h>
#include <PR/os_pfs.h>
#include <PR/os_gbpak.h>
#include <PR/os_voice.h>
#include <PR/os_cache.h>
#include <PR/os_debug.h>
#include <PR/os_error.h>
#include <PR/os_gio.h>
#include <PR/os_reg.h>
#include <PR/os_system.h>
#include <PR/os_eeprom.h>
#include <PR/os_host.h>
#include <PR/os_convert.h>
#include <PR/os_rdp.h>
#include <PR/os_rsp.h>
#include <PR/os_motor.h>
#include <PR/os_libc.h>
#include <PR/os_version.h>

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

/**************************************************************************
 *
 * Global definitions
 *
 */

/*
 * Stack size for I/O device managers: PIM (PI Manager), VIM (VI Manager),
 *	SIM (SI Manager)
 *
 */
#define OS_PIM_STACKSIZE	4096
#define OS_VIM_STACKSIZE	4096
#define OS_SIM_STACKSIZE	4096

#define	OS_MIN_STACKSIZE	72

/* 
 * Leo Disk 
 */

/* transfer mode */

#define LEO_BLOCK_MODE	1
#define LEO_TRACK_MODE	2
#define LEO_SECTOR_MODE	3

/*
 * Boot addresses
 */
#define	BOOT_ADDRESS_ULTRA	0x80000400
#define	BOOT_ADDRESS_COSIM	0x80002000
#define	BOOT_ADDRESS_EMU	0x20010000
#define	BOOT_ADDRESS_INDY 	0x88100000


#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_H */
