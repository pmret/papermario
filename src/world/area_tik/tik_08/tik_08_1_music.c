#include "tik_08.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TOAD_TOWN_TUNNELS, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayBlooperSong) = {
    EVT_CALL(SetMusicTrack, 0, SONG_BLOOPER_THEME, 0, 8)
    EVT_RETURN
    EVT_END
};
