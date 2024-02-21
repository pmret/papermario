#include "nok_11.h"

EvtScript N(EVS_ExitWalk_mac_01_1) = {
    IfEq(GB_KootFavor_State, KOOT_FAVOR_STATE_2)
        Set(GF_KootFavor_LeftKoopaArea, TRUE)
    EndIf
    Call(UseExitHeading, 60, nok_11_ENTRY_0)
    Exec(ExitWalk)
    Call(GotoMap, Ref("mac_01"), mac_01_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_nok_12_0) = EVT_EXIT_WALK_NOK(60, nok_11_ENTRY_1, "nok_12", nok_12_ENTRY_0);

EvtScript N(EVS_TexPan_Flowers) = {
    Call(SetTexPanner, MODEL_hana2, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_hana3, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_hana4, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_hana5, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_hana6, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_hana7, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_hana8, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_hana9, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_hana10, TEX_PANNER_0)
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
            Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, LVar2)
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
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_AUX, LVar1, LVar2)
        Sub(LVar0, 100)
        Add(LVar1, 800)
        Sub(LVar1, 400)
        Wait(1)
        Goto(20)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_mac_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiri1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_nok_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PLEASANT_PATH)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Set(GF_MAP_PleasantPath, TRUE)
    IfEq(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        Call(MakeNpcs, FALSE, Ref(N(JrTroopaNPCs)))
    Else
        IfGe(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
            IfEq(GF_NOK11_Defeated_KentC, FALSE)
                Call(MakeNpcs, FALSE, Ref(N(KentCKoopaNPCs)))
            Else
                Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
            EndIf
        Else
            Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
        EndIf
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_TexPan_Flowers))
    Exec(N(EVS_TexPan_Water))
    Exec(N(EVS_SetupMusic))
    Call(PlaySound, SOUND_LOOP_NOK_WATER)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};
