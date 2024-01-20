#include "battle/battle.h"
#include "mapfs/kzn_bt02_shape.h"

#define NAMESPACE A(kzn_02)

#include "./Decorations.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Set(LVar0, MODEL_yougan)
    Set(LVar1, TEX_PANNER_0)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_y1_1)
    Set(LVar1, TEX_PANNER_1)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_y1_2)
    Set(LVar1, TEX_PANNER_2)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_y2_1)
    Set(LVar1, TEX_PANNER_3)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_y2_2)
    Set(LVar1, TEX_PANNER_4)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_y3_1)
    Set(LVar1, TEX_PANNER_5)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_y3_2)
    Set(LVar1, TEX_PANNER_6)
    Exec(N(EVS_TexPan_Lava))
    Set(LVar0, MODEL_move)
    Set(LVar1, 180)
    Set(LVar2, 0)
    Set(LVar3, 200)
    Exec(N(EVS_MovingPlatform))
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
    .shape = "kzn_bt02_shape",
    .hit = "kzn_bt02_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
