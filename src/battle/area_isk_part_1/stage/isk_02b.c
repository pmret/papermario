#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_02b

EvtSource N(beforeBattle_80223D90) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(EnableModel, 7, 0)
    EVT_CALL(EnableModel, 8, 0)
    EVT_CALL(EnableModel, 9, 0)
    EVT_CALL(EnableModel, 15, 0)
    EVT_CALL(EnableModel, 16, 0)
    EVT_CALL(EnableModel, 17, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_80223E44) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80223E54)[] = {
    0x0000001F, 0x0000001E, 0x00000021, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt02_shape",
    .hit = "isk_bt02_hit",
    .preBattle = N(beforeBattle_80223D90),
    .postBattle = N(afterBattle_80223E44),
    .foregroundModelList = N(foregroundModelList_80223E54),
};
