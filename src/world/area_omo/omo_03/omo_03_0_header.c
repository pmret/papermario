#include "omo_03.h"

EntryList N(Entrances) = {
    [omo_03_ENTRY_0]    { -320.0,    0.0,  320.0,   45.0 },
    [omo_03_ENTRY_1]    {  340.0,    0.0,  330.0,  315.0 },
    [omo_03_ENTRY_2]    { -320.0,   10.0, -320.0,  135.0 },
    [omo_03_ENTRY_3]    {  320.0,   10.0, -320.0,  225.0 },
    [omo_03_ENTRY_4]    { -245.0,  270.0,  250.0,   90.0 },
    [omo_03_ENTRY_5]    {    0.0, -100.0,    0.0,   90.0 },
    [omo_03_ENTRY_6]    { -320.0,    0.0,  320.0,   45.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_omo_03 },
};
