#define NAMESPACE battle_partner_watt

#include "common.h"

INCLUDE_ASM(s32, "battle/partner/703AF0", func_80238000_703AF0);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_80238370_703E60);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_802383C0_703EB0);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_802383D4_703EC4);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_802383E4_703ED4);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_802383F8_703EE8);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_80238408_703EF8);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_80238434_703F24);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_80238478_703F68);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_802384B0_703FA0);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_80238570_704060);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_8023859C_70408C);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_80238668_704158);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_80238784_704274);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_80238810_704300);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_80238B3C_70462C);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_80238C08_7046F8);

INCLUDE_ASM(s32, "battle/partner/703AF0", func_80238C84_704774);

ApiStatus N(AverageTargetParalyzeChance)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor;
    ActorPart* targetActorPart;
    s32 targetActorDescBaseStatusChance;
    s32 chanceTotal = 0;
    s32 nTargets = 0;
    s32 i;

    for (i = 0; i < partnerActor->targetListLength; i++) {
        targetActor = get_actor(partnerActor->targetData[i].actorID);
        targetActorPart = get_actor_part(targetActor, partnerActor->targetData[i].partID);
        targetActorDescBaseStatusChance = lookup_status_chance(targetActor->statusTable, STATUS_PARALYZE);

        if (targetActor->transStatus == 14) {
            targetActorDescBaseStatusChance = 0;
        }

        if (targetActorPart->eventFlags & 0x20) {
            targetActorDescBaseStatusChance = 0;
        }

        if (targetActorDescBaseStatusChance > 0) {
            chanceTotal += targetActorDescBaseStatusChance;
            nTargets++;
        }
    }

    if (nTargets > 0) {
        script->varTable[0] = chanceTotal / nTargets;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}
