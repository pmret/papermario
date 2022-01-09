#include "common.h"
#include "effects.h"
#include "script_api/battle.h"

ApiStatus func_802C0000(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    playFX_11(0, a, b, c, 60.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_802C00AC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    playFX_40(0, a, b, c, d);
    return ApiStatus_DONE2;
}

ApiStatus func_802C016C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    playFX_40(1, a, b, c, d);
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
    gOverrideFlags |= 0x200000;
    return ApiStatus_DONE2;
}

ApiStatus func_802C031C(Evt* script, s32 isInitialCall) {
    set_time_freeze_mode(TIME_FREEZE_NORMAL);
    gOverrideFlags &= ~0x200000;
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

EvtSource D_802C0410 = {
    EVT_SET_GROUP(0)
    EVT_CALL(SetPlayerAnimation, ANIM_GOT_ITEM)
    EVT_CALL(GetPlayerPos, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 45)
    EVT_CALL(MakeItemEntity, LW(10), LW(0), LW(1), LW(2), 1, 0)
    EVT_SET(LW(10), LW(0))
    EVT_WAIT_FRAMES(15)
    EVT_CALL(GetPlayerPos, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 20)
    EVT_CALL(func_802C0000, LW(0), LW(1), LW(2))
    EVT_CALL(RemoveItemEntity, LW(10))
    EVT_RETURN
    EVT_END
};

EvtSource D_802C04F4 = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySound, SOUND_2095)
            EVT_WAIT_FRAMES(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_EAT)
    EVT_WAIT_FRAMES(45)
    EVT_RETURN
    EVT_END
};

EvtSource D_802C0560 = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySound, SOUND_2095)
            EVT_WAIT_FRAMES(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_DRINK)
    EVT_WAIT_FRAMES(45)
    EVT_RETURN
    EVT_END
};

EvtSource D_802C05CC_32579C = {
    EVT_SET_GROUP(0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetCurrentPartner, LW(0))
    EVT_IF_NE(LW(0), 0)
        EVT_CALL(func_802D2B6C)
        EVT_WAIT_FRAMES(20)
    EVT_END_IF
    EVT_CALL(func_802C02E4)
    EVT_CALL(func_802C0358, LW(10))
    EVT_EXEC_WAIT(D_802C0410)
    EVT_IF_EQ(LW(13), 0)
        EVT_EXEC_WAIT(D_802C04F4)
    EVT_ELSE
        EVT_EXEC_WAIT(D_802C0560)
    EVT_END_IF
    EVT_IF_EQ(LW(15), 1)
        EVT_CALL(SetPlayerAnimation, ANIM_STICK_OUT_TONGUE)
    EVT_END_IF
    EVT_IF_GT(LW(11), 0)
        EVT_CALL(GetPlayerPos, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 0)
        EVT_ADD(LW(1), 35)
        EVT_CALL(func_802C00AC, LW(0), LW(1), LW(2), LW(11))
    EVT_END_IF
    EVT_IF_GT(LW(12), 0)
        EVT_CALL(GetPlayerPos, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 20)
        EVT_ADD(LW(1), 25)
        EVT_CALL(func_802C016C, LW(0), LW(1), LW(2), LW(12))
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 25)
    EVT_CALL(func_802D7520, LW(0), LW(1), LW(2), LW(11))
    EVT_IF_NE(LW(11), 0)
        EVT_CALL(func_802C022C, LW(11))
    EVT_END_IF
    EVT_IF_NE(LW(12), 0)
        EVT_CALL(func_802C0288, LW(12))
    EVT_END_IF
    EVT_IF_EQ(LW(15), 0)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetPlayerAnimation, ANIM_THUMBS_UP)
        EVT_WAIT_FRAMES(30)
    EVT_ELSE
        EVT_WAIT_FRAMES(30)
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LW(0), LW(1), LW(2))
    EVT_CALL(func_802D75D8, LW(0), LW(1), LW(2), LW(11))
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(func_802C03E8)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(func_802C031C)
    EVT_RETURN
    EVT_END
};
