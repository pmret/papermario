#include "omo_17.h"

EntryList N(Entrances) = {
    [omo_17_ENTRY_0]    { -600.0,    0.0,  135.0,   90.0 },
    [omo_17_ENTRY_1]    { -600.0,   10.0, -135.0,   90.0 },
    [omo_17_ENTRY_2]    {  600.0,    0.0,  135.0,  270.0 },
    [omo_17_ENTRY_3]    {  600.0,   10.0, -135.0,  270.0 },
    [omo_17_ENTRY_4]    { -600.0,   10.0,    0.0,   90.0 },
    [omo_17_ENTRY_5]    {  600.0,   10.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_omo_17 },
};
