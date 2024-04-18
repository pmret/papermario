#include "jan_16.h"

EntryList N(Entrances) = {
    [jan_16_ENTRY_0]    { -480.0,    0.0,    0.0,   90.0 },
    [jan_16_ENTRY_1]    {  480.0,    0.0,    0.0,  270.0 },
    [jan_16_ENTRY_2]    { -247.0,    0.0,    0.0,  225.0 },
    [jan_16_ENTRY_3]    { -390.0,    0.0,   20.0,  100.0 },
    [jan_16_ENTRY_4]    {   35.0,  600.0,  330.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_jan_16 },
};
