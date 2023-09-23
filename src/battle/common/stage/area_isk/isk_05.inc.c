#include "battle/battle.h"
#include "mapfs/isk_bt05_shape.h"
#include "effects.h"

#define NAMESPACE A(isk_05)

BSS EffectInstance* N(TorchFlameL);
BSS EffectInstance* N(TorchFlameR);

API_CALLABLE(N(CreateTorchFX)) {
    fx_flame(FX_FLAME_RED, -90.0f, 45.0f, -146.0f, 0.25f, &N(TorchFlameL));
    fx_flame(FX_FLAME_RED, 80.0f, 45.0f, -146.0f, 0.25f, &N(TorchFlameR));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DeleteTorchFX)) {
    remove_effect(N(TorchFlameL));
    remove_effect(N(TorchFlameR));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(N(CreateTorchFX))
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
    .shape = "isk_bt05_shape",
    .hit = "isk_bt05_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
