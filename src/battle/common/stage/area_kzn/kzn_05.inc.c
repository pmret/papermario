#include "battle/battle.h"
#include "mapfs/kzn_bt05_shape.h"

#define NAMESPACE A(kzn_05)

#include "./Decorations.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Set(LVar0, MODEL_yougan2)
    Set(LVar1, TEX_PANNER_0)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_yougan)
    Set(LVar1, TEX_PANNER_1)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_awa1)
    Set(LVar1, TEX_PANNER_2)
    Exec(N(EVS_TexAnim_LavaBubble))
    Set(LVar0, MODEL_awa2)
    Set(LVar1, TEX_PANNER_3)
    Exec(N(EVS_TexAnim_LavaBubble))
    Set(LVar0, MODEL_awa3)
    Set(LVar1, TEX_PANNER_4)
    Exec(N(EVS_TexAnim_LavaBubble))
    Set(LVar0, MODEL_awa4)
    Set(LVar1, TEX_PANNER_5)
    Exec(N(EVS_TexAnim_LavaBubble))
    Call(EnableModel, MODEL_p00, false)
    Call(EnableModel, MODEL_p01, false)
    Call(EnableModel, MODEL_p02, false)
    Call(EnableModel, MODEL_p03, false)
    Call(EnableModel, MODEL_p04, false)
    Call(EnableModel, MODEL_p05, false)
    Call(EnableModel, MODEL_p06, false)
    Call(EnableModel, MODEL_p07, false)
    Call(EnableModel, MODEL_p08, false)
    Call(EnableModel, MODEL_p09, false)
    Call(EnableModel, MODEL_p10, false)
    Call(EnableModel, MODEL_p11, false)
    Call(EnableModel, MODEL_p12, false)
    Call(EnableModel, MODEL_q00, false)
    Call(EnableModel, MODEL_q01, false)
    Call(EnableModel, MODEL_q02, false)
    Call(EnableModel, MODEL_q03, false)
    Call(EnableModel, MODEL_q04, false)
    Call(EnableModel, MODEL_q05, false)
    Call(EnableModel, MODEL_q06, false)
    Call(EnableModel, MODEL_q07, false)
    Call(EnableModel, MODEL_q08, false)
    Call(EnableModel, MODEL_q09, false)
    Call(EnableModel, MODEL_q10, false)
    Call(EnableModel, MODEL_q11, false)
    Call(EnableModel, MODEL_q12, false)
    Call(EnableModel, MODEL_r00, false)
    Call(EnableModel, MODEL_r01, false)
    Call(EnableModel, MODEL_r02, false)
    Call(EnableModel, MODEL_r03, false)
    Call(EnableModel, MODEL_r04, false)
    Call(EnableModel, MODEL_r05, false)
    Call(EnableModel, MODEL_r06, false)
    Call(EnableModel, MODEL_r07, false)
    Call(EnableModel, MODEL_r08, false)
    Call(EnableModel, MODEL_r09, false)
    Call(EnableModel, MODEL_r10, false)
    Call(EnableModel, MODEL_r11, false)
    Call(EnableModel, MODEL_r12, false)
    Call(EnableModel, MODEL_s01, false)
    Call(EnableModel, MODEL_s02, false)
    Call(EnableModel, MODEL_s03, false)
    Call(EnableModel, MODEL_s04, false)
    Call(EnableModel, MODEL_s05, false)
    Call(EnableModel, MODEL_s06, false)
    Call(EnableModel, MODEL_s07, false)
    Call(EnableModel, MODEL_s08, false)
    Call(EnableModel, MODEL_s09, false)
    Call(EnableModel, MODEL_h01, false)
    Call(EnableModel, MODEL_h02, false)
    Call(EnableModel, MODEL_h03, false)
    Call(EnableModel, MODEL_h04, false)
    Call(EnableModel, MODEL_h05, false)
    Call(EnableModel, MODEL_h06, false)
    Call(EnableModel, MODEL_h07, false)
    Call(EnableModel, MODEL_h08, false)
    Call(EnableModel, MODEL_h09, false)
    Call(EnableModel, MODEL_h10, false)
    Call(EnableModel, MODEL_h11, false)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt05_shape",
    .hit = "kzn_bt05_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
