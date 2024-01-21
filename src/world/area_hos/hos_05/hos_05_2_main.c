#include "hos_05.h"

EvtScript N(EVS_ExitWalk_hos_04_1) = EVT_EXIT_WALK(60, hos_05_ENTRY_0, "hos_04", hos_04_ENTRY_1);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_hos_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_Starship_Depart)), TRIGGER_FLOOR_TOUCH, COLLIDER_o630, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_STAR_HAVEN)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(GetEntryID, LVar0)
    IfEq(LVar0, hos_05_ENTRY_3)
        Call(MakeNpcs, FALSE, Ref(N(IntroNPCs)))
    Else
        Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    EndIf
    Exec(N(EVS_SetupStarshipAndWater))
    ExecWait(N(EVS_SetupMusic))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_05_ENTRY_0)
            Call(SetCamSpeed, CAM_DEFAULT, Float(2.5))
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(hos_05_ENTRY_1)
            Thread
                ExecWait(N(EVS_EnterStarship))
                Exec(N(EVS_BindExitTriggers))
            EndThread
        CaseEq(hos_05_ENTRY_3)
            ExecWait(N(EVS_Intro_Main))
    EndSwitch
    Exec(N(EVS_SetupNarrator))
    Call(EnableGroup, MODEL_g277, FALSE)
    Call(EnableGroup, MODEL_g279, FALSE)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseRange(hos_05_ENTRY_0, hos_05_ENTRY_1)
            Exec(N(EVS_SetupLightBeam))
    EndSwitch
    Return
    End
};
