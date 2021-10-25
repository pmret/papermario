#include "volt_shroom.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_71AA2C)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    inflict_status(player, STATUS_STATIC, script->varTable[0]);
    player->status = 0;
    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x0000008B)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_EXEC_WAIT(N(EatItem))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SET(EVT_VAR(3), 20)
    EVT_CALL(MultiplyByActorScale, EVT_VAR(3))
    EVT_ADD(EVT_VAR(1), EVT_VAR(3))
    EVT_SETF(EVT_VAR(3), EVT_FIXED(1.0))
    EVT_CALL(MultiplyByActorScale, EVT_VAR(3))
    EVT_CALL(PlayEffect, 0x57, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySound, SOUND_UNKNOWN_379)
    EVT_CALL(GetItemPower, ITEM_VOLT_SHROOM, EVT_VAR(0), EVT_VAR(1))
    EVT_CALL(N(func_802A123C_71AA2C))
    EVT_WAIT_FRAMES(20)
    EVT_CALL(ShowMessageBox, 16, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
