#include "iwa_02.h"

EvtScript N(EVS_ExitWalk_iwa_01_2) = EVT_EXIT_WALK(60, iwa_02_ENTRY_0, "iwa_01", iwa_01_ENTRY_2);
EvtScript N(EVS_ExitWalk_iwa_01_3) = EVT_EXIT_WALK(60, iwa_02_ENTRY_1, "iwa_01", iwa_01_ENTRY_3);
EvtScript N(EVS_ExitWalk_iwa_04_0) = EVT_EXIT_WALK(60, iwa_02_ENTRY_2, "iwa_04", iwa_04_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_iwa_01_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_iwa_01_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_iwa_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_RUGGED)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Call(SetMusic, 0, SONG_MT_RUGGED, 0, VOL_LEVEL_FULL)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};
