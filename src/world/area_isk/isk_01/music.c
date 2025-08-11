#include "isk_01.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GF_ISK01_FirstWarning, false)
        Thread
            Call(FadeInMusic, 1, SONG_TUTANKOOPA_WARNING, 0, 2000, 0, 127)
            Call(FadeOutMusic, 0, 2000)
            Call(DisablePlayerInput, true)
            Wait(20)
            SetGroup(EVT_GROUP_NEVER_PAUSE)
            Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
            Call(ShowMessageAtScreenPos, MSG_CH2_00DD, 160, 40)
            Set(GF_ISK01_FirstWarning, true)
            Call(DisablePlayerInput, false)
            Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
            Call(FadeInMusic, 0, SONG_DRY_DRY_RUINS, 0, 2000, 0, 127)
            Call(FadeOutMusic, 1, 2000)
        EndThread
        Return
    EndIf
#if VERSION_PAL
    Call(SetMusic, 0, SONG_DRY_DRY_RUINS, 0, VOL_LEVEL_FULL)
#else
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
            Call(SetMusic, 0, SONG_DRY_DRY_RUINS, 0, VOL_LEVEL_FULL)
        CaseLt(STORY_CH2_DEFEATED_TUTANKOOPA)
            Call(SetMusic, 0, SONG_RUINS_BASEMENT, 0, VOL_LEVEL_FULL)
        CaseGe(STORY_CH2_DEFEATED_TUTANKOOPA)
            Call(SetMusic, 0, SONG_DRY_DRY_RUINS, 0, VOL_LEVEL_FULL)
    EndSwitch
#endif
    Return
    End
};
