#include "kpa_51.h"

EntryList N(Entrances) = {
    [kpa_51_ENTRY_0]    { -470.0,    0.0,  -28.0,   90.0 },
    [kpa_51_ENTRY_1]    {  745.0,    0.0,  -28.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_51 },
};
