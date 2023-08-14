#include "trd_10.h"
#include "sprite/player.h"

extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_InitFakeBowser);
extern EvtScript N(EVS_SetupFakeBowser);
extern NpcGroupList N(DefaultNPCs);

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

API_CALLABLE(N(SetMapChangeFadeRate)) {
    set_map_change_fade_rate(10);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_BossDefeated) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
            EVT_SET(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
            EVT_CALL(GotoMap, EVT_PTR("trd_06"), trd_06_ENTRY_2)
            EVT_WAIT(100)
            EVT_RETURN
        EVT_CASE_EQ(STORY_CH1_DEFEATED_KOOPA_BROS)
            EVT_SET(LVar0, 1)
            EVT_CALL(GetEntryID, LVar1)
            EVT_IF_EQ(LVar1, trd_10_ENTRY_1)
                EVT_SET(LVar0, 0)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -135, 85, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.6))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -135, 30, 0)
        EVT_SPIRIT_ADJUST_CAM(10000)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(N(StarSpiritEffectFunc2), 0, 180, -135, 10, 0, -135, 85, 0, 30, 0)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(1)
            EVT_CALL(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(N(StarSpiritEffectFunc1))
            EVT_CALL(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, -135, 85, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(45)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(180)
            EVT_WAIT(115)
            EVT_CALL(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, -135, 85, 0)
        EVT_END_THREAD
        EVT_CALL(N(StarSpiritEffectFunc4), 1)
        EVT_THREAD
            EVT_WAIT(80)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_END_THREAD
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar1)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -135, 0, 0)
        EVT_CALL(N(StarSpiritEffectFunc4), 2)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(N(StarSpiritEffectFunc5), 0, -135, 30, 0, 0)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc6))
        EVT_END_THREAD
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(N(StarSpiritEffectFunc4), 3)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GB_StoryProgress, STORY_CH1_STAR_SPIRIT_RESCUED)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_23"), kmr_23_ENTRY_0, TRANSITION_GET_STAR_CARD)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(trd_10_ENTRY_0)
            EVT_SET(LVar2, MODEL_o192)
            EVT_SET(LVar3, MODEL_o191)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(trd_10_ENTRY_1)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SetNpcPos, NPC_PARTNER, -253, 0, 0)
            EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
            EVT_WAIT(3)
            EVT_CALL(EnablePartnerAI)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_trd_09_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, trd_10_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_ttw)
    EVT_SET(LVar2, MODEL_o192)
    EVT_SET(LVar3, MODEL_o191)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("trd_09"), trd_09_ENTRY_1)
    EVT_END_IF //@bug unmatched endif
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_09_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(N(SetMapChangeFadeRate))
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_InitFakeBowser))
    EVT_EXEC(N(EVS_SetupFakeBowser))
    EVT_IF_EQ(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        EVT_EXEC(N(EVS_BossDefeated))
    EVT_END_IF
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        EVT_EXEC(N(EVS_EnterMap))
    EVT_END_IF
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
