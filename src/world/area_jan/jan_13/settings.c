#include "jan_13.h"

EntryList N(Entrances) = {
    [jan_13_ENTRY_0]    { -300.0,    0.0,  120.0,    0.0 },
    [jan_13_ENTRY_1]    {   55.0,    0.0, -120.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_jan_13 },
};
