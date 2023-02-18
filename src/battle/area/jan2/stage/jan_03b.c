#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan2_jan_03b

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetGroupVisibility, 66, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    0x00000040, 0x0000003F, 0x0000003E, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt03_shape",
    .hit = "jan_bt03_hit",
    .bg = "jan_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
