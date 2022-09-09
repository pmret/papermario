#include "common.h"
#include "Pipe.inc.h"

EvtScript N(Pipe_EnterVertical) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(GetCurrentPartnerID, LocalVar(0))
    EVT_IF_NE(LocalVar(0), PARTNER_NONE)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
    EVT_END_IF
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_SUB(LocalVar(2), 40)
    EVT_CALL(SetPlayerPos, LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_CALL(InterpPlayerYaw, LocalVar(4), 0)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_CALL(func_802D286C, 0x100)
    EVT_CALL(func_802D2520, ANIM_STAND_STILL, 5, 2, 1, 1, 0)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_LOOP(40)
        EVT_ADD(LocalVar(1), 1)
        EVT_CALL(SetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(3)
    EVT_CALL(GetCurrentPartnerID, LocalVar(0))
    EVT_IF_NE(LocalVar(0), 0)
        EVT_THREAD
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_SUB(LocalVar(2), 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(func_802D2520, ANIM_STAND_STILL, 0, 0, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_LABEL(0)
    EVT_CALL(N(Pipe_GetCurrentFloor))
    EVT_WAIT(1)
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_EXEC(LocalVar(10))
    EVT_RETURN
    EVT_END
};

EvtScript N(Pipe_EnterHorizontal) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, LocalVar(11), 0x7FFFFE00)
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_SET(LocalVar(5), LocalVar(1))
    EVT_SET(LocalVar(6), LocalVar(2))
    EVT_SET(LocalVar(7), LocalVar(3))
    EVT_ADD(LocalVar(2), 2)
    EVT_CALL(SetPlayerPos, LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_CALL(InterpPlayerYaw, LocalVar(4), 0)
    EVT_IF_EQ(LocalVar(4), 90)
        EVT_ADD(LocalVar(5), 40)
    EVT_ELSE
        EVT_SUB(LocalVar(5), 40)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, 0, LocalVar(5), LocalVar(6), LocalVar(7))
    EVT_CALL(SetPanTarget, 0, LocalVar(5), LocalVar(6), LocalVar(7))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(GetCurrentPartnerID, LocalVar(0))
    EVT_IF_NE(LocalVar(0), PARTNER_NONE)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, LocalVar(0), 0)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(HidePlayerShadow, FALSE)
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 0x900)
    EVT_CALL(func_802D2520, ANIM_10002, 5, 3, 1, 1, 0)
    EVT_LOOP(40)
        EVT_CALL(N(Pipe_GetPointAheadOfPlayer), EVT_FIXED(1.0))
        EVT_CALL(SetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetCurrentPartnerID, LocalVar(0))
    EVT_IF_NE(LocalVar(0), PARTNER_NONE)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_SUB(LocalVar(2), 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(func_802D2520, ANIM_10002, 0, 0, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, 1, LocalVar(11), 0x7FFFFE00)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_EXEC(LocalVar(10))
    EVT_RETURN
    EVT_END
};

EvtScript N(Pipe_ExitVertical) = {
    EVT_CALL(N(Pipe_AwaitDownInput))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, LocalVar(0))
    EVT_IF_NE(LocalVar(0), 0)
        EVT_CALL(GetCurrentPartnerID, LocalVar(1))
        EVT_IF_NE(LocalVar(1), PARTNER_WATT)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(func_802D2B6C)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_EXEC_WAIT(N(Pipe_ScriptD))
    EVT_RETURN
    EVT_END
};

EvtScript N(Pipe_ScriptD) = {
    EVT_CALL(N(Pipe_SetAnimFlag))
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_SET(LocalVar(0), LocalVar(10))
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_CALL(PlayerMoveTo, LocalVar(1), LocalVar(3), 3)
    EVT_SET(LocalVar(0), LocalVar(10))
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_CALL(SetPlayerPos, LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_CALL(SetPlayerFlagBits, PLAYER_STATUS_ANIM_FLAGS_200000, TRUE)
    EVT_CALL(N(Pipe_GetCameraYaw))
    EVT_CALL(InterpPlayerYaw, LocalVar(0), 0)
    EVT_WAIT(2)
    EVT_CALL(SetPlayerFlagBits, PLAYER_STATUS_ANIM_FLAGS_200000, FALSE)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_THREAD
        EVT_WAIT(4)
        EVT_LOOP(40)
            EVT_SUB(LocalVar(1), 1)
            EVT_CALL(SetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 0x800)
    EVT_CALL(func_802D2520, ANIM_10002, 5, 2, 1, 1, 0)
    EVT_WAIT(25)
    EVT_EXEC_WAIT(LocalVar(12))
    EVT_RETURN
    EVT_END
};

EvtScript N(Pipe_ExitHorizontal) = {
    EVT_CALL(IsPlayerOnValidFloor, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionState, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), ACTION_STATE_SPIN)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, LocalVar(0))
    EVT_IF_NE(LocalVar(0), 0)
        EVT_CALL(GetCurrentPartnerID, LocalVar(1))
        EVT_IF_NE(LocalVar(1), PARTNER_WATT)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(func_802D2B6C)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(N(Pipe_SetAnimFlag))
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, LocalVar(11), 0x7FFFFE00)
    EVT_SET(LocalVar(0), LocalVar(10))
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_SET(LocalVar(5), LocalVar(1))
    EVT_SET(LocalVar(6), LocalVar(2))
    EVT_ADD(LocalVar(6), 2)
    EVT_SET(LocalVar(7), LocalVar(3))
    EVT_SET(LocalVar(8), LocalVar(4))
    EVT_ADD(LocalVar(8), 180)
    EVT_IF_GE(LocalVar(4), 360)
        EVT_SUB(LocalVar(4), 360)
    EVT_END_IF
    EVT_CALL(InterpPlayerYaw, LocalVar(8), 1)
    EVT_WAIT(1)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetPlayerPos, LocalVar(0), LocalVar(6), LocalVar(7))
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(func_802D286C, 0x800)
    EVT_CALL(func_802D2520, ANIM_STAND_STILL, 5, 3, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(HidePlayerShadow, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(3)
        EVT_LOOP(40)
            EVT_CALL(N(Pipe_GetPointAheadOfPlayer), EVT_FIXED(1.0))
            EVT_CALL(SetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(25)
    EVT_EXEC_WAIT(LocalVar(12))
    EVT_RETURN
    EVT_END
};
