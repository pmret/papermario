#include "kzn_20.h"

EvtScript N(EVS_SetupMusic) = {
    IfGe(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
        Call(PlaySound, SOUND_LOOP_RUMBLE)
    EndIf
    IfLt(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        Call(SetMusic, 0, SONG_MT_LAVALAVA, 0, VOL_LEVEL_FULL)
        Call(PlayAmbientSounds, AMBIENT_LAVA_3)
    Else
        Call(SetMusic, 0, SONG_VOLCANO_ESCAPE, 0, VOL_LEVEL_FULL)
        Call(PlayAmbientSounds, AMBIENT_LAVA_1)
    EndIf
    Return
    End
};
