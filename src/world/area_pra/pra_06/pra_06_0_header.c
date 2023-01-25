#include "pra_06.h"

EntryList N(Entrances) = {
    [pra_06_ENTRY_0]    {   13.0,    0.0,   75.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_pra_06 },
};
