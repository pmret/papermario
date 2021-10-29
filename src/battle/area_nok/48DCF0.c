#include "common.h"

#define NAMESPACE b_area_nok

#define NAMESPACE dup2_b_area_nok
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_nok

#define NAMESPACE dup2_b_area_nok
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_nok

INCLUDE_ASM(s32, "battle/area_nok/48DCF0", func_80218C74_48DE14);

ApiStatus func_80218DF8_48DF98(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = args++;

    evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}
