#include "omo_16.h"

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    Call(SetMusic, 0, SONG_TOYBOX_TRAIN, 0, VOL_LEVEL_FULL)
    ExecWait(N(EVS_802429C4))
    Wait(3)
    Return
    End
};
