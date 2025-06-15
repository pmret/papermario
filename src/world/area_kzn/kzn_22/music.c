#include "kzn_22.h"

EvtScript N(EVS_SetupMusic) = {
    IfGe(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
        Call(PlaySound, SOUND_LOOP_RUMBLE)
    EndIf
    Call(SetMusic, 0, SONG_VOLCANO_ESCAPE, 0, VOL_LEVEL_FULL)
    Call(PlayAmbientSounds, AMBIENT_LAVA_4)
    Return
    End
};
