#include "ultra64.h"
#include "PR/os_flash.h"

// BSS
extern u32 __osFlashID[4];
extern OSIoMesg __osFlashMsg;
extern OSMesgQueue __osFlashMessageQ;
extern OSPiHandle __osFlashHandler;
extern OSMesg __osFlashMsgBuf;
extern s32 __osFlashVersion;

OSPiHandle* osFlashReInit(u8 latency, u8 pulse, u8 page_size, u8 rel_duration, u32 start) {
    __osFlashHandler.baseAddress = PHYS_TO_K1(start);
    __osFlashHandler.type++;
    __osFlashHandler.latency = latency;
    __osFlashHandler.pulse = pulse;
    __osFlashHandler.pageSize = page_size;
    __osFlashHandler.relDuration = rel_duration;
    __osFlashHandler.domain = PI_DOMAIN2;

    return &__osFlashHandler;
}

void osFlashChange(u32 flash_num) {
    __osFlashHandler.baseAddress = PHYS_TO_K1(FLASH_START_ADDR + flash_num * FLASH_SIZE);
    __osFlashHandler.type = DEVICE_TYPE_FLASH + flash_num;
    return;
}

OSPiHandle* osFlashInit(void) {
    u32 flash_type;
    u32 flash_maker;

    osCreateMesgQueue(&__osFlashMessageQ, &__osFlashMsgBuf, 1);

    if (__osFlashHandler.baseAddress == 0xA8000000) {
        return &__osFlashHandler;
    }

    __osFlashHandler.type = DEVICE_TYPE_FLASH;
    __osFlashHandler.baseAddress = 0xA8000000;
    __osFlashHandler.latency = FLASH_LATENCY;
    __osFlashHandler.pulse = FLASH_PULSE;
    __osFlashHandler.pageSize = FLASH_PAGE_SIZE;
    __osFlashHandler.relDuration = FLASH_REL_DURATION;
    __osFlashHandler.domain = PI_DOMAIN2;
    __osFlashHandler.speed = 0;

    bzero((void*)&__osFlashHandler.transferInfo, sizeof(__osFlashHandler.transferInfo));
    osEPiLinkHandle(&__osFlashHandler);
    osFlashReadId(&flash_type, &flash_maker);

    if (flash_maker == FLASH_VERSION_MX_C ||
        flash_maker == FLASH_VERSION_MX_A ||
        flash_maker == FLASH_VERSION_MX_PROTO_A)
    {
        __osFlashVersion = OLD_FLASH;
    } else {
        __osFlashVersion = NEW_FLASH;
    }

    return &__osFlashHandler;
}

void osFlashReadStatus(u8* flash_status) {
    u32 status;

    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | 0x10000, 0xD2000000);
    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | 0x10000, 0xD2000000);
    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    *flash_status = status & 0xFF;
    return;
}

void osFlashReadId(u32* flash_type, u32* flash_maker) {
    u8 temp;

    osFlashReadStatus(&temp);

    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | 0x10000, 0xE1000000);

    __osFlashMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    __osFlashMsg.hdr.retQueue = &__osFlashMessageQ;
    __osFlashMsg.dramAddr = &__osFlashID[0];
    __osFlashMsg.devAddr = 0;
    __osFlashMsg.size = 8;

    osWritebackDCache(&__osFlashID[0], 0x10);
    osEPiStartDma(&__osFlashHandler, &__osFlashMsg, OS_READ);
    osRecvMesg(&__osFlashMessageQ, NULL, OS_MESG_BLOCK);

    *flash_type = __osFlashID[0];
    *flash_maker = __osFlashID[1];
    return;
}

void osFlashClearStatus(void) {
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | 0x10000, 0xD2000000);
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress, 0);
    return;
}

s32 osFlashAllErase(void) {
    u32 status;

    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | 0x10000, 0x3C000000);
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | 0x10000, 0x78000000);

    do {
        osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    } while ((status & 2) == 2);

    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    osFlashClearStatus();

    if ((status & 0xFF) == 8 || (status & 0xFF) == 0x48 || (status & 8) == 8) {
        return 0;
    } else {
        return -1;
    }
}

s32 osFlashSectorErase(u32 page_num) {
    u32 status;

    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | 0x10000, page_num | 0x4B000000);
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | 0x10000, 0x78000000);

    do {
        osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    } while ((status & 2) == 2);

    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    osFlashClearStatus();

    if ((status & 0xFF) == 8 || (status & 0xFF) == 0x48 || (status & 8) == 8) {
        return 0;
    } else {
        return -1;
    }
}

s32 osFlashWriteBuffer(OSIoMesg* mb, s32 priority, void *dramAddr, OSMesgQueue* mq) {
    s32 ret;

    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | 0x10000, 0xB4000000);
    mb->hdr.pri = priority;
    mb->hdr.retQueue = mq;
    mb->dramAddr = dramAddr;
    mb->devAddr = 0;
    mb->size = 0x80;
    ret = osEPiStartDma(&__osFlashHandler, mb, OS_WRITE);
    return ret;
}

s32 osFlashWriteArray(u32 page_num) {
    u32 status;

    if (__osFlashVersion == NEW_FLASH) {
        osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | 0x10000, 0xB4000000);
    }

    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | 0x10000, page_num | 0xA5000000);

    do {
        osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    } while ((status & 1) == 1);

    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    osFlashClearStatus();

    if ((status & 0xFF) == 4 || (status & 0xFF) == 0x44 || (status & 4) == 4) {
        return 0;
    } else {
        return -1;
    }
}


s32 osFlashReadArray(OSIoMesg* mb, s32 priority, u32 page_num, void* dramAddr, u32 n_pages, OSMesgQueue* mq) {
    s32 ret;
    u32 sp18;

    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | 0x10000, 0xF0000000);
    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &sp18);
    mb->hdr.pri = priority;
    mb->hdr.retQueue = mq;
    mb->dramAddr = dramAddr;
    mb->size = n_pages * 128;

    if (__osFlashVersion == OLD_FLASH) {
        mb->devAddr = page_num * 64;
    } else {
        mb->devAddr = page_num * 128;
    }

    ret = osEPiStartDma(&__osFlashHandler, mb, OS_READ);
    return ret;
}
