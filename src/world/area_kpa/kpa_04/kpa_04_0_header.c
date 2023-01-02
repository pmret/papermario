#include "kpa_04.h"

EntryList N(Entrances) = {
    [kpa_04_ENTRY_0]    {  212.0,    0.0,  150.0,  270.0 },
    [kpa_04_ENTRY_1]    {    0.0,    0.0,  287.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_04 },
};
