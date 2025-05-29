#include "kzn_07.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusic, 0, SONG_MT_LAVALAVA, 0, VOL_LEVEL_FULL)
    Call(PlayAmbientSounds, AMBIENT_LAVA_1)
    Return
    End
};

EvtScript N(EVS_PlayUpgradeFanfare) = {
    Call(PushSong, SONG_ITEM_UPGRADE, 1)
    Wait(130)
    Call(PopSong)
    Return
    End
};
