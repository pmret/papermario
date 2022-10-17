#include "arn_13.h"

EntryList N(Entrances) = {
    [arn_13_ENTRY_0]    { -231.0,    0.0,    5.0,   90.0 },
    [arn_13_ENTRY_1]    {  231.0,    0.0,    5.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_arn_13 },
};
