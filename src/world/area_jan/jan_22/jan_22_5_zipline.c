#include "jan_22.h"
#include "sprite/player.h"

API_CALLABLE(N(Zipline_AdjustMoveDownSound)) {
    Bytecode* args = script->ptrReadPos;

    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_168, SOUND_SPACE_MODE_0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Zipline_AdjustMoveUpSound)) {
    Bytecode* args = script->ptrReadPos;

    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_185, SOUND_SPACE_MODE_0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Zipline_UpdatePlayerPos)) {
    Bytecode* args = script->ptrReadPos;
    s32 mode = evt_get_variable(script, *args++);
    f32* array = (f32*) script->array[0];

    f32 dx = array[3] - array[0];
    f32 dy = array[4] - array[1];
    f32 dz = array[5] - array[2];

    script->varTable[5] = (dx / 1000.0f) * script->varTable[0];
    script->varTable[6] = (dy / 1000.0f) * script->varTable[0];
    script->varTable[7] = (dz / 1000.0f) * script->varTable[0];

    if (mode == 0) {
        Npc* partner = get_npc_safe(NPC_PARTNER);
        gPlayerStatus.pos.x = (script->varTable[2] + script->varTable[5]);
        gPlayerStatus.pos.y = (script->varTable[3] + script->varTable[6]);
        gPlayerStatus.pos.z = (script->varTable[4] + script->varTable[7]);
        gPlayerStatus.targetYaw = atan2(array[0], array[2], array[3], array[5]);
        partner->pos.x = gPlayerStatus.pos.x;
        partner->pos.y = gPlayerStatus.pos.y - 10.0f;
        partner->pos.z = gPlayerStatus.pos.z - 5.0f;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Zipline_CheckInputForJumpOff)) {
    Bytecode* args = script->ptrReadPos;
    s32 posA = evt_get_variable(script, *args++);
    s32 ax1 = posA - 17;
    s32 ax2 = posA + 17;
    s32 posB = evt_get_variable(script, *args++);
    s32 bx1 = posB - 17;
    s32 bx2 = posB + 17;

    script->varTable[8] = -1;
    if (((gPlayerStatus.pos.x < ax1) || (ax2 < gPlayerStatus.pos.x))
     && ((gPlayerStatus.pos.x < bx1) || (bx2 < gPlayerStatus.pos.x))) {
        script->varTable[8] = gGameStatusPtr->pressedButtons[0] & BUTTON_A;
    }
    return ApiStatus_DONE2;
}

Vec3f N(Zipline_Endpoints1)[] = {
    { 507.0, 407.0, -35.0 },
    { 950.0, 307.0, -35.0 },
};

Vec3f N(Zipline_Endpoints2)[] = {
    { 972.0, 247.0, 65.0 },
    { 530.0, 164.0, 65.0 },
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
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o339, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o276, COLLIDER_FLAGS_UPPER_MASK)
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
    EVT_CALL(SetPlayerJumpscale, 0)
    EVT_CALL(PlayerJump, ArrayVar(3), ArrayVar(4), ArrayVar(5), 7)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_HoldOnto)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_CALL(PlaySound, SOUND_80000019)
    EVT_CHILD_THREAD
        EVT_SET(MF_RidingZipline1, TRUE)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_SET(AB_JAN22_ZiplineNpc1, ArrayVar(6))
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_CALL(N(Zipline_AdjustMoveDownSound), MF_RidingZipline1, LVar1, LVar2, LVar3)
            EVT_IF_NE(AB_JAN22_ZiplineNpc1, LVar0)
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
        EVT_CALL(N(Zipline_CheckInputForJumpOff), ArrayVar(7), ArrayVar(8))
        EVT_IF_EQ(LVar8, BUTTON_A)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(PlaySound, SOUND_2087)
    EVT_LABEL(10)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_SCRIPTED_FALL, TRUE)
    EVT_SET(MF_RidingZipline1, FALSE)
    EVT_CALL(StopSound, SOUND_80000019)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o339, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o339, COLLIDER_FLAG_IGNORE_SHELL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o276, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_KILL_THREAD(LVar9)
    EVT_WAIT(20)
    EVT_CALL(PlaySound, SOUND_8000001A)
    EVT_CHILD_THREAD
        EVT_SET(MF_RidingZipline2, TRUE)
        EVT_SET(LVar0, ArrayVar(6))
        EVT_SET(AB_JAN22_ZiplineNpc2, ArrayVar(6))
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_CALL(N(Zipline_AdjustMoveUpSound), MF_RidingZipline2, LVar1, LVar2, LVar3)
            EVT_IF_NE(AB_JAN22_ZiplineNpc2, LVar0)
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
    EVT_CALL(StopSound, SOUND_8000001A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupZiplines) = {
    EVT_MALLOC_ARRAY(9, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_SET(ArrayVar(0), EVT_PTR(N(Zipline_Endpoints1)))
    EVT_SET(ArrayVar(1), MODEL_o112)
    EVT_SET(ArrayVar(2), MODEL_o113)
    EVT_SET(ArrayVar(3), 507)
    EVT_SET(ArrayVar(4), 285)
    EVT_SET(ArrayVar(5), -26)
    EVT_SET(ArrayVar(6), NPC_ZiplineDummy1)
    EVT_SET(ArrayVar(7), 795)
    EVT_SET(ArrayVar(8), 940)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_RideZipline)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o170, 1, 0)
    EVT_EXEC(N(EVS_SyncZiplineDummyNPC1))
    EVT_MALLOC_ARRAY(9, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_SET(ArrayVar(0), EVT_PTR(N(Zipline_Endpoints2)))
    EVT_SET(ArrayVar(1), MODEL_o131)
    EVT_SET(ArrayVar(2), MODEL_o132)
    EVT_SET(ArrayVar(3), 974)
    EVT_SET(ArrayVar(4), 135)
    EVT_SET(ArrayVar(5), 74)
    EVT_SET(ArrayVar(6), NPC_ZiplineDummy2)
    EVT_SET(ArrayVar(7), 800)
    EVT_SET(ArrayVar(8), 930)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_RideZipline)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o119, 1, 0)
    EVT_EXEC(N(EVS_SyncZiplineDummyNPC2))
    EVT_RETURN
    EVT_END
};
