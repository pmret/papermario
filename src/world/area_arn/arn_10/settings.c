#include "arn_10.h"

EntryList N(Entrances) = {
    [arn_10_ENTRY_0]    { -225.0,    0.0,    0.0,   90.0 },
    [arn_10_ENTRY_1]    {  225.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_arn_10 },
};
