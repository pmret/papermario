#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kgr_kgr_01

#include "common/UnkModelStuff2.inc.c"

EvtScript N(beforeBattle_8021D3B4) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LVar0, 19)
        EVT_EXEC(N(script4))
        EVT_WAIT(4)
        EVT_SET(LVar0, 20)
        EVT_EXEC(N(script4))
        EVT_WAIT(4)
        EVT_SET(LVar0, 21)
        EVT_EXEC(N(script4))
        EVT_WAIT(4)
        EVT_SET(LVar0, 22)
        EVT_EXEC(N(script4))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 14)
        EVT_EXEC(N(script4))
        EVT_WAIT(4)
        EVT_SET(LVar0, 15)
        EVT_EXEC(N(script4))
        EVT_WAIT(4)
        EVT_SET(LVar0, 16)
        EVT_EXEC(N(script4))
        EVT_WAIT(4)
        EVT_SET(LVar0, 17)
        EVT_EXEC(N(script4))
        EVT_WAIT(4)
        EVT_SET(LVar0, 18)
        EVT_EXEC(N(script4))
    EVT_END_THREAD
    EVT_SET(LVar0, 11)
    EVT_EXEC(N(script4))
    EVT_SET(LVar0, 12)
    EVT_EXEC(N(script4))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021D598) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8021D5A8)[] = {
    0x00000009, 0x00000010, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "kgr_tex",
    .shape = "kgr_bt01_shape",
    .hit = "kgr_bt01_hit",
    .preBattle = &N(beforeBattle_8021D3B4),
    .postBattle = &N(afterBattle_8021D598),
    .foregroundModelList = N(foregroundModelList_8021D5A8),
};
