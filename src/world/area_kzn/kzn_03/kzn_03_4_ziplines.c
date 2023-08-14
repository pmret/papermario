
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
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RideZipline) = {
    EVT_CALL(GetPartnerInUse, LVar9)
    EVT_IF_EQ(LVar9, PARTNER_KOOPER)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar9, PARTNER_BOMBETTE)
        EVT_RETURN
    EVT_END_IF
    EVT_USE_ARRAY(LVar0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(EVS_Zipline_TetherCameraToPlayer), LVar9)
    EVT_THREAD
        EVT_WAIT(7)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_SET(LVar0, ArrayVar(4))
        EVT_SUB(LVar0, 10)
        EVT_SET(LVar1, ArrayVar(5))
        EVT_ADD(LVar1, -5)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump0, NPC_PARTNER, ArrayVar(3), LVar0, LVar1, 8)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_END_THREAD
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.2))
    EVT_CALL(PlayerJump, ArrayVar(3), ArrayVar(4), ArrayVar(5), 5)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_HoldOnto)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_CALL(PlaySound, SOUND_LOOP_ZIPLINE_RIDE)
    EVT_CHILD_THREAD
        EVT_SET(MF_RidingZipline1, TRUE)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_SET(AB_KZN_LastZiplineNpc1, ArrayVar(6))
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_CALL(N(Zipline_AdjustMoveDownSound), MF_RidingZipline1, LVar1, LVar2, LVar3)
            EVT_IF_NE(AB_KZN_LastZiplineNpc1, LVar0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(MakeLerp, 0, 1000, 70, EASING_QUADRATIC_IN)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(Zipline_UpdatePlayerPos), 0)
        EVT_CALL(TranslateModel, ArrayVar(1), LVar5, LVar6, LVar7)
        EVT_CALL(TranslateModel, ArrayVar(2), LVar5, LVar6, LVar7)
        EVT_WAIT(1)
        EVT_CALL(N(Zipline_CheckInputForJumpOff))
        EVT_IF_EQ(LVar8, BUTTON_A)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(PlaySound, SOUND_ZIPLINE_FINISH)
        EVT_LABEL(10)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_SCRIPTED_FALL, TRUE)
    EVT_SET(MF_RidingZipline1, FALSE)
    EVT_CALL(StopSound, SOUND_LOOP_ZIPLINE_RIDE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_KILL_THREAD(LVar9)
    EVT_WAIT(20)
    EVT_CALL(PlaySound, SOUND_LOOP_ZIPLINE_RETURN)
    EVT_CHILD_THREAD
        EVT_SET(MF_RidingZipline2, TRUE)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_SET(AB_KZN_LastZiplineNpc2, ArrayVar(6))
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_CALL(N(Zipline_AdjustMoveUpSound), MF_RidingZipline2, LVar1, LVar2, LVar3)
            EVT_IF_NE(AB_KZN_LastZiplineNpc2, LVar0)
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
        EVT_CALL(N(Zipline_UpdatePlayerPos), 1)
        EVT_CALL(TranslateModel, ArrayVar(1), LVar5, LVar6, LVar7)
        EVT_CALL(TranslateModel, ArrayVar(2), LVar5, LVar6, LVar7)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_SET(MF_RidingZipline2, FALSE)
    EVT_CALL(StopSound, SOUND_LOOP_ZIPLINE_RETURN)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupZiplines) = {
    EVT_MALLOC_ARRAY(7, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_SET(ArrayVar(0), EVT_PTR(N(Zipline_Endpoints1)))
    EVT_SET(ArrayVar(1), MODEL_kassya_koma)
    EVT_SET(ArrayVar(2), MODEL_kassya_himo)
    EVT_SET(ArrayVar(3), -327)
    EVT_SET(ArrayVar(4), 895)
    EVT_SET(ArrayVar(5), -46)
    EVT_SET(ArrayVar(6), NPC_ZiplineDummy1)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_RideZipline)), TRIGGER_FLOOR_PRESS_A, COLLIDER_ropeway1, 1, 0)
    EVT_EXEC(N(EVS_SyncZiplineDummyNPC1))
    EVT_MALLOC_ARRAY(7, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_SET(ArrayVar(0), EVT_PTR(N(Zipline_Endpoints2)))
    EVT_SET(ArrayVar(1), MODEL_kssya2_koma)
    EVT_SET(ArrayVar(2), MODEL_kassya2_himo)
    EVT_SET(ArrayVar(3), 298)
    EVT_SET(ArrayVar(4), 495)
    EVT_SET(ArrayVar(5), 265)
    EVT_SET(ArrayVar(6), NPC_ZiplineDummy2)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_RideZipline)), TRIGGER_FLOOR_PRESS_A, COLLIDER_ropeway2, 1, 0)
    EVT_EXEC(N(EVS_SyncZiplineDummyNPC2))
    EVT_RETURN
    EVT_END
};
