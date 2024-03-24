#include "iwa_11.h"

EntryList N(Entrances) = {
    [iwa_11_ENTRY_0]    {    0.0,    0.0,   15.0,   90.0 },
    [iwa_11_ENTRY_1]    {    0.0,    0.0,   15.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};
