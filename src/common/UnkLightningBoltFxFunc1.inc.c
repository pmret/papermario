#include "common.h"
#include "effects.h"

typedef struct FxLightningBoltState {
    /* 0x00 */ EffectInstance* effect;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 radius;
    /* 0x14 */ f32 yaw;
    /* 0x18 */ f32 angularSpeed;
    /* 0x1C */ s32 duration;
} FxLightningBoltState; // size = 0x20

API_CALLABLE(N(UnkLightningBoltFxFunc1)) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 i;
    FxLightningBoltState* effectState;
    ActorState* actorState;

    if (actor == NULL) {
        return ApiStatus_DONE2;
    }

    actorState = &actor->state;

    if (isInitialCall) {
        s32 x, y, z;

        effectState = heap_malloc(sizeof(FxLightningBoltState) * 3);
        actorState->functionTempPtr[0] = effectState;

        x = evt_get_variable(script, *args++);
        y = 0;
        z = evt_get_variable(script, *args++);

        for (i = 0; i < 3; effectState++, i++) {
            effectState->effect = fx_lightning_bolt(2, x, 200.0f, z, x, 0.0f, z, 1.0f, 60);
            effectState->duration = 45;
            effectState->pos.x = x;
            effectState->pos.y = y;
            effectState->pos.z = z;

            effectState->radius = 10.0f;
            effectState->yaw = i * 120;
            effectState->angularSpeed = 15.0f;

        }
        return ApiStatus_BLOCK;
    }

    effectState = actorState->functionTempPtr[0];

    for (i = 0; i < 3; effectState++, i++) {
        f32 x = effectState->pos.x + cos_deg(effectState->yaw) * effectState->radius;
        f32 z = effectState->pos.z + sin_deg(effectState->yaw) * effectState->radius;

        effectState->effect->data.lightningBolt->tipPos.x = x;
        effectState->effect->data.lightningBolt->startPos.x = x;
        effectState->effect->data.lightningBolt->endPos.x = x;

        effectState->effect->data.lightningBolt->tipPos.z = z;
        effectState->effect->data.lightningBolt->startPos.z = z;
        effectState->effect->data.lightningBolt->endPos.z = z;

        if (effectState->duration > 10) {
            effectState->radius += 1.5;
        }
        effectState->yaw += effectState->angularSpeed;
        if (effectState->duration > 30) {
            effectState->angularSpeed -= 0.3;
        }
        effectState->duration--;
    }

    effectState = actorState->functionTempPtr[0];
    if (effectState->duration <= 0) {
        heap_free(effectState);
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
