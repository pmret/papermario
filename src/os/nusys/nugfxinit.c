#include "common.h"
#include "nu/nusys.h"

extern u64 gspF3DZEX2_NoN_PosLight_fifoTextStart[];
extern u64 gspF3DZEX2_NoN_PosLight_fifoDataStart[];

NUUcode nugfx_ucode = {
    gspF3DZEX2_NoN_PosLight_fifoTextStart, gspF3DZEX2_NoN_PosLight_fifoDataStart,
};

extern u16 gFrameBuf0[];
extern u16 gFrameBuf1[];
extern u16 gFrameBuf2[];
u16* FrameBuf[] = {
    gFrameBuf0, gFrameBuf1, gFrameBuf2
};

extern s32 D_800B91D0[];

Gfx rdpstateinit_dl[] = {
    gsDPSetEnvColor(0, 0, 0, 0),
    gsDPSetPrimColor(0, 0, 0, 0, 0, 0),
    gsDPSetBlendColor(0, 0, 0, 0),
    gsDPSetFogColor(0, 0, 0, 0),
    gsDPSetFillColor(0x00000000),
    gsDPSetPrimDepth(0, 0),
    gsDPSetConvert(0, 0, 0, 0, 0, 0),
    gsDPSetKeyR(0, 0, 0),
    gsDPSetKeyGB(0, 0, 0, 0, 0, 0),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_RENDERTILE, 0,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 1, 0,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 2, 0, G_TX_NOMIRROR | G_TX_WRAP,
                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 3, 0, G_TX_NOMIRROR | G_TX_WRAP,
                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 4, 0, G_TX_NOMIRROR | G_TX_WRAP,
                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 5, 0, G_TX_NOMIRROR | G_TX_WRAP,
                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP,
                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0, 0),
    gsDPSetTileSize(1, 0, 0, 0, 0),
    gsDPSetTileSize(2, 0, 0, 0, 0),
    gsDPSetTileSize(3, 0, 0, 0, 0),
    gsDPSetTileSize(4, 0, 0, 0, 0),
    gsDPSetTileSize(5, 0, 0, 0, 0),
    gsDPSetTileSize(6, 0, 0, 0, 0),
    gsDPSetTileSize(G_TX_LOADTILE, 0, 0, 0, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

void nuGfxInitEX2(void) {
    Gfx gfx[0x100];
    Gfx* ptr;

    nuGfxThreadStart();
    nuGfxSetCfb(FrameBuf, NU_GFX_FRAMEBUFFER_NUM);
    nuGfxSetZBuffer((u16*) NU_GFX_ZBUFFER_ADDR);
    nuGfxSwapCfbFuncSet(nuGfxSwapCfb);
#if VERSION_PAL
    nuGfxSetUcodeFifo(D_800B91D0, NU_GFX_RDP_OUTPUTBUFF_SIZE);
#endif
    nuGfxUcode = &nugfx_ucode;
    nuGfxTaskMgrInit();

    ptr = gfx;
    gSPDisplayList(ptr++, OS_K0_TO_PHYSICAL(&rdpstateinit_dl));
    gDPFullSync(ptr++);
    gSPEndDisplayList(ptr++);

    nuGfxTaskStart(gfx, (s32)(ptr - gfx) * sizeof(Gfx), NU_GFX_UCODE_F3DEX, NU_SC_NOSWAPBUFFER);
    nuGfxTaskAllEndWait();
}
