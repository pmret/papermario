#include "common.h"
#include "nu/nusys.h"

NUCallBackList* nuSiCallBackList = NULL;

extern OSMesg nuSiMesgBuf[8];
extern OSThread siMgrThread;
extern s32 D_800A08C0;

static void nuSiMgrThread(void* arg);

u8 nuSiMgrInit(void) {
    u8 pattern;
    OSContStatus status[NU_CONT_MAXCONTROLLERS];
    u32 i;

    osCreateMesgQueue(&nuSiMesgQ, &nuSiMesgBuf, ARRAY_COUNT(nuSiMesgBuf));
    osSetEventMesg(OS_EVENT_SI, &nuSiMesgQ, NULL);
    osContInit(&nuSiMesgQ, &pattern, &status[0]);

    for (i = 0; i < ARRAY_COUNT(status); i++) {
        if (((pattern >> i) & 1) && (status[i].errno == 0) && ((status[i].type & 0x1F07) != 5)) {
            pattern &= ~(1 << i);
        }
    }

    osCreateThread(&siMgrThread, NU_SI_THREAD_ID, nuSiMgrThread, NULL, &D_800A08C0, NU_SI_THREAD_PRI);
    osStartThread(&siMgrThread);
    return pattern;
}

s32 nuSiSendMesg(NUScMsg mesg, void* dataPtr) {
    OSMesg rtnMesgBuf;
    OSMesgQueue rtnMesgQ;
    NUSiCommonMesg siCommonMesg;

    siCommonMesg.mesg = mesg;
    siCommonMesg.dataPtr = dataPtr;
    siCommonMesg.rtnMesgQ = &rtnMesgQ;

    osCreateMesgQueue(&rtnMesgQ, &rtnMesgBuf, 1);

    osSendMesg(&nuSiMgrMesgQ, &siCommonMesg, OS_MESG_BLOCK);
    osRecvMesg(&rtnMesgQ, NULL, OS_MESG_BLOCK);

    return siCommonMesg.error;
}

void nuSiMgrStop(void) {
    nuSiSendMesg(NU_SI_STOP_MGR_MSG, NULL);
}

void nuSiMgrRestart(void) {
    osStartThread(&siMgrThread);
}

void nuSiMgrThread(void* arg) {
    NUScClient siClient;
    OSMesg siMgrMesgBuf[NU_SI_MESG_MAX];
    NUSiCommonMesg* siMesg;
    NUCallBackList** siCallBackListPtr;
    s32 temp;
    u16 majorNo;
    u16 minorNo;

    osCreateMesgQueue(&nuSiMgrMesgQ, &siMgrMesgBuf, NU_SI_MESG_MAX);
    nuScAddClient(&siClient, &nuSiMgrMesgQ, NU_SC_RETRACE_MSG);

    while (TRUE) {
        osRecvMesg(&nuSiMgrMesgQ, &siMesg, OS_MESG_BLOCK);

        siCallBackListPtr = &nuSiCallBackList;

        switch (siMesg->mesg) {
            case NU_SC_RETRACE_MSG:
                while (*siCallBackListPtr) {
                    if ((*siCallBackListPtr)->func[0]){
                        temp = (*((*siCallBackListPtr)->func[0]))(siMesg);
                    }
                    if (temp != 0) {
                        break;
                    }
                    siCallBackListPtr = &(*siCallBackListPtr)->next;
                }
                break;
            case NU_SI_STOP_MGR_MSG:
                osSendMesg(siMesg->rtnMesgQ, NULL, OS_MESG_BLOCK);
                nuScResetClientMesgType(&siClient, 0);
                osStopThread(NULL);
                nuScResetClientMesgType(&siClient, NU_SC_RETRACE_MSG);
                break;
            default:
                majorNo = siMesg->mesg & NU_SI_MSG_MAJOR_NO_MASK;
                minorNo = siMesg->mesg & NU_SI_MSG_MINOR_NO_MASK;

                while (*siCallBackListPtr) {
                    if ((*siCallBackListPtr)->majorNo == majorNo) {
                        if ((*siCallBackListPtr)->funcNum > minorNo) {
                            siMesg->error = (*((*siCallBackListPtr)->func[minorNo]))(siMesg);
                        }
                        if (siMesg->rtnMesgQ != NULL) {
                            osSendMesg(siMesg->rtnMesgQ, NULL, OS_MESG_BLOCK);
                        }
                        break;
                    }
                    siCallBackListPtr = &(*siCallBackListPtr)->next;
                }
                break;
        }
    }
}
