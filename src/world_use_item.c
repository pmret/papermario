#include "common.h"
#include "effects.h"
#include "script_api/battle.h"
#include "sprite/player.h"

API_CALLABLE(WorldItem_ShowUseSparkles) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_sparkles(FX_SPARKLES_0, x, y, z, 60.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(WorldItem_ShowHPGain) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 amt = evt_get_variable(script, *args++);

    fx_recover(0, x, y, z, amt);
    return ApiStatus_DONE2;
}

API_CALLABLE(WorldItem_ShowFPGain) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 amt = evt_get_variable(script, *args++);

    fx_recover(1, x, y, z, amt);
    return ApiStatus_DONE2;
}

API_CALLABLE(WorldItem_RestoreHP) {
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

API_CALLABLE(WorldItem_RestoreFP) {
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

API_CALLABLE(WorldItem_PauseTime) {
    set_time_freeze_mode(TIME_FREEZE_FULL);
#if !VERSION_JP
    gOverrideFlags |= GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS;
#endif
    return ApiStatus_DONE2;
}

API_CALLABLE(WorldItem_UnpauseTime) {
    set_time_freeze_mode(TIME_FREEZE_NORMAL);
#if !VERSION_JP
    gOverrideFlags &= ~GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS;
#endif
    return ApiStatus_DONE2;
}

API_CALLABLE(WorldItem_GetItemProperties) {
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

API_CALLABLE(WorldItem_ConsumeItem) {
    remove_consumable();
    return ApiStatus_DONE2;
}

EvtScript EVS_WorldItem_ShowUsedItem = {
    SetGroup(EVT_GROUP_00)
    Call(SetPlayerAnimation, ANIM_Mario1_UsePower)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar1, 45)
    Call(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 1, 0)
    Set(LVarA, LVar0)
    Wait(15)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(WorldItem_ShowUseSparkles, LVar0, LVar1, LVar2)
    Call(RemoveItemEntity, LVarA)
    Return
    End
};

EvtScript EVS_WorldItem_PlayEatingSounds = {
    Thread
        Loop(4)
            Call(PlaySound, SOUND_EAT_OR_DRINK)
            Wait(10)
        EndLoop
    EndThread
    Call(SetPlayerAnimation, ANIM_Mario1_Eat)
    Wait(45)
    Return
    End
};

EvtScript EVS_WorldItem_PlayDrinkingSounds = {
    Thread
        Loop(4)
            Call(PlaySound, SOUND_EAT_OR_DRINK)
            Wait(10)
        EndLoop
    EndThread
    Call(SetPlayerAnimation, ANIM_Mario1_Drink)
    Wait(45)
    Return
    End
};

EvtScript EVS_World_UseItem = {
    SetGroup(EVT_GROUP_00)
    Call(DisablePlayerInput, TRUE)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, 0)
        Call(InterruptUsePartner)
        Wait(20)
    EndIf
    Call(WorldItem_PauseTime)
    Call(WorldItem_GetItemProperties, LVarA)
    ExecWait(EVS_WorldItem_ShowUsedItem)
    IfEq(LVarD, 0)
        ExecWait(EVS_WorldItem_PlayEatingSounds)
    Else
        ExecWait(EVS_WorldItem_PlayDrinkingSounds)
    EndIf
    IfEq(LVarF, 1)
        Call(SetPlayerAnimation, ANIM_Mario1_StickOutTongue)
    EndIf
    IfGt(LVarB, 0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 0)
        Add(LVar1, 35)
        Call(WorldItem_ShowHPGain, LVar0, LVar1, LVar2, LVarB)
    EndIf
    IfGt(LVarC, 0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 20)
        Add(LVar1, 25)
        Call(WorldItem_ShowFPGain, LVar0, LVar1, LVar2, LVarC)
    EndIf
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar1, 25)
    Call(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    IfNe(LVarB, 0)
        Call(WorldItem_RestoreHP, LVarB)
    EndIf
    IfNe(LVarC, 0)
        Call(WorldItem_RestoreFP, LVarC)
    EndIf
    IfEq(LVarF, 0)
        Wait(10)
        Call(SetPlayerAnimation, ANIM_Mario1_ThumbsUp)
        Wait(30)
    Else
        Wait(30)
    EndIf
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(ShowRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(20)
    Call(WorldItem_ConsumeItem)
    Call(DisablePlayerInput, FALSE)
    Call(WorldItem_UnpauseTime)
    Return
    End
};

MATCHING_BSS(0x2700);
