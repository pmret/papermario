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

EffectInstance* star_main(s32 type, f32 posX, f32 posY, f32 posZ, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
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
    part->pos.x = posX;
    part->pos.y = posY;
    part->pos.z = posZ;
    part->unk_1C = 0;
    part->angle = 0.0f;
    part->unk_28 = 0;
    part->type = type;

    if (type == 3) {
        part->scale = 0.2f;
        part->primR = rand_int(255);
        part->primG = rand_int(255 - part->primR);
        temp_s0 = 255 - part->primG;
        part->primB = temp_s0 - part->primR;
    } else {
        part->primR = 210;
        part->primG = 186;
        part->primB = 90;
        part->scale = 0.5f;
    }

    temp_f24 = arg4 - posX;
    temp_f22 = arg5 - posY;
    temp_f20 = arg6 - posZ;

    temp_f26 = SQ(temp_f24) + SQ(temp_f22) + SQ(temp_f20);
    phi_f26 = temp_f26;
    if (temp_f26 != 0.0f) {
        phi_f26 = sqrtf(temp_f26);
        temp_f26 = arg7 / phi_f26;
    }

    part->vel.x = temp_f24 * temp_f26;
    part->vel.y = temp_f22 * temp_f26;
    part->vel.z = temp_f20 * temp_f26;

    currentYaw = gCameras[gCurrentCameraID].curYaw;
    cosYaw = -cos_deg(currentYaw);
    sinYaw = -sin_deg(currentYaw);

    temp_f4 = cosYaw * part->vel.x;
    temp_f2 = sinYaw * part->vel.z;
    temp_f12 = SQ(temp_f4) + SQ(temp_f2);

    if (temp_f12 != 0.0f) {
        temp_f12 = sqrtf(temp_f12);
    }

    if ((cosYaw * part->vel.x) + (sinYaw * part->vel.z) < 0.0f) {
        temp_f12 = -temp_f12;
        part->unk_2C = -20.0f;
    } else {
        part->unk_2C = 20.0f;
    }

    part->unk_20 = part->angle = atan2(0.0f, 0.0f, -part->vel.y, -temp_f12);
    part->unk_30 = phi_f26 / arg7;
    part->unk_34 = -temp_f12;
    guTranslate(part->unk_40, part->pos.x, part->pos.y, part->pos.z);

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

    if (data->type >= 2) {
        length = SQ(data->vel.x) + SQ(data->vel.y) + SQ(data->vel.z);
        if (length > 0.01f) {
            length = 1.0f / sqrtf(length);
        }

        xTemp = data->vel.x * length * 32.0f;
        yTemp = data->vel.y * length * 32.0f;
        zTemp = data->vel.z * length * 32.0f;
        x = data->pos.x - xTemp;
        y = data->pos.y - yTemp;
        z = data->pos.z - zTemp;
        length = 64.0f;

        if (data->unk_00 != 0 &&
            data->vel.y < 0.0f &&
            npc_raycast_down_sides(0, &x, &y, &z, &length) != 0 &&
            length < 42.0f)
        {
            data->unk_1C = data->unk_1C + 1.0f;
            data->vel.y = -data->vel.y * 0.6;
            data->vel.x = data->vel.x * 0.7;
            data->unk_34 = data->unk_34 * 0.7;
            data->unk_2C = data->unk_2C * 0.7;
            load_effect(EFFECT_LANDING_DUST);
            landing_dust_main(0, data->pos.x, data->pos.y - 5.0f, data->pos.z, 0.0f);

            if (!gGameStatusPtr->isBattle) {
                sfx_play_sound_at_position(SOUND_SEQ_16, SOUND_SPACE_MODE_0, data->pos.x, data->pos.y, data->pos.z);
            }

            data->unk_00 = 0;
            if (data->unk_1C >= 10.0f) {
                data->unk_30 = -1;
            }
        }

        if (data->unk_1C != 0.0f) {
            data->vel.y += -0.5;
            data->angle += data->unk_2C;
            data->unk_20 = atan2(0.0f, 0.0f, -data->vel.y, data->unk_34);
        }
    }

    if (playerStatus->pos.y - data->pos.y > 300.0f) {
        data->unk_30 = -1;
    }

    data->pos.x += data->vel.x;
    data->pos.y += data->vel.y;
    data->pos.z += data->vel.z;

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
    if (effect15->type != 0) {
        renderModeTemp = RENDER_MODE_2D;
    } else {
        renderModeTemp = RENDER_MODE_SURF_SOLID_AA_ZB_LAYER0;
    }
    renderTaskPtr->renderMode = renderModeTemp;

    retTask = queue_render_task(&renderTask);
}

void star_appendGfx(void* effect) {
    StarFXData* data = ((EffectInstance*)effect)->data.star;
    f32 scale = data->scale;
    s32 type = data->type;
    s32 primR = data->primR;
    s32 primG = data->primG;
    s32 primB = data->primB;
    s32 idx;
    Matrix4f sp20;
    Matrix4f sp60;
    s32 i;

    gDPPipeSync(gMainGfxPos++);
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, scale, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(sp60, data->angle, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 80, primR, primG, primB, 255);
    gDPSetEnvColor(gMainGfxPos++, 127, 127, 127, 127);

    gSPDisplayList(gMainGfxPos++, (data->type >= 2) ? D_09001650_333CF0 : D_09001530_333BD0);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);

    if (type == 3) {
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
        guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, scale, data->pos.x, data->pos.y, data->pos.z);
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
