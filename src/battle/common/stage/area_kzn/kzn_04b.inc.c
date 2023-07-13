#include "battle/battle.h"
#include "mapfs/kzn_bt04_shape.h"

#define NAMESPACE A(kzn_04b)

#include "./Decorations.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetGroupVisibility, MODEL_06, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_16, MODEL_GROUP_HIDDEN)
    EVT_SET(LVar0, MODEL_y2_1)
    EVT_SET(LVar1, TEX_PANNER_0)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_y2_2)
    EVT_SET(LVar1, TEX_PANNER_1)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_y3_1)
    EVT_SET(LVar1, TEX_PANNER_2)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_y3_2)
    EVT_SET(LVar1, TEX_PANNER_3)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_yougan)
    EVT_SET(LVar1, TEX_PANNER_4)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_y1_1)
    EVT_SET(LVar1, TEX_PANNER_5)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_y1_2)
    EVT_SET(LVar1, TEX_PANNER_6)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_tri)
    EVT_SET(LVar1, TEX_PANNER_7)
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_SET(LVar0, MODEL_awa1)
    EVT_SET(LVar1, TEX_PANNER_8)
    EVT_EXEC(N(EVS_TexAnim_LavaBubble))
    EVT_SET(LVar0, MODEL_awa2)
    EVT_SET(LVar1, TEX_PANNER_9)
    EVT_EXEC(N(EVS_TexAnim_LavaBubble))
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
    .shape = "kzn_bt04_shape",
    .hit = "kzn_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
