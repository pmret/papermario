#include "omo_16.h"

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Call(SetMusicTrack, 0, SONG_TOYBOX_TRAIN, 0, 8)
    ExecWait(N(EVS_802429C4))
    Wait(3)
    Return
    End
};
