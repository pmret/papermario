#include "arn_07.h"
#include "sprite/player.h"

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

s32 N(KeyList)[] = {
    ITEM_MYSTICAL_KEY,
    ITEM_NONE
};

EvtScript N(EVS_SpawnStarCard) = {
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_SET(LVar0, 0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 145, 65, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.6))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 145, 30, 0)
        EVT_SPIRIT_ADJUST_CAM(10000)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(N(StarSpiritEffectFunc2), 2, 50, 100, 31, -6, 145, 65, 0, 30, 0)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(1)
            EVT_CALL(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(N(StarSpiritEffectFunc1))
            EVT_CALL(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 145, 65, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(12)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(50)
            EVT_WAIT(115)
            EVT_CALL(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 145, 65, 0)
        EVT_END_THREAD
        EVT_CALL(N(StarSpiritEffectFunc4), 1)
        EVT_THREAD
            EVT_WAIT(80)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_END_THREAD
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar1)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 145, 0, 0)
        EVT_CALL(N(StarSpiritEffectFunc4), 2)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(N(StarSpiritEffectFunc5), 2, 145, 30, 0, 0)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc6))
        EVT_END_THREAD
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(N(StarSpiritEffectFunc4), 3)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_23"), kmr_23_ENTRY_2, TRANSITION_GET_STAR_CARD)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RespawnStarCard) = {
    EVT_SET(LVar0, 1)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 145, 65, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.6))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 145, 30, 0)
        EVT_SPIRIT_ADJUST_CAM(10000)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(N(StarSpiritEffectFunc2), 2, 50, 100, 31, -6, 145, 65, 0, 30, 0)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(1)
            EVT_CALL(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(N(StarSpiritEffectFunc1))
            EVT_CALL(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 145, 65, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(12)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(50)
            EVT_WAIT(115)
            EVT_CALL(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 145, 65, 0)
        EVT_END_THREAD
        EVT_CALL(N(StarSpiritEffectFunc4), 1)
        EVT_THREAD
            EVT_WAIT(80)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_END_THREAD
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar1)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 145, 0, 0)
        EVT_CALL(N(StarSpiritEffectFunc4), 2)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(N(StarSpiritEffectFunc5), 2, 145, 30, 0, 0)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc6))
        EVT_END_THREAD
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(N(StarSpiritEffectFunc4), 3)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_23"), kmr_23_ENTRY_2, TRANSITION_GET_STAR_CARD)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_arn_08_0) = EVT_EXIT_SINGLE_DOOR(arn_07_ENTRY_0, "arn_08", arn_08_ENTRY_0,
    COLLIDER_tt3, MODEL_o39, DOOR_SWING_OUT);
EvtScript N(EVS_ExitWalk_arn_03_0) = EVT_EXIT_WALK(60, arn_07_ENTRY_1, "arn_03", arn_03_ENTRY_0);
EvtScript N(EVS_ExitWalk_mim_12_1) = EVT_EXIT_WALK(60, arn_07_ENTRY_2, "mim_12", mim_12_ENTRY_1);

EvtScript N(EVS_Scene_TubbaReunion) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerPos, -28, 0, -333)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -28, 0, -333)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamType, CAM_DEFAULT, 0, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(25.0), EVT_FLOAT(-4.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1100)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 500, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -500)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 5, 0, -147)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(RotateModel, MODEL_o39, 80, 0, -1, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcJumpscale, NPC_TubbasHeart, EVT_FLOAT(2.5))
    EVT_CALL(NpcJump0, NPC_TubbasHeart, 0, 20, -120, 8 * DT)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_TubbasHeart, 0, 10, -60, 12 * DT)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_TubbasHeart, 0, 0, 0, 12 * DT)
    EVT_WAIT(1)
    EVT_CALL(SetNpcVar, NPC_TubbasHeart, 0, 0)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_TubbasHeart, 0, 0, 0, 10 * DT)
            EVT_WAIT(1)
            EVT_CALL(GetNpcVar, NPC_TubbasHeart, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcVar, NPC_TubbasHeart, 0, 2)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 80, 0, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o39, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_tt3, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(NpcFaceNpc, NPC_TubbasHeart, NPC_Tubba, 0)
    EVT_CALL(SpeakToPlayer, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0A, ANIM_TubbasHeart_Anim01, 5, MSG_CH3_00C7)
    EVT_CALL(SetNpcVar, NPC_TubbasHeart, 0, 1)
    EVT_LOOP(0)
        EVT_CALL(GetNpcVar, NPC_TubbasHeart, 0, LVar0)
        EVT_IF_EQ(LVar0, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_TubbasHeart, 75, 0, 10, 12)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_TubbasHeart, 150, 0, 20, 12)
    EVT_WAIT(1)
    EVT_THREAD
        EVT_WAIT(4 * DT)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(2.0), EVT_FLOAT(-9.0))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 700)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, 500, 0)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -500)
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 65, 0, -137)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim22)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_TubbasHeart, 298, 56, 31, 18)
    EVT_CALL(SetNpcPos, NPC_TubbasHeart, NPC_DISPOSE_LOCATION)
    EVT_CALL(EnableNpcShadow, NPC_TubbasHeart, FALSE)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim23)
        EVT_WAIT(20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Tubba, ANIM_WorldTubba_Anim06)
    EVT_END_THREAD
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_tt3, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o39, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 236, 0, -46)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(8.0), EVT_FLOAT(-9.0))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 250, 0, -46)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetPlayerPos, 0, 20, -195)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 0, 20, -195)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PlayerMoveTo, 0, 0, 45 * DT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_THREAD
        EVT_CALL(MakeLerp, 80, 0, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o39, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_tt3, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, 200, 0, 35 * DT)
    EVT_WAIT(5 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Tubba, ANIM_WorldTubba_Anim10, ANIM_WorldTubba_Anim06, 0, MSG_CH3_00C8)
    EVT_CALL(SetNpcVar, NPC_Tubba, 0, 1)
    EVT_WAIT(30 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_arn_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mim_12_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_UNLOCKED_WINDY_MILL)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockDoor)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(KeyList)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_arn_08_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt3, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(arn_07_ENTRY_0)
            EVT_IF_EQ(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
                EVT_EXEC_WAIT(N(EVS_Scene_TubbaReunion))
                EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_ELSE
                EVT_SET(LVar2, MODEL_o39)
                EVT_SET(LVar3, DOOR_SWING_OUT)
                EVT_EXEC_WAIT(EnterSingleDoor)
                EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_END_IF
        EVT_CASE_EQ(arn_07_ENTRY_1)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(arn_07_ENTRY_2)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(arn_07_ENTRY_3)
            EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_GUSTY_GULCH)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_SET(GF_MAP_GustyGulch, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(BossNPCs)))
        EVT_CASE_EQ(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(SpiritNPCs)))
        EVT_CASE_DEFAULT
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_EQ(GB_StoryProgress, STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        EVT_EXEC(N(EVS_RespawnStarCard))
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, arn_07_ENTRY_3)
        EVT_WAIT(65)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupWindmill))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.3))
    EVT_RETURN
    EVT_END
};
