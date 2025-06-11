#include "flo_12.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_12_ENTRY_1)
        Call(SetMusic, 0, SONG_SUNSHINE_RETURNS, 0, VOL_LEVEL_FULL)
    Else
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                Call(SetMusic, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, VOL_LEVEL_FULL)
            CaseDefault
                Call(SetMusic, 0, SONG_FLOWER_FIELDS_SUNNY, 0, VOL_LEVEL_FULL)
        EndSwitch
    EndIf
    Return
    End
};

EvtScript N(EVS_PushFlowerSong) = {
    Call(PushSong, SONG_FLOWER_NPC_THEME, 3)
    Return
    End
};

EvtScript N(EVS_PopMusic) = {
    Call(FadeOutMusic, 0, 250)
    Wait(10)
    Call(PopSong)
    Return
    End
};
