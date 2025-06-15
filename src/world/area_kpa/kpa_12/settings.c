#include "kpa_12.h"

s32 N(get_tattle)(void) {
    if (!evt_get_variable(nullptr, GF_KPA16_ShutOffLava)) {
        return MSG_MapTattle_kpa_12_before;
    } else {
        return MSG_MapTattle_kpa_12_after;
    }
}

EntryList N(Entrances) = {
    [kpa_12_ENTRY_0]    {   30.0,   30.0, -150.0,   90.0 },
    [kpa_12_ENTRY_1]    { 1470.0,   30.0, -150.0,  270.0 },
    [kpa_12_ENTRY_2]    {   17.0,  -20.0,  -17.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { .get = &N(get_tattle) },
};
