#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_nok_nok_04

EvtSource N(beforeBattle_8022BB90) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_8022BBB0) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8022BBC0)[] = {
    0x0000001B, 0x0000001A, 0x0000001D, 0x0000001C, 0x00000019, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "nok_tex",
    .shape = "nok_bt04_shape",
    .hit = "nok_bt04_hit",
    .bg = "nok_bg",
    .preBattle = N(beforeBattle_8022BB90),
    .postBattle = N(afterBattle_8022BBB0),
    .foregroundModelList = N(foregroundModelList_8022BBC0),
};
