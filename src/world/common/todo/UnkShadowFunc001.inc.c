#include "common.h"
#include "model.h"

ApiStatus N(UnkShadowFunc001)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x, y, z;
    f32 sp24;
    f32 sp28;
    f32 sp2C;
    Shadow* shadow;
    Model* model;

    if (isInitialCall) {
        s32 treeIndex = evt_get_variable(script, *args++);

        script->functionTemp[3] = *args++;
        script->functionTempPtr[1] = model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));
        script->functionTemp[2] = create_shadow_type(0, model->center.x, 0.0f, model->center.z);
        evt_set_variable(script, script->functionTemp[3], 0);
    }

    if (evt_get_variable(script, script->functionTemp[3]) != 0) {
        delete_shadow(script->functionTemp[2]);
        return ApiStatus_DONE2;
    }

    model = script->functionTempPtr[1];
    shadow = get_shadow_by_index(script->functionTemp[2]);
    x = model->center.x;
    y = model->center.y;
    z = model->center.z;
    entity_raycast_down(&x, &y, &z, &sp24, &sp28, &sp2C);
    set_standard_shadow_scale(shadow, sp2C);
    shadow->rotation.y = 0.0f;
    shadow->position.x = x;
    shadow->position.y = y;
    shadow->position.z = z;
    shadow->rotation.x = sp24;
    shadow->rotation.z = sp28;
    shadow->scale.x *= 2.0f;
    shadow->scale.z *= 2.0f;
    return ApiStatus_BLOCK;
}
