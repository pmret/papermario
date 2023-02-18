#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "mapfs/isk_bt06_shape.h"

#define NAMESPACE b_area_isk_part_1_isk_06b

BSS EffectInstance* N(D_80224DA0);

API_CALLABLE(func_80218B30_4E3270) {
    fx_flame(1, -110.0f, 80.0f, -146.0, 0.3f, &N(D_80224DA0));
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80218B78_4E32B8) {
    remove_effect(N(D_80224DA0));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(func_80218B30_4E3270)
    EVT_CALL(EnableModel, MODEL_kesu, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_CALL(func_80218B78_4E32B8)
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
