#ifndef _OS_INTERNAL_FLASH_H_
#define	_OS_INTERNAL_FLASH_H_

#include "os_message.h"
#include "os_flash.h"

#define FLASH_BLOCK_SIZE 128

/**
 * Flash commands
 */
#define FLASH_CMD_REG   0x10000

/* set whole chip erase mode */
#define FLASH_CMD_CHIP_ERASE    0x3C000000
/* set sector erase mode */
#define FLASH_CMD_SECTOR_ERASE  0x4B000000
/* do erasure */
#define FLASH_CMD_EXECUTE_ERASE 0x78000000
/* program selected page */
#define FLASH_CMD_PROGRAM_PAGE  0xA5000000
/* set page program mode */
#define FLASH_CMD_PAGE_PROGRAM  0xB4000000
/* set status mode */
#define FLASH_CMD_STATUS        0xD2000000
/* set silicon id mode */
#define FLASH_CMD_ID            0xE1000000
/* set read mode */
#define FLASH_CMD_READ_ARRAY    0xF0000000

extern OSIoMesg __osFlashMsg;
extern OSMesgQueue __osFlashMessageQ;
extern OSPiHandle __osFlashHandler;
extern OSMesg __osFlashMsgBuf[1];
extern s32 __osFlashVersion;
extern u32 __osFlashID[4];

u32 __osFlashGetAddr(u32 page_num);

#endif
