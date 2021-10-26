#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_isk_part_2

#include "common/ChainChompChainInit.inc.c"

#include "common/ChainChompChainUpdateHelperFunc.inc.c"

#include "common/ChainChompChainUpdateHelperFunc2.inc.c"

INCLUDE_ASM(s32, "battle/area_isk_part_2/4EF4A0", b_area_isk_part_2_ChainChompChainUpdate);

ApiStatus func_8021866C_4EFB0C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_get_variable(script, args[1]);
    return ApiStatus_DONE2;
}

#include "common/UnkBattleFunc1.inc.c"

ApiStatus func_8021875C_4EFBFC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    EffectInstance* effect = playFX_4C(2, var1, 150.0f, var3, var2, -0.5f, -0.9f, 0.5f, 60);

    effect->data->unk_30 = 0;
    effect->data->unk_38 = 0;
    effect->data->unk_34 = 0;
    return ApiStatus_DONE2;
}
