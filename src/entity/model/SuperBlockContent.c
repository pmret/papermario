#include "common.h"
#include "include_asset.h"

INCLUDE_IMG("entity/model/SuperBlockContent.png", D_0A000000_E4A6A0);
INCLUDE_PAL("entity/model/SuperBlockContent.pal", D_0A000200_E4A8A0);
INCLUDE_PAL("entity/model/SuperBlockContent.pal2.pal", D_0A000220_E4A8C0);
INCLUDE_PAL("entity/model/SuperBlockContent.pal3.pal", D_0A000240_E4A8E0);
INCLUDE_PAL("entity/model/SuperBlockContent.pal4.pal", D_0A000260_E4A900);

Vtx Entity_SuperBlockContent_vtx[] = {
    {{{    13,    13,     0 }, 0, {     0,     0 }, { 255, 255, 255, 255 }}},
    {{{   -13,    13,     0 }, 0, {  1024,     0 }, { 255, 255, 255, 255 }}},
    {{{   -13,   -13,     0 }, 0, {  1024,  1024 }, { 255, 255, 255, 255 }}},
    {{{    13,   -13,     0 }, 0, {     0,  1024 }, { 255, 255, 255, 255 }}},
};

Gfx Entity_SuperBlockContent_Prepare[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Gfx Entity_SuperBlockContent_RenderImage[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPDisplayList(Entity_SuperBlockContent_Prepare),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(Entity_SuperBlockContent_vtx, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_SuperBlockContent_Render[] = {
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2),
    gsDPLoadTextureBlock_4b(D_0A000000_E4A6A0, G_IM_FMT_CI, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPDisplayList(Entity_SuperBlockContent_RenderImage),
    gsSPEndDisplayList(),
};

Gfx Entity_SuperBlockContent_Render2[] = {
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2),
    gsDPLoadTextureBlock_4b(D_0A000000_E4A6A0, G_IM_FMT_CI, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPDisplayList(Entity_SuperBlockContent_RenderImage),
    gsSPEndDisplayList(),
};
