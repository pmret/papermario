#include "repel_gel.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_72DDAC)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    ActorPart* part = player->partsTable;

    inflict_status(player, STATUS_TRANSPARENT, script->varTable[0]);
    player->status = 0;
    part->flags |= ACTOR_PART_FLAG_100;

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtScript N(main) = {
    EVT_SET_CONST(LocalVar(10), 0x00000097)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_375)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_30008)
    EVT_WAIT(45)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 20)
    EVT_CALL(PlayEffect, 0x33, 3, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_376)
    EVT_CALL(GetItemPower, ITEM_REPEL_GEL, LocalVar(0), LocalVar(1))
    EVT_CALL(N(func_802A123C_72DDAC))
    EVT_WAIT(20)
    EVT_CALL(ShowMessageBox, 17, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

