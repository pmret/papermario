#include "common.h"
#include "nu/nusys.h"
#include "nu/nualsgi.h"
#include "audio.h"

s32 D_80078170 = 0;
NUAuPreNMIFunc nuAuPreNMIFunc = NULL;
s32 nuAuDmaNext = 0;
u32 nuAuFrameCounter = 0;
u8 nuAuTaskStop = 1;
u8 D_80078181 = 1;

//bss
//static u16 D_800A0F50;

INCLUDE_ASM(s32, "25f00_len_940", create_audio_system);

void nuAuPreNMIFuncSet(NUAuPreNMIFunc func) {
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    nuAuPreNMIFunc = func;
    osSetIntMask(mask);
}

INCLUDE_ASM(s32, "25f00_len_940", func_8004AE08);

extern OSMesgQueue* D_800A3640;
extern OSIoMesg D_800A3720[];
extern NUDMABuffer* D_800A3BD4;

// s32 nuAuDmaCallBack(s32 addr, s32 len, void* state, s32 arg3);
// WIP
#ifdef NON_MATCHING
s32 nuAuDmaCallBack(s32 addr, s32 len, void *state, u8 arg3) {
    NUDMABuffer *temp_s1;
    NUDMABuffer *temp_a1;
    NUDMABuffer *firstFree;
    OSIoMesg *mesg;
    char *temp_s2;
    s32 temp_s0;
    s32 temp_s3;
    char *new_var;
    s32 startAddr;

    if (arg3 == 0) {
        return osVirtualToPhysical(addr);
    }

    temp_s1 = D_800A3BD4;

    while (temp_s1 != NULL) {
        startAddr = temp_s1->startAddr;

        if (addr >= startAddr) {
            if ((startAddr + 0x500) >= (addr + len)) {
                temp_s1->frameCnt = nuAuFrameCounter;
                return osVirtualToPhysical((temp_s1->ptr + addr) - temp_s1->startAddr);
            }

        } else {
            break;
        }

        temp_s1 = temp_s1->node.next;
    }

    firstFree = nuAuDmaState.firstFree;
    if (firstFree == NULL) {
        return osVirtualToPhysical(nuAuDmaState.firstUsed);
    }

    new_var = firstFree->ptr;
    nuAuDmaState.firstFree = firstFree;
    alUnlink(&firstFree->node);

    if (temp_s1 != NULL) {
        alLink(&firstFree->node, temp_s1);
    } else {
        temp_a1 = nuAuDmaState.firstUsed;
        if (temp_a1 != NULL) {
            nuAuDmaState.firstUsed = firstFree;
            firstFree->node.next = &temp_a1->node;
            firstFree->node.prev = NULL;
            temp_a1->node.prev = &firstFree->node;
        } else {
            nuAuDmaState.firstUsed = firstFree;
            firstFree->node.next = NULL;
            firstFree->node.prev = NULL;
        }
    }

    temp_s0 = addr & 1;
    temp_s3 = addr - temp_s0;
    temp_s2 = new_var;
    firstFree->startAddr = temp_s3;
    mesg = &D_800A3720[nuAuDmaNext];
    nuAuDmaNext++;
    firstFree->frameCnt = nuAuFrameCounter;
    mesg->hdr.pri = 0;
    mesg->hdr.retQueue = &D_800A3640;
    mesg->dramAddr = temp_s2;
    mesg->devAddr = temp_s3;
    mesg->size = 0x500;
    osEPiStartDma(carthandle, mesg, 0);
    return osVirtualToPhysical(temp_s2) + temp_s0;
}
#else
INCLUDE_ASM(s32, "25f00_len_940", nuAuDmaCallBack, s32 addr, s32 len, void* state, s32 arg3);
#endif

ALDMAproc nuAuDmaNew(NUDMAState** state) {
    if (!nuAuDmaState.initialized) {
        nuAuDmaState.firstFree = &nuAuDmaBuf;
        nuAuDmaState.firstUsed = NULL;
        nuAuDmaState.initialized = TRUE;
    }

    nuAuDmaNext = 0;
    *state = &nuAuDmaState;
    return nuAuDmaCallBack;
}

void nuAuCleanDMABuffers(void) {
    NUDMAState* state = &nuAuDmaState;
    NUDMABuffer* dmaPtr = state->firstUsed;

    // A bit odd, this
    do {
        NUDMAState* state = &nuAuDmaState;
        NUDMABuffer* nextPtr;
        u32* frameCounter;

        while (dmaPtr != NULL) {
            nextPtr = dmaPtr->node.next;

            if (dmaPtr->frameCnt + 1 < nuAuFrameCounter) {
                if (state->firstUsed == dmaPtr) {
                    state->firstUsed = nextPtr;
                }

                alUnlink(dmaPtr);

                if (state->firstFree != 0) {
                    alLink(dmaPtr, state->firstFree);
                } else {
                    state->firstFree = dmaPtr;
                    dmaPtr->node.next = 0;
                    dmaPtr->node.prev = 0;
                }
            }

            dmaPtr = nextPtr;
        }

        nuAuDmaNext = 0;
        frameCounter = &nuAuFrameCounter;
        *frameCounter += 1;
    } while (0);
}

// Nop issue
// try again when bss is figured out up until this file
#ifdef NON_MATCHING
void func_8004B328(s16 arg0, s32 arg1) {
    s16 temp_a0_2;
    s32 temp_s0;

    switch (arg0) {
        case 2:
            D_800A0F50 = func_80056D50();
            func_80056D34();
            break;
        case 1:
            temp_a0_2 = D_800A0F50;
            temp_s0 = temp_a0_2 - (temp_a0_2 / 20) * arg1;

            if (temp_s0 < 0) {
                temp_s0 = 0;
            }

            temp_s0 = (temp_s0 * temp_s0) >> 15;
            func_80056D44(temp_s0);

            if (temp_s0 == 0) {
                nuAuTaskStop = 0;
            }
            break;
    }
}
#else
INCLUDE_ASM(s32, "25f00_len_940", func_8004B328);
#endif

void alLink(ALLink* element, ALLink* after) {
    element->next = after->next;
    element->prev = after;

    if (after->next != NULL) {
        after->next->prev = element;
    }
    after->next = element;
}

void alUnlink(ALLink* element) {
    if (element->next != NULL) {
        element->next->prev = element->prev;
    }

    if (element->prev != NULL) {
        element->prev->next = element->next;
    }
}
