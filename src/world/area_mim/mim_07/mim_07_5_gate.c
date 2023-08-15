#include "mim_07.h"

EvtScript N(EVS_SetGateCameraZones) = {
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(SetZoneEnabled, ZONE_north, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_west, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_south, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_east, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_higashi, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_nishi, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_minami, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_kita, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_stage, FALSE)
            EVT_SET(LVar1, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetZoneEnabled, ZONE_north, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_west, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_south, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_east, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_higashi, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_nishi, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_minami, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_kita, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_stage, TRUE)
            EVT_SET(LVar1, 1)
        EVT_CASE_EQ(2)
            EVT_CALL(SetZoneEnabled, ZONE_north, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_west, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_south, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_east, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_higashi, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_nishi, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_minami, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_kita, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_stage, FALSE)
            EVT_SET(LVar1, 2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InitializeGates) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_monn, MODEL_n1)
    EVT_CALL(RotateGroup, MODEL_monn, LVar2, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_monn)
    EVT_CALL(ParentColliderToModel, COLLIDER_mons, MODEL_s1)
    EVT_CALL(RotateGroup, MODEL_mons, LVar2, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_mons)
    EVT_CALL(ParentColliderToModel, COLLIDER_mone, MODEL_e1)
    EVT_CALL(RotateGroup, MODEL_mone, LVar2, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_mone)
    EVT_CALL(ParentColliderToModel, COLLIDER_monw, MODEL_w1)
    EVT_CALL(RotateGroup, MODEL_monw, LVar2, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_monw)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ResetGates) = {
    EVT_CALL(RotateGroup, MODEL_monn, 0, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_monn)
    EVT_CALL(RotateGroup, MODEL_mons, 0, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_mons)
    EVT_CALL(RotateGroup, MODEL_mone, 0, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_mone)
    EVT_CALL(RotateGroup, MODEL_monw, 0, 0, 1, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_monw)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate) = {
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, LVar9, SOUND_FOREST_GATE_OPEN, SOUND_SPACE_DEFAULT)
        EVT_WAIT(19)
        EVT_CALL(PlaySoundAtCollider, LVar9, SOUND_FOREST_GATE_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_SWITCH(AB_MIM_1)
        EVT_CASE_EQ(0)
            EVT_THREAD
                EVT_CALL(MakeLerp, 10, 90, 10, EASING_QUADRATIC_IN)
                EVT_LABEL(10)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
                EVT_CALL(UpdateColliderTransform, LVar9)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(10)
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT(15)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, LVar7)
                EVT_ADD(LVar2, LVar8)
                EVT_CALL(PlayerMoveTo, LVar0, LVar2, 15)
            EVT_END_THREAD
            EVT_SET(LVar1, 1)
            EVT_EXEC(N(EVS_SetGateCameraZones))
            EVT_CALL(MakeLerp, 90, 360, 30, EASING_LINEAR)
            EVT_LABEL(20)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
            EVT_CALL(UpdateColliderTransform, LVar9)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(20)
            EVT_END_IF
            EVT_EXEC(N(EVS_ResetGates))
            EVT_SET(AB_MIM_1, 1)
            EVT_SET(GF_MIM_ChoosingPath, TRUE)
        EVT_CASE_EQ(1)
            EVT_THREAD
                EVT_CALL(MakeLerp, 360, 270, 10, EASING_QUADRATIC_IN)
                EVT_LABEL(30)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
                EVT_CALL(UpdateColliderTransform, LVar9)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(30)
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT(15)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, LVar7)
                EVT_SUB(LVar2, LVar8)
                EVT_CALL(PlayerMoveTo, LVar0, LVar2, 15)
            EVT_END_THREAD
            EVT_SET(LVar1, 2)
            EVT_EXEC(N(EVS_SetGateCameraZones))
            EVT_CALL(MakeLerp, 270, -10, 30, EASING_LINEAR)
            EVT_LABEL(40)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
            EVT_CALL(UpdateColliderTransform, LVar9)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(40)
            EVT_END_IF
            EVT_SET(AB_MIM_1, 2)
        EVT_CASE_EQ(2)
            EVT_THREAD
                EVT_CALL(MakeLerp, -10, 90, 10, EASING_QUADRATIC_IN)
                EVT_LABEL(50)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
                EVT_CALL(UpdateColliderTransform, LVar9)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(50)
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT(15)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, LVar7)
                EVT_ADD(LVar2, LVar8)
                EVT_CALL(PlayerMoveTo, LVar0, LVar2, 15)
            EVT_END_THREAD
            EVT_SET(LVar1, 1)
            EVT_EXEC(N(EVS_SetGateCameraZones))
            EVT_CALL(MakeLerp, 90, 360, 30, EASING_LINEAR)
            EVT_LABEL(60)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
            EVT_CALL(UpdateColliderTransform, LVar9)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(60)
            EVT_END_IF
            EVT_EXEC(N(EVS_ResetGates))
            EVT_SET(AB_MIM_1, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_North) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, 0)
    EVT_SET(LVar8, 70)
    EVT_SET(LVar9, COLLIDER_monn)
    EVT_SET(LVarA, MODEL_monn)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_South) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, 0)
    EVT_SET(LVar8, -70)
    EVT_SET(LVar9, COLLIDER_mons)
    EVT_SET(LVarA, MODEL_mons)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_East) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, -70)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, COLLIDER_mone)
    EVT_SET(LVarA, MODEL_mone)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
        EVT_IF_EQ(GF_MIM10_Defeated_JrTroopa, FALSE)
            EVT_IF_EQ(GF_MIM10_JrTroopaFreakout, FALSE)
                EVT_SET(GF_MIM10_JrTroopaFreakout, TRUE)
                EVT_CALL(ShowMessageAtScreenPos, MSG_CH3_0017, 160, 40)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_West) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, 70)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, COLLIDER_monw)
    EVT_SET(LVarA, MODEL_monw)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupGates) = {
    EVT_IF_EQ(GF_MIM_ChoosingPath, FALSE)
        EVT_SET(GF_MIM_ChoosingPath, TRUE)
        EVT_SET(AB_MIM_1, 2)
        EVT_SET(LVar1, 2)
        EVT_SET(LVar2, -10)
    EVT_ELSE
        EVT_SET(GF_MIM_ChoosingPath, FALSE)
        EVT_SET(AB_MIM_1, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 10)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetGateCameraZones))
    EVT_EXEC(N(EVS_InitializeGates))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseGate_North)), TRIGGER_WALL_PRESS_A, COLLIDER_monn, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseGate_South)), TRIGGER_WALL_PRESS_A, COLLIDER_mons, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseGate_West)),  TRIGGER_WALL_PRESS_A, COLLIDER_monw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseGate_East)),  TRIGGER_WALL_PRESS_A, COLLIDER_mone, 1, 0)
    EVT_RETURN
    EVT_END
};
