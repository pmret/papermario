#include "battle/battle.h"
#include "mapfs/kzn_bt02_shape.h"

#define NAMESPACE A(kzn_02)

#include "./Decorations.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, MODEL_yougan)
    EVT_SET(LVar1, TEX_PANNER_0)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_y1_1)
    EVT_SET(LVar1, TEX_PANNER_1)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_y1_2)
    EVT_SET(LVar1, TEX_PANNER_2)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_y2_1)
    EVT_SET(LVar1, TEX_PANNER_3)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_y2_2)
    EVT_SET(LVar1, TEX_PANNER_4)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_y3_1)
    EVT_SET(LVar1, TEX_PANNER_5)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_y3_2)
    EVT_SET(LVar1, TEX_PANNER_6)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_move)
    EVT_SET(LVar1, 180)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, 200)
    EVT_EXEC(N(EVS_MovingPlatform))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_iwa3,
    MODEL_sita1,
    MODEL_ue3,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt02_shape",
    .hit = "kzn_bt02_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
