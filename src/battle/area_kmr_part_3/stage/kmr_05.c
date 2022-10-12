#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_kmr_05

#include "world/common/todo/clouds.inc.c"

EvtScript N(beforeBattle_80232F58) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(EnableModel, 26, 0)
    EVT_CALL(EnableModel, 29, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80232FA0) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80232FB0)[] = {
    0x00000020, 0x00000024, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt05_shape",
    .hit = "kmr_bt05_hit",
    .bg = "kmr_bg",
    .preBattle = &N(beforeBattle_80232F58),
    .postBattle = &N(afterBattle_80232FA0),
    .foregroundModelList = N(foregroundModelList_80232FB0),
};
