#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/sam_bt02_shape.h"

#define NAMESPACE b_area_sam_sam_02d

#include "battle/common/stage/sam_Snowflakes.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetGroupVisibility, 3, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 10, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 12, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 26, MODEL_GROUP_HIDDEN)
    EVT_EXEC(N(EVS_SpawnSnowfall))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    -1,
    MODEL_kouri1,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "sam_tex",
    .shape = "sam_bt02_shape",
    .hit = "sam_bt02_hit",
    .bg = "yki_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
