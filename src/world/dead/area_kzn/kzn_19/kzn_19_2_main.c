#include "kzn_19.h"
#include "sprite/player.h"

#include "world/area_kzn/common/SmokeTexPanners.inc.c"

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

EvtScript N(EVS_TrySpawningStarCard) = {
    // determine if card should be spawned
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH5_KOLORADO_IN_TREASURE_ROOM)
            EVT_SET(LVar0, FALSE)
            EVT_IF_EQ(MV_BossDefeated, FALSE)
                EVT_RETURN
            EVT_END_IF
            EVT_SET(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
        EVT_CASE_EQ(STORY_CH5_DEFEATED_LAVA_PIRANHA)
            EVT_CALL(GetEntryID, LVar0)
            EVT_IF_EQ(LVar0, kzn_19_ENTRY_3)
                EVT_RETURN
            EVT_END_IF
            EVT_SET(LVar0, TRUE)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_IF_EQ(LVar0, 0)
        // card appearing scene
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 185, 110, -30)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.44))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 185, 55, -30)
        EVT_SPIRIT_ADJUST_CAM(10000)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(N(StarSpiritEffectFunc2), 4, 180, 304, 15, -54, 185, 110, -30, 55, 25)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(1)
            EVT_CALL(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(N(StarSpiritEffectFunc1))
            EVT_CALL(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 185, 110, -30)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(45)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(180)
            EVT_WAIT(115)
            EVT_CALL(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 185, 110, -30)
        EVT_END_THREAD
        EVT_CALL(N(StarSpiritEffectFunc4), 1)
        EVT_THREAD
            EVT_WAIT(80)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_END_THREAD
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar1)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 185, 25, -30)
        EVT_CALL(N(StarSpiritEffectFunc4), 2)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        // just make the card spawn
        EVT_CALL(N(StarSpiritEffectFunc5), 4, 185, 55, -30, 25)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc6))
        EVT_END_THREAD
        EVT_WAIT(1)
    EVT_END_IF
    // wait for pickup
    EVT_CALL(N(StarSpiritEffectFunc4), 3)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_23"), kmr_23_ENTRY_4, TRANSITION_GET_STAR_CARD)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_kzn_18_1) = EVT_EXIT_WALK(60, kzn_19_ENTRY_0, "kzn_18", kzn_18_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_18_2) = EVT_EXIT_WALK(60, kzn_19_ENTRY_1, "kzn_18", kzn_18_ENTRY_2);
EvtScript N(EVS_ExitWalk_kzn_20_0) = EVT_EXIT_WALK(60, kzn_19_ENTRY_2, "kzn_20", kzn_20_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_18_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_18_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_20_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartTexPanners_Lava) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_yougan1_1, TEX_PANNER_2)
    EVT_CALL(EnableTexPanning, MODEL_toro, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_poko, TRUE)
    EVT_CALL(SetTexPanner, MODEL_poko1, TEX_PANNER_E)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(  200,    0,  400, -100)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(  300, -500,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, LVar0, 0)
            EVT_ADD(LVar0, 0x8000)
            EVT_WAIT(6)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar0, 0)
            EVT_ADD(LVar0, 0x8000)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateLavaWaves) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 0, 180, 40, EASING_COS_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_SUBF(LVar0, EVT_FLOAT(0.9))
            EVT_CALL(ScaleModel, MODEL_yougan1_1, 1, LVar0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 180, 0, 40, EASING_SIN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_SUBF(LVar0, EVT_FLOAT(0.9))
            EVT_CALL(ScaleModel, MODEL_yougan1_1, 1, LVar0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_19)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kzn_19_ENTRY_3)
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(EscapeNPCs)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(BossNPCs)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kzn_19_ENTRY_3)
        EVT_THREAD
            EVT_EXEC_WAIT(N(EVS_Misstar_Escape))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_END_THREAD
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
        EVT_WAIT(1)
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_DEFEATED_LAVA_PIRANHA)
            EVT_CALL(EnableGroup, MODEL_ato, FALSE)
            EVT_CALL(EnableGroup, MODEL_naka, FALSE)
            EVT_CALL(EnableGroup, MODEL_g93, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ato, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hoshi_ato, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_EQ(STORY_CH5_DEFEATED_LAVA_PIRANHA)
            EVT_CALL(EnableGroup, MODEL_mae, FALSE)
            EVT_CALL(EnableGroup, MODEL_g93, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mae, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hoshi_ato, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_GT(STORY_CH5_DEFEATED_LAVA_PIRANHA)
            EVT_CALL(EnableGroup, MODEL_mae, FALSE)
            EVT_CALL(EnableGroup, MODEL_naka, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mae, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_StartTexPanners_Lava))
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeLeft))
    EVT_SET(LVar0, MODEL_kem2)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeRight))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_UpdateLavaWaves))
    EVT_EXEC(N(EVS_UpdateEruption))
    EVT_EXEC(N(EVS_TrySpawningStarCard))
    EVT_RETURN
    EVT_END
};
