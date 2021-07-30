#include "common.h"
#include "nu/nusys.h"

// INCLUDE_ASM(void, "os/nusys/3B4A0", nuPiReadRomOverlay, NUPiOverlaySegment* segment);

void nuPiReadRomOverlay(NUPiOverlaySegment* segment) {
    OSIoMesg dmaIoMesgBuf;
    OSMesgQueue dmaMesgQ;
    OSMesg dmaMesgBuf;
    u32 readSize;
    u8* romAddr;
    u32 size;
    s32 clearBSS = TRUE;
    void* bufPtr;

    osCreateMesgQueue(&dmaMesgQ, &dmaMesgBuf, 1);
    dmaIoMesgBuf.hdr.pri = OS_MESG_PRI_NORMAL;
    dmaIoMesgBuf.hdr.retQueue = &dmaMesgQ;

    osInvalDCache(segment->dataStart, segment->dataEnd - segment->dataStart);
    osInvalICache(segment->textStart, segment->textEnd - segment->textStart);

    romAddr = segment->romStart;
    size = segment->romEnd - romAddr;
    bufPtr = segment->ramStart;

    while (size != 0) {
        if (size > NU_PI_CART_BLOCK_READ_SIZE) {
            readSize = NU_PI_CART_BLOCK_READ_SIZE;
        } else {
            readSize = size;
        }

        dmaIoMesgBuf.dramAddr = bufPtr;
        dmaIoMesgBuf.devAddr = romAddr;
        dmaIoMesgBuf.size = readSize;

        osEPiStartDma(nuPiCartHandle, &dmaIoMesgBuf, OS_READ);

        if (clearBSS) {
            bzero(segment->bssStart, segment->bssEnd - segment->bssStart);
            clearBSS = FALSE;
        }

        osRecvMesg(&dmaMesgQ, &dmaMesgBuf, OS_MESG_BLOCK);
        romAddr += readSize;
        bufPtr = (void*)((u8*)bufPtr + readSize);
        size -= readSize;
    }
}
