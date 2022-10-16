#include "mgm_03.h"

EvtScript N(EVS_Main) = {
    EVT_CALL(SetSpriteShading, SHADING_ARN_09)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_RETURN
    EVT_END
};
