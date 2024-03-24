#include "kkj_20.h"

EntryList N(Entrances) = {
    [kkj_20_ENTRY_0]    { -185.0,    0.0,  -25.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kkj_20 },
};
