#include "battle/battle.h"
#include "mapfs/jan_bt00_shape.h"
#include "effects.h"

#define NAMESPACE A(jan_00)

#include "battle/common/stage/lib/BeachEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Set(LVar0, MODEL_g88)
    Exec(N(EVS_AnimatePalmLeaves))
    Set(LVar0, MODEL_g89)
    Exec(N(EVS_AnimatePalmLeaves))
    Set(LVar0, MODEL_g86)
    Exec(N(EVS_AnimateWave))
    PlayEffect(EFFECT_SUN, 0, 0, 0, 0, 0, 0, 0)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt00_shape",
    .hit = "jan_bt00_hit",
    .bg = "yos_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
