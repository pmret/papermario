#include "common.h"
#include "effects.h"

typedef struct StarOutlineState2 {
    /* 0x00 */ EffectInstance* effect;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 delay;
    /* 0x18 */ s32 duration;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x38 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s32 effectEnded;
} StarOutlineState2; // size = 0x34

API_CALLABLE(N(StarRodPowerUpEffect)) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 i;
    s32 endedCount;
    StarOutlineState2* effectState;

    if (actor == NULL) {
        return ApiStatus_DONE2;
    }

    if (isInitialCall) {
        f32 x = evt_get_variable(script, *args++);
        f32 y = evt_get_variable(script, *args++);
        f32 z = evt_get_variable(script, *args++);
        f32 arg4 = evt_get_float_variable(script, *args++);

        if (actor->debuff == STATUS_KEY_SHRINK) {
            arg4 *= 0.4;
        }

        effectState = heap_malloc(sizeof(StarOutlineState2) * 3);
        actor->state.functionTempPtr[0] = effectState;

        for (i = 0; i < 3; effectState++, i++) {
            effectState->pos.x = x;
            effectState->pos.y = y;
            effectState->pos.z = z;
            effectState->unk_10 = arg4;
            effectState->delay = 1 + i * 16;
            effectState->duration = 50;
            effectState->unk_1C = 255;
            effectState->unk_20 = 255;
            effectState->unk_24 = 90.0f;
            effectState->unk_28 = 0.0f;
            effectState->unk_2C = 0.0f;
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
                                                        effectState->unk_10, -1);
                effectState->effect->data.starOutline->unk_3C.x = effectState->unk_24;
                effectState->effect->data.starOutline->unk_3C.y = effectState->unk_28;
                effectState->effect->data.starOutline->unk_3C.z = effectState->unk_2C;
            }
        } else if (effectState->effectEnded) {
            endedCount++;
        } else {
#ifdef BOWSER_LARGE
            if (actor->debuff != STATUS_KEY_SHRINK) {
                if (effectState->pos.y < 60.0) {
                    effectState->pos.y += 4.5;
                } else if (effectState->pos.y < 90.0) {
                    effectState->pos.y += 3.6000001430511475;
                } else if (effectState->pos.y < 120.0) {
                    effectState->pos.y += 2.400000035762787;
                } else {
                    effectState->pos.y += 1.5;
                }
            } else {
                if (effectState->pos.y < 24.0) {
                    effectState->pos.y += 1.8;
                } else if (effectState->pos.y < 36.0) {
                    effectState->pos.y += 1.440000057220459;
                } else if (effectState->pos.y < 48.0) {
                    effectState->pos.y += 0.9600000143051148;
                } else {
                    effectState->pos.y += 0.6000000000000001;
                }
            }
#else
            if (actor->debuff != STATUS_KEY_SHRINK) {
                if (effectState->pos.y < 40.0) {
                    effectState->pos.y += 3.0;
                } else if (effectState->pos.y < 60.0) {
                    effectState->pos.y += 2.400000095367431640625;
                } else if (effectState->pos.y < 80.0) {
                    effectState->pos.y += 1.60000002384185791015625;
                } else {
                    effectState->pos.y += 1.0;
                }
            } else {
                if (effectState->pos.y < 16.0) {
                    effectState->pos.y += 1.20000000000000017763568394003;
                } else if (effectState->pos.y < 24.0) {
                    effectState->pos.y += 0.96000003814697265625;
                } else if (effectState->pos.y < 32.0) {
                    effectState->pos.y += 0.640000009536743186266960492503;
                } else {
                    effectState->pos.y += 0.4;
                }
            }
#endif
            effectState->unk_28 += 18.0f;

            if (effectState->duration <= 16) {
                effectState->unk_1C = effectState->duration * 255 / 16;
                effectState->unk_20 = effectState->duration * 255 / 16;
            }

            effectState->effect->data.starOutline->pos.x = effectState->pos.x;
            effectState->effect->data.starOutline->pos.y = effectState->pos.y;
            effectState->effect->data.starOutline->pos.z = effectState->pos.z;
            effectState->effect->data.starOutline->unk_3C.x = effectState->unk_24;
            effectState->effect->data.starOutline->unk_3C.y = effectState->unk_28;
            effectState->effect->data.starOutline->unk_3C.z = effectState->unk_2C;
            effectState->effect->data.starOutline->unk_38 = effectState->unk_10;
            effectState->effect->data.starOutline->unk_24 = effectState->unk_1C;
            effectState->effect->data.starOutline->unk_34 = effectState->unk_20;

            effectState->duration--;

            if (effectState->duration <= 0) {
                remove_effect(effectState->effect);
                effectState->effectEnded = TRUE;
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
