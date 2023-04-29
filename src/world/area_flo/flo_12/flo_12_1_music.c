#include "flo_12.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, flo_12_ENTRY_1)
        EVT_CALL(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
            EVT_CASE_DEFAULT
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushFlowerSong) = {
    EVT_CALL(PushSong, SONG_FLOWER_NPC_THEME, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PopMusic) = {
    EVT_CALL(FadeOutMusic, 0, 250)
    EVT_WAIT(10)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};
