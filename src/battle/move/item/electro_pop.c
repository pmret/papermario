#include "common.h"
#include "script_api/battle.h"
#include "sprite/player.h"

#include "effects.h"

#define NAMESPACE battle_item_electro_pop

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_7307DC)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    inflict_status(player, STATUS_KEY_STATIC, script->varTable[0]);
    player->statusAfflicted = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnHeartRecoveryFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(0, a, b, c, d);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnFlowerRecoveryFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(1, a, b, c, d);

    return ApiStatus_DONE2;
}

#if !VERSION_PAL
#include "common/AddHP.inc.c"

API_CALLABLE(N(func_802A1450_7309F0)) {
    ItemData* item = &gItemTable[ITEM_ELECTRO_POP];
    PlayerData* playerData = &gPlayerData;

    playerData->curHP += item->potencyA;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }

    script->varTable[3] = item->potencyA;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(AddFP)) {
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
#endif

API_CALLABLE(N(func_802A14F0_730A90)) {
    ItemData* item = &gItemTable[ITEM_ELECTRO_POP];
    PlayerData* playerData = &gPlayerData;

#if VERSION_PAL
    playerData->curFP += item->potencyB;
#else
    playerData->curFP += item->potencyA;
#endif
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
    }

    script->varTable[3] = item->potencyB;

    return ApiStatus_DONE2;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    EVT_SET_CONST(LVarA, ITEM_ELECTRO_POP)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_EXEC_WAIT(N(EatItem))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0)
    EVT_CALL(PlaySound, SOUND_VOLT_SHROOM_APPLY)
    EVT_CALL(GetItemPower, ITEM_VOLT_SHROOM, LVar0, LVar1)
    EVT_CALL(N(func_802A123C_7307DC))
    EVT_WAIT(40)
    EVT_CALL(N(func_802A14F0_730A90))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar1, 25)
    EVT_CALL(N(SpawnFlowerRecoveryFX), LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVar3)
#if !VERSION_PAL
    EVT_CALL(N(AddFP), LVar3)
#endif
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_WAIT(20)
    EVT_CALL(ShowMessageBox, BTL_MSG_PLAYER_CHARGED, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
