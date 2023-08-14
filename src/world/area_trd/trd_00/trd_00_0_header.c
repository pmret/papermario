#include "trd_00.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [trd_00_ENTRY_0]    { -973.0,    0.0,  204.0,   90.0 },
    [trd_00_ENTRY_1]    { -525.0,    0.0,  130.0,  240.0 },
    [trd_00_ENTRY_2]    {  400.0,    0.0,  185.0,  180.0 },
    [trd_00_ENTRY_3]    {  587.0,    0.0,    6.0,   90.0 },
    [trd_00_ENTRY_4]    { -955.0,  200.0, -101.0,   90.0 },
    [trd_00_ENTRY_5]    { -518.0,    0.0,  212.0,  240.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_trd_00 },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_ARRIVED_AT_KOOPA_FORTRESS)
            EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_FORTRESS, 1, 8)
            EVT_CALL(PlaySound, SOUND_LOOP_TRD_WATER_EXT)
        EVT_CASE_EQ(STORY_CH1_BEGAN_PEACH_MISSION)
            EVT_CALL(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_PLEASANT_PATH, 0, 8)
            EVT_CALL(PlaySound, SOUND_LOOP_TRD_WATER_EXT)
    EVT_END_SWITCH
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_RETURN
    EVT_END
};
