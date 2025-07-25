#include "jan_14.h"

EvtScript N(EVS_ExitWalk_jan_15_0) = EVT_EXIT_WALK(60, jan_14_ENTRY_1, "jan_15", jan_15_ENTRY_0);
EvtScript N(EVS_ExitWalk_jan_13_1) = EVT_EXIT_WALK(60, jan_14_ENTRY_0, "jan_13", jan_13_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_jan_13_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_jan_15_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    Exec(N(EVS_SetupVines))
    Exec(N(EVS_SetupTrees))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilits, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Call(SetMusic, 0, SONG_DEEP_JUNGLE, 0, VOL_LEVEL_FULL)
    Call(PlayAmbientSounds, AMBIENT_JUNGLE)
    Return
    End
};
