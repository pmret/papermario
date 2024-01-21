#include "mim_12.h"

EvtScript N(EVS_StartForestMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_ARRIVED_AT_BOOS_MANSION)
            Call(SetMusicTrack, 0, SONG_BOOS_MANSION, 1, 8)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_FOREVER_FOREST, 0, 8)
    EndSwitch
    Call(ClearAmbientSounds, 250)
    Return
    End
};

EvtScript N(EVS_StartGustyMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_WOKE_UP)
            Call(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
    EndSwitch
    Call(PlayAmbientSounds, AMBIENT_WIND)
    Return
    End
};

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mim_12_ENTRY_0)
        ExecWait(N(EVS_StartForestMusic))
    Else
        ExecWait(N(EVS_StartGustyMusic))
    EndIf
    Return
    End
};
