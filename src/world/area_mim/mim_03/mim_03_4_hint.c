#include "mim_03.h"
#include "model.h"

#include "world/common/util/GetFirstTriangleNormal.inc.c"

API_CALLABLE(N(GetFlowerNormal)) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = evt_get_variable(script, *args++);
    s32 treeIndex = get_model_list_index_from_tree_index(modelID);
    Model* mdl = get_model_from_list_index(treeIndex);
    f32 x, y, z;

    N(GetFirstTriangleNormal)(mdl->modelNode->displayData->displayList, &x, &y, &z);

    evt_set_variable(script, *args++, EVT_FLOAT_TO_FIXED(x));
    evt_set_variable(script, *args++, EVT_FLOAT_TO_FIXED(y));
    evt_set_variable(script, *args++, EVT_FLOAT_TO_FIXED(z));
    return ApiStatus_DONE2;
}

s32 N(FlowerModels_North)[] = {
    MODEL_o1, MODEL_o2,
    MODEL_o3, MODEL_o4,
    MODEL_o5, MODEL_o6,
};

s32 N(FlowerModels_West)[] = {
    MODEL_o19, MODEL_o20,
    MODEL_o21, MODEL_o22,
    MODEL_o23, MODEL_o24,
    MODEL_o25, MODEL_o26,
};

s32 N(FlowerModels_South)[] = {
    MODEL_o13, MODEL_o14,
    MODEL_o15, MODEL_o16,
    MODEL_o17, MODEL_o18,
};

s32 N(FlowerModels_East)[] = {
    MODEL_o7, MODEL_o8,
    MODEL_o9, MODEL_o10,
    MODEL_o11, MODEL_o12,
};

EvtScript N(EVS_FlowersReact_Wrong) = {
    EVT_CALL(SetTexPanOffset, LVar9, 0, 0, -0x8000)
    EVT_WAIT(2)
    EVT_CALL(SetTexPanOffset, LVar9, 0, 0, -0x10000)
    EVT_WAIT(2)
    EVT_CALL(MakeLerp, 0, 720, 200, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_USE_BUF(LVar8)
    EVT_LOOP(3)
        EVT_BUF_READ2(LVar6, LVar7)
        EVT_CALL(N(GetFlowerNormal), LVar6, LVar3, LVar4, LVar5)
        EVT_CALL(RotateModel, LVar6, LVar0, LVar3, LVar4, LVar5)
        EVT_CALL(RotateModel, LVar7, LVar0, LVar3, LVar4, LVar5)
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetTexPanOffset, LVar9, 0, 0, -0x8000)
    EVT_WAIT(2)
    EVT_CALL(SetTexPanOffset, LVar9, 0, 0, 0)
    EVT_WAIT(2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlowersReact_Correct) = {
    EVT_LOOP(2)
        EVT_CALL(SetTexPanOffset, LVar9, 0, 0, -0x8000)
        EVT_WAIT(2)
        EVT_CALL(MakeLerp, 0, 30, 50, EASING_COS_IN_OUT)
        EVT_LABEL(5)
        EVT_CALL(UpdateLerp)
        EVT_USE_BUF(LVar8)
        EVT_LOOP(4)
            EVT_BUF_READ2(LVar6, LVar7)
            EVT_CALL(N(GetFlowerNormal), LVar6, LVar3, LVar4, LVar5)
            EVT_CALL(RotateModel, LVar6, LVar0, LVar3, LVar4, LVar5)
            EVT_CALL(RotateModel, LVar7, LVar0, LVar3, LVar4, LVar5)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(5)
        EVT_END_IF
        EVT_CALL(MakeLerp, 30, -30, 50, EASING_COS_IN_OUT)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_USE_BUF(LVar8)
        EVT_LOOP(4)
            EVT_BUF_READ2(LVar6, LVar7)
            EVT_CALL(N(GetFlowerNormal), LVar6, LVar3, LVar4, LVar5)
            EVT_CALL(RotateModel, LVar6, LVar0, LVar3, LVar4, LVar5)
            EVT_CALL(RotateModel, LVar7, LVar0, LVar3, LVar4, LVar5)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(MakeLerp, -30, 0, 50, EASING_COS_IN_OUT)
        EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_USE_BUF(LVar8)
        EVT_LOOP(4)
            EVT_BUF_READ2(LVar6, LVar7)
            EVT_CALL(N(GetFlowerNormal), LVar6, LVar3, LVar4, LVar5)
            EVT_CALL(RotateModel, LVar6, LVar0, LVar3, LVar4, LVar5)
            EVT_CALL(RotateModel, LVar7, LVar0, LVar3, LVar4, LVar5)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, LVar9, 0, 0, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CheckFlowers_North) = {
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_LIGHT_GIGGLE, SOUND_SPACE_DEFAULT, 0, 0, -300)
    EVT_SET(LVar8, EVT_PTR(N(FlowerModels_North)))
    EVT_SET(LVar9, 0)
    EVT_EXEC_WAIT(N(EVS_FlowersReact_Wrong))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CheckFlowers_West) = {
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_SAD_GIGGLE, SOUND_SPACE_DEFAULT, -300, 0, 0)
    EVT_SET(LVar8, EVT_PTR(N(FlowerModels_West)))
    EVT_SET(LVar9, 1)
    EVT_EXEC_WAIT(N(EVS_FlowersReact_Correct))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CheckFlowers_South) = {
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_LIGHT_GIGGLE, SOUND_SPACE_DEFAULT, 0, 0, 300)
    EVT_SET(LVar8, EVT_PTR(N(FlowerModels_South)))
    EVT_SET(LVar9, 2)
    EVT_EXEC_WAIT(N(EVS_FlowersReact_Wrong))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CheckFlowers_East) = {
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_LIGHT_GIGGLE, SOUND_SPACE_DEFAULT, 300, 0, 0)
    EVT_SET(LVar8, EVT_PTR(N(FlowerModels_East)))
    EVT_SET(LVar9, 3)
    EVT_EXEC_WAIT(N(EVS_FlowersReact_Wrong))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupExitHint) = {
    EVT_CALL(SetTexPanner, MODEL_o2, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o4, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o6, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o20, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o22, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o24, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o26, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o14, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_o16, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_o18, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_o8, TEX_PANNER_3)
    EVT_CALL(SetTexPanner, MODEL_o10, TEX_PANNER_3)
    EVT_CALL(SetTexPanner, MODEL_o12, TEX_PANNER_3)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_CheckFlowers_West)),  TRIGGER_WALL_PRESS_A, COLLIDER_o132, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_CheckFlowers_North)), TRIGGER_WALL_PRESS_A, COLLIDER_o149, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_CheckFlowers_South)), TRIGGER_WALL_PRESS_A, COLLIDER_o151, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_CheckFlowers_East)),  TRIGGER_WALL_PRESS_A, COLLIDER_o150, 1, 0)
    EVT_RETURN
    EVT_END
};
