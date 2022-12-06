#include "isk_05.h"

EntryList N(Entrances) = {
    [isk_05_ENTRY_0]    {  463.0,   25.0, -279.0,  320.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_05 },
};
