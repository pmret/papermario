#include "jan_09.h"

EntryList N(Entrances) = {
    [jan_09_ENTRY_0]    {    0.0,    0.0,  480.0,    0.0 },
    [jan_09_ENTRY_1]    {  480.0,    0.0,    0.0,  270.0 },
    [jan_09_ENTRY_2]    { -480.0,  -20.0,    0.0,   90.0 },
    [jan_09_ENTRY_3]    { -177.0,  125.0, -435.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_jan_09 },
};
