#include "mgm_00.h"

EntryList N(Entrances) = {
    [mgm_00_ENTRY_0]    { -152.0,    0.0, -218.0,   90.0 },
    [mgm_00_ENTRY_1]    {  -25.0,   30.0, -168.0,   90.0 },
    [mgm_00_ENTRY_2]    {   95.0,   30.0, -168.0,   90.0 },
    [mgm_00_ENTRY_3]    {  237.0,    0.0,  -53.0,  270.0 },
    [mgm_00_ENTRY_4]    {   20.0,    0.0,  -80.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_mgm_00 },
};
