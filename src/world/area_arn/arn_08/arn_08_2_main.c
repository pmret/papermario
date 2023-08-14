#include "arn_08.h"

EvtScript N(EVS_ExitDoor_arn_07_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ClearDefeatedEnemies)
    EVT_SET(LVar0, arn_08_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tts)
    EVT_SET(LVar2, MODEL_doa)
    EVT_SET(LVar4, MODEL_o37)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSplitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("arn_07"), arn_07_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_arn_07_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(arn_08_ENTRY_0)
            EVT_SET(LVar4, MODEL_o37)
            EVT_SET(LVar2, MODEL_doa)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSplitSingleDoor)
            EVT_SET(AF_ARN_01, FALSE)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(arn_08_ENTRY_1)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_IF_EQ(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WELL)
                EVT_CALL(SetPlayerPos, 1000, 1000, 0)
                EVT_CALL(SetNpcPos, NPC_PARTNER, 1000, 1000, 0)
                EVT_CALL(RotateModel, MODEL_doa, 80, 0, -1, 0)
                EVT_CALL(RotateModel, MODEL_o37, 80, 0, -1, 0)
                EVT_CALL(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim06)
                EVT_CALL(SetNpcJumpscale, NPC_TubbasHeart, EVT_FLOAT(2.5))
                EVT_CALL(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_TubbasHeart, -50, 0, 50, 10 * DT)
                EVT_CALL(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim07)
                EVT_WAIT(1)
                EVT_CALL(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim06)
                EVT_CALL(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_TubbasHeart, -110, 0, 110, 10 * DT)
                EVT_CALL(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim07)
                EVT_WAIT(1)
                EVT_CALL(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim06)
                EVT_CALL(PlaySoundAtNpc, NPC_TubbasHeart, SOUND_TUBBA_HEART_JUMP, SOUND_SPACE_DEFAULT)
                EVT_CALL(NpcJump0, NPC_TubbasHeart, -180, 0, 180, 10 * DT)
                EVT_CALL(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim07)
                EVT_WAIT(1)
                EVT_CALL(MakeLerp, 80, 0, 10, EASING_LINEAR)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(RotateModel, MODEL_doa, LVar0, 0, -1, 0)
                    EVT_CALL(RotateModel, MODEL_o37, LVar0, 0, -1, 0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
                EVT_CALL(PlaySoundAtCollider, COLLIDER_tts, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
                EVT_WAIT(20 * DT)
                EVT_CALL(SetPlayerPos, 0, 0, 0)
                EVT_CALL(SetNpcPos, NPC_PARTNER, 0, 0, 0)
                EVT_SET(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
            EVT_END_IF
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.0))
            EVT_CALL(PlayerJump, -10, 0, 75, 18)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_WINDY_MILL)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_SET(GF_MAP_WindyMill, TRUE)
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_FRYING_PAN_STOLEN)
        EVT_SET(GF_ARN10_Defeated_Goomba, FALSE)
        EVT_SET(GF_ARN12_Defeated_Goomba, FALSE)
        EVT_SET(GF_ARN13_Defeated_Goomba, FALSE)
    EVT_END_IF
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_AnimateGears))
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_NE(LVar0, DEMO_STATE_NONE)
        EVT_EXEC_WAIT(N(EVS_PlayDemoScene))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_SetupHole))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
