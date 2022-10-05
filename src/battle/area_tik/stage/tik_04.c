#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_tik_tik_04

#include "common/UnkModelStuff2.inc.c"

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LVar0, 15)
        EVT_EXEC(N(script2))
        EVT_WAIT(5)
        EVT_SET(LVar0, 16)
        EVT_EXEC(N(script2))
        EVT_WAIT(5)
        EVT_SET(LVar0, 17)
        EVT_EXEC(N(script2))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_SET(LVar0, 9)
        EVT_SET(LVar1, 145)
        EVT_EXEC(N(script3))
        EVT_SET(LVar0, 10)
        EVT_SET(LVar1, 145)
        EVT_EXEC(N(script3))
    EVT_END_THREAD
    EVT_SET(LVar0, 12)
    EVT_SET(LVar1, 60)
    EVT_EXEC(N(script3))
    EVT_SET(LVar0, 13)
    EVT_SET(LVar1, 60)
    EVT_EXEC(N(script3))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "tik_tex",
    .shape = "tik_bt04_shape",
    .hit = "tik_bt04_hit",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
};


