#include "pra_39.h"

EntryList N(Entrances) = {
    [pra_39_ENTRY_0]    {   13.0,    0.0,   70.0,   90.0 },
    [pra_39_ENTRY_1]    {  487.0,    0.0,   70.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_pra_39 },
};
