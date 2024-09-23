#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000280_3DC1C0[];
extern Gfx D_090003B0_3DC2F0[];

Gfx* D_E00E0A40[] = { D_090003B0_3DC2F0, D_09000280_3DC1C0 };

f32 D_E00E0A48[] = {
    0.01f, 0.05f,  0.1f,  0.2f, 0.35f,  0.5f,
    0.65f,  0.8f, 0.95f,  1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f, 0.95f,  0.8f, 0.65f,
     0.5f, 0.35f,  0.2f,  0.1f, 0.05f, 0.01f
};

void embers_init(EffectInstance* effect);
void embers_update(EffectInstance* effect);
void embers_render(EffectInstance* effect);
void embers_appendGfx(void* effect);

EffectInstance* embers_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5,
    f32 arg6,
    s32 arg7,
    s32 arg8,
    f32 arg9,
    f32 argA
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    EmbersFXData* part;
    s32 numParts;
    f32 temp1;
    s32 i;

    arg7++;

    bp.init = embers_init;
    bp.update = embers_update;
    bp.renderWorld = embers_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_EMBERS;

    effect = create_effect_instance(&bp);
    effect->numParts = arg7;
    part = effect->data.embers = general_heap_malloc(arg7 * sizeof(*part));
    ASSERT(effect->data.embers != NULL);

    part->unk_00 = arg0;
    part->lifetime = 0;
    if (arg8 <= 0) {
        part->timeLeft = 1000;
    } else {
        part->timeLeft = arg8;
    }
    part->unk_2C = 0;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_40 = arg6;
    part->unk_10 = arg4;
    part->unk_14 = arg5;
    part->unk_68 = arg9;
    part->unk_6C = argA;
    part->unk_20 = 127;
    part->unk_24 = 0;
    part->unk_28 = 0;
    part->unk_30 = 127;
    part->unk_34 = 127;
    part->unk_38 = 0;
    part->unk_3C = 255;

    temp1 = 30.0f / (arg7 - 1);
    temp1 *= 0.5;

    part++;
    for (i = 1; i < arg7; i++, part++) {
        s32 temp_f0 = -(f32) i * temp1;
        part->unk_64 = temp_f0 - 1;
    }

    return effect;
}

void embers_init(EffectInstance* effect) {
}

void embers_update(EffectInstance* effect) {
    EmbersFXData* part = effect->data.embers;
    f32 unk_10;
    f32 unk_14;
    s32 time;
    f32 unk_68;
    f32 unk_6C;
    s32 i;

    if (effect->flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags &= ~FX_INSTANCE_FLAG_DISMISS;
        part->timeLeft = 16;
    }

    if (part->timeLeft < 1000) {
        part->timeLeft--;
    }

    part->lifetime++;
    if (part->lifetime > 324000) {
        part->lifetime = 256;
    }

    if (part->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    time = part->lifetime;

    if (part->timeLeft < 16) {
        part->unk_2C = part->timeLeft * 16;
    }

    if (time < 16) {
        part->unk_2C = time * 16 + 15;
    }

    unk_10 = part->unk_10;
    unk_14 = part->unk_14;
    unk_68 = part->unk_68;
    unk_6C = part->unk_6C;

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        part->unk_64++;
        if (part->unk_64 >= 30) {
            part->unk_64 = 0;
        }

        if (part->unk_64 >= 0) {
            if (part->unk_64 == 0) {
                part->unk_04 = rand_int(unk_10) - unk_10 * 0.5;
                part->unk_08 = rand_int(unk_14);
                part->unk_0C = 0.0f;
                part->unk_44 = (f32) (rand_int(20) - 10) * 0.05;
                part->unk_48 = (rand_int(40) - 1) * unk_68 * 0.05;
                part->unk_4C = 0.0f;
                part->unk_50 = (f32) (rand_int(20) - 10) * 0.05;
                part->unk_54 = (rand_int(30) - 1) * unk_6C * 0.05;
                part->unk_58 = 0.0f;
                part->unk_5C = rand_int(15);
                part->unk_60 = rand_int(15);
            }
            part->unk_40 = D_E00E0A48[part->unk_64];
            part->unk_04 += part->unk_44;
            part->unk_08 += part->unk_48;
            part->unk_0C += part->unk_4C;
            part->unk_5C += 0.1;
            part->unk_60 += 0.3;
            part->unk_44 += (part->unk_50 - part->unk_44) * 0.04;
            part->unk_48 += (part->unk_54 - part->unk_48) * 0.04;
            part->unk_4C += (part->unk_58 - part->unk_4C) * 0.04;
        }
    }
}

void embers_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = embers_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void func_E00E05F8(void) {
}

void embers_appendGfx(void* effect) {
    EmbersFXData* part = ((EffectInstance*)effect)->data.embers;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 unk_2C = part->unk_2C;
    Matrix4f sp10;
    Matrix4f sp50;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guTranslateF(sp10, part->unk_04, part->unk_08, part->unk_0C);
    guScaleF(sp50, part->unk_40, part->unk_40, part->unk_40);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMainGfxPos++, camera->mtxBillboard, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, part->unk_20, part->unk_24, part->unk_28, unk_2C);
    gDPSetEnvColor(gMainGfxPos++, part->unk_30, part->unk_34, part->unk_38, part->unk_3C);
    gSPDisplayList(gMainGfxPos++, D_E00E0A40[1]);

    part++;
    for (i = 1; i < ((EffectInstance*)effect)->numParts; i++, part++) {
        if (part->unk_64 >= 0) {
            guTranslateF(sp10, part->unk_04, part->unk_08, part->unk_0C);
            guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0, (i % 4) * 16 * 4, 15 * 4, ((i % 4) * 16 + 15) * 4);
            gDPSetTileSize(gMainGfxPos++, 1, (s32) part->unk_5C * 4, (s32) part->unk_60 * 4, ((s32) part->unk_5C + 15) * 4, ((s32) part->unk_60 + 15) * 4);
            gSPDisplayList(gMainGfxPos++, D_E00E0A40[0]);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}
