#include "jan_22.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, jan_22_ENTRY_3)
        EVT_CALL(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
        EVT_THREAD
            EVT_LOOP(0)
                EVT_WAIT(1)
                EVT_IF_GE(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(SetMusicTrack, 0, SONG_DEEP_JUNGLE, 0, 8)
        EVT_END_THREAD
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_RANGE(STORY_CH5_RAPHAEL_MOVED_ROOT, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
                EVT_IF_NE(LVar0, jan_22_ENTRY_1)
                    EVT_CALL(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 0, 8)
                    EVT_SET(AF_JAN_03, FALSE)
                EVT_END_IF
                EVT_THREAD
                    EVT_LOOP(0)
                        EVT_WAIT(1)
                        EVT_IF_GE(GB_StoryProgress, STORY_CH5_ZIP_LINE_READY)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                    EVT_END_LOOP
                    EVT_CALL(SetMusicTrack, 0, SONG_DEEP_JUNGLE, 0, 8)
                    EVT_SET(AF_JAN_03, FALSE)
                EVT_END_THREAD
            EVT_CASE_DEFAULT
                EVT_CALL(SetMusicTrack, 0, SONG_DEEP_JUNGLE, 0, 8)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(PlayAmbientSounds, AMBIENT_JUNGLE)
    EVT_RETURN
    EVT_END
};
