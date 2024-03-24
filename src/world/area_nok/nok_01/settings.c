#include "nok_01.h"

EntryList N(Entrances) = {
    [nok_01_ENTRY_0]    { -333.0,    0.0,  350.0,   45.0 },
    [nok_01_ENTRY_1]    {  470.0,    0.0,   10.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_nok_01 },
};
