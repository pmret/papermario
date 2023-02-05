#include "nok_12.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_PLEASANT_PATH, 0, 8)
    EVT_CALL(PlaySound, SOUND_8000005B)
    EVT_RETURN
    EVT_END
};
