#include "flo_03.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_03_ENTRY_2)
        Call(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    Else
        Switch(GB_StoryProgress)
            CaseLe(STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
                IfEq(GF_FLO03_DefeatedAll_MontyMoles, FALSE)
                    Call(SetMusicTrack, 0, SONG_MONTY_MOLE_ASSAULT, 0, 8)
                Else
                    Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
                EndIf
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
    IfGe(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
        IfEq(GF_FLO03_DefeatedAll_MontyMoles, TRUE)
            Call(PushSong, SONG_FLOWER_NPC_THEME, 0)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_PopSong) = {
    IfGe(GB_StoryProgress, STORY_CH6_ASKED_TO_DEFEAT_MONTY_MOLES)
        IfEq(GF_FLO03_DefeatedAll_MontyMoles, TRUE)
            Call(FadeOutMusic, 0, 250)
            Wait(10)
            Call(PopSong)
        EndIf
    EndIf
    Return
    End
};
