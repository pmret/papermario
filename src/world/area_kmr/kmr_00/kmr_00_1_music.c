#include "kmr_00.h"

EvtScript N(EVS_SetupMusic) = {
    IfGe(GB_StoryProgress, STORY_CH0_WAKE_UP)
        Call(SetMusicTrack, 0, SONG_GOOMBA_VILLAGE, 0, 8)
        Call(PlayAmbientSounds, AMBIENT_BIRDS)
    EndIf
    Return
    End
};
