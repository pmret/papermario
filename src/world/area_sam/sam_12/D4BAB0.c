#include "sam_12.h"
#include "effects.h"

ApiStatus func_80240090_D4BAB0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    set_screen_overlay_params_front(0, evt_get_float_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_802400C0_D4BAE0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    s32 x = evt_get_float_variable(script, *args++);
    s32 y = evt_get_float_variable(script, *args++);
    s32 z = evt_get_float_variable(script, *args++);
    ItemEntity* item = get_item_entity(idx);

    item->position.x = x;
    item->position.y = y;
    item->position.z = z;
    return ApiStatus_DONE2;
}

#include "world/common/todo/PlayRisingBubble.inc.c"

ApiStatus func_80240238_D4BC58(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 temp_f26 = evt_get_float_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    f32 t = evt_get_float_variable(script, *args++);
    s32 outVar = *args++;
    EffectInstance* effect;

    fx_sleep_bubble(
        0,
        gPlayerStatus.position.x + x,
        gPlayerStatus.position.y + ((gPlayerStatus.colliderHeight * 2) / 3) + y,
        gPlayerStatus.position.z + z,
        (gPlayerStatus.colliderHeight / 3) + t,
        temp_f26,
        &effect
    );
    evt_set_variable(script, outVar, (s32) effect);
    return ApiStatus_DONE2;
}
