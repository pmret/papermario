#include "mac_04.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, mac_04_ENTRY_4)
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
                EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
            EVT_CASE_DEFAULT
                EVT_EXEC(N(EVS_SetupMusicTriggers))
        EVT_END_SWITCH
        EVT_THREAD
            EVT_WAIT(60)
            EVT_CALL(StopSound, SOUND_LOOP_JAN_BEACH_WAVES)
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
