#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_tik2

#define NAMESPACE dup_b_area_tik2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_tik2

// same as func_802186D8_609188
ApiStatus func_80218258_608D08(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode arg0 = *args++;
    f32 var0, var1;

    var1 = evt_get_float_variable(script, *args++);
    do {} while(0);
    var0 = evt_get_float_variable(script, arg0);

    evt_set_float_variable(script, arg0, var1 * sin_rad(DEG_TO_RAD(var0)));

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnfadeBackgroundToBlack.inc.c"

ApiStatus func_80218404_608EB4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);
    f32 temp_f0 = evt_get_float_variable(script, *args++);

    effect->data.snakingStatic->pos.x = x;
    effect->data.snakingStatic->pos.y = y;
    effect->data.snakingStatic->pos.z = z;
    effect->data.snakingStatic->unk_38 = temp_f0;
    return ApiStatus_DONE2;
}

#define NAMESPACE dup_b_area_tik2
#include "common/UnkWaterFountainFunc.inc.c"
#define NAMESPACE b_area_tik2

#define NAMESPACE dup2_b_area_tik2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_tik2

// same as func_80218258_608D08
ApiStatus func_802186D8_609188(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode arg0 = *args++;
    f32 var0, var1;

    var1 = evt_get_float_variable(script, *args++);
    do {} while(0);
    var0 = evt_get_float_variable(script, arg0);

    evt_set_float_variable(script, arg0, var1 * sin_rad(DEG_TO_RAD(var0)));

    return ApiStatus_DONE2;
}

#define NAMESPACE dup_b_area_tik2
#include "common/FadeBackgroundToBlack.inc.c"
#define NAMESPACE b_area_tik2

#define NAMESPACE dup_b_area_tik2
#include "common/UnfadeBackgroundToBlack.inc.c"
#define NAMESPACE b_area_tik2

#define NAMESPACE dup2_b_area_tik2
#include "common/UnkWaterFountainFunc.inc.c"
#define NAMESPACE b_area_tik2

#define NAMESPACE dup3_b_area_tik2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_tik2

#include "common/UnkBattleFunc2.inc.c"

#include "world/common/UnkFunc56.inc.c"
