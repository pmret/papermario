#include "isk_19.h"

EvtScript N(EVS_SetupMusic) = {
    IfEq(GF_ISK19_FinalWarning, FALSE)
        Thread
            Call(FadeInMusic, 1, SONG_TUTANKOOPA_WARNING, 0, 2000, 0, 127)
            Call(FadeOutMusic, 0, 2000)
            Call(DisablePlayerInput, TRUE)
            Wait(20)
            SetGroup(EVT_GROUP_NEVER_PAUSE)
            Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
            Call(ShowMessageAtScreenPos, MSG_CH2_00E1, 160, 40)
            Set(GF_ISK19_FinalWarning, TRUE)
            Call(DisablePlayerInput, FALSE)
            Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
            Call(FadeInMusic, 0, SONG_RUINS_BASEMENT, 0, 2000, 0, 127)
            Call(FadeOutMusic, 1, 2000)
        EndThread
        Return
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
            Call(SetMusicTrack, 0, SONG_DRY_DRY_RUINS, 0, 8)
        CaseLt(STORY_CH2_DEFEATED_TUTANKOOPA)
            Call(SetMusicTrack, 0, SONG_RUINS_BASEMENT, 0, 8)
        CaseGe(STORY_CH2_DEFEATED_TUTANKOOPA)
            Call(SetMusicTrack, 0, SONG_DRY_DRY_RUINS, 0, 8)
    EndSwitch
    Return
    End
};
