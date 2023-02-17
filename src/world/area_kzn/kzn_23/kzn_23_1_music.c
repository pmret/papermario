#include "kzn_23.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_VOLCANO_ESCAPE, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_5)
    EVT_RETURN
    EVT_END
};
