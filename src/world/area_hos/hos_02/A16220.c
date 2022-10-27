#include "hos_02.h"

static char* N(exit_str_0) = "hos_01";
static char* N(exit_str_1) = "hos_03";

extern u16 D_802433AC_A195CC;
extern u16 D_802433AE_A195CE;
extern u16 D_802433B0_A195D0;
extern u16 D_802433B2_A195D2;
extern u16 D_802433B4_A195D4;


#include "world/common/atomic/TexturePan.inc.c"

void func_8024030C_A1652C(void) {
    f32 scale = ((sins(D_802433AC_A195CC) * (1 / 32768.0f)) * 0.5 * 0.5) + 1.05;

    D_802433AC_A195CC += 409;
    guScale(&gDisplayContext->matrixStack[gMatrixListPos], scale, scale, scale);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

void func_80240434_A16654(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    mdl_get_copied_vertices(0, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(D_802433AE_A195CE * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 100;
        colors[1] = temp1 * 155 / 0x8000 + 100;

        temp3 = sins(D_802433AE_A195CE / 0x8000 * (((i / 2) % 3 + 1) << 15)  + D_802433AE_A195CE / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(0));
    D_802433AE_A195CE += 0x253;
}

void func_80240610_A16830(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    mdl_get_copied_vertices(1, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(D_802433B0_A195D0 * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 48.62745098039216;
        colors[1] = temp1 * 155 / 0x8000 + 89.41176470588236;

        temp3 = sins(D_802433B0_A195D0 / 0x8000 * (((i / 2) % 3 + 1) << 15)  + D_802433B0_A195D0 / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000 + 99.6078431372549;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(1));
    D_802433B0_A195D0 += 0x253;
}

void func_80240904_A16B24(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    mdl_get_copied_vertices(2, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(D_802433B2_A195D2 * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 67.45098039215686;
        colors[1] = temp1 * 155 / 0x8000 + 100.0;

        temp3 = sins(D_802433B2_A195D2 / 0x8000 * (((i / 2) % 3 + 1) << 15)  + D_802433B2_A195D2 / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000 + 59.21568627450981;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(2));
    D_802433B2_A195D2 += 0x253;
}

void func_80240BFC_A16E1C(void) {
    Vtx* firstVertex;
    Vtx* copiedVertices;
    s32 numVertices;
    s32 i;
    s32 temp3;

    mdl_get_copied_vertices(3, &firstVertex, &copiedVertices, &numVertices);

    for (i = 0; i < numVertices; i++) {
        u8* colors = copiedVertices[i].v.cn;
        s16 temp1 = (sins(D_802433B4_A195D4 * (i % 3 + 1) + i) + 0x8000) / 2;
        colors[0] = temp1 * 155 / 0x8000 + 100.0;
        colors[1] = temp1 * 155 / 0x8000 + 80.3921568627451;

        temp3 = sins(D_802433B4_A195D4 / 0x8000 * (((i / 2) % 3 + 1) << 15)  + D_802433B4_A195D4 / 0x4000 * 0x8000 + i) + 0x8000;
        colors[2] = colors[0] * temp3 / 0x10000 + 96.07843137254902;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(3));
    D_802433B4_A195D4 += 0x253;
}

INCLUDE_ASM(s32, "world/area_hos/hos_02/A16220", func_80240EF4_A17114);

INCLUDE_ASM(s32, "world/area_hos/hos_02/A16220", func_80240F68_A17188);
