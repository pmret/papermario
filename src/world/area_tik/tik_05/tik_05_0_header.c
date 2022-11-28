#include "tik_05.h"

EntryList N(Entrances) = {
    [tik_05_ENTRY_0]    {  320.0,  -10.0,    0.0,  270.0 },
    [tik_05_ENTRY_1]    {  100.0,   25.0,  -82.0,  180.0 },
    [tik_05_ENTRY_2]    {  185.0,   25.0,  -82.0,  180.0 },
    [tik_05_ENTRY_3]    {  270.0,   25.0,  -82.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_05 },
};
