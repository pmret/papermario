#include "omo_15.h"
#include "sprite/player.h"

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

EvtScript N(EVS_TrySpawningStarCard) = {
    // determine if card should be spawned
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH4_OPENED_GENERAL_GUY_ROOM)
            EVT_SET(LVar0, FALSE)
            EVT_SET(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        EVT_CASE_EQ(STORY_CH4_DEFEATED_GENERAL_GUY)
            EVT_SET(LVar0, TRUE)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_IF_EQ(LVar0, FALSE)
        // card appearing scene
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -100, 85, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -100, 30, 0)
        EVT_SPIRIT_ADJUST_CAM(10000)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(N(StarSpiritEffectFunc2), 3, 180, 215, 60, 0, -100, 85, 0, 30, 0)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(1)
            EVT_CALL(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(N(StarSpiritEffectFunc1))
            EVT_CALL(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, -100, 85, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(45)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(180)
            EVT_WAIT(115)
            EVT_CALL(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, -100, 85, 0)
        EVT_END_THREAD
        EVT_CALL(N(StarSpiritEffectFunc4), 1)
        EVT_THREAD
            EVT_WAIT(80)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_END_THREAD
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar1)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -100, 0, 0)
        EVT_CALL(N(StarSpiritEffectFunc4), 2)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        // just make the card spawn
        EVT_CALL(N(StarSpiritEffectFunc5), 3, -100, 30, 0, 0)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc6))
        EVT_END_THREAD
        EVT_WAIT(1)
    EVT_END_IF
    // wait for pickup
    EVT_CALL(N(StarSpiritEffectFunc4), 3)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GB_StoryProgress, STORY_CH4_STAR_SPIRIT_RESCUED)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_23"), kmr_23_ENTRY_3, TRANSITION_GET_STAR_CARD)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_omo_14_1) = EVT_EXIT_WALK(60, omo_15_ENTRY_0, "omo_14", omo_14_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_14_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        EVT_EXEC(N(EVS_TrySpawningStarCard))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
