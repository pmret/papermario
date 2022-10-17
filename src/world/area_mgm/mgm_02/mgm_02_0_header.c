#include "mgm_02.h"

EntryList N(Entrances) = {
    [mgm_02_ENTRY_0]    { -300.0,  200.0,  200.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_mgm_02 },
};
