#include "ultra64.h"
#include "PR/os_internal_flash.h"
#include "macros.h"

u32 __osFlashID[4] ALIGNED(8);
OSIoMesg __osFlashMsg ALIGNED(8);
OSMesgQueue __osFlashMessageQ ALIGNED(8);
OSPiHandle __osFlashHandler ALIGNED(8);
OSMesg __osFlashMsgBuf[1];
s32 __osFlashVersion;

OSPiHandle* osFlashInit(void) {
#ifndef BBPLAYER
    u32 flash_type;
    u32 flash_maker;
#endif

    osCreateMesgQueue(&__osFlashMessageQ, __osFlashMsgBuf, ARRAY_COUNT(__osFlashMsgBuf));

    if (__osFlashHandler.baseAddress == PHYS_TO_K1(FLASH_START_ADDR)) {
        return &__osFlashHandler;
    }

    __osFlashHandler.type = DEVICE_TYPE_FLASH;
    __osFlashHandler.baseAddress = PHYS_TO_K1(FLASH_START_ADDR);
    __osFlashHandler.latency = FLASH_LATENCY;
    __osFlashHandler.pulse = FLASH_PULSE;
    __osFlashHandler.pageSize = FLASH_PAGE_SIZE;
    __osFlashHandler.relDuration = FLASH_REL_DURATION;
    __osFlashHandler.domain = PI_DOMAIN2;
    __osFlashHandler.speed = 0;

    bzero(&__osFlashHandler.transferInfo, sizeof(__OSTranxInfo));

    osEPiLinkHandle(&__osFlashHandler);

#ifndef BBPLAYER
    osFlashReadId(&flash_type, &flash_maker);

    if (flash_maker == FLASH_VERSION_MX_C || flash_maker == FLASH_VERSION_MX_A ||
        flash_maker == FLASH_VERSION_MX_PROTO_A) {
        __osFlashVersion = OLD_FLASH;
    } else {
        __osFlashVersion = NEW_FLASH;
    }
#else
    __osFlashVersion = NEW_FLASH;
#endif

    return &__osFlashHandler;
}
