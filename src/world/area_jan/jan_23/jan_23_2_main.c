#include "jan_23.h"

EvtScript N(EVS_ExitWalk_jan_19_1) = EVT_EXIT_WALK(60, jan_23_ENTRY_0, "jan_19", jan_19_ENTRY_1);

EvtScript N(EVS_ExitFall_jan_16_4) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar1, 110)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SETF(MV_Unk_05, 0)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, 8)
        EVT_THREAD
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
                EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(3.0))
                EVT_CALL(NpcJump0, NPC_PARTNER, LVar2, LVar3, LVar4, 15)
            EVT_ELSE
                EVT_WAIT(10)
            EVT_END_IF
            EVT_CALL(GetNpcPos, NPC_PARTNER, LVar2, LVar3, LVar4)
            EVT_CALL(MakeLerp, LVar3, -500, 15, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_ADD(LVar4, 2)
                EVT_CALL(SetNpcPos, NPC_PARTNER, LVar2, LVar0, LVar4)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(GetPlayerActionState, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(ACTION_STATE_SPIN_JUMP)
                    EVT_GOTO(11)
                EVT_CASE_EQ(ACTION_STATE_TORNADO_JUMP)
                    EVT_LABEL(11)
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, 250, 100)
                    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, -100, LVar2)
                    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
                    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                    EVT_SET(MV_Unk_05, -1)
                EVT_CASE_DEFAULT
                    EVT_WAIT(10)
            EVT_END_SWITCH
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
            EVT_CALL(MakeLerp, LVar3, -500, 15, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_ADD(LVar4, 2)
                EVT_CALL(SetPlayerPos, LVar2, LVar0, LVar4)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
        EVT_END_THREAD
    EVT_END_IF
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar1, -100)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_IF_EQ(MV_Unk_05, 0)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, 250, 100)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GotoMap, EVT_PTR("jan_16"), jan_16_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_19_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_EXEC(N(EVS_ExitFall_jan_16_4))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
