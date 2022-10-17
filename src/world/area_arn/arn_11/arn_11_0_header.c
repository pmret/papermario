#include "arn_11.h"

EntryList N(Entrances) = {
    [arn_11_ENTRY_0]    { -165.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_arn_11 },
};
