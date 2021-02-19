#include "common.h"
#include "battle/battle.h"

INCLUDE_ASM(s32, "battle/partner/parakarry_6FFD80", func_80238000_6FFD80);

ApiStatus func_80238C88_700A08(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    u8 level = battleStatus->partnerActor->staticActorData->level;
    s32 var0 = 0;

    switch (level) {
        case 0:
            var0 = 5;
            break;
        case 1:
            var0 = 6;
            break;
        case 2:
            var0 = 7;
            break;
        default:
            break;
    }

    script->varTable[15] = var0;
    return ApiStatus_DONE2;
}

//INCLUDE_ASM(s32, "battle/partner/parakarry_6FFD80", func_80238CE0_700A60);
ApiStatus func_80238CE0_700A60(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor = get_actor(partnerActor->targetActorID);
    s32 airLiftChance = targetActor->staticActorData->airLiftChance;

    if (targetActor->transStatus == 14) {
        airLiftChance = 0;
    }

    if (get_actor_part(targetActor, partnerActor->targetPartIndex)->eventFlags & 0x20) {
        airLiftChance = 0;
    }

    airLiftChance = airLiftChance * (100 - ((targetActor->currentHP * 100) / targetActor->maxHP));

    if (airLiftChance > 0) {
        airLiftChance = airLiftChance + (airLiftChance / 100.0f);

        if (airLiftChance > 100) {
            airLiftChance = 100;
        }

        if (targetActor->debuff) {
            airLiftChance = ((airLiftChance * 4) + airLiftChance) * 30;
            airLiftChance = airLiftChance / 100.0f;

            if (airLiftChance > 150) {
                airLiftChance = 150;
            }
        }
    }

    script->varTable[15] = airLiftChance;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/parakarry_6FFD80", func_80238E24_700BA4);

INCLUDE_ASM(s32, "battle/partner/parakarry_6FFD80", func_802390B4_700E34);

INCLUDE_ASM(s32, "battle/partner/parakarry_6FFD80", func_802397C8_701548);
