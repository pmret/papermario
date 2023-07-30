#include "common.h"
#include "model.h"

API_CALLABLE(N(UpdateLogShadow)) {
    Bytecode* args = script->ptrReadPos;
    f32 hitYaw, hitPitch, hitLength;
    f32 x, y, z;
    Shadow* shadow;
    Model* model;

    if (isInitialCall) {
        s32 modelID = evt_get_variable(script, *args++);

        script->functionTemp[3] = *args++;
        script->functionTempPtr[1] = model = get_model_from_list_index(get_model_list_index_from_tree_index(modelID));
        script->functionTemp[2] = create_shadow_type(0, model->center.x, 0.0f, model->center.z);
        evt_set_variable(script, script->functionTemp[3], 0);
    }

    if (evt_get_variable(script, script->functionTemp[3])) {
        delete_shadow(script->functionTemp[2]);
        return ApiStatus_DONE2;
    }

    model = script->functionTempPtr[1];
    shadow = get_shadow_by_index(script->functionTemp[2]);
    x = model->center.x;
    y = model->center.y;
    z = model->center.z;
    entity_raycast_down(&x, &y, &z, &hitYaw, &hitPitch, &hitLength);
    set_standard_shadow_scale(shadow, hitLength);
    shadow->rot.y = 0.0f;
    shadow->pos.x = x;
    shadow->pos.y = y;
    shadow->pos.z = z;
    shadow->rot.x = hitYaw;
    shadow->rot.z = hitPitch;
    shadow->scale.x *= 2.0f;
    shadow->scale.z *= 2.0f;
    return ApiStatus_BLOCK;
}
