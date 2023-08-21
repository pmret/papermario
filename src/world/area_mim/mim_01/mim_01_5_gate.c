#include "mim_01.h"

EvtScript N(EVS_SetGateCameraZones) = {
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(SetZoneEnabled, ZONE_north, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_west, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_south, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_east, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_higashi, FALSE)
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
            EVT_CALL(SetZoneEnabled, ZONE_west, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_south, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_east, FALSE)
            EVT_CALL(SetZoneEnabled, ZONE_higashi, TRUE)
            EVT_CALL(SetZoneEnabled, ZONE_nishi, FALSE)
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
    EVT_CALL(RotateGroup, MODEL_monw, 10, 0, 1, 0)
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

EvtScript N(EVS_PlayGateSounds) = {
    EVT_CALL(PlaySoundAtCollider, LVar9, SOUND_FOREST_GATE_OPEN, SOUND_SPACE_DEFAULT)
    EVT_WAIT(19)
    EVT_CALL(PlaySoundAtCollider, LVar9, SOUND_FOREST_GATE_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate) = {
    EVT_EXEC(N(EVS_PlayGateSounds))
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
    EVT_SET(LVar9, 26)
    EVT_SET(LVarA, 155)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_South) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, 0)
    EVT_SET(LVar8, -70)
    EVT_SET(LVar9, 30)
    EVT_SET(LVarA, 161)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_East) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar7, -70)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, 28)
    EVT_SET(LVarA, 158)
    EVT_EXEC_WAIT(N(EVS_UseGate))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate_West) = {
    EVT_SET(LVar9, 32)
    EVT_EXEC(N(EVS_PlayGateSounds))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_NE(AB_MIM_1, 1)
        EVT_THREAD
            EVT_CALL(MakeLerp, 10, 90, 10, EASING_QUADRATIC_IN)
            EVT_LABEL(10)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_monw, LVar0, 0, 1, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_monw)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_END_THREAD
        EVT_WAIT(15)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 70)
            EVT_CALL(PlayerMoveTo, LVar0, LVar2, 15)
        EVT_END_THREAD
        EVT_SET(LVar1, 1)
        EVT_EXEC(N(EVS_SetGateCameraZones))
        EVT_CALL(MakeLerp, 90, 360, 30, EASING_LINEAR)
        EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_monw, LVar0, 0, 1, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_monw)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_EXEC(N(EVS_ResetGates))
        EVT_SET(AB_MIM_1, 1)
        EVT_SET(GF_MIM_ChoosingPath, TRUE)
    EVT_ELSE
        EVT_THREAD
            EVT_CALL(MakeLerp, 360, 270, 10, EASING_QUADRATIC_IN)
            EVT_LABEL(30)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_monw, LVar0, 0, 1, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_monw)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(30)
            EVT_END_IF
        EVT_END_THREAD
        EVT_WAIT(15)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 70)
            EVT_CALL(PlayerMoveTo, LVar0, LVar2, 15)
        EVT_END_THREAD
        EVT_SET(LVar1, 2)
        EVT_EXEC(N(EVS_SetGateCameraZones))
        EVT_CALL(MakeLerp, 270, 10, 30, EASING_LINEAR)
        EVT_LABEL(40)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_monw, LVar0, 0, 1, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_monw)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(40)
        EVT_END_IF
        EVT_SET(AB_MIM_1, 0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

#include "../common/SetupGates.inc.c"
