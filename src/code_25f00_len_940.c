#include "common.h"
#include "nu/nusys.h"
#include "nu/nualsgi.h"

extern NUDMAState nuAuDmaState;
extern s32 nuAuDmaNext;

INCLUDE_ASM(s32, "code_25f00_len_940", func_8004AB00);

void nuAuPreNMIFuncSet(NUAuPreNMIFunc func) {
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    nuAuPreNMIFunc = func;
    osSetIntMask(mask);
}

INCLUDE_ASM(s32, "code_25f00_len_940", func_8004AE08);

INCLUDE_ASM(s32, "code_25f00_len_940", nuAuDmaCallBack);

ALDMAproc nuAuDmaNew(NUDMAState **state) {
    if (!nuAuDmaState.initialized) {
        nuAuDmaState.firstFree = &nuAuDmaBuf;
        nuAuDmaState.firstUsed = NULL;
        nuAuDmaState.initialized = TRUE;
    }

    nuAuDmaNext = 0;
    *state = &nuAuDmaState;
    return nuAuDmaCallBack;
}

// Some weird symbol loading shenanigans (addiu vs lw)
#ifdef NON_MATCHING
void nuAuCleanDMABuffers(void) {
    NUDMABuffer* dmaPtr = nuAuDmaState.firstUsed;
    NUDMABuffer* nextPtr;

    while (dmaPtr != NULL) {
        nextPtr = dmaPtr->node.next;
        if (&nuAuDmaState) {

        }

        if (dmaPtr->frameCnt + 1 < nuAuFrameCounter) {
            if (nuAuDmaState.firstUsed == dmaPtr) {
                nuAuDmaState.firstUsed = nextPtr;
            }

            alUnlink(dmaPtr);

            if (nuAuDmaState.firstFree != NULL) {
                alLink(dmaPtr, nuAuDmaState.firstFree);
            } else {
                nuAuDmaState.firstFree = dmaPtr;
                dmaPtr->node.next = NULL;
                dmaPtr->node.prev = NULL;
            }
        }

        dmaPtr = nextPtr;
    }

    nuAuDmaNext = 0;
    nuAuFrameCounter += 1;
}
#else
INCLUDE_ASM(void, "code_25f00_len_940", nuAuCleanDMABuffers);
#endif

INCLUDE_ASM(s32, "code_25f00_len_940", func_8004B328);

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
