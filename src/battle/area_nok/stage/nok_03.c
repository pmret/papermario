#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_nok_nok_03

EvtSource N(beforeBattle_8022BB20) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_8022BB40) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8022BB50)[] = {
    0x0000000E, 0x0000000F, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "nok_tex",
    .shape = "nok_bt03_shape",
    .hit = "nok_bt03_hit",
    .bg = "nok_bg",
    .preBattle = N(beforeBattle_8022BB20),
    .postBattle = N(afterBattle_8022BB40),
    .foregroundModelList = N(foregroundModelList_8022BB50),
};
