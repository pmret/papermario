#include "common.h"
#include "nu/nusys.h"

void gfxThread(void);

extern s32 nuContWaitMesgBuf;
extern OSThread D_800B1B90;
extern OSMesg nuGfxMesgBuf[NU_GFX_MESGS];

void nuGfxThreadStart(void) {
    osCreateThread(&D_800B1B90, 4, gfxThread, NULL, &nuContWaitMesgBuf, NU_GFX_THREAD_PRI);
    osStartThread(&D_800B1B90);
}

void gfxThread(void) {
    NUScClient gfxClient;
    NUScMsg* mesgType;

    osCreateMesgQueue(&nuGfxMesgQ, &nuGfxMesgBuf, NU_GFX_MESGS);
    nuScAddClient(&gfxClient, &nuGfxMesgQ, NU_SC_RETRACE_MSG | NU_SC_PRENMI_MSG);

    while (TRUE) {
        osRecvMesg(&nuGfxMesgQ, &mesgType, OS_MESG_BLOCK);

        switch (*mesgType) {
            case NU_SC_RETRACE_MSG:
                if (nuGfxFunc != NULL) {
                    (*nuGfxFunc)(nuGfxTaskSpool);
                }
                break;
            case NU_SC_PRENMI_MSG:
                if (nuGfxPreNMIFunc != NULL) {
                    (*nuGfxPreNMIFunc)();
                }
                break;
        }
    }
}
