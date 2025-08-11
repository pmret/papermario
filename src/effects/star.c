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

EffectInstance* star_main(s32 type, f32 startX, f32 startY, f32 startZ, f32 endX, f32 endY, f32 endZ, f32 speed) {
    EffectBlueprint bp;
    StarFXData* part;
    EffectInstance* effect;
    s32 numParts = 1;
    s32 i;

    f32 projVel;
    f32 dz;
    f32 currentYaw;
    f32 sinYaw;
    f32 cosYaw;
    f32 dy;
    f32 dx;
    f32 norm;
    f32 projVz;
    f32 projVx;
    s32 temp_s0;
    f32 length;

    bp.unk_00 = 0;
    bp.init = star_init;
    bp.update = star_update;
    bp.renderScene = star_render;
    bp.renderUI = nullptr;
    bp.effectID = EFFECT_STAR;

    effect = create_effect_instance(&bp);
    effect->numParts = 1;
    part = effect->data.star = general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data.star != nullptr);
    part->canBounce = true;
    part->pos.x = startX;
    part->pos.y = startY;
    part->pos.z = startZ;
    part->bounceTime = 0.0f;
    part->starAngle = 0.0f;
    part->unk_28 = 0.0f;
    part->type = type;

    if (type == FX_STAR_SMALL_BOUNCING) {
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

    dx = endX - startX;
    dy = endY - startY;
    dz = endZ - startZ;

    norm = SQ(dx) + SQ(dy) + SQ(dz);
    length = norm;
    if (norm != 0.0f) {
        length = sqrtf(norm);
        norm = speed / length;
    }

    part->vel.x = dx * norm;
    part->vel.y = dy * norm;
    part->vel.z = dz * norm;

    currentYaw = gCameras[gCurrentCameraID].curYaw;
    cosYaw = -cos_deg(currentYaw);
    sinYaw = -sin_deg(currentYaw);

    projVx = cosYaw * part->vel.x;
    projVz = sinYaw * part->vel.z;
    projVel = SQ(projVx) + SQ(projVz);

    if (projVel != 0.0f) {
        projVel = sqrtf(projVel);
    }

    if ((cosYaw * part->vel.x) + (sinYaw * part->vel.z) < 0.0f) {
        projVel = -projVel;
        part->starAngleVel = -20.0f;
    } else {
        part->starAngleVel = 20.0f;
    }

    part->trailAngle = part->starAngle = atan2(0.0f, 0.0f, -part->vel.y, -projVel);
    part->timeLeft = length / speed;
    part->projVel = -projVel;
    guTranslate(&part->trailMatrices[0], part->pos.x, part->pos.y, part->pos.z);

    for (i = 1; i < ARRAY_COUNT(part->trailMatrices); i++) {
        part->trailMatrices[i] = part->trailMatrices[0];
    }

    part->trailMatrixPos = -1;
    return effect;
}

void star_init(EffectInstance* effect) {
}

EFFECT_DEF_LANDING_DUST(landing_dust_main);

void star_update(EffectInstance* effect) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    StarFXData* data = effect->data.star;
    f32 traceStartX, traceStartY, traceStartZ, length;
    f32 dx, dy, dz;

    if (data->type >= FX_STAR_LARGE_BOUNCING) {
        length = SQ(data->vel.x) + SQ(data->vel.y) + SQ(data->vel.z);
        if (length > 0.01f) {
            length = 1.0f / sqrtf(length);
        }

        dx = data->vel.x * length * 32.0f;
        dy = data->vel.y * length * 32.0f;
        dz = data->vel.z * length * 32.0f;
        traceStartX = data->pos.x - dx;
        traceStartY = data->pos.y - dy;
        traceStartZ = data->pos.z - dz;
        length = 64.0f;

        if (data->canBounce
            && data->vel.y < 0.0f
            && npc_raycast_down_sides(0, &traceStartX, &traceStartY, &traceStartZ, &length) != 0
            && length < 42.0f
        ) {
            data->bounceTime += 1.0f;
            data->vel.y = -data->vel.y * 0.6;
            data->vel.x = data->vel.x * 0.7;
            data->projVel *= 0.7;
            data->starAngleVel *= 0.7;
            load_effect(EFFECT_LANDING_DUST);
            landing_dust_main(0, data->pos.x, data->pos.y - 5.0f, data->pos.z, 0.0f);

            if (gGameStatusPtr->context == CONTEXT_WORLD) {
                sfx_play_sound_at_position(SOUND_SEQ_SHOOTING_STAR_BOUNCE, SOUND_SPACE_DEFAULT, data->pos.x, data->pos.y, data->pos.z);
            }

            data->canBounce = false;
            if (data->bounceTime >= 10.0f) {
                data->timeLeft = -1;
            }
        }

        if (data->bounceTime != 0.0f) {
            data->vel.y += -0.5;
            data->starAngle += data->starAngleVel;
            data->trailAngle = atan2(0.0f, 0.0f, -data->vel.y, data->projVel);
        }
    }

    if (playerStatus->pos.y - data->pos.y > 300.0f) {
        data->timeLeft = -1;
    }

    data->pos.x += data->vel.x;
    data->pos.y += data->vel.y;
    data->pos.z += data->vel.z;

    if (data->timeLeft < 0) {
        remove_effect(effect);
    }
}

void star_render(EffectInstance* effect) {
    StarFXData* data = effect->data.star;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;
    s32 renderModeTemp;

    renderTask.appendGfxArg = effect;
    renderTask.appendGfx = star_appendGfx;
    renderTask.dist = 0;
    if (data->type != FX_STAR_BACKGROUND) {
        renderModeTemp = RENDER_MODE_CLOUD_NO_ZCMP;
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
    gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->shared->graphics));

    guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, scale, data->pos.x, data->pos.y, data->pos.z);
    guRotateF(sp60, data->starAngle, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp60, sp20, sp20);
    guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMainGfxPos++, 0, 80, primR, primG, primB, 255);
    gDPSetEnvColor(gMainGfxPos++, 127, 127, 127, 127);

    gSPDisplayList(gMainGfxPos++, (data->type >= FX_STAR_LARGE_BOUNCING) ? D_09001650_333CF0 : D_09001530_333BD0);
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMainGfxPos++);

    if (type == FX_STAR_SMALL_BOUNCING) {
        gSPDisplayList(gMainGfxPos++, D_090017D0_333E70);
    } else {
        gSPDisplayList(gMainGfxPos++, D_09001780_333E20);
    }

    data->trailMatrixPos++;
    if (data->trailMatrixPos >= ARRAY_COUNT(data->trailMatrices)) {
        data->trailMatrixPos = 0;
    }

    // draw trail
    if (data->bounceTime <= 1.0f) {
        s32 baseIdx = (data->trailMatrixPos + 5) % ARRAY_COUNT(data->trailMatrices);
        guPositionF(sp20, 0.0f, -gCameras[gCurrentCameraID].curYaw, 0.0f, scale, data->pos.x, data->pos.y, data->pos.z);
        guRotateF(sp60, data->trailAngle, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp60, sp20, sp20);
        guMtxF2L(sp20, &data->trailMatrices[data->trailMatrixPos]);

        for (i = 0; i < 5; i++) {
            idx = (baseIdx - i + ARRAY_COUNT(data->trailMatrices)) % ARRAY_COUNT(data->trailMatrices);
            gDisplayContext->matrixStack[gMatrixListPos] = data->trailMatrices[idx];

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
