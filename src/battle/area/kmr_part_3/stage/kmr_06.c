#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_kmr_06

#include "world/common/todo/clouds.inc.c"

#include "common/UnkFogFunc.inc.c"

EvtScript N(beforeBattle_80233378) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(N(UnkFogFunc))
    EVT_SET(LVar0, 1)
    EVT_SET(LVar2, 0)
    EVT_EXEC(N(clouds1))
    EVT_SET(LVar0, 4)
    EVT_SET(LVar2, 70)
    EVT_EXEC(N(clouds1))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_802333FC) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8023340C)[] = {
    0x0000001D, 0x00000022, 0x00000021, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt06_shape",
    .hit = "kmr_bt06_hit",
    .bg = "kmr_bg",
    .preBattle = &N(beforeBattle_80233378),
    .postBattle = &N(afterBattle_802333FC),
    .foregroundModelList = N(foregroundModelList_8023340C),
};
