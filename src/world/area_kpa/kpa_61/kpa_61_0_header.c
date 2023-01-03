#include "kpa_61.h"

EntryList N(Entrances) = {
    [kpa_61_ENTRY_0]    { -100.0, -160.0,  116.0,  120.0 },
    [kpa_61_ENTRY_1]    { -100.0,  200.0,  102.0,  120.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kpa_61 },
};
