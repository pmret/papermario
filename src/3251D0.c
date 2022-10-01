#include "common.h"
#include "effects.h"
#include "script_api/battle.h"

ApiStatus func_802C0000(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    fx_sparkles(FX_SPARKLES_0, a, b, c, 60.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_802C00AC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(0, a, b, c, d);
    return ApiStatus_DONE2;
}

ApiStatus func_802C016C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(1, a, b, c, d);
    return ApiStatus_DONE2;
}

ApiStatus func_802C022C(Evt* script, s32 isInitialCall) {
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

ApiStatus func_802C0288(Evt* script, s32 isInitialCall) {
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

ApiStatus func_802C02E4(Evt* script, s32 isInitialCall) {
    set_time_freeze_mode(TIME_FREEZE_FULL);
    gOverrideFlags |= GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS;
    return ApiStatus_DONE2;
}

ApiStatus func_802C031C(Evt* script, s32 isInitialCall) {
    set_time_freeze_mode(TIME_FREEZE_NORMAL);
    gOverrideFlags &= ~GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS;
    return ApiStatus_DONE2;
}

ApiStatus func_802C0358(Evt* script, s32 isInitialCall) {
    s32 itemIdx = evt_get_variable(script, *script->ptrReadPos);
    s32 var15;

    script->varTable[11] = (&gItemTable[itemIdx])->potencyA;
    script->varTable[12] = (&gItemTable[itemIdx])->potencyB;
    script->varTable[13] = 0;

    if ((&gItemTable[itemIdx])->typeFlags & 0x100) {
        script->varTable[13] = 1;
    }

    var15 = 0;
    if (script->varTable[11] < 0 || (script->varTable[11] <= 0 && script->varTable[12] < 0)) {
        var15 = 1;
    }
    script->varTable[15] = var15;

    return ApiStatus_DONE2;
}

ApiStatus func_802C03E8(Evt* script, s32 isInitialCall) {
    remove_consumable();
    return ApiStatus_DONE2;
}

EvtScript D_802C0410 = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_GotItem)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 45)
    EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 1, 0)
    EVT_SET(LVarA, LVar0)
    EVT_WAIT(15)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(func_802C0000, LVar0, LVar1, LVar2)
    EVT_CALL(RemoveItemEntity, LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript D_802C04F4 = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySound, SOUND_2095)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_Eat)
    EVT_WAIT(45)
    EVT_RETURN
    EVT_END
};

EvtScript D_802C0560 = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySound, SOUND_2095)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_Drink)
    EVT_WAIT(45)
    EVT_RETURN
    EVT_END
};

EvtScript D_802C05CC_32579C = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetCurrentPartner, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_CALL(func_802C02E4)
    EVT_CALL(func_802C0358, LVarA)
    EVT_EXEC_WAIT(D_802C0410)
    EVT_IF_EQ(LVarD, 0)
        EVT_EXEC_WAIT(D_802C04F4)
    EVT_ELSE
        EVT_EXEC_WAIT(D_802C0560)
    EVT_END_IF
    EVT_IF_EQ(LVarF, 1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_StickOutTongue)
    EVT_END_IF
    EVT_IF_GT(LVarB, 0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 0)
        EVT_ADD(LVar1, 35)
        EVT_CALL(func_802C00AC, LVar0, LVar1, LVar2, LVarB)
    EVT_END_IF
    EVT_IF_GT(LVarC, 0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 20)
        EVT_ADD(LVar1, 25)
        EVT_CALL(func_802C016C, LVar0, LVar1, LVar2, LVarC)
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    EVT_IF_NE(LVarB, 0)
        EVT_CALL(func_802C022C, LVarB)
    EVT_END_IF
    EVT_IF_NE(LVarC, 0)
        EVT_CALL(func_802C0288, LVarC)
    EVT_END_IF
    EVT_IF_EQ(LVarF, 0)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_ThumbsUp)
        EVT_WAIT(30)
    EVT_ELSE
        EVT_WAIT(30)
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(20)
    EVT_CALL(func_802C03E8)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(func_802C031C)
    EVT_RETURN
    EVT_END
};
