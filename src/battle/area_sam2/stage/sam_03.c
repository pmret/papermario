#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/sam_bt03_shape.h"

#define NAMESPACE b_area_sam2_sam_03

#include "common/UnkModelStuff.inc.c"

void func_80219E40_63F020(void) {
    enable_background_wave();
}

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_THREAD
        EVT_SET(LW(0), 16)
        EVT_SET(LW(1), 0)
        EVT_EXEC(N(UnkModelStuffScript3))
        EVT_WAIT(5)
        EVT_SET(LW(0), 25)
        EVT_SET(LW(1), 0)
        EVT_EXEC(N(UnkModelStuffScript4))
        EVT_WAIT(5)
        EVT_SET(LW(0), 22)
        EVT_SET(LW(1), 0)
        EVT_EXEC(N(UnkModelStuffScript4))
        EVT_WAIT(5)
        EVT_SET(LW(0), 19)
        EVT_SET(LW(1), 0)
        EVT_EXEC(N(UnkModelStuffScript4))
    EVT_END_THREAD
    EVT_EXEC(N(UnkModelStuffScript1))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    -1, MODEL_o278, 0,
};

Stage NAMESPACE = {
    .texture = "sam_tex",
    .shape = "sam_bt03_shape",
    .hit = "sam_bt03_hit",
    .bg = "sam_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
