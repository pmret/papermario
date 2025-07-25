#include "kmr_30.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MARIOS_HOUSE)
    Call(SetSpriteShading, SHADING_KMR_30)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    Call(EnableWorldStatusBar, false)
    Thread
        Call(FadeOutMusic, 0, 0x00001388)
        Wait(390)
        Call(SetMusic, 0, SONG_THE_END, 0, VOL_LEVEL_FULL)
    EndThread
    Exec(N(EVS_Scene_TheEnd))
    Return
    End
};
