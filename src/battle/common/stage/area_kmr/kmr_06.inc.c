#include "battle/battle.h"
#include "mapfs/kmr_bt06_shape.h"

#define NAMESPACE A(kmr_06)

#include "battle/common/stage/lib/MovingClouds.inc.c"

API_CALLABLE(N(SetupFog)) {
    set_world_fog_dist(980, 1000);
    set_world_fog_color(15, 5, 55, 255);
    enable_world_fog();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(N(SetupFog))
    EVT_SET(LVar0, MODEL_g59)
    EVT_SET(LVar2, 0)
    EVT_EXEC(N(EVS_AnimateCloud))
    EVT_SET(LVar0, MODEL_g60)
    EVT_SET(LVar2, 70)
    EVT_EXEC(N(EVS_AnimateCloud))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_n2,
    MODEL_o303,
    MODEL_ha3,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt06_shape",
    .hit = "kmr_bt06_hit",
    .bg = "kmr_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
