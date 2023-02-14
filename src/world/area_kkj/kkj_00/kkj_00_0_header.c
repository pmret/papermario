#include "kkj_00.h"

s32 N(map_init)(void) {
    if (evt_get_variable(NULL, GB_StoryProgress) >= STORY_EPILOGUE) {
        gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_COMBINED_EPILOGUE;
    }
    return FALSE;
}

EntryList N(Entrances) = {
    [kkj_00_ENTRY_0]    {    0.0,    0.0,  480.0,    0.0 },
    [kkj_00_ENTRY_1]    {    0.0,  100.0, -365.0,  180.0 },
    [kkj_00_ENTRY_2]    { -420.0,   40.0, -260.0,  135.0 },
    [kkj_00_ENTRY_3]    {  230.0,    0.0, -210.0,  180.0 },
    [kkj_00_ENTRY_4]    {  420.0,   40.0, -260.0,  225.0 },
    [kkj_00_ENTRY_5]    {    0.0,    0.0,  480.0,    0.0 },
    [kkj_00_ENTRY_6]    {    0.0,    0.0,  480.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};
