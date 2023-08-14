#include "mim_06.h"
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

API_CALLABLE(N(GetWitherTranslation)) {
    Bytecode* args = script->ptrReadPos;
    s32 angle = evt_get_variable(script, *args++);

    evt_set_variable(script, *args++, sin_deg(angle) * 10.0f);
    return ApiStatus_DONE2;
}

s32 N(FlowerModels_South)[] = {
    MODEL_sa_1, MODEL_sa_2,
    MODEL_sb_1, MODEL_sb_2,
    MODEL_sc_1, MODEL_sc_2,
};

s32 N(FlowerModels_West)[] = {
    MODEL_wa_1, MODEL_wa_2,
    MODEL_wb_1, MODEL_wb_2,
    MODEL_wc_1, MODEL_wc_2,
};

s32 N(FlowerModels_North)[] = {
    MODEL_na_1, MODEL_na_2,
    MODEL_nb_1, MODEL_nb_2,
    MODEL_nc_1, MODEL_nc_2,
};

s32 N(FlowerModels_East)[] = {
    MODEL_ea_1, MODEL_ea_2,
    MODEL_eb_1, MODEL_eb_2,
    MODEL_ec_1, MODEL_ec_2,
};

EvtScript N(EVS_FlowersWither) = {
    EVT_CALL(RandInt, 20, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_WAIT(LVar0)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_CALL(RandInt, 20, LVarC)
    EVT_SUB(LVarC, 10)
    EVT_LOOP(60)
        EVT_ADD(LVar0, LVarC)
        EVT_CALL(N(GetWitherTranslation), LVar0, LVar2)
        EVT_SUB(LVar1, 1)
        EVT_CALL(TranslateModel, LVarA, 0, LVar1, LVar2)
        EVT_CALL(N(GetFlowerNormal), LVarA, LVar7, LVar8, LVar9)
        EVT_CALL(RotateModel, LVarA, LVar0, LVar7, LVar8, LVar9)
        EVT_CALL(ScaleModel, LVarA, LVar3, LVar3, LVar3)
        EVT_CALL(TranslateModel, LVarB, 0, LVar1, LVar2)
        EVT_CALL(N(GetFlowerNormal), LVarA, LVar7, LVar8, LVar9)
        EVT_CALL(RotateModel, LVarB, LVar0, LVar7, LVar8, LVar9)
        EVT_CALL(ScaleModel, LVarB, LVar3, LVar3, LVar3)
        EVT_MULF(LVar3, EVT_FLOAT(0.965))
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_CALL(EnableModel, LVarA, FALSE)
    EVT_CALL(EnableModel, LVarB, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InspectFlowers_South) = {
    EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x8000)
    EVT_WAIT(2)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x10000)
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, -10, 0, -300)
    EVT_CALL(MakeLerp, 0, 30, 50, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_USE_BUF(EVT_PTR(N(FlowerModels_South)))
    EVT_LOOP(3)
        EVT_BUF_READ2(LVar2, LVar3)
        EVT_CALL(N(GetFlowerNormal), LVar2, LVar7, LVar8, LVar9)
        EVT_CALL(RotateModel, LVar2, LVar0, LVar7, LVar8, LVar9)
        EVT_CALL(RotateModel, LVar3, LVar0, LVar7, LVar8, LVar9)
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_FLOWERS_LAUGH)
    EVT_CALL(MakeLerp, 30, -30, 50, EASING_COS_IN_OUT)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_USE_BUF(EVT_PTR(N(FlowerModels_South)))
    EVT_LOOP(3)
        EVT_BUF_READ2(LVar2, LVar3)
        EVT_CALL(N(GetFlowerNormal), LVar2, LVar7, LVar8, LVar9)
        EVT_CALL(RotateModel, LVar2, LVar0, LVar7, LVar8, LVar9)
        EVT_CALL(RotateModel, LVar3, LVar0, LVar7, LVar8, LVar9)
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_FLOWERS_LAUGH)
    EVT_CALL(MakeLerp, -30, 0, 50, EASING_COS_IN_OUT)
    EVT_LABEL(20)
    EVT_CALL(UpdateLerp)
    EVT_USE_BUF(EVT_PTR(N(FlowerModels_South)))
    EVT_LOOP(3)
        EVT_BUF_READ2(LVar2, LVar3)
        EVT_CALL(N(GetFlowerNormal), LVar2, LVar7, LVar8, LVar9)
        EVT_CALL(RotateModel, LVar2, LVar0, LVar7, LVar8, LVar9)
        EVT_CALL(RotateModel, LVar3, LVar0, LVar7, LVar8, LVar9)
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x8000)
    EVT_WAIT(2)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InspectFlowers_West) = {
    EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, -0x8000)
    EVT_WAIT(2)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, -0x10000)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_WITHER, SOUND_SPACE_DEFAULT, -300, 0, -10)
    EVT_USE_BUF(EVT_PTR(N(FlowerModels_West)))
    EVT_BUF_READ2(LVarA, LVarB)
    EVT_EXEC(N(EVS_FlowersWither))
    EVT_BUF_READ2(LVarA, LVarB)
    EVT_EXEC(N(EVS_FlowersWither))
    EVT_BUF_READ2(LVarA, LVarB)
    EVT_EXEC(N(EVS_FlowersWither))
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InspectFlowers_North) = {
    EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, -0x8000)
    EVT_WAIT(2)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, -0x10000)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_WITHER, SOUND_SPACE_DEFAULT, 10, 0, 300)
    EVT_USE_BUF(EVT_PTR(N(FlowerModels_North)))
    EVT_BUF_READ2(LVarA, LVarB)
    EVT_EXEC(N(EVS_FlowersWither))
    EVT_BUF_READ2(LVarA, LVarB)
    EVT_EXEC(N(EVS_FlowersWither))
    EVT_BUF_READ2(LVarA, LVarB)
    EVT_EXEC(N(EVS_FlowersWither))
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InspectFlowers_East) = {
    EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, -0x8000)
    EVT_WAIT(2)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, -0x10000)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_WITHER, SOUND_SPACE_DEFAULT, 300, 0, -10)
    EVT_USE_BUF(EVT_PTR(N(FlowerModels_East)))
    EVT_BUF_READ2(LVarA, LVarB)
    EVT_EXEC(N(EVS_FlowersWither))
    EVT_BUF_READ2(LVarA, LVarB)
    EVT_EXEC(N(EVS_FlowersWither))
    EVT_BUF_READ2(LVarA, LVarB)
    EVT_EXEC(N(EVS_FlowersWither))
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802439F8_BA8178) = {
    EVT_CALL(SetTexPanner, MODEL_sa_2, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_sb_2, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_sc_2, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_wa_2, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_wb_2, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_wc_2, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_na_2, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_nb_2, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_nc_2, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_ea_2, TEX_PANNER_3)
    EVT_CALL(SetTexPanner, MODEL_eb_2, TEX_PANNER_3)
    EVT_CALL(SetTexPanner, MODEL_ec_2, TEX_PANNER_3)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_InspectFlowers_South)), TRIGGER_WALL_PRESS_A, COLLIDER_o416, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_InspectFlowers_West)), TRIGGER_WALL_PRESS_A, COLLIDER_o418, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_InspectFlowers_North)), TRIGGER_WALL_PRESS_A, COLLIDER_o417, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_InspectFlowers_East)), TRIGGER_WALL_PRESS_A, COLLIDER_o331, 1, 0)
    EVT_RETURN
    EVT_END
};
