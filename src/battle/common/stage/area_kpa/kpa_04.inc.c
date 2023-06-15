#include "battle/battle.h"
#include "mapfs/kpa_bt04_shape.h"

#define NAMESPACE A(kpa_04)

// blue torches
EvtScript N(EVS_TexAnim_Fire) = {
    EVT_SET(LVarA, LVar0)
    EVT_CALL(SetTexPanner, LVarA, TEX_PANNER_1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_ADD(LVar0, 0x8000)
        EVT_ADD(LVar1, 0)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetGroupVisibility, MODEL_g3, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_wa, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_kusari, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_g4, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_hi1, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_hi2, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_hi3, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_hi4, MODEL_GROUP_HIDDEN)
    EVT_SET(LVar0, MODEL_o450)
    EVT_EXEC(N(EVS_TexAnim_Fire))
    EVT_SET(LVar0, MODEL_o451)
    EVT_EXEC(N(EVS_TexAnim_Fire))
    EVT_SET(LVar0, MODEL_o454)
    EVT_EXEC(N(EVS_TexAnim_Fire))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt04_shape",
    .hit = "kpa_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
