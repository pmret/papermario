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

Script N(searchBush) = {
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(0)),
    SI_CMD(ScriptOpcode_BUFFER_READ_4, SI_VAR(1), SI_VAR(2), SI_VAR(3), SI_VAR(4)),
    SI_CMD(ScriptOpcode_CALL, (s32)GetPlayerPos, SI_VAR(5), SI_VAR(15), SI_VAR(7)),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 0),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(1), 0),
    SI_CMD(ScriptOpcode_LOOP, 5),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(1)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(2)),
    SI_CMD(ScriptOpcode_LOOP, SI_VAR(2)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
    SI_CMD(ScriptOpcode_CALL, (s32)N(TransformFoliage), SI_VAR(3), SI_FIXED(0.1005859375), 1, SI_VAR(15), 0),
    SI_CMD(ScriptOpcode_IF_EQ, SI_FLAG(0), 0),
    SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 1),
    SI_CMD(ScriptOpcode_CALL, (s32)PlaySoundAtModel, SI_VAR(3), 339, 0),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(1)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(2)),
    SI_CMD(ScriptOpcode_LOOP, SI_VAR(2)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
    SI_CMD(ScriptOpcode_CALL, (s32)N(TransformFoliage), SI_VAR(3), SI_FIXED(0.1005859375), -1, SI_VAR(15), 0),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(1)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(2)),
    SI_CMD(ScriptOpcode_LOOP, SI_VAR(2)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
    SI_CMD(ScriptOpcode_CALL, (s32)TranslateModel, SI_VAR(3), 0, 0, 0),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(2), 0),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(2)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
    SI_CMD(ScriptOpcode_LOOP, SI_VAR(3)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(4)),
    SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(5), SI_VAR(6), SI_VAR(7)),
    SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(8), SI_VAR(9), SI_VAR(10)),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(10), 0),
    SI_CMD(ScriptOpcode_CALL, (s32)DropItemEntity, SI_VAR(4), SI_VAR(5), SI_VAR(6), SI_VAR(7), SI_VAR(8), SI_VAR(9)),
    SI_CMD(ScriptOpcode_ELSE),
    SI_CMD(ScriptOpcode_CALL, (s32)GetValueByRef, SI_VAR(10), SI_VAR(11)),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(11), 0),
    SI_CMD(ScriptOpcode_CALL, (s32)SetValueByRef, SI_VAR(10), 1),
    SI_CMD(ScriptOpcode_CALL, (s32)DropItemEntity, SI_VAR(4), SI_VAR(5), SI_VAR(6), SI_VAR(7), SI_VAR(8), SI_VAR(9)),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(4), 0),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, 0xFE363C84),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};

Script N(shakeTree) = {
    SI_CMD(ScriptOpcode_SET_TIMESCALE, SI_FIXED(2.0)),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(0)),
    SI_CMD(ScriptOpcode_BUFFER_READ_4, SI_VAR(1), SI_VAR(2), SI_VAR(3), SI_VAR(4)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(5)),
    SI_CMD(ScriptOpcode_CALL, (s32)GetPlayerPos, SI_VAR(6), SI_VAR(15), SI_VAR(8)),
    SI_CMD(ScriptOpcode_CALL, (s32)PlaySound, 357),
    SI_CMD(ScriptOpcode_CALL, (s32)PlaySound, 358),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 0),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(1), 0),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_LOOP, 5),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(1)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(2)),
    SI_CMD(ScriptOpcode_LOOP, SI_VAR(2)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
    SI_CMD(ScriptOpcode_CALL, (s32)N(TransformFoliage), SI_VAR(3), SI_FIXED(0.1005859375), SI_FIXED(0.2001953125), SI_VAR(15), 0),
    SI_CMD(ScriptOpcode_IF_EQ, SI_FLAG(0), 0),
    SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 1),
    SI_CMD(ScriptOpcode_CALL, (s32)PlaySoundAtModel, SI_VAR(3), 358, 0),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(1)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(2)),
    SI_CMD(ScriptOpcode_LOOP, SI_VAR(2)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
    SI_CMD(ScriptOpcode_CALL, (s32)N(TransformFoliage), SI_VAR(3), SI_FIXED(0.1005859375), SI_FIXED(-0.19921875), SI_VAR(15), 0),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(1)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(2)),
    SI_CMD(ScriptOpcode_LOOP, SI_VAR(2)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
    SI_CMD(ScriptOpcode_CALL, (s32)TranslateModel, SI_VAR(3), 0, 0, 0),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 0),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(2), 0),
    SI_CMD(ScriptOpcode_LOOP, 5),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(2)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
    SI_CMD(ScriptOpcode_LOOP, SI_VAR(3)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(4)),
    SI_CMD(ScriptOpcode_CALL, (s32)N(TransformFoliage), SI_VAR(4), SI_FIXED(0.1005859375), SI_FIXED(0.2001953125), SI_VAR(15), 0),
    SI_CMD(ScriptOpcode_IF_EQ, SI_FLAG(0), 0),
    SI_CMD(ScriptOpcode_SET, SI_FLAG(0), 1),
    SI_CMD(ScriptOpcode_CALL, (s32)PlaySoundAtModel, SI_VAR(4), 357, 0),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(2)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
    SI_CMD(ScriptOpcode_LOOP, SI_VAR(3)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(4)),
    SI_CMD(ScriptOpcode_CALL, (s32)N(TransformFoliage), SI_VAR(4), SI_FIXED(0.1005859375), SI_FIXED(-0.19921875), SI_VAR(15), 0),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(2)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(3)),
    SI_CMD(ScriptOpcode_LOOP, SI_VAR(3)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(4)),
    SI_CMD(ScriptOpcode_CALL, (s32)TranslateModel, SI_VAR(4), 0, 0, 0),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 1),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(3), 0),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(3)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(4)),
    SI_CMD(ScriptOpcode_LOOP, SI_VAR(4)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(5)),
    SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(6), SI_VAR(7), SI_VAR(8)),
    SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(9), SI_VAR(10), SI_VAR(11)),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(11), 0),
    SI_CMD(ScriptOpcode_CALL, (s32)DropItemEntity, SI_VAR(5), SI_VAR(6), SI_VAR(7), SI_VAR(8), SI_VAR(9), SI_VAR(10)),
    SI_CMD(ScriptOpcode_ELSE),
    SI_CMD(ScriptOpcode_CALL, (s32)GetValueByRef, SI_VAR(11), SI_VAR(12)),
    SI_CMD(ScriptOpcode_IF_EQ, SI_VAR(12), 0),
    SI_CMD(ScriptOpcode_CALL, (s32)SetValueByRef, SI_VAR(11), 1),
    SI_CMD(ScriptOpcode_CALL, (s32)DropItemEntity, SI_VAR(5), SI_VAR(6), SI_VAR(7), SI_VAR(8), SI_VAR(9), SI_VAR(10)),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(4), 0),
    SI_CMD(ScriptOpcode_USE_BUFFER, SI_VAR(4)),
    SI_CMD(ScriptOpcode_BUFFER_READ_1, SI_VAR(5)),
    SI_CMD(ScriptOpcode_LOOP, SI_VAR(5)),
    SI_CMD(ScriptOpcode_BUFFER_READ_3, SI_VAR(6), SI_VAR(7), SI_VAR(8)),
    SI_CMD(ScriptOpcode_CALL, (s32)PlayEffect, 20, 0, SI_VAR(6), SI_VAR(7), SI_VAR(8), 100, 0, 0, 0, 0, 0, 0, 0, 0),
    SI_CMD(ScriptOpcode_END_LOOP),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_END_SPAWN_THREAD),
    SI_CMD(ScriptOpcode_IF_NE, SI_VAR(5), 0),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, 0xFE363C85),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_SLEEP_FRAMES, 15),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
