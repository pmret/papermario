#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_omo_omo_06

EvtScript N(8022F630) = {
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(9), LW(1))
    EVT_SET(LW(8), LW(2))
    EVT_LABEL(0)
    EVT_CALL(MakeLerp, 0, LW(9), LW(8), 10)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LW(10), 0, LW(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, LW(9), 0, LW(8), 10)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, LW(10), 0, LW(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_8022F790) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LW(0), 26)
        EVT_SET(LW(1), -50)
        EVT_SET(LW(2), 120)
        EVT_EXEC(N(8022F630))
        EVT_WAIT_FRAMES(10)
        EVT_SET(LW(0), 30)
        EVT_SET(LW(1), -80)
        EVT_SET(LW(2), 150)
        EVT_EXEC(N(8022F630))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022F860) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8022F870)[] = {
    0x00000027, 0x00000026, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt06_shape",
    .hit = "omo_bt06_hit",
    .bg = "omo_bg",
    .preBattle = N(beforeBattle_8022F790),
    .postBattle = N(afterBattle_8022F860),
    .foregroundModelList = N(foregroundModelList_8022F870),
};
