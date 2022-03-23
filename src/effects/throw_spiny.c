#include "common.h"
#include "effects_internal.h"
#include "effects.h"

void throw_spiny_appendGfx(void* effect);

void throw_spiny_init(void);
void throw_spiny_update(EffectInstance* effect);
void throw_spiny_render(EffectInstance* effect);

extern u8 D_E00C8718[4];
extern u8 D_E00C8720[4];
extern f64 D_E00C8738;

extern f64 D_E00C8730;

typedef struct unk_spinyThrow {
    EffectBlueprint* unk_00;
    f32 x;
    f32 y;
    f32 z;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    s32 life;
    s32 lifeDuration;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 gravity;
    f32 unk_4C;
    f32 yaw;
    f32 rotationSpeed;
    f32 xScale;
    f32 yScale;
    s32 state;
    s32 unk_64;
    s32 timeUntilFall; //how quickly should spiny fall to ground ?
} unk_spinyThrow; //sizeof 0x68

//during spiny surge
EffectInstance* throw_spiny_main(EffectBlueprint *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 time) {
    EffectInstance* effectInstance;
    unk_spinyThrow* spinyObject;
    EffectBlueprint effectBluePrint;
    int new_var;
    f32 temp_f4, temp_f8, new_var2;

    effectBluePrint.unk_00 = 0;
    effectBluePrint.init = (void*)(&throw_spiny_init);
    effectBluePrint.update = (void*)(&throw_spiny_update);
    effectBluePrint.renderWorld = (void*)(&throw_spiny_render);
    (&effectBluePrint)->unk_14 = NULL;
    new_var = 1;
    effectBluePrint.effectID = EFFECT_THROW_SPINY;
    effectInstance = (EffectInstance *)shim_create_effect_instance(&effectBluePrint);
    effectInstance->numParts = new_var;
    spinyObject = effectInstance->data = (unk_spinyThrow*)shim_general_heap_malloc(sizeof(unk_spinyThrow));
    ASSERT(spinyObject);
    spinyObject->unk_00 = arg0;
    spinyObject->lifeDuration = 0;

    if (time <= 0) {
        spinyObject->life = 1000;
    } else {
        spinyObject->life = time + 60;
    }

    temp_f8 = arg5 - arg2;
    temp_f4 = time;
    new_var2 = (temp_f8 / temp_f4) - (time * D_E00C8730);
    spinyObject->timeUntilFall = time;
    spinyObject->unk_3C = 255;
    spinyObject->unk_10 = arg1;
    spinyObject->unk_14 = arg2;
    spinyObject->unk_18 = arg3;
    spinyObject->unk_1C = arg4;
    spinyObject->unk_20 = arg5;
    spinyObject->unk_24 = arg6;
    spinyObject->x = arg1;
    spinyObject->unk_44 = (arg4 - arg1) / temp_f4;
    spinyObject->unk_4C = (arg6 - arg3) / temp_f4;
    spinyObject->y = arg2;
    spinyObject->z = arg3;
    spinyObject->gravity = new_var2;

    if (temp_f8 < 0.0f) {
        spinyObject->unk_64 = 1;
    } else {
        spinyObject->unk_64 = 0;
    }

    spinyObject->unk_40 = arg7;
    spinyObject->unk_30 = 70;
    spinyObject->unk_34 = 180;
    spinyObject->unk_38 = 120;
    spinyObject->yaw = shim_rand_int(360);
    spinyObject->rotationSpeed = shim_rand_int(10) + 5;
    spinyObject->state = -1;
    spinyObject->xScale = 1.0f;
    spinyObject->yScale = 1.0f;
    return effectInstance;
}

void throw_spiny_init(void) {
}

void throw_spiny_update(EffectInstance* effectInstance) {
    unk_spinyThrow* spinyObject = effectInstance->data;
    u32 state;
    f32 gravity;
    s32 tempVar;

    if (effectInstance->flags & 0x10) {
        effectInstance->flags &= ~0x10;
        spinyObject->life = 16;
    }

    if (spinyObject->life < 1000) {
        spinyObject->life--;
    }

    spinyObject->lifeDuration++;

    if (spinyObject->life < 0) {
        shim_remove_effect((EffectInstance*)effectInstance);
        return;
    }
    
    tempVar = spinyObject->lifeDuration;
    state = spinyObject->state;

    if (state < 7) {
        spinyObject->xScale = D_E00C8718[state] * 0.01f;
        spinyObject->yScale = D_E00C8720[state] * 0.01f;
        spinyObject->state += 1;
        spinyObject->yaw -= 40.0f;
    } else {
        spinyObject->gravity += -0.2f;
        spinyObject->x += spinyObject->unk_44;
        spinyObject->y += spinyObject->gravity;
        spinyObject->z += spinyObject->unk_4C;
        spinyObject->yaw += spinyObject->rotationSpeed;
    }

    if ((tempVar - 1) == spinyObject->timeUntilFall) {
        spinyObject->state = 0;
        spinyObject->gravity = -spinyObject->gravity;
        spinyObject->unk_44 = spinyObject->unk_44;
        spinyObject->rotationSpeed = -4.0f;
        return;
    }

    gravity = spinyObject->gravity;

    if ((gravity < 0.0f) && (spinyObject->y < D_E00C8738)) {
        spinyObject->y = 14.285714f;
        spinyObject->rotationSpeed = -20.0f;
        spinyObject->gravity = gravity - gravity;
    }
}

void throw_spiny_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = throw_spiny_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00C844C(void) {
}

INCLUDE_ASM(s32, "effects/throw_spiny", throw_spiny_appendGfx);
