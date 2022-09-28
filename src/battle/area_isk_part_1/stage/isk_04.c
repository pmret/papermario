#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "mapfs/isk_bt04_shape.h"

#define NAMESPACE b_area_isk_part_1_isk_04

BSS EffectInstance* N(D_80224D60);
BSS EffectInstance* N(D_80224D64);

ApiStatus N(CreateTorchFX)(Evt* script, s32 isInitialCall) {
    fx_flame(1, -133.0f, 72.0f, -143.0f, 0.3f, &N(D_80224D60));
    fx_flame(1,  129.0f, 72.0f, -143.0f, 0.3f, &N(D_80224D64));
    return ApiStatus_DONE2;
}

ApiStatus N(DeleteTorchFX)(Evt* script, s32 isInitialCall) {
    remove_effect(N(D_80224D60));
    remove_effect(N(D_80224D64));
    return ApiStatus_DONE2;
}

EvtScript N(beforeBattle_80223AC0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(N(CreateTorchFX))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80223B08) = {
    EVT_CALL(N(DeleteTorchFX))
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80223B24)[] = {
    MODEL_o500, MODEL_o501, 0,
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt04_shape",
    .hit = "isk_bt04_hit",
    .preBattle = &N(beforeBattle_80223AC0),
    .postBattle = &N(afterBattle_80223B08),
    .foregroundModelList = N(foregroundModelList_80223B24),
};
