#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../obk.h"
#include "obk_09.h"

EntryList N(Entrances) = {
    [obk_09_ENTRY_0]    { -180.0,    0.0,  380.0,    0.0 },
    [obk_09_ENTRY_1]    {  180.0,    0.0,  380.0,    0.0 },
    [obk_09_ENTRY_2]    { -135.0,    0.0,  135.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_obk_09 },
};
