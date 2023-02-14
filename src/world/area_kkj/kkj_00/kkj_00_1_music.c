#include "kkj_00.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_INTRO)
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, kkj_00_ENTRY_3)
            EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 7)
            EVT_WAIT(3)
        EVT_END_IF
        EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
    EVT_ELSE
        EVT_THREAD
            EVT_WAIT(90)
            EVT_CALL(FadeOutMusic, 0, 3000)
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
