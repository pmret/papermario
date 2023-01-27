#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "mapfs/isk_bt04_shape.h"

#define NAMESPACE b_area_isk_part_2_isk_04

BSS EffectInstance* D_80220740;
BSS EffectInstance* D_80220744;

ApiStatus func_80218850_4EFCF0(Evt* script, s32 isInitialCall) {
    fx_flame(1, -133.0f, 72.0f, -143.0f, 0.3f, &D_80220740);
    fx_flame(1, 129.0f, 72.0f, -143.0f, 0.3f, &D_80220744);
    return ApiStatus_DONE2;
}

ApiStatus func_802188E4_4EFD84(Evt* script, s32 isInitialCall) {
    remove_effect(D_80220740);
    remove_effect(D_80220744);
    return ApiStatus_DONE2;
}

EvtScript N(beforeBattle_80220130) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(func_80218850_4EFCF0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80220178) = {
    EVT_CALL(func_802188E4_4EFD84)
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80220194)[] = {
    MODEL_o500, MODEL_o501, 0,
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt04_shape",
    .hit = "isk_bt04_hit",
    .preBattle = &N(beforeBattle_80220130),
    .postBattle = &N(afterBattle_80220178),
    .foregroundModelList = N(foregroundModelList_80220194),
};
