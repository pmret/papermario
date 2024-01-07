#include "common.h"
#include "include_asset.h"

INCLUDE_IMG("entity/model/CymbalPlant.png", D_0A000000_E992F0);
INCLUDE_PAL("entity/model/CymbalPlant.pal", D_0A000800_E99AF0);
Gfx Entity_CymbalPlant_LoadTexture[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000800_E99AF0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000000_E992F0, G_IM_FMT_CI, 64, 64, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

#include "entity/model/CymbalPlant_1.vtx.inc.c"
#include "entity/model/CymbalPlant_2.vtx.inc.c"
#include "entity/model/CymbalPlant_3.vtx.inc.c"
#include "entity/model/CymbalPlant_4.vtx.inc.c"
#include "entity/model/CymbalPlant_5.vtx.inc.c"
#include "entity/model/CymbalPlant_6.vtx.inc.c"
#include "entity/model/CymbalPlant_7.vtx.inc.c"
#include "entity/model/CymbalPlant_8.vtx.inc.c"

Mtx Entity_CymbalPlant_RightMtx = RDP_MATRIX(
    1.000000, 0.000000, 0.000000,  2.668290,
    0.000000, 1.000000, 0.000000, 26.668290,
    0.000000, 0.000000, 1.000000,  0.000000,
    0.000000, 0.000000, 0.000000,  1.000000
);

Mtx Entity_CymbalPlant_LeftMtx = RDP_MATRIX(
    1.000000, 0.000000, 0.000000, -2.331711,
    0.000000, 1.000000, 0.000000, 26.668290,
    0.000000, 0.000000, 1.000000,  0.000000,
    0.000000, 0.000000, 0.000000,  1.000000
);

Gfx Entity_CymbalPlant_RenderNode3[] = {
    gsDPPipeSync(),
    gsSPMatrix(&Entity_CymbalPlant_LeftMtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_CymbalPlant_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000F28_E9A218, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSP2Triangles(2, 6, 3, 0, 5, 6, 2, 0),
    gsSP2Triangles(7, 6, 8, 0, 9, 6, 7, 0),
    gsSP2Triangles(3, 6, 9, 0, 8, 6, 10, 0),
    gsSP2Triangles(11, 6, 5, 0, 12, 6, 11, 0),
    gsSP2Triangles(13, 6, 12, 0, 10, 6, 13, 0),
    gsSP2Triangles(14, 0, 3, 0, 14, 3, 9, 0),
    gsSP2Triangles(15, 14, 9, 0, 15, 9, 7, 0),
    gsSP2Triangles(15, 7, 8, 0, 15, 8, 16, 0),
    gsSP2Triangles(16, 8, 10, 0, 16, 10, 17, 0),
    gsSP2Triangles(5, 4, 18, 0, 5, 18, 11, 0),
    gsSP2Triangles(19, 17, 10, 0, 19, 10, 13, 0),
    gsSP2Triangles(20, 19, 13, 0, 20, 13, 12, 0),
    gsSP2Triangles(18, 20, 12, 0, 18, 12, 11, 0),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx Entity_CymbalPlant_RenderNode4[] = {
    gsDPPipeSync(),
    gsSPMatrix(&Entity_CymbalPlant_LeftMtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_CymbalPlant_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000DB8_E9A0A8, 23, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
    gsSP2Triangles(4, 6, 0, 0, 0, 6, 1, 0),
    gsSP2Triangles(7, 6, 8, 0, 8, 6, 4, 0),
    gsSP2Triangles(1, 6, 9, 0, 10, 6, 7, 0),
    gsSP2Triangles(9, 6, 11, 0, 11, 6, 12, 0),
    gsSP2Triangles(12, 6, 13, 0, 13, 6, 10, 0),
    gsSP2Triangles(1, 9, 14, 0, 1, 14, 2, 0),
    gsSP2Triangles(8, 4, 5, 0, 8, 5, 15, 0),
    gsSP2Triangles(16, 7, 8, 0, 16, 8, 15, 0),
    gsSP2Triangles(17, 10, 7, 0, 17, 7, 16, 0),
    gsSP2Triangles(11, 18, 14, 0, 11, 14, 9, 0),
    gsSP2Triangles(19, 10, 17, 0, 19, 17, 20, 0),
    gsSP2Triangles(11, 21, 22, 0, 11, 22, 18, 0),
    gsSP2Triangles(21, 19, 20, 0, 21, 20, 22, 0),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx Entity_CymbalPlant_RenderNode5[] = {
    gsDPPipeSync(),
    gsSPMatrix(&Entity_CymbalPlant_LeftMtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(&D_0A0009C8_E99CB8[8], 1, 0),
    gsSPVertex(D_0A000D28_E9A018, 9, 1),
    gsSP2Triangles(1, 0, 2, 0, 1, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(7, 6, 8, 0, 7, 8, 9, 0),
    gsSP2Triangles(3, 2, 5, 0, 3, 5, 4, 0),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx D_0A001308_E9A5F8[] = {
    gsSPMatrix(&Entity_CymbalPlant_LeftMtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsSPDisplayList(Entity_CymbalPlant_RenderNode5),
    gsSPDisplayList(Entity_CymbalPlant_RenderNode4),
    gsSPDisplayList(Entity_CymbalPlant_RenderNode3),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx Entity_CymbalPlant_RenderNode7[] = {
    gsDPPipeSync(),
    gsSPMatrix(&Entity_CymbalPlant_RightMtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_CymbalPlant_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000BB8_E99EA8, 23, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSP2Triangles(2, 6, 3, 0, 5, 6, 2, 0),
    gsSP2Triangles(7, 6, 8, 0, 9, 6, 7, 0),
    gsSP2Triangles(3, 6, 9, 0, 8, 6, 10, 0),
    gsSP2Triangles(11, 6, 5, 0, 12, 6, 11, 0),
    gsSP2Triangles(13, 6, 12, 0, 10, 6, 13, 0),
    gsSP2Triangles(14, 0, 3, 0, 14, 3, 9, 0),
    gsSP2Triangles(15, 14, 9, 0, 15, 9, 7, 0),
    gsSP2Triangles(15, 7, 8, 0, 15, 8, 16, 0),
    gsSP2Triangles(16, 8, 10, 0, 16, 10, 17, 0),
    gsSP2Triangles(5, 4, 18, 0, 5, 18, 11, 0),
    gsSP2Triangles(19, 17, 10, 0, 19, 10, 20, 0),
    gsSP2Triangles(18, 21, 22, 0, 18, 22, 11, 0),
    gsSP2Triangles(21, 19, 20, 0, 21, 20, 22, 0),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx Entity_CymbalPlant_RenderNode9[] = {
    gsDPPipeSync(),
    gsSPMatrix(&Entity_CymbalPlant_RightMtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPDisplayList(Entity_CymbalPlant_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000A68_E99D58, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
    gsSP2Triangles(4, 6, 0, 0, 0, 6, 1, 0),
    gsSP2Triangles(7, 6, 8, 0, 8, 6, 4, 0),
    gsSP2Triangles(1, 6, 9, 0, 10, 6, 7, 0),
    gsSP2Triangles(9, 6, 11, 0, 11, 6, 12, 0),
    gsSP2Triangles(12, 6, 13, 0, 13, 6, 10, 0),
    gsSP2Triangles(1, 9, 14, 0, 1, 14, 2, 0),
    gsSP2Triangles(8, 4, 5, 0, 8, 5, 15, 0),
    gsSP2Triangles(16, 7, 8, 0, 16, 8, 15, 0),
    gsSP2Triangles(17, 10, 7, 0, 17, 7, 16, 0),
    gsSP2Triangles(11, 18, 14, 0, 11, 14, 9, 0),
    gsSP2Triangles(13, 10, 17, 0, 13, 17, 19, 0),
    gsSP2Triangles(12, 13, 19, 0, 12, 19, 20, 0),
    gsSP2Triangles(11, 12, 20, 0, 11, 20, 18, 0),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx Entity_CymbalPlant_RenderNode8[] = {
    gsDPPipeSync(),
    gsSPMatrix(&Entity_CymbalPlant_RightMtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A0009C8_E99CB8, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 4, 6, 0, 5, 6, 7, 0),
    gsSP2Triangles(7, 6, 8, 0, 7, 8, 9, 0),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx D_0A001540_E9A830[] = {
    gsSPMatrix(&Entity_CymbalPlant_RightMtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsSPDisplayList(Entity_CymbalPlant_RenderNode8),
    gsSPDisplayList(Entity_CymbalPlant_RenderNode9),
    gsSPDisplayList(Entity_CymbalPlant_RenderNode7),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx D_0A001570_E9A860[] = {
    gsSPDisplayList(D_0A001540_E9A830),
    gsSPDisplayList(D_0A001308_E9A5F8),
    gsSPEndDisplayList(),
};

Gfx Entity_CymbalPlant_RenderNode10[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A000968_E99C58, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(0, 4, 1, 0, 3, 5, 4, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_CymbalPlant_RenderNode1[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPVertex(D_0A0008C8_E99BB8, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 1, 5, 2, 0),
    gsSPVertex(D_0A0008C8_E99BB8, 1, 0),
    gsSPVertex(&D_0A0008C8_E99BB8[3], 7, 1),
    gsSP2Triangles(0, 1, 4, 0, 0, 4, 5, 0),
    gsSP2Triangles(2, 6, 7, 0, 2, 7, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0A001658_E9A948[] = {
    gsSPDisplayList(Entity_CymbalPlant_RenderNode1),
    gsSPDisplayList(Entity_CymbalPlant_RenderNode10),
    gsSPEndDisplayList(),
};

Gfx D_0A001670_E9A960[] = {
    gsSPDisplayList(D_0A001658_E9A948),
    gsSPDisplayList(D_0A001570_E9A860),
    gsSPEndDisplayList(),
};

Gfx D_0A001688_E9A978[] = {
    gsSPDisplayList(D_0A001670_E9A960),
    gsSPEndDisplayList(),
};
