#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/sam_bt03_shape.h"

#define NAMESPACE A(sam_03)

#include "battle/common/stage/lib/Snowflakes.inc.c"

void N(EnableBackgroundWave)(void) {
    enable_background_wave();
}

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Thread
        Set(LVar0, MODEL_Default)
        Set(LVar1, 0)
        Exec(N(EVS_AnimateHangingSnowflake_RandomSpin))
        Wait(5)
        Set(LVar0, MODEL_g62)
        Set(LVar1, 0)
        Exec(N(EVS_AnimateHangingSnowflake_NoSpin))
        Wait(5)
        Set(LVar0, MODEL_g60)
        Set(LVar1, 0)
        Exec(N(EVS_AnimateHangingSnowflake_NoSpin))
        Wait(5)
        Set(LVar0, MODEL_g58)
        Set(LVar1, 0)
        Exec(N(EVS_AnimateHangingSnowflake_NoSpin))
    EndThread
    Exec(N(EVS_SpawnSnowfall))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
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
