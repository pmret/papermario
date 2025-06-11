#include "common.h"
#include "nu/nusys.h"

NUGfxFunc nuGfxFunc = NULL;
NUGfxPreNMIFunc nuGfxPreNMIFunc = NULL;
OSMesgQueue	nuGfxMesgQ;
static OSMesg nuGfxMesgBuf[NU_GFX_MESGS];
static char GfxStack[NU_GFX_STACK_SIZE];

OSThread D_800B1B90;

static void gfxThread(void* data) {
    NUScClient gfxClient;
    NUScMsg* mesgType;

    osCreateMesgQueue(&nuGfxMesgQ, nuGfxMesgBuf, NU_GFX_MESGS);
    nuScAddClient(&gfxClient, &nuGfxMesgQ, NU_SC_RETRACE_MSG | NU_SC_PRENMI_MSG);

    while (TRUE) {
        osRecvMesg(&nuGfxMesgQ, (OSMesg*) &mesgType, OS_MESG_BLOCK);

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

void nuGfxThreadStart(void) {
    osCreateThread(&D_800B1B90, NU_GFX_THREAD_ID, gfxThread, NULL, &GfxStack[NU_GFX_STACK_SIZE], NU_GFX_THREAD_PRI);
    osStartThread(&D_800B1B90);
}
