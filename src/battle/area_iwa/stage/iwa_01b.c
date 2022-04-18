#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/iwa_bt01_shape.h"

#define NAMESPACE b_area_iwa_iwa_01b

EvtScript N(beforeBattle_80221510) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetGroupEnabled, MODEL_a, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80221544) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80221554)[] = {
    MODEL_iwa1, MODEL_o331, 0,
};

Stage NAMESPACE = {
    .texture = "iwa_tex",
    .shape = "iwa_bt01_shape",
    .hit = "iwa_bt01_hit",
    .bg = "iwa_bg",
    .preBattle = N(beforeBattle_80221510),
    .postBattle = N(afterBattle_80221544),
    .foregroundModelList = N(foregroundModelList_80221554),
};
