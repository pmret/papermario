#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Whacka.h"
#include "mapfs/iwa_bt02_shape.h"

#define NAMESPACE b_area_iwa_iwa_02

extern ActorBlueprint N(whacka);

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_o331,
    MODEL_iwa1,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "iwa_tex",
    .shape = "iwa_bt02_shape",
    .hit = "iwa_bt02_hit",
    .bg = "iwa_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};

Vec3i N(D_802215F4_4B17E4) = { 0, 0, 0 };

Formation N(specialFormation_whacka) = {
    { .actor = &N(whacka), .home = { .vec = &N(D_802215F4_4B17E4) }},
};

#define NAMESPACE b_area_iwa_iwa_02_whacka
#include "battle/common/actor/whacka.inc.c"
#define NAMESPACE b_area_iwa_iwa_02
