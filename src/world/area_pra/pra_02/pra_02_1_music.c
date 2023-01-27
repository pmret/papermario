#include "pra_02.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_CRYSTAL_PALACE, 0, 8)
    EVT_RETURN
    EVT_END
};
