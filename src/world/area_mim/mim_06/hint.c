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

    evt_set_variable(script, *args++, FLOAT_TO_FIXED(x));
    evt_set_variable(script, *args++, FLOAT_TO_FIXED(y));
    evt_set_variable(script, *args++, FLOAT_TO_FIXED(z));
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
    Call(RandInt, 20, LVar0)
    Add(LVar0, 1)
    Wait(LVar0)
    Set(LVar0, 0)
    Set(LVar1, 0)
    SetF(LVar3, Float(1.0))
    Call(RandInt, 20, LVarC)
    Sub(LVarC, 10)
    Loop(60)
        Add(LVar0, LVarC)
        Call(N(GetWitherTranslation), LVar0, LVar2)
        Sub(LVar1, 1)
        Call(TranslateModel, LVarA, 0, LVar1, LVar2)
        Call(N(GetFlowerNormal), LVarA, LVar7, LVar8, LVar9)
        Call(RotateModel, LVarA, LVar0, LVar7, LVar8, LVar9)
        Call(ScaleModel, LVarA, LVar3, LVar3, LVar3)
        Call(TranslateModel, LVarB, 0, LVar1, LVar2)
        Call(N(GetFlowerNormal), LVarA, LVar7, LVar8, LVar9)
        Call(RotateModel, LVarB, LVar0, LVar7, LVar8, LVar9)
        Call(ScaleModel, LVarB, LVar3, LVar3, LVar3)
        MulF(LVar3, Float(0.965))
        Wait(2)
    EndLoop
    Call(EnableModel, LVarA, false)
    Call(EnableModel, LVarB, false)
    Return
    End
};

EvtScript N(EVS_InspectFlowers_South) = {
    Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x8000)
    Wait(2)
    Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x10000)
    Call(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, -10, 0, -300)
    Call(MakeLerp, 0, 30, 50, EASING_COS_IN_OUT)
    Label(0)
    Call(UpdateLerp)
    UseBuf(Ref(N(FlowerModels_South)))
    Loop(3)
        BufRead2(LVar2, LVar3)
        Call(N(GetFlowerNormal), LVar2, LVar7, LVar8, LVar9)
        Call(RotateModel, LVar2, LVar0, LVar7, LVar8, LVar9)
        Call(RotateModel, LVar3, LVar0, LVar7, LVar8, LVar9)
    EndLoop
    Wait(1)
    IfEq(LVar1, 1)
        Goto(0)
    EndIf
    Call(PlaySound, SOUND_FLOWERS_LAUGH)
    Call(MakeLerp, 30, -30, 50, EASING_COS_IN_OUT)
    Label(10)
    Call(UpdateLerp)
    UseBuf(Ref(N(FlowerModels_South)))
    Loop(3)
        BufRead2(LVar2, LVar3)
        Call(N(GetFlowerNormal), LVar2, LVar7, LVar8, LVar9)
        Call(RotateModel, LVar2, LVar0, LVar7, LVar8, LVar9)
        Call(RotateModel, LVar3, LVar0, LVar7, LVar8, LVar9)
    EndLoop
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(PlaySound, SOUND_FLOWERS_LAUGH)
    Call(MakeLerp, -30, 0, 50, EASING_COS_IN_OUT)
    Label(20)
    Call(UpdateLerp)
    UseBuf(Ref(N(FlowerModels_South)))
    Loop(3)
        BufRead2(LVar2, LVar3)
        Call(N(GetFlowerNormal), LVar2, LVar7, LVar8, LVar9)
        Call(RotateModel, LVar2, LVar0, LVar7, LVar8, LVar9)
        Call(RotateModel, LVar3, LVar0, LVar7, LVar8, LVar9)
    EndLoop
    Wait(1)
    IfEq(LVar1, 1)
        Goto(20)
    EndIf
    Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x8000)
    Wait(2)
    Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
    Return
    End
};

EvtScript N(EVS_InspectFlowers_West) = {
    Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, -0x8000)
    Wait(2)
    Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, -0x10000)
    Wait(15)
    Call(PlaySoundAt, SOUND_FLOWERS_WITHER, SOUND_SPACE_DEFAULT, -300, 0, -10)
    UseBuf(Ref(N(FlowerModels_West)))
    BufRead2(LVarA, LVarB)
    Exec(N(EVS_FlowersWither))
    BufRead2(LVarA, LVarB)
    Exec(N(EVS_FlowersWither))
    BufRead2(LVarA, LVarB)
    Exec(N(EVS_FlowersWither))
    Unbind
    Return
    End
};

EvtScript N(EVS_InspectFlowers_North) = {
    Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, -0x8000)
    Wait(2)
    Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, -0x10000)
    Wait(15)
    Call(PlaySoundAt, SOUND_FLOWERS_WITHER, SOUND_SPACE_DEFAULT, 10, 0, 300)
    UseBuf(Ref(N(FlowerModels_North)))
    BufRead2(LVarA, LVarB)
    Exec(N(EVS_FlowersWither))
    BufRead2(LVarA, LVarB)
    Exec(N(EVS_FlowersWither))
    BufRead2(LVarA, LVarB)
    Exec(N(EVS_FlowersWither))
    Unbind
    Return
    End
};

EvtScript N(EVS_InspectFlowers_East) = {
    Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, -0x8000)
    Wait(2)
    Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, -0x10000)
    Wait(15)
    Call(PlaySoundAt, SOUND_FLOWERS_WITHER, SOUND_SPACE_DEFAULT, 300, 0, -10)
    UseBuf(Ref(N(FlowerModels_East)))
    BufRead2(LVarA, LVarB)
    Exec(N(EVS_FlowersWither))
    BufRead2(LVarA, LVarB)
    Exec(N(EVS_FlowersWither))
    BufRead2(LVarA, LVarB)
    Exec(N(EVS_FlowersWither))
    Unbind
    Return
    End
};

EvtScript N(D_802439F8_BA8178) = {
    Call(SetTexPanner, MODEL_sa_2, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_sb_2, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_sc_2, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_wa_2, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_wb_2, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_wc_2, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_na_2, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_nb_2, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_nc_2, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_ea_2, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_eb_2, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_ec_2, TEX_PANNER_3)
    BindTrigger(Ref(N(EVS_InspectFlowers_South)), TRIGGER_WALL_PRESS_A, COLLIDER_o416, 1, 0)
    BindTrigger(Ref(N(EVS_InspectFlowers_West)), TRIGGER_WALL_PRESS_A, COLLIDER_o418, 1, 0)
    BindTrigger(Ref(N(EVS_InspectFlowers_North)), TRIGGER_WALL_PRESS_A, COLLIDER_o417, 1, 0)
    BindTrigger(Ref(N(EVS_InspectFlowers_East)), TRIGGER_WALL_PRESS_A, COLLIDER_o331, 1, 0)
    Return
    End
};
