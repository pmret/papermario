#include "common.h"
#include "battle/battle.h"
#include "mapfs/omo_bt01_shape.h"
#include "model.h"

#define NAMESPACE b_area_omo3_omo_01

extern EvtScript N(updateModels);

s32 N(modelList)[] = { MODEL_uma };

typedef struct Omo01Struct {
    /* 0x00 */ f32 offsetX;
    /* 0x04 */ f32 offsetZ;
    /* 0x08 */ f32 rotSpeed;
    /* 0x0C */ f32 angle;
    /* 0x10 */ s32 modelID;
    /* 0x14 */ s32 unk_14;
} Omo01Struct; // size = 0x18

API_CALLABLE(N(update_model_uma)) {
    Omo01Struct* ptr;
    Model* model;
    f32 rotZ;
    f32 offsetY;
    s32 i;
    Matrix4f mtx1;
    Matrix4f mtx2;

    if (isInitialCall) {
        ptr = heap_malloc(sizeof(*ptr));
        script->functionTempPtr[0] = ptr;

        for (i = 0; i == 0; i++, ptr++) {
            ptr->modelID = N(modelList)[i];
            ptr->unk_14 = ((s32*)N(updateModels))[i]; // WTF ???
            model = get_model_from_list_index(get_model_list_index_from_tree_index(ptr->modelID));
            ptr->offsetX = 0.0f;
            ptr->offsetZ = 0.0f;
            ptr->rotSpeed = 3.5f;
            ptr->angle = 0.0f;
        }
    }

    ptr = script->functionTempPtr[0];
    for (i = 0; i == 0; i++, ptr++) {
        ptr->angle += ptr->rotSpeed;
        ptr->angle = clamp_angle(ptr->angle);

        rotZ = sin_rad(ptr->angle * 3.14f / 180.0f) * 20.0f; // the value of PI xD
        offsetY = SQ(rotZ) / 90.0f;

        model = get_model_from_list_index(get_model_list_index_from_tree_index(ptr->modelID));
        model->flags |= MODEL_FLAG_USES_TRANSFORM_MATRIX | MODEL_FLAG_HAS_TRANSFORM_APPLIED;
        guTranslateF(mtx1, -ptr->offsetX, 0.0f, -ptr->offsetZ);
        guRotateF(mtx2, rotZ, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtx1, mtx2, model->transformMatrix);
        guTranslateF(mtx1, ptr->offsetX, offsetY, ptr->offsetZ);
        guMtxCatF(model->transformMatrix, mtx1, model->transformMatrix);
    }
    return ApiStatus_BLOCK;
}

EvtScript N(updateModels) = {
    EVT_CALL(N(update_model_uma))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_THREAD
        EVT_SETF(LVar0, EVT_FLOAT(0.0))
        EVT_SETF(LVar1, EVT_FLOAT(0.0))
        EVT_LOOP(0)
            EVT_CALL(RotateModel, MODEL_o367, LVar1, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_hari, LVar0, 0, 0, 1)
            EVT_SUBF(LVar0, EVT_FLOAT(0.6))
            EVT_SUBF(LVar1, EVT_FLOAT(7.2))
            EVT_CALL(ClampAngleFloat, LVar0)
            EVT_CALL(ClampAngleFloat, LVar1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC(N(updateModels))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt01_shape",
    .hit = "omo_bt01_hit",
    .bg = "omo_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
