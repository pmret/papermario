#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_1_kmr_06

#include "common/UnkFogFunc.inc.c"
#include "clouds.inc.c"

Script N(beforeBattle_80220E28) = SCRIPT({
    SetSpriteShading(-1);

    N(UnkFogFunc)();

    SI_VAR(0) = 1;
    SI_VAR(2) = 0;
    spawn N(clouds1);

    SI_VAR(0) = 4;
    SI_VAR(2) = 70;
    spawn N(clouds1);
});

Script N(afterBattle_80220EAC) = SCRIPT({

});

s32 N(foregroundModelList_80220EBC)[] = {
    0x0000001D, 0x00000022, 0x00000021, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt06_shape",
    .hit = "kmr_bt06_hit",
    .bg = "kmr_bg",
    .preBattle = &N(beforeBattle_80220E28),
    .postBattle = &N(beforeBattle_80220E28),
    .foregroundModelList = &N(foregroundModelList_80220EBC),
};
