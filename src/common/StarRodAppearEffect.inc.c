#include "common.h"
#include "effects.h"

typedef struct StarOutlineState {
    /* 0x00 */ EffectInstance* effect;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 delay;
    /* 0x20 */ s32 duration;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 effectEnded;
} StarOutlineState; // size = 0x3C

API_CALLABLE(N(StarRodAppearEffect)) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 i;
    s32 endedCount;
    StarOutlineState* effectState;

    if (actor == NULL) {
        return ApiStatus_DONE2;
    }

    if (isInitialCall) {
        f32 x = evt_get_variable(script, *args++);
        f32 y = evt_get_variable(script, *args++);
        f32 z = evt_get_variable(script, *args++);
        f32 arg4 = evt_get_float_variable(script, *args++);
        f32 arg5 = evt_get_float_variable(script, *args++);
        effectState = heap_malloc(sizeof(StarOutlineState) * 3);
        actor->state.functionTempPtr[0] = effectState;

        for (i = 0; i < 3; effectState++, i++) {
            effectState->pos.x = x;
            effectState->pos.y = y;
            effectState->pos.z = z;
            effectState->unk_18 = arg4;
            effectState->unk_10 = arg4;
            effectState->unk_14 = arg5;
            effectState->delay = 1 + i * 10;
            effectState->duration = 40;
            effectState->unk_24 = 255;
            effectState->unk_28 = 255;
            effectState->unk_2C = 0.0f;
            effectState->unk_30 = 0.0f;
            effectState->unk_34 = 0.0f;
            effectState->effectEnded = FALSE;
        }
        return ApiStatus_BLOCK;
    }

    effectState = actor->state.functionTempPtr[0];
    endedCount = 0;

    for (i = 0; i < 3; effectState++, i++) {
        if (effectState->delay > 0) {
            effectState->delay--;
            if (effectState->delay <= 0) {
                effectState->effect = fx_star_outline(0, effectState->pos.x, effectState->pos.y, effectState->pos.z,
                                                        effectState->unk_18, -1);
                effectState->effect->data.starOutline->unk_3C.x = effectState->unk_2C;
                effectState->effect->data.starOutline->unk_3C.y = effectState->unk_30;
                effectState->effect->data.starOutline->unk_3C.z = effectState->unk_34;
                effectState->effect->data.starOutline->unk_00 = 0;
            }
        } else if (effectState->effectEnded) {
            endedCount++;
        } else {
            effectState->unk_34 += 9.0f;
            effectState->unk_18 = fabsf(effectState->unk_10 - effectState->unk_14) * effectState->duration / 40.0f + effectState->unk_14;

            if (effectState->duration <= 10) {
                effectState->unk_24 = (effectState->duration / 2 * 0.1f + 0.5f) * 255.0f;
                effectState->unk_28 = (effectState->duration / 2 * 0.1f + 0.5f) * 255.0f;
            }

            effectState->duration--;

            if (effectState->duration <= 0) {
                remove_effect(effectState->effect);
                effectState->effectEnded = TRUE;
            } else {
                effectState->effect->data.starOutline->pos.x = effectState->pos.x;
                effectState->effect->data.starOutline->pos.y = effectState->pos.y;
                effectState->effect->data.starOutline->pos.z = effectState->pos.z;
                effectState->effect->data.starOutline->unk_3C.x = effectState->unk_2C;
                effectState->effect->data.starOutline->unk_3C.y = effectState->unk_30;
                effectState->effect->data.starOutline->unk_3C.z = effectState->unk_34;
                effectState->effect->data.starOutline->unk_38 = effectState->unk_18;
                effectState->effect->data.starOutline->unk_24 = effectState->unk_24;
                effectState->effect->data.starOutline->unk_34 = effectState->unk_28;
            }
        }
    }

    if (endedCount >= 3) {
        heap_free(effectState);//@bug effectState doesn't point to allocated memory
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
