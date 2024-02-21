#include "nok_13.h"

EvtScript N(EVS_ExitWalk_nok_12_1) = {
    Call(UseExitHeading, 60, nok_13_ENTRY_0)
    Exec(ExitWalk)
    Call(GotoMap, Ref("nok_12"), nok_12_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_nok_01_0) = {
    Call(UseExitHeading, 60, nok_13_ENTRY_1)
    Exec(ExitWalk)
    Call(GotoMap, Ref("nok_01"), nok_01_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_nok_14_0) = {
    Call(UseExitHeading, 60, nok_13_ENTRY_2)
    Exec(ExitWalk)
    Call(GotoMap, Ref("nok_14"), nok_14_ENTRY_0)
    Wait(100)
    Return
    End
};

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_TexPan_Flowers) = {
    Call(SetTexPanner, MODEL_hana1, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_hana2, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_hanahana, TEX_PANNER_0)
    Label(10)
    Loop(12)
        Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
        Wait(1)
    EndLoop
    Loop(12)
        Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0x4000, 0)
        Wait(1)
    EndLoop
    Goto(10)
    Return
    End
};

EvtScript N(EVS_TexPan_Water) = {
    Thread
        Call(SetTexPanner, MODEL_suimen1, TEX_PANNER_1)
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Label(10)
            Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX,  LVar1, LVar2)
            Sub(LVar0, 100)
            Sub(LVar1, 400)
            Add(LVar1, 1000)
            Wait(1)
            Goto(10)
    EndThread
    Call(SetTexPanner, MODEL_kabemizu1, TEX_PANNER_2)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Label(20)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, 0)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_AUX,  LVar1, LVar2)
        Sub(LVar0, 100)
        Add(LVar1, 800)
        Sub(LVar1, 400)
        Wait(1)
        Goto(20)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_nok_12_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_nok_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_nok_14_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PLEASANT_PATH)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_TexPan_Flowers))
    Exec(N(EVS_TexPan_Water))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_SetupMusicalHill))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};
