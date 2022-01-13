#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_iwa_iwa_01b

EvtSource N(beforeBattle_80221510) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetGroupEnabled, 13, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_80221544) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80221554)[] = {
    0x00000017, 0x00000018, 0x00000000,
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
