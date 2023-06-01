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
    EVT_SET(LVarA, LVar0) // modelID
    EVT_SET(LVar7, LVar1) // initialPhase
    EVT_MUL(LVar7, 10)
    EVT_CALL(N(GetModelPos))
    EVT_LABEL(0)
        EVT_ADD(LVar7, 1)
        EVT_IF_GT(LVar7, 3599)
            EVT_SUB(LVar7, 3600)
        EVT_END_IF
        EVT_CALL(N(UpdateSunPos), LVar7, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SET(LVar0, MODEL_g60)
    EVT_SET(LVar1, 0)
    EVT_EXEC(N(EVS_UpdateSunPos))
    EVT_SET(LVar0, MODEL_g63)
    EVT_SET(LVar1, 120)
    EVT_EXEC(N(EVS_UpdateSunPos))
    EVT_SET(LVar0, MODEL_g62)
    EVT_SET(LVar1, 240)
    EVT_EXEC(N(EVS_UpdateSunPos))
    EVT_PLAY_EFFECT(EFFECT_SUN, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
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
