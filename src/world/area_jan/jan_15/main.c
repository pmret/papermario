#include "jan_15.h"

EvtScript N(EVS_ExitWalk_jan_16) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(UseExitHeading, 60, jan_15_ENTRY_1)
    Exec(ExitWalk)
    IfLt(GB_StoryProgress, STORY_CH5_REACHED_RAPHAELS_TREE)
        Call(GotoMap, Ref("jan_16"), jan_16_ENTRY_3)
    Else
        Call(GotoMap, Ref("jan_16"), jan_16_ENTRY_0)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_jan_14_1) = EVT_EXIT_WALK(60, jan_15_ENTRY_0, "jan_14", jan_14_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_jan_14_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_jan_16)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupTrees))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilits, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Call(SetMusic, 0, SONG_DEEP_JUNGLE, 0, VOL_LEVEL_FULL)
    Call(PlayAmbientSounds, AMBIENT_JUNGLE)
    Return
    End
};
