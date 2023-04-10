#include "common.h"
#include "nu/nusys.h"

NOP_FIX

NUScPreNMIFunc nuScPreNMIFunc = NULL;

char nusys_version[] = "NuSystem2.05";

u32 nuScRetraceCounter = (u32) nusys_version; // wtf?

void nuScEventHandler(void);
void nuScExecuteAudio(void);
void nuScExecuteGraphics(void);
void nuScEventBroadcast(NUScMsg* msg);
void nuScWaitTaskReady(NUScTask* task);

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

    nuScPreNMIFlag = NU_SC_PRENMI_YET;

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

void nuScExecuteAudio(void) {
    NUScTask* gfxTask;
    NUScTask* audioTask;
    OSMesg msg;
    u32 yieldFlag;

    while (TRUE) {
        osRecvMesg(&nusched.audioRequestMQ, (OSMesg *) &audioTask, OS_MESG_BLOCK);
        if (nuScPreNMIFlag & NU_SC_BEFORE_RESET) {
            osSendMesg(audioTask->msgQ, audioTask->msg, OS_MESG_BLOCK);
            continue;
        }

        osWritebackDCacheAll();

        yieldFlag = 0;
        gfxTask = nusched.curGraphicsTask;

        if (gfxTask != NULL) {
            osSpTaskYield();
            osRecvMesg(&nusched.rspMQ, &msg, OS_MESG_BLOCK);

            if (osSpTaskYielded(&gfxTask->list)) {
                yieldFlag = 1;
            } else {
                yieldFlag = 2;
            }
        }

        nusched.curAudioTask = audioTask;
        osSpTaskStart(&audioTask->list);

        osRecvMesg(&nusched.rspMQ, &msg, OS_MESG_BLOCK);
        nusched.curAudioTask = NULL;

        if( nusched.graphicsTaskSuspended )
            osSendMesg(&nusched.waitMQ, &msg, OS_MESG_BLOCK );

        if (yieldFlag == 1) {
            osSpTaskStart(&gfxTask->list);
        } else if (yieldFlag == 2) {
            osSendMesg(&nusched.rspMQ, &msg, OS_MESG_BLOCK);
        }

        osSendMesg(audioTask->msgQ, audioTask->msg, OS_MESG_BLOCK);
    }
}

void nuScExecuteGraphics(void) {
    OSMesg msg;
    NUScTask* gfxTask;
    OSIntMask mask;

    while (TRUE) {
        osRecvMesg(&nusched.graphicsRequestMQ, (OSMesg *) &gfxTask, OS_MESG_BLOCK);
        if(nuScPreNMIFlag & NU_SC_BEFORE_RESET){
            osSendMesg(gfxTask->msgQ, (OSMesg*) gfxTask, OS_MESG_BLOCK);
            continue;
        }

        nuScWaitTaskReady(gfxTask);

        mask = osSetIntMask(OS_IM_NONE);
        if (nusched.curAudioTask) {
            nusched.graphicsTaskSuspended = gfxTask;
            osSetIntMask(mask);
            osRecvMesg(&nusched.waitMQ, &msg, OS_MESG_BLOCK);
            mask = osSetIntMask(OS_IM_NONE);
            nusched.graphicsTaskSuspended = NULL;
        }
        osSetIntMask(mask);

        mask = osSetIntMask(OS_IM_NONE);
        nusched.curGraphicsTask = gfxTask;
        osSetIntMask(mask);

        osSpTaskStart(&gfxTask->list);

        osRecvMesg(&nusched.rspMQ, &msg, OS_MESG_BLOCK);

        mask = osSetIntMask(OS_IM_NONE);
        nusched.curGraphicsTask = NULL;
        osSetIntMask(mask);

        if (!(gfxTask->flags & NU_SC_NORDP)) {
            osRecvMesg(&nusched.rdpMQ, &msg, OS_MESG_BLOCK);
        }
        osSendMesg(gfxTask->msgQ, (OSMesg*) gfxTask, OS_MESG_BLOCK);
    }
}

void nuScAddClient(NUScClient* c, OSMesgQueue* mq, NUScMsg msgType) {
    s32 mask;

    mask = osSetIntMask(OS_IM_NONE);

    c->msgQ = mq;
    c->next = nusched.clientList;
    c->msgType = msgType;

    nusched.clientList = c;

    if ((msgType & NU_SC_PRENMI_MSG) && nuScPreNMIFlag) {
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

OSMesgQueue* nuScGetGfxMQ(void) {
    return &nusched.graphicsRequestMQ;
}

OSMesgQueue* nuScGetAudioMQ(void) {
    return &nusched.audioRequestMQ;
}

void nuScSetFrameBufferNum(u8 frameBufferNum) {
    nusched.frameBufferNum = frameBufferNum;
}

s32 nuScGetFrameRate(void) {
    return nusched.frameRate;
}

void nuScEventHandler(void) {
    OSMesg  msg;
    s32     beforeResetFrame;

    nuScRetraceCounter = 0;

    while (TRUE) {
        osRecvMesg(&nusched.retraceMQ, &msg, OS_MESG_BLOCK);

        switch ((s32) msg) {
            case 666:
                nuScRetraceCounter++;

                nuScEventBroadcast(&nusched.retraceMsg);

                if (nuScPreNMIFlag){
                    if (beforeResetFrame){
                        beforeResetFrame--;
                    } else {
                        nuScPreNMIFlag |= NU_SC_BEFORE_RESET;
                        osAfterPreNMI();
                        osViSetYScale(1.0);
                        osViBlack(TRUE);
                    }
                }
                break;
            case 669:
                nuScPreNMIFlag = NU_SC_PRENMI_GET;
                nuScEventBroadcast(&nusched.prenmiMsg);

                if (nuScPreNMIFunc != NULL){
                    (*nuScPreNMIFunc)();
                }

                beforeResetFrame = (nusched.frameRate / 2) / nusched.retraceCount - 3;
                break;
            default:
                break;
        }
    }
}

void nuScEventBroadcast(NUScMsg* msg) {
    NUScClient* clientList = nusched.clientList;

    while (clientList != NULL) {
        if (clientList->msgType & *msg) {
            osSendMesg(clientList->msgQ, msg, OS_MESG_NOBLOCK);
        }
        clientList = clientList->next;
    }
}

// copy of nuScAddClient
static inline void nuScAddClient_inline(NUScClient* c, OSMesgQueue* mq, NUScMsg msgType) {
    s32 mask;

    mask = osSetIntMask(OS_IM_NONE);

    c->msgQ = mq;
    c->next = nusched.clientList;
    c->msgType = msgType;

    nusched.clientList = c;

    if ((msgType & NU_SC_PRENMI_MSG) && nuScPreNMIFlag) {
        osSendMesg(mq, &nusched.prenmiMsg, OS_MESG_NOBLOCK);
    }

    osSetIntMask(mask);
}

// copy of nuScRemoveClient
static inline void nuScRemoveClient_inline(NUScClient* client) {
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

// TODO: investigate why nuScAddClient and nuScRemoveClient were inlined
void nuScWaitTaskReady(NUScTask* task) {
    NUScClient client;
    void* fb = task->framebuffer;

    if(nusched.frameBufferNum == 1) {
        return;
    }

    while (osViGetCurrentFramebuffer() == fb || osViGetNextFramebuffer() == fb) {
        nuScAddClient_inline(&client, &nusched.waitMQ, NU_SC_RETRACE_MSG);
        osRecvMesg(&nusched.waitMQ, NULL, OS_MESG_BLOCK);
        nuScRemoveClient_inline(&client);
    }
}
