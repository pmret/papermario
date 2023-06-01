#include "battle/battle.h"
#include "mapfs/mac_bt01_shape.h"

#define NAMESPACE A(mac_01)

#include "battle/common/stage/lib/WaterEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LVar0, MODEL_nami4)
        EVT_EXEC(N(EVS_AnimateWaveModel))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_nami3)
        EVT_EXEC(N(EVS_AnimateWaveModel))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_nami2)
        EVT_EXEC(N(EVS_AnimateWaveModel))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_nami1)
        EVT_EXEC(N(EVS_AnimateWaveModel))
    EVT_END_THREAD
    EVT_SET(LVar0, MODEL_o391)
    EVT_EXEC(N(EVS_AnimateFishModel))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "mac_tex",
    .shape = "mac_bt01_shape",
    .hit = "mac_bt01_hit",
    .bg = "nok_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
