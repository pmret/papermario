#include "kpa_60.h"

EvtScript N(EVS_SetupMusic) = {
    IfNe(GB_StoryProgress, STORY_CH8_STAR_SHIP_ACTIVATED)
        Call(SetMusicTrack, 0, SONG_BOWSERS_CASTLE, 0, 8)
        Thread
            Wait(30)
        Call(SetMusicTrackVolumes, TRACK_VOLS_KPA_OUTSIDE)
        EndThread
    EndIf
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Return
    End
};
