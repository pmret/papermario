#include "jan_01.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_YOSHIS_VILLAGE, 0, 8)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};
