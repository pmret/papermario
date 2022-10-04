#include "kpa_117.h"

EntryList N(Entrances) = {
    [kpa_117_ENTRY_0]   { -210.0,    0.0,  100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_117 },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(SetMusicTrackVolumes, TRACK_VOLS_KPA_2)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
