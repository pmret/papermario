#include "kpa_81.h"

EntryList N(Entrances) = {
    [kpa_81_ENTRY_0]    { -195.0,    0.0,  150.0,   90.0 },
    [kpa_81_ENTRY_1]    {    0.0,  200.0,  150.0,    0.0 },
    [kpa_81_ENTRY_2]    {  150.0,    0.0,  150.0,  270.0 },
    [kpa_81_ENTRY_3]    {    0.0,    0.0,   59.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_81 },
};
