#include "kkj_15.h"

void sprite_shading_set_light_source(u32, s8, f32, f32, f32, u8, u8, u8, f32, s8);

ApiStatus func_80240500_AE5A90(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    sprite_shading_set_light_source(0, 5, x, y, z, 255, 255, 255, 0.0001f, 0);
    return ApiStatus_DONE2;
}
