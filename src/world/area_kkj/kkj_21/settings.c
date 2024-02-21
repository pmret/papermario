#include "kkj_21.h"

EntryList N(Entrances) = {
    [kkj_21_ENTRY_0]    {  325.0,    0.0,  -30.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kkj_21 },
};
