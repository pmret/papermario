#include "common.h"

#include "entity/model/Chest_1.vtx.inc.c"
#include "entity/model/Chest_2.vtx.inc.c"
#include "entity/model/Chest_3.vtx.inc.c"
#include "entity/model/Chest_4.vtx.inc.c"

#include "entity/model/Chest_tex1.png.inc.c"
Gfx Entity_Chest_LoadTexture1[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A000410_E64CE0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

#include "entity/model/Chest_tex2.png.inc.c"
#include "entity/model/Chest_tex2.pal.inc.c"
Gfx Entity_Chest_LoadTexture2[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000898_E65168, G_IM_FMT_CI, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000998_E65268),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

#include "entity/model/Chest_lock.png.inc.c"
#include "entity/model/Chest_lock.pal.inc.c"
Gfx Entity_Chest_LoadTextureLock[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000A70_E65340, G_IM_FMT_CI, 16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000B70_E65440),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

Mtx Entity_Chest_LidMtx = RDP_MATRIX(
    1.000000, 0.000000, 0.000000,   0.000000,
    0.000000, 1.000000, 0.000000,  29.000000,
    0.000000, 0.000000, 1.000000, -23.000000,
    0.000000, 0.000000, 0.000000,   1.000000
);

Gfx Entity_Chest_RenderLidLock[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_Chest_LoadTextureLock),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000390_E64C60, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 5, 0),
    gsSP2Triangles(3, 2, 6, 0, 3, 6, 4, 0),
    gsSP2Triangles(4, 6, 7, 0, 4, 7, 5, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Chest_RenderLidWooden[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_Chest_LoadTexture2),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000210_E64AE0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(&D_0A000210_E64AE0[1], 2, 0),
    gsSPVertex(&D_0A000210_E64AE0[4], 20, 2),
    gsSP2Triangles(1, 2, 3, 0, 1, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(4, 8, 9, 0, 4, 9, 10, 0),
    gsSP2Triangles(4, 10, 11, 0, 4, 11, 12, 0),
    gsSP2Triangles(4, 12, 13, 0, 4, 13, 14, 0),
    gsSP2Triangles(3, 15, 8, 0, 3, 8, 7, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(16, 19, 20, 0, 16, 20, 21, 0),
    gsSP2Triangles(16, 21, 15, 0, 16, 15, 2, 0),
    gsSP2Triangles(8, 15, 21, 0, 8, 21, 9, 0),
    gsSP2Triangles(9, 21, 20, 0, 9, 20, 10, 0),
    gsSP2Triangles(10, 20, 19, 0, 10, 19, 11, 0),
    gsSP2Triangles(11, 19, 18, 0, 11, 18, 12, 0),
    gsSP2Triangles(12, 18, 17, 0, 12, 17, 13, 0),
    gsSP2Triangles(13, 17, 16, 0, 13, 16, 14, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Chest_RenderLid[] = {
    gsSPDisplayList(Entity_Chest_RenderLidWooden),
    gsSPDisplayList(Entity_Chest_RenderLidLock),
    gsSPEndDisplayList(),
};

Gfx Entity_Chest_RenderBoxLock[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_Chest_LoadTextureLock),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0A000190_E64A60, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
    gsSP2Triangles(2, 1, 6, 0, 2, 6, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 5, 6, 7, 0),
    gsSP2Triangles(7, 6, 1, 0, 7, 1, 0, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Chest_RenderBoxWooden[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_Chest_LoadTexture1),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000000_E648D0, 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(7, 8, 9, 0, 7, 9, 10, 0),
    gsSP2Triangles(9, 11, 12, 0, 9, 12, 13, 0),
    gsSP2Triangles(14, 15, 10, 0, 14, 10, 16, 0),
    gsSP2Triangles(12, 14, 16, 0, 12, 16, 13, 0),
    gsSP2Triangles(17, 18, 19, 0, 17, 19, 20, 0),
    gsSP2Triangles(21, 22, 23, 0, 21, 23, 24, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_Chest_RenderBox[] = {
    gsSPDisplayList(Entity_Chest_RenderBoxWooden),
    gsSPDisplayList(Entity_Chest_RenderBoxLock),
    gsSPEndDisplayList(),
};
