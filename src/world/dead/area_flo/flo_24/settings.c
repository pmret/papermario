#include "flo_24.h"

EntryList N(Entrances) = {
    [flo_24_ENTRY_0]    { -455.0,    0.0,    0.0,   90.0 },
    [flo_24_ENTRY_1]    {  455.0,    0.0,    0.0,  270.0 },
    [flo_24_ENTRY_2]    {  455.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_24 },
};
