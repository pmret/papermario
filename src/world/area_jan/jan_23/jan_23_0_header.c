#include "jan_23.h"

EntryList N(Entrances) = {
    [jan_23_ENTRY_0]    {  230.0,  160.0,  106.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_jan_23 },
};
