#include "pra_40.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_CRYSTAL_PALACE, 0, 8)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_RETURN
    EVT_END
};
