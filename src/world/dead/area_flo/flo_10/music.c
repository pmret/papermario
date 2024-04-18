#include "flo_10.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_10_ENTRY_1)
        Call(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    Else
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
            CaseDefault
                Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
        EndSwitch
    EndIf
    IfGe(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
        Call(PlaySound, SOUND_LOOP_FLO_WATER_FLOW_2)
    EndIf
    Return
    End
};

EvtScript N(EVS_PushFlowerSong) = {
    Call(PushSong, SONG_FLOWER_NPC_THEME, 2)
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
