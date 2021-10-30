#include "common.h"
#include "nu/nusys.h"

extern s32 D_80073DE0;
extern OSViMode D_80095800; // _osViModeNtscLan1 - 0x20?;
extern GameStatus* D_8007417C; // gGameStatusPtr

void gfxRetrace_Callback(s32);
void gfxPreNMI_Callback(void);
void gfx_task_main(void);

void func_80025F70(void) {
    if (osTvType == OS_TV_NTSC) {
        func_8005F0B0();
        func_80066DE0(&D_80095800);
        func_80066E30(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
        func_8005F0B0();
    } else {
        PANIC();
    }

    is_debug_init();
    func_8005F210();
    D_8007417C->contBitPattern = func_8005F2C0();
    func_8002CA00();
    func_802B2000();
    func_802B203C();
    func_8005EF00((NUGfxFunc) gfxRetrace_Callback);
    func_8005EF40(gfxPreNMI_Callback);
    gRandSeed += func_800659D0();
    func_8005F0E0(&gRandSeed);

    while (TRUE) {}
}

INCLUDE_ASM(s32, "1370", gfxRetrace_Callback);

INCLUDE_ASM(s32, "1370", func_80026148);

void gfxPreNMI_Callback(void) {
    D_80073DE0 = 1;
    nuContRmbForceStop();
}
