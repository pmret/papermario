#include "omo_10.h"

EntryList N(Entrances) = {
    [omo_10_ENTRY_0]    { -330.0,    0.0,  330.0,   45.0 },
    [omo_10_ENTRY_1]    {  330.0,    0.0,  330.0,  315.0 },
    [omo_10_ENTRY_2]    { -330.0,   10.0, -330.0,  135.0 },
    [omo_10_ENTRY_3]    {  330.0,   10.0, -330.0,  225.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_omo_10 },
};
