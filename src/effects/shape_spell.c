#include "common.h"
#include "effects_internal.h"

typedef struct ShapeSpellFXData {
    /* 0x00 */ s32 isChild;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 timeLeft;
    /* 0x34 */ s32 unk_34;
} ShapeSpellFXData; // size = 0x38

s32 D_E0024CC0[] = { 0x00FFD01A, 0x09001128, 0x090011A0, 0x784DD0FE, 0x09001150, 0x090011C8, 0xF0FE4C6E, 0x09001178, 0x090011F0, 0x00000000, 0x00000000, 0x00000000 };

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
    bp.unk_14 = 0;
    bp.effectID = EFFECT_SHAPE_SPELL;

    effect = shim_create_effect_instance(bpPtr);
    effect->numParts = numParts;
    part = effect->data = shim_general_heap_malloc(numParts * sizeof(*part));

    ASSERT(effect->data != NULL);

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
    ShapeSpellFXData* part = effect->data;
    s32 isChild;

    if (flags & 0x10) {
        effect->flags = flags & ~0x10;
        part->timeLeft = 0;
    }

    part->timeLeft--;
    part->unk_2C++;

    if (part->timeLeft < 0) {
        shim_remove_effect(effect);
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
        )->data;
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
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

s32 func_E0024324(s32 arg0, s32 arg1) {
    s32 frameCounter = gGameStatusPtr->frameCounter * 32;
    
    return (f32)((shim_sin_deg(frameCounter + arg1) * (255 - arg0) + (255 - arg0)) * 0.5 + arg0);
}

s32 func_E00243BC(s32 arg0, s32 arg1) {
    s32 frameCounter = gGameStatusPtr->frameCounter * 32;
    arg1 += 180;

    return (f32)((shim_sin_deg(frameCounter + arg1) * -arg0 + -arg0) * 0.5 + arg0);
}

INCLUDE_ASM(s32, "effects/shape_spell", shape_spell_appendGfx);
