#include "tik_21.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_TOAD_TOWN_TUNNELS, 0, VOL_LEVEL_FULL)
    Return
    End
};
