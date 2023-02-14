#include "kkj_27.h"

EntryList N(Entrances) = {
    [kkj_27_ENTRY_0]    {  425.0,    0.0,   40.0,    0.0 },
    [kkj_27_ENTRY_1]    { -250.0,   10.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};
