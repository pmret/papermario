#include "mgm_03.h"

EntryList N(Entrances) = {
    [mgm_03_ENTRY_0]    {    0.0,  200.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_mgm_01 },
};
