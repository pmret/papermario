#include "kzn_07.h"

EntryList N(Entrances) = {
    [kzn_07_ENTRY_0]    {  290.0,    0.0,   70.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_07 },
};
