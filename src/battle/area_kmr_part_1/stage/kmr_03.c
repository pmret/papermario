#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_1_kmr_03

#include "clouds.inc.c"

Script N(beforeBattle_80220188) = SCRIPT({
    SetSpriteShading(-1);

    SI_VAR(0) = 1; // model
    SI_VAR(2) = 0; // speed
    spawn N(clouds1);

    SI_VAR(0) = 4;
    SI_VAR(2) = 70;
    spawn N(clouds1);
});

Script N(afterBattle_80220200) = SCRIPT({
});

s32 N(foregroundModelList_80220210)[] = {
    0x00000027, 0x0000002B, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt03_shape",
    .hit = "kmr_bt03_hit",
    .bg = "kmr_bg",
    .preBattle = &N(beforeBattle_80220188),
    .postBattle = &N(beforeBattle_80220188),
    .foregroundModelList = &N(foregroundModelList_80220210),
};
