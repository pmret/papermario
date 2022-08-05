#include "common.h"

Vtx Entity_HiddenPanel_vtxTopSide[] = {
    {{{   -30,     1,   -30 }, 0, {     0,  1024 }, { 255, 255, 255, 255 }}},
    {{{   -30,     1,    30 }, 0, {  1024,  1024 }, { 255, 255, 255, 255 }}},
    {{{    30,     1,    30 }, 0, {  1024,     0 }, { 255, 255, 255, 255 }}},
    {{{    30,     1,   -30 }, 0, {     0,     0 }, { 255, 255, 255, 255 }}},
};
Vtx Entity_HiddenPanel_vtxBottomSide[] = {
    {{{   -30,    -1,   -30 }, 0, {     0,  1024 }, { 128, 128, 128, 255 }}},
    {{{   -30,    -1,    30 }, 0, {  1024,  1024 }, { 128, 128, 128, 255 }}},
    {{{    30,    -1,    30 }, 0, {  1024,     0 }, { 128, 128, 128, 255 }}},
    {{{    30,    -1,   -30 }, 0, {     0,     0 }, { 128, 128, 128, 255 }}},
};
Vtx Entity_HiddenPanel_vtxBottomSideDark[] = {
    {{{   -30,     0,   -30 }, 0, {     0,  1024 }, {  10,  10,  10, 128 }}},
    {{{   -30,     0,    30 }, 0, {  1024,  1024 }, {  10,  10,  10, 128 }}},
    {{{    30,     0,    30 }, 0, {  1024,     0 }, {  10,  10,  10, 128 }}},
    {{{    30,     0,   -30 }, 0, {     0,     0 }, {  10,  10,  10, 128 }}},
};
Vtx Entity_HiddenPanel_vtxTopSide2[] = {
    {{{   -30,     1,   -30 }, 0, {     0,  1024 }, { 255, 255, 255, 255 }}},
    {{{   -30,     1,    30 }, 0, {  1024,  1024 }, { 255, 255, 255, 255 }}},
    {{{    30,     1,    30 }, 0, {  1024,     0 }, { 255, 255, 255, 255 }}},
    {{{    30,     1,   -30 }, 0, {     0,     0 }, { 255, 255, 255, 255 }}},
};
Vtx D_0A000016_E56BA0[] = {
    {{{   -30,    -1,   -30 }, 0, {     0,  1024 }, { 128, 128, 128, 255 }}},
    {{{   -30,    -1,    30 }, 0, {  1024,  1024 }, { 128, 128, 128, 255 }}},
    {{{    30,    -1,    30 }, 0, {  1024,     0 }, { 128, 128, 128, 255 }}},
    {{{    30,    -1,   -30 }, 0, {     0,     0 }, { 128, 128, 128, 255 }}}
};
Vtx D_0A000020_E56BA0[] = {
    {{{   -30,     0,   -30 }, 0, {     0,  1024 }, {  10,  10,  10, 128 }}},
    {{{   -30,     0,    30 }, 0, {  1024,  1024 }, {  10,  10,  10, 128 }}},
    {{{    30,     0,    30 }, 0, {  1024,     0 }, {  10,  10,  10, 128 }}},
    {{{    30,     0,   -30 }, 0, {     0,     0 }, {  10,  10,  10, 128 }}},
};

Gfx Gfx_HiddenPanel_RenderTop[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK),
    gsSPVertex(Entity_HiddenPanel_vtxTopSide, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Gfx_AltHiddenPanel_RenderTop[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK),
    gsSPVertex(Entity_HiddenPanel_vtxTopSide2, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Gfx_HiddenPanel_RenderBottom[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPVertex(Entity_HiddenPanel_vtxBottomSide, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSPEndDisplayList(),
};

Gfx Gfx_HiddenPanel_RenderHole[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_CULL_BOTH | G_LIGHTING),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPVertex(Entity_HiddenPanel_vtxBottomSideDark, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Gfx_HiddenPanel_Render[] = {
    gsDPPipeSync(),
    gsSPDisplayList(Gfx_HiddenPanel_RenderTop),
    gsSPDisplayList(Gfx_HiddenPanel_RenderBottom),
    gsSPEndDisplayList(),
};

Gfx Gfx_HiddenPanel_Render2[] = {
    gsDPPipeSync(),
    gsSPDisplayList(Gfx_AltHiddenPanel_RenderTop),
    gsSPDisplayList(Gfx_HiddenPanel_RenderBottom),
    gsSPEndDisplayList(),
};
