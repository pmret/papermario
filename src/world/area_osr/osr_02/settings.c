#include "osr_02.h"

s32 N(map_init)(void) {
    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_COMBINED_EPILOGUE;
    return false;
}

EntryList N(Entrances) = {
    [osr_02_ENTRY_0]    { -205.0,    0.0,   55.0,  135.0 },
    [osr_02_ENTRY_1]    {    0.0,   20.0, -290.0,  180.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_osr_02 },
};
