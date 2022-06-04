#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_sam_01

#include "common/UnkModelStuff.inc.c"

EvtScript N(beforeBattle_80233998) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_EXEC(N(UnkModelStuffScript1))
    EVT_THREAD
        EVT_SET(LW(0), 22)
        EVT_SET(LW(1), 1)
        EVT_EXEC(N(UnkModelStuffScript3))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), 20)
        EVT_SET(LW(1), 3)
        EVT_EXEC(N(UnkModelStuffScript3))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), 18)
        EVT_SET(LW(1), 4)
        EVT_EXEC(N(UnkModelStuffScript3))
        EVT_WAIT_FRAMES(5)
        EVT_SET(LW(0), 16)
        EVT_SET(LW(1), 2)
        EVT_EXEC(N(UnkModelStuffScript3))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80233AA8) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80233AB8)[] = {
    0xFFFFFFFF, 0x0000001A, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "sam_tex",
    .shape = "sam_bt01_shape",
    .hit = "sam_bt01_hit",
    .bg = "yki_bg",
    .preBattle = &N(beforeBattle_80233998),
    .postBattle = &N(afterBattle_80233AA8),
    .foregroundModelList = N(foregroundModelList_80233AB8),
};
