#include "kzn_08.h"
#include "model.h"

EntryList N(Entrances) = {
    [kzn_08_ENTRY_0]    { -315.0,    0.0,   85.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_08 },
};
