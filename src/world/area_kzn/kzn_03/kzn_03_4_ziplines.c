
#include "kzn_03.h"
#include "sprite/player.h"

API_CALLABLE(N(Zipline_AdjustMoveDownSound)) {
    Bytecode* args = script->ptrReadPos;

    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_LRAW_ZIPLINE_RIDE, SOUND_SPACE_DEFAULT, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Zipline_AdjustMoveUpSound)) {
    Bytecode* args = script->ptrReadPos;

    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_LRAW_ZIPLINE_RETURN, SOUND_SPACE_DEFAULT, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Zipline_UpdatePlayerPos)) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_v0 = evt_get_variable(script, *args++);
    f32* array = *(f32**) script->array;
    f32 dx = array[3] - array[0];
    f32 dy = array[4] - array[1];
    f32 dz = array[5] - array[2];

    script->varTable[5] = (dx / 1000.0f) * script->varTable[0];
    script->varTable[6] = (dy / 1000.0f) * script->varTable[0];
    script->varTable[7] = (dz / 1000.0f) * script->varTable[0];
    if (temp_v0 == 0) {
        Npc* partner = get_npc_safe(NPC_PARTNER);
        gPlayerStatus.pos.x = script->varTable[2] + script->varTable[5];
        gPlayerStatus.pos.y = script->varTable[3] + script->varTable[6];
        gPlayerStatus.pos.z = script->varTable[4] + script->varTable[7];
        gPlayerStatus.targetYaw = atan2(array[0], array[2], array[3], array[5]);
        partner->pos.x = gPlayerStatus.pos.x;
        partner->pos.y = gPlayerStatus.pos.y - 10.0f;
        partner->pos.z = gPlayerStatus.pos.z - 5.0f;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Zipline_CheckInputForJumpOff)) {
    script->varTable[8] = gGameStatusPtr->pressedButtons[0] & BUTTON_A;
    return ApiStatus_DONE2;
}

Vec3f N(Zipline_Endpoints1)[] = {
    { -327.5, 1008.7, -55.0 },
    {  233.9,  914.0, -55.0 },
};

Vec3f N(Zipline_Endpoints2)[] = {
    {  297.0, 608.0, 255.0 },
    { -362.0, 267.0, 255.0 },
};

EvtScript N(EVS_Zipline_TetherCameraToPlayer) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_RideZipline) = {
    Call(GetPartnerInUse, LVar9)
    IfEq(LVar9, PARTNER_KOOPER)
        Return
    EndIf
    IfEq(LVar9, PARTNER_BOMBETTE)
        Return
    EndIf
    UseArray(LVar0)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Wait(1)
    ExecGetTID(N(EVS_Zipline_TetherCameraToPlayer), LVar9)
    Thread
        Wait(7)
        Call(DisablePartnerAI, 0)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Set(LVar0, ArrayVar(4))
        Sub(LVar0, 10)
        Set(LVar1, ArrayVar(5))
        Add(LVar1, -5)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.5))
        Call(NpcJump0, NPC_PARTNER, ArrayVar(3), LVar0, LVar1, 8)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EndThread
    Call(SetPlayerJumpscale, Float(0.2))
    Call(PlayerJump, ArrayVar(3), ArrayVar(4), ArrayVar(5), 5)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_MarioW2_HoldOnto)
    Wait(10)
    Call(GetPlayerPos, LVar2, LVar3, LVar4)
    Call(PlaySound, SOUND_LOOP_ZIPLINE_RIDE)
    ChildThread
        Set(MF_RidingZipline1, TRUE)
        Set(LVar0, ArrayVar(6))
        Set(AB_KZN_LastZiplineNpc1, ArrayVar(6))
        Loop(0)
            Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            Call(N(Zipline_AdjustMoveDownSound), MF_RidingZipline1, LVar1, LVar2, LVar3)
            IfNe(AB_KZN_LastZiplineNpc1, LVar0)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    EndChildThread
    Call(MakeLerp, 0, 1000, 70, EASING_QUADRATIC_IN)
    Label(0)
        Call(UpdateLerp)
        Call(N(Zipline_UpdatePlayerPos), 0)
        Call(TranslateModel, ArrayVar(1), LVar5, LVar6, LVar7)
        Call(TranslateModel, ArrayVar(2), LVar5, LVar6, LVar7)
        Wait(1)
        Call(N(Zipline_CheckInputForJumpOff))
        IfEq(LVar8, BUTTON_A)
            Goto(10)
        EndIf
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
        Call(PlaySound, SOUND_ZIPLINE_FINISH)
        Label(10)
    Call(SetPlayerFlagBits, PS_FLAG_SCRIPTED_FALL, TRUE)
    Set(MF_RidingZipline1, FALSE)
    Call(StopSound, SOUND_LOOP_ZIPLINE_RIDE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    KillThread(LVar9)
    Wait(20)
    Call(PlaySound, SOUND_LOOP_ZIPLINE_RETURN)
    ChildThread
        Set(MF_RidingZipline2, TRUE)
        Set(LVar0, ArrayVar(6))
        Set(AB_KZN_LastZiplineNpc2, ArrayVar(6))
        Loop(0)
            Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            Call(N(Zipline_AdjustMoveUpSound), MF_RidingZipline2, LVar1, LVar2, LVar3)
            IfNe(AB_KZN_LastZiplineNpc2, LVar0)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    EndChildThread
    Set(LVar2, LVar0)
    Div(LVar2, 10)
    Call(MakeLerp, LVar0, 0, LVar2, EASING_LINEAR)
    Label(1)
        Call(UpdateLerp)
        Call(N(Zipline_UpdatePlayerPos), 1)
        Call(TranslateModel, ArrayVar(1), LVar5, LVar6, LVar7)
        Call(TranslateModel, ArrayVar(2), LVar5, LVar6, LVar7)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Set(MF_RidingZipline2, FALSE)
    Call(StopSound, SOUND_LOOP_ZIPLINE_RETURN)
    Return
    End
};

EvtScript N(EVS_SetupZiplines) = {
    MallocArray(7, LVar0)
    UseArray(LVar0)
    Set(ArrayVar(0), Ref(N(Zipline_Endpoints1)))
    Set(ArrayVar(1), MODEL_kassya_koma)
    Set(ArrayVar(2), MODEL_kassya_himo)
    Set(ArrayVar(3), -327)
    Set(ArrayVar(4), 895)
    Set(ArrayVar(5), -46)
    Set(ArrayVar(6), NPC_ZiplineDummy1)
    BindTrigger(Ref(N(EVS_RideZipline)), TRIGGER_FLOOR_PRESS_A, COLLIDER_ropeway1, 1, 0)
    Exec(N(EVS_SyncZiplineDummyNPC1))
    MallocArray(7, LVar0)
    UseArray(LVar0)
    Set(ArrayVar(0), Ref(N(Zipline_Endpoints2)))
    Set(ArrayVar(1), MODEL_kssya2_koma)
    Set(ArrayVar(2), MODEL_kassya2_himo)
    Set(ArrayVar(3), 298)
    Set(ArrayVar(4), 495)
    Set(ArrayVar(5), 265)
    Set(ArrayVar(6), NPC_ZiplineDummy2)
    BindTrigger(Ref(N(EVS_RideZipline)), TRIGGER_FLOOR_PRESS_A, COLLIDER_ropeway2, 1, 0)
    Exec(N(EVS_SyncZiplineDummyNPC2))
    Return
    End
};
