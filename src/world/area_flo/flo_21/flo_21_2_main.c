#include "flo_21.h"
#include "sprite/player.h"

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_TrySpawningStarCard) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH6_GREW_MAGIC_BEANSTALK)
            EVT_SET(LVar0, FALSE)
            EVT_IF_EQ(MV_BossDefeated, FALSE)
                EVT_RETURN
            EVT_END_IF
            EVT_SET(GB_StoryProgress, STORY_CH6_DEFEATED_HUFF_N_PUFF)
        EVT_CASE_EQ(STORY_CH6_DEFEATED_HUFF_N_PUFF)
            EVT_SET(LVar0, TRUE)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_IF_EQ(LVar0, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 650, 205, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.6))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 650, 150, 0)
        EVT_SPIRIT_ADJUST_CAM(EVT_FLOAT(-5.5))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(N(StarSpiritEffectFunc2), 5, 180, 650, 170, 0, 650, 205, 0, 150, 120)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(1)
            EVT_CALL(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(N(StarSpiritEffectFunc1))
            EVT_CALL(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 650, 205, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(45)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(180)
            EVT_WAIT(115)
            EVT_CALL(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 650, 205, 0)
        EVT_END_THREAD
        EVT_CALL(N(StarSpiritEffectFunc4), 1)
        EVT_THREAD
            EVT_WAIT(80)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_END_THREAD
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar1)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 650, 120, 0)
        EVT_CALL(N(StarSpiritEffectFunc4), 2)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(N(StarSpiritEffectFunc5), 5, 650, 150, 0, 120)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc6))
        EVT_END_THREAD
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(N(StarSpiritEffectFunc4), 3)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GB_StoryProgress, STORY_CH6_STAR_SPIRIT_RESCUED)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_23"), kmr_23_ENTRY_5, TRANSITION_GET_STAR_CARD)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_flo_19_1) = EVT_EXIT_WALK(60, flo_21_ENTRY_0, "flo_19", flo_19_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_19_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_CLOUDY_CLIMB)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_Scene_HuffNPuffAmbush))
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_EXEC(N(EVS_SetupCloudPuffs))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o114, SURFACE_TYPE_CLOUD)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o115, SURFACE_TYPE_CLOUD)
    EVT_CALL(GetEntryID, LVar0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_EXEC(N(EVS_TrySpawningStarCard))
    EVT_RETURN
    EVT_END
};
