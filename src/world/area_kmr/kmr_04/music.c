#include "kmr_04.h"

EvtScript N(EVS_SetNormalMusic) = {
    Call(SetMusicTrack, 0, SONG_PLEASANT_PATH, 0, 8)
    Return
    End
};

EvtScript N(EVS_SetJrTroopaMusic) = {
    Call(SetMusicTrack, 0, SONG_JR_TROOPA_THEME, 0, 8)
    Return
    End
};

EvtScript N(EVS_PlayUpgradeSong) = {
    Call(PushSong, SONG_ITEM_UPGRADE, 0)
    Wait(130)
    Call(PopSong)
    Return
    End
};
