#include "pra_28.h"

EntryList N(Entrances) = {
    [pra_28_ENTRY_0]    {   23.0,    0.0,   70.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_pra_28 },
};
