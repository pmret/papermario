#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/sam_bt01_shape.h"

#define NAMESPACE b_area_sam_sam_01

#include "common/UnkModelStuff.inc.c"

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_EXEC(N(UnkModelStuffScript1))
    EVT_THREAD
        EVT_SET(LVar0, 22)
        EVT_SET(LVar1, 1)
        EVT_EXEC(N(UnkModelStuffScript3))
        EVT_WAIT(5)
        EVT_SET(LVar0, 20)
        EVT_SET(LVar1, 3)
        EVT_EXEC(N(UnkModelStuffScript3))
        EVT_WAIT(5)
        EVT_SET(LVar0, 18)
        EVT_SET(LVar1, 4)
        EVT_EXEC(N(UnkModelStuffScript3))
        EVT_WAIT(5)
        EVT_SET(LVar0, 16)
        EVT_SET(LVar1, 2)
        EVT_EXEC(N(UnkModelStuffScript3))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    -1, MODEL_saku, 0,
};

Stage NAMESPACE = {
    .texture = "sam_tex",
    .shape = "sam_bt01_shape",
    .hit = "sam_bt01_hit",
    .bg = "yki_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
