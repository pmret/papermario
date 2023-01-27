#include "pra_15.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_SHIVER_MOUNTAIN, 0, 8)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_RETURN
    EVT_END
};
