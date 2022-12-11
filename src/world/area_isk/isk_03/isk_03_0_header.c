#include "isk_03.h"

EntryList N(Entrances) = {
    [isk_03_ENTRY_0]    {  369.0,   50.0,  408.0,   59.0 },
    [isk_03_ENTRY_1]    {  401.0, -140.0,  447.0,   59.0 },
    [isk_03_ENTRY_2]    {  557.0, -155.0,  224.0,  209.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_03 },
};
