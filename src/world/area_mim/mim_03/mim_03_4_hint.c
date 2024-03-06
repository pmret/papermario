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

    evt_set_variable(script, *args++, FLOAT_TO_FIXED(x));
    evt_set_variable(script, *args++, FLOAT_TO_FIXED(y));
    evt_set_variable(script, *args++, FLOAT_TO_FIXED(z));
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
    Call(SetTexPanOffset, LVar9, 0, 0, -0x8000)
    Wait(2)
    Call(SetTexPanOffset, LVar9, 0, 0, -0x10000)
    Wait(2)
    Call(MakeLerp, 0, 720, 200, EASING_COS_IN_OUT)
    Label(0)
    Call(UpdateLerp)
    UseBuf(LVar8)
    Loop(3)
        BufRead2(LVar6, LVar7)
        Call(N(GetFlowerNormal), LVar6, LVar3, LVar4, LVar5)
        Call(RotateModel, LVar6, LVar0, LVar3, LVar4, LVar5)
        Call(RotateModel, LVar7, LVar0, LVar3, LVar4, LVar5)
    EndLoop
    Wait(1)
    IfEq(LVar1, 1)
        Goto(0)
    EndIf
    Call(SetTexPanOffset, LVar9, 0, 0, -0x8000)
    Wait(2)
    Call(SetTexPanOffset, LVar9, 0, 0, 0)
    Wait(2)
    Return
    End
};

EvtScript N(EVS_FlowersReact_Correct) = {
    Loop(2)
        Call(SetTexPanOffset, LVar9, 0, 0, -0x8000)
        Wait(2)
        Call(MakeLerp, 0, 30, 50, EASING_COS_IN_OUT)
        Label(5)
        Call(UpdateLerp)
        UseBuf(LVar8)
        Loop(4)
            BufRead2(LVar6, LVar7)
            Call(N(GetFlowerNormal), LVar6, LVar3, LVar4, LVar5)
            Call(RotateModel, LVar6, LVar0, LVar3, LVar4, LVar5)
            Call(RotateModel, LVar7, LVar0, LVar3, LVar4, LVar5)
        EndLoop
        Wait(1)
        IfEq(LVar1, 1)
            Goto(5)
        EndIf
        Call(MakeLerp, 30, -30, 50, EASING_COS_IN_OUT)
        Label(10)
        Call(UpdateLerp)
        UseBuf(LVar8)
        Loop(4)
            BufRead2(LVar6, LVar7)
            Call(N(GetFlowerNormal), LVar6, LVar3, LVar4, LVar5)
            Call(RotateModel, LVar6, LVar0, LVar3, LVar4, LVar5)
            Call(RotateModel, LVar7, LVar0, LVar3, LVar4, LVar5)
        EndLoop
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
        Call(MakeLerp, -30, 0, 50, EASING_COS_IN_OUT)
        Label(20)
        Call(UpdateLerp)
        UseBuf(LVar8)
        Loop(4)
            BufRead2(LVar6, LVar7)
            Call(N(GetFlowerNormal), LVar6, LVar3, LVar4, LVar5)
            Call(RotateModel, LVar6, LVar0, LVar3, LVar4, LVar5)
            Call(RotateModel, LVar7, LVar0, LVar3, LVar4, LVar5)
        EndLoop
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
        Call(SetTexPanOffset, LVar9, 0, 0, 0)
        Wait(2)
    EndLoop
    Return
    End
};

EvtScript N(EVS_CheckFlowers_North) = {
    Call(PlaySoundAt, SOUND_FLOWERS_LIGHT_GIGGLE, SOUND_SPACE_DEFAULT, 0, 0, -300)
    Set(LVar8, Ref(N(FlowerModels_North)))
    Set(LVar9, 0)
    ExecWait(N(EVS_FlowersReact_Wrong))
    Return
    End
};

EvtScript N(EVS_CheckFlowers_West) = {
    Call(PlaySoundAt, SOUND_FLOWERS_SAD_GIGGLE, SOUND_SPACE_DEFAULT, -300, 0, 0)
    Set(LVar8, Ref(N(FlowerModels_West)))
    Set(LVar9, 1)
    ExecWait(N(EVS_FlowersReact_Correct))
    Return
    End
};

EvtScript N(EVS_CheckFlowers_South) = {
    Call(PlaySoundAt, SOUND_FLOWERS_LIGHT_GIGGLE, SOUND_SPACE_DEFAULT, 0, 0, 300)
    Set(LVar8, Ref(N(FlowerModels_South)))
    Set(LVar9, 2)
    ExecWait(N(EVS_FlowersReact_Wrong))
    Return
    End
};

EvtScript N(EVS_CheckFlowers_East) = {
    Call(PlaySoundAt, SOUND_FLOWERS_LIGHT_GIGGLE, SOUND_SPACE_DEFAULT, 300, 0, 0)
    Set(LVar8, Ref(N(FlowerModels_East)))
    Set(LVar9, 3)
    ExecWait(N(EVS_FlowersReact_Wrong))
    Return
    End
};

EvtScript N(EVS_SetupExitHint) = {
    Call(SetTexPanner, MODEL_o2, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o4, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o6, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o20, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o22, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o24, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o26, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o14, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o16, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o18, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o8, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o10, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o12, TEX_PANNER_3)
    BindTrigger(Ref(N(EVS_CheckFlowers_West)),  TRIGGER_WALL_PRESS_A, COLLIDER_o132, 1, 0)
    BindTrigger(Ref(N(EVS_CheckFlowers_North)), TRIGGER_WALL_PRESS_A, COLLIDER_o149, 1, 0)
    BindTrigger(Ref(N(EVS_CheckFlowers_South)), TRIGGER_WALL_PRESS_A, COLLIDER_o151, 1, 0)
    BindTrigger(Ref(N(EVS_CheckFlowers_East)),  TRIGGER_WALL_PRESS_A, COLLIDER_o150, 1, 0)
    Return
    End
};
