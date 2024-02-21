#include "jan_02.h"

EntryList N(Entrances) = {
    [jan_02_ENTRY_0]    { -450.0,    0.0, -450.0,  135.0 },
    [jan_02_ENTRY_1]    {  640.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_jan_02 },
};
