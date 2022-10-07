#include "trd_09.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [trd_09_ENTRY_0]    { -565.0,   60.0,   10.0,   90.0 },
    [trd_09_ENTRY_1]    { 1515.0,   60.0,    0.0,  270.0 },
    [trd_09_ENTRY_2]    { -340.0,    0.0,   50.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_trd_09 },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH1_KOOPA_BROS_FIRING_BLASTERS)
        EVT_IF_EQ(GF_TRD09_Defeated_BillBlasters, FALSE)
            EVT_CALL(SetMusicTrack, 0, SONG_BULLET_BILL_ASSAULT, 0, 8)
        EVT_ELSE
            EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_FORTRESS, 0, 8)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_FORTRESS, 0, 8)
    EVT_END_IF
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_RETURN
    EVT_END
};
