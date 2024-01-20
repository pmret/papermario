#include "battle/battle.h"
#include "mapfs/flo_bt02_shape.h"
#include "effects.h"

#define NAMESPACE A(flo_02b)

#include "battle/common/stage/lib/RandomFlowers.inc.c"
#include "common/MakeSun.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(SetGroupVisibility, MODEL_dai_05, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_0809, MODEL_GROUP_VISIBLE)
    Call(SetGroupVisibility, MODEL_16, MODEL_GROUP_HIDDEN)
    Exec(N(EVS_RandomFlowers_FarBack))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, 0, SURFACE_TYPE_FLOWERS)
    ExecWait(N(MakeSun))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    -1,
    MODEL_8hana4,
    MODEL_8hana5,
    MODEL_8hana6,
    MODEL_8hana1,
    MODEL_8hana1,
    MODEL_8hana3,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "flo_tex",
    .shape = "flo_bt02_shape",
    .hit = "flo_bt02_hit",
    .bg = "fla_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
