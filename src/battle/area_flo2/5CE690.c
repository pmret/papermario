#include "common.h"

#define NAMESPACE b_area_flo2

#include "common/StartRumbleWithParams.inc.c"

INCLUDE_ASM(s32, "battle/area_flo2/5CE690", func_80218058_5CE6E8);

#include "common/UnkFloatFunc.inc.c"

INCLUDE_ASM(s32, "battle/area_flo2/5CE690", func_802182A4_5CE934);

INCLUDE_ASM(s32, "battle/area_flo2/5CE690", func_80218440_5CEAD0);

INCLUDE_ASM(s32, "battle/area_flo2/5CE690", func_802185D4_5CEC64);

INCLUDE_ASM(s32, "battle/area_flo2/5CE690", func_80218620_5CECB0);

INCLUDE_ASM(s32, "battle/area_flo2/5CE690", func_80218774_5CEE04);

ApiStatus func_802188A8_5CEF38(ScriptInstance* script, s32 isInitialCall) {
    func_8011D82C(1);
    *D_801512F0 = 1;
    set_background_color_blend(0, 0, 0, 0);
    return ApiStatus_DONE2;
}

ApiStatus func_802188EC_5CEF7C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    set_background_color_blend(0, 0, 0, get_variable(script, *args++));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/area_flo2/5CE690", func_80218924_5CEFB4);

INCLUDE_ASM(s32, "battle/area_flo2/5CE690", func_802189FC_5CF08C);

INCLUDE_ASM(s32, "battle/area_flo2/5CE690", func_80218AA0_5CF130);

INCLUDE_ASM(s32, "battle/area_flo2/5CE690", func_80218B60_5CF1F0);
