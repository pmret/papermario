#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_tik_tik_01

#include "world/common/todo/UnkFunc56.inc.c"

EvtScript N(802301F0) = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, 0, LVar0, LVar1)
        EVT_ADD(LVar0, LVarB)
        EVT_ADD(LVar1, LVarC)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802302C0) = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, 0, LVar0, 0)
        EVT_CALL(SetTexPanOffset, LVarA, 1, LVar1, 0)
        EVT_ADD(LVar0, LVarB)
        EVT_ADD(LVar1, LVarC)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802303AC) = {
    EVT_SET(LVarA, LVar1)
    EVT_SET(LVarB, LVar2)
    EVT_SET(LVarC, LVar3)
    EVT_CALL(SetTexPanner, LVar0, LVar1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, LVarA, 0, 0, LVar0)
        EVT_CALL(SetTexPanOffset, LVarA, 1, 0, LVar1)
        EVT_ADD(LVar0, LVarB)
        EVT_ADD(LVar1, LVarC)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80230498) = {
    EVT_SET(LVar1, ArrayVar(5))
    EVT_ADD(LVar1, 1)
    EVT_SET(LVar2, ArrayVar(0))
    EVT_SET(LVar3, ArrayVar(1))
    EVT_SET(LVar4, ArrayVar(5))
    EVT_ADD(LVar4, 2)
    EVT_SET(LVar5, ArrayVar(0))
    EVT_SET(LVar6, ArrayVar(1))
    EVT_SET(LVar7, ArrayVar(5))
    EVT_ADD(LVar7, 3)
    EVT_SET(LVar8, ArrayVar(0))
    EVT_SET(LVar9, ArrayVar(1))
    EVT_SET(LVarA, ArrayVar(5))
    EVT_ADD(LVarA, 4)
    EVT_SET(LVarB, ArrayVar(0))
    EVT_SET(LVarC, ArrayVar(1))
    EVT_CALL(EnableModel, LVar1, TRUE)
    EVT_CALL(EnableModel, LVar4, TRUE)
    EVT_CALL(EnableModel, LVar7, TRUE)
    EVT_CALL(EnableModel, LVarA, TRUE)
    EVT_LOOP(5)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_ADD(LVar3, 1)
        EVT_CALL(TranslateModel, LVar1, LVar2, LVar0, LVar3)
        EVT_CALL(ScaleModel, LVar1, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_ADD(LVar5, -1)
        EVT_ADD(LVar6, 1)
        EVT_CALL(TranslateModel, LVar4, LVar5, LVar0, LVar6)
        EVT_CALL(ScaleModel, LVar4, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_ADD(LVar8, 1)
        EVT_ADD(LVar9, -1)
        EVT_CALL(TranslateModel, LVar7, LVar8, LVar0, LVar9)
        EVT_CALL(ScaleModel, LVar7, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_ADD(LVarB, -1)
        EVT_ADD(LVarC, -1)
        EVT_CALL(TranslateModel, LVarA, LVarB, LVar0, LVarC)
        EVT_CALL(ScaleModel, LVarA, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(5)
        EVT_ADD(LVar0, -1)
        EVT_ADD(LVar2, 1)
        EVT_ADD(LVar3, 1)
        EVT_CALL(TranslateModel, LVar1, LVar2, LVar0, LVar3)
        EVT_CALL(ScaleModel, LVar1, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_ADD(LVar5, -1)
        EVT_ADD(LVar6, 1)
        EVT_CALL(TranslateModel, LVar4, LVar5, LVar0, LVar6)
        EVT_CALL(ScaleModel, LVar4, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_ADD(LVar8, 1)
        EVT_ADD(LVar9, -1)
        EVT_CALL(TranslateModel, LVar7, LVar8, LVar0, LVar9)
        EVT_CALL(ScaleModel, LVar7, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_ADD(LVarB, -1)
        EVT_ADD(LVarC, -1)
        EVT_CALL(TranslateModel, LVarA, LVarB, LVar0, LVarC)
        EVT_CALL(ScaleModel, LVarA, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(0.5))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, LVar1, FALSE)
    EVT_CALL(EnableModel, LVar4, FALSE)
    EVT_CALL(EnableModel, LVar7, FALSE)
    EVT_CALL(EnableModel, LVarA, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80230968) = {
    EVT_SET_GROUP(0)
    EVT_USE_ARRAY(LVarA)
    EVT_SET(LVar5, ArrayVar(5))
    EVT_LOOP(5)
        EVT_CALL(CloneModel, 16, LVar5)
        EVT_CALL(TranslateModel, LVar5, ArrayVar(0), ArrayVar(2), ArrayVar(1))
        EVT_ADD(LVar5, 1)
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_CALL(RandInt, 200, LVar0)
    EVT_ADD(LVar0, 50)
    EVT_WAIT(LVar0)
    EVT_CALL(EnableModel, ArrayVar(5), TRUE)
    EVT_CALL(MakeLerp, ArrayVar(2), ArrayVar(3), ArrayVar(4), EASING_QUADRATIC_IN)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, ArrayVar(5), ArrayVar(0), LVar0, ArrayVar(1))
    EVT_WAIT(1)
    EVT_CALL(N(UnkFunc56), ArrayVar(5))
    EVT_IF_EQ(LVar2, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_LABEL(10)
    EVT_CALL(EnableModel, ArrayVar(5), FALSE)
    EVT_EXEC_WAIT(N(80230498))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80230B30) = {
    EVT_SET(LVarF, 10000)
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ1(LVar1)
    EVT_LOOP(LVar1)
        EVT_BUF_READ4(LVar2, LVar3, LVar4, LVar5)
        EVT_BUF_READ3(LVar6, LVar7, LVar8)
        EVT_BUF_READ1(LVar9)
        EVT_LOOP(LVar9)
            EVT_MALLOC_ARRAY(6, LVarA)
            EVT_USE_ARRAY(LVarA)
            EVT_CALL(RandInt, LVar4, LVarB)
            EVT_CALL(RandInt, LVar5, LVarC)
            EVT_SET(LVarD, LVar2)
            EVT_SET(LVarE, LVar3)
            EVT_ADD(LVarD, LVarB)
            EVT_ADD(LVarE, LVarC)
            EVT_SET(ArrayVar(0), LVarD)
            EVT_SET(ArrayVar(1), LVarE)
            EVT_SET(ArrayVar(2), LVar6)
            EVT_SET(ArrayVar(3), LVar7)
            EVT_SET(ArrayVar(4), LVar8)
            EVT_SET(ArrayVar(5), LVarF)
            EVT_CHILD_THREAD
                EVT_EXEC(N(80230968))
            EVT_END_CHILD_THREAD
            EVT_ADD(LVarF, 5)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_CALL(EnableModel, 16, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(80230CEC)[] = {
    1, -100, -50, 200, 100, 200, 0, 60, 4,
};

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, 13)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, -500)
    EVT_EXEC(N(802301F0))
    EVT_SET(LVar0, N(80230CEC))
    EVT_EXEC(N(80230B30))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "tik_tex",
    .shape = "tik_bt01_shape",
    .hit = "tik_bt01_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
