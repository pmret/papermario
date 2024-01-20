#include "battle/battle.h"
#include "mapfs/iwa_bt02_shape.h"

#define NAMESPACE A(iwa_02)

// this (unused) whacka is part of the stage
extern ActorBlueprint N(whacka);

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
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

Vec3i N(OriginPos) = { 0, 0, 0 };

Formation N(WhackaFormation) = {
    ACTOR_BY_POS(N(whacka), N(OriginPos), 0),
};

// needs to match stage name used while defining NAMESPACE above
// the actor include redefines NAMESPACE based on current AREA, so we need to insert the stage name via prefix
#define NAME_PREFIX iwa_02_
#include "battle/common/actor/whacka.inc.c"
#define NAME_PREFIX
