#include "mim_11.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_ARRIVED_AT_BOOS_MANSION)
            EVT_CALL(SetMusicTrack, 0, SONG_BOOS_MANSION, 1, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FOREVER_FOREST, 0, 8)
    EVT_END_SWITCH
    EVT_CALL(PlayAmbientSounds, AMBIENT_SPOOKY)
    EVT_RETURN
    EVT_END
};
