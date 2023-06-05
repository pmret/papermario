#include "battle/battle.h"
#include "mapfs/jan_bt00_shape.h"
#include "effects.h"

#define NAMESPACE A(jan_00)

#include "battle/common/stage/lib/BeachEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, MODEL_g88)
    EVT_EXEC(N(EVS_AnimatePalmLeaves))
    EVT_SET(LVar0, MODEL_g89)
    EVT_EXEC(N(EVS_AnimatePalmLeaves))
    EVT_SET(LVar0, MODEL_g86)
    EVT_EXEC(N(EVS_AnimateWave))
    EVT_PLAY_EFFECT(EFFECT_SUN, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt00_shape",
    .hit = "jan_bt00_hit",
    .bg = "yos_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
