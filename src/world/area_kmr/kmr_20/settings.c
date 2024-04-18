#include "kmr_20.h"

EntryList N(Entrances) = {
    [kmr_20_ENTRY_0]    {  240.0,   30.0,  -80.0,   90.0 },
    [kmr_20_ENTRY_1]    {  240.0,   30.0,  -70.0,   90.0 },
    [kmr_20_ENTRY_2]    {  100.0,   44.0,  -40.0,   90.0 },
    [kmr_20_ENTRY_3]    {  100.0,   44.0,  -40.0,   90.0 },
    [kmr_20_ENTRY_4]    {  594.0,   30.0, -216.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kmr_20 },
};
