#include "pra_32.h"
#include "sprite/player.h"

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

API_CALLABLE(N(DisableFloorReflections)) {
    gOverrideFlags &= ~GLOBAL_OVERRIDES_ENABLE_FLOOR_REFLECTION;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SpawnStarCard) = {
    EVT_SET(LVar0, 0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 595, 185, 116)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.6))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 595, 130, 116)
        EVT_SPIRIT_ADJUST_CAM(10000)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(N(StarSpiritEffectFunc2), 6, 180, 590, 120, 116, 595, 185, 116, 130, 100)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(1)
            EVT_CALL(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(N(StarSpiritEffectFunc1))
            EVT_CALL(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 595, 185, 116)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(45)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(180)
            EVT_WAIT(115)
            EVT_CALL(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 595, 185, 116)
        EVT_END_THREAD
        EVT_CALL(N(StarSpiritEffectFunc4), 1)
        EVT_THREAD
            EVT_WAIT(80)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_END_THREAD
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar1)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 595, 100, 116)
        EVT_CALL(N(StarSpiritEffectFunc4), 2)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(N(StarSpiritEffectFunc5), 6, 595, 130, 116, 100)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc6))
        EVT_END_THREAD
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(N(StarSpiritEffectFunc4), 3)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GB_StoryProgress, STORY_CH7_STAR_SPIRIT_RESCUED)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_23"), kmr_23_ENTRY_6, TRANSITION_GET_STAR_CARD)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RespawnStarCard) = {
    EVT_SET(LVar0, 1)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 595, 185, 116)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.6))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 595, 130, 116)
        EVT_SPIRIT_ADJUST_CAM(10000)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(N(StarSpiritEffectFunc2), 6, 180, 590, 120, 116, 595, 185, 116, 130, 100)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(1)
            EVT_CALL(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(N(StarSpiritEffectFunc1))
            EVT_CALL(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            EVT_CALL(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 595, 185, 116)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(45)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(180)
            EVT_WAIT(115)
            EVT_CALL(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 595, 185, 116)
        EVT_END_THREAD
        EVT_CALL(N(StarSpiritEffectFunc4), 1)
        EVT_THREAD
            EVT_WAIT(80)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_END_THREAD
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar1)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 595, 100, 116)
        EVT_CALL(N(StarSpiritEffectFunc4), 2)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(N(StarSpiritEffectFunc5), 6, 595, 130, 116, 100)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc6))
        EVT_END_THREAD
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(N(StarSpiritEffectFunc4), 3)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GB_StoryProgress, STORY_CH7_STAR_SPIRIT_RESCUED)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_23"), kmr_23_ENTRY_6, TRANSITION_GET_STAR_CARD)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(DoorModelsL)[] = {
    MODEL_o948, -1
};

s32 N(DoorModelsR)[] = {
    MODEL_o946, -1
};

EvtScript N(EVS_ExitDoors_pra_40_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_32_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittw)
    EVT_SET(LVar2, EVT_PTR(N(DoorModelsL)))
    EVT_SET(LVar3, EVT_PTR(N(DoorModelsR)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_40"), pra_40_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_40_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_SET(LVar2, EVT_PTR(N(DoorModelsL)))
    EVT_SET(LVar3, EVT_PTR(N(DoorModelsR)))
    EVT_EXEC_WAIT(BaseEnterDoor)
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1309, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1293, SURFACE_TYPE_SNOW)
    EVT_PLAY_EFFECT(EFFECT_SNOWFALL, 0, 120)
    EVT_CALL(N(DisableFloorReflections))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
