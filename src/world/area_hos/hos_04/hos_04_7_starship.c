#include "hos_04.h"

API_CALLABLE(N(ScreenOverlayFadeIn)) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    script->functionTemp[1] += 16;

    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_Starship_FlyingAway) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 45, 16, 4096)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -280, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -280, 0, 0)
    EVT_CALL(SetCamType, CAM_DEFAULT, 0, FALSE)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(550.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-688.0), EVT_FLOAT(50.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-544.0), EVT_FLOAT(50.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(2.0), EVT_FLOAT(-20.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_STARSHIP_ASCEND)
        EVT_CALL(MakeLerp, 0, 900, 45, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_g161, 0, LVar0, 0)
            EVT_ADD(LVar0, 520)
            EVT_CALL(SetPlayerPos, 315, LVar0, 5)
            EVT_CALL(SetNpcPos, NPC_PARTNER, 313, LVar0, 5)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(55)
    EVT_CALL(GotoMap, EVT_PTR("hos_20"), hos_20_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetStarshipPosRot) = {
    EVT_SET(LVar4, 0)
    EVT_SET(LVar5, 100)
    EVT_LABEL(10)
        EVT_SET(LVar3, LVar4)
        EVT_SET(LVar4, LVar5)
        EVT_SET(LVar5, LVar3)
        EVT_CALL(MakeLerp, LVar3, LVar4, 30, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_MULF(LVar2, EVT_FLOAT(0.1))
            EVT_ADDF(LVar2, MV_Starship_PosY)
            EVT_CALL(TranslateGroup, MODEL_g161, MV_Starship_PosX, LVar2, 0)
            EVT_CALL(RotateGroup, MODEL_g161, MV_Starship_PosZ, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

// flight1 (same as hos_20 entry 0, without motion lines)
EvtScript N(EVS_BetaStarship_Flight1) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -500, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -5000, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -5000, 50)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 5000, 50)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(MV_Starship_Yaw, 0)
    EVT_SET(MV_Starship_PosX, -5000)
    EVT_SET(MV_Starship_PosY, -525)
    EVT_SET(MV_Starship_PosZ, 180)
    EVT_EXEC(N(EVS_SetStarshipPosRot))
    EVT_WAIT(1)
    EVT_THREAD
        EVT_SET(LVar7, 45)
        EVT_LOOP(20)
            EVT_ADD(MV_Starship_PosX, LVar7)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_SET(LVar7, 50)
        EVT_LOOP(0)
            EVT_ADD(MV_Starship_PosX, LVar7)
            EVT_WAIT(1)
            EVT_CALL(GetModelCenter, MODEL_o480)
            EVT_ADD(LVar0, 25)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 10)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar3, LVar4, LVar5)
            EVT_IF_GT(LVar0, LVar3)
                EVT_IF_GT(LVar7, 45)
                    EVT_SUB(LVar7, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_GT(MV_Starship_PosX, 2000)
                EVT_SET(MV_Starship_Yaw, 1)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, -5000)
        EVT_LOOP(0)
            EVT_ADD(LVar0, 45)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LABEL(20)
    EVT_IF_EQ(MV_Starship_Yaw, 0)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_UNUSED_0000005D)
        EVT_CALL(GotoMap, EVT_PTR("hos_00"), hos_00_ENTRY_3)
    EVT_ELSE
        EVT_SET(LVar0, 2)
        EVT_LOOP(10)
            EVT_MUL(LVar0, 2)
            EVT_ADD(MV_Starship_PosX, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(20)
        EVT_CALL(GotoMap, EVT_PTR("kpa_60"), kpa_60_ENTRY_4)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

// flight2 (same as hos_20 entry 1, without motion lines)
EvtScript N(EVS_BetaStarship_Flight2) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -500, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -5000, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -5000, 50)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 5000, 50)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(MV_Starship_Yaw, 0)
    EVT_SET(MV_Starship_PosX, -4673)
    EVT_SET(MV_Starship_PosY, -525)
    EVT_SET(MV_Starship_PosZ, 180)
    EVT_EXEC(N(EVS_SetStarshipPosRot))
    EVT_WAIT(1)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_ADD(MV_Starship_PosX, 45)
            EVT_WAIT(1)
            EVT_CALL(GetModelCenter, MODEL_o480)
            EVT_ADD(LVar0, 25)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 10)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, -5000)
        EVT_LOOP(0)
            EVT_ADD(LVar0, 45)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_WAIT(1)
            EVT_IF_GT(LVar0, 0)
                EVT_SET(MV_Starship_Yaw, 1)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LABEL(20)
    EVT_IF_EQ(MV_Starship_Yaw, 0)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_SET(LVar0, 2)
    EVT_LOOP(10)
        EVT_MUL(LVar0, 2)
        EVT_ADD(MV_Starship_PosX, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(GotoMap, EVT_PTR("osr_03"), osr_03_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

// return flight (same as hos_20 entry 2, without motion lines)
EvtScript N(EVS_BetaStarship_Return) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -500, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 5000, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -5000, 50)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 5000, 50)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(MV_Starship_Yaw, 0)
    EVT_SET(MV_Starship_PosX, 5000)
    EVT_SET(MV_Starship_PosY, -525)
    EVT_SET(MV_Starship_PosZ, 0)
    EVT_EXEC(N(EVS_SetStarshipPosRot))
    EVT_WAIT(2)
    EVT_THREAD
        EVT_CALL(InterpPlayerYaw, 225, 0)
        EVT_SET(LVar7, -50)
        EVT_LOOP(0)
            EVT_ADD(MV_Starship_PosX, LVar7)
            EVT_CALL(GetModelCenter, MODEL_o480)
            EVT_ADD(LVar0, -25)
            EVT_ADD(LVar2, -5)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar2, 10)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar3, LVar4, LVar5)
            EVT_IF_LT(LVar0, LVar3)
                EVT_IF_LT(LVar7, -45)
                    EVT_ADD(LVar7, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 5000)
        EVT_LOOP(0)
            EVT_ADD(LVar0, -45)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_WAIT(1)
            EVT_IF_LT(LVar0, -1000)
                EVT_SET(MV_Starship_Yaw, 1)
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LABEL(20)
    EVT_IF_EQ(MV_Starship_Yaw, 0)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_SET(LVar0, -2)
    EVT_LOOP(10)
        EVT_MUL(LVar0, 2)
        EVT_ADD(MV_Starship_PosX, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GotoMap, EVT_PTR("hos_05"), hos_05_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
