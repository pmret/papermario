#include "dgb_01.h"

EntryList N(Entrances) = {
    [dgb_01_ENTRY_0]    {    0.0,    0.0,  485.0,    0.0 },
    [dgb_01_ENTRY_1]    { -485.0,    0.0,    0.0,   90.0 },
    [dgb_01_ENTRY_2]    {  485.0,    0.0,    0.0,  270.0 },
    [dgb_01_ENTRY_3]    { -485.0,  210.0,    0.0,   90.0 },
    [dgb_01_ENTRY_4]    {  485.0,  210.0,    0.0,  270.0 },
    [dgb_01_ENTRY_5]    { -485.0,  420.0,    0.0,   90.0 },
    [dgb_01_ENTRY_6]    {  485.0,  420.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_dgb_01 },
};
