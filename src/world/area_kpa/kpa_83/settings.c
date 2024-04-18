#include "kpa_83.h";

EntryList N(Entrances) = {
    [kpa_83_ENTRY_0]    { -210.0,    0.0,  150.0,   90.0 },
    [kpa_83_ENTRY_1]    {  150.0,    0.0,  150.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_83 },
};
