#include "common.h"

Vtx Entity_ArrowSign_vtxSign[] = {
    {{{   -10,   -10,     0 }, 0, {     0,     0 }, { 255, 255, 255, 255 }}},
    {{{    20,   -10,     0 }, 0, {  2048,     0 }, { 255, 255, 255, 255 }}},
    {{{    20,    10,     0 }, 0, {  2048,  1024 }, { 255, 255, 255, 255 }}},
    {{{   -10,    10,     0 }, 0, {     0,  1024 }, { 255, 255, 255, 255 }}},
};
Vtx Entity_ArrowSign_vtxPole[] = {
    {{{    -2,     0,    -1 }, 0, {     0,     0 }, {  25,  20,   0, 255 }}},
    {{{     1,     0,    -1 }, 0, {     0,     0 }, {  25,  20,   0, 255 }}},
    {{{     1,    19,    -1 }, 0, {     0,     0 }, {  25,  20,   0, 255 }}},
    {{{    -2,    19,    -1 }, 0, {     0,     0 }, {  25,  20,   0, 255 }}},
};

#include "entity/model/ArrowSign.png.inc.c"
#include "entity/model/ArrowSign.pal.inc.c"
Gfx Entity_ArrowSign_LoadTexture[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal256(D_0A000880_E5A780),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock(D_0A000080_E59F80, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Mtx Entity_ArrowSign_mtxSign = RDP_MATRIX(
    1.000000, 0.000000, 0.000000, -0.180848,
    0.000000, 1.000000, 0.000000, 20.000000,
    0.000000, 0.000000, 1.000000,  1.000000,
    0.000000, 0.000000, 0.000000,  1.000000
);

Gfx Entity_ArrowSign_RenderPole[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(Entity_ArrowSign_vtxPole, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_ArrowSign_RenderPole_[] = {
    gsSPDisplayList(Entity_ArrowSign_RenderPole),
    gsSPEndDisplayList(),
};

Gfx Entity_ArrowSign_RenderRotatedSign[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsSPDisplayList(Entity_ArrowSign_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(Entity_ArrowSign_vtxSign, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_ArrowSign_RenderSign[] = {
    gsSPMatrix(&Entity_ArrowSign_mtxSign, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsSPDisplayList(Entity_ArrowSign_RenderRotatedSign),
    gsSPPopMatrix(G_MTX_MODELVIEW),
    gsSPEndDisplayList(),
};

Gfx Entity_ArrowSign_RenderPole__[] = {
    gsSPDisplayList(Entity_ArrowSign_RenderPole_),
    gsSPEndDisplayList(),
};

Gfx Entity_ArrowSign_Render[] = {
    gsSPDisplayList(Entity_ArrowSign_RenderPole__),
    gsSPEndDisplayList(),
};
