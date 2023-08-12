#include "common.h"
#include "effects.h"
#include "script_api/battle.h"
#include "sprite/player.h"

ApiStatus WorldItem_ShowUseSparkles(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_sparkles(FX_SPARKLES_0, x, y, z, 60.0f);
    return ApiStatus_DONE2;
}

ApiStatus WorldItem_ShowHPGain(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 amt = evt_get_variable(script, *args++);

    fx_recover(0, x, y, z, amt);
    return ApiStatus_DONE2;
}

ApiStatus WorldItem_ShowFPGain(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 amt = evt_get_variable(script, *args++);

    fx_recover(1, x, y, z, amt);
    return ApiStatus_DONE2;
}

ApiStatus WorldItem_RestoreHP(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 newHP = playerData->curHP + evt_get_variable(script, *script->ptrReadPos);

    if (newHP > playerData->curMaxHP) {
        newHP = playerData->curMaxHP;
    }

    if (newHP <= 0) {
        newHP = 1;
    }

    playerData->curHP = newHP;
    return ApiStatus_DONE2;
}

ApiStatus WorldItem_RestoreFP(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 newFP = playerData->curFP + evt_get_variable(script, *script->ptrReadPos);

    if (newFP > playerData->curMaxFP) {
        newFP = playerData->curMaxFP;
    }

    if (newFP <= 0) {
        newFP = 1;
    }

    playerData->curFP = newFP;
    return ApiStatus_DONE2;
}

ApiStatus WorldItem_PauseTime(Evt* script, s32 isInitialCall) {
    set_time_freeze_mode(TIME_FREEZE_FULL);
    gOverrideFlags |= GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS;
    return ApiStatus_DONE2;
}

ApiStatus WorldItem_UnpauseTime(Evt* script, s32 isInitialCall) {
    set_time_freeze_mode(TIME_FREEZE_NORMAL);
    gOverrideFlags &= ~GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS;
    return ApiStatus_DONE2;
}

ApiStatus WorldItem_GetItemProperties(Evt* script, s32 isInitialCall) {
    s32 itemIdx = evt_get_variable(script, *script->ptrReadPos);
    s32 var15;

    script->varTable[11] = (&gItemTable[itemIdx])->potencyA;
    script->varTable[12] = (&gItemTable[itemIdx])->potencyB;
    script->varTable[13] = FALSE;

    if ((&gItemTable[itemIdx])->typeFlags & ITEM_TYPE_FLAG_USE_DRINK_ANIMATION) {
        script->varTable[13] = TRUE;
    }

    var15 = 0;
    if (script->varTable[11] < 0 || (script->varTable[11] <= 0 && script->varTable[12] < 0)) {
        var15 = 1;
    }
    script->varTable[15] = var15;

    return ApiStatus_DONE2;
}

ApiStatus WorldItem_ConsumeItem(Evt* script, s32 isInitialCall) {
    remove_consumable();
    return ApiStatus_DONE2;
}

EvtScript EVS_WorldItem_ShowUsedItem = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_UsePower)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 45)
    EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 1, 0)
    EVT_SET(LVarA, LVar0)
    EVT_WAIT(15)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(WorldItem_ShowUseSparkles, LVar0, LVar1, LVar2)
    EVT_CALL(RemoveItemEntity, LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_WorldItem_PlayEatingSounds = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySound, SOUND_EAT_OR_DRINK)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Eat)
    EVT_WAIT(45)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_WorldItem_PlayDrinkingSounds = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySound, SOUND_EAT_OR_DRINK)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Drink)
    EVT_WAIT(45)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_World_UseItem = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_CALL(WorldItem_PauseTime)
    EVT_CALL(WorldItem_GetItemProperties, LVarA)
    EVT_EXEC_WAIT(EVS_WorldItem_ShowUsedItem)
    EVT_IF_EQ(LVarD, 0)
        EVT_EXEC_WAIT(EVS_WorldItem_PlayEatingSounds)
    EVT_ELSE
        EVT_EXEC_WAIT(EVS_WorldItem_PlayDrinkingSounds)
    EVT_END_IF
    EVT_IF_EQ(LVarF, 1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_StickOutTongue)
    EVT_END_IF
    EVT_IF_GT(LVarB, 0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 0)
        EVT_ADD(LVar1, 35)
        EVT_CALL(WorldItem_ShowHPGain, LVar0, LVar1, LVar2, LVarB)
    EVT_END_IF
    EVT_IF_GT(LVarC, 0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 20)
        EVT_ADD(LVar1, 25)
        EVT_CALL(WorldItem_ShowFPGain, LVar0, LVar1, LVar2, LVarC)
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    EVT_IF_NE(LVarB, 0)
        EVT_CALL(WorldItem_RestoreHP, LVarB)
    EVT_END_IF
    EVT_IF_NE(LVarC, 0)
        EVT_CALL(WorldItem_RestoreFP, LVarC)
    EVT_END_IF
    EVT_IF_EQ(LVarF, 0)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_ThumbsUp)
        EVT_WAIT(30)
    EVT_ELSE
        EVT_WAIT(30)
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(20)
    EVT_CALL(WorldItem_ConsumeItem)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(WorldItem_UnpauseTime)
    EVT_RETURN
    EVT_END
};

MATCHING_BSS(0x2700);
