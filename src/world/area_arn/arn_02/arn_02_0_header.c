#include "arn_02.h"

EntryList N(Entrances) = {
    [arn_02_ENTRY_0]    { -585.0,   60.0,  150.0,   90.0 },
    [arn_02_ENTRY_1]    {  880.0,  320.0,  150.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_arn_02 },
};
