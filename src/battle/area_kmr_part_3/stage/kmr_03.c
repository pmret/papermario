#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_kmr_03

#include "world/common/clouds.inc.c"

EvtScript N(beforeBattle_802326B8) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_SET(LW(0), 1)
    EVT_SET(LW(2), 0)
    EVT_EXEC(N(clouds1))
    EVT_SET(LW(0), 4)
    EVT_SET(LW(2), 70)
    EVT_EXEC(N(clouds1))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80232730) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80232740)[] = {
    0x00000027, 0x0000002B, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt03_shape",
    .hit = "kmr_bt03_hit",
    .bg = "kmr_bg",
    .preBattle = &N(beforeBattle_802326B8),
    .postBattle = &N(afterBattle_80232730),
    .foregroundModelList = N(foregroundModelList_80232740),
};
