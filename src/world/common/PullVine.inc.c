#include "common.h"
#include "model.h"

ApiStatus N(PullVine_WaitForPlayerGrab)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 modelX, modelY, modelZ;
    f32 dx, dy, dz;
    f32 dist;
    s32 result;
    
    modelX = evt_get_float_variable(script, *args++);
    modelY = evt_get_float_variable(script, *args++) + 15.0f;
    modelZ = evt_get_float_variable(script, *args++);
    dist = evt_get_float_variable(script, *args++);
    dx = script->varTable[0] - modelX;
    dy = script->varTable[1] - modelY;
    dz = script->varTable[2] - modelZ;
    result = 1;
    if (!(dx*dx + dy*dy + dz*dz < dist*dist)) {
        result = 0;
    }
    script->varTable[0] = result;
    return ApiStatus_DONE2;
}

ApiStatus N(PullVine_UpdatePosition)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x1 = evt_get_float_variable(script, *args++);
    f32 x2 = evt_get_float_variable(script, *args++);
    
    evt_set_float_variable(script, *args++, (x2 - x1) / 10.0f);
    return ApiStatus_DONE2;
}

void N(PullVine_apply_shear_mtx)(Matrix4f mtx, f32 f) {
    guMtxIdentF(mtx);
    mtx[1][0] = f * 0.2;
    mtx[1][1] = 1.0f;
    mtx[1][2] = 0.0f;
}

ApiStatus N(PullVine_ShearBushModel)(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 modelID = evt_get_variable(script, *args++);
    s32 modelIndex = get_model_list_index_from_tree_index(modelID);
    f32 f = evt_get_float_variable(script, *args++);
    Model* mdl = get_model_from_list_index(modelIndex);
    Matrix4f mtx;
    
    if (!(mdl->flags & 0x400)) {
        N(PullVine_apply_shear_mtx)(mdl->transformMatrix, f);
        mdl->flags |= 0x1400;
    } else {
        N(PullVine_apply_shear_mtx)(mtx, f);
        guMtxCatF(mtx, mdl->transformMatrix, mdl->transformMatrix);
    }
    return ApiStatus_DONE2;
}
