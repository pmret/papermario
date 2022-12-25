#include "obk_06.h"

EntryList N(Entrances) = {
    [obk_06_ENTRY_0]    {    0.0,  200.0,    0.0,    0.0 },
    [obk_06_ENTRY_1]    { -220.0,    0.0,   50.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_obk_06 },
};
