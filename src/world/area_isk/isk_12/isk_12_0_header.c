#include "isk_12.h"

EntryList N(Entrances) = {
    [isk_12_ENTRY_0]    {  434.0, -470.0,  338.0,   29.0 },
    [isk_12_ENTRY_1]    {  472.0, -660.0,  370.0,   29.0 },
    [isk_12_ENTRY_2]    {  512.0, -840.0,  273.0,   27.0 },
    [isk_12_ENTRY_3]    {  580.0, -710.0,   20.0,  191.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_isk_12 },
};
