#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Whacka.h"
#include "mapfs/iwa_bt01_shape.h"

#define NAMESPACE b_area_iwa_iwa_01

extern ActorBlueprint N(whacka);
extern Formation N(specialFormation_802208E4);

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetGroupVisibility, MODEL_b, MODEL_GROUP_HIDDEN)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_iwa1,
    MODEL_o331,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "iwa_tex",
    .shape = "iwa_bt01_shape",
    .hit = "iwa_bt01_hit",
    .bg = "iwa_bg\0",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
    .stageEnemyCount = 1,
    .stageFormation = &N(specialFormation_802208E4),
    .stageEnemyChance = 512,
};

Vec3i N(vector3D_802208D8) = { 116, 0, -30 };

Formation N(specialFormation_802208E4) = {
    { .actor = &N(whacka), .home = { .vec = &N(vector3D_802208D8) }},
};

#define NAMESPACE b_area_iwa_iwa_01_whacka
#include "battle/common/actor/whacka.inc.c"
#define NAMESPACE b_area_iwa_iwa_01
