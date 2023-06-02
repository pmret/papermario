#include "battle/battle.h"
#include "mapfs/tik_bt04_shape.h"

#define NAMESPACE A(tik_04)

#include "battle/common/stage/lib/WaterEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LVar0, MODEL_mizu2)
        EVT_EXEC(N(EVS_AnimateWaveModel))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_mizu3)
        EVT_EXEC(N(EVS_AnimateWaveModel))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_mizu4)
        EVT_EXEC(N(EVS_AnimateWaveModel))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_o357)
        EVT_SET(LVar1, 145)
        EVT_EXEC(N(EVS_AnimateDrifting))
        EVT_SET(LVar0, MODEL_o361)
        EVT_SET(LVar1, 145)
        EVT_EXEC(N(EVS_AnimateDrifting))
    EVT_END_THREAD
    EVT_SET(LVar0, MODEL_o358)
    EVT_SET(LVar1, 60)
    EVT_EXEC(N(EVS_AnimateDrifting))
    EVT_SET(LVar0, MODEL_o360)
    EVT_SET(LVar1, 60)
    EVT_EXEC(N(EVS_AnimateDrifting))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "tik_tex",
    .shape = "tik_bt04_shape",
    .hit = "tik_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};


