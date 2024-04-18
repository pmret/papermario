#include "kpa_62.h"

EntryList N(Entrances) = {
    [kpa_62_ENTRY_0]    { -191.0,    0.0, -135.0,  180.0 },
    [kpa_62_ENTRY_1]    {  276.0,    0.0, -305.0,  180.0 },
    [kpa_62_ENTRY_2]    {  386.0,  -45.0, -231.0,  180.0 },
    [kpa_62_ENTRY_3]    {   75.0,   21.0,  600.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kpa_62 },
};
