#include "tik_01.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_TOAD_TOWN_TUNNELS, 0, 8)
    Return
    End
};

EvtScript N(EVS_PlayBlooperSong) = {
    Call(SetMusicTrack, 0, SONG_BLOOPER_THEME, 0, 8)
    Return
    End
};
