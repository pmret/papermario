#include "common.h"

INCLUDE_ASM(s32, "battle/partner/sushie", func_80238000_707CA0);

INCLUDE_ASM(s32, "battle/partner/sushie", func_80238114_707DB4);

INCLUDE_ASM(s32, "battle/partner/sushie", func_802381EC_707E8C);

INCLUDE_ASM(s32, "battle/partner/sushie", func_802382A4_707F44);

//INCLUDE_ASM(s32, "battle/partner/sushie", func_80238328_707FC8);
ApiStatus func_80238328_707FC8(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var = script->varTable[0];

    if (var > 0) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = 0;
    script->varTable[10] = var;
    if (battleStatus->waterBlockTurnsLeft < var) {
        battleStatus->waterBlockTurnsLeft = var;
        battleStatus->waterBlockAmount = 1;
        battleStatus->unk_43C->unk_0C->unk_10 = battleStatus->waterBlockTurnsLeft;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/sushie", func_80238388_708028);

INCLUDE_ASM(s32, "battle/partner/sushie", func_80238480_708120);

INCLUDE_ASM(s32, "battle/partner/sushie", func_80238540_7081E0);

INCLUDE_ASM(s32, "battle/partner/sushie", func_80238E30_708AD0);
