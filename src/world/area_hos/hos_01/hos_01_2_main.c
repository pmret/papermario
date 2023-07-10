#include "hos_01.h"

#include "../common/FallingStars.inc.c"

#include "world/common/todo/GetFloorCollider.inc.c"

//@bug malformed script is missing EVT_RETURN and EVT_END, only works because another EvtScript follows
EvtScript N(EVS_GotoMap_kmr_24_0) = {
    EVT_CALL(FadeOutMusic, 0, 1500)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_24"), kmr_24_ENTRY_0, TRANSITION_AFTER_SAVE_PROMPT)
    EVT_WAIT(100)
};

EvtScript N(EVS_ExitWalk_hos_00_1) = EVT_EXIT_WALK(60, hos_01_ENTRY_0, "hos_00", hos_00_ENTRY_1);

EvtScript N(EVS_ExitStarBeam) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
        EVT_RETURN
    EVT_END_IF
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
    EVT_EXEC_WAIT(N(EVS_AscendStarBeam))
    EVT_CALL(GotoMap, EVT_PTR("hos_02"), hos_02_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_hos_00_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, hos_01_ENTRY_1)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitStarBeam)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilin, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterStarBeam) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -30, 250, -160)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -30, 250, -160)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_SET(LVar2, 360)
    EVT_CALL(MakeLerp, 500, 250, 60, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPlayerPos, -30, LVar0, -160)
        EVT_CALL(SetNpcPos, NPC_PARTNER, -30, LVar0, -170)
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
        EVT_IF_LT(LVar2, 540)
            EVT_CALL(InterpPlayerYaw, LVar2, 0)
            EVT_CALL(SetNpcRotation, NPC_PARTNER, 0, LVar2, 0)
            EVT_ADD(LVar2, LVar0)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SET(LVar2, 180)
        EVT_SUB(LVar0, 5)
        EVT_IF_GT(LVar0, 20)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(SetNpcRotation, NPC_PARTNER, 0, 0, 0)
    EVT_CALL(N(func_80240AAC_A1132C), MV_StarBeamFXPtr)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetMusicTrack, 0, SONG_SHOOTING_STAR_SUMMIT, 0, 8)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_LABEL(20)
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_IF_NE(LVar0, COLLIDER_o234)
            EVT_WAIT(1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitStarBeam)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilin, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHOOTING_STAR_SUMMIT)
    EVT_CALL(SetSpriteShading, SHADING_HOS_01)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_THREAD
        EVT_LABEL(1)
        EVT_IF_NE(GB_StoryProgress, STORY_CH0_MET_STAR_SPIRITS)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_EXEC_WAIT(N(EVS_GotoMap_kmr_24_0))
    EVT_END_THREAD
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupModelFX))
    EVT_EXEC(N(EVS_Starfall_Random))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_01_ENTRY_0)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(hos_01_ENTRY_1)
            EVT_THREAD
                EVT_EXEC_WAIT(N(EVS_EnterStarBeam))
                EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_END_THREAD
    EVT_END_SWITCH
    EVT_IF_EQ(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_EXEC(N(EVS_Scene_StarWayOpened))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
