#include "kmr_04.h"

EntryList N(Entrances) = {
    [kmr_04_ENTRY_0]    {  485.0,    0.0,    9.0,  270.0 },
    [kmr_04_ENTRY_1]    {  198.0,  100.0,  -25.0,  270.0 },
    [kmr_04_ENTRY_2]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_04_ENTRY_3]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_04_ENTRY_4]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_04_ENTRY_5]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_04_ENTRY_6]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_04_ENTRY_7]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_04_ENTRY_8]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_04_ENTRY_9]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_04_ENTRY_A]    {   43.0,    0.0, -376.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kmr_04 },
};
