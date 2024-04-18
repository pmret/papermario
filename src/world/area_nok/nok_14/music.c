#include "nok_14.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_PLEASANT_PATH, 0, 8)
    Call(PlaySound, SOUND_LOOP_NOK_WATER)
    Return
    End
};
