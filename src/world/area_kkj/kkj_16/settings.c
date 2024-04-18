#include "kkj_16.h"

EntryList N(Entrances) = {
    [kkj_16_ENTRY_0]    {  435.0,    0.0,  -25.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kkj_16 },
};
