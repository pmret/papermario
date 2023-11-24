#include "effects/gfx/D_09000000_353BB0.png.inc.c"
#include "effects/gfx/D_09000200_353DB0.png.inc.c"
#include "effects/gfx/D_09000400_353FB0.png.inc.c"
#include "effects/gfx/D_09000600_3541B0.png.inc.c"

extern unsigned char D_800B32E0[];
extern unsigned char D_800B3AE0[];

//#include "effects/gfx/D_09000800_3543B0.gfx.inc.c"
#include "common.h"
Gfx D_09000800_3543B0[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPSetAlphaDither(G_AD_PATTERN),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPLoadTextureTile(OS_K0_TO_PHYSICAL(&D_800B32E0), G_IM_FMT_I, G_IM_SIZ_8b, 32, 0, 0, 0, 31, 63, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetCombineMode(PM_CC_34, PM_CC_35),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

#include "effects/gfx/D_090008B8_354468.vtx.inc.c"
#include "effects/gfx/D_090008F8_3544A8.gfx.inc.c"
#include "effects/gfx/D_09000918_3544C8.gfx.inc.c"

Gfx D_090009E0_354590[] = {
    gsDPSetColorImage(G_IM_FMT_I, G_IM_SIZ_8b, 32, OS_K0_TO_PHYSICAL(&D_800B3AE0)),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 32, 64),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetRenderMode(G_RM_PASS, G_RM_CLD_SURF2),
    gsDPSetCombineMode(PM_CC_CONST_ALPHA_1, PM_CC_CONST_ALPHA_1),
    gsSPTextureRectangle(0, 0, 0x0080, 0x0100, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400),
    gsDPPipeSync(),
    gsDPSetCombineMode(PM_CC_36, PM_CC_37),
    gsSPTextureRectangle(0, 0, 0x0080, 0x0100, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400),
    gsDPPipeSync(),
    gsDPLoadTextureTile(OS_K0_TO_PHYSICAL(&D_800B3AE0), G_IM_FMT_I, G_IM_SIZ_8b, 32, 0, 0, 0, 31, 63, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetColorImage(G_IM_FMT_I, G_IM_SIZ_8b, 32, OS_K0_TO_PHYSICAL(&D_800B32E0)),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetCombineMode(PM_CC_38, PM_CC_39),
    gsDPSetConvert(0, 0, 0, 0, 92, 0),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0x78),
    gsDPSetEnvColor(0x00, 0x00, 0x00, 0xA4),
    gsDPLoadMultiTile(OS_K0_TO_PHYSICAL(&D_800B32E0), 0x0100, 1, G_IM_FMT_I, G_IM_SIZ_8b, 32, 0, 0, 0, 31, 63, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTileSize(1, 0x0004, 0, 0x007C, 0x00FC),
    gsSPTextureRectangle(0, 0, 0x0080, 0x0100, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400),
    gsDPPipeSync(),
    gsDPLoadMultiTile(OS_K0_TO_PHYSICAL(&D_800B32E0), 0x0100, 1, G_IM_FMT_I, G_IM_SIZ_8b, 32, 0, 0, 0, 31, 63, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTileSize(1, 0x007C, 0, 0x007C, 0x00FC),
    gsSPTextureRectangle(0, 0, 0x0080, 0x0100, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400),
    gsDPPipeSync(),
    gsDPLoadMultiTile(OS_K0_TO_PHYSICAL(&D_800B32E0), 0x0100, 1, G_IM_FMT_I, G_IM_SIZ_8b, 32, 0, 0, 0, 31, 63, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTileSize(1, 0, 0x0004, 0x007C, 0x00FC),
    gsSPTextureRectangle(0, 0, 0x0080, 0x0100, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
