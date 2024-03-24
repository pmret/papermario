#include "isk_04.h"

EvtScript N(EVS_ExitWalk_isk_03_2) = EVT_EXIT_WALK(40, isk_04_ENTRY_0, "isk_03", isk_03_ENTRY_2);
EvtScript N(EVS_ExitWalk_isk_07_1) = EVT_EXIT_WALK(40, isk_04_ENTRY_1, "isk_07", isk_07_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_06_0) = EVT_EXIT_WALK(40, isk_04_ENTRY_2, "isk_06", isk_06_ENTRY_0);
EvtScript N(EVS_ExitWalk_isk_06_1) = EVT_EXIT_WALK(40, isk_04_ENTRY_3, "isk_06", isk_06_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_05_0) = EVT_EXIT_WALK(40, isk_04_ENTRY_4, "isk_05", isk_05_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_isk_03_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_07_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_06_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_06_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    Call(SetSpriteShading, SHADING_ISK_04)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(GetDemoState, LVar0)
    IfNe(LVar0, DEMO_STATE_NONE)
        ExecWait(N(EVS_SetupObstructions))
        ExecWait(N(EVS_SetupDemo))
        Return
    EndIf
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupObstructions))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
