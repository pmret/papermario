#include "mim_12.h"

EvtScript N(EVS_StartForestMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_ARRIVED_AT_BOOS_MANSION)
            Call(SetMusic, 0, SONG_BOOS_MANSION, BGM_VARIATION_1, VOL_LEVEL_FULL)
        CaseDefault
            Call(SetMusic, 0, SONG_FOREVER_FOREST, 0, VOL_LEVEL_FULL)
    EndSwitch
    Call(ClearAmbientSounds, 250)
    Return
    End
};

EvtScript N(EVS_StartGustyMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_WOKE_UP)
            Call(SetMusic, 0, SONG_GUSTY_GULCH, 0, VOL_LEVEL_FULL)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SetMusic, 0, SONG_TUBBA_ESCAPE, 0, VOL_LEVEL_FULL)
        CaseDefault
            Call(SetMusic, 0, SONG_GUSTY_GULCH, 0, VOL_LEVEL_FULL)
    EndSwitch
    Call(PlayAmbientSounds, AMBIENT_WIND)
    Return
    End
};

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mim_12_ENTRY_0)
        ExecWait(N(EVS_StartForestMusic))
    Else
        ExecWait(N(EVS_StartGustyMusic))
    EndIf
    Return
    End
};
