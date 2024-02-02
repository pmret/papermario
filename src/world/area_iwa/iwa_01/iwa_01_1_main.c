#include "iwa_01.h"

EvtScript N(EVS_ExitWalk_iwa_00_1) = EVT_EXIT_WALK(60, iwa_01_ENTRY_0, "iwa_00", iwa_00_ENTRY_1);
EvtScript N(EVS_ExitWalk_iwa_03_0) = EVT_EXIT_WALK(60, iwa_01_ENTRY_1, "iwa_03", iwa_03_ENTRY_0);
EvtScript N(EVS_ExitWalk_iwa_02_0) = EVT_EXIT_WALK(60, iwa_01_ENTRY_2, "iwa_02", iwa_02_ENTRY_0);
EvtScript N(EVS_ExitWalk_iwa_02_1) = EVT_EXIT_WALK(60, iwa_01_ENTRY_3, "iwa_02", iwa_02_ENTRY_1);

EvtScript N(EVS_TexPan_Water) = {
    Call(EnableTexPanning, MODEL_o946, TRUE)
    Call(EnableTexPanning, MODEL_o947, TRUE)
    Set(LVar0, 0)
    Label(10)
        Sub(LVar0, 3000)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, LVar0)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(D_80243568_912C18) = {
    Call(EnableTexPanning, MODEL_o952, TRUE)
    Call(EnableTexPanning, MODEL_o956, TRUE)
    Call(EnableTexPanning, MODEL_o957, TRUE)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Label(10)
        Call(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, LVar0, 0)
        Call(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, 0, LVar1)
        Add(LVar0, 0x8000)
        Add(LVar1, 0x8000)
        Wait(2)
        Call(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, 0, LVar1)
        Add(LVar1, 0x8000)
        Wait(2)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_iwa_00_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_iwa_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_iwa_02_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_iwa_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili4, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_RUGGED)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_TexPan_Water))
    Exec(N(D_80243568_912C18))
    ExecWait(N(EVS_MakeSplashes))
    Exec(N(EVS_BindSlideTriggers2))
    Exec(N(EVS_BindSlideTriggers1))
    Call(SetMusicTrack, 0, SONG_MT_RUGGED, 0, 8)
    Call(PlaySoundAtF, SOUND_LOOP_IWA01_FLOW1, SOUND_SPACE_WITH_DEPTH, -570, -180, 425)
    Call(PlaySoundAtF, SOUND_LOOP_IWA01_FLOW2, SOUND_SPACE_WITH_DEPTH, 740, -170, 330)
    Call(GetLoadType, LVar1)
    IfEq(LVar1, 1)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
    Else
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    EndIf
    Wait(1)
    Return
    End
};

MAP_RODATA_PAD(1, pad);
