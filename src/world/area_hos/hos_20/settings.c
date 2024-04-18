#include "hos_20.h"

EntryList N(Entrances) = {
    [hos_20_ENTRY_0]    { -400.0,    0.0,    0.0,  135.0 },
    [hos_20_ENTRY_1]    {    0.0,    0.0,    0.0,  135.0 },
    [hos_20_ENTRY_2]    {  400.0,    0.0,    0.0,  225.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};
