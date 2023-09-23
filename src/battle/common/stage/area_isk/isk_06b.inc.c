#include "battle/battle.h"
#include "mapfs/isk_bt06_shape.h"
#include "effects.h"

#define NAMESPACE A(isk_06b)

BSS EffectInstance* N(TorchFlame);

API_CALLABLE(N(CreateTorchFX)) {
    fx_flame(FX_FLAME_RED, -110.0f, 80.0f, -146.0, 0.3f, &N(TorchFlame));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DeleteTorchFX)) {
    remove_effect(N(TorchFlame));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(N(CreateTorchFX))
    EVT_CALL(EnableModel, MODEL_kesu, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_CALL(N(DeleteTorchFX))
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt06_shape",
    .hit = "isk_bt06_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
