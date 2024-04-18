#include "kpa_14.h"

s32 N(get_tattle)(void) {
    if (!evt_get_variable(NULL, GF_KPA16_ShutOffLava)) {
        return MSG_MapTattle_kpa_14_before;
    } else {
        return MSG_MapTattle_kpa_14_after;
    }
}

EntryList N(Entrances) = {
    [kpa_14_ENTRY_0]    {   30.0,   30.0, -150.0,   90.0 },
    [kpa_14_ENTRY_1]    { 1990.0,   30.0, -150.0,  270.0 },
    [kpa_14_ENTRY_2]    { 1776.0,    0.0, -187.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { .get = &N(get_tattle) },
};
