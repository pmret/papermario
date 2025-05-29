#include "hos_04.h"

EvtScript N(EVS_PlayIntroSong) = {
    Wait(80)
    Call(SetMusic, 0, SONG_INTRO_STORY, BGM_VARIATION_2, VOL_LEVEL_FULL)
    Return
    End
};

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_04_ENTRY_2)
            Call(SetMusic, 0, SONG_STARSHIP_THEME, 0, VOL_LEVEL_FULL)
        CaseEq(hos_04_ENTRY_3)
        CaseEq(hos_04_ENTRY_4)
            Exec(N(EVS_PlayIntroSong))
        CaseDefault
            IfEq(GF_HOS04_Visited, FALSE)
                Call(SetMusic, 0, SONG_STAR_SANCTUARY, BGM_VARIATION_1, VOL_LEVEL_FULL)
            Else
                Call(SetMusic, 0, SONG_STAR_HAVEN, 0, VOL_LEVEL_FULL)
            EndIf
            Call(PlaySound, SOUND_LOOP_STAR_SANCTUARY_NEAR)
    EndSwitch
    Return
    End
};
