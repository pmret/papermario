#include "dgb_02.h"

EntryList N(Entrances) = {
    [dgb_02_ENTRY_0]    { -567.0,    0.0,  180.0,   90.0 },
    [dgb_02_ENTRY_1]    {  567.0,    0.0,  180.0,  270.0 },
    [dgb_02_ENTRY_2]    { -450.0,    0.0,   88.0,  180.0 },
    [dgb_02_ENTRY_3]    {  450.0,    0.0,   88.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_02 },
};
