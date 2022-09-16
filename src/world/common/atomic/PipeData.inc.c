#include "common.h"
#include "Pipe.inc.h"

EvtScript N(Pipe_EnterVertical) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_SUB(LVar2, 40)
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(InterpPlayerYaw, LVar4, 0)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_CALL(func_802D286C, 0x100)
    EVT_CALL(func_802D2520, ANIM_Mario_StandStill, 5, 2, 1, 1, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_LOOP(40)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(3)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_THREAD
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar2, 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_2)), FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(func_802D2520, ANIM_Mario_StandStill, 0, 0, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_LABEL(0)
    EVT_CALL(N(Pipe_GetCurrentFloor))
    EVT_WAIT(1)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_EXEC(LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(Pipe_EnterHorizontal) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, LVarB, 0x7FFFFE00)
    EVT_CALL(GetEntryID, LVar0)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_SET(LVar5, LVar1)
    EVT_SET(LVar6, LVar2)
    EVT_SET(LVar7, LVar3)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(InterpPlayerYaw, LVar4, 0)
    EVT_IF_EQ(LVar4, 90)
        EVT_ADD(LVar5, 40)
    EVT_ELSE
        EVT_SUB(LVar5, 40)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, 0, LVar5, LVar6, LVar7)
    EVT_CALL(SetPanTarget, 0, LVar5, LVar6, LVar7)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVar0, 0)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(HidePlayerShadow, FALSE)
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 0x900)
    EVT_CALL(func_802D2520, ANIM_Mario_10002, 5, 3, 1, 1, 0)
    EVT_LOOP(40)
        EVT_CALL(N(Pipe_GetPointAheadOfPlayer), EVT_FLOAT(1.0))
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar2, 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(func_802D2520, ANIM_Mario_10002, 0, 0, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, 1, LVarB, 0x7FFFFE00)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_EXEC(LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(Pipe_ExitVertical) = {
    EVT_CALL(N(Pipe_AwaitDownInput))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetCurrentPartnerID, LVar1)
        EVT_IF_NE(LVar1, PARTNER_WATT)
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
    EVT_SET(LVar0, LVarA)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_CALL(PlayerMoveTo, LVar1, LVar3, 3)
    EVT_SET(LVar0, LVarA)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(SetPlayerFlagBits, PA_FLAGS_200000, TRUE)
    EVT_CALL(N(Pipe_GetCameraYaw))
    EVT_CALL(InterpPlayerYaw, LVar0, 0)
    EVT_WAIT(2)
    EVT_CALL(SetPlayerFlagBits, PA_FLAGS_200000, FALSE)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_LOOP(40)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 0x800)
    EVT_CALL(func_802D2520, ANIM_Mario_10002, 5, 2, 1, 1, 0)
    EVT_WAIT(25)
    EVT_EXEC_WAIT(LVarC)
    EVT_RETURN
    EVT_END
};

EvtScript N(Pipe_ExitHorizontal) = {
    EVT_CALL(IsPlayerOnValidFloor, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_EQ(LVar0, ACTION_STATE_SPIN)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetCurrentPartnerID, LVar1)
        EVT_IF_NE(LVar1, PARTNER_WATT)
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
    EVT_CALL(ModifyColliderFlags, 0, LVarB, 0x7FFFFE00)
    EVT_SET(LVar0, LVarA)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_SET(LVar5, LVar1)
    EVT_SET(LVar6, LVar2)
    EVT_ADD(LVar6, 2)
    EVT_SET(LVar7, LVar3)
    EVT_SET(LVar8, LVar4)
    EVT_ADD(LVar8, 180)
    EVT_IF_GE(LVar4, 360)
        EVT_SUB(LVar4, 360)
    EVT_END_IF
    EVT_CALL(InterpPlayerYaw, LVar8, 1)
    EVT_WAIT(1)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerPos, LVar0, LVar6, LVar7)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(func_802D286C, 0x800)
    EVT_CALL(func_802D2520, ANIM_Mario_StandStill, 5, 3, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(HidePlayerShadow, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(3)
        EVT_LOOP(40)
            EVT_CALL(N(Pipe_GetPointAheadOfPlayer), EVT_FLOAT(1.0))
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(25)
    EVT_EXEC_WAIT(LVarC)
    EVT_RETURN
    EVT_END
};
