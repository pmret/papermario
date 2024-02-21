#include "kpa_112.h"

EntryList N(Entrances) = {
    [kpa_112_ENTRY_0]   { -150.0,    0.0,  110.0,    0.0 },
    [kpa_112_ENTRY_1]   {  473.0,    0.0,  112.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_112 },
};
