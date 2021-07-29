#include "common.h"
#include "nu/nusys.h"

u32 nuGfxCfbNum = 1;
NUGfxSwapCfbFunc nuGfxSwapCfbFunc = NULL;
NUGfxTaskEndFunc nuGfxTaskEndFunc = NULL;
u16 beforeFlag = 0;

extern OSMesg D_8009E6D0[NU_GFX_TASKMGR_MESGS];
extern OSMesgQueue D_800DAC90;
extern NUScTask* nuGfxTask_ptr;
extern s16 taskDoneMsg;
extern s16 swapBufMsg;
extern OSThread GfxTaskMgrThread;
extern NUScTask nuGfxTask[NU_GFX_TASK_NUM];
extern s32 D_800DA040;
extern s32 D_800B91D0;
extern s32 D_800D91D0;
extern void D_800D9780;
extern u32 nuGfxCfbCounter;
extern OSMesgQueue D_800DA47C;

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

void nuGfxTaskMgrInit(void) {
    u32 i;

    taskDoneMsg = NU_SC_GTASKEND_MSG;
    swapBufMsg = NU_SC_SWAPBUFFER_MSG;
    nuGfxTaskSpool = 0;
    nuGfxDisplayOff();
    osCreateThread(&GfxTaskMgrThread, NU_GFX_TASKMGR_THREAD_ID, nuGfxTaskMgr, NULL, &D_8009E6D0, NU_GFX_TASKMGR_THREAD_PRI);
    osStartThread(&GfxTaskMgrThread);

    for (i = 0; i < NU_GFX_TASK_NUM; i++) {
        nuGfxTask[i].next = &nuGfxTask[i + 1];
        nuGfxTask[i].msgQ = &D_800DAC90;
        nuGfxTask[i].list.t.type = M_GFXTASK;
        nuGfxTask[i].list.t.flags = 0;
        dma_copy((u8* )0xB0000B70, (u8* )0xB0000C70, &D_800D9780);
        nuGfxTask[i].list.t.ucode_boot = &D_800D9780;
        nuGfxTask[i].list.t.ucode_boot_size = 0x100;
        nuGfxTask[i].list.t.ucode_size = SP_UCODE_SIZE;
        nuGfxTask[i].list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
        nuGfxTask[i].list.t.dram_stack = &D_800DA040;
        nuGfxTask[i].list.t.dram_stack_size = SP_DRAM_STACK_SIZE8;
        nuGfxTask[i].list.t.output_buff = &D_800B91D0;
        nuGfxTask[i].list.t.output_buff_size = &D_800D91D0;
        nuGfxTask[i].list.t.yield_data_ptr = &nuYieldBuf;
        nuGfxTask[i].list.t.yield_data_size = NU_GFX_YIELD_BUF_SIZE;
    }

    nuGfxTask[NU_GFX_TASK_NUM - 1].next = &nuGfxTask[0];
    nuGfxTask_ptr = &nuGfxTask[0];
}

void nuGfxTaskStart(Gfx* gfxList_ptr, u32 gfxListSize, u32 ucode, u32 flag) {
    u32 mask;

    nuGfxTask_ptr->list.t.data_ptr = (u64*) gfxList_ptr;
    nuGfxTask_ptr->list.t.data_size = gfxListSize;
    nuGfxTask_ptr->list.t.flags = flag >> 16;
    nuGfxTask_ptr->list.t.ucode = nuGfxUcode[ucode].ucode;
    nuGfxTask_ptr->list.t.ucode_data = nuGfxUcode[ucode].ucode_data;
    nuGfxTask_ptr->flags = flag & 0xFFFF;
    nuGfxTask_ptr->framebuffer = nuGfxCfb_ptr;

    if (beforeFlag & NU_SC_UCODE_XBUS) {
        beforeFlag ^= NU_SC_UCODE_XBUS;
        nuGfxTask_ptr->list.t.flags |= OS_TASK_DP_WAIT;
    }

    beforeFlag = flag;

    if (flag & NU_SC_SWAPBUFFER) {
        nuGfxTask_ptr->msg = (void*) &swapBufMsg;
        nuGfxCfbCounter = (nuGfxCfbCounter + 1) % nuGfxCfbNum;
        nuGfxCfb_ptr = D_8009A658[nuGfxCfbCounter];
    } else {
        nuGfxTask_ptr->msg = (void*) &taskDoneMsg;
    }

    mask = osSetIntMask(OS_IM_NONE);
    nuGfxTaskSpool++;
    osSetIntMask(mask);
    osWritebackDCacheAll();
    osSendMesg(&D_800DA47C, (void*) nuGfxTask_ptr, OS_MESG_BLOCK);
    nuGfxTask_ptr = nuGfxTask_ptr->next;
}
