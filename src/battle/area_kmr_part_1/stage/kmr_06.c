#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_1_kmr_06

#include "clouds.inc.c"
#include "common/UnkFogFunc.inc.c"

EvtSource N(beforeBattle_80220E28) = SCRIPT({
    SetSpriteShading(-1);

    N(UnkFogFunc)();

    EVT_VAR(0) = 1;
    EVT_VAR(2) = 0;
    spawn N(clouds1);

    EVT_VAR(0) = 4;
    EVT_VAR(2) = 70;
    spawn N(clouds1);
});

EvtSource N(afterBattle_80220EAC) = SCRIPT({

});

s32 N(foregroundModelList_80220EBC)[] = {
    0x0000001D, 0x00000022, 0x00000021, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt06_shape",
    .hit = "kmr_bt06_hit",
    .bg = "kmr_bg",
    .preBattle = N(beforeBattle_80220E28),
    .postBattle = N(afterBattle_80220EAC),
    .foregroundModelList = N(foregroundModelList_80220EBC),
};
