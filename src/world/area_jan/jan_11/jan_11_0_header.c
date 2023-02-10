#include "jan_11.h"

EntryList N(Entrances) = {
    [jan_11_ENTRY_0]    {  -90.0,    0.0,   61.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_jan_11 },
};
