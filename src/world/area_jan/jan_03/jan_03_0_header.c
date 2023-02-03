#include "jan_03.h"

EntryList N(Entrances) = {
    [jan_03_ENTRY_0]    { -583.0,    0.0,    0.0,   90.0 },
    [jan_03_ENTRY_1]    { -405.0,    0.0, -405.0,  135.0 },
    [jan_03_ENTRY_2]    {  583.0,    0.0,    0.0,  270.0 },
    [jan_03_ENTRY_3]    { -540.0,   35.0,  195.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_jan_03 },
};
