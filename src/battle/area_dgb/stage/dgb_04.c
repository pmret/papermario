#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_dgb_dgb_04

EvtScript N(beforeBattle_8021B170) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021B190) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8021B1A0)[] = {
    0x00000012, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "dgb_tex",
    .shape = "dgb_bt04_shape",
    .hit = "dgb_bt04_hit",
    .preBattle = N(beforeBattle_8021B170),
    .postBattle = N(afterBattle_8021B190),
    .foregroundModelList = N(foregroundModelList_8021B1A0),
};
