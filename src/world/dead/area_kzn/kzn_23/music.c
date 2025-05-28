#include "kzn_23.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_VOLCANO_ESCAPE, 0, VOL_LEVEL_FULL)
    Call(PlayAmbientSounds, AMBIENT_LAVA_5)
    Return
    End
};
