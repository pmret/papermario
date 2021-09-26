/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo.

        $RCSfile: os_flash.h,v $
        $Revision: 1.1 $
        $Date: 2000/06/15 06:24:55 $
 *---------------------------------------------------------------------*/

#ifndef _OS_FLASH_H_
#define	_OS_FLASH_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/*
 * defines for FLASH
 */
#define FLASH_START_ADDR	0x08000000

#define FLASH_SIZE		0x20000
#define FLASH_LATENCY		0x5
#define FLASH_PULSE		0x0c
#define FLASH_PAGE_SIZE		0xf
#define FLASH_REL_DURATION	0x2
#define DEVICE_TYPE_FLASH	8

#define FLASH_VERSION_MX_PROTO_A	0x00c20000
#define FLASH_VERSION_MX_A		0x00c20001
#define FLASH_VERSION_MX_C		0x00c2001e
#define FLASH_VERSION_MX_B_AND_D	0x00c2001d
#define FLASH_VERSION_MEI		0x003200f1

#define OLD_FLASH			0
#define NEW_FLASH			1
/* OLD_FLASH is MX_PROTO_A, MX_A and MX_C */
/* NEW_FLASH is MX_B_AND_D and MATSUSHITA flash */

#define FLASH_STATUS_ERASE_BUSY		2
#define	FLASH_STATUS_ERASE_ERROR	-1
#define FLASH_STATUS_ERASE_OK		0

extern OSPiHandle *osFlashReInit(u8 latency, u8 pulse,
				 u8 page_size, u8 rel_duration, u32 start);
extern OSPiHandle *osFlashInit(void);
extern void    osFlashReadStatus(u8 *flash_status);
extern void    osFlashReadId(u32 *flash_type, u32 *flash_maker);
extern void    osFlashClearStatus(void);
extern s32     osFlashAllErase(void);
extern s32     osFlashSectorErase(u32 page_num);
extern s32     osFlashWriteBuffer(OSIoMesg *mb, s32 priority,
				void *dramAddr, OSMesgQueue *mq);
extern s32     osFlashWriteArray(u32 page_num);
extern s32     osFlashReadArray(OSIoMesg *mb, s32 priority, u32 page_num,
				void *dramAddr, u32 n_pages, OSMesgQueue *mq);
extern void    osFlashChange(u32 flash_num);
extern void    osFlashAllEraseThrough(void);
extern void    osFlashSectorEraseThrough(u32 page_num);
extern s32     osFlashCheckEraseEnd(void);

#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_FLASH_H_ */
