#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_sam_01

#include "common/UnkModelStuff.inc.c"

EvtScript N(EVS_PreBattle) = {
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

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    0xFFFFFFFF,
    0x0000001A,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "sam_tex",
    .shape = "sam_bt01_shape",
    .hit = "sam_bt01_hit",
    .bg = "yki_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
