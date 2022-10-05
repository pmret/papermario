#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_mac_mac_01

#include "common/UnkModelStuff2.inc.c"

EvtScript N(beforeBattle_802327F4) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LVar0, 44)
        EVT_EXEC(N(script2))
        EVT_WAIT(5)
        EVT_SET(LVar0, 47)
        EVT_EXEC(N(script2))
        EVT_WAIT(5)
        EVT_SET(LVar0, 46)
        EVT_EXEC(N(script2))
        EVT_WAIT(5)
        EVT_SET(LVar0, 45)
        EVT_EXEC(N(script2))
    EVT_END_THREAD
    EVT_SET(LVar0, 40)
    EVT_EXEC(N(script1))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_802328F0) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "mac_tex",
    .shape = "mac_bt01_shape",
    .hit = "mac_bt01_hit",
    .bg = "nok_bg",
    .preBattle = &N(beforeBattle_802327F4),
    .postBattle = &N(afterBattle_802328F0),
};
