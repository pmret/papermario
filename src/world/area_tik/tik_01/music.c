#include "tik_01.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_TOAD_TOWN_TUNNELS, 0, VOL_LEVEL_FULL)
    Return
    End
};

EvtScript N(EVS_PlayBlooperSong) = {
    Call(SetMusic, 0, SONG_BLOOPER_THEME, 0, VOL_LEVEL_FULL)
    Return
    End
};
