#include "kmr_23.h"

// skip loading shape/hit/tex for this map
s32 N(map_init)(void) {
    return TRUE;
}

EntryList N(Entrances) = {
    [kmr_23_ENTRY_0]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_23_ENTRY_1]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_23_ENTRY_2]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_23_ENTRY_3]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_23_ENTRY_4]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_23_ENTRY_5]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_23_ENTRY_6]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_23_ENTRY_7]    {    0.0,    0.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};
