#include "hos_10.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(hos_10_ENTRY_1)
            EVT_CALL(SetMusicTrack, 0, SONG_INTRO_STORY, 3, 8)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(hos_10_ENTRY_2)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(hos_10_ENTRY_3)
        EVT_CASE_OR_EQ(hos_10_ENTRY_4)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(hos_10_ENTRY_5)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(SetMusicTrack, 0, SONG_MARIO_FALLS, 0, 8)
            EVT_END_THREAD
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
