#include "common.h"
#include "effects_internal.h"

extern Vtx_t D_09001400_333AA0[];
extern Gfx D_09001530_333BD0[];
extern Gfx D_09001650_333CF0[];
extern Gfx D_09001780_333E20[];
extern Gfx D_090017D0_333E70[];

void star_init(EffectInstance* effect);
void star_update(EffectInstance* effect);
void star_render(EffectInstance* effect);
void star_appendGfx(void* effect);

EffectInstance* star_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    EffectBlueprint bp;
    StarFXData* part;
    EffectInstance* effect;
    s32 numParts = 1;
    s32 i;

    f32 temp_f12;
    f32 temp_f20;
    f32 currentYaw;
    f32 sinYaw;
    f32 cosYaw;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f2;
    f32 temp_f4;
    s32 temp_s0;
    f32 phi_f26;

    bp.unk_00 = 0;
    bp.init = star_init;
    bp.update = star_update;
    bp.renderWorld = star_render;
    bp.renderUI = NULL;
    bp.effectID = EFFECT_STAR;

    effect = create_effect_instance(&bp);
    effect->numParts = 1;
    part = effect->data.star = general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.star != NULL);
    part->unk_00 = 1;
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_1C = 0;
    part->unk_24 = 0.0f;
    part->unk_28 = 0;
    part->unk_38 = arg0;

    if (arg0 == 3) {
        part->unk_240 = 0.2f;
        part->unk_244 = rand_int(255);
        part->unk_248 = rand_int(255 - part->unk_244);
        temp_s0 = 255 - part->unk_248;
        part->unk_24C = temp_s0 - part->unk_244;
    } else {
        part->unk_244 = 210;
        part->unk_248 = 186;
        part->unk_24C = 90;
        part->unk_240 = 0.5f;
    }

    temp_f24 = arg4 - arg1;
    temp_f22 = arg5 - arg2;
    temp_f20 = arg6 - arg3;

    temp_f26 = SQ(temp_f24) + SQ(temp_f22) + SQ(temp_f20);
    phi_f26 = temp_f26;
    if (temp_f26 != 0.0f) {
        phi_f26 = sqrtf(temp_f26);
        temp_f26 = arg7 / phi_f26;
    }

    part->unk_10 = temp_f24 * temp_f26;
    part->unk_14 = temp_f22 * temp_f26;
    part->unk_18 = temp_f20 * temp_f26;

    currentYaw = gCameras[gCurrentCameraID].curYaw;
    cosYaw = -cos_deg(currentYaw);
    sinYaw = -sin_deg(currentYaw);

    temp_f4 = cosYaw * part->unk_10;
    temp_f2 = sinYaw * part->unk_18;
    temp_f12 = SQ(temp_f4) + SQ(temp_f2);

    if (temp_f12 != 0.0f) {
        temp_f12 = sqrtf(temp_f12);
    }

    if ((cosYaw * part->unk_10) + (sinYaw * part->unk_18) < 0.0f) {
        temp_f12 = -temp_f12;
        part->unk_2C = -20.0f;
    } else {
        part->unk_2C = 20.0f;
    }

    part->unk_20 = part->unk_24 = atan2(0.0f, 0.0f, -part->unk_14, -temp_f12);
    part->unk_30 = phi_f26 / arg7;
    part->unk_34 = -temp_f12;
    guTranslate(part->unk_40, part->unk_04, part->unk_08, part->unk_0C);

    for (i = 1; i < ARRAY_COUNT(part->unk_40); i++) {
        part->unk_40[i] = part->unk_40[0];
    }

    part->unk_3C = -1;
    return effect;
}

void star_init(EffectInstance* effect) {
}

EFFECT_DEF_LANDING_DUST(landing_dust_main);

void star_update(EffectInstance* effect) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    StarFXData* data = effect->data.star;
    f32 x, y, z, length;
    f32 xTemp, yTemp, zTemp;

    if (data->unk_38 >= 2) {
        length = SQ(data->unk_10) + SQ(data->unk_14) + SQ(data->unk_18);
        if (length > 0.01f) {
            length = 1.0f / sqrtf(length);
        }

        xTemp = data->unk_10 * length * 32.0f;
        yTemp = data->unk_14 * length * 32.0f;
        zTemp = data->unk_18 * length * 32.0f;
        x = data->unk_04 - xTemp;
        y = data->unk_08 - yTemp;
        z = data->unk_0C - zTemp;
        length = 64.0f;

        if (data->unk_00 != 0 &&
            data->unk_14 < 0.0f &&
            npc_raycast_down_sides(0, &x, &y, &z, &length) != 0 &&
            length < 42.0f)
        {
            data->unk_1C = data->unk_1C + 1.0f;
            data->unk_14 = -data->unk_14 * 0.6;
            data->unk_10 = data->unk_10 * 0.7;
            data->unk_34 = data->unk_34 * 0.7;
            data->unk_2C = data->unk_2C * 0.7;
            load_effect(EFFECT_LANDING_DUST);
            landing_dust_main(0, data->unk_04, data->unk_08 - 5.0f, data->unk_0C, 0.0f);

            if (!gGameStatusPtr->isBattle) {
                sfx_play_sound_at_position(SOUND_B0000016, SOUND_SPACE_MODE_0, data->unk_04, data->unk_08, data->unk_0C);
            }

            data->unk_00 = 0;
            if (data->unk_1C >= 10.0f) {
                data->unk_30 = -1;
            }
        }

        if (data->unk_1C != 0.0f) {
            data->unk_14 += -0.5;
            data->unk_24 += data->unk_2C;
            data->unk_20 = atan2(0.0f, 0.0f, -data->unk_14, data->unk_34);
        }
    }

    if (playerStatus->pos.y - data->unk_08 > 300.0f) {
        data->unk_30 = -1;
    }

    data->unk_04 += data->unk_10;
    data->unk_08 += data->unk_14;
    data->unk_0C += data->unk_18;

    if (data->unk_30 < 0) {
        remove_effect(effect);
    }
}

void star_render(EffectInstance* effect) {
    StarFXData* effect15 = effect->data.star;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    s32 renderModeTemp;

    renderTask.appendGfxArg = effect;
    renderTask.appendGfx = star_appendGfx;
    renderTask.dist = 0;
    if (effect15->unk_38 != 0) {
        renderModeTemp = RENDER_MODE_2D;
    } else {
        renderModeTemp = RENDER_MODE_SURF_SOLID_AA_ZB_LAYER0;
    }
    renderTaskPtr->renderMode = renderModeTemp;

    retTask = queue_render_task(&renderTask);
}

void star_appendGfx(void* effect) {
    StarFXData* data = ((EffectInstance*)effect)->data.star;
    f32 unk_240 = data->unk_240;
    s32 unk_38 = data->unk_38;
    s32 unk_244 = data->unk_244;
    s32 unk_248 = data->unk_248;
    s32 unk_24C = data->unk_24C;
    s32 idx;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, unk_240, data->unk_04, data->unk_08, data->unk_0C);
    guRotateF(sp60, data->unk_24, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 80, unk_244, unk_248, unk_24C, 255);
    gDPSetEnvColor(gMainGfxPos++, 127, 127, 127, 127);

    gSPDisplayList(gMainGfxPos++, (data->unk_38 >= 2) ? D_09001650_333CF0 : D_09001530_333BD0);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);

    if (unk_38 == 3) {
        gSPDisplayList(gMainGfxPos++, D_090017D0_333E70);
    } else {
        gSPDisplayList(gMainGfxPos++, D_09001780_333E20);
    }

    data->unk_3C++;
    if (data->unk_3C >= 8) {
        data->unk_3C = 0;
    }

    if (data->unk_1C <= 1.0f) {
        s32 baseIdx = (data->unk_3C + 5) % 8;

        guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, unk_240, data->unk_04, data->unk_08, data->unk_0C);
        guRotateF(sp60, data->unk_20, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp60, sp20, sp20);
        guMtxF2L(sp20, &data->unk_40[data->unk_3C]);

        for (i = 0; i < 5; i++) {
            idx = (baseIdx - i + 8) % 8;
            gDisplayContext->matrixStack[gMatrixListPos] = data->unk_40[idx];

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPVertex(gMainGfxPos++, &D_09001400_333AA0[i * 2], 2, i * 2);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }

        for (i = 0; i < 4; i++) {
            s32 i2 = i * 2;
            gSP2Triangles(gMainGfxPos++,
                i2    , i2 + 1, i2 + 2, i2,
                i2 + 1, i2 + 3, i2 + 2, i2 + 1);
        }

        gDPPipeSync(gMainGfxPos++);
    }
}
