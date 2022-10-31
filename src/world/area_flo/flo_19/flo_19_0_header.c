#include "flo_19.h"

EntryList N(Entrances) = {
    [flo_19_ENTRY_0]    {    0.0,    0.0,  100.0,   90.0 },
    [flo_19_ENTRY_1]    {  460.0,    0.0,    0.0,  270.0 },
    [flo_19_ENTRY_2]    {    0.0, -500.0,    0.0,    0.0 },
    [flo_19_ENTRY_3]    {    0.0,    0.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_19 },
};
