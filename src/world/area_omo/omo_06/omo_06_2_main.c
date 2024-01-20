#include "omo_06.h"

EvtScript N(EVS_ExitWalk_omo_17_2) = EVT_EXIT_WALK(60, omo_06_ENTRY_0, "omo_17", omo_17_ENTRY_2);
EvtScript N(EVS_ExitWalk_omo_17_3) = EVT_EXIT_WALK(60, omo_06_ENTRY_1, "omo_17", omo_17_ENTRY_3);
EvtScript N(EVS_ExitWalk_omo_07_0) = EVT_EXIT_WALK(60, omo_06_ENTRY_4, "omo_07", omo_07_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_omo_17_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_omo_17_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilit5, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_omo_07_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseRange(omo_06_ENTRY_2, omo_06_ENTRY_3)
            Exec(N(EVS_BindExitTriggers))
            Wait(3)
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
#if VERSION_PAL
    Call(GetLanguage, LVar0)
    Switch(LVar0)
        IfGe(LVar0, LANGUAGE_FR) // or LANGUAGE_ES
            Sub(LVar0, LANGUAGE_FR - LANGUAGE_EN)
        EndIf
        Call(SetModelTexVariant, MODEL_s, LVar0)
        Call(SetModelTexVariant, MODEL_a, LVar0)
        Call(SetModelTexVariant, MODEL_t, LVar0)
        Call(SetModelTexVariant, MODEL_i, LVar0)
        Call(SetModelTexVariant, MODEL_o, LVar0)
        Call(SetModelTexVariant, MODEL_n, LVar0)
#endif
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupGizmos))
    ExecWait(N(EVS_SetupMusic))
    ExecWait(N(EVS_80244F40))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
