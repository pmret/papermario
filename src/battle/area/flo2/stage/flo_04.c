#include "common.h"
#include "battle/battle.h"
#include "mapfs/flo_bt04_shape.h"

#define NAMESPACE b_area_flo2_flo_04

#include "common/CosInterpMinMax.inc.c"

EvtScript N(80233470) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarF, 0)
    EVT_LOOP(0)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, EVT_FLOAT(0.968), EVT_FLOAT(1.031), 15, 0, 0)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar1, EVT_FLOAT(1.031), EVT_FLOAT(0.968), 15, 0, 0)
        EVT_CALL(ScaleModel, LVarA, LVar1, LVar0, 1)
        EVT_ADD(LVarF, 1)
        EVT_IF_GE(LVarF, 30)
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#include "common/MakeSun.inc.c"

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, 14)
    EVT_EXEC(N(80233470))
    EVT_SET(LVar0, 16)
    EVT_EXEC(N(80233470))
    EVT_SET(LVar0, 18)
    EVT_EXEC(N(80233470))
    EVT_SET(LVar0, 20)
    EVT_EXEC(N(80233470))
    EVT_SET(LVar0, 25)
    EVT_EXEC(N(80233470))
    EVT_THREAD
        EVT_SET(LVar0, 31)
        EVT_EXEC(N(80233470))
        EVT_SET(LVar0, 32)
        EVT_EXEC(N(80233470))
        EVT_WAIT(5)
        EVT_SET(LVar0, 0)
        EVT_EXEC(N(80233470))
        EVT_SET(LVar0, 1)
        EVT_EXEC(N(80233470))
        EVT_WAIT(5)
        EVT_SET(LVar0, 5)
        EVT_EXEC(N(80233470))
        EVT_SET(LVar0, 4)
        EVT_EXEC(N(80233470))
        EVT_SET(LVar0, 6)
        EVT_EXEC(N(80233470))
        EVT_WAIT(5)
        EVT_SET(LVar0, 33)
        EVT_EXEC(N(80233470))
        EVT_SET(LVar0, 34)
        EVT_EXEC(N(80233470))
    EVT_END_THREAD
    EVT_CALL(CloneModel, 27, 0x00002710)
    EVT_CALL(EnableModel, 0x00002710, FALSE)
    EVT_CALL(TranslateModel, 0x00002710, 0, 9, 0)
    EVT_CALL(ParentColliderToModel, 0, 0x00002710)
    EVT_EXEC_WAIT(N(MakeSun))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    -1, MODEL_o431, MODEL_o419, 0,
};

Stage NAMESPACE = {
    .texture = "flo_tex",
    .shape = "flo_bt04_shape",
    .hit = "flo_bt04_hit",
    .bg = "sra_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
