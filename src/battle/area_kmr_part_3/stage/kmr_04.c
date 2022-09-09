#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_kmr_04

#include "world/common/clouds.inc.c"

EvtScript N(beforeBattle_80232B08) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_SET(LocalVar(0), 1)
    EVT_SET(LocalVar(2), 0)
    EVT_EXEC(N(clouds1))
    EVT_SET(LocalVar(0), 4)
    EVT_SET(LocalVar(2), 70)
    EVT_EXEC(N(clouds1))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80232B80) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80232B90)[] = {
    0x00000024, 0x00000020, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt04_shape",
    .hit = "kmr_bt04_hit",
    .bg = "kmr_bg",
    .preBattle = &N(beforeBattle_80232B08),
    .postBattle = &N(afterBattle_80232B80),
    .foregroundModelList = N(foregroundModelList_80232B90),
};
