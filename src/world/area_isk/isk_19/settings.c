#include "isk_19.h"

EntryList N(Entrances) = {
    [isk_19_ENTRY_0]    {  548.0, -910.0,  182.0,   21.0 },
    [isk_19_ENTRY_1]    {  573.0, -910.0,   21.0,  186.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_19 },
};
