#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/sam_bt01_shape.h"

#define NAMESPACE A(sam_01)

#include "battle/common/stage/lib/Snowflakes.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_EXEC(N(EVS_SpawnSnowfall))
    EVT_THREAD
        EVT_SET(LVar0, MODEL_o262)
        EVT_SET(LVar1, 1)
        EVT_EXEC(N(EVS_AnimateHangingSnowflake_RandomSpin))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_o261)
        EVT_SET(LVar1, 3)
        EVT_EXEC(N(EVS_AnimateHangingSnowflake_RandomSpin))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_o260)
        EVT_SET(LVar1, 4)
        EVT_EXEC(N(EVS_AnimateHangingSnowflake_RandomSpin))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_o253)
        EVT_SET(LVar1, 2)
        EVT_EXEC(N(EVS_AnimateHangingSnowflake_RandomSpin))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    -1,
    MODEL_saku,
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
