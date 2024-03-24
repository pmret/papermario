#include "kmr_22.h"

s32 N(map_init)(void) {
    return TRUE;
}

EntryList N(Entrances) = {
    [kmr_22_ENTRY_0]    {    0.0,    0.0,    0.0,   90.0 },
    [kmr_22_ENTRY_1]    {    0.0,    0.0,    0.0,   90.0 },
    [kmr_22_ENTRY_2]    {    0.0,    0.0,    0.0,   90.0 },
    [kmr_22_ENTRY_3]    {    0.0,    0.0,    0.0,   90.0 },
    [kmr_22_ENTRY_4]    {    0.0,    0.0,    0.0,   90.0 },
    [kmr_22_ENTRY_5]    {    0.0,    0.0,    0.0,   90.0 },
    [kmr_22_ENTRY_6]    {    0.0,    0.0,    0.0,   90.0 },
    [kmr_22_ENTRY_7]    {    0.0,    0.0,    0.0,   90.0 },
    [kmr_22_ENTRY_8]    {    0.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};
