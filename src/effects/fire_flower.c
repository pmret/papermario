#include "common.h"
#include "effects_internal.h"

extern char D_09000000[][0x200];
extern Gfx D_09000D40[];
extern Gfx D_09000DE0[];
extern Gfx D_09000EB8[];
extern Gfx D_09000ED8[];
extern Gfx D_09000EF8[];
extern s8 D_E007EC2F[];

s32 D_E007EC30[] = { 0x323C4650, 0x5A646964 };

void fire_flower_appendGfx(void* effect);
void fire_flower_init(EffectInstance* effect);
void fire_flower_update(EffectInstance* effect);
void fire_flower_render(EffectInstance* effect);

EffectInstance* fire_flower_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    FireFlowerFXData* part;
    Vec3i* partData;
    s32 numParts = 31;
    s32 i;

    bp.unk_00 = 0;
    bp.init = fire_flower_init;
    bp.update = fire_flower_update;
    bp.renderWorld = fire_flower_render;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_FIRE_FLOWER;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    part = shim_general_heap_malloc(numParts * sizeof(*part));
    effect->data.fireFlower = part;

    ASSERT(effect->data.fireFlower != NULL);

    part->unk_04 = 0;
    part->unk_00 = arg0;
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;
    part->unk_40.x = arg4;
    part->unk_40.y = 0;
    part->unk_34 = 0;
    part->unk_38 = 0;
    part->unk_28 = 0;

    part->unk_3C = 255;
    part->unk_30 = 0.5f;
    part->unk_2C = -10.0f;

    part++;

    for (i = 1; i < numParts; i++, part++) {
        partData = &part->unk_40;
        part->unk_00 = 1;
        part->pos.x = 0;
        part->pos.y = 0;
        part->pos.z = 0;
        part->unk_14 = 8.0f;
        part->unk_18 = 0;
        part->unk_1C = func_E0200000(20) - 8;
        part->unk_20 = (func_E0200000(10) - 5) * 0.05;
        part->unk_24 = func_E0200000(80) + 5;
        part->unk_3C = 255;
        partData->z = i - 1;
        partData->x = 10;
    }

    return effect;
}

void fire_flower_init(EffectInstance* effect) {
}

void fire_flower_update(EffectInstance* effect) {
    FireFlowerFXData* part = effect->data.fireFlower;
    s32 unk_04;
    s32 unk_40X;
    s32 i;

    part->unk_40.y++;
    part->unk_40.x++;

    unk_04 = part->unk_04;
    unk_40X = part->unk_40.x;

    if (unk_04 == 7) {
        shim_remove_effect(effect);
        return;
    }

    switch (unk_04) {
        case 0:
            shim_load_effect(45);
            stars_spread_main(0, part->pos.x - 10.0f, part->pos.y, part->pos.z, 7, 20);
            part->unk_34 = 0;
            part->unk_38 = 0;
            part->unk_40.x = 0;
            part->unk_04++;
            break;
        case 1:
            if (unk_40X >= 8) {
                part->unk_40.x = 0;
                part->unk_04++;
            } else {
                part->unk_30 = D_E007EC2F[unk_40X] * 0.01;
                part->unk_34 = 0;
                part->unk_38 = 0;
            }
            break;
        case 2:
            if (unk_40X >= 2) {
                part->unk_40.x = 0;
                part->unk_04++;
            } else {
                part->unk_34 = 1;
            }
            break;
        case 3:
            if (unk_40X >= 15) {
                part->unk_40.x = 0;
                part->unk_04++;
            } else {
                part->unk_34 = 2;
            }
            break;
        case 4:
            if (unk_40X >= 45) {
                part->unk_40.x = 0;
                part->unk_04++;
            } else {
                part->unk_34 = 3;
                part->unk_2C = 0;
                if (unk_40X % 2) {
                    part->unk_30 = 1.0f;
                } else {
                    part->unk_30 = 1.05f;
                }
            }
            break;
        case 5:
            if (unk_40X >= 10) {
                part->unk_40.x = 0;
                part->unk_04++;
            } else {
                part->unk_34 = 0;
                part->unk_2C = -10.0f;
            }
            break;
        case 6:
            part->unk_28 += 36.0f;
            part->unk_34 = 0;
            part->unk_3C *= 0.9;
            if (part->unk_28 >= 720.0f) {
                part->unk_28 = 720.0f;
                part->unk_04++;
            }
            break;
    }

    unk_04 = part->unk_04;
    part++;

    if (unk_04 == 4 || unk_04 == 5 || unk_04 == 6) {
        for (i = 1; i < effect->numParts; i++, part++) {
            if (part->unk_40.z <= 0 || --part->unk_40.z <= 0) {
                part->unk_18 += part->unk_20;
                part->pos.x += part->unk_14;
                part->pos.y += part->unk_18;
                part->pos.z += part->unk_1C;

                if (unk_04 == 4 && part->pos.x > 200.0f) {
                    part->pos.x = 0;
                    part->pos.y = 0;
                    part->unk_18 = 0;
                    part->pos.z = 0;
                }
            }
        }
    }
}

void fire_flower_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fire_flower_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void fire_flower_appendGfx(void* effect) {
    FireFlowerFXData* part = ((EffectInstance*)effect)->data.fireFlower;
    s32 unk_34 = part->unk_34;
    f32 unk_30 = part->unk_30;
    s32 unk_04 = part->unk_04;
    f32 unk_28 = part->unk_28;
    f32 unk_2C = part->unk_2C;
    Matrix4f sp18;
    Matrix4f sp58;
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    shim_guTranslateF(sp18, part->pos.x, part->pos.y, part->pos.z);
    shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 255, 0, 0, part->unk_3C);
    gDPSetEnvColor(gMasterGfxPos++, 255, 0, 0, part->unk_38);

    if ((u32) (unk_04 - 4) < 3U) {
        shim_guTranslateF(sp18, 0.0f, 16.0f, 0.0f);
        shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_09000DE0);

        part++;
        for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
            if (part->unk_40.z == 0) {
                shim_guRotateF(sp18, part->unk_24, 0.0f, 0.0f, 1.0f);
                shim_guTranslateF(sp58, part->pos.x, part->pos.y, part->pos.z);
                shim_guMtxCatF(sp58, sp18, sp18);
                shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

                gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                gSPDisplayList(gMasterGfxPos++, part->unk_00 != 0 ? D_09000ED8 : D_09000EB8);
                gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
            }
        }

        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    gSPDisplayList(gMasterGfxPos++, D_09000D40);
    gDPLoadTextureTile_4b(
        gMasterGfxPos++, D_09000000[3 - unk_34],
        G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0,
        G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP,
        5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiTile_4b(
        gMasterGfxPos++, D_09000000[2 - unk_34],
        0x0080, 1, G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0,
        G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP,
        5, 5, G_TX_NOLOD, G_TX_NOLOD);

    shim_guTranslateF(sp18, unk_2C, 0.0f, 0.0f);
    shim_guScaleF(sp58, unk_30, unk_30, unk_30);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guRotateF(sp58, unk_28, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_09000EF8);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
