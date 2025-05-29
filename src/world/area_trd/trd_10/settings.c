#include "trd_10.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [trd_10_ENTRY_0]    { -310.0,    0.0,    0.0,   90.0 },
    [trd_10_ENTRY_1]    { -225.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_trd_10 },
};

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_DEFEATED_KOOPA_BROS)
            Call(SetMusic, 0, SONG_KOOPA_BROS_THEME, BGM_VARIATION_1, VOL_LEVEL_FULL)
        CaseEq(STORY_CH1_DEFEATED_KOOPA_BROS)
            Call(FadeOutMusic, 0, 500)
        CaseDefault
            Call(SetMusic, 0, SONG_KOOPA_FORTRESS, 0, VOL_LEVEL_FULL)
    EndSwitch
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Return
    End
};
