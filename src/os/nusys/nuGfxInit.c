#include "common.h"
#include "nu/nusys.h"

extern u16* FrameBuf[3];
extern UNK_PTR D_8009A610;
extern UNK_PTR D_80093BA0;
extern Gfx rdpstateinit_dl[];

void nuGfxInit(void) {
    Gfx gfx[0x100];
    Gfx* ptr;

    nuGfxThreadStart();
    nuGfxSetCfb(FrameBuf, NU_GFX_FRAMEBUFFER_NUM);
    nuGfxSetZBuffer((u16*) NU_GFX_ZBUFFER_ADDR);
    nuGfxSwapCfbFuncSet(nuGfxSwapCfb);
    D_8009A610 = &D_80093BA0;
    nuGfxTaskMgrInit();

    ptr = gfx;
    // TODO: Verify that this macro call works in PM64.
    gSPDisplayList(ptr++, OS_K0_TO_PHYSICAL(&rdpstateinit_dl));
    gDPFullSync(ptr++);
    gSPEndDisplayList(ptr++);

    nuGfxTaskStart(gfx, (s32)(ptr - gfx) * sizeof(Gfx), NU_GFX_UCODE_F3DEX, NU_SC_NOSWAPBUFFER);
    nuGfxTaskAllEndWait();
}
