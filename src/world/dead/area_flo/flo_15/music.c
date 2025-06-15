#include "flo_15.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_15_ENTRY_1)
        Call(SetMusic, 0, SONG_SUNSHINE_RETURNS, 0, VOL_LEVEL_FULL)
    Else
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                Call(SetMusic, 0, SONG_SUN_TOWER_CLOUDY, 0, VOL_LEVEL_FULL)
            CaseDefault
                Call(SetMusic, 0, SONG_SUN_TOWER_SUNNY, 0, VOL_LEVEL_FULL)
        EndSwitch
    EndIf
    Return
    End
};
