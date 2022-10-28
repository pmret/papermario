#include "kzn_23.h"

EntryList N(Entrances) = {
    [kzn_23_ENTRY_0]    {    0.0,    0.0,  100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};
