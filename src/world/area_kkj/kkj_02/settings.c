#include "kkj_02.h"

EntryList N(Entrances) = {
    [kkj_02_ENTRY_0]    {  -75.0,    0.0,    0.0,   90.0 },
    [kkj_02_ENTRY_1]    { 1175.0,  110.0,    0.0,  270.0 },
    [kkj_02_ENTRY_2]    {  354.0,    0.0,  294.0,  117.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};
