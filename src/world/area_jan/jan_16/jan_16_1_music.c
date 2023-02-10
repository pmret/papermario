#include "jan_16.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(jan_16_ENTRY_0)
            EVT_CALL(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 0, 8)
            EVT_SET(AF_JAN_03, FALSE)
        EVT_CASE_EQ(jan_16_ENTRY_3)
            EVT_CALL(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 1, 8)
            EVT_SET(AF_JAN_03, TRUE)
        EVT_CASE_DEFAULT
            EVT_IF_EQ(AF_JAN_03, FALSE)
                EVT_CALL(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 0, 8)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(PlayAmbientSounds, AMBIENT_JUNGLE)
    EVT_RETURN
    EVT_END
};
