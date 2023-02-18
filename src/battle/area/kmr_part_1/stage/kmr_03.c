#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_1_kmr_03

#include "world/common/todo/clouds.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar2, 0)
    EVT_EXEC(N(clouds1))
    EVT_SET(LVar0, 4)
    EVT_SET(LVar2, 70)
    EVT_EXEC(N(clouds1))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    0x00000027, 0x0000002B, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt03_shape",
    .hit = "kmr_bt03_hit",
    .bg = "kmr_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
