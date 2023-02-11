#include "kkj_24.h"

EntryList N(Entrances) = {
    [kkj_24_ENTRY_0]    {  145.0,    0.0,  -10.0,  270.0 },
    [kkj_24_ENTRY_1]    {  145.0,  420.0,  -20.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kkj_24 },
};
