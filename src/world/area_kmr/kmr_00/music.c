#include "kmr_00.h"

EvtScript N(EVS_SetupMusic) = {
    IfGe(GB_StoryProgress, STORY_CH0_WAKE_UP)
        Call(SetMusic, 0, SONG_GOOMBA_VILLAGE, 0, VOL_LEVEL_FULL)
        Call(PlayAmbientSounds, AMBIENT_BIRDS)
    EndIf
    Return
    End
};
