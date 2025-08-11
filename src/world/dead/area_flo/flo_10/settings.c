#include "flo_10.h"

s32 N(get_tattle)(void) {
    if (evt_get_variable(nullptr, GB_StoryProgress) < STORY_CH6_FILLED_SPRING_WITH_WATER) {
        return MSG_MapTattle_flo_10_before;
    } else {
        return MSG_MapTattle_flo_10_after;
    }
}

EntryList N(Entrances) = {
    [flo_10_ENTRY_0]    { -360.0,    0.0,    0.0,   90.0 },
    [flo_10_ENTRY_1]    { -360.0,    0.0,    0.0,   90.0 },
    [flo_10_ENTRY_2]    { -100.0,  -10.0, -172.0,  135.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { .get = &N(get_tattle) },
};
