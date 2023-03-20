#include "mgm_02.h"

#if VERSION_PAL
s32 N(get_tattle)(void);
INCLUDE_ASM(void, "world/area_mgm/mgm_02/mgm_02_0_header", mgm_02_get_tattle);
#endif

EntryList N(Entrances) = {
    [mgm_02_ENTRY_0]    { -300.0,  200.0,  200.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
#if VERSION_PAL
    .tattle = { .get = &N(get_tattle) },
#else
    .tattle = { MSG_MapTattle_mgm_02 },
#endif
};
