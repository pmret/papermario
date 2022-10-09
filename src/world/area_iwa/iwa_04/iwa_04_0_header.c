#include "iwa_04.h"
#include "entity.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [iwa_04_ENTRY_0]    { -630.0,    0.0,  -49.0,   90.0 },
    [iwa_04_ENTRY_1]    {  770.0, -250.0,  -40.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_iwa_04 },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_MT_RUGGED, 0, 8)
    EVT_RETURN
    EVT_END
};
