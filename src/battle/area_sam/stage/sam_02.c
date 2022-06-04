#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/sam_bt02_shape.h"

#define NAMESPACE b_area_sam_sam_02

#include "common/UnkModelStuff.inc.c"

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetGroupEnabled, 10, 0)
    EVT_CALL(SetGroupEnabled, 12, 0)
    EVT_THREAD
        EVT_SET(LW(0), 18)
        EVT_SET(LW(1), 0)
        EVT_EXEC(EVT_ADDR(N(UnkModelStuffScript3)))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), 20)
        EVT_SET(LW(1), 0)
        EVT_EXEC(EVT_ADDR(N(UnkModelStuffScript3)))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), 22)
        EVT_SET(LW(1), 0)
        EVT_EXEC(EVT_ADDR(N(UnkModelStuffScript3)))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), 24)
        EVT_SET(LW(1), 0)
        EVT_EXEC(EVT_ADDR(N(UnkModelStuffScript3)))
    EVT_END_THREAD
    EVT_EXEC(EVT_ADDR(N(UnkModelStuffScript1)))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    -1, MODEL_kouri1, 0,
};

Stage NAMESPACE = {
    .texture = "sam_tex",
    .shape = "sam_bt02_shape",
    .hit = "sam_bt02_hit",
    .bg = "yki_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
