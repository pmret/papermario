#include "mac_01.h"

EntryList N(Entrances) = {
    [mac_01_ENTRY_0]    { -600.0,    0.0,    0.0,   90.0 },
    [mac_01_ENTRY_1]    {  600.0,    0.0,    0.0,  270.0 },
    [mac_01_ENTRY_2]    {    0.0,    0.0, -570.0,  180.0 },
    [mac_01_ENTRY_3]    {    0.0,    0.0,  600.0,    0.0 },
    [mac_01_ENTRY_4]    { -400.0,    0.0,    0.0,   90.0 },
    [mac_01_ENTRY_5]    {  264.0,   27.0,  350.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_mac_01 },
};
