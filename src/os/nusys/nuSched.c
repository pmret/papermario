#include "common.h"
#include "nu/nusys.h"

void nuScEventHandler(void);
void nuScExecuteAudio(void);
void nuScExecuteGraphics(void);

extern u8 D_8009A5B0;

extern u64 nuScStack[NU_SC_STACK_SIZE / sizeof(u64)];
extern u64 nuScAudioStack[NU_SC_STACK_SIZE / sizeof(u64)];
extern u64 nuScGraphicsStack[NU_SC_STACK_SIZE / sizeof(u64)];

void nuScCreateScheduler(u8 videoMode, u8 numFields) {
    nusched.curGraphicsTask =       NULL;
    nusched.curAudioTask =          NULL;
    nusched.graphicsTaskSuspended = NULL;
    nusched.clientList =            NULL;

    nusched.retraceMsg =     NU_SC_RETRACE_MSG;
    nusched.prenmiMsg =      NU_SC_PRENMI_MSG;
    nusched.retraceCount =   numFields;
    nusched.frameBufferNum = 2;

    if (osTvType == OS_TV_PAL) {
        nusched.frameRate = 50;
    } else {
        nusched.frameRate = 60;
    }

    D_8009A5B0 = 0;

    osCreateMesgQueue(&nusched.retraceMQ,         nusched.retraceMsgBuf,      NU_SC_MAX_MESGS);
    osCreateMesgQueue(&nusched.rspMQ,             nusched.rspMsgBuf,          NU_SC_MAX_MESGS);
    osCreateMesgQueue(&nusched.rdpMQ,             nusched.rdpMsgBuf,          NU_SC_MAX_MESGS);
    osCreateMesgQueue(&nusched.graphicsRequestMQ, nusched.graphicsRequestBuf, NU_SC_MAX_MESGS);
    osCreateMesgQueue(&nusched.audioRequestMQ,    nusched.audioRequestBuf,    NU_SC_MAX_MESGS);
    osCreateMesgQueue(&nusched.waitMQ,            nusched.waitMsgBuf,         NU_SC_MAX_MESGS);

    osCreateViManager(0xFE);
    osViSetMode(&osViModeTable[videoMode]);
    osViBlack(TRUE);
    osViSetEvent(&nusched.retraceMQ, (OSMesg) 0x29A, numFields);

    osSetEventMesg(OS_EVENT_SP,     &nusched.rspMQ, (OSMesg) 0x29B);
    osSetEventMesg(OS_EVENT_DP,     &nusched.rdpMQ, (OSMesg) 0x29C);
    osSetEventMesg(OS_EVENT_PRENMI, &nusched.retraceMQ, (OSMesg) 0x29D);

    osCreateThread(&nusched.schedulerThread, 19, (void(*)) nuScEventHandler,    &nusched,
                   nuScStack + NU_SC_STACK_SIZE / sizeof(u64),         NU_SC_HANDLER_PRI);
    osStartThread(&nusched.schedulerThread);

    osCreateThread(&nusched.audioThread,     18, (void(*)) nuScExecuteAudio,    &nusched,
                   nuScAudioStack + NU_SC_STACK_SIZE / sizeof(u64),    NU_SC_AUDIO_PRI);
    osStartThread(&nusched.audioThread);

    osCreateThread(&nusched.graphicsThread,  17, (void(*)) nuScExecuteGraphics, &nusched,
                   nuScGraphicsStack + NU_SC_STACK_SIZE / sizeof(u64), NU_SC_GRAPHICS_PRI);
    osStartThread(&nusched.graphicsThread);
}

INCLUDE_ASM(void, "os/nusys/nuSched", nuScExecuteAudio);

INCLUDE_ASM(void, "os/nusys/nuSched", nuScExecuteGraphics);

void nuScAddClient(NUScClient* c, OSMesgQueue* mq, NUScMsg msgType) {
    s32 mask;

    mask = osSetIntMask(OS_IM_NONE);

    c->msgQ = mq;
    c->next = nusched.clientList;
    c->msgType = msgType;

    nusched.clientList = c;

    if ((msgType & NU_SC_PRENMI_MSG) && D_8009A5B0) {
        osSendMesg(mq, &nusched.prenmiMsg, OS_MESG_NOBLOCK);
    }

    osSetIntMask(mask);
}

void nuScRemoveClient(NUScClient* client) {
    s32 mask = osSetIntMask(OS_IM_NONE);
    NUScClient* clientList = nusched.clientList;
    NUScClient* prev = NULL;

    while (clientList != NULL) {
        if (clientList == client) {
            if (prev != NULL) {
                prev->next = clientList->next;
            } else {
                nusched.clientList = clientList->next;
            }
            break;
        }
        prev = clientList;
        clientList = clientList->next;
    }

    osSetIntMask(mask);
}

void nuScResetClientMesgType(NUScClient* client, NUScMsg msgType) {
    s32 mask;

    mask = osSetIntMask(OS_IM_NONE);
    client->msgType = msgType;
    osSetIntMask(mask);
}

#ifdef NON_MATCHING
// This should match when data is decompiled.
OSMesgQueue* nuScGetGfxMQ(void) {
    return &nusched.graphicsRequestMQ;
}
#else
INCLUDE_ASM(OSMesgQueue*, "os/nusys/nuSched", nuScGetGfxMQ, void);
#endif

#ifdef NON_MATCHING
// This should match when data is decompiled.
OSMesgQueue* nuScGetAudioMQ(void) {
    return &nusched.audioRequestMQ;
}
#else
INCLUDE_ASM(OSMesgQueue*, "os/nusys/nuSched", nuScGetAudioMQ, void);
#endif

#ifdef NON_MATCHING
// This should match when data is decompiled.
void nuScSetFrameBufferNum(u8 frameBufferNum) {
    nusched.frameBufferNum = frameBufferNum;
}
#else
INCLUDE_ASM(void, "os/nusys/nuSched", nuScSetFrameBufferNum, u8 frameBufferNum);
#endif

#ifdef NON_MATCHING
// This should match when data is decompiled.
s32 nuScGetFrameRate(void) {
    return nusched.frameRate;
}
#else
INCLUDE_ASM(s32, "os/nusys/nuSched", nuScGetFrameRate, void);
#endif

INCLUDE_ASM(void, "os/nusys/nuSched", nuScEventHandler);

static void nuScEventBroadcast(NUScMsg* msg) {
    NUScClient* clientList = nusched.clientList;

    while (clientList != NULL) {
        if (clientList->msgType & *msg) {
            osSendMesg(clientList->msgQ, msg, OS_MESG_NOBLOCK);
        }
        clientList = clientList->next;
    }
}

INCLUDE_ASM(void, "os/nusys/nuSched", nuScWaitTaskReady);
