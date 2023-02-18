#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_mac_mac_02

EvtScript N(beforeBattle_80232930) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(EnableBattleFloorReflections, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8023297C) = {
    EVT_CALL(EnableBattleFloorReflections, FALSE)
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "mac_tex",
    .shape = "mac_bt02_shape",
    .hit = "mac_bt02_hit",
    .preBattle = &N(beforeBattle_80232930),
    .postBattle = &N(afterBattle_8023297C),
};
