#include "common.h"

extern s32 D_8023D2C8;
extern s32 D_8023D330;
extern s32 D_8023D334;

ApiStatus func_80238000_70BD10(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall != 0) {
        D_8023D2C8 = 0;
    }

    if (D_8023D2C8 == 0) {
        btl_set_popup_duration(99);
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/lakilester", func_8023803C_70BD4C);

INCLUDE_ASM(s32, "battle/partner/lakilester", func_80238A6C_70C77C);

INCLUDE_ASM(s32, "battle/partner/lakilester", func_80238B50_70C860);

ApiStatus func_80238C14_70C924(ScriptInstance* script, s32 isInitialCall) {
    s32 temp_a0 = gBattleStatus.cloudNineEffect;

    if (temp_a0 != 0) {
        remove_effect(temp_a0);
        gBattleStatus.cloudNineEffect = 0;
        gBattleStatus.cloudNineTurnsLeft = 0;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/lakilester", func_80238C58_70C968);

ApiStatus func_80238D48_70CA58(ScriptInstance* script, s32 isInitialCall) {
    if (gBattleStatus.cloudNineTurnsLeft < script->varTable[10]) {
        gBattleStatus.cloudNineTurnsLeft = script->varTable[10];
        gBattleStatus.cloudNineDodgeChance = 50;
        gBattleStatus.unk_43C->unk_0C->unk_1A = gBattleStatus.cloudNineTurnsLeft;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/lakilester", func_80238D8C_70CA9C);

INCLUDE_ASM(s32, "battle/partner/lakilester", func_8023906C_70CD7C);

INCLUDE_ASM(s32, "battle/partner/lakilester", func_80239140_70CE50);

INCLUDE_ASM(s32, "battle/partner/lakilester", func_80239F84_70DC94);

ApiStatus func_8023A19C_70DEAC(ScriptInstance* script, s32 isInitialCall) {
    return (D_8023D330 == 0) * 2;
}

INCLUDE_ASM(s32, "battle/partner/lakilester", func_8023A1B0_70DEC0);
/* Should work, but there seems to be an issue with the split?
void func_8023A1B0_70DEC0(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = D_8023D334;
}
*/
