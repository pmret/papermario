
#include "kzn_03.h"

extern EvtScript N(EVS_802451E4);
extern EvtScript N(EVS_80245240);

ApiStatus N(func_80242DB0_C63AC0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_168, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

ApiStatus N(func_80242E54_C63B64)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_185, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80242EF8_C63C08);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C63A10", func_80242EF8_C63C08);

ApiStatus N(func_80243070_C63D80)(Evt* script, s32 isInitialCall) {
    script->varTable[8] = gGameStatusPtr->pressedButtons[0] & BUTTON_A;
    return ApiStatus_DONE2;
}

f32 N(D_80246990_C676A0)[] = {
    -327.5, 1008.7, -55.0, 233.9, 914.0, -55.0, 
};

f32 N(D_802469A8_C676B8)[] = {
    297.0, 608.0, 255.0, -362.0, 267.0, 255.0, 
};

EvtScript N(D_802469C0_C676D0) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246A28_C67738) = {
    EVT_CALL(GetCurrentPartner, LVar9)
    EVT_IF_EQ(LVar9, 2)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar9, 3)
        EVT_RETURN
    EVT_END_IF
    EVT_USE_ARRAY(LVar0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(D_802469C0_C676D0), LVar9)
    EVT_THREAD
        EVT_WAIT(7)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_40 | NPC_FLAG_100, TRUE)
        EVT_SET(LVar0, ArrayVar(4))
        EVT_SUB(LVar0, 10)
        EVT_SET(LVar1, ArrayVar(5))
        EVT_ADD(LVar1, -5)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump0, NPC_PARTNER, ArrayVar(3), LVar0, LVar1, 8)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x00000106)
    EVT_END_THREAD
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.2))
    EVT_CALL(PlayerJump, ArrayVar(3), ArrayVar(4), ArrayVar(5), 5)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_8000D)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_CALL(PlaySound, SOUND_80000019)
    EVT_CHILD_THREAD
        EVT_SET(MF_Unk_0A, TRUE)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_SET(AB_KZN_0, ArrayVar(6))
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_CALL(N(func_80242DB0_C63AC0), MF_Unk_0A, LVar1, LVar2, LVar3)
            EVT_IF_NE(AB_KZN_0, LVar0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, 0, 1000, 70, EASING_QUADRATIC_IN)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(func_80242EF8_C63C08, 0)
    EVT_CALL(TranslateModel, ArrayVar(1), LVar5, LVar6, LVar7)
    EVT_CALL(TranslateModel, ArrayVar(2), LVar5, LVar6, LVar7)
    EVT_WAIT(1)
    EVT_CALL(N(func_80243070_C63D80))
    EVT_IF_EQ(LVar8, 0x00008000)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_2087)
    EVT_LABEL(10)
    EVT_CALL(SetPlayerFlagBits, PS_FLAGS_800000, TRUE)
    EVT_SET(MF_Unk_0A, FALSE)
    EVT_CALL(StopSound, SOUND_80000019)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_40, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_KILL_THREAD(LVar9)
    EVT_WAIT(20)
    EVT_CALL(PlaySound, SOUND_8000001A)
    EVT_CHILD_THREAD
        EVT_SET(MF_Unk_0B, TRUE)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_SET(AB_KZN_1, ArrayVar(6))
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_CALL(N(func_80242E54_C63B64), MF_Unk_0B, LVar1, LVar2, LVar3)
            EVT_IF_NE(AB_KZN_1, LVar0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_SET(LVar2, LVar0)
    EVT_DIV(LVar2, 10)
    EVT_CALL(MakeLerp, LVar0, 0, LVar2, EASING_LINEAR)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(func_80242EF8_C63C08, 1)
    EVT_CALL(TranslateModel, ArrayVar(1), LVar5, LVar6, LVar7)
    EVT_CALL(TranslateModel, ArrayVar(2), LVar5, LVar6, LVar7)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_SET(MF_Unk_0B, FALSE)
    EVT_CALL(StopSound, SOUND_8000001A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80247044) = {
    EVT_MALLOC_ARRAY(7, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_SET(ArrayVar(0), EVT_PTR(N(D_80246990_C676A0)))
    EVT_SET(ArrayVar(1), 53)
    EVT_SET(ArrayVar(2), 55)
    EVT_SET(ArrayVar(3), -327)
    EVT_SET(ArrayVar(4), 895)
    EVT_SET(ArrayVar(5), -46)
    EVT_SET(ArrayVar(6), 1)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80246A28_C67738)), TRIGGER_FLOOR_PRESS_A, COLLIDER_ropeway1, 1, 0)
    EVT_EXEC(N(EVS_802451E4))
    EVT_MALLOC_ARRAY(7, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_SET(ArrayVar(0), EVT_PTR(N(D_802469A8_C676B8)))
    EVT_SET(ArrayVar(1), 59)
    EVT_SET(ArrayVar(2), 57)
    EVT_SET(ArrayVar(3), 298)
    EVT_SET(ArrayVar(4), 495)
    EVT_SET(ArrayVar(5), 265)
    EVT_SET(ArrayVar(6), 2)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80246A28_C67738)), TRIGGER_FLOOR_PRESS_A, COLLIDER_ropeway2, 1, 0)
    EVT_EXEC(N(EVS_80245240))
    EVT_RETURN
    EVT_END
};
