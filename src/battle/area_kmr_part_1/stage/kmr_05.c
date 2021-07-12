#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_1_kmr_05

#include "clouds.inc.c"

Script N(beforeBattle_80220A28) = SCRIPT({
    SetSpriteShading(-1);
    EnableModel(27, 0);
});

Script N(afterBattle_80220A5C) = SCRIPT({

});

s32 N(foregroundModelList_80220A6C)[] = {
    0x00000020, 0x00000024, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt05_shape",
    .hit = "kmr_bt05_hit",
    .bg = "kmr_bg",
    .preBattle = &N(beforeBattle_80220A28),
    .postBattle = &N(beforeBattle_80220A28),
    .foregroundModelList = &N(foregroundModelList_80220A6C),
};
