#include "hos_20.h"

API_CALLABLE(N(CheckForSkipInput)) {
    script->varTable[8] = FALSE;
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        script->varTable[8] = TRUE;
    }
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_B) {
        script->varTable[8] = TRUE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimateStarship) = {
    EVT_THREAD
        EVT_SET(LVar4, 185)
        EVT_SET(LVar5, 50)
        EVT_LOOP(0)
            EVT_SET(LVar3, LVar4)
            EVT_SET(LVar4, LVar5)
            EVT_SET(LVar5, LVar3)
            EVT_CALL(MakeLerp, LVar3, LVar4, 30, EASING_COS_IN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_DIVF(LVar0, 10)
                EVT_CALL(SetCamPitch, CAM_DEFAULT, LVar0, EVT_FLOAT(-3.0))
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(LVar4, -20)
    EVT_SET(LVar5, 80)
    EVT_CALL(GetEntryID, LVar8)
    EVT_LOOP(0)
        EVT_SET(LVar3, LVar4)
        EVT_SET(LVar4, LVar5)
        EVT_SET(LVar5, LVar3)
        EVT_CALL(MakeLerp, LVar3, LVar4, 30, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_MULF(LVar2, EVT_FLOAT(0.1))
            EVT_CALL(TranslateGroup, MODEL_ry, MV_Starship_PosX, LVar2, 0)
            EVT_CALL(RotateGroup, MODEL_ry, MV_Starship_Yaw, 0, 1, 0)
            EVT_CALL(GetModelCenter, MODEL_ry3)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_NE(LVar8, hos_20_ENTRY_2)
                EVT_ADD(LVar0, -10)
            EVT_ELSE
                EVT_ADD(LVar0, 10)
            EVT_END_IF
            EVT_ADD(LVar2, 5)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Starship_Flight1) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(InterpPlayerYaw, 135, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-3.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(MV_Starship_PosX, -300)
    EVT_SET(MV_Starship_Yaw, 0)
    EVT_EXEC(N(EVS_AnimateStarship))
    EVT_WAIT(1)
    EVT_CALL(PlaySound, SOUND_STARSHIP_ENGINE_LOOP)
    EVT_IF_LT(GB_StoryProgress, STORY_UNUSED_0000005D)
        EVT_CALL(MakeLerp, -300, 0, 120, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_Starship_PosX, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(100)
        EVT_CALL(PlaySound, SOUND_STARSHIP_ENGINE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
        EVT_CALL(GotoMap, EVT_PTR("hos_00"), hos_00_ENTRY_3)
    EVT_ELSE
        EVT_THREAD
            EVT_CALL(MakeLerp, -300, 0, 120, EASING_QUADRATIC_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_SET(MV_Starship_PosX, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT(75)
            EVT_CALL(PlaySound, SOUND_STARSHIP_ENGINE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
            EVT_CALL(PlaySound, SOUND_STARSHIP_BOOST)
            EVT_CALL(MakeLerp, 0, 300, 60, EASING_CUBIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_SET(MV_Starship_PosX, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT(20)
        EVT_END_THREAD
        EVT_WAIT(60)
        EVT_LOOP(215)
            EVT_WAIT(1)
            EVT_CALL(N(CheckForSkipInput))
            EVT_IF_EQ(LVar8, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySound, SOUND_STARSHIP_ENGINE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
        EVT_CALL(GotoMap, EVT_PTR("kpa_60"), kpa_60_ENTRY_4)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Starship_Flight2) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(InterpPlayerYaw, 135, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-3.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(PlaySound, SOUND_STARSHIP_ENGINE_LOOP)
    EVT_SET(MV_Starship_PosX, 0)
    EVT_SET(MV_Starship_Yaw, 0)
    EVT_EXEC(N(EVS_AnimateStarship))
    EVT_WAIT(100)
    EVT_CALL(PlaySound, SOUND_STARSHIP_ENGINE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_CALL(PlaySound, SOUND_STARSHIP_BOOST)
    EVT_CALL(MakeLerp, 0, 300, 60, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(MV_Starship_PosX, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(GotoMap, EVT_PTR("osr_03"), osr_03_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Starship_Return) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(InterpPlayerYaw, 225, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 270)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-3.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(MV_Starship_PosX, 300)
    EVT_SET(MV_Starship_Yaw, 180)
    EVT_EXEC(N(EVS_AnimateStarship))
    EVT_WAIT(2)
    EVT_CALL(PlaySound, SOUND_STARSHIP_ENGINE_LOOP)
    EVT_THREAD
        EVT_CALL(MakeLerp, 300, 0, 120, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_Starship_PosX, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(75)
        EVT_CALL(PlaySound, SOUND_STARSHIP_ENGINE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
        EVT_CALL(PlaySound, SOUND_STARSHIP_BOOST)
        EVT_CALL(MakeLerp, 0, -300, 60, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_Starship_PosX, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(20)
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_LOOP(215)
        EVT_WAIT(1)
        EVT_CALL(N(CheckForSkipInput))
        EVT_IF_EQ(LVar8, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySound, SOUND_STARSHIP_ENGINE_LOOP | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_CALL(GotoMap, EVT_PTR("hos_05"), hos_05_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
