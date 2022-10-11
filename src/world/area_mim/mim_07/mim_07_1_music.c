#include "mim_07.h"

EvtScript N(EVS_PlayForestMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_FOREVER_FOREST, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_SPOOKY)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JrTroopaMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_JR_TROOPA_THEME, 0, 8)
    EVT_RETURN
    EVT_END
};
