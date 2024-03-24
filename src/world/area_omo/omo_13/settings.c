#include "omo_13.h"

EntryList N(Entrances) = {
    [omo_13_ENTRY_0]    { -480.0,    0.0,    0.0,   90.0 },
    [omo_13_ENTRY_1]    {  565.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_omo_13 },
};
