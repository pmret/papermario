#include "kmr_07.h"

EntryList N(Entrances) = {
    [kmr_07_ENTRY_0]    {  -22.0,    0.0,   42.0,   90.0 },
    [kmr_07_ENTRY_1]    {  551.0,   80.0,  -28.0,  245.0 },
    [kmr_07_ENTRY_2]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_07_ENTRY_3]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_07_ENTRY_4]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_07_ENTRY_5]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_07_ENTRY_6]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_07_ENTRY_7]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_07_ENTRY_8]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_07_ENTRY_9]    {    0.0,    0.0,    0.0,    0.0 },
    [kmr_07_ENTRY_A]    {  480.0,    0.0,  110.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_kmr_07 },
};
