#include "kpa_60.h"

EvtScript N(EVS_SetupMusic) = {
    IfNe(GB_StoryProgress, STORY_CH8_STAR_SHIP_ACTIVATED)
        Call(SetMusic, 0, SONG_BOWSERS_CASTLE, 0, VOL_LEVEL_FULL)
        Thread
            Wait(30)
        Call(SetTrackVolumes, TRACK_VOLS_KPA_OUTSIDE)
        EndThread
    EndIf
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Return
    End
};
