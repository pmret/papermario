#include "jan_13.h"

EvtScript N(EVS_ExitWalk_jan_14_0) = EVT_EXIT_WALK(60, jan_13_ENTRY_1, "jan_14", jan_14_ENTRY_0);
EvtScript N(EVS_ExitWalk_jan_12_1) = EVT_EXIT_WALK(60, jan_13_ENTRY_0, "jan_12", jan_12_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_jan_12_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_jan_14_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Exec(N(EVS_MakeEntities))
    Exec(N(EVS_SetupPuzzle))
    Exec(N(EVS_SetupTrees))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilits, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Call(SetMusicTrack, 0, SONG_DEEP_JUNGLE, 0, 8)
    Call(PlayAmbientSounds, AMBIENT_JUNGLE)
    Return
    End
};
