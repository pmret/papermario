#include "hos_04.h"

static char* N(exit_str_0) = "hos_03";
static char* N(exit_str_1) = "hos_05";

extern u16 D_802416F0_A285C0;

void func_80240000_A26ED0(void) {
    f32 temp_f0 = ((sin_rad(D_802416F0_A285C0 * (1 / 32.0f)) + 1.0f) * 0.25f) + 0.75;

    guScale(&gDisplayContext->matrixStack[gMatrixListPos], (temp_f0 * 0.3) + 0.5, temp_f0, (temp_f0 * 0.3) + 0.5);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_802416F0_A285C0++;
}

void func_80240154_A27024(void) {
    f64 t1 = (sin_rad(D_802416F0_A285C0 * (1 / 32.0f)) * 10.0f) + 1.5;
    f64 t2 = sin_rad(D_802416F0_A285C0 * 0.25f) * 2.5;

    guTranslate(&gDisplayContext->matrixStack[gMatrixListPos], 0.0f, t1 + t2, 0.0f);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

#include "world/common/atomic/TexturePan.inc.c"

