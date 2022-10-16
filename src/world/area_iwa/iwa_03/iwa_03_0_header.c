#include "iwa_03.h"

EntryList N(Entrances) = {
    [iwa_03_ENTRY_0]    {   14.0,  -18.0,    7.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_iwa_03 },
};
