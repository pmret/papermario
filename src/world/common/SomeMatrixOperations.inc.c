#include "common.h"
#include "map.h"

void N(SomeMatrixOperation)(Matrix4f mtx, f32 arg1, f32 arg2, f32 arg3) {
    guMtxIdentF(*mtx);
    mtx[1][0] = arg1 * arg2;
    mtx[1][1] = 1.0f;
    mtx[1][2] = arg1 * arg3;
}

ApiStatus N(SomeMatrixOperation2)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelListIndex = get_model_list_index_from_tree_index(get_variable(script, *args++));
    f32 temp_f28 = get_float_variable(script, *args++);
    f32 temp_f26 = get_float_variable(script, *args++);
    f32 temp_f22 = get_float_variable(script, *args++);
    f32 temp_f24 = get_float_variable(script, *args++);
    Model* model = get_model_from_list_index(modelListIndex);
    Matrix4f mtx;

    if (!(model->flags & 0x400)) {
        guTranslateF(model->transformMatrix, 0.0f, temp_f22, 0.0f);
        N(SomeMatrixOperation)(&mtx, temp_f28, temp_f26, temp_f24);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
        guTranslateF(&mtx, 0.0f, -temp_f22, 0.0f);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
        model->flags |= 0x1400;
    } else {
        guTranslateF(mtx, 0.0f, temp_f22, 0.0f);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
        N(SomeMatrixOperation)(&mtx, temp_f28, temp_f26, temp_f24);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
        guTranslateF(mtx, 0.0f, -temp_f22, 0.0f);
        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
    }

    return ApiStatus_DONE2;
}
