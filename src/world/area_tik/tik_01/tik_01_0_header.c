#include "tik_01.h"

EntryList N(Entrances) = {
    [tik_01_ENTRY_0]    {  320.0,  -10.0,    0.0,  270.0 },
    [tik_01_ENTRY_1]    { -220.0,  -10.0,    0.0,   90.0 },
    [tik_01_ENTRY_2]    {  150.0,   25.0,  -82.0,  180.0 },
    [tik_01_ENTRY_3]    {   50.0,   25.0,  -82.0,  180.0 },
    [tik_01_ENTRY_4]    {  -50.0,   25.0,  -82.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_01 },
};
