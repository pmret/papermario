#include "kmr_04.h"

EvtScript N(EVS_SetNormalMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_PLEASANT_PATH, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetJrTroopaMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_JR_TROOPA_THEME, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayUpgradeSong) = {
    EVT_CALL(PushSong, SONG_ITEM_UPGRADE, 0)
    EVT_WAIT(130)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};
