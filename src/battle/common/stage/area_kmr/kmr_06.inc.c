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
    Call(SetSpriteShading, SHADING_NONE)
    Call(N(SetupFog))
    Set(LVar0, MODEL_g59)
    Set(LVar2, 0)
    Exec(N(EVS_AnimateCloud))
    Set(LVar0, MODEL_g60)
    Set(LVar2, 70)
    Exec(N(EVS_AnimateCloud))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
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
