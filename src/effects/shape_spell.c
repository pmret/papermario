#include "common.h"
#include "effects_internal.h"

typedef struct UnkStruct {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ Gfx* unk_04;
    /* 0x08 */ Gfx* unk_08;
} UnkStruct; // size = 0xC

extern Gfx D_09001080_33AFE0[];
extern Gfx D_09001128_33B088[];
extern Gfx D_09001150_33B0B0[];
extern Gfx D_09001178_33B0D8[];
extern Gfx D_090011A0_33B100[];
extern Gfx D_090011C8_33B128[];
extern Gfx D_090011F0_33B150[];

UnkStruct D_E0024CC0[] = {
    {   0, 255, 208,  26, D_09001128_33B088, D_090011A0_33B100 },
    { 120,  77, 208, 254, D_09001150_33B0B0, D_090011C8_33B128 },
    { 240, 254,  76, 110, D_09001178_33B0D8, D_090011F0_33B150 }
};

void shape_spell_appendGfx(void* effect);
void shape_spell_init(EffectInstance* effect);
void shape_spell_update(EffectInstance* effect);
void shape_spell_render(EffectInstance* effect);

EffectInstance* shape_spell_main(s32 isChild, f32 x, f32 y, f32 z, f32 arg4, f32 arg5, f32 arg6, s32 arg7) {
    EffectBlueprint bp;
    EffectBlueprint* bpPtr = &bp;
    EffectInstance* effect;
    ShapeSpellFXData* part;
    s32 numParts = 1;

    bp.init = shape_spell_init;
    bp.update = shape_spell_update;
    bp.renderWorld = shape_spell_render;
    bp.unk_00 = 0;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_SHAPE_SPELL;

    effect = create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data.shapeSpell = general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.shapeSpell != NULL);

    part->unk_2C = 0;
    part->isChild = isChild;
    part->unk_34 = 255;
    part->pos.x = x;
    part->pos.y = y;
    part->pos.z = z;
    part->unk_28 = 1.0f;
    if (!isChild) {
        part->unk_10 = 0;
        part->unk_14 = 0.0f;
        part->unk_18 = 0.0f;
        part->timeLeft = arg7;
        part->unk_1C = (arg4 - x) * (1.0f / arg7);
        part->unk_20 = (arg5 - y) * (1.0f / arg7);
        part->unk_24 = (arg6 - z) * (1.0f / arg7);
    } else {
        part->unk_10 = 29.f;
        part->unk_14 = 0.0f;
        part->unk_18 = 0.0f;
        part->unk_1C = 6.2f;
        part->unk_20 = 0.0f;
        part->unk_24 = 0.0f;
        part->timeLeft = 24;
    }

    return effect;
}

void shape_spell_init(EffectInstance* effect) {
}

void shape_spell_update(EffectInstance* effect) {
    s32 flags = effect->flags;
    ShapeSpellFXData* part = effect->data.shapeSpell;
    s32 isChild;

    if (flags & FX_INSTANCE_FLAG_DISMISS) {
        effect->flags = flags & ~FX_INSTANCE_FLAG_DISMISS;
        part->timeLeft = 0;
    }

    part->timeLeft--;
    part->unk_2C++;

    if (part->timeLeft < 0) {
        remove_effect(effect);
        return;
    }

    isChild = part->isChild;

    if (!isChild && part->timeLeft == 0) {
        ShapeSpellFXData* newPart = shape_spell_main(
            1,
            part->pos.x + part->unk_10,
            part->pos.y + part->unk_14,
            part->pos.z + part->unk_18,
            0.0f, 0.0f, 0.0f, 0x18
        )->data.shapeSpell;
        newPart->unk_28 = part->unk_28;
    }

    if (isChild == TRUE) {
        part->unk_34 = part->unk_34 * 0.9;
        part->unk_1C = part->unk_1C * 0.83;
    }
    part->unk_10 += part->unk_1C;
    part->unk_14 += part->unk_20;
    part->unk_18 += part->unk_24;
}

void shape_spell_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shape_spell_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.dist = 0;
    renderTask.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;

    retTask = queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

s32 func_E0024324(s32 arg0, s32 arg1) {
    s32 frameCounter = gGameStatusPtr->frameCounter * 32;

    return (f32)((sin_deg(frameCounter + arg1) * (255 - arg0) + (255 - arg0)) * 0.5 + arg0);
}

s32 func_E00243BC(s32 arg0, s32 arg1) {
    s32 frameCounter = gGameStatusPtr->frameCounter * 32;

    arg1 += 180;

    return (f32)((sin_deg(frameCounter + arg1) * -arg0 + -arg0) * 0.5 + arg0);
}

void shape_spell_appendGfx(void* effect) {
    ShapeSpellFXData* data = ((EffectInstance*)effect)->data.shapeSpell;
    s32 isChild;
    Gfx* savedGfxPos2;
    Gfx* savedGfxPos;
    f32 unk_28 = data->unk_28;
    s32 primA;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 angle;
    f32 factor;
    f32 var_f30;
    s32 timeLeft;
    Matrix4f sp20;
    Mtx* sp60[3];
    Mtx* mtx;
    s32 i;
    s32 j;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
    gSPDisplayList(gMainGfxPos++, D_09001080_33AFE0);

    savedGfxPos = gMainGfxPos++;
    savedGfxPos2 = gMainGfxPos;
    isChild = data->isChild;
    primA = data->unk_34;
    unk_10 = data->unk_10;
    unk_14 = data->unk_14;
    unk_18 = data->unk_18;
    timeLeft = data->timeLeft;

    if (isChild == 0) {
        angle = timeLeft * 35;
        factor = 9.0f;
        var_f30 = -gCameras[gCurrentCameraID].curYaw;
    } else {
        angle = timeLeft * 25;
        factor = 6.0f;
        var_f30 = 0.0f;
        unk_10 *= unk_28;
    }

    for (i = 0; i < 3; i++) {
        if (i > 0) {
            if (!isChild) {
                angle -= 70.0f;
                unk_10 -= 2.0f * data->unk_1C;
                unk_14 -= 2.0f * data->unk_20;
                unk_18 -= 2.0f * data->unk_24;
            } else {
                angle -= 50.0f;
                unk_10 -= data->unk_1C * (100.0 / 83) * 2.0;
            }
            primA = data->unk_34 * 100 / 255;
        }

        guPositionF(sp20, 0.0f, var_f30, 0.0f, unk_28, unk_10, unk_14, unk_18);
        guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        guTranslateF(sp20,
            sin_deg(angle) * factor,
            cos_deg(angle) * factor, 0.0f);

        angle += 120.0f;
        sp60[0] = &gDisplayContext->matrixStack[gMatrixListPos++];

        guMtxF2L(sp20, sp60[0]);
        guTranslateF(sp20,
            sin_deg(angle) * factor,
            cos_deg(angle) * factor, 0.0f);

        angle += 120.0f;
        sp60[1] = &gDisplayContext->matrixStack[gMatrixListPos++];

        guMtxF2L(sp20, sp60[1]);
        guTranslateF(sp20,
            sin_deg(angle) * factor,
            cos_deg(angle) * factor, 0.0f);

        sp60[2] = &gDisplayContext->matrixStack[gMatrixListPos++];

        guMtxF2L(sp20, sp60[2]);

        for (j = 0; j < 3; j++) {
            gSPMatrix(gMainGfxPos++, sp60[j], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPSetPrimColor(gMainGfxPos++, 0, 0,
                func_E00243BC(D_E0024CC0[j].unk_01, D_E0024CC0[j].unk_00),
                func_E00243BC(D_E0024CC0[j].unk_02, D_E0024CC0[j].unk_00),
                func_E00243BC(D_E0024CC0[j].unk_03, D_E0024CC0[j].unk_00),
                primA);
            gDPSetEnvColor(gMainGfxPos++,
                func_E0024324(D_E0024CC0[j].unk_01, D_E0024CC0[j].unk_00),
                func_E0024324(D_E0024CC0[j].unk_02, D_E0024CC0[j].unk_00),
                func_E0024324(D_E0024CC0[j].unk_03, D_E0024CC0[j].unk_00),
                255);
            gSPDisplayList(gMainGfxPos++, !isChild ?
                D_E0024CC0[j].unk_04 : D_E0024CC0[j].unk_08);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }

        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    gSPEndDisplayList(gMainGfxPos++);
    gSPBranchList(savedGfxPos, gMainGfxPos);

    if (!isChild) {
        var_f30 = 0.0f;
    } else {
        var_f30 = -gCameras[gCurrentCameraID].curYaw;
    }

    guPositionF(sp20, 0.0f, var_f30, 0.0f, 1.0f, data->pos.x, data->pos.y, data->pos.z);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (!isChild) {
        gSPDisplayList(gMainGfxPos++, savedGfxPos2);
    } else {
        guRotateF(sp20, 30.0f, 0.0f, 0.0f, 1.0f);

        mtx = &gDisplayContext->matrixStack[gMatrixListPos++];
        guMtxF2L(sp20, mtx);

        for (i = 0; i < 12; i++) {
            gSPMatrix(gMainGfxPos++, mtx, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, savedGfxPos2);
        }
    }

    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);
}
