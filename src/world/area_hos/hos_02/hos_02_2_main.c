#include "hos_02.h"

EvtScript N(EVS_ExitStarBeam) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(20)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(IsPlayerOnValidFloor, LVar0)
            EVT_IF_EQ(LVar0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_EXEC_WAIT(N(EVS_DescendStarBeam))
    EVT_CALL(GotoMap, EVT_PTR("hos_01"), hos_01_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_hos_03_0) = EVT_EXIT_WALK(60, hos_02_ENTRY_1, "hos_03", hos_03_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, hos_02_ENTRY_0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitStarBeam)), TRIGGER_FLOOR_TOUCH, COLLIDER_deiliw, 1, 0)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_hos_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterStarBeam) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -1105, -171, 225)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -1105, -171, 225)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_SET(LVar2, 360)
    EVT_CALL(MakeLerp, -400, -171, 60, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPlayerPos, -1105, LVar0, 225)
        EVT_CALL(SetNpcPos, NPC_PARTNER, -1105, LVar0, 215)
        EVT_ADD(LVar2, 40)
        EVT_CALL(InterpPlayerYaw, LVar2, 0)
        EVT_CALL(SetNpcRotation, NPC_PARTNER, 0, LVar2, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LVar0, LVar2)
    EVT_SUB(LVar0, 360)
    EVT_SUB(LVar2, LVar0)
    EVT_SET(LVar0, 40)
    EVT_LABEL(10)
        EVT_IF_LT(LVar2, 450)
            EVT_CALL(InterpPlayerYaw, LVar2, 0)
            EVT_CALL(SetNpcRotation, NPC_PARTNER, 0, LVar2, 0)
            EVT_ADD(LVar2, LVar0)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SET(LVar2, 90)
        EVT_SUB(LVar0, 5)
        EVT_IF_GT(LVar0, 20)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(SetNpcRotation, NPC_PARTNER, 0, 0, 0)
    EVT_CALL(N(func_80240EF4_A17114), MV_StarBeamEffect)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetMusicTrack, 0, SONG_STAR_WAY_OPENS, 3, 8)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(AwaitPlayerLeave, -1105, 225, 40)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitStarBeam)), TRIGGER_FLOOR_TOUCH, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_STAR_WAY)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(GF_MAP_StarWay, TRUE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_02_ENTRY_0)
            EVT_THREAD
                EVT_EXEC_WAIT(N(EVS_EnterStarBeam))
                EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_END_THREAD
        EVT_CASE_EQ(hos_02_ENTRY_1)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_SetupModelFX))
    EVT_EXEC(N(EVS_SetupUnused))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
