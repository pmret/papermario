#include "kpa_33.h"

EntryList N(Entrances) = {
    [kpa_33_ENTRY_0]    { -547.0,  -50.0,   -5.0,   90.0 },
    [kpa_33_ENTRY_1]    {  547.0,  -50.0,   -5.0,  270.0 },
    [kpa_33_ENTRY_2]    {  550.0,  140.0,    0.0,  270.0 },
    [kpa_33_ENTRY_3]    { -550.0,  140.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kpa_33 },
};
