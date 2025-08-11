#include "osr_03.h"

s32 N(map_init)(void) {
    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_COMBINED_EPILOGUE;
    return false;
}

EntryList N(Entrances) = {
    [osr_03_ENTRY_0]    {    0.0,    0.0,  604.0,    0.0 },
    [osr_03_ENTRY_1]    {    0.0,    0.0,    0.0,  270.0 },
    [osr_03_ENTRY_2]    {    0.0,    0.0,  290.0,  180.0 },
    [osr_03_ENTRY_3]    {    0.0,  -50.0,    0.0,  180.0 },
    [osr_03_ENTRY_4]    {    0.0,    0.0,    0.0,  180.0 },
    [osr_03_ENTRY_5]    {    0.0,  -50.0,    0.0,  180.0 },
    [osr_03_ENTRY_6]    {    0.0,    0.0, -290.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};
