#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kzn2_kzn_01

EvtScript N(beforeBattle_80227780) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 17, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_802277D0) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_802277E0)[] = {
    0x0000000E, 0x0000000F, 0x00000018, 0x00000019, 0x0000001A, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt01_shape",
    .hit = "kzn_bt01_hit",
    .preBattle = &N(beforeBattle_80227780),
    .postBattle = &N(afterBattle_802277D0),
    .foregroundModelList = N(foregroundModelList_802277E0),
};
