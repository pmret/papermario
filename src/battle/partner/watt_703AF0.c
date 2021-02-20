#include "common.h"

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238000_703AF0);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238370_703E60);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_802383C0_703EB0);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_802383D4_703EC4);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_802383E4_703ED4);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_802383F8_703EE8);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238408_703EF8);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238434_703F24);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238478_703F68);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_802384B0_703FA0);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238570_704060);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_8023859C_70408C);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238668_704158);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238784_704274);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238810_704300);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238B3C_70462C);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238C08_7046F8);

INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238C84_704774);

// It matches, but splat split it wrong
#ifdef NON_MATCHING
ApiStatus func_80238E5C_70494C(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor;
    ActorPart* targetActorPart;
    s32 targetActorDescBaseStatusChance;
    s32 var0 = 0;
    s32 var1 = 0;
    s32 var2 = 0;

    for (var2; var2 < partnerActor->targetListLength; var2++) {
        targetActor = get_actor(partnerActor->targetData[var2].actorID);
        targetActorPart = get_actor_part(targetActor, partnerActor->targetData[var2].partID);
        targetActorDescBaseStatusChance = lookup_status_chance(targetActor->statusTable, 4);

        if (targetActor->transStatus == 14) {
            targetActorDescBaseStatusChance = 0;
        }

        if (targetActorPart->eventFlags & 0x20) {
            targetActorDescBaseStatusChance = 0;
        }

        if (targetActorDescBaseStatusChance > 0) {
            var0 += targetActorDescBaseStatusChance;
            var1++;
        }
    }

    if (var1 > 0) {
        script->varTable[0] = (var0 / var1);
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "battle/partner/watt_703AF0", func_80238E5C_70494C)
#endif
