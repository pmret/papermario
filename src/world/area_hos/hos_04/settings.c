#include "hos_04.h"

EntryList N(Entrances) = {
    [hos_04_ENTRY_0]    { -565.0,    0.0,    0.0,   90.0 },
    [hos_04_ENTRY_1]    {  100.0,  100.0,    0.0,  270.0 },
    [hos_04_ENTRY_2]    {    0.0,    0.0,    0.0,    0.0 },
    [hos_04_ENTRY_3]    { -1570.0,    0.0,    0.0,   90.0 },
    [hos_04_ENTRY_4]    { -1570.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_hos_04 },
};
