#include "mgm_02.h"

#if VERSION_PAL
s32 N(get_tattle)(void) {
    s32 msgID = MSG_MapTattle_mgm_02;
    if (N(pal_variable) != 0) {
        msgID = MSG_NONE;
    }
    return msgID;
}
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
