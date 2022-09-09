#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_nok_01

EvtScript N(80233450) = {
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_LABEL(0)
    EVT_CALL(TranslateModel, LocalVar(10), 0, 2, 0)
    EVT_WAIT(5)
    EVT_CALL(TranslateModel, LocalVar(10), 0, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(TranslateModel, LocalVar(10), 0, 2, 0)
    EVT_WAIT(5)
    EVT_CALL(TranslateModel, LocalVar(10), 0, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(RandInt, 30, LocalVar(0))
    EVT_ADD(LocalVar(0), 30)
    EVT_WAIT(LocalVar(0))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_80233558) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_SET(LocalVar(0), 19)
    EVT_EXEC(N(80233450))
    EVT_SET(LocalVar(0), 20)
    EVT_EXEC(N(80233450))
    EVT_SET(LocalVar(0), 21)
    EVT_EXEC(N(80233450))
    EVT_SET(LocalVar(0), 22)
    EVT_EXEC(N(80233450))
    EVT_SET(LocalVar(0), 23)
    EVT_EXEC(N(80233450))
    EVT_SET(LocalVar(0), 24)
    EVT_EXEC(N(80233450))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80233620) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80233630)[] = {
    0x0000001E, 0x0000001D, 0x0000001C, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "nok_tex",
    .shape = "nok_bt01_shape",
    .hit = "nok_bt01_hit",
    .bg = "nok_bg",
    .preBattle = &N(beforeBattle_80233558),
    .postBattle = &N(afterBattle_80233620),
    .foregroundModelList = N(foregroundModelList_80233630),
};
