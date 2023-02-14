#include "kkj_15.h"

EntryList N(Entrances) = {
    [kkj_15_ENTRY_0]    {  225.0,    0.0,  -80.0,  270.0 },
    [kkj_15_ENTRY_1]    {   50.0,   10.0, -150.0,  270.0 },
    [kkj_15_ENTRY_2]    { -237.0,    0.0,   -5.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kkj_15 },
};
