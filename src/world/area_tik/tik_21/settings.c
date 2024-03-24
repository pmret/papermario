#include "tik_21.h"

EntryList N(Entrances) = {
    [tik_21_ENTRY_0]    { -325.0,  -20.0,    0.0,   90.0 },
    [tik_21_ENTRY_1]    {  325.0,  -20.0,    0.0,  270.0 },
    [tik_21_ENTRY_2]    {  270.0, -105.0,   93.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_tik_21 },
};
