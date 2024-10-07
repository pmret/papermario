#include "ultra64.h"
#include "PR/os_internal_flash.h"


extern u32 __osBbFlashAddress;
extern u32 __osBbFlashSize;

s32 osFlashReadArray(OSIoMesg* mb, s32 priority, u32 page_num, void* dramAddr, u32 n_pages, OSMesgQueue* mq) {
#ifdef BBPLAYER
    if (__osBbFlashSize != 0 && __osBbFlashSize >= (page_num + n_pages) * 0x80) {
        bcopy((void*)(__osBbFlashAddress + page_num * 0x80), dramAddr, n_pages * 0x80);
        return osSendMesg(mq, NULL, OS_MESG_NOBLOCK);
    } else {
        bzero(dramAddr, n_pages * 0x80);
        return osSendMesg(mq, NULL, OS_MESG_NOBLOCK);
    }
#else
    u32 ret;
    u32 tmp;
    u32 end_page;
    u32 one_dma_pages;

    // select read array mode
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_READ_ARRAY);
    // dummy read?
    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &tmp);

    // DMA requested pages
    mb->hdr.pri = priority;
    mb->hdr.retQueue = mq;
    mb->dramAddr = dramAddr;

    end_page = page_num + n_pages - 1;

    if ((end_page & 0xF00) != (page_num & 0xF00)) {
        one_dma_pages = 256 - (page_num & 0xFF);
        n_pages -= one_dma_pages;
        mb->size = one_dma_pages * FLASH_BLOCK_SIZE;
        mb->devAddr = __osFlashGetAddr(page_num);
        osEPiStartDma(&__osFlashHandler, mb, OS_READ);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        page_num = (page_num + 256) & 0xF00;
        mb->dramAddr = (void*)((u32)mb->dramAddr + mb->size);
    }

    while (n_pages > 256) {
        one_dma_pages = 256;
        n_pages -= 256;
        mb->size = one_dma_pages * FLASH_BLOCK_SIZE;
        mb->devAddr = __osFlashGetAddr(page_num);
        osEPiStartDma(&__osFlashHandler, mb, OS_READ);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        page_num += 256;
        mb->dramAddr = (void*)((u32)mb->dramAddr + mb->size);
    }

    mb->size = n_pages * FLASH_BLOCK_SIZE;
    mb->devAddr = __osFlashGetAddr(page_num);

    ret = osEPiStartDma(&__osFlashHandler, mb, OS_READ);

    return ret;
#endif
}
