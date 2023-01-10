#include "jan_18.h"

EntryList N(Entrances) = {
    [jan_18_ENTRY_0]    {   25.0,  180.0,  205.0,  172.0 },
    [jan_18_ENTRY_1]    {   20.0,  345.0, -210.0,    6.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_jan_18 },
};
