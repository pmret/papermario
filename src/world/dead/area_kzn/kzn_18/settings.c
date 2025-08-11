#include "kzn_18.h"

extern EvtScript(N(EVS_Main));

s32 N(get_tattle)(void) {
    if (evt_get_variable(nullptr, GB_StoryProgress) < STORY_CH5_STAR_SPRIT_DEPARTED) {
        return MSG_MapTattle_kzn_18_before;
    } else {
        return MSG_MapTattle_kzn_18_after;
    }
}

EntryList N(Entrances) = {
    [kzn_18_ENTRY_0]    { -405.0,  250.0, -330.0,   90.0 },
    [kzn_18_ENTRY_1]    {  435.0,  250.0, -350.0,  270.0 },
    [kzn_18_ENTRY_2]    {  490.0,   25.0,   -5.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { .get = &N(get_tattle) },
};
