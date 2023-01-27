#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_1_kmr_04

#include "world/common/todo/clouds.inc.c"

EvtScript N(beforeBattle_802205D8) = {
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

EvtScript N(afterBattle_80220650) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80220660)[] = {
    0x00000024, 0x00000020, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt04_shape",
    .hit = "kmr_bt04_hit",
    .bg = "kmr_bg",
    .preBattle = &N(beforeBattle_802205D8),
    .postBattle = &N(afterBattle_80220650),
    .foregroundModelList = N(foregroundModelList_80220660),
};
