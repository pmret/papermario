#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_1_kmr_04

#include "clouds.inc.c"

EvtSource N(beforeBattle_802205D8) = SCRIPT({
    SetSpriteShading(-1);

    EVT_VAR(0) = 1;
    EVT_VAR(2) = 0;
    spawn N(clouds1);

    EVT_VAR(0) = 4;
    EVT_VAR(2) = 70;
    spawn N(clouds1);
});

EvtSource N(afterBattle_80220650) = SCRIPT({

});

s32 N(foregroundModelList_80220660)[] = {
    0x00000024, 0x00000020, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt04_shape",
    .hit = "kmr_bt04_hit",
    .bg = "kmr_bg",
    .preBattle = N(beforeBattle_802205D8),
    .postBattle = N(afterBattle_80220650),
    .foregroundModelList = N(foregroundModelList_80220660),
};
