#include "nok_11.h"

EntryList N(Entrances) = {
    [nok_11_ENTRY_0]    { -758.0,    0.0,  -49.0,   90.0 },
    [nok_11_ENTRY_1]    {  886.0,    0.0,  -40.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_nok_11 },
};
