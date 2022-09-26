#include "kzn_07.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    {  290.0,    0.0,   70.0,  270.0 },  /* kzn_07_ENTRY_0 */
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_07 },
};

//SPLIT for music?

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayUpgradeFanfare) = {
    EVT_CALL(PushSong, SONG_ITEM_UPGRADE, 1)
    EVT_WAIT(130)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};
