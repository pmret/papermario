#include "kkj_28.h"

EntryList N(Entrances) = {
    [kkj_28_ENTRY_0]    {  325.0,    0.0,  -30.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
#if VERSION_JP
    .tattle = { MSG_MapTattle_018B },
#endif
};
