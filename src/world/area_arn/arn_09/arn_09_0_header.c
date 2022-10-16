#include "arn_09.h"

EntryList N(Entrances) = {
    [arn_09_ENTRY_0]    {  125.0,    0.0,    0.0,  270.0 },
    [arn_09_ENTRY_1]    {    0.0,  200.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_arn_09 },
};
