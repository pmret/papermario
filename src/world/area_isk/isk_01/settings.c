#include "isk_01.h"

EntryList N(Entrances) = {
    [isk_01_ENTRY_0]    { -576.0,    0.0,  -71.0,  179.0 },
    [isk_01_ENTRY_1]    { -555.0,    0.0,  170.0,  350.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_isk_01 },
};
