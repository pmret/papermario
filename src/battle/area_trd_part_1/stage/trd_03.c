#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_1_trd_03

#include "world/common/todo/clouds.inc.c"

EvtScript N(beforeBattle_80223F08) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SET(LVar0, 4)
    EVT_SET(LVar2, 0)
    EVT_EXEC(N(clouds1))
    EVT_SET(LVar0, 2)
    EVT_SET(LVar2, 70)
    EVT_SET(LVar3, 175)
    EVT_SET(LVar4, -170)
    EVT_EXEC(N(clouds2))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80223FA0) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80223FB0)[] = {
    0x0000000F, 0x0000000E, 0x0000000D, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt03_shape",
    .hit = "trd_bt03_hit",
    .bg = "nok_bg",
    .preBattle = &N(beforeBattle_80223F08),
    .postBattle = &N(afterBattle_80223FA0),
    .foregroundModelList = N(foregroundModelList_80223FB0),
};
