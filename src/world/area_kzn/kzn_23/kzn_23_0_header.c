#include "kzn_23.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [kzn_23_ENTRY_0]    {    0.0,    0.0,  100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_VOLCANO_ESCAPE, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_EXIT_SEA)
    EVT_RETURN
    EVT_END
};
