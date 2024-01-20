#include "tik_25.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_TOAD_TOWN_TUNNELS, 0, 8)
    Return
    End
};

EvtScript N(EVS_PlayUpgradeSong) = {
    Call(PushSong, SONG_ITEM_UPGRADE, 1)
    Wait(130)
    Call(PopSong)
    Return
    End
};
