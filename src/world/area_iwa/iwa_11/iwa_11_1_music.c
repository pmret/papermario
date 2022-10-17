#include "iwa_11.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_RIDING_THE_RAILS, 0, 8)
    EVT_RETURN
    EVT_END
};
