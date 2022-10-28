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
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5,
    EffectInstance** outEffect
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    StarsOrbitingFXData* part;
    s32 i;

    arg5++;

    bp.init = stars_orbiting_init;
    bp.update = stars_orbiting_update;
    bp.renderWorld = stars_orbiting_render;
    bp.unk_00 = 0;
    bp.unk_14 = func_E005E318;
    bp.effectID = EFFECT_STARS_ORBITING;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = arg5;
    part = effect->data.starsOrbiting = shim_general_heap_malloc(arg5 * sizeof(*part));
    ASSERT(effect->data.starsOrbiting != NULL);

    shim_mem_clear(part, arg5 * sizeof(*part));

    part->unk_00 = arg0;
    part->pos.x = arg1;
    part->pos.y = arg2;
    part->pos.z = arg3;
    part->unk_10 = 0;
    part->unk_24 = 0;
    part->unk_14 = arg4;
    part->unk_28 = 1;

    part++;
    for (i = 1; i < arg5; i++, part++) {
        part->pos.x = 0;
        part->pos.y = 0;
        part->pos.z = 0;
        part->unk_18 = (i - 1) * 360 / (arg5 - 1);
        part->unk_1C = 20.0f;
        part->unk_20 = 0;
        part->unk_24 = (i - 1) * 360 / (arg5 - 1);
    }

    *outEffect = effect;
}

void stars_orbiting_init(EffectInstance* effect) {
}

void stars_orbiting_update(EffectInstance* effect) {
    StarsOrbitingFXData* part = effect->data.starsOrbiting;
    f32 unk_10;
    s32 i;

    if (part->unk_28 != 0) {
        part->unk_24++;
        part->unk_10 += (part->unk_14 - part->unk_10) * 0.1;
        unk_10 = part->unk_10;

        part++;
        for (i = 1; i < effect->numParts; i++, part++) {
            part->pos.x = unk_10 * shim_sin_deg(part->unk_24);
            part->pos.z = unk_10 * shim_cos_deg(part->unk_24) * shim_cos_deg(part->unk_20);
            part->pos.y = unk_10 * shim_cos_deg(part->unk_24) * shim_sin_deg(part->unk_20);
            part->unk_18 += part->unk_1C;
            part->unk_20 = 0.0f;
            part->unk_24 += 16;
            if (part->unk_24 > 360) {
                part->unk_24 -= 360;
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

    if (part->unk_28 != 0) {
        Gfx* dlist = D_E005E670[0];
        Gfx* dlist2 = D_E005E674[0];

        gDPPipeSync(gMasterGfxPos++);
        gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));
        gSPDisplayList(gMasterGfxPos++, dlist2);

        shim_guTranslateF(sp18, part->pos.x, part->pos.y, part->pos.z);
        shim_guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        shim_guMtxCatF(sp58, sp18, sp98);
        shim_guMtxF2L(sp98, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 220, 220, 40, 255);

        part++;
        for (i = 1; i < effect->numParts; i++, part++) {
            shim_guTranslateF(sp18, part->pos.x, part->pos.y, part->pos.z);
            shim_guRotateF(sp58, part->unk_18, 0.0f, 0.0f, 1.0f);
            shim_guMtxCatF(sp58, sp18, sp18);
            shim_guMtxF2L(sp18, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, dlist);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }

        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }
}
