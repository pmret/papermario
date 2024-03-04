#include "omo_13.h"

EvtScript N(EVS_ExitWalk_omo_01_0) = EVT_EXIT_WALK(60, omo_13_ENTRY_0, "omo_01", omo_01_ENTRY_0);
EvtScript N(EVS_ExitWalk_omo_03_0) = EVT_EXIT_WALK(60, omo_13_ENTRY_1, "omo_03", omo_03_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_omo_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_omo_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    IfEq(GF_OMO13_Defeated_AntiGuy, TRUE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_he, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupGizmos))
    ExecWait(N(EVS_SetupMusic))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};
