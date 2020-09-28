#include "common.h"
#include "nu/nusys.h"

INCLUDE_ASM(void, "os/code_39db0_len_8a0", nuScCreateScheduler, u8 videoMode, u8 numFields);

INCLUDE_ASM(void, "os/code_39db0_len_8a0", nuScExecuteAudio);

INCLUDE_ASM(void, "os/code_39db0_len_8a0", nuScExecuteGraphics);

INCLUDE_ASM(void, "os/code_39db0_len_8a0", nuScAddClient, NUScClient *c, OSMesgQueue *mq, NUScMsg msgType);

void nuScRemoveClient(NUScClient *client) {
    s32 mask = osSetIntMask(OS_IM_NONE);
    NUScClient *clientList = nusched.clientList;
    NUScClient *prev = NULL;

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
INCLUDE_ASM(OSMesgQueue*, "os/code_39db0_len_8a0", nuScGetGfxMQ, void);
#endif

#ifdef NON_MATCHING
// This should match when data is decompiled.
OSMesgQueue* nuScGetAudioMQ(void) {
    return &nusched.audioRequestMQ;
}
#else
INCLUDE_ASM(OSMesgQueue*, "os/code_39db0_len_8a0", nuScGetAudioMQ, void);
#endif

#ifdef NON_MATCHING
// This should match when data is decompiled.
void nuScSetFrameBufferNum(u8 frameBufferNum) {
    nusched.frameBufferNum = frameBufferNum;
}
#else
INCLUDE_ASM(void, "os/code_39db0_len_8a0", nuScSetFrameBufferNum, u8 frameBufferNum);
#endif

#ifdef NON_MATCHING
// This should match when data is decompiled.
s32 nuScGetFrameRate(void) {
    return nusched.frameRate;
}
#else
(s32, "os/code_39db0_len_8a0", nuScGetFrameRate, void);
#endif

INCLUDE_ASM(void, "os/code_39db0_len_8a0", nuScEventHandler);

static void nuScEventBroadcast(NUScMsg *msg) {
    NUScClient *clientList = nusched.clientList;

    while (clientList != NULL) {
        if (clientList->msgType & *msg) {
            osSendMesg(clientList->msgQ, msg, OS_MESG_NOBLOCK);
        }
        clientList = clientList->next;
    }
}

INCLUDE_ASM(void, "os/code_39db0_len_8a0", nuScWaitTaskReady);
