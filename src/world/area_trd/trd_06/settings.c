#include "trd_06.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [trd_06_ENTRY_0]    {    0.0,    0.0,    0.0,    0.0 },
    [trd_06_ENTRY_1]    { -310.0,    0.0,    0.0,   90.0 },
    [trd_06_ENTRY_2]    {    0.0,    0.0,    0.0,    0.0 },
    [trd_06_ENTRY_3]    {    0.0,    0.0,    0.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_trd_06 },
};

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseGe(trd_06_ENTRY_2)
        CaseDefault
            Call(SetMusic, 0, SONG_KOOPA_FORTRESS, 0, VOL_LEVEL_FULL)
    EndSwitch
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Return
    End
};

EvtScript N(EVS_PushSong) = {
    Call(PushSong, SONG_NEW_PARTNER, 0)
    Return
    End
};

EvtScript N(EVS_PopSong) = {
    Call(FadeOutMusic, 0, 500)
    Wait(15)
    Call(PopSong)
    Return
    End
};
