#include "nok_11.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_PLEASANT_PATH, 0, VOL_LEVEL_FULL)
    Return
    End
};

EvtScript N(EVS_PlayJrTroopaSong) = {
    Call(SetMusic, 0, SONG_JR_TROOPA_THEME, 0, VOL_LEVEL_FULL)
    Return
    End
};
