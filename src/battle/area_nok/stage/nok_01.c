#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_nok_nok_01

EvtScript N(8022B5F0) = {
    EVT_SET(LW(10), LW(0))
    EVT_LABEL(0)
    EVT_CALL(TranslateModel, LW(10), 0, 2, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(TranslateModel, LW(10), 0, 2, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(RandInt, 30, LW(0))
    EVT_ADD(LW(0), 30)
    EVT_WAIT_FRAMES(LW(0))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_8022B6F8) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_SET(LW(0), 19)
    EVT_EXEC(N(8022B5F0))
    EVT_SET(LW(0), 20)
    EVT_EXEC(N(8022B5F0))
    EVT_SET(LW(0), 21)
    EVT_EXEC(N(8022B5F0))
    EVT_SET(LW(0), 22)
    EVT_EXEC(N(8022B5F0))
    EVT_SET(LW(0), 23)
    EVT_EXEC(N(8022B5F0))
    EVT_SET(LW(0), 24)
    EVT_EXEC(N(8022B5F0))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022B7C0) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8022B7D0)[] = {
    0x0000001E, 0x0000001D, 0x0000001C, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "nok_tex",
    .shape = "nok_bt01_shape",
    .hit = "nok_bt01_hit",
    .bg = "nok_bg",
    .preBattle = N(beforeBattle_8022B6F8),
    .postBattle = N(afterBattle_8022B7C0),
    .foregroundModelList = N(foregroundModelList_8022B7D0),
};
