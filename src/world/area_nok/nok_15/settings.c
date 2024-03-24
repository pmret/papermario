#include "nok_15.h"

EntryList N(Entrances) = {
    [nok_15_ENTRY_0]    { -782.0,    0.0,  -48.0,   90.0 },
    [nok_15_ENTRY_1]    {  -21.0,    0.0, -931.0,  145.0 },
    [nok_15_ENTRY_2]    { -238.0,  200.0, -758.0,  130.0 },
    [nok_15_ENTRY_3]    {  -62.0,   30.0, -430.0,    0.0 },
    [nok_15_ENTRY_4]    { -138.0,  260.0, -638.0,  320.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_nok_15 },
};
