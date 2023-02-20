#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kzn_kzn_01b

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    0x0000000E,
    0x0000000F,
    0x00000018,
    0x00000019,
    0x0000001A,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt01_shape",
    .hit = "kzn_bt01_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
