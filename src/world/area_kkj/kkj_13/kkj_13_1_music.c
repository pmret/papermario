#include "kkj_13.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_INTRO)
        EVT_CASE_GE(STORY_CH8_REACHED_PEACHS_CASTLE)
            EVT_IF_EQ(GF_KKJ13_BowserTaunts, FALSE)
                EVT_THREAD
                    EVT_WAIT(30)
                    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
                EVT_END_THREAD
            EVT_ELSE
                EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
            EVT_END_IF
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_RETURN
    EVT_END
};
