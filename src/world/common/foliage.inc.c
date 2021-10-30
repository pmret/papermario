#include "common.h"
#include "npc.h"
#include "model.h"

typedef struct FoliageModelList {
    s32 count;
    s32 models[0];
} FoliageModelList;

typedef struct FoliageDropList {
    s32 count;
    struct {
        s32 itemID;
        Vec3i pos;
        s32 spawnMode;
        Bytecode pickupFlag;
        Bytecode spawnFlag;
    } drops[0];
} FoliageDropList;

typedef struct FoliageVectorList {
    s32 count;
    Vec3i vectors[0];
} FoliageVectorList;

typedef struct SearchBushConfig {
    FoliageModelList* bush;
    FoliageDropList* drops;
    FoliageVectorList* vectors;
    EvtSource* callback;
} SearchBushConfig;

typedef struct ShakeTreeConfig {
    FoliageModelList* leaves;
    FoliageModelList* trunk;
    FoliageDropList* drops;
    FoliageVectorList* vectors;
    EvtSource* callback;
} ShakeTreeConfig;

void N(foliage_setup_shear_mtx)(Matrix4f mtx, f32 scale, f32 xAmount, f32 zAmount) {
    guMtxIdentF(mtx);
    mtx[1][0] = scale * xAmount;
    mtx[1][1] = 1.0f;
    mtx[1][2] = scale * zAmount;
}

/// @apiparam int model ID
/// @apiparam float scale
/// @apiparam float dx
/// @apiparam float dy
/// @apiparam float dz
ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelListIndex = get_model_list_index_from_tree_index(evt_get_variable(script, *args++));
    f32 scale = evt_get_float_variable(script, *args++);
    f32 dx = evt_get_float_variable(script, *args++);
    f32 dy = evt_get_float_variable(script, *args++);
    f32 dz = evt_get_float_variable(script, *args++);
    Model* model = get_model_from_list_index(modelListIndex);
    Matrix4f mtx;

    if (!(model->flags & 0x400)) {
        guTranslateF(model->transformMatrix, 0.0f, dy, 0.0f);
        N(foliage_setup_shear_mtx)(mtx, scale, dx, dz);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
        guTranslateF(mtx, 0.0f, -dy, 0.0f);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
        model->flags |= 0x1400;
    } else {
        guTranslateF(mtx, 0.0f, dy, 0.0f);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
        N(foliage_setup_shear_mtx)(mtx, scale, dx, dz);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
        guTranslateF(mtx, 0.0f, -dy, 0.0f);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
    }

    return ApiStatus_DONE2;
}

EvtSource N(searchBush) = {
    EVT_USE_BUF(EVT_VAR(0))
    EVT_BUF_READ4(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
    EVT_CALL(GetPlayerPos, EVT_VAR(5), EVT_VAR(15), EVT_VAR(7))
    EVT_THREAD
        EVT_SET(EVT_FLAG(0), 0)
        EVT_IF_NE(EVT_VAR(1), 0)
            EVT_LOOP(5)
                EVT_USE_BUF(EVT_VAR(1))
                EVT_BUF_READ1(EVT_VAR(2))
                EVT_LOOP(EVT_VAR(2))
                    EVT_BUF_READ1(EVT_VAR(3))
                    EVT_CALL(N(TransformFoliage), EVT_VAR(3), EVT_FIXED(0.1), 1, EVT_VAR(15), 0)
                    EVT_IF_EQ(EVT_FLAG(0), 0)
                        EVT_SET(EVT_FLAG(0), 1)
                        EVT_CALL(PlaySoundAtModel, EVT_VAR(3), 339, 0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
                EVT_USE_BUF(EVT_VAR(1))
                EVT_BUF_READ1(EVT_VAR(2))
                EVT_LOOP(EVT_VAR(2))
                    EVT_BUF_READ1(EVT_VAR(3))
                    EVT_CALL(N(TransformFoliage), EVT_VAR(3), EVT_FIXED(0.1), -1, EVT_VAR(15), 0)
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_USE_BUF(EVT_VAR(1))
            EVT_BUF_READ1(EVT_VAR(2))
            EVT_LOOP(EVT_VAR(2))
                EVT_BUF_READ1(EVT_VAR(3))
                EVT_CALL(TranslateModel, EVT_VAR(3), 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT_FRAMES(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(EVT_VAR(2), 0)
            EVT_USE_BUF(EVT_VAR(2))
            EVT_BUF_READ1(EVT_VAR(3))
            EVT_LOOP(EVT_VAR(3))
                EVT_BUF_READ1(EVT_VAR(4))
                EVT_BUF_READ3(EVT_VAR(5), EVT_VAR(6), EVT_VAR(7))
                EVT_BUF_READ3(EVT_VAR(8), EVT_VAR(9), EVT_VAR(10))
                EVT_IF_EQ(EVT_VAR(10), 0)
                    EVT_CALL(DropItemEntity, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9))
                EVT_ELSE
                    EVT_CALL(GetValueByRef, EVT_VAR(10), EVT_VAR(11))
                    EVT_IF_EQ(EVT_VAR(11), 0)
                        EVT_CALL(SetValueByRef, EVT_VAR(10), 1)
                        EVT_CALL(DropItemEntity, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9))
                    EVT_END_IF
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT_FRAMES(15)
    EVT_IF_NE(EVT_VAR(4), 0)
        EVT_EXEC_WAIT(EVT_VAR(4))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(shakeTree) = {
    EVT_SET_TIMESCALE(EVT_FIXED(2.0))
    EVT_USE_BUF(EVT_VAR(0))
    EVT_BUF_READ4(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
    EVT_BUF_READ1(EVT_VAR(5))
    EVT_CALL(GetPlayerPos, EVT_VAR(6), EVT_VAR(15), EVT_VAR(8))
    EVT_CALL(PlaySound, SOUND_SMASH_GOOMNUT_TREE)
    EVT_CALL(PlaySound, 358)
    EVT_THREAD
        EVT_SET(EVT_FLAG(0), 0)
        EVT_IF_NE(EVT_VAR(1), 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(5)
                EVT_USE_BUF(EVT_VAR(1))
                EVT_BUF_READ1(EVT_VAR(2))
                EVT_LOOP(EVT_VAR(2))
                    EVT_BUF_READ1(EVT_VAR(3))
                    EVT_CALL(N(TransformFoliage), EVT_VAR(3), EVT_FIXED(0.1), EVT_FIXED(0.2), EVT_VAR(15), 0)
                    EVT_IF_EQ(EVT_FLAG(0), 0)
                        EVT_SET(EVT_FLAG(0), 1)
                        EVT_CALL(PlaySoundAtModel, EVT_VAR(3), 358, 0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
                EVT_USE_BUF(EVT_VAR(1))
                EVT_BUF_READ1(EVT_VAR(2))
                EVT_LOOP(EVT_VAR(2))
                    EVT_BUF_READ1(EVT_VAR(3))
                    EVT_CALL(N(TransformFoliage), EVT_VAR(3), EVT_FIXED(0.1), EVT_FIXED(-0.2), EVT_VAR(15), 0)
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_USE_BUF(EVT_VAR(1))
            EVT_BUF_READ1(EVT_VAR(2))
            EVT_LOOP(EVT_VAR(2))
                EVT_BUF_READ1(EVT_VAR(3))
                EVT_CALL(TranslateModel, EVT_VAR(3), 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT_FRAMES(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(EVT_FLAG(0), 0)
        EVT_IF_NE(EVT_VAR(2), 0)
            EVT_LOOP(5)
                EVT_USE_BUF(EVT_VAR(2))
                EVT_BUF_READ1(EVT_VAR(3))
                EVT_LOOP(EVT_VAR(3))
                    EVT_BUF_READ1(EVT_VAR(4))
                    EVT_CALL(N(TransformFoliage), EVT_VAR(4), EVT_FIXED(0.1), EVT_FIXED(0.2), EVT_VAR(15), 0)
                    EVT_IF_EQ(EVT_FLAG(0), 0)
                        EVT_SET(EVT_FLAG(0), 1)
                        EVT_CALL(PlaySoundAtModel, EVT_VAR(4), 357, 0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
                EVT_USE_BUF(EVT_VAR(2))
                EVT_BUF_READ1(EVT_VAR(3))
                EVT_LOOP(EVT_VAR(3))
                    EVT_BUF_READ1(EVT_VAR(4))
                    EVT_CALL(N(TransformFoliage), EVT_VAR(4), EVT_FIXED(0.1), EVT_FIXED(-0.2), EVT_VAR(15), 0)
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_USE_BUF(EVT_VAR(2))
            EVT_BUF_READ1(EVT_VAR(3))
            EVT_LOOP(EVT_VAR(3))
                EVT_BUF_READ1(EVT_VAR(4))
                EVT_CALL(TranslateModel, EVT_VAR(4), 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT_FRAMES(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(EVT_VAR(3), 0)
            EVT_USE_BUF(EVT_VAR(3))
            EVT_BUF_READ1(EVT_VAR(4))
            EVT_LOOP(EVT_VAR(4))
                EVT_BUF_READ1(EVT_VAR(5))
                EVT_BUF_READ3(EVT_VAR(6), EVT_VAR(7), EVT_VAR(8))
                EVT_BUF_READ3(EVT_VAR(9), EVT_VAR(10), EVT_VAR(11))
                EVT_IF_EQ(EVT_VAR(11), 0)
                    EVT_CALL(DropItemEntity, EVT_VAR(5), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9), EVT_VAR(10))
                EVT_ELSE
                    EVT_CALL(GetValueByRef, EVT_VAR(11), EVT_VAR(12))
                    EVT_IF_EQ(EVT_VAR(12), 0)
                        EVT_CALL(SetValueByRef, EVT_VAR(11), 1)
                        EVT_CALL(DropItemEntity, EVT_VAR(5), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9), EVT_VAR(10))
                    EVT_END_IF
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(EVT_VAR(4), 0)
            EVT_USE_BUF(EVT_VAR(4))
            EVT_BUF_READ1(EVT_VAR(5))
            EVT_LOOP(EVT_VAR(5))
                EVT_BUF_READ3(EVT_VAR(6), EVT_VAR(7), EVT_VAR(8))
                EVT_CALL(PlayEffect, 0x14, 0, EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), 100, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_IF_NE(EVT_VAR(5), 0)
        EVT_EXEC_WAIT(EVT_VAR(5))
    EVT_END_IF
    EVT_WAIT_FRAMES(15)
    EVT_RETURN
    EVT_END
};
