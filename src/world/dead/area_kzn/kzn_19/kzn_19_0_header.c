#include "kzn_19.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [kzn_19_ENTRY_0]    { -435.0,  250.0, -350.0,   90.0 },
    [kzn_19_ENTRY_1]    { -490.0,   25.0,  -30.0,   90.0 },
    [kzn_19_ENTRY_2]    {  440.0,   25.0,  -50.0,  270.0 },
    [kzn_19_ENTRY_3]    {  440.0,   25.0,  -50.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_19 },
};
