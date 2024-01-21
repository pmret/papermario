#include "battle/battle.h"
#include "mapfs/isk_bt06_shape.h"
#include "effects.h"

#define NAMESPACE A(isk_06)

BSS EffectInstance* N(TorchFlame);

API_CALLABLE(N(CreateTorchFX)) {
    fx_flame(FX_FLAME_RED, -110.0f, 80.0f, -146.0f, 0.3f, &N(TorchFlame));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DeleteTorchFX)) {
    remove_effect(N(TorchFlame));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(N(CreateTorchFX))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Call(N(DeleteTorchFX))
    Return
    End
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt06_shape",
    .hit = "isk_bt06_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
