#include "nok_03.h"

EvtScript N(EVS_ExitWalk_nok_02_1) = EVT_EXIT_WALK_NOK(60, nok_03_ENTRY_0, "nok_02", nok_02_ENTRY_1);
EvtScript N(EVS_ExitWalk_nok_04_0) = EVT_EXIT_WALK_NOK(123, nok_03_ENTRY_1, "nok_04", nok_04_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_nok_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_nok_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_TexPan_Flowers) = {
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
    Call(SetTexPanner, MODEL_kabemizu, TEX_PANNER_2)
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

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_KOOPA_VILLAGE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_TexPan_Flowers))
    Exec(N(EVS_TexPan_Water))
    Exec(N(EVS_SetupMusic))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};
