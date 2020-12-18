#include "common.h"
#include "nu/nusys.h"
#include "nu/nualsgi.h"
#include "audio.h"

extern NUDMAState nuAuDmaState;

s32 D_80078170 = 0;
NUAuPreNMIFunc nuAuPreNMIFunc = NULL;
s32 nuAuDmaNext = 0;
u32 nuAuFrameCounter = 0;
u8 D_80078180 = 1;
u8 D_80078181 = 1;

INCLUDE_ASM(s32, "code_25f00_len_940", func_8004AB00);

void nuAuPreNMIFuncSet(NUAuPreNMIFunc func) {
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    nuAuPreNMIFunc = func;
    osSetIntMask(mask);
}

INCLUDE_ASM(s32, "code_25f00_len_940", func_8004AE08);

s32 nuAuDmaCallBack(s32 addr, s32 len, void* state);
INCLUDE_ASM(s32, "code_25f00_len_940", nuAuDmaCallBack, s32 addr, s32 len, void* state);

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

    do {
        NUDMAState* state = &nuAuDmaState;
        NUDMABuffer* nextPtr;
        u32* frameCounter;

        while (dmaPtr != NULL) {
            nextPtr = dmaPtr->node.next;
            if ((dmaPtr->frameCnt + 1) < nuAuFrameCounter) {
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

extern u16 D_800A0F50;

INCLUDE_ASM(s32, "code_25f00_len_940", func_8004B328);
// void func_8004B328(s16 arg0, s32 arg1) {
//     s32 temp_s0;
//     s32 temp_hi;

//     switch (arg0) {
//         case 2:
//             D_800A0F50 = func_80056D50();
//             func_80056D34();
//             break;
//         case 1:
//             temp_s0 = D_800A0F50 -  D_800A0F50 * (s32)(0x66666667) * arg1;

//             func_80056D44(temp_s0);
//             if (temp_s0 == 0) {
//                 D_80078180 = 0;
//             }
//             break;
//     }
// }

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
