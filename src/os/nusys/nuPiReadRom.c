#include "common.h"
#include "nu/nusys.h"

void nuPiReadRom(u32 rom_addr, void* buf_ptr, u32 size) {
    OSIoMesg ioMesg;
    OSMesg mesg;
    OSMesgQueue queue;
    u32 mesgSize;

    osCreateMesgQueue(&queue, &mesg, 1);

    ioMesg.hdr.pri = OS_MESG_PRI_NORMAL;
    ioMesg.hdr.retQueue = &queue;
    osInvalDCache(buf_ptr, size);
    osInvalICache(buf_ptr, size);

    while (size != 0) {
        mesgSize = size;

        if (size > 0x4000) {
            mesgSize = 0x4000;
        }

        ioMesg.dramAddr = buf_ptr;
        ioMesg.devAddr = rom_addr;
        ioMesg.size = mesgSize;

        osEPiStartDma(nuPiCartHandle, &ioMesg, OS_READ);
        osRecvMesg(&queue, &mesg, OS_MESG_BLOCK);

        rom_addr += mesgSize;
        buf_ptr += mesgSize;
        size -= mesgSize;
    }
}
