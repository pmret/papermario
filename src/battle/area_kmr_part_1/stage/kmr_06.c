#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_1_kmr_06

#include "world/common/clouds.inc.c"
#include "common/UnkFogFunc.inc.c"

EvtScript N(beforeBattle_80220E28) = {
    EVT_CALL(SetSpriteShading, -1)
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

EvtScript N(afterBattle_80220EAC) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80220EBC)[] = {
    0x0000001D, 0x00000022, 0x00000021, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt06_shape",
    .hit = "kmr_bt06_hit",
    .bg = "kmr_bg",
    .preBattle = &N(beforeBattle_80220E28),
    .postBattle = &N(afterBattle_80220EAC),
    .foregroundModelList = N(foregroundModelList_80220EBC),
};
