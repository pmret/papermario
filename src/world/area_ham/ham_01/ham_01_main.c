#include "ham_01.h"

extern EvtScript N(EVS_Main);

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TESTING)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Return
    End
};
