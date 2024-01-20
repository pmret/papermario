#include "battle/battle.h"
#include "mapfs/kpa_bt04_shape.h"

#define NAMESPACE A(kpa_04b)

// blue torches
EvtScript N(EVS_TexAnim_Fire) = {
    Set(LVarA, LVar0)
    Call(SetTexPanner, LVarA, TEX_PANNER_1)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Loop(0)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, LVar1)
        Add(LVar0, 0x8000)
        Add(LVar1, 0)
        Wait(5)
    EndLoop
    Return
    End
};

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(SetGroupVisibility, MODEL_g2, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_wa, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_kusari, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_hi1, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_hi2, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_hi3, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_hi4, MODEL_GROUP_HIDDEN)
    Set(LVar0, MODEL_o450)
    Exec(N(EVS_TexAnim_Fire))
    Set(LVar0, MODEL_o451)
    Exec(N(EVS_TexAnim_Fire))
    Set(LVar0, MODEL_o454)
    Exec(N(EVS_TexAnim_Fire))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt04_shape",
    .hit = "kpa_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
