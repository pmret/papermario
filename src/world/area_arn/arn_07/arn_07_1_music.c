#include "arn_07.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_WOKE_UP)
            EVT_CALL(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
            EVT_CALL(PlayAmbientSounds, AMBIENT_WIND)
        EVT_CASE_LT(STORY_CH3_HEART_ESCAPED_WINDY_MILL)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
            EVT_CALL(PlayAmbientSounds, AMBIENT_WIND)
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_BLUBBA_THEME, 0, 8)
            EVT_CALL(PlayAmbientSounds, AMBIENT_WIND)
        EVT_CASE_EQ(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
            EVT_CALL(PlayAmbientSounds, AMBIENT_WIND)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
