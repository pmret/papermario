#include "osr_00.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_INTRO)
            Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
        CaseEq(STORY_EPILOGUE)
            Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 0, 8)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 8)
    EndSwitch
    Call(GetEntryID, LVar0)
    IfEq(LVar0, osr_00_ENTRY_3)
        Call(ClearAmbientSounds, 250)
    EndIf
    Return
    End
};
