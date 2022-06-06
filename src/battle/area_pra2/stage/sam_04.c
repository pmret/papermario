#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_pra2_sam_04

#include "common/UnkModelStuff.inc.c"

void func_802189E0_661130(void) {
    enable_background_wave();
}


EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_EXEC(N(UnkModelStuffScript1))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "sam_tex",
    .shape = "sam_bt04_shape",
    .hit = "sam_bt04_hit",
    .bg = "sam_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
};
