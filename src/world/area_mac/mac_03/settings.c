#include "mac_03.h"

EntryList N(Entrances) = {
    [mac_03_ENTRY_0]    {    0.0,    0.0, -600.0,  180.0 },
    [mac_03_ENTRY_1]    {  590.0,   30.0,  100.0,  270.0 },
    [mac_03_ENTRY_2]    { -125.0,   50.0, -562.0,   90.0 },
    [mac_03_ENTRY_3]    { -415.0,   20.0,   92.0,  350.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_mac_03 },
};
