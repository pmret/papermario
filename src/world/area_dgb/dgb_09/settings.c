#include "dgb_09.h"

EntryList N(Entrances) = {
    [dgb_09_ENTRY_0]    { -567.0,    0.0,  180.0,   90.0 },
    [dgb_09_ENTRY_1]    {  567.0,    0.0,  180.0,  270.0 },
    [dgb_09_ENTRY_2]    { -450.0,    0.0,   90.0,  180.0 },
    [dgb_09_ENTRY_3]    {  300.0,    0.0,   90.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_09 },
};
