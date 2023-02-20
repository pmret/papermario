#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_pra2_sam_04

#include "battle/common/stage/sam_Snowflakes.inc.c"

void func_802189E0_661130(void) {
    enable_background_wave();
}


EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_EXEC(N(EVS_SpawnSnowfall))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "sam_tex",
    .shape = "sam_bt04_shape",
    .hit = "sam_bt04_hit",
    .bg = "sam_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
