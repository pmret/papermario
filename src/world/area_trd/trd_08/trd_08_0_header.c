#include "trd_08.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [trd_08_ENTRY_0]    {  660.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_trd_08 },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_FORTRESS, 0, 8)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_RETURN
    EVT_END
};
