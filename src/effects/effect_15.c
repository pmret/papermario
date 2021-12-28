#include "common.h"
#include "effects_internal.h"

void fx_15_init(EffectInstance* effect);
void fx_15_update(EffectInstance* effect);
void fx_15_render(EffectInstance* effect);
void fx_15_appendGfx(EffectInstance* effect);

EffectInstance* fx_15_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    EffectBlueprint bp;
    Effect15* part;
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
    bp.init = fx_15_init;
    bp.update = fx_15_update;
    bp.renderWorld = fx_15_render;
    bp.unk_14 = 0;
    bp.effectIndex = 15;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = 1;
    part = effect->data = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data != NULL);
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
        part->unk_244 = shim_rand_int(255);
        part->unk_248 = shim_rand_int(255 - part->unk_244);
        temp_s0 = (255 - part->unk_248);
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
        phi_f26 = shim_sqrtf(temp_f26);
        temp_f26 = arg7 / phi_f26;
    }

    part->unk_10 = temp_f24 * temp_f26;
    part->unk_14 = temp_f22 * temp_f26;
    part->unk_18 = temp_f20 * temp_f26;

    currentYaw = gCameras[gCurrentCameraID].currentYaw;
    cosYaw = -shim_cos_deg(currentYaw);
    sinYaw = -shim_sin_deg(currentYaw);

    temp_f4 = cosYaw * part->unk_10;
    temp_f2 = sinYaw * part->unk_18;
    temp_f12 = SQ(temp_f4) + SQ(temp_f2);

    if (temp_f12 != 0.0f) {
        temp_f12 = shim_sqrtf(temp_f12);
    }

    if ((cosYaw * part->unk_10) + (sinYaw * part->unk_18) < 0.0f) {
        temp_f12 = -temp_f12;
        part->unk_2C = -20.0f;
    } else {
        part->unk_2C = 20.0f;
    }

    part->unk_20 = part->unk_24 = shim_atan2(0.0f, 0.0f, -part->unk_14, -temp_f12);
    part->unk_30 = phi_f26 / arg7;
    part->unk_34 = -temp_f12;
    shim_guTranslate(part->unk_40, part->unk_04, part->unk_08, part->unk_0C);

    for (i = 1; i < ARRAY_COUNT(part->unk_40); i++) {
        part->unk_40[i] = part->unk_40[0];
    }

    part->unk_3C = -1;
    return effect;
}

void fx_15_init(EffectInstance* effect) {
}

void fx_15_update(EffectInstance* effect) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Effect15* data = effect->data;
    f32 x, y, z, length;
    f32 xTemp, yTemp, zTemp;

    if (data->unk_38 >= 2) {
        length = SQ(data->unk_10) + SQ(data->unk_14) + SQ(data->unk_18);
        if (length > 0.01f) {
            length = 1.0f / shim_sqrtf(length);
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
            shim_npc_raycast_down_sides(0, &x, &y, &z, &length) != 0 &&
            length < 42.0f)
        {
            data->unk_1C = data->unk_1C + 1.0f;
            data->unk_14 = -data->unk_14 * 0.6;
            data->unk_10 = data->unk_10 * 0.7;
            data->unk_34 = data->unk_34 * 0.7;
            data->unk_2C = data->unk_2C * 0.7;
            shim_load_effect(6);
            fx_6_main(0, data->unk_04, data->unk_08 - 5.0f, data->unk_0C, 0.0f);

            if (!gGameStatusPtr->isBattle) {
                shim_sfx_play_sound_at_position(0xB0000016, 0, data->unk_04, data->unk_08, data->unk_0C);
            }

            data->unk_00 = 0;
            if (data->unk_1C >= 10.0f) {
                data->unk_30 = -1;
            }
        }

        if (data->unk_1C != 0.0f) {
            data->unk_14 += -0.5;
            data->unk_24 += data->unk_2C;
            data->unk_20 = shim_atan2(0.0f, 0.0f, -data->unk_14, data->unk_34);
        }
    }

    if (playerStatus->position.y - data->unk_08 > 300.0f) {
        data->unk_30 = -1;
    }

    data->unk_04 += data->unk_10;
    data->unk_08 += data->unk_14;
    data->unk_0C += data->unk_18;

    if (data->unk_30 < 0) {
        shim_remove_effect(effect);
    }
}

void fx_15_render(EffectInstance* effect) {
    Effect15* effect15 = effect->data;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    s32 renderModeTemp;

    renderTask.appendGfxArg = effect;
    renderTask.appendGfx = fx_15_appendGfx;
    renderTask.distance = 0;
    if (effect15->unk_38 != 0) {
        renderModeTemp = RENDER_MODE_2D;
    } else {
        renderModeTemp = RENDER_MODE_SURF_SOLID_AA_ZB_LAYER0;
    }
    renderTaskPtr->renderMode = renderModeTemp;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/effect_15", fx_15_appendGfx);
