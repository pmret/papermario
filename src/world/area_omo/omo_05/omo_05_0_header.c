#include "omo_05.h"

EntryList N(Entrances) = {
    [omo_05_ENTRY_0]    {  590.0,    0.0,  135.0,  270.0 },
    [omo_05_ENTRY_1]    {  590.0,   10.0, -140.0,  270.0 },
    [omo_05_ENTRY_2]    { -600.0,   10.0,    0.0,   90.0 },
    [omo_05_ENTRY_3]    {  600.0,   10.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_omo_05 },
};
