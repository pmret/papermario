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
        ItemSpawnMode spawnMode;
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
    Script* callback;
} SearchBushConfig;

typedef struct ShakeTreeConfig {
    FoliageModelList* leaves;
    FoliageModelList* trunk;
    FoliageDropList* drops;
    FoliageVectorList* vectors;
    Script* callback;
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
ApiStatus N(TransformFoliage)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelListIndex = get_model_list_index_from_tree_index(get_variable(script, *args++));
    f32 scale = get_float_variable(script, *args++);
    f32 dx = get_float_variable(script, *args++);
    f32 dy = get_float_variable(script, *args++);
    f32 dz = get_float_variable(script, *args++);
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

Script N(searchBush) = SCRIPT({
    buf_use SI_VAR(0);
    buf_read SI_VAR(1) SI_VAR(2) SI_VAR(3) SI_VAR(4);
    GetPlayerPos(SI_VAR(5), SI_VAR(15), SI_VAR(7));
    spawn {
        SI_FLAG(0) = 0;
        if (SI_VAR(1) != NULL) {
            loop 5 {
                buf_use SI_VAR(1);
                buf_read SI_VAR(2);
                loop SI_VAR(2) {
                    buf_read SI_VAR(3);
                    N(TransformFoliage)(SI_VAR(3), 0.1, 1, SI_VAR(15), 0);
                    if (SI_FLAG(0) == 0) {
                        SI_FLAG(0) = 1;
                        PlaySoundAtModel(SI_VAR(3), 339, 0);
                    }
                }
                sleep 1;
                buf_use SI_VAR(1);
                buf_read SI_VAR(2);
                loop SI_VAR(2) {
                    buf_read SI_VAR(3);
                    N(TransformFoliage)(SI_VAR(3), 0.1, -1, SI_VAR(15), 0);
                }
                sleep 1;
            }
            buf_use SI_VAR(1);
            buf_read SI_VAR(2);
            loop SI_VAR(2) {
                buf_read SI_VAR(3);
                TranslateModel(SI_VAR(3), 0, 0, 0);
            }
            sleep 1;
        }
    }
    spawn {
        if (SI_VAR(2) != NULL) {
            buf_use SI_VAR(2);
            buf_read SI_VAR(3);
            loop SI_VAR(3) {
                buf_read SI_VAR(4);
                buf_read SI_VAR(5) SI_VAR(6) SI_VAR(7);
                buf_read SI_VAR(8) SI_VAR(9) SI_VAR(10);
                if (SI_VAR(10) == 0) {
                    DropItemEntity(SI_VAR(4), SI_VAR(5), SI_VAR(6), SI_VAR(7), SI_VAR(8), SI_VAR(9));
                } else {
                    GetValueByRef(SI_VAR(10), SI_VAR(11));
                    if (SI_VAR(11) == 0) {
                        SetValueByRef(SI_VAR(10), 1);
                        DropItemEntity(SI_VAR(4), SI_VAR(5), SI_VAR(6), SI_VAR(7), SI_VAR(8), SI_VAR(9));
                    }
                }
            }
        }
    }
    sleep 15;
    if (SI_VAR(4) != NULL) {
        await SI_VAR(4);
    }
});

Script N(shakeTree) = SCRIPT({
    timescale 2.0;
    buf_use SI_VAR(0);
    buf_read SI_VAR(1) SI_VAR(2) SI_VAR(3) SI_VAR(4);
    buf_read SI_VAR(5);
    GetPlayerPos(SI_VAR(6), SI_VAR(15), SI_VAR(8));
    PlaySound(0x165);
    PlaySound(0x166);
    spawn {
        SI_FLAG(0) = 0;
        if (SI_VAR(1) != NULL) {
            sleep 1;
            loop 5 {
                buf_use SI_VAR(1);
                buf_read SI_VAR(2);
                loop SI_VAR(2) {
                    buf_read SI_VAR(3);
                    N(TransformFoliage)(SI_VAR(3), 0.1, 0.2, SI_VAR(15), 0);
                    if (SI_FLAG(0) == 0) {
                        SI_FLAG(0) = 1;
                        PlaySoundAtModel(SI_VAR(3), 358, 0);
                    }
                }
                sleep 1;
                buf_use SI_VAR(1);
                buf_read SI_VAR(2);
                loop SI_VAR(2) {
                    buf_read SI_VAR(3);
                    N(TransformFoliage)(SI_VAR(3), 0.1, -0.2, SI_VAR(15), 0);
                }
                sleep 1;
            }
            buf_use SI_VAR(1);
            buf_read SI_VAR(2);
            loop SI_VAR(2) {
                buf_read SI_VAR(3);
                TranslateModel(SI_VAR(3), 0, 0, 0);
            }
            sleep 1;
        }
    }
    spawn {
        SI_FLAG(0) = 0;
        if (SI_VAR(2) != NULL) {
            loop 5 {
                buf_use SI_VAR(2);
                buf_read SI_VAR(3);
                loop SI_VAR(3) {
                    buf_read SI_VAR(4);
                    N(TransformFoliage)(SI_VAR(4), 0.1, 0.2, SI_VAR(15), 0);
                    if (SI_FLAG(0) == 0) {
                        SI_FLAG(0) = 1;
                        PlaySoundAtModel(SI_VAR(4), 357, 0);
                    }
                }
                sleep 1;
                buf_use SI_VAR(2);
                buf_read SI_VAR(3);
                loop SI_VAR(3) {
                    buf_read SI_VAR(4);
                    N(TransformFoliage)(SI_VAR(4), 0.1, -0.2, SI_VAR(15), 0);
                }
                sleep 1;
            }
            buf_use SI_VAR(2);
            buf_read SI_VAR(3);
            loop SI_VAR(3) {
                buf_read SI_VAR(4);
                TranslateModel(SI_VAR(4), 0, 0, 0);
            }
            sleep 1;
        }
    }
    spawn {
        if (SI_VAR(3) != NULL) {
            buf_use SI_VAR(3);
            buf_read SI_VAR(4);
            loop SI_VAR(4) {
                buf_read SI_VAR(5);
                buf_read SI_VAR(6) SI_VAR(7) SI_VAR(8);
                buf_read SI_VAR(9) SI_VAR(10) SI_VAR(11);
                if (SI_VAR(11) == 0) {
                    DropItemEntity(SI_VAR(5), SI_VAR(6), SI_VAR(7), SI_VAR(8), SI_VAR(9), SI_VAR(10));
                } else {
                    GetValueByRef(SI_VAR(11), SI_VAR(12));
                    if (SI_VAR(12) == 0) {
                        SetValueByRef(SI_VAR(11), 1);
                        DropItemEntity(SI_VAR(5), SI_VAR(6), SI_VAR(7), SI_VAR(8), SI_VAR(9), SI_VAR(10));
                    }
                }
            }
        }
    }
    spawn {
        if (SI_VAR(4) != NULL) {
            buf_use SI_VAR(4);
            buf_read SI_VAR(5);
            loop SI_VAR(5) {
                buf_read SI_VAR(6) SI_VAR(7) SI_VAR(8);
                PlayEffect(0x14, 0, SI_VAR(6), SI_VAR(7), SI_VAR(8), 100, 0, 0, 0, 0, 0, 0, 0, 0);
            }
        }
    }
    if (SI_VAR(5) != NULL) {
        await SI_VAR(5);
    }
    sleep 15;
});
