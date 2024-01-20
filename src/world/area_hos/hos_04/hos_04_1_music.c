#include "hos_04.h"

EvtScript N(EVS_PlayIntroSong) = {
    Wait(80)
    Call(SetMusicTrack, 0, SONG_INTRO_STORY, 2, 8)
    Return
    End
};

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_04_ENTRY_2)
            Call(SetMusicTrack, 0, SONG_STARSHIP_THEME, 0, 8)
        CaseEq(hos_04_ENTRY_3)
        CaseEq(hos_04_ENTRY_4)
            Exec(N(EVS_PlayIntroSong))
        CaseDefault
            IfEq(GF_HOS04_Visited, FALSE)
                Call(SetMusicTrack, 0, SONG_STAR_SANCTUARY, 1, 8)
            Else
                Call(SetMusicTrack, 0, SONG_STAR_HAVEN, 0, 8)
            EndIf
            Call(PlaySound, SOUND_LOOP_STAR_SANCTUARY_NEAR)
    EndSwitch
    Return
    End
};
