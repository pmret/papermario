#include "nok_13.h"

EntryList N(Entrances) = {
    [nok_13_ENTRY_0]    { -488.0,  150.0,    0.0,   90.0 },
    [nok_13_ENTRY_1]    {  165.0,    0.0, -483.0,  180.0 },
    [nok_13_ENTRY_2]    {  277.0,  150.0,  210.0,  315.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_nok_13 },
};
