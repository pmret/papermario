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

EvtScript N(main) = {
    EVT_SET_CONST(LocalVar(10), 0x0000008B)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_EXEC_WAIT(N(EatItem))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SET(LocalVar(3), 20)
    EVT_CALL(MultiplyByActorScale, LocalVar(3))
    EVT_ADD(LocalVar(1), LocalVar(3))
    EVT_SETF(LocalVar(3), EVT_FLOAT(1.0))
    EVT_CALL(MultiplyByActorScale, LocalVar(3))
    EVT_CALL(PlayEffect, 0x57, 0, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySound, SOUND_379)
    EVT_CALL(GetItemPower, ITEM_VOLT_SHROOM, LocalVar(0), LocalVar(1))
    EVT_CALL(N(func_802A123C_71AA2C))
    EVT_WAIT(20)
    EVT_CALL(ShowMessageBox, 16, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
