#include "tik_25.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TOAD_TOWN_TUNNELS, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayUpgradeSong) = {
    EVT_CALL(PushSong, SONG_ITEM_UPGRADE, 1)
    EVT_WAIT(130)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};
