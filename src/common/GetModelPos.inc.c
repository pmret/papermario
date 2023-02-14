#include "common.h"
#include "model.h"

API_CALLABLE(N(GetModelPos)) {
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(script->varTable[10]));

    script->varTable[11] = (s32) model->center.x;
    script->varTable[12] = (s32) model->center.y;
    script->varTable[13] = (s32) model->center.z;

    return ApiStatus_DONE2;
}
