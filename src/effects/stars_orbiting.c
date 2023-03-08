#include "common.h"
#include "effects_internal.h"

extern Gfx D_09000440_363090[];
extern Gfx D_090004F0_363140[];

Gfx* D_E005E670[] = { D_090004F0_363140 };
Gfx* D_E005E674[] = { D_09000440_363090 };

void stars_orbiting_init(EffectInstance* effect);
void stars_orbiting_update(EffectInstance* effect);
void stars_orbiting_render(EffectInstance* effect);
void func_E005E318(EffectInstance* effect);
void func_E005E334(EffectInstance* effect);

void stars_orbiting_main(
    s32 type,
    f32 posX,
    f32 posY,
    f32 posZ,
    f32 radius,
    s32 numStars,
    EffectInstance** outEffect
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    StarsOrbitingFXData* part;
    s32 i;

    numStars++;

    bp.init = stars_orbiting_init;
    bp.update = stars_orbiting_update;
    bp.renderWorld = stars_orbiting_render;
    bp.unk_00 = 0;
    bp.unk_14 = func_E005E318;
    bp.effectID = EFFECT_STARS_ORBITING;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numStars;
    part = effect->data.starsOrbiting = shim_general_heap_malloc(numStars * sizeof(*part));
    ASSERT(effect->data.starsOrbiting != NULL);

    shim_mem_clear(part, numStars * sizeof(*part));

    part->type = type;
    part->pos.x = posX;
    part->pos.y = posY;
    part->pos.z = posZ;
    part->orbitRadius = 0;
    part->yaw = 0;
    part->targetRadius = radius;
    part->enabled = TRUE;

    part++;
    for (i = 1; i < numStars; i++, part++) {
        part->pos.x = 0;
        part->pos.y = 0;
        part->pos.z = 0;
        part->roll = (i - 1) * 360 / (numStars - 1);
        part->rollSpinRate = 20.0f;
        part->pitch = 0;
        part->yaw = (i - 1) * 360 / (numStars - 1);
    }

    *outEffect = effect;
}

void stars_orbiting_init(EffectInstance* effect) {
}

void stars_orbiting_update(EffectInstance* effect) {
    StarsOrbitingFXData* part = effect->data.starsOrbiting;
    f32 radius;
    s32 i;

    if (part->enabled) {
        part->yaw++;
        part->orbitRadius += (part->targetRadius - part->orbitRadius) * 0.1;
        radius = part->orbitRadius;

        part++;
        for (i = 1; i < effect->numParts; i++, part++) {
            part->pos.x = radius * shim_sin_deg(part->yaw);
            part->pos.z = radius * shim_cos_deg(part->yaw) * shim_cos_deg(part->pitch);
            part->pos.y = radius * shim_cos_deg(part->yaw) * shim_sin_deg(part->pitch);
            part->roll += part->rollSpinRate;
            part->pitch = 0.0f;
            part->yaw += 16;
            if (part->yaw > 360) {
                part->yaw -= 360;
            }
        }
    }
}

void stars_orbiting_render(EffectInstance* effect) {
}

void func_E005E318(EffectInstance* effect) {
    func_E005E334(effect);
}

void func_E005E334(EffectInstance* effect) {
    StarsOrbitingFXData* part = effect->data.starsOrbiting;
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    s32 i;

    if (part->enabled) {
        Gfx* dlist = D_E005E670[0];
        Gfx* dlist2 = D_E005E674[0];

        gDPPipeSync(gMainGfxPos++);
        gSPSegment(gMainGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
        gSPDisplayList(gMainGfxPos++, dlist2);

        shim_guTranslateF(sp18, part->pos.x, part->pos.y, part->pos.z);
        shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        shim_guMtxCatF(sp58, sp18, sp98);
        shim_guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 220, 220, 40, 255);

        part++;
        for (i = 1; i < effect->numParts; i++, part++) {
            shim_guTranslateF(sp18, part->pos.x, part->pos.y, part->pos.z);
            shim_guRotateF(sp58, part->roll, 0.0f, 0.0f, 1.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, dlist);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }

        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}
