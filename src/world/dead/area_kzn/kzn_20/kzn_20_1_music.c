#include "kzn_20.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
        EVT_CALL(PlaySound, SOUND_LOOP_RUMBLE)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
        EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_3)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_VOLCANO_ESCAPE, 0, 8)
        EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
