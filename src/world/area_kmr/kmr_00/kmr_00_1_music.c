#include "kmr_00.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_WAKE_UP)
        EVT_CALL(SetMusicTrack, 0, SONG_GOOMBA_VILLAGE, 0, 8)
        EVT_CALL(PlayAmbientSounds, AMBIENT_BIRDS)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
