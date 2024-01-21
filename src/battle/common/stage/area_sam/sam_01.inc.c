#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/sam_bt01_shape.h"

#define NAMESPACE A(sam_01)

#include "battle/common/stage/lib/Snowflakes.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Exec(N(EVS_SpawnSnowfall))
    Thread
        Set(LVar0, MODEL_o262)
        Set(LVar1, 1)
        Exec(N(EVS_AnimateHangingSnowflake_RandomSpin))
        Wait(5)
        Set(LVar0, MODEL_o261)
        Set(LVar1, 3)
        Exec(N(EVS_AnimateHangingSnowflake_RandomSpin))
        Wait(5)
        Set(LVar0, MODEL_o260)
        Set(LVar1, 4)
        Exec(N(EVS_AnimateHangingSnowflake_RandomSpin))
        Wait(5)
        Set(LVar0, MODEL_o253)
        Set(LVar1, 2)
        Exec(N(EVS_AnimateHangingSnowflake_RandomSpin))
    EndThread
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
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
