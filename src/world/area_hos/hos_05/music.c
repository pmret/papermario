#include "hos_05.h"

EvtScript N(EVS_PlayIntroStoryMusic) = {
    Wait(40)
    Call(SetMusic, 0, SONG_INTRO_STORY, 0, VOL_LEVEL_FULL)
    Wait(2030)
    Call(SetMusic, 0, SONG_INTRO_STORY, BGM_VARIATION_1, VOL_LEVEL_FULL)
    Return
    End
};

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_05_ENTRY_1)
            Call(SetMusic, 0, SONG_STARSHIP_THEME, BGM_VARIATION_1, VOL_LEVEL_FULL)
            Call(PlaySound, SOUND_LOOP_STAR_SANCTUARY_INSIDE)
        CaseEq(hos_05_ENTRY_3)
            Exec(N(EVS_PlayIntroStoryMusic))
        CaseEq(hos_05_ENTRY_4)
        CaseDefault
            IfEq(AF_HOS_B5, FALSE)
                Call(SetMusic, 0, SONG_STAR_SANCTUARY, 0, VOL_LEVEL_FULL)
            EndIf
            Call(PlaySound, SOUND_LOOP_STAR_SANCTUARY_INSIDE)
    EndSwitch
    Return
    End
};
