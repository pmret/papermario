#include "flo_16.h"

EntryList N(Entrances) = {
    [flo_16_ENTRY_0]    { -720.0,    0.0,    0.0,   90.0 },
    [flo_16_ENTRY_1]    {  710.0,  100.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_16 },
};
