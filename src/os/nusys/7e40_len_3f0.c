#include "common.h"
#include "nu/nusys.h"

s32 D_800773F0 = 1;
NUGfxSwapCfbFunc nuGfxSwapCfbFunc = NULL;
NUGfxTaskEndFunc nuGfxTaskEndFunc = NULL;
s32 D_800773FC = 0;

extern OSMesg D_8009E6D0[NU_GFX_TASKMGR_MESGS];
extern OSMesgQueue D_800DAC90;

void nuGfxTaskMgr(void) {
    NUScTask* task;
    s16* msg;
    OSIntMask mask;

    osCreateMesgQueue(&D_800DAC90, &D_8009E6D0[0], NU_GFX_MESGS);

    while (TRUE) {
        osRecvMesg(&D_800DAC90, (OSMesg*)&task, OS_MESG_BLOCK);
        msg = task->msg;

        switch (*msg) {
            case NU_SC_SWAPBUFFER_MSG:
                if (nuGfxSwapCfbFunc != NULL) {
                    nuGfxSwapCfbFunc(task);
                }
                if (nuGfxDisplay & NU_GFX_DISPLAY_ON_TRIGGER) {
                    osViBlack(FALSE);
                    nuGfxDisplay = NU_GFX_DISPLAY_ON;
                }
                mask = osSetIntMask(OS_IM_NONE);
                nuGfxTaskSpool--;
                osSetIntMask(mask);
                break;
            case NU_SC_GTASKEND_MSG:
                if (nuGfxTaskEndFunc != NULL) {
                    nuGfxTaskEndFunc(task);
                }
                mask = osSetIntMask(OS_IM_NONE);
                nuGfxTaskSpool--;
                osSetIntMask(mask);
                break;
        }
    }
}

INCLUDE_ASM(void, "os/nusys/7e40_len_3f0", nuGfxTaskMgrInit);

INCLUDE_ASM(void, "os/nusys/7e40_len_3f0", nuGfxTaskStart);
