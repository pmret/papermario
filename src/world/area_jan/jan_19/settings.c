#include "jan_19.h"

EntryList N(Entrances) = {
    [jan_19_ENTRY_0]    { -220.0,    0.0,   10.0,   90.0 },
    [jan_19_ENTRY_1]    {  190.0,  450.0,  110.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_jan_19 },
};
