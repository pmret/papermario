#include "mac_05.h"

EntryList N(Entrances) = {
    [mac_05_ENTRY_0]    {  426.0,    0.0, -426.0,  225.0 },
    [mac_05_ENTRY_1]    {    0.0,    0.0,    0.0,    0.0 },
    [mac_05_ENTRY_2]    { -120.0,   24.0,  375.0,    0.0 },
    [mac_05_ENTRY_3]    { -280.0,  -10.0,  371.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_mac_05 },
};
