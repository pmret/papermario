#include "common.h"
#include "effects_internal.h"

typedef struct Effect9 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[0x2];
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 primAlpha;
    /* 0x09 */ char unk_09[0x3];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ Mtx unk_30;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ f32 unk_78;
    /* 0x7C */ f32 unk_7C;
    /* 0x80 */ f32 unk_80;
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ f32 unk_88;
    /* 0x8C */ f32 unk_8C;
    /* 0x90 */ f32 unk_90;
    /* 0x94 */ f32 unk_94;
} Effect9; // size = 0x98

void fx_9_init(EffectInstance* effect);
void fx_9_update(EffectInstance* effect);
void fx_9_render(EffectInstance* effect);
void fx_9_appendGfx(EffectInstance* effect);

void func_E0012000(Effect9* effect) {
    Matrix4f sp18;
    Matrix4f sp58;

    shim_guRotateF(sp18, effect->unk_24, 1.0f, 0.0f, 0.0f);
    shim_guRotateF(sp58, effect->unk_2C, 0.0f, 0.0f, 1.0f);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guRotateF(sp58, effect->unk_28, 0.0f, 1.0f, 0.0f);
    shim_guMtxCatF(sp18, sp58, sp18);
    shim_guScaleF(sp58, effect->unk_18, effect->unk_1C, effect->unk_20);
    shim_guMtxCatF(sp58, sp18, sp18);
    shim_guTranslateF(sp58, effect->unk_0C, effect->unk_10, effect->unk_14);
    shim_guMtxCatF(sp18, sp58, sp18);
    shim_guMtxF2L(sp18, &effect->unk_30);
}

void func_E0012104(Effect9* effect);
INCLUDE_ASM(s32, "effects/effect_9", func_E0012104);

INCLUDE_ASM(s32, "effects/effect_9", fx_9_main);

void func_E0012440(EffectInstance* effect) {
}

void fx_9_update(EffectInstance* effect) {
    Effect9* part = (Effect9*)effect->data;
    s32 cond = FALSE;
    s32 i;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->unk_00 != 0) {
            part->unk_06--;
            if (part->unk_06 <= 0) {
                part->unk_00 = 0;
            } else {
                cond = TRUE;
                func_E0012104(part);
                func_E0012000(part);
            }
        }
    }

    if (!cond) {
        shim_remove_effect(effect);
    }
}

void fx_9_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_9_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E0012548(EffectInstance* effect) {
    shim_remove_effect(effect);
}

INCLUDE_ASM(s32, "effects/effect_9", fx_9_appendGfx);
