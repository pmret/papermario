#include "common.h"
#include "nu/nusys.h"

extern u16* FrameBuf[3];
extern UNK_PTR nugfx_ucode;
extern Gfx rdpstateinit_dl[];

void nuGfxInitEX2(void) {
    Gfx gfx[0x100];
    Gfx* ptr;

    nuGfxThreadStart();
    nuGfxSetCfb(FrameBuf, NU_GFX_FRAMEBUFFER_NUM);
    nuGfxSetZBuffer((u16*) NU_GFX_ZBUFFER_ADDR);
    nuGfxSwapCfbFuncSet(nuGfxSwapCfb);
    nuGfxUcode = &nugfx_ucode;
    nuGfxTaskMgrInit();

    ptr = gfx;
    gSPDisplayList(ptr++, OS_K0_TO_PHYSICAL(&rdpstateinit_dl));
    gDPFullSync(ptr++);
    gSPEndDisplayList(ptr++);

    nuGfxTaskStart(gfx, (s32)(ptr - gfx) * sizeof(Gfx), NU_GFX_UCODE_F3DEX, NU_SC_NOSWAPBUFFER);
    nuGfxTaskAllEndWait();
}
