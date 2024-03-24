#include "kkj_19.h"

EntryList N(Entrances) = {
    [kkj_19_ENTRY_0]    {  485.0,    0.0,   25.0,  330.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kkj_19 },
};
