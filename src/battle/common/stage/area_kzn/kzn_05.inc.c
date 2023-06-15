#include "battle/battle.h"
#include "mapfs/kzn_bt05_shape.h"

#define NAMESPACE A(kzn_05)

#include "./Decorations.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, MODEL_yougan2)
    EVT_SET(LVar1, TEX_PANNER_0)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_yougan)
    EVT_SET(LVar1, TEX_PANNER_1)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_awa1)
    EVT_SET(LVar1, TEX_PANNER_2)
    EVT_EXEC(N(EVS_TexAnim_LavaBubble))
    EVT_SET(LVar0, MODEL_awa2)
    EVT_SET(LVar1, TEX_PANNER_3)
    EVT_EXEC(N(EVS_TexAnim_LavaBubble))
    EVT_SET(LVar0, MODEL_awa3)
    EVT_SET(LVar1, TEX_PANNER_4)
    EVT_EXEC(N(EVS_TexAnim_LavaBubble))
    EVT_SET(LVar0, MODEL_awa4)
    EVT_SET(LVar1, TEX_PANNER_5)
    EVT_EXEC(N(EVS_TexAnim_LavaBubble))
    EVT_CALL(EnableModel, MODEL_p00, FALSE)
    EVT_CALL(EnableModel, MODEL_p01, FALSE)
    EVT_CALL(EnableModel, MODEL_p02, FALSE)
    EVT_CALL(EnableModel, MODEL_p03, FALSE)
    EVT_CALL(EnableModel, MODEL_p04, FALSE)
    EVT_CALL(EnableModel, MODEL_p05, FALSE)
    EVT_CALL(EnableModel, MODEL_p06, FALSE)
    EVT_CALL(EnableModel, MODEL_p07, FALSE)
    EVT_CALL(EnableModel, MODEL_p08, FALSE)
    EVT_CALL(EnableModel, MODEL_p09, FALSE)
    EVT_CALL(EnableModel, MODEL_p10, FALSE)
    EVT_CALL(EnableModel, MODEL_p11, FALSE)
    EVT_CALL(EnableModel, MODEL_p12, FALSE)
    EVT_CALL(EnableModel, MODEL_q00, FALSE)
    EVT_CALL(EnableModel, MODEL_q01, FALSE)
    EVT_CALL(EnableModel, MODEL_q02, FALSE)
    EVT_CALL(EnableModel, MODEL_q03, FALSE)
    EVT_CALL(EnableModel, MODEL_q04, FALSE)
    EVT_CALL(EnableModel, MODEL_q05, FALSE)
    EVT_CALL(EnableModel, MODEL_q06, FALSE)
    EVT_CALL(EnableModel, MODEL_q07, FALSE)
    EVT_CALL(EnableModel, MODEL_q08, FALSE)
    EVT_CALL(EnableModel, MODEL_q09, FALSE)
    EVT_CALL(EnableModel, MODEL_q10, FALSE)
    EVT_CALL(EnableModel, MODEL_q11, FALSE)
    EVT_CALL(EnableModel, MODEL_q12, FALSE)
    EVT_CALL(EnableModel, MODEL_r00, FALSE)
    EVT_CALL(EnableModel, MODEL_r01, FALSE)
    EVT_CALL(EnableModel, MODEL_r02, FALSE)
    EVT_CALL(EnableModel, MODEL_r03, FALSE)
    EVT_CALL(EnableModel, MODEL_r04, FALSE)
    EVT_CALL(EnableModel, MODEL_r05, FALSE)
    EVT_CALL(EnableModel, MODEL_r06, FALSE)
    EVT_CALL(EnableModel, MODEL_r07, FALSE)
    EVT_CALL(EnableModel, MODEL_r08, FALSE)
    EVT_CALL(EnableModel, MODEL_r09, FALSE)
    EVT_CALL(EnableModel, MODEL_r10, FALSE)
    EVT_CALL(EnableModel, MODEL_r11, FALSE)
    EVT_CALL(EnableModel, MODEL_r12, FALSE)
    EVT_CALL(EnableModel, MODEL_s01, FALSE)
    EVT_CALL(EnableModel, MODEL_s02, FALSE)
    EVT_CALL(EnableModel, MODEL_s03, FALSE)
    EVT_CALL(EnableModel, MODEL_s04, FALSE)
    EVT_CALL(EnableModel, MODEL_s05, FALSE)
    EVT_CALL(EnableModel, MODEL_s06, FALSE)
    EVT_CALL(EnableModel, MODEL_s07, FALSE)
    EVT_CALL(EnableModel, MODEL_s08, FALSE)
    EVT_CALL(EnableModel, MODEL_s09, FALSE)
    EVT_CALL(EnableModel, MODEL_h01, FALSE)
    EVT_CALL(EnableModel, MODEL_h02, FALSE)
    EVT_CALL(EnableModel, MODEL_h03, FALSE)
    EVT_CALL(EnableModel, MODEL_h04, FALSE)
    EVT_CALL(EnableModel, MODEL_h05, FALSE)
    EVT_CALL(EnableModel, MODEL_h06, FALSE)
    EVT_CALL(EnableModel, MODEL_h07, FALSE)
    EVT_CALL(EnableModel, MODEL_h08, FALSE)
    EVT_CALL(EnableModel, MODEL_h09, FALSE)
    EVT_CALL(EnableModel, MODEL_h10, FALSE)
    EVT_CALL(EnableModel, MODEL_h11, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt05_shape",
    .hit = "kzn_bt05_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
