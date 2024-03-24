#include "mac_00.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_INTRO)
            Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
        CaseEq(STORY_EPILOGUE)
            Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 0, 8)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
        CaseDefault
            Exec(N(EVS_SetupMusicTriggers))
    EndSwitch
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(mac_00_ENTRY_4)
        CaseOrEq(mac_00_ENTRY_5)
        CaseOrEq(mac_00_ENTRY_6)
        CaseOrEq(mac_00_ENTRY_7)
            Call(ClearAmbientSounds, 250)
        EndCaseGroup
    EndSwitch
    Return
    End
};
