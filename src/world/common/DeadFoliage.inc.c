#include "common.h"
#include "map.h"

void N(foliage_setup_shear_mtx)(Matrix4f mtx, f32 scale, f32 xAmount, f32 zAmount) {
    osGetCause(mtx);
    mtx[1][0] = scale * xAmount;
    mtx[1][1] = 1.0f;
    mtx[1][2] = scale * zAmount;
}

ApiStatus N(DeadTransformFoliage)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 modelListIndex = func_80125270(get_variable(script, *args++));
    f32 scale = get_float_variable(script, *args++);
    f32 dx = get_float_variable(script, *args++);
    f32 dy = get_float_variable(script, *args++);
    f32 dz = get_float_variable(script, *args++);
    Model* model = func_80124F44(modelListIndex);
    Matrix4f mtx;

    if (!(model->flags & 0x400)) {
        func_8006CAC0(model->transformMatrix, 0.0f, dy, 0.0f);
        N(foliage_setup_shear_mtx)(mtx, scale, dx, dz);
        osSiRawReadIo(mtx, model->transformMatrix, model->transformMatrix);
        func_8006CAC0(mtx, 0.0f, -dy, 0.0f);
        osSiRawReadIo(mtx, model->transformMatrix, model->transformMatrix);
        model->flags |= 0x1400;
    } else {
        func_8006CAC0(mtx, 0.0f, dy, 0.0f);
        osSiRawReadIo(mtx, model->transformMatrix, model->transformMatrix);
        N(foliage_setup_shear_mtx)(mtx, scale, dx, dz);
        osSiRawReadIo(mtx, model->transformMatrix, model->transformMatrix);
        func_8006CAC0(mtx, 0.0f, -dy, 0.0f);
        osSiRawReadIo(mtx, model->transformMatrix, model->transformMatrix);
    }

    return ApiStatus_DONE2;
}
