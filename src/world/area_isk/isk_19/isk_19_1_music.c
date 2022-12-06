#include "isk_19.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_EQ(GF_ISK19_FinalWarning, FALSE)
        EVT_THREAD
            EVT_CALL(FadeInMusic, 1, SONG_TUTANKOOPA_WARNING, 0, 2000, 0, 127)
            EVT_CALL(FadeOutMusic, 0, 2000)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_WAIT(20)
            EVT_SET_GROUP(EVT_GROUP_00)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH2_00E1, 160, 40)
            EVT_SET(GF_ISK19_FinalWarning, TRUE)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_CALL(FadeInMusic, 0, SONG_RUINS_BASEMENT, 0, 2000, 0, 127)
            EVT_CALL(FadeOutMusic, 1, 2000)
        EVT_END_THREAD
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
            EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_RUINS, 0, 8)
        EVT_CASE_LT(STORY_CH2_DEFEATED_TUTANKOOPA)
            EVT_CALL(SetMusicTrack, 0, SONG_RUINS_BASEMENT, 0, 8)
        EVT_CASE_GE(STORY_CH2_DEFEATED_TUTANKOOPA)
            EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_RUINS, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
