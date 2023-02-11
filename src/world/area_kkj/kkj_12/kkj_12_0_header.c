#include "kkj_12.h"

EntryList N(Entrances) = {
    [kkj_12_ENTRY_0]    {  -75.0,    0.0,    0.0,   90.0 },
    [kkj_12_ENTRY_1]    { 1175.0,  110.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kkj_12 },
};
