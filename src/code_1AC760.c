#include "common.h"

INCLUDE_ASM(s32, "code_1AC760", dispatch_event_partner);

INCLUDE_ASM(s32, "code_1AC760", dispatch_event_partner_continue_turn);

INCLUDE_ASM(s32, "code_1AC760", calc_partner_test_enemy);

INCLUDE_ASM(s32, "code_1AC760", calc_partner_damage_enemy);

INCLUDE_ASM(s32, "code_1AC760", dispatch_damage_event_partner);

INCLUDE_ASM(s32, "code_1AC760", dispatch_damage_event_partner_0);

INCLUDE_ASM(s32, "code_1AC760", dispatch_damage_event_partner_1);

INCLUDE_ASM(s32, "code_1AC760", MakeOwnerTargetIndex);

INCLUDE_ASM(s32, "code_1AC760", func_8027FC90);

ApiStatus GetActorLevel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = get_variable(script, *args++);
    Bytecode* outVar;

    if (actorID == -0x7F) {
        actorID = script->owner1.enemyID;
    }

    outVar = *args++;
    set_variable(script, outVar, get_actor(actorID)->staticActorData->level);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1AC760", PartnerDamageEnemy);

INCLUDE_ASM(s32, "code_1AC760", PartnerAfflictEnemy);

INCLUDE_ASM(s32, "code_1AC760", PartnerPowerBounceEnemy);

INCLUDE_ASM(s32, "code_1AC760", PartnerTestEnemy);

INCLUDE_ASM(s32, "code_1AC760", func_8028070C);

INCLUDE_ASM(s32, "code_1AC760", DeletePartner);

INCLUDE_ASM(s32, "code_1AC760", func_802807D0);

INCLUDE_ASM(s32, "code_1AC760", func_80280818);
