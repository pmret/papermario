#include "kzn_03.h"
#include "entity.h"

EntryList N(Entrances) = {
    [kzn_03_ENTRY_0]    { -410.0,  870.0,  -65.0,   90.0 },
    [kzn_03_ENTRY_1]    {  435.0,  670.0,  -10.0,  270.0 },
    [kzn_03_ENTRY_2]    {  450.0,  470.0,  220.0,  270.0 },
    [kzn_03_ENTRY_3]    { -425.0,   60.0,  325.0,   90.0 },
    [kzn_03_ENTRY_4]    {  440.0,   20.0,  280.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_03 },
};
