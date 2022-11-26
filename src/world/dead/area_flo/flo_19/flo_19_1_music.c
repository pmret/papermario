#include "flo_19.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(flo_19_ENTRY_0)
        EVT_CASE_OR_EQ(flo_19_ENTRY_1)
            EVT_CALL(SetMusicTrack, 0, SONG_CLOUDY_CLIMB, 0, 8)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(flo_19_ENTRY_2)
        EVT_CASE_OR_EQ(7)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(flo_19_ENTRY_3)
            EVT_IF_NE(AF_FLO_RidingBeanstalk, FALSE)
            EVT_ELSE
                EVT_CALL(FadeOutMusic, 1, 3000)
                EVT_CALL(FadeInMusic, 0, SONG_CLOUDY_CLIMB, 0, 3000, 0, 127)
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
