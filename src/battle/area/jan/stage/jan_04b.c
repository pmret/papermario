#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan_jan_04b

EvtScript N(beforeBattle_802284F0) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 33, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80228540) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80228550)[] = {
    0x00000025, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt04_shape",
    .hit = "jan_bt04_hit",
    .bg = "jan_bg",
    .preBattle = &N(beforeBattle_802284F0),
    .postBattle = &N(afterBattle_80228540),
    .foregroundModelList = N(foregroundModelList_80228550),
};
