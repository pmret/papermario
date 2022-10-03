#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Whacka.h"
#include "mapfs/iwa_bt01_shape.h"

#define NAMESPACE b_area_iwa_iwa_01

extern ActorBlueprint N(whacka);
extern Formation N(specialFormation_802208E4);

EvtScript N(beforeBattle_80220860) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetGroupEnabled, MODEL_b, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80220894) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_802208A4)[] = {
    MODEL_iwa1, MODEL_o331, 0,
};

Stage NAMESPACE = {
    .texture = "iwa_tex",
    .shape = "iwa_bt01_shape",
    .hit = "iwa_bt01_hit",
    .bg = "iwa_bg\0",
    .preBattle = &N(beforeBattle_80220860),
    .postBattle = &N(afterBattle_80220894),
    .foregroundModelList = N(foregroundModelList_802208A4),
    .specialFormationSize = 1,
    .specialFormation = &N(specialFormation_802208E4),
    .unk_24 = 0x200,
};

Vec3i N(vector3D_802208D8) = { 116, 0, -30 };

Formation N(specialFormation_802208E4) = {
    { .actor = &N(whacka), .home = { .vec = &N(vector3D_802208D8) }},
};

#define NAMESPACE b_area_iwa_iwa_01_whacka
#include "battle/common/actor/whacka.inc.c"
#define NAMESPACE b_area_iwa_iwa_01
