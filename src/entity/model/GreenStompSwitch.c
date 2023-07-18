#include "common.h"

#include "entity/model/GreenStompSwitch_1.vtx.inc.c"
#include "entity/model/GreenStompSwitch_2.vtx.inc.c"

#include "entity/model/GreenStompSwitch_tex.png.inc.c"
#include "entity/model/GreenStompSwitch_tex.pal.inc.c"
Gfx Entity_GreenStompSwitch_LoadTexture[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000280_E625F0, G_IM_FMT_CI, 16, 16, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000300_E62670),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

#include "entity/model/GreenStompSwitch_exclamationMark.png.inc.c"
#include "entity/model/GreenStompSwitch_exclamationMark.pal.inc.c"
Gfx Entity_GreenStompSwitch_LoadExclMark[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A0003D8_E62748, G_IM_FMT_CI, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A0004D8_E62848),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

Mtx Entity_GreenStompSwitch_mtx = RDP_MATRIX(
    1.000000, 0.000000, 0.000000, 0.000000,
    0.000000, 1.000000, 0.000000, 0.000000,
    0.000000, 0.000000, 1.000000, 0.000000,
    0.000000, 0.000000, 0.000000, 1.000000
);

Gfx Entity_GreenStompSwitch_RenderBase[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_GreenStompSwitch_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000080_E623F0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 1, 0, 4, 1, 0, 0),
    gsSP2Triangles(3, 2, 6, 0, 3, 6, 7, 0),
    gsSP2Triangles(8, 9, 5, 0, 8, 5, 4, 0),
    gsSP2Triangles(10, 11, 9, 0, 10, 9, 8, 0),
    gsSP2Triangles(12, 13, 11, 0, 12, 11, 10, 0),
    gsSP2Triangles(14, 15, 13, 0, 14, 13, 12, 0),
    gsSP2Triangles(7, 6, 15, 0, 7, 15, 14, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(17, 16, 20, 0, 17, 20, 21, 0),
    gsSP2Triangles(21, 20, 22, 0, 21, 22, 23, 0),
    gsSP2Triangles(19, 18, 24, 0, 19, 24, 25, 0),
    gsSP2Triangles(25, 24, 26, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 27, 26, 0, 28, 26, 29, 0),
    gsSPVertex(&D_0A000080_E623F0[22], 2, 0),
    gsSPVertex(&D_0A000080_E623F0[28], 4, 2),
    gsSP2Triangles(1, 0, 4, 0, 1, 4, 5, 0),
    gsSP2Triangles(5, 4, 2, 0, 5, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_GreenStompSwitch_RenderExclMark[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_GreenStompSwitch_LoadExclMark),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000000_E62370, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 5, 0),
    gsSP2Triangles(0, 5, 6, 0, 0, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_GreenStompSwitch_RenderMain[] = {
    gsSPMatrix(&Entity_GreenStompSwitch_mtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsSPDisplayList(Entity_GreenStompSwitch_RenderExclMark),
    gsSPDisplayList(Entity_GreenStompSwitch_RenderBase),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx Entity_GreenStompSwitch_Render[] = {
    gsSPDisplayList(Entity_GreenStompSwitch_RenderMain),
    gsSPEndDisplayList(),
};
