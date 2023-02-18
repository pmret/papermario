#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_nok_nok_04

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    0x0000001B, 0x0000001A, 0x0000001D, 0x0000001C, 0x00000019, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "nok_tex",
    .shape = "nok_bt04_shape",
    .hit = "nok_bt04_hit",
    .bg = "nok_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
