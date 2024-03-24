#include "sbk_33.h"
#include "entity.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [sbk_33_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_33_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_33_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_33_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_33 },
};
