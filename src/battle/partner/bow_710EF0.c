#include "common.h"

ApiStatus func_80238000_710EF0(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    script->varTable[0] = (s8) battleStatus->outtaSightActive;

    return ApiStatus_DONE2;
}

ApiStatus func_80238014_710F04(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* partnerTargetActor = get_actor(partnerActor->targetActorID);
    f32 partnerTargetActorSize = (partnerTargetActor->size.y + partnerTargetActor->size.x) >> 1;

    partnerTargetActorSize = (partnerTargetActorSize * 150.0f) / 100.0f;
    script->varTable[0] = partnerTargetActorSize;

    return ApiStatus_DONE2;
}

//INCLUDE_ASM(s32, "battle/partner/bow_710EF0", func_8023808C_710F7C);
ApiStatus func_8023808C_710F7C(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->outtaSightActive = 1;
    if ((battleStatus->flags2 & 2) == 0) {
        battleStatus->outtaSightActive = -1;
    }

    //battleStatus->playerActor->partsTable->idleAnimations = &bMarioHideAnims;
    battleStatus->hustleTurns = 0;
    battleStatus->flags1 &= ~0x04000000;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/bow_710EF0", func_802380E4_710FD4);

INCLUDE_ASM(s32, "battle/partner/bow_710EF0", func_80238198_711088);

INCLUDE_ASM(s32, "battle/partner/bow_710EF0", func_802381C8_7110B8);

INCLUDE_ASM(s32, "battle/partner/bow_710EF0", func_802381E8_7110D8);
