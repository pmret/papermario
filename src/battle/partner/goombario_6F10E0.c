#include "common.h"

extern s32 D_8023CDA4;

ApiStatus func_80238000_6F10E0(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* secondBattleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 posX = partnerActor->currentPos.x;
    f32 posY = partnerActor->currentPos.y;
    f32 posZ = partnerActor->currentPos.z;
    f32 goalX = partnerActor->movePos.goal.x;
    f32 goalY = partnerActor->movePos.goal.y;
    f32 goalZ = partnerActor->movePos.goal.z;

    script->varTable[0] = (dist3D(posX, posY, posZ, goalX, goalY, goalZ) * 15.0f) / 100.0f;

    if (script->varTable[0] >= 21) {
        script->varTable[0] = 20;
    }

    if (secondBattleStatus->unk_83 != 0) {
        if (script->varTable[0] < 10) {
            script->varTable[0] = 10;
        }
    } else if (script->varTable[0] < 15) {
        script->varTable[0] = 15;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_802380E4_6F11C4);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_8023817C_6F125C);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238A20_6F1B00);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238B60_6F1C40);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238BCC_6F1CAC);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238E04_6F1EE4);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238E48_6F1F28);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238E74_6F1F54);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238EDC_6F1FBC);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_8023903C_6F211C);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80239068_6F2148);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_802390B0_6F2190);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_802390C8_6F21A8);

ApiStatus func_80239190_6F2270(ScriptInstance* script, s32 isInitialCall) {
    if (D_8023CDA4 == 0) {
        script->varTable[0] = 36;
    } else {
        script->varTable[0] = 37;
    }

    return ApiStatus_DONE2;
}
