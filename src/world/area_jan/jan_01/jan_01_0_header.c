#include "jan_01.h"

EntryList N(Entrances) = {
    [jan_01_ENTRY_0]    { -663.0,  -14.0,   53.0,   90.0 },
    [jan_01_ENTRY_1]    {  663.0,  -16.0,   40.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_jan_01 },
};
