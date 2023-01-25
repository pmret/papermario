#include "common.h"
#include "battle/battle.h"
#include "mapfs/tik_bt05_shape.h"

#define NAMESPACE b_area_tik3_tik_05

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(80233540) = {
    EVT_SET_GROUP(0)
    EVT_IF_EQ(LVar5, 1)
        EVT_IF_EQ(LVar6, 1)
            EVT_IF_EQ(LVar7, 1)
                EVT_IF_EQ(LVar8, 1)
                    EVT_CALL(N(UpdateTexturePanSmooth))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(UpdateTexturePanStepped))
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetTexPanner, 15, TEX_PANNER_1)
    EVT_CALL(EnableTexPanning, 15, 1)
    EVT_THREAD
        EVT_SET(LVar0, 1)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, -2700)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, -3000)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 1)
        EVT_SET(LVar7, 1)
        EVT_SET(LVar8, 1)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(80233540))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, 16, TEX_PANNER_2)
    EVT_CALL(EnableTexPanning, 16, 1)
    EVT_THREAD
        EVT_SET(LVar0, 2)
        EVT_SET(LVar1, 50)
        EVT_SET(LVar2, -200)
        EVT_SET(LVar3, 110)
        EVT_SET(LVar4, -500)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 1)
        EVT_SET(LVar7, 1)
        EVT_SET(LVar8, 1)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(80233540))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_taki1, 0,
};

Stage NAMESPACE = {
    .texture = "tik_tex",
    .shape = "tik_bt05_shape",
    .hit = "tik_bt05_hit",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};

