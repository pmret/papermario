#include "sam_07.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_SHIVER_MOUNTAIN, 0, 8)
    EVT_RETURN
    EVT_END
};
