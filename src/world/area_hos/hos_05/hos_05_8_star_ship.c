#include "hos_05.h"
#include "effects.h"
#include "model.h"

API_CALLABLE(N(SwingCameraPitchUpward)) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    if (isInitialCall) {
        script->functionTemp[0] = 40;
    }
    script->functionTemp[0]--;
    if (camera->curController != NULL) {
        camera->curController->viewPitch -= 1.0 - ((f32) (40 - script->functionTemp[0]) * 0.01);
    } else if (camera->prevController != NULL) {
        camera->prevController->viewPitch -= 1.0 - ((f32) (40 - script->functionTemp[0]) * 0.01);
    }

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_UpdatePassengers) = {
    EVT_LABEL(0)
        EVT_CALL(GetModelCenter, MODEL_o637)
        EVT_ADD(LVar0, -5)
        EVT_IF_EQ(MV_PlayerOnBoard, TRUE)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_ADD(LVar0, 10)
        EVT_IF_EQ(MV_PartnerOnBoard, TRUE)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Starship_Depart) = {
    EVT_CALL(GetPartnerInUse, LVar9)
    EVT_IF_NE(LVar9, PARTNER_NONE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_EXEC_GET_TID(N(EVS_UpdatePassengers), LVar9)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(GetModelCenter, MODEL_o637)
    EVT_ADD(LVar0, -5)
    EVT_CALL(SetPlayerJumpscale, 0)
    EVT_CALL(PlayerJump2, LVar0, LVar1, LVar2, 2)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_SET(MV_PlayerOnBoard, TRUE)
    EVT_CALL(InterpPlayerYaw, 0, 0)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_ADD(LVar0, 10)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(1.5))
    EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 12)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_SET(MV_PartnerOnBoard, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0188, 160, 40)
    EVT_CALL(ShowChoice, MSG_Choice_000C)
    EVT_CALL(CloseMessage)
    EVT_IF_EQ(LVar0, 1)
        // player chose "not ready to take off"
        EVT_KILL_THREAD(LVar9)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_SET(MV_PlayerOnBoard, FALSE)
        EVT_THREAD
            EVT_SET(MV_PartnerOnBoard, FALSE)
            EVT_CALL(PartnerIsFlying, LVar0)
            EVT_IF_EQ(LVar0, TRUE)
                EVT_WAIT(10)
                EVT_CALL(SetNpcJumpscale, NPC_PARTNER, 1)
                EVT_CALL(NpcJump0, NPC_PARTNER, 45, 162, 25, 10)
            EVT_END_IF
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
        EVT_CALL(SetPlayerJumpscale, 1)
        EVT_CALL(PlayerJump, 25, 162, 45, 10)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
        EVT_CALL(HidePlayerShadow, FALSE)
        EVT_WAIT(10)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(20)
    EVT_IF_LT(GB_StoryProgress, STORY_UNUSED_0000005D)
        EVT_CALL(SetMusicTrack, 0, SONG_STARSHIP_THEME, 0, 8)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_STARSHIP_THEME, 1, 8)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(N(SwingCameraPitchUpward))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPlayer, SOUND_17D, 0)
    EVT_SET(LVar2, MV_Starship_PosY)
    EVT_CALL(MakeLerp, 0, 1000, 100, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_ADD(LVar0, LVar2)
        EVT_SET(MV_Starship_PosY, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_IF_LT(GB_StoryProgress, STORY_UNUSED_0000005D)
        EVT_CALL(GotoMap, EVT_PTR("hos_04"), hos_04_ENTRY_2)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("hos_20"), hos_20_ENTRY_0)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterStarship) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 180, -5)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 180, -5)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(550.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-35.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(MV_PlayerOnBoard, TRUE)
    EVT_SET(MV_PartnerOnBoard, TRUE)
    EVT_EXEC_GET_TID(N(EVS_UpdatePassengers), LVar9)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(MakeLerp, -350, -70, 60, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_DIVF(LVar2, 10)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), LVar2)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPlayer, SOUND_17F, 0)
    EVT_CALL(MakeLerp, 750, -85, 90, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(MV_Starship_PosY, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVar9)
    EVT_SET(MV_PlayerOnBoard, FALSE)
    EVT_CALL(SetPlayerJumpscale, 1)
    EVT_CALL(PlayerJump, 25, 162, 45, 10)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_THREAD
        EVT_SET(MV_PartnerOnBoard, FALSE)
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CASE_EQ(PARTNER_BOW)
            EVT_CASE_EQ(PARTNER_WATT)
            EVT_CASE_EQ(PARTNER_LAKILESTER)
            EVT_CASE_DEFAULT
                EVT_WAIT(10)
                EVT_CALL(SetNpcJumpscale, NPC_PARTNER, 1)
                EVT_CALL(NpcJump0, NPC_PARTNER, 45, 162, 25, 10)
        EVT_END_SWITCH
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetMusicTrack, 0, SONG_STAR_SANCTUARY, 0, 8)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
