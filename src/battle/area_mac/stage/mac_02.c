#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_mac_mac_02

EvtSource N(beforeBattle_80232930) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(func_802536A8, 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_8023297C) = {
    EVT_CALL(func_802536A8, 0)
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "mac_tex",
    .shape = "mac_bt02_shape",
    .hit = "mac_bt02_hit",
    .preBattle = N(beforeBattle_80232930),
    .postBattle = N(afterBattle_8023297C),
};
