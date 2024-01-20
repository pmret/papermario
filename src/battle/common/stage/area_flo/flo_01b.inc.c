#include "battle/battle.h"
#include "mapfs/flo_bt01_shape.h"
#include "effects.h"

#define NAMESPACE A(flo_01b)

#include "battle/common/stage/lib/RandomFlowers.inc.c"
#include "common/MakeSun.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(SetGroupVisibility, MODEL_dai_03, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_dai_04, MODEL_GROUP_VISIBLE)
    Call(SetGroupVisibility, MODEL_dai_05, MODEL_GROUP_HIDDEN)
    Exec(N(EVS_RandomFlowers_Background))
    ExecWait(N(MakeSun))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    -1,
    MODEL_kuki,
    MODEL_hana1,
    MODEL_mae1,
    MODEL_mae2,
    MODEL_mae3,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "flo_tex",
    .shape = "flo_bt01_shape",
    .hit = "flo_bt01_hit",
    .bg = "fla_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
