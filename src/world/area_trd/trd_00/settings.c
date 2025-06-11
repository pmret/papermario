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
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_ARRIVED_AT_KOOPA_FORTRESS)
            Call(SetMusic, 0, SONG_KOOPA_FORTRESS, BGM_VARIATION_1, VOL_LEVEL_FULL)
            Call(PlaySound, SOUND_LOOP_TRD_WATER_EXT)
        CaseEq(STORY_CH1_BEGAN_PEACH_MISSION)
            Call(SetMusic, 0, SONG_STAR_SPIRIT_THEME, BGM_VARIATION_1, VOL_LEVEL_FULL)
        CaseDefault
            Call(SetMusic, 0, SONG_PLEASANT_PATH, 0, VOL_LEVEL_FULL)
            Call(PlaySound, SOUND_LOOP_TRD_WATER_EXT)
    EndSwitch
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Return
    End
};
