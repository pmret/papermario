#include "tik_17.h"

EntryList N(Entrances) = {
    [tik_17_ENTRY_0]    {  400.0,   20.0,   10.0,  180.0 },
    [tik_17_ENTRY_1]    {  720.0,   65.0,    5.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_17 },
};
