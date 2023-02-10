#include "jan_10.h"

EntryList N(Entrances) = {
    [jan_10_ENTRY_0]    {  380.0,  -20.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_jan_10 },
};
