#include "tik_24.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_TOAD_TOWN_TUNNELS, 0, 8)
    Return
    End
};
