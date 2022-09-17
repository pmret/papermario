#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "mapfs/isk_bt06_shape.h"

#define NAMESPACE b_area_isk_part_1_isk_06b

BSS EffectInstance* N(D_80224DA0);

ApiStatus func_80218B30_4E3270(Evt* script, s32 isInitialCall) {
    fx_flame(1, -110.0f, 80.0f, -146.0, 0.3f, &N(D_80224DA0));
    return ApiStatus_DONE2;
}

ApiStatus func_80218B78_4E32B8(Evt* script, s32 isInitialCall) {
    remove_effect(N(D_80224DA0));
    return ApiStatus_DONE2;
}

EvtScript N(beforeBattle_80223F40) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(func_80218B30_4E3270)
    EVT_CALL(EnableModel, MODEL_kesu, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80223F9C) = {
    EVT_CALL(func_80218B78_4E32B8)
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt06_shape",
    .hit = "isk_bt06_hit",
    .preBattle = &N(beforeBattle_80223F40),
    .postBattle = &N(afterBattle_80223F9C),
};
