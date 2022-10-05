#include "sbk_02.h"

extern EvtScript N(EVS_Main);

s32 N(get_tattle)(void) {
    s32 tattle;
    if (evt_get_variable(NULL, GB_StoryProgress) > STORY_CH2_GOT_PULSE_STONE) {
        tattle = MSG_MapTattle_sbk_02_after;
    } else {
        tattle = MSG_MapTattle_sbk_02_before;
    }
    return tattle;
}

EntryList N(Entrances) = {
    [sbk_02_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_02_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_02_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_02_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
    [sbk_02_ENTRY_4]    {    0.0,   80.0, -195.0,  180.0 },
    [sbk_02_ENTRY_5]    {   20.0,    0.0,  110.0,  270.0 },
    [sbk_02_ENTRY_6]    {  -80.0,    0.0,   80.0,  180.0 },
    [sbk_02_ENTRY_7]    {   80.0,    0.0,   80.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { &N(get_tattle) },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(sbk_02_ENTRY_6)
        EVT_CASE_OR_EQ(sbk_02_ENTRY_7)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
