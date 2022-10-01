#include "common.h"

#define NAMESPACE b_area_tik2

#define NAMESPACE dup_b_area_tik2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_tik2

INCLUDE_ASM(s32, "battle/area_tik2/608CB0", func_80218258_608D08);

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnfadeBackgroundToBlack.inc.c"

INCLUDE_ASM(s32, "battle/area_tik2/608CB0", func_80218404_608EB4);

#define NAMESPACE dup_b_area_tik2
#include "common/UnkWaterFountainFunc.inc.c"
#define NAMESPACE b_area_tik2

#define NAMESPACE dup2_b_area_tik2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_tik2

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
