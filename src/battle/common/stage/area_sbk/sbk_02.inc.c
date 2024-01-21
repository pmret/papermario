#include "battle/battle.h"
#include "mapfs/sbk_bt02_shape.h"

#include "effects.h"
#include "model.h"

#define NAMESPACE A(sbk_02)

API_CALLABLE(N(UpdateSunPos)) {
    Bytecode* args = script->ptrReadPos;
    s32 outPosX;
    s32 outPosY;
    s32 outPosZ;
    f32 x;
    f32 y;
    f32 z;
    f32 angle;
#if !VERSION_PAL
    Matrix4f mtxUnused;
#endif

    angle = evt_get_variable(script, *args++) / 10.0;
    angle = angle * TAU;
    angle = angle / 360.0f;

    outPosX = *args++;
    outPosY = *args++;
    outPosZ = *args++;

    x = sin_rad(angle) * 150.0f + 0.0f;
    y = cos_rad(angle) * 150.0f + 0.0f;
    z = -252.0f;

    x -= script->varTable[11];
    y -= script->varTable[12];
    z -= script->varTable[13];

    evt_set_float_variable(script, outPosX, x);
    evt_set_float_variable(script, outPosY, y);
    evt_set_float_variable(script, outPosZ, z);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetModelPos)) {
    s32 modelID = script->varTable[10];
    s32 modelIdx = get_model_list_index_from_tree_index(modelID);
    Model* model = get_model_from_list_index(modelIdx);

    script->varTable[11] = (s32) model->center.x;
    script->varTable[12] = (s32) model->center.y;
    script->varTable[13] = (s32) model->center.z;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdateSunPos) = {
    Set(LVarA, LVar0) // modelID
    Set(LVar7, LVar1) // initialPhase
    Mul(LVar7, 10)
    Call(N(GetModelPos))
    Label(0)
        Add(LVar7, 1)
        IfGt(LVar7, 3599)
            Sub(LVar7, 3600)
        EndIf
        Call(N(UpdateSunPos), LVar7, LVar0, LVar1, LVar2)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Set(LVar0, MODEL_g60)
    Set(LVar1, 0)
    Exec(N(EVS_UpdateSunPos))
    Set(LVar0, MODEL_g63)
    Set(LVar1, 120)
    Exec(N(EVS_UpdateSunPos))
    Set(LVar0, MODEL_g62)
    Set(LVar1, 240)
    Exec(N(EVS_UpdateSunPos))
    PlayEffect(EFFECT_SUN, 0, 0, 0, 0, 0, 0, 0)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    MODEL_o322,
    MODEL_o321,
    MODEL_o320,
    MODEL_o319,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "sbk_tex",
    .shape = "sbk_bt02_shape",
    .hit = "sbk_bt02_hit",
    .bg = "sbk_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
