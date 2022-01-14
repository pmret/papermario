#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_arn_arn_03

EvtSource N(beforeBattle_80227A90) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_80227AB0) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80227AC0)[] = {
    0xFFFFFFFF, 0x0000001A, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt03_shape",
    .hit = "arn_bt03_hit",
    .bg = "arn_bg",
    .preBattle = N(beforeBattle_80227A90),
    .postBattle = N(afterBattle_80227AB0),
    .foregroundModelList = N(foregroundModelList_80227AC0),
};
