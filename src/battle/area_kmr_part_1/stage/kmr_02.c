#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_1_kmr_02

Script N(beforeBattle_8021FDA0) = SCRIPT({
    SetSpriteShading(-1);
});

Script N(afterBattle_8021FDC0) = SCRIPT({
});

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt02_shape",
    .bg = "kmr_bg",
    .preBattle = &N(beforeBattle_8021FDA0),
    .postBattle = &N(beforeBattle_8021FDA0),
};
