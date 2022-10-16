#include "arn_04.h"

EntryList N(Entrances) = {
    [arn_04_ENTRY_0]    { -585.0,   60.0,  150.0,   90.0 },
    [arn_04_ENTRY_1]    {  820.0,  285.0,  150.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_arn_04 },
};
