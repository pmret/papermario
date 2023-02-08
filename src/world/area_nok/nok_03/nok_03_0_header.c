#include "nok_03.h"

EntryList N(Entrances) = {
    [nok_03_ENTRY_0]    { -654.0,    0.0,    6.0,   90.0 },
    [nok_03_ENTRY_1]    { 1046.0,    0.0,  -31.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_nok_03 },
};
