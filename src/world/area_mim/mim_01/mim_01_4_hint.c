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

    evt_set_variable(script, *args++, EVT_FLOAT_TO_FIXED(x));
    evt_set_variable(script, *args++, EVT_FLOAT_TO_FIXED(y));
    evt_set_variable(script, *args++, EVT_FLOAT_TO_FIXED(z));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_LaughingFlowers) = {
    EVT_CALL(PlaySoundAt, SOUND_CHECK_LAUGHING_FLOWERS, SOUND_SPACE_DEFAULT, 301, 0, -27)
    EVT_LOOP(6)
        EVT_SET(LVar0, 2)
        EVT_CALL(TranslateModel, MODEL_ea_1, 0, 0, LVar0)
        EVT_CALL(TranslateModel, MODEL_ea_2, 0, 0, LVar0)
        EVT_CALL(TranslateModel, MODEL_eb_1, 0, 0, LVar0)
        EVT_CALL(TranslateModel, MODEL_eb_2, 0, 0, LVar0)
        EVT_CALL(TranslateModel, MODEL_ec_1, 0, 0, LVar0)
        EVT_CALL(TranslateModel, MODEL_ec_2, 0, 0, LVar0)
        EVT_CALL(TranslateModel, MODEL_atari_kusa, 0, 0, LVar0)
        EVT_WAIT(1)
        EVT_SET(LVar0, -2)
        EVT_CALL(TranslateModel, MODEL_ea_1, 0, 0, LVar0)
        EVT_CALL(TranslateModel, MODEL_ea_2, 0, 0, LVar0)
        EVT_CALL(TranslateModel, MODEL_eb_1, 0, 0, LVar0)
        EVT_CALL(TranslateModel, MODEL_eb_2, 0, 0, LVar0)
        EVT_CALL(TranslateModel, MODEL_ec_1, 0, 0, LVar0)
        EVT_CALL(TranslateModel, MODEL_ec_2, 0, 0, LVar0)
        EVT_CALL(TranslateModel, MODEL_atari_kusa, 0, 0, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(TranslateModel, MODEL_ea_1, 0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_ea_2, 0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_eb_1, 0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_eb_2, 0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_ec_1, 0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_ec_2, 0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_atari_kusa, 0, 0, 0)
    EVT_WAIT(20)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, -0x8000)
    EVT_WAIT(2)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, -0x10000)
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, 301, 0, -27)
    EVT_CALL(MakeLerp, 0, 30, 50, EASING_COS_IN_OUT)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(GetFlowerNormal), MODEL_ea_1, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_ea_1, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_ea_2, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(N(GetFlowerNormal), MODEL_eb_1, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_eb_1, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_eb_2, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(N(GetFlowerNormal), MODEL_ec_1, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_ec_1, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_ec_2, LVar0, LVar7, LVar8, LVar9)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, 301, 0, -27)
    EVT_CALL(MakeLerp, 30, -30, 50, EASING_COS_IN_OUT)
    EVT_LABEL(20)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(GetFlowerNormal), MODEL_ea_1, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_ea_1, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_ea_2, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(N(GetFlowerNormal), MODEL_eb_1, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_eb_1, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_eb_2, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(N(GetFlowerNormal), MODEL_ec_1, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_ec_1, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_ec_2, LVar0, LVar7, LVar8, LVar9)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, 301, 0, -27)
    EVT_CALL(MakeLerp, -30, 0, 50, EASING_COS_IN_OUT)
    EVT_LABEL(30)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(GetFlowerNormal), MODEL_ea_1, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_ea_1, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_ea_2, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(N(GetFlowerNormal), MODEL_eb_1, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_eb_1, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_eb_2, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(N(GetFlowerNormal), MODEL_ec_1, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_ec_1, LVar0, LVar7, LVar8, LVar9)
    EVT_CALL(RotateModel, MODEL_ec_2, LVar0, LVar7, LVar8, LVar9)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, -0x8000)
    EVT_WAIT(2)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, 0)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_WaitForPlayerNearby) = {
    EVT_LABEL(0)
        EVT_CALL(AwaitPlayerApproach, 350, 0, 50)
        EVT_EXEC_WAIT(N(EVS_LaughingFlowers))
        EVT_CALL(AwaitPlayerLeave, 350, 0, 50)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupExitHint) = {
    EVT_CALL(SetTexPanner, MODEL_ea_2, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_eb_2, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_ec_2, TEX_PANNER_1)
    EVT_EXEC(N(EVS_WaitForPlayerNearby))
    EVT_RETURN
    EVT_END
};
