#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/sam_bt03_shape.h"

#define NAMESPACE A(sam_03)

#include "battle/common/stage/lib/Snowflakes.inc.c"

void N(EnableBackgroundWave)(void) {
    enable_background_wave();
}

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_THREAD
        EVT_SET(LVar0, MODEL_Default)
        EVT_SET(LVar1, 0)
        EVT_EXEC(N(EVS_AnimateHangingSnowflake_RandomSpin))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_g62)
        EVT_SET(LVar1, 0)
        EVT_EXEC(N(EVS_AnimateHangingSnowflake_NoSpin))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_g60)
        EVT_SET(LVar1, 0)
        EVT_EXEC(N(EVS_AnimateHangingSnowflake_NoSpin))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_g58)
        EVT_SET(LVar1, 0)
        EVT_EXEC(N(EVS_AnimateHangingSnowflake_NoSpin))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_SpawnSnowfall))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    -1,
    MODEL_o278,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "sam_tex",
    .shape = "sam_bt03_shape",
    .hit = "sam_bt03_hit",
    .bg = "sam_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
