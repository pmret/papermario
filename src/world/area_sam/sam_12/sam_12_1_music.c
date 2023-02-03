#include "sam_12.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_MERLAR_THEME, 0, 8)
    EVT_RETURN
    EVT_END
};
