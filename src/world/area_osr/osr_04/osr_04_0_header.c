#include "osr_04.h"

EntryList N(Entrances) = {
    [osr_04_ENTRY_0]    {    0.0,    0.0,  604.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};
