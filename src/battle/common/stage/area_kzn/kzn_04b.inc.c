#include "battle/battle.h"
#include "mapfs/kzn_bt04_shape.h"

#define NAMESPACE A(kzn_04b)

#include "./Decorations.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(SetGroupVisibility, MODEL_06, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_16, MODEL_GROUP_HIDDEN)
    Set(LVar0, MODEL_y2_1)
    Set(LVar1, TEX_PANNER_0)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_y2_2)
    Set(LVar1, TEX_PANNER_1)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_y3_1)
    Set(LVar1, TEX_PANNER_2)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_y3_2)
    Set(LVar1, TEX_PANNER_3)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_yougan)
    Set(LVar1, TEX_PANNER_4)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_y1_1)
    Set(LVar1, TEX_PANNER_5)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_y1_2)
    Set(LVar1, TEX_PANNER_6)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_tri)
    Set(LVar1, TEX_PANNER_7)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_awa1)
    Set(LVar1, TEX_PANNER_8)
    Exec(N(EVS_TexAnim_LavaBubble))
    Set(LVar0, MODEL_awa2)
    Set(LVar1, TEX_PANNER_9)
    Exec(N(EVS_TexAnim_LavaBubble))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
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
