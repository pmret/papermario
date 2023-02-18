#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "mapfs/isk_bt04_shape.h"

#define NAMESPACE b_area_isk_part_2_isk_04

BSS EffectInstance* N(FlameEffectL);
BSS EffectInstance* N(FlameEffectR);

API_CALLABLE(N(CreateTorchFlames)) {
    fx_flame(1, -133.0f, 72.0f, -143.0f, 0.3f, &N(FlameEffectL));
    fx_flame(1,  129.0f, 72.0f, -143.0f, 0.3f, &N(FlameEffectR));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DestroyTorchFlames)) {
    remove_effect(N(FlameEffectL));
    remove_effect(N(FlameEffectR));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(N(CreateTorchFlames))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_CALL(N(DestroyTorchFlames))
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_o500,
    MODEL_o501,
    0,
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt04_shape",
    .hit = "isk_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
