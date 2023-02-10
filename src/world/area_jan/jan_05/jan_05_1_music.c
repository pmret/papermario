#include "jan_05.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_JADE_JUNGLE, 0, 8)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};
