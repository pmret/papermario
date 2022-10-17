#include "hos_03.h"

extern u16 D_80243BCC_A1ECCC;
extern u16 D_80243BCE_A1ECCE;
extern u16 D_80243BD0_A1ECD0;
extern u16 D_80243BD2_A1ECD2;
extern u16 D_80243BD4_A1ECD4;

#include "world/common/atomic/TexturePan.inc.c"

void func_8024033C_A1B43C(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    f32 angle = sins(D_80243BCC_A1ECCC) / 32768.0f * 45.0f;
    D_80243BCC_A1ECCC += 0x400;
    guRotate(&gDisplayContext->matrixStack[gMatrixListPos], angle, 0.0f, 1.0f, 0.0f);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    mdl_get_copied_vertices(1, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(D_80243BCE_A1ECCE * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 100;
        colors[1] = temp1 * 155 / 0x8000 + 100;

        temp3 = sins(D_80243BCE_A1ECCE / 0x8000 * (((i / 2) % 3 + 1) << 15)  + D_80243BCE_A1ECCE / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000;
    }

    gSPClearGeometryMode(gMasterGfxPos++, G_CULL_BOTH);
    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(1));
    D_80243BCE_A1ECCE += 0x666;
}

void func_8024060C_A1B70C(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    mdl_get_copied_vertices(2, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(D_80243BD0_A1ECD0 * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 100;
        colors[1] = temp1 * 155 / 0x8000 + 100;

        temp3 = sins(D_80243BD0_A1ECD0 / 0x8000 * (((i / 2) % 3 + 1) << 15)  + D_80243BD0_A1ECD0 / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(2));
    D_80243BD0_A1ECD0 += 0x253;
}

void func_802407E8_A1B8E8(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;

    mdl_get_copied_vertices(0, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        Vtx* vtxDst = &copiedVertices[i];
        Vtx* vtxSrc = &firstVertex[i];
        s32 v0 = sins(D_80243BD2_A1ECD2 * (i % 3 + 1) + i * 0x2AAA) * 50;
        vtxDst->v.ob[1] = vtxSrc->v.ob[1] + v0 / 0x8000;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(0));
    D_80243BD2_A1ECD2 += 0xA3;
}

void func_80240928_A1BA28(void) {
    f32 scale = ((sins(D_80243BD4_A1ECD4) * (1 / 32768.0f)) * 0.5 * 0.5) + 1.05;

    D_80243BD4_A1ECD4 += 409;
    guScale(&gDisplayContext->matrixStack[gMatrixListPos], scale, scale, scale);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

ApiStatus func_80240A50_A1BB50(Evt* script, s32 isInitialCall) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}
