#include "ultra_shroom.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_7239BC)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    playFX_40(0, a, b, c, d);
    return ApiStatus_DONE2;
}

ApiStatus N(func_802A12FC_723A7C)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP += 10;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x0000008C)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(AddBattleCamZoom, 50)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_EXEC_WAIT(N(EatItem))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 0)
    EVT_ADD(EVT_VAR(1), 35)
    EVT_CALL(N(func_802A123C_7239BC), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 25)
    EVT_ADD(EVT_VAR(2), 5)
    EVT_CALL(func_802D7520, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
    EVT_CALL(N(func_802A12FC_723A7C))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_THUMBS_UP)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(2), 5)
    EVT_CALL(func_802D75D8, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_WAIT_FRAMES(20)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
