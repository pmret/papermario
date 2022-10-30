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
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GE(trd_06_ENTRY_2)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_FORTRESS, 0, 8)
    EVT_END_SWITCH
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushSong) = {
    EVT_CALL(PushSong, SONG_NEW_PARTNER, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PopSong) = {
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_WAIT(15)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};
