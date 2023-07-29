#include "common.h"
#include "effects_internal.h"

extern Gfx D_09003F98_3FE448[];
extern Gfx D_09004010_3FE4C0[];
extern Gfx D_09004088_3FE538[];
extern Gfx D_09004100_3FE5B0[];
extern Gfx D_09004178_3FE628[];
extern Gfx D_090041F0_3FE6A0[];
extern Gfx D_09004268_3FE718[];
extern Gfx D_090042E0_3FE790[];
extern Gfx D_09004360_3FE810[];
extern Gfx D_09004458_3FE908[];
extern Gfx D_09004508_3FE9B8[];
extern Gfx D_09004600_3FEAB0[];

Gfx* D_E0116C60[] = { D_09004458_3FE908 };

Gfx* D_E0116C64[] = { D_09004600_3FEAB0 };

Gfx* D_E0116C68[] = { D_09004360_3FE810 };

Gfx* D_E0116C6C[] = { D_09004508_3FE9B8 };

Gfx* D_E0116C70[] = {
    D_09003F98_3FE448, D_09004010_3FE4C0, D_09004088_3FE538,
    D_09004100_3FE5B0, D_09004178_3FE628, D_090041F0_3FE6A0,
    D_09004268_3FE718
};

Color_RGB8 D_E0116C8C[] = {
    { 255, 224,  65 },
    { 244, 227,  72 },
    { 211, 220,  22 },
    { 152, 214, 222 },
    { 211, 138, 239 },
    { 231, 174, 219 },
    { 255, 200,  11 },
    {   0,   0,   0 }
};

s16 D_E0116CA4[] = {
    0, 60, 120, 180, 240, 300,
    0, 60, 120, 180, 240, 300,
    0, 60, 120, 180, 240, 300,
    0, 60, 120, 180, 240, 300,
    0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330, 345, 353, 357, 359,
    0
};

u8 D_E0116CF8[] = {
    2, 20, 40, 60, 80, 100, 120, 160, 180, 200, 220, 240, 255
};

u8 D_E0116D08[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 20, 40, 60, 80, 100, 120, 160, 180, 200, 220, 240, 255
};

u8 D_E0116D3C[] = {
    255, 255, 255, 255, 255, 255, 255, 225, 185, 165, 148, 128,
    255, 255, 255, 255, 255, 255, 255, 225, 185, 165, 148, 128,
    255, 255, 255, 255, 255, 255, 255, 225, 185, 165, 148, 128,
    255, 255, 255, 255, 255, 255, 255, 225, 185, 165, 148, 128
};

u8 D_E0116D6C[] = {
    50, 80, 100, 105, 107, 108, 108, 108, 108, 108, 108, 107, 105, 100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50
};

void something_rotating_init(EffectInstance* effect);
void something_rotating_update(EffectInstance* effect);
void something_rotating_render(EffectInstance* effect);
void something_rotating_appendGfx(void* effect);

EffectInstance* something_rotating_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    SomethingRotatingFXData* part;
    s32 numParts = 8;
    s32 i;

    bp.init = something_rotating_init;
    bp.update = something_rotating_update;
    bp.renderWorld = something_rotating_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_SOMETHING_ROTATING;

    effect = create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.somethingRotating = general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.somethingRotating != NULL);

    part->unk_00 = arg0;
    part->unk_14 = 0;
    if (arg5 <= 0) {
        part->unk_10 = 1000;
    } else {
        part->unk_10 = arg5;
    }
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;
    part->unk_18 = arg4;
    part->unk_1C = 30.0f;
    part->unk_20 = 0;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        part->primAlpha = 0;
        part->unk_18 = arg4 * 0.5;
        part->env.r = 255;
        part->env.g = 255;
        part->env.b = 0;
        part->unk_25 = 0;
        part->unk_1C = 30.0f;
        part->unk_20 = 0;
        part->state = 0;
        part->unk_2C = 50.0f;
    }

    return effect;
}

void something_rotating_init(EffectInstance* effect) {
}

void something_rotating_update(EffectInstance* effect) {
    SomethingRotatingFXData* part = effect->data.somethingRotating;
    f32 x = part->pos.x;
    f32 y = part->pos.y;
    f32 z = part->pos.z;
    s32 unk_14;
    s32 unk_14_2;
    f32 factor;
    f32 angle1;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        part->unk_10 = 32;
    }

    if (part->unk_10 < 1000) {
        part->unk_10--;
    }

    part->unk_14++;

    if (part->unk_10 < 0) {
        remove_effect(effect);
        return;
    }

    unk_14 = part->unk_14;
    part->unk_20 = 90.0f;
    angle1 = 90.0f;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        f32 angle2 = unk_14 * 4.0f + (f32) i * 51.43;
        f32 temp_f24 = sin_deg(angle2);
        f32 temp_f22 = part->unk_2C;

        part->pos.x = x + temp_f22 * sin_deg(angle1) * temp_f24;
        part->pos.y = y + temp_f22 * cos_deg(angle2);
        part->pos.z = z + temp_f22 * cos_deg(angle1) * temp_f24;

        switch (part->state) {
            case 1:
                part->unk_14 = 0;
                part->state++;
                // fallthrough
            case 2:
                unk_14_2 = part->unk_14;

                if (unk_14_2 < ARRAY_COUNT(D_E0116CA4)) {
                    part->unk_20 = D_E0116CA4[unk_14_2];
                } else {
                    part->unk_20 = D_E0116CA4[ARRAY_COUNT(D_E0116CA4) - 1];
                }
                if (unk_14_2 < ARRAY_COUNT(D_E0116CF8)) {
                    part->primAlpha = D_E0116CF8[unk_14_2];
                } else {
                    part->primAlpha = D_E0116CF8[ARRAY_COUNT(D_E0116CF8) - 1];
                }
                if (unk_14_2 < ARRAY_COUNT(D_E0116D08)) {
                    part->unk_25 = D_E0116D08[unk_14_2];
                } else {
                    part->unk_25 = D_E0116D08[ARRAY_COUNT(D_E0116D08) - 1];
                }

                if (unk_14_2 < ARRAY_COUNT(D_E0116D3C)) {
                    factor = D_E0116D3C[unk_14_2];
                } else {
                    factor = D_E0116D3C[ARRAY_COUNT(D_E0116D3C) - 1];
                }

                factor *= 0.0039215686; // 1 / 255
                part->env.r = factor * D_E0116C8C[i - 1].r;
                part->env.g = factor * D_E0116C8C[i - 1].g;
                part->env.b = factor * D_E0116C8C[i - 1].b;

                if (unk_14_2 < ARRAY_COUNT(D_E0116D6C)) {
                    part->unk_18 = (f32) D_E0116D6C[unk_14_2] * 0.01;
                } else {
                    part->unk_18 = (f32) D_E0116D6C[ARRAY_COUNT(D_E0116D6C) - 1] * 0.01;
                }

                break;
            case 3:
                part->unk_14 = 0;
                part->state++;
                // fallthrough
            case 4:
                unk_14_2 = part->unk_14;

                if (unk_14_2 < 18) {
                    part->unk_2C = (sin_deg(90 - unk_14_2 * 10) + 1.0f) * 50.0f * 0.5;
                } else {
                    part->unk_2C = 0.0f;
                    part->state++;
                }

                break;
            case 5:
                break;
        }

        part->unk_14++;
    }
}

void something_rotating_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = something_rotating_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E01166E8(s32 arg0, SomethingRotatingFXData* part) {
    f32 temp;
    Matrix4f sp20;
    Matrix4f sp60;

    if (arg0 == 0) {
        temp = gCameras[gCurrentCameraID].curYaw;
    } else {
        temp = 0.0f;
    }

    guPositionF(sp20, 0.0f, part->unk_20 - temp, 0.0f, part->unk_18,
        part->pos.x + 2.0f,
        part->pos.y,
        part->pos.z + 2.0f
    );
    guRotateF(sp60, part->unk_1C, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp60, sp20, sp20);
    guTranslateF(sp60, 0.0f, 0.0f, -2.0f);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void something_rotating_appendGfx(void* effect) {
    SomethingRotatingFXData* data = ((EffectInstance*)effect)->data.somethingRotating;
    s32 unk_14 = data->unk_14;
    s32 l, t;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    gSPDisplayList(gMainGfxPos++, D_090042E0_3FE790);
    gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, 255);

    data++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, data++) {
        if (data->state != 5) {
            func_E01166E8(1, data);
            if (data->primAlpha != 255) {
                gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, data->primAlpha);
                gDPSetEnvColor(gMainGfxPos++, data->env.r, data->env.g, data->env.b, 0x78);
                gSPDisplayList(gMainGfxPos++, D_E0116C6C[0]);

                l = ((unk_14 * 4.0f) * 100.0f) * (1.0 / 1024);
                t = ((unk_14 * 4.0f) * 40.0f) * (1.0 / 1024);
                gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, l, t, l + 0xFC, t + 0xFC);

                l = ((unk_14 * 4.0f) * 200.0f) * (1.0 / 1024);
                t = ((unk_14 * 4.0f) * 90.0f) * (1.0 / 1024);
                gDPSetTileSize(gMainGfxPos++, 1, l, t, l + 0xFC, t + 0xFC);
                gSPDisplayList(gMainGfxPos++, D_E0116C64[0]);
            } else {
                gSPDisplayList(gMainGfxPos++, D_E0116C68[0]);
                gDPSetEnvColor(gMainGfxPos++, data->env.r, data->env.g, data->env.b, data->unk_25);
                gSPDisplayList(gMainGfxPos++, D_E0116C70[i - 1]);
                gSPDisplayList(gMainGfxPos++, D_E0116C60[0]);
            }
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }
}
