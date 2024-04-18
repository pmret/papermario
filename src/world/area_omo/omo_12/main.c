#include "omo_12.h"

EvtScript N(EVS_ExitWalk_omo_11_0) = EVT_EXIT_WALK(60, omo_12_ENTRY_0, "omo_11", omo_11_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_omo_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_SetupMusic))
    ExecWait(N(EVS_SetupLightSource))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_DEFEATED_LANTERN_GHOST)
            Exec(N(EVS_BindExitTriggers))
            Exec(N(EVS_EnterScene))
            Wait(1)
        CaseLt(STORY_CH4_WATT_JOINED_PARTY)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        CaseGe(STORY_CH4_WATT_JOINED_PARTY)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
    EndSwitch
    Return
    End
};
