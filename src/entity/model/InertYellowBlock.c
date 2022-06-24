#include "common.h"

Vtx Entity_InertYellowBlock_vtxFaces[] = {
    {{{   -13,     0,   -13 }, 0, {  1024,     0 }, { 255, 234, 151, 255 }}},
    {{{   -13,    25,   -13 }, 0, {  1024,  1024 }, { 255, 234, 151, 255 }}},
    {{{    13,    25,   -13 }, 0, {     0,  1024 }, { 255, 234, 151, 255 }}},
    {{{    13,     0,   -13 }, 0, {     0,     0 }, { 255, 234, 151, 255 }}},
    {{{    13,     0,   -13 }, 0, {  1024,     0 }, { 156, 133,  42, 255 }}},
    {{{    13,    25,   -13 }, 0, {  1024,  1024 }, { 156, 133,  42, 255 }}},
    {{{    13,    25,    13 }, 0, {     0,  1024 }, { 156, 133,  42, 255 }}},
    {{{    13,     0,    13 }, 0, {     0,     0 }, { 156, 133,  42, 255 }}},
    {{{    13,     0,    13 }, 0, {  1024,     0 }, { 255, 234, 151, 255 }}},
    {{{    13,    25,    13 }, 0, {  1024,  1024 }, { 255, 234, 151, 255 }}},
    {{{   -13,    25,    13 }, 0, {     0,  1024 }, { 255, 234, 151, 255 }}},
    {{{   -13,     0,    13 }, 0, {     0,     0 }, { 255, 234, 151, 255 }}},
    {{{   -13,     0,    13 }, 0, {  1024,     0 }, { 156, 133,  42, 255 }}},
    {{{   -13,    25,    13 }, 0, {  1024,  1024 }, { 156, 133,  42, 255 }}},
    {{{   -13,    25,   -13 }, 0, {     0,  1024 }, { 156, 133,  42, 255 }}},
    {{{   -13,     0,   -13 }, 0, {     0,     0 }, { 156, 133,  42, 255 }}},
};
Vtx Entity_InertYellowBlock_vtxTopBottom[] = {
    {{{   -13,    25,   -13 }, 0, {     0,     0 }, { 202, 186, 120, 255 }}},
    {{{   -13,    25,    13 }, 0, {     0,     0 }, { 202, 186, 120, 255 }}},
    {{{    13,    25,    13 }, 0, {     0,     0 }, { 202, 186, 120, 255 }}},
    {{{    13,    25,   -13 }, 0, {     0,     0 }, { 202, 186, 120, 255 }}},
    {{{    13,     0,   -13 }, 0, {     0,     0 }, {  68,  48,  18, 255 }}},
    {{{    13,     0,    13 }, 0, {     0,     0 }, {  68,  48,  18, 255 }}},
    {{{   -13,     0,    13 }, 0, {     0,     0 }, {  68,  48,  18, 255 }}},
    {{{   -13,     0,   -13 }, 0, {     0,     0 }, {  68,  48,  18, 255 }}},
};

#include "entity/model/InertYellowBlock_face.png.inc.c"
#include "entity/model/InertYellowBlock_face.pal.inc.c"
Gfx Entity_InertYellowBlock_LoadTexture[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_0A000380_E425C0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPLoadTextureBlock_4b(D_0A000180_E423C0, G_IM_FMT_CI, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Gfx Entity_InertYellowBlock_RenderTopBottom[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPTexture(0x0080, 0x0080, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(Entity_InertYellowBlock_vtxTopBottom, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_InertYellowBlock_RenderFaces[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_InertYellowBlock_LoadTexture),
    gsSPClearGeometryMode(G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(Entity_InertYellowBlock_vtxFaces, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_InertYellowBlock_Render[] = {
    gsSPDisplayList(Entity_InertYellowBlock_RenderFaces),
    gsSPDisplayList(Entity_InertYellowBlock_RenderTopBottom),
    gsSPEndDisplayList(),
};
