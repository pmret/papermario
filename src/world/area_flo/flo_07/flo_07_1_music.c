#include "flo_07.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_07_ENTRY_1)
        Call(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    Else
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
            CaseDefault
                Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
        EndSwitch
    EndIf
    Call(PlaySound, SOUND_LOOP_FLO_WATER_FLOW_1)
    Return
    End
};

EvtScript N(EVS_PushFlowerSong) = {
    Call(PushSong, SONG_FLOWER_NPC_THEME, 1)
    Return
    End
};

EvtScript N(EVS_PopSong) = {
    Call(FadeOutMusic, 0, 250)
    Wait(10)
    Call(PopSong)
    Return
    End
};
