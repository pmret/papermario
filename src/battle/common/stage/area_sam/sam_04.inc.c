#include "battle/battle.h"
#include "mapfs/sam_bt04_shape.h"

#define NAMESPACE A(sam_04)

#include "battle/common/stage/lib/Snowflakes.inc.c"

void N(EnableBackgroundWave)(void) {
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
