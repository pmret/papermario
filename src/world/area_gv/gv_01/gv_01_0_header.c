#include "gv_01.h"

EntryList N(Entrances) = {
    [gv_01_ENTRY_0]     {    0.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};
