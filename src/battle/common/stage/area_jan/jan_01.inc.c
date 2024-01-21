#include "battle/battle.h"
#include "mapfs/jan_bt01_shape.h"

#define NAMESPACE A(jan_01)

#include "battle/common/stage/lib/BeachEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(SetGroupVisibility, MODEL_g18, MODEL_GROUP_HIDDEN)
    Thread
        Wait(5)
        Set(LVar0, MODEL_o55)
        Exec(N(EVS_AnimateWave))
        Wait(5)
        Set(LVar0, MODEL_o54)
        Exec(N(EVS_AnimateWave))
        Wait(5)
        Set(LVar0, MODEL_o53)
        Exec(N(EVS_AnimateWave))
    EndThread
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    MODEL_o85,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt01_shape",
    .hit = "jan_bt01_hit",
    .bg = "yos_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
