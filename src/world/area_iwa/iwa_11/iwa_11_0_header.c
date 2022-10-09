#include "iwa_11.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [iwa_11_ENTRY_0]    {    0.0,    0.0,   15.0,   90.0 },
    [iwa_11_ENTRY_1]    {    0.0,    0.0,   15.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_RIDING_THE_RAILS, 0, 8)
    EVT_RETURN
    EVT_END
};
