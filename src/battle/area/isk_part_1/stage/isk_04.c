#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "mapfs/isk_bt04_shape.h"

#define NAMESPACE b_area_isk_part_1_isk_04

BSS EffectInstance* N(D_80224D60);
BSS EffectInstance* N(D_80224D64);

API_CALLABLE(N(CreateTorchFX)) {
    fx_flame(1, -133.0f, 72.0f, -143.0f, 0.3f, &N(D_80224D60));
    fx_flame(1,  129.0f, 72.0f, -143.0f, 0.3f, &N(D_80224D64));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DeleteTorchFX)) {
    remove_effect(N(D_80224D60));
    remove_effect(N(D_80224D64));
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

s32 N(ForegroundModels)[] = {
    MODEL_o500,
    MODEL_o501,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt04_shape",
    .hit = "isk_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
