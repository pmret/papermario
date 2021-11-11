#include "repel_gel.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_72DDAC)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    ActorPart* part = player->partsTable;

    inflict_status(player, STATUS_E, script->varTable[0]);
    player->status = 0;
    part->flags |= ACTOR_PART_FLAG_100;

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x00000097)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_375)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30008)
    EVT_WAIT_FRAMES(45)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 20)
    EVT_CALL(PlayEffect, 0x33, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_FIXED(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_376)
    EVT_CALL(GetItemPower, ITEM_REPEL_GEL, EVT_VAR(0), EVT_VAR(1))
    EVT_CALL(N(func_802A123C_72DDAC))
    EVT_WAIT_FRAMES(20)
    EVT_CALL(ShowMessageBox, 17, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

