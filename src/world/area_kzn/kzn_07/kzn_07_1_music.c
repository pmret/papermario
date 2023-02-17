#include "kzn_07.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayUpgradeFanfare) = {
    EVT_CALL(PushSong, SONG_ITEM_UPGRADE, 1)
    EVT_WAIT(130)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};
