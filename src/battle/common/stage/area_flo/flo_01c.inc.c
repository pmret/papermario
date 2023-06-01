#include "battle/battle.h"
#include "mapfs/flo_bt01_shape.h"
#include "effects.h"

#define NAMESPACE A(flo_01c)

#include "battle/common/stage/lib/RandomFlowers.inc.c"
#include "common/MakeSun.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetGroupVisibility, MODEL_dai_03, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_dai_04, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_dai_05, MODEL_GROUP_VISIBLE)
    EVT_EXEC(N(EVS_RandomFlowers_Background))
    EVT_EXEC(N(EVS_RandomFlowers_Foreground))
    EVT_EXEC_WAIT(N(MakeSun))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    -1,
    MODEL_o381,
    MODEL_o382,
    MODEL_o388,
    MODEL_o389,
    MODEL_o390,
    MODEL_o383,
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
