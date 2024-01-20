#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/sam_bt02_shape.h"

#define NAMESPACE A(sam_02)

#include "battle/common/stage/lib/Snowflakes.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetGroupVisibility, MODEL_p2, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_p3, MODEL_GROUP_HIDDEN)
    Thread
        Set(LVar0, MODEL_o253)
        Set(LVar1, 0)
        Exec(N(EVS_AnimateHangingSnowflake_RandomSpin))
        Wait(5)
        Set(LVar0, MODEL_o283)
        Set(LVar1, 0)
        Exec(N(EVS_AnimateHangingSnowflake_RandomSpin))
        Wait(5)
        Set(LVar0, MODEL_o284)
        Set(LVar1, 0)
        Exec(N(EVS_AnimateHangingSnowflake_RandomSpin))
        Wait(5)
        Set(LVar0, MODEL_o285)
        Set(LVar1, 0)
        Exec(N(EVS_AnimateHangingSnowflake_RandomSpin))
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
    MODEL_kouri1,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "sam_tex",
    .shape = "sam_bt02_shape",
    .hit = "sam_bt02_hit",
    .bg = "yki_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
