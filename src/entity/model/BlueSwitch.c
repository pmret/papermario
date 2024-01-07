#include "common.h"
#include "include_asset.h"

#include "entity/model/BlueSwitch_1.vtx.inc.c"
#include "entity/model/BlueSwitch_2.vtx.inc.c"
#include "entity/model/BlueSwitch_3.vtx.inc.c"
#include "entity/model/BlueSwitch_4.vtx.inc.c"

INCLUDE_IMG("entity/model/BlueSwitch_tex.png", D_0A0005D0_E63F90);
INCLUDE_PAL("entity/model/BlueSwitch_tex.pal", D_0A0006D0_E64090);
Gfx Entity_BlueSwitch_LoadTexture[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal256(D_0A0006D0_E64090),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A0005D0_E63F90, G_IM_FMT_CI, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

INCLUDE_IMG("entity/model/BlueSwitch_exclamationMark.png", D_0A000978_E64338);
Gfx Entity_BlueSwitch_LoadExclMark[] = {
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000978_E64338, G_IM_FMT_IA, 16, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_BlueSwitch_mtxExclMark = RDP_MATRIX(
    1.000000, 0.000000, 0.000000, 0.000000,
    0.000000, 1.000000, 0.000000, 6.000000,
    0.000000, 0.000000, 1.000000, 0.000000,
    0.000000, 0.000000, 0.000000, 1.000000
);

Mtx Entity_BlueSwitch_mtxBlueBubble = RDP_MATRIX(
    1.000000, 0.000000, 0.000000, -0.026597,
    0.000000, 1.000000, 0.000000,  5.000000,
    0.000000, 0.000000, 1.000000,  0.609116,
    0.000000, 0.000000, 0.000000,  1.000000
);

Gfx Entity_BlueSwitch_RenderBlueBubble[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A0003D0_E63D90, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
    gsSP2Triangles(1, 6, 7, 0, 1, 7, 2, 0),
    gsSP2Triangles(2, 7, 8, 0, 2, 8, 4, 0),
    gsSP2Triangles(4, 8, 9, 0, 4, 9, 10, 0),
    gsSP2Triangles(5, 4, 10, 0, 5, 10, 11, 0),
    gsSP2Triangles(12, 13, 6, 0, 12, 6, 1, 0),
    gsSP2Triangles(13, 14, 15, 0, 13, 15, 6, 0),
    gsSP2Triangles(6, 15, 16, 0, 6, 16, 7, 0),
    gsSP2Triangles(17, 18, 19, 0, 17, 19, 20, 0),
    gsSP2Triangles(17, 20, 16, 0, 17, 16, 15, 0),
    gsSP2Triangles(17, 15, 14, 0, 17, 14, 21, 0),
    gsSP2Triangles(7, 16, 20, 0, 7, 20, 8, 0),
    gsSP2Triangles(22, 12, 1, 0, 22, 1, 0, 0),
    gsSP2Triangles(23, 24, 13, 0, 23, 13, 12, 0),
    gsSP2Triangles(24, 21, 14, 0, 24, 14, 13, 0),
    gsSP2Triangles(25, 23, 12, 0, 25, 12, 22, 0),
    gsSP2Triangles(8, 20, 19, 0, 8, 19, 9, 0),
    gsSP2Triangles(26, 27, 24, 0, 26, 24, 23, 0),
    gsSP2Triangles(28, 29, 27, 0, 28, 27, 26, 0),
    gsSP2Triangles(29, 18, 17, 0, 29, 17, 27, 0),
    gsSP2Triangles(27, 17, 21, 0, 27, 21, 24, 0),
    gsSP2Triangles(10, 9, 29, 0, 10, 29, 28, 0),
    gsSP2Triangles(9, 19, 18, 0, 9, 18, 29, 0),
    gsSPVertex(&D_0A0003D0_E63D90[10], 2, 0),
    gsSPVertex(&D_0A0003D0_E63D90[23], 1, 2),
    gsSPVertex(&D_0A0003D0_E63D90[25], 2, 3),
    gsSPVertex(&D_0A0003D0_E63D90[28], 1, 5),
    gsSPVertex(&D_0A0003D0_E63D90[30], 2, 6),
    gsSP2Triangles(6, 5, 4, 0, 6, 4, 7, 0),
    gsSP2Triangles(7, 4, 2, 0, 7, 2, 3, 0),
    gsSP2Triangles(1, 0, 5, 0, 1, 5, 6, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_BlueSwitch_RenderRotatedBlueBubble[] = {
    gsSPMatrix(&Entity_BlueSwitch_mtxBlueBubble, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsSPDisplayList(Entity_BlueSwitch_RenderBlueBubble),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx Entity_BlueSwitch_RenderExclMark[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPDisplayList(Entity_BlueSwitch_LoadExclMark),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000390_E63D50, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_BlueSwitch_RenderRotatedExclMark[] = {
    gsSPMatrix(&Entity_BlueSwitch_mtxExclMark, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsSPDisplayList(Entity_BlueSwitch_RenderExclMark),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx Entity_BlueSwitch_RenderBase2[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000300_E63CC0, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(2, 1, 4, 0, 2, 4, 5, 0),
    gsSP2Triangles(2, 5, 6, 0, 7, 2, 6, 0),
    gsSP2Triangles(8, 3, 2, 0, 7, 8, 2, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_BlueSwitch_RenderBase[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_BlueSwitch_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000000_E639C0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 1, 0, 4, 1, 0, 0),
    gsSP2Triangles(3, 2, 6, 0, 3, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 9, 0, 12, 9, 8, 0),
    gsSP2Triangles(11, 10, 14, 0, 11, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 21, 17, 0, 20, 17, 16, 0),
    gsSP2Triangles(19, 18, 22, 0, 19, 22, 23, 0),
    gsSP2Triangles(7, 6, 24, 0, 7, 24, 25, 0),
    gsSP2Triangles(15, 14, 26, 0, 15, 26, 27, 0),
    gsSP2Triangles(28, 29, 21, 0, 28, 21, 20, 0),
    gsSPVertex(&D_0A000000_E639C0[4], 2, 0),
    gsSPVertex(&D_0A000000_E639C0[12], 2, 2),
    gsSPVertex(&D_0A000000_E639C0[22], 26, 4),
    gsSP2Triangles(12, 24, 25, 0, 12, 25, 13, 0),
    gsSP2Triangles(13, 25, 1, 0, 13, 1, 0, 0),
    gsSP2Triangles(14, 26, 27, 0, 14, 27, 15, 0),
    gsSP2Triangles(15, 27, 3, 0, 15, 3, 2, 0),
    gsSP2Triangles(16, 28, 11, 0, 16, 11, 10, 0),
    gsSP2Triangles(5, 4, 17, 0, 5, 17, 21, 0),
    gsSP2Triangles(9, 8, 18, 0, 9, 18, 19, 0),
    gsSP2Triangles(19, 18, 26, 0, 19, 26, 14, 0),
    gsSP2Triangles(20, 29, 28, 0, 20, 28, 16, 0),
    gsSP2Triangles(21, 17, 29, 0, 21, 29, 20, 0),
    gsSP2Triangles(22, 23, 24, 0, 22, 24, 12, 0),
    gsSP2Triangles(7, 6, 23, 0, 7, 23, 22, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_BlueSwitch_RenderBaseMain[] = {
    gsSPDisplayList(Entity_BlueSwitch_RenderBase),
    gsSPDisplayList(Entity_BlueSwitch_RenderBase2),
    gsSPEndDisplayList(),
};

Gfx Entity_BlueSwitch_RenderMain[] = {
    gsSPDisplayList(Entity_BlueSwitch_RenderBaseMain),
    gsSPDisplayList(Entity_BlueSwitch_RenderRotatedExclMark),
    gsSPDisplayList(Entity_BlueSwitch_RenderRotatedBlueBubble),
    gsSPEndDisplayList(),
};

Gfx Entity_BlueSwitch_Render[] = {
    gsSPDisplayList(Entity_BlueSwitch_RenderMain),
    gsSPEndDisplayList(),
};
