#include "mim_01.h"
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

EvtScript N(EVS_LaughingFlowers) = {
    Call(PlaySoundAt, SOUND_CHECK_LAUGHING_FLOWERS, SOUND_SPACE_DEFAULT, 301, 0, -27)
    Loop(6)
        Set(LVar0, 2)
        Call(TranslateModel, MODEL_ea_1, 0, 0, LVar0)
        Call(TranslateModel, MODEL_ea_2, 0, 0, LVar0)
        Call(TranslateModel, MODEL_eb_1, 0, 0, LVar0)
        Call(TranslateModel, MODEL_eb_2, 0, 0, LVar0)
        Call(TranslateModel, MODEL_ec_1, 0, 0, LVar0)
        Call(TranslateModel, MODEL_ec_2, 0, 0, LVar0)
        Call(TranslateModel, MODEL_atari_kusa, 0, 0, LVar0)
        Wait(1)
        Set(LVar0, -2)
        Call(TranslateModel, MODEL_ea_1, 0, 0, LVar0)
        Call(TranslateModel, MODEL_ea_2, 0, 0, LVar0)
        Call(TranslateModel, MODEL_eb_1, 0, 0, LVar0)
        Call(TranslateModel, MODEL_eb_2, 0, 0, LVar0)
        Call(TranslateModel, MODEL_ec_1, 0, 0, LVar0)
        Call(TranslateModel, MODEL_ec_2, 0, 0, LVar0)
        Call(TranslateModel, MODEL_atari_kusa, 0, 0, LVar0)
        Wait(1)
    EndLoop
    Call(TranslateModel, MODEL_ea_1, 0, 0, 0)
    Call(TranslateModel, MODEL_ea_2, 0, 0, 0)
    Call(TranslateModel, MODEL_eb_1, 0, 0, 0)
    Call(TranslateModel, MODEL_eb_2, 0, 0, 0)
    Call(TranslateModel, MODEL_ec_1, 0, 0, 0)
    Call(TranslateModel, MODEL_ec_2, 0, 0, 0)
    Call(TranslateModel, MODEL_atari_kusa, 0, 0, 0)
    Wait(20)
    Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, -0x8000)
    Wait(2)
    Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, -0x10000)
    Wait(2)
    Call(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, 301, 0, -27)
    Call(MakeLerp, 0, 30, 50, EASING_COS_IN_OUT)
    Label(10)
    Call(UpdateLerp)
    Call(N(GetFlowerNormal), MODEL_ea_1, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_ea_1, LVar0, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_ea_2, LVar0, LVar7, LVar8, LVar9)
    Call(N(GetFlowerNormal), MODEL_eb_1, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_eb_1, LVar0, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_eb_2, LVar0, LVar7, LVar8, LVar9)
    Call(N(GetFlowerNormal), MODEL_ec_1, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_ec_1, LVar0, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_ec_2, LVar0, LVar7, LVar8, LVar9)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, 301, 0, -27)
    Call(MakeLerp, 30, -30, 50, EASING_COS_IN_OUT)
    Label(20)
    Call(UpdateLerp)
    Call(N(GetFlowerNormal), MODEL_ea_1, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_ea_1, LVar0, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_ea_2, LVar0, LVar7, LVar8, LVar9)
    Call(N(GetFlowerNormal), MODEL_eb_1, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_eb_1, LVar0, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_eb_2, LVar0, LVar7, LVar8, LVar9)
    Call(N(GetFlowerNormal), MODEL_ec_1, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_ec_1, LVar0, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_ec_2, LVar0, LVar7, LVar8, LVar9)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(20)
    EndIf
    Call(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, 301, 0, -27)
    Call(MakeLerp, -30, 0, 50, EASING_COS_IN_OUT)
    Label(30)
    Call(UpdateLerp)
    Call(N(GetFlowerNormal), MODEL_ea_1, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_ea_1, LVar0, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_ea_2, LVar0, LVar7, LVar8, LVar9)
    Call(N(GetFlowerNormal), MODEL_eb_1, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_eb_1, LVar0, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_eb_2, LVar0, LVar7, LVar8, LVar9)
    Call(N(GetFlowerNormal), MODEL_ec_1, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_ec_1, LVar0, LVar7, LVar8, LVar9)
    Call(RotateModel, MODEL_ec_2, LVar0, LVar7, LVar8, LVar9)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(30)
    EndIf
    Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, -0x8000)
    Wait(2)
    Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, 0)
    Wait(30)
    Return
    End
};

EvtScript N(EVS_WaitForPlayerNearby) = {
    Label(0)
        Call(AwaitPlayerApproach, 350, 0, 50)
        ExecWait(N(EVS_LaughingFlowers))
        Call(AwaitPlayerLeave, 350, 0, 50)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SetupExitHint) = {
    Call(SetTexPanner, MODEL_ea_2, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_eb_2, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_ec_2, TEX_PANNER_1)
    Exec(N(EVS_WaitForPlayerNearby))
    Return
    End
};
