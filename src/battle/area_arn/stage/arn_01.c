#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_arn_arn_01

EvtScript N(beforeBattle_802278F0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80227910) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80227920)[] = {
    0xFFFFFFFF, 0x0000001F, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt01_shape",
    .hit = "arn_bt01_hit",
    .bg = "arn_bg",
    .preBattle = N(beforeBattle_802278F0),
    .postBattle = N(afterBattle_80227910),
    .foregroundModelList = N(foregroundModelList_80227920),
};
