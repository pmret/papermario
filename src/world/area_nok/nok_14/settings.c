#include "nok_14.h"

EntryList N(Entrances) = {
    [nok_14_ENTRY_0]    { -855.0,   75.0,  -35.0,   90.0 },
    [nok_14_ENTRY_1]    {  436.0,    0.0,  -49.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_nok_14 },
};
