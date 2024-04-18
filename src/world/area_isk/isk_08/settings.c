#include "isk_08.h"

EntryList N(Entrances) = {
    [isk_08_ENTRY_0]    { -510.0, -390.0,  207.0,  150.0 },
    [isk_08_ENTRY_1]    { -557.0, -520.0,  224.0,  150.0 },
    [isk_08_ENTRY_2]    { -401.0, -390.0,  447.0,  320.0 },
    [isk_08_ENTRY_3]    { -401.0, -520.0,  447.0,  320.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_08 },
};
