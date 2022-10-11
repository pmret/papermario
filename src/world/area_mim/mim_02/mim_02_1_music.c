#include "mim_02.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_FOREVER_FOREST, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_SPOOKY)
    EVT_RETURN
    EVT_END
};
