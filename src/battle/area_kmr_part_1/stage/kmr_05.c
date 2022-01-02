#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_1_kmr_05

#include "world/common/clouds.inc.c"

EvtSource N(beforeBattle_80220A28) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(EnableModel, 27, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_80220A5C) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80220A6C)[] = {
    0x00000020, 0x00000024, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt05_shape",
    .hit = "kmr_bt05_hit",
    .bg = "kmr_bg",
    .preBattle = N(beforeBattle_80220A28),
    .postBattle = N(afterBattle_80220A5C),
    .foregroundModelList = N(foregroundModelList_80220A6C),
};
