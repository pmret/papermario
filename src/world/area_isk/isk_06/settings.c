#include "isk_06.h"

EntryList N(Entrances) = {
    [isk_06_ENTRY_0]    {  471.0,  -80.0, -290.0,  320.0 },
    [isk_06_ENTRY_1]    {  509.0, -270.0, -318.0,  320.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_06 },
};
