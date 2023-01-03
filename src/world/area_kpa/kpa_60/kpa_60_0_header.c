#include "kpa_60.h"

EntryList N(Entrances) = {
    [kpa_60_ENTRY_0]    { -191.0,    0.0, -135.0,  180.0 },
    [kpa_60_ENTRY_1]    {  276.0,    0.0, -305.0,  180.0 },
    [kpa_60_ENTRY_2]    {  386.0,  -25.0, -231.0,  180.0 },
    [kpa_60_ENTRY_3]    {   75.0,   21.0,  600.0,   90.0 },
    [kpa_60_ENTRY_4]    {    0.0, -1000.0,    0.0,    0.0 },
    [kpa_60_ENTRY_5]    {    0.0, -1000.0,    0.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kpa_62 },
};
