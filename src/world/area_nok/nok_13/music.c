#include "nok_13.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_PLEASANT_PATH, 0, VOL_LEVEL_FULL)
    Call(PlaySound, SOUND_LOOP_NOK_WATER)
    Return
    End
};
