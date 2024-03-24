#include "iwa_00.h"

EvtScript N(EVS_ExitWalk_iwa_10_1) = EVT_EXIT_WALK(60, iwa_00_ENTRY_0, "iwa_10", iwa_10_ENTRY_1);
EvtScript N(EVS_ExitWalk_iwa_01_0) = EVT_EXIT_WALK(60, iwa_00_ENTRY_1, "iwa_01", iwa_01_ENTRY_0);

EvtScript N(EVS_TexPan_Water) = {
    Call(EnableTexPanning, MODEL_o949, TRUE)
    Call(EnableTexPanning, MODEL_water, TRUE)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 3000)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, LVar0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_iwa_10_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_iwa_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
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
    Exec(N(EVS_BindSlideTriggers))
    Call(SetMusicTrack, 0, SONG_MT_RUGGED, 0, 8)
    Call(PlaySoundAtF, SOUND_LOOP_IWA00_FLOW3, SOUND_SPACE_WITH_DEPTH, 35, -80, -120)
    Call(PlaySoundAtF, SOUND_LOOP_IWA00_FLOW2, SOUND_SPACE_WITH_DEPTH, 500, 85, -120)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};
