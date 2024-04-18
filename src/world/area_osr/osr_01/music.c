
#include "osr_01.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 6)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 6)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_PlaySong_Starship) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, osr_01_ENTRY_3)
        Call(SetMusicTrack, 0, SONG_STARSHIP_THEME, 0, 8)
    Else
        Exec(N(EVS_SetupMusic))
    EndIf
    Return
    End
};
