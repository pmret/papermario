#include "common.h"
#include "nu/nusys.h"

static s32 contRmbControl(NUContRmbCtl* rmbCtl, u32 contNo) {
    s32 ret = 0;
    u32 cnt;

    switch (rmbCtl->state) {
        case NU_CONT_RMB_STATE_STOPPED:
            break;

        case NU_CONT_RMB_STATE_STOPPING:
            if (rmbCtl->counter != 0) {
                ret = osMotorStop(&nuContPfs[contNo]);
            } else {
                rmbCtl->state = NU_CONT_RMB_STATE_STOPPED;
            }
            rmbCtl->counter--;
            break;

        case NU_CONT_RMB_STATE_RUN:
            if (rmbCtl->frame > 0) {
                rmbCtl->counter += rmbCtl->freq;
                cnt = rmbCtl->counter >> 8;
                rmbCtl->counter &= 0xFF;
                if (cnt > 0) {
                    ret = osMotorStart(&nuContPfs[contNo]);
                } else {
                    ret = osMotorStop(&nuContPfs[contNo]);
                }
            } else {
                ret = osMotorStop(&nuContPfs[contNo]);
                rmbCtl->state = NU_CONT_RMB_STATE_STOPPING;
                rmbCtl->counter = 2;
            }
            rmbCtl->frame--;
            break;

        case NU_CONT_RMB_STATE_FORCESTOP:
            ret = osMotorInit(&nuSiMesgQ, &nuContPfs[contNo], contNo);
            if (ret == 0) {
                osMotorStop(&nuContPfs[contNo]);
            }
            rmbCtl->state = NU_CONT_RMB_STATE_STOPPING;
            rmbCtl->counter = 2;
    }

    return ret;
}

static s32 contRmbRetrace(NUSiCommonMesg* mesg) {
    u32 i;
    NUContRmbCtl* cont;

    for (i = 0; i < NU_CONT_MAXCONTROLLERS; i++) {
        cont = &nuContRmbCtl[i];
        switch (cont->mode) {
            case NU_CONT_RMB_MODE_DISABLE:
                break;

            case NU_CONT_RMB_MODE_ENABLE:
                if (contRmbControl(cont, i)) {
                    cont->mode = NU_CONT_RMB_MODE_DISABLE;
                }
                break;

            case NU_CONT_RMB_MODE_AUTORUN:
                if (cont->autorun == NU_CONT_RMB_AUTO_SEARCH) {
                    if ((cont->counter % nuContRmbSearchTime) == 0) {
                        if (osMotorInit(&nuSiMesgQ, &nuContPfs[i], i) == 0) {
                            cont->autorun = NU_CONT_RMB_AUTO_FIND;
                            cont->type = NU_CONT_PAK_TYPE_RUMBLE;
                        }
                    }
                    cont->counter++;
                } else {
                    if (contRmbControl(cont, i)) {
                        cont->counter = i;
                        cont->autorun = NU_CONT_RMB_AUTO_SEARCH;
                        cont->type = NU_CONT_PAK_TYPE_NONE;
                    }
                }
                break;

            case (NU_CONT_RMB_MODE_ENABLE | NU_CONT_RMB_MODE_PAUSE):
            case (NU_CONT_RMB_MODE_AUTORUN | NU_CONT_RMB_MODE_PAUSE):
                if (cont->type == NU_CONT_PAK_TYPE_RUMBLE) {
                    contRmbControl(cont, i);
                }
        }
    }

    return 0;
}


#ifdef NON_MATCHING
// Will match when data is decompiled.
void nuContRmbMgrInit(void) {
    u32 i;

    for (i = 0; i < NU_CONT_MAXCONTROLLERS; i++) {
        nuContRmbCtl[i].state = NU_CONT_RMB_STATE_STOPPED;
        nuContRmbCtl[i].mode = NU_CONT_RMB_MODE_DISABLE;
        nuContRmbCtl[i].counter = i;
    }

    nuSiCallBackAdd(&nuContRmbCallBack);
}
#else
void INCLUDE_ASM("os/nuContRmbMgr", nuContRmbMgrInit);
#endif

void nuContRmbMgrRemove(void) {
    nuSiCallBackRemove(&nuContRmbCallBack);
}

static s32 contRmbCheckMesg(NUSiCommonMesg* mesg) {
    NUContRmbMesg* rmbMesg = (NUContRmbMesg*) mesg->dataPtr;

    return osMotorInit(&nuSiMesgQ, &nuContPfs[rmbMesg->contNo], rmbMesg->contNo);
}

static s32 contRmbStartMesg(NUSiCommonMesg* mesg) {
    NUContRmbMesg* rmbMesg = (NUContRmbMesg*) mesg->dataPtr;
    NUContRmbCtl* rmbCtl = (NUContRmbCtl*) rmbMesg->data;

    nuContRmbCtl[rmbMesg->contNo].state = rmbCtl->state;
    nuContRmbCtl[rmbMesg->contNo].frame = rmbCtl->frame;
    nuContRmbCtl[rmbMesg->contNo].freq = rmbCtl->freq;
    nuContRmbCtl[rmbMesg->contNo].counter = 0;
    return 0;
}

static s32 contRmbStopMesg(NUSiCommonMesg* mesg) {
    NUContRmbMesg* rmbMesg = (NUContRmbMesg*) mesg->dataPtr;

    nuContRmbCtl[rmbMesg->contNo].frame = 0;

    return 0;
}

static s32 contRmbForceStopMesg(NUSiCommonMesg* mesg) {
    u32 i;

    for (i = 0; i < NU_CONT_MAXCONTROLLERS; i++) {
        nuContRmbCtl[i].state = NU_CONT_RMB_STATE_FORCESTOP;
        nuContRmbCtl[i].mode |= NU_CONT_RMB_MODE_PAUSE;
    }

    return 0;
}

static s32 contRmbForceStopEndMesg(NUSiCommonMesg* mesg) {
    u32 i;

    for (i = 0; i < NU_CONT_MAXCONTROLLERS; i++) {
        nuContRmbCtl[i].mode &= ~NU_CONT_RMB_MODE_PAUSE;
    }

    return 0;
}
