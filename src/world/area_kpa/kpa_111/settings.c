#include "kpa_111.h"

EntryList N(Entrances) = {
    [kpa_111_ENTRY_0]   { -208.0,    0.0,  105.0,   90.0 },
    [kpa_111_ENTRY_1]   {  300.0,    0.0,   25.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kpa_111 },
};
