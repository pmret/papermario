#include "jan_03.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING, STORY_CH5_SUSHIE_JOINED_PARTY)
            EVT_CALL(SetMusicTrack, 0, SONG_YOSHIS_PANIC, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_YOSHIS_VILLAGE, 0, 8)
    EVT_END_SWITCH
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayRestingSong) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    EVT_RETURN
    EVT_END
};
