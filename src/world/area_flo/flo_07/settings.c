#include "flo_07.h"

EntryList N(Entrances) = {
    [flo_07_ENTRY_0]    {  375.0,    0.0,    0.0,  270.0 },
    [flo_07_ENTRY_1]    {  325.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_07 },
};
