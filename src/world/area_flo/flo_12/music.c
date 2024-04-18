#include "flo_12.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_12_ENTRY_1)
        Call(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    Else
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
            CaseDefault
                Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
        EndSwitch
    EndIf
    Return
    End
};

EvtScript N(EVS_PushFlowerSong) = {
    Call(PushSong, SONG_FLOWER_NPC_THEME, 3)
    Return
    End
};

EvtScript N(EVS_PopMusic) = {
    Call(FadeOutMusic, 0, 250)
    Wait(10)
    Call(PopSong)
    Return
    End
};
