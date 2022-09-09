#include "electro_pop.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_7307DC)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    inflict_status(player, STATUS_STATIC, script->varTable[0]);
    player->status = 0;
    return ApiStatus_DONE2;
}

ApiStatus N(func_802A127C_73081C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(0, a, b, c, d);

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A133C_7308DC)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(1, a, b, c, d);

    return ApiStatus_DONE2;
}

#include "common/AddHP.inc.c"

ApiStatus N(func_802A1450_7309F0)(Evt* script, s32 isInitialCall) {
    ItemData* item = &gItemTable[ITEM_ELECTRO_POP];
    PlayerData* playerData = &gPlayerData;

    playerData->curHP += item->potencyA;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }

    script->varTable[3] = item->potencyA;

    return ApiStatus_DONE2;
}

ApiStatus N(AddFP)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 amt = evt_get_variable(script, *script->ptrReadPos);

    // @bug Should be playerData->curFP
    s32 newFP = playerData->curHP + amt;

    if (newFP > playerData->curMaxFP) {
        newFP = playerData->curMaxFP;
    }

    playerData->curFP = newFP;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A14F0_730A90)(Evt* script, s32 isInitialCall) {
    ItemData* item = &gItemTable[ITEM_ELECTRO_POP];
    PlayerData* playerData = &gPlayerData;

    playerData->curFP += item->potencyA;
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
    }

    script->varTable[3] = item->potencyB;

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtScript N(main) = {
    EVT_SET_CONST(LVarA, 0x000000CC)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_EXEC_WAIT(N(EatItem))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(PlayEffect, 0x57, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySound, SOUND_379)
    EVT_CALL(GetItemPower, ITEM_VOLT_SHROOM, LVar0, LVar1)
    EVT_CALL(N(func_802A123C_7307DC))
    EVT_WAIT(40)
    EVT_CALL(N(func_802A14F0_730A90))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar1, 25)
    EVT_CALL(N(func_802A133C_7308DC), LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(N(AddFP), LVar3)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_THUMBS_UP)
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_WAIT(20)
    EVT_CALL(ShowMessageBox, 16, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
