#include "common.h"
#include "battle/battle.h"

INCLUDE_ASM(s32, "battle/partner/parakarry", func_80238000_6FFD80);

ApiStatus func_80238C88_700A08(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var0 = 0;

    switch (battleStatus->partnerActor->staticActorData->level) {
        case 0:
            var0 = 5;
            break;
        case 1:
            var0 = 6;
            break;
        case 2:
            var0 = 7;
            break;
    }

    script->varTable[15] = var0;
    return ApiStatus_DONE2;
}

ApiStatus func_80238CE0_700A60(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor = get_actor(partnerActor->targetActorID);
    ActorPart* targetActorPart = get_actor_part(targetActor, partnerActor->targetPartIndex);
    s32 airLiftChance = targetActor->staticActorData->airLiftChance;
    s32 temp = 100 - (targetActor->currentHP * 100) / targetActor->maxHP;

    if (targetActor->transStatus == 14) {
        airLiftChance = 0;
    }

    if (targetActorPart->eventFlags & 0x20) {
        airLiftChance = 0;
    }

    if (airLiftChance > 0) {
        airLiftChance = airLiftChance + ((airLiftChance * temp) / 100);

        if (airLiftChance > 100) {
            airLiftChance = 100;
        }

        if (targetActor->debuff != 0) {
            airLiftChance = (airLiftChance * 150) / 100;

            if (airLiftChance > 150) {
                airLiftChance = 150;
            }
        }
    }

    script->varTable[0] = airLiftChance;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/parakarry", func_80238E24_700BA4);

INCLUDE_ASM(s32, "battle/partner/parakarry", func_802390B4_700E34);

ApiStatus func_802397C8_701548(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[15] = ((script->varTable[0] * 100) / 2499) + 2;

    return ApiStatus_DONE2;
}
