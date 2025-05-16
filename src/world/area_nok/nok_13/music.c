#include "nok_13.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_PLEASANT_PATH, 0, VOL_LEVEL_8)
    Call(PlaySound, SOUND_LOOP_NOK_WATER)
    Return
    End
};
