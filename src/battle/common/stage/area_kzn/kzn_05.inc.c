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
    Call(EnableModel, MODEL_p00, FALSE)
    Call(EnableModel, MODEL_p01, FALSE)
    Call(EnableModel, MODEL_p02, FALSE)
    Call(EnableModel, MODEL_p03, FALSE)
    Call(EnableModel, MODEL_p04, FALSE)
    Call(EnableModel, MODEL_p05, FALSE)
    Call(EnableModel, MODEL_p06, FALSE)
    Call(EnableModel, MODEL_p07, FALSE)
    Call(EnableModel, MODEL_p08, FALSE)
    Call(EnableModel, MODEL_p09, FALSE)
    Call(EnableModel, MODEL_p10, FALSE)
    Call(EnableModel, MODEL_p11, FALSE)
    Call(EnableModel, MODEL_p12, FALSE)
    Call(EnableModel, MODEL_q00, FALSE)
    Call(EnableModel, MODEL_q01, FALSE)
    Call(EnableModel, MODEL_q02, FALSE)
    Call(EnableModel, MODEL_q03, FALSE)
    Call(EnableModel, MODEL_q04, FALSE)
    Call(EnableModel, MODEL_q05, FALSE)
    Call(EnableModel, MODEL_q06, FALSE)
    Call(EnableModel, MODEL_q07, FALSE)
    Call(EnableModel, MODEL_q08, FALSE)
    Call(EnableModel, MODEL_q09, FALSE)
    Call(EnableModel, MODEL_q10, FALSE)
    Call(EnableModel, MODEL_q11, FALSE)
    Call(EnableModel, MODEL_q12, FALSE)
    Call(EnableModel, MODEL_r00, FALSE)
    Call(EnableModel, MODEL_r01, FALSE)
    Call(EnableModel, MODEL_r02, FALSE)
    Call(EnableModel, MODEL_r03, FALSE)
    Call(EnableModel, MODEL_r04, FALSE)
    Call(EnableModel, MODEL_r05, FALSE)
    Call(EnableModel, MODEL_r06, FALSE)
    Call(EnableModel, MODEL_r07, FALSE)
    Call(EnableModel, MODEL_r08, FALSE)
    Call(EnableModel, MODEL_r09, FALSE)
    Call(EnableModel, MODEL_r10, FALSE)
    Call(EnableModel, MODEL_r11, FALSE)
    Call(EnableModel, MODEL_r12, FALSE)
    Call(EnableModel, MODEL_s01, FALSE)
    Call(EnableModel, MODEL_s02, FALSE)
    Call(EnableModel, MODEL_s03, FALSE)
    Call(EnableModel, MODEL_s04, FALSE)
    Call(EnableModel, MODEL_s05, FALSE)
    Call(EnableModel, MODEL_s06, FALSE)
    Call(EnableModel, MODEL_s07, FALSE)
    Call(EnableModel, MODEL_s08, FALSE)
    Call(EnableModel, MODEL_s09, FALSE)
    Call(EnableModel, MODEL_h01, FALSE)
    Call(EnableModel, MODEL_h02, FALSE)
    Call(EnableModel, MODEL_h03, FALSE)
    Call(EnableModel, MODEL_h04, FALSE)
    Call(EnableModel, MODEL_h05, FALSE)
    Call(EnableModel, MODEL_h06, FALSE)
    Call(EnableModel, MODEL_h07, FALSE)
    Call(EnableModel, MODEL_h08, FALSE)
    Call(EnableModel, MODEL_h09, FALSE)
    Call(EnableModel, MODEL_h10, FALSE)
    Call(EnableModel, MODEL_h11, FALSE)
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
