#include "kzn_22.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
        EVT_CALL(PlaySound, SOUND_LOOP_RUMBLE)
    EVT_END_IF
    EVT_CALL(SetMusicTrack, 0, SONG_VOLCANO_ESCAPE, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_4)
    EVT_RETURN
    EVT_END
};
