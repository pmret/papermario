#include "pra_32.h"
#include "sprite/player.h"

#define STAR_SPIRIT_DATA_VAR MV_Unk_01
#include "world/common/todo/StarSpiritEffectFunc.inc.c"

API_CALLABLE(N(DisableFloorReflections)) {
    gOverrideFlags &= ~GLOBAL_OVERRIDES_ENABLE_FLOOR_REFLECTION;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SpawnStarCard) = {
    Set(LVar0, 0)
    IfEq(LVar0, 0)
        Call(DisablePlayerInput, true)
        Call(UseSettingsFrom, CAM_DEFAULT, 595, 185, 116)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.6))
        Call(SetPanTarget, CAM_DEFAULT, 595, 130, 116)
        EVT_SPIRIT_ADJUST_CAM(10000)
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(N(StarSpiritEffectFunc2), 6, 180, 590, 120, 116, 595, 185, 116, 130, 100)
        Thread
            Call(N(StarSpiritEffectFunc3))
        EndThread
        Thread
            Wait(1)
            Call(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            Call(N(StarSpiritEffectFunc1))
            Call(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            Call(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 595, 185, 116)
        EndThread
        Thread
            Wait(45)
            Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EndThread
        Thread
            Wait(180)
            Wait(115)
            Call(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 595, 185, 116)
        EndThread
        Call(N(StarSpiritEffectFunc4), 1)
        Thread
            Wait(80)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Add(LVar1, 100)
        Call(SetCamDistance, CAM_DEFAULT, LVar1)
        Call(SetPanTarget, CAM_DEFAULT, 595, 100, 116)
        Call(N(StarSpiritEffectFunc4), 2)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
        Call(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, false)
        Call(DisablePlayerInput, false)
    Else
        Call(N(StarSpiritEffectFunc5), 6, 595, 130, 116, 100)
        Thread
            Call(N(StarSpiritEffectFunc6))
        EndThread
        Wait(1)
    EndIf
    Call(N(StarSpiritEffectFunc4), 3)
    Call(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    Call(DisablePlayerInput, true)
    Set(GB_StoryProgress, STORY_CH7_STAR_SPIRIT_RESCUED)
    Call(GotoMapSpecial, Ref("kmr_23"), kmr_23_ENTRY_6, TRANSITION_GET_STAR_CARD)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_RespawnStarCard) = {
    Set(LVar0, 1)
    IfEq(LVar0, 0)
        Call(DisablePlayerInput, true)
        Call(UseSettingsFrom, CAM_DEFAULT, 595, 185, 116)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.6))
        Call(SetPanTarget, CAM_DEFAULT, 595, 130, 116)
        EVT_SPIRIT_ADJUST_CAM(10000)
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(N(StarSpiritEffectFunc2), 6, 180, 590, 120, 116, 595, 185, 116, 130, 100)
        Thread
            Call(N(StarSpiritEffectFunc3))
        EndThread
        Thread
            Wait(1)
            Call(PlaySound, SOUND_LOOP_STAR_ORB_RISING)
            Call(N(StarSpiritEffectFunc1))
            Call(StopSound, SOUND_LOOP_STAR_ORB_RISING)
            Call(PlaySoundAt, SOUND_STAR_ORB_BURST, SOUND_SPACE_DEFAULT, 595, 185, 116)
        EndThread
        Thread
            Wait(45)
            Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EndThread
        Thread
            Wait(180)
            Wait(115)
            Call(PlaySoundAt, SOUND_STAR_CARD_APPEARS, SOUND_SPACE_DEFAULT, 595, 185, 116)
        EndThread
        Call(N(StarSpiritEffectFunc4), 1)
        Thread
            Wait(80)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        EndThread
        Add(LVar1, 100)
        Call(SetCamDistance, CAM_DEFAULT, LVar1)
        Call(SetPanTarget, CAM_DEFAULT, 595, 100, 116)
        Call(N(StarSpiritEffectFunc4), 2)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
        Call(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, false)
        Call(DisablePlayerInput, false)
    Else
        Call(N(StarSpiritEffectFunc5), 6, 595, 130, 116, 100)
        Thread
            Call(N(StarSpiritEffectFunc6))
        EndThread
        Wait(1)
    EndIf
    Call(N(StarSpiritEffectFunc4), 3)
    Call(PlaySoundAtPlayer, SOUND_RESCUE_STAR_SPIRIT, SOUND_SPACE_DEFAULT)
    Call(DisablePlayerInput, true)
    Set(GB_StoryProgress, STORY_CH7_STAR_SPIRIT_RESCUED)
    Call(GotoMapSpecial, Ref("kmr_23"), kmr_23_ENTRY_6, TRANSITION_GET_STAR_CARD)
    Wait(100)
    Return
    End
};

s32 N(DoorModelsL)[] = {
    MODEL_o948, -1
};

s32 N(DoorModelsR)[] = {
    MODEL_o946, -1
};

EvtScript N(EVS_ExitDoors_pra_40_1) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_32_ENTRY_0)
    Set(LVar1, COLLIDER_deilittw)
    Set(LVar2, Ref(N(DoorModelsL)))
    Set(LVar3, Ref(N(DoorModelsR)))
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_40"), pra_40_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_40_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Set(LVar2, Ref(N(DoorModelsL)))
    Set(LVar3, Ref(N(DoorModelsR)))
    ExecWait(BaseEnterDoor)
    Exec(N(EVS_BindExitTriggers))
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1309, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1293, SURFACE_TYPE_SNOW)
    PlayEffect(EFFECT_SNOWFALL, 0, 120)
    Call(N(DisableFloorReflections))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
