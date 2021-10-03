#include "common.h"
#include "map.h"

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

EvtSource N(searchBush) = SCRIPT({
    buf_use EVT_VAR(0);
    buf_read EVT_VAR(1) EVT_VAR(2) EVT_VAR(3) EVT_VAR(4);
    GetPlayerPos(EVT_VAR(5), EVT_VAR(15), EVT_VAR(7));
    spawn {
        EVT_FLAG(0) = 0;
        if (EVT_VAR(1) != NULL) {
            loop 5 {
                buf_use EVT_VAR(1);
                buf_read EVT_VAR(2);
                loop EVT_VAR(2) {
                    buf_read EVT_VAR(3);
                    N(TransformFoliage)(EVT_VAR(3), 0.1, 1, EVT_VAR(15), 0);
                    if (EVT_FLAG(0) == 0) {
                        EVT_FLAG(0) = 1;
                        PlaySoundAtModel(EVT_VAR(3), 339, 0);
                    }
                }
                sleep 1;
                buf_use EVT_VAR(1);
                buf_read EVT_VAR(2);
                loop EVT_VAR(2) {
                    buf_read EVT_VAR(3);
                    N(TransformFoliage)(EVT_VAR(3), 0.1, -1, EVT_VAR(15), 0);
                }
                sleep 1;
            }
            buf_use EVT_VAR(1);
            buf_read EVT_VAR(2);
            loop EVT_VAR(2) {
                buf_read EVT_VAR(3);
                TranslateModel(EVT_VAR(3), 0, 0, 0);
            }
            sleep 1;
        }
    }
    spawn {
        if (EVT_VAR(2) != NULL) {
            buf_use EVT_VAR(2);
            buf_read EVT_VAR(3);
            loop EVT_VAR(3) {
                buf_read EVT_VAR(4);
                buf_read EVT_VAR(5) EVT_VAR(6) EVT_VAR(7);
                buf_read EVT_VAR(8) EVT_VAR(9) EVT_VAR(10);
                if (EVT_VAR(10) == 0) {
                    DropItemEntity(EVT_VAR(4), EVT_VAR(5), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9));
                } else {
                    GetValueByRef(EVT_VAR(10), EVT_VAR(11));
                    if (EVT_VAR(11) == 0) {
                        SetValueByRef(EVT_VAR(10), 1);
                        DropItemEntity(EVT_VAR(4), EVT_VAR(5), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9));
                    }
                }
            }
        }
    }
    sleep 15;
    if (EVT_VAR(4) != NULL) {
        await EVT_VAR(4);
    }
});

EvtSource N(shakeTree) = SCRIPT({
    timescale 2.0;
    buf_use EVT_VAR(0);
    buf_read EVT_VAR(1) EVT_VAR(2) EVT_VAR(3) EVT_VAR(4);
    buf_read EVT_VAR(5);
    GetPlayerPos(EVT_VAR(6), EVT_VAR(15), EVT_VAR(8));
    PlaySound(0x165);
    PlaySound(0x166);
    spawn {
        EVT_FLAG(0) = 0;
        if (EVT_VAR(1) != NULL) {
            sleep 1;
            loop 5 {
                buf_use EVT_VAR(1);
                buf_read EVT_VAR(2);
                loop EVT_VAR(2) {
                    buf_read EVT_VAR(3);
                    N(TransformFoliage)(EVT_VAR(3), 0.1, 0.2, EVT_VAR(15), 0);
                    if (EVT_FLAG(0) == 0) {
                        EVT_FLAG(0) = 1;
                        PlaySoundAtModel(EVT_VAR(3), 358, 0);
                    }
                }
                sleep 1;
                buf_use EVT_VAR(1);
                buf_read EVT_VAR(2);
                loop EVT_VAR(2) {
                    buf_read EVT_VAR(3);
                    N(TransformFoliage)(EVT_VAR(3), 0.1, -0.2, EVT_VAR(15), 0);
                }
                sleep 1;
            }
            buf_use EVT_VAR(1);
            buf_read EVT_VAR(2);
            loop EVT_VAR(2) {
                buf_read EVT_VAR(3);
                TranslateModel(EVT_VAR(3), 0, 0, 0);
            }
            sleep 1;
        }
    }
    spawn {
        EVT_FLAG(0) = 0;
        if (EVT_VAR(2) != NULL) {
            loop 5 {
                buf_use EVT_VAR(2);
                buf_read EVT_VAR(3);
                loop EVT_VAR(3) {
                    buf_read EVT_VAR(4);
                    N(TransformFoliage)(EVT_VAR(4), 0.1, 0.2, EVT_VAR(15), 0);
                    if (EVT_FLAG(0) == 0) {
                        EVT_FLAG(0) = 1;
                        PlaySoundAtModel(EVT_VAR(4), 357, 0);
                    }
                }
                sleep 1;
                buf_use EVT_VAR(2);
                buf_read EVT_VAR(3);
                loop EVT_VAR(3) {
                    buf_read EVT_VAR(4);
                    N(TransformFoliage)(EVT_VAR(4), 0.1, -0.2, EVT_VAR(15), 0);
                }
                sleep 1;
            }
            buf_use EVT_VAR(2);
            buf_read EVT_VAR(3);
            loop EVT_VAR(3) {
                buf_read EVT_VAR(4);
                TranslateModel(EVT_VAR(4), 0, 0, 0);
            }
            sleep 1;
        }
    }
    spawn {
        if (EVT_VAR(3) != NULL) {
            buf_use EVT_VAR(3);
            buf_read EVT_VAR(4);
            loop EVT_VAR(4) {
                buf_read EVT_VAR(5);
                buf_read EVT_VAR(6) EVT_VAR(7) EVT_VAR(8);
                buf_read EVT_VAR(9) EVT_VAR(10) EVT_VAR(11);
                if (EVT_VAR(11) == 0) {
                    DropItemEntity(EVT_VAR(5), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9), EVT_VAR(10));
                } else {
                    GetValueByRef(EVT_VAR(11), EVT_VAR(12));
                    if (EVT_VAR(12) == 0) {
                        SetValueByRef(EVT_VAR(11), 1);
                        DropItemEntity(EVT_VAR(5), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9), EVT_VAR(10));
                    }
                }
            }
        }
    }
    spawn {
        if (EVT_VAR(4) != NULL) {
            buf_use EVT_VAR(4);
            buf_read EVT_VAR(5);
            loop EVT_VAR(5) {
                buf_read EVT_VAR(6) EVT_VAR(7) EVT_VAR(8);
                PlayEffect(0x14, 0, EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), 100, 0, 0, 0, 0, 0, 0, 0, 0);
            }
        }
    }
    if (EVT_VAR(5) != NULL) {
        await EVT_VAR(5);
    }
    sleep 15;
});
