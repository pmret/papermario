#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "mapfs/isk_bt06_shape.h"

#define NAMESPACE b_area_isk_part_2_isk_06b

BSS EffectInstance* D_80220770;

ApiStatus func_80218A60_4EFF00(Evt* script, s32 isInitialCall) {
    fx_flame(1, -110.0f, 80.0f, -146.0f, 0.3f, &D_80220770);
    return ApiStatus_DONE2;
}

ApiStatus func_80218AA8_4EFF48(Evt* script, s32 isInitialCall) {
    remove_effect(D_80220770);
    return ApiStatus_DONE2;
}

EvtScript N(beforeBattle_802202F0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(func_80218A60_4EFF00)
    EVT_CALL(EnableModel, MODEL_kesu, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022034C) = {
    EVT_CALL(func_80218AA8_4EFF48)
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt06_shape",
    .hit = "isk_bt06_hit",
    .preBattle = &N(beforeBattle_802202F0),
    .postBattle = &N(afterBattle_8022034C),
};
