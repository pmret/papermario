#ifndef _RAMROM_H
#define	_RAMROM_H

/**************************************************************************
 *									  *
 *		 Copyright (C) 1994, Silicon Graphics, Inc.		  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/

/**************************************************************************
 *
 *  $Revision: 1.20 $
 *  $Date: 1997/02/11 08:26:47 $
 *  $Source: /hosts/gate3/exdisk2/cvs/N64OS/Master/cvsmdev2/PR/include/ramrom.h,v $
 *
 **************************************************************************/

/*
 * Defines for the GIO card in the Nintendo Development Station
 * 
 * The RAM on the GIO card acts as ROM for the game
 * Interrupts available between the game and the Indy host
 *
 * The last part of the ramrom is used for communication between
 * game and host.  There are 6 4K buffers defined:
 *    log, printf, rmon to indy, rmon from indy, app to indy, app from indy
 * The last 8 bytes of the buffer are used in the emulator environment
 */

#define	RAMROM_SIZE		(0x1000000)

#define RAMROM_BUF_SIZE		(4096)
#define RAMROM_MSG_SIZE		(RAMROM_BUF_SIZE*6)
#define RAMROM_MSG_ADDR		(RAMROM_SIZE - RAMROM_MSG_SIZE)
#define RAMROM_MSG_HDR_SIZE	(3*4) // TODO: Used to be (3*sizeof(long))
#define RAMROM_USER_DATA_SIZE	(RAMROM_MSG_SIZE-RAMROM_MSG_HDR_SIZE)

#define RAMROM_APP_READ_ADDR	(RAMROM_MSG_ADDR + (0*RAMROM_BUF_SIZE))
#define RAMROM_APP_WRITE_ADDR	(RAMROM_MSG_ADDR + (1*RAMROM_BUF_SIZE))
#define RAMROM_RMON_READ_ADDR	(RAMROM_MSG_ADDR + (2*RAMROM_BUF_SIZE))
#define RAMROM_RMON_WRITE_ADDR	(RAMROM_MSG_ADDR + (3*RAMROM_BUF_SIZE))
#define RAMROM_PRINTF_ADDR	(RAMROM_MSG_ADDR + (4*RAMROM_BUF_SIZE))
#define RAMROM_LOG_ADDR		(RAMROM_MSG_ADDR + (5*RAMROM_BUF_SIZE))

/*#define RAMROM_GIO_INTERRUPT	(RAMROM_MSG_ADDR + RAMROM_MSG_SIZE - 4)*/

/*
 * For the initial round of PIF bringup, we will load in a bootstrap loader
 * 0x400 bytes into the ramrom, and the rom will be loaded at 0x2000
 */
#ifndef _HW_VERSION_1
#define RAMROM_BOOTSTRAP_OFFSET	0x40
#define RAMROM_GAME_OFFSET	0x1000
#define RAMROM_FONTDATA_OFFSET	0xb70
#define RAMROM_FONTDATA_SIZE	1152
#else
#define RAMROM_BOOTSTRAP_OFFSET	0x400
#define RAMROM_GAME_OFFSET	0x2000
#endif 
#define RAMROM_CLOCKRATE_OFFSET	0x4
#define RAMROM_CLOCKRATE_MASK	0xfffffff0
#define RAMROM_BOOTADDR_OFFSET	0x8
#define RAMROM_RELEASE_OFFSET	0xc
/*
 * Second version of the PIF jumps to location 0x1000, and we'll put a jump to
 * location 0x400 into the ramrom (for backwards compatibility).
 */
#define RAMROM_PIF2BOOTSTRAP_OFFSET	0x1000

typedef struct {
    long type;
    long length;	    /* in bytes of userdata */
    long magic;
    char userdata[RAMROM_USER_DATA_SIZE];
} RamRomBuffer;

/*
 * Interrupt values  (must fit in 6 bits!)
 * values are used for both request & response
 * Transactions initiated by the host start with HOST
 * and those initiated by the target start with GAME.
 */

#define HOST_PIACCESS_REQ	1
#define HOST_DBG_CMD_READY	2
#define GAME_DBG_DATA_SEND	3
#define HOST_DBG_DATA_ACK	4
#define GAME_PRINTF_SEND	5
#define HOST_PRINTF_ACK		6
#define GAME_LOG_SEND		7
#define HOST_LOG_ACK		8
#define HOST_APP_CMD_READY	9
#define GAME_APP_DATA_READY	10
#define	HOST_PROF_REQ		11
#define	GAME_PROF_SEND		12
#define	HOST_PROF_ACK		13
#define	GAME_FAULT_SEND		14
#define	HOST_FAULT_ACK		15
#define	GAME_EXIT		16
#define	HOST_DATA_ACK		17

#ifdef _EMULATOR
void __RamRomInit(int key, void *romaddr);
void __RamRomDestroy(int key);
#endif /* _EMULATOR */

#endif /* !_RAMROM_H */
