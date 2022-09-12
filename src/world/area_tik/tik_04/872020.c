#include "tik_04.h"

#include "world/common/UnkPosFunc2.inc.c"

ApiStatus func_80240960_872390(Evt* script, s32 isInitialCall) {
    Model* model1;
    Model* model2;

    model1 = get_model_from_list_index(get_model_list_index_from_tree_index(0x12));
    script->array[0] = create_shadow_type(1, model1->center.x, model1->center.y - 100.0f, model1->center.z);
    model2 = get_model_from_list_index(get_model_list_index_from_tree_index(0x14));
    script->array[1] = create_shadow_type(1, model2->center.x, model2->center.y - 100.0f, model2->center.z);

    return ApiStatus_DONE2;
}

ApiStatus func_80240A00_872430(Evt* script, s32 isInitialCall) {
    Model* model;
    Shadow* shadow;
    f32 x, y, z;
    f32 hitYaw, hitPitch, hitLength;

    shadow = get_shadow_by_index(script->array[0]);
    model = get_model_from_list_index(get_model_list_index_from_tree_index(0x12));
    x = model->center.x;
    y = model->center.y;
    z = model->center.z;
    hitLength = 1000.0f;
    entity_raycast_down(&x, &y, &z, &hitYaw, &hitPitch, &hitLength);
    set_standard_shadow_scale(shadow, hitLength);
    shadow->position.x = x;
    shadow->position.y = y;
    shadow->position.z = z;
    shadow->rotation.x = hitYaw;
    shadow->rotation.y = 0.0f;
    shadow->rotation.z = hitPitch;
    shadow->scale.x *= 4.5f;
    shadow->scale.z *= 4.5f;

    shadow = get_shadow_by_index(script->array[1]);
    model = get_model_from_list_index(get_model_list_index_from_tree_index(0x14));
    x = model->center.x;
    y = model->center.y;
    z = model->center.z;
    hitLength = 1000.0f;
    entity_raycast_down(&x, &y, &z, &hitYaw, &hitPitch, &hitLength);
    set_standard_shadow_scale(shadow, hitLength);
    shadow->position.x = x;
    shadow->position.y = y;
    shadow->position.z = z;
    shadow->rotation.x = hitYaw;
    shadow->rotation.y = 0.0f;
    shadow->rotation.z = hitPitch;
    shadow->scale.x *= 4.5f;
    shadow->scale.z *= 4.5f;

    return ApiStatus_DONE2;
}

#include "world/common/GetFloorCollider.inc.c"

ApiStatus func_80240C20_872650(Evt* script, s32 isInitialCall) {
    PlayerStatus* player = &gPlayerStatus;

    if ((gCollisionStatus.currentFloor == 9) || (gCollisionStatus.currentFloor == 0xB)) {
        if ((player->actionState == ACTION_STATE_SPIN_POUND) || (player->actionState == ACTION_STATE_TORNADO_POUND)) {
            return ApiStatus_BLOCK;
        }
    }
    return ApiStatus_DONE2;
}
