#include "nok_12.h"

EntryList N(Entrances) = {
    [nok_12_ENTRY_0]    { -786.0,    0.0,  -49.0,   90.0 },
    [nok_12_ENTRY_1]    {  886.0,   75.0,  -49.0,  270.0 },
    [nok_12_ENTRY_2]    {  180.0,    0.0,  -50.0,   90.0 },
    [nok_12_ENTRY_3]    { -500.0,    0.0, -145.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_nok_12 },
};
