#include "mac_00.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_INTRO)
            Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, BGM_VARIATION_1, VOL_LEVEL_FULL)
        CaseEq(STORY_EPILOGUE)
            Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, 0, VOL_LEVEL_FULL)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(SetMusic, 0, SONG_SHY_GUY_INVASION, 0, VOL_LEVEL_FULL)
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
