#include "osr_00.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_INTRO)
            Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, BGM_VARIATION_1, VOL_LEVEL_FULL)
        CaseEq(STORY_EPILOGUE)
            Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, 0, VOL_LEVEL_FULL)
        CaseDefault
            Call(SetMusic, 0, SONG_TOAD_TOWN, 0, VOL_LEVEL_FULL)
    EndSwitch
    Call(GetEntryID, LVar0)
    IfEq(LVar0, osr_00_ENTRY_3)
        Call(ClearAmbientSounds, 250)
    EndIf
    Return
    End
};
