#include "kpa_15.h"

#if VERSION_JP
s32 N(get_tattle)(void) {
    if (!evt_get_variable(nullptr, GF_KPA16_ShutOffLava)) {
        return MSG_MapTattle_kpa_15_before;
    } else {
        return MSG_MapTattle_kpa_15_after;
    }
}
#endif

EntryList N(Entrances) = {
    [kpa_15_ENTRY_0]    {   12.0,    0.0,  -97.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
#if VERSION_JP
    .tattle = { .get = &N(get_tattle) },
#else
    .tattle = { MSG_MapTattle_kpa_15 },
#endif
};
