#include "flo_15.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_15_ENTRY_1)
        Call(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    Else
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                Call(SetMusicTrack, 0, SONG_SUN_TOWER_CLOUDY, 0, 8)
            CaseDefault
                Call(SetMusicTrack, 0, SONG_SUN_TOWER_SUNNY, 0, 8)
        EndSwitch
    EndIf
    Return
    End
};
