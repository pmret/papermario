
#include "jan_00.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [jan_00_ENTRY_0]    {  150.0,    0.0,  200.0,    0.0 },
    [jan_00_ENTRY_1]    {  340.0,    0.0,  340.0,  315.0 },
    [jan_00_ENTRY_2]    {  340.0,    0.0, -340.0,  225.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_jan_00 },
};

EvtScript N(EVS_80241C10) = {
    EVT_CALL(SetMusicTrack, 0, SONG_YOSHIS_VILLAGE, 0, 8)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};
