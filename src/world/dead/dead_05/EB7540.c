#include "dead.h"
#include "common.h"
#include "effects.h"

// Copy of kzn_23 (kzn_23_2_extra.c)

#define NAMESPACE EB7540

API_CALLABLE(N(SetChestPosition)) {
    Bytecode* args = script->ptrReadPos;
    s32 entityIndex = evt_get_variable(script, *args++);
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);
    Entity* entity = get_entity_by_index(entityIndex);

    entity->position.x = x;
    entity->position.y = y;
    entity->position.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetChestPosition)) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = get_entity_by_index(evt_get_variable(script, *args++));

    evt_set_variable(script, *args++, entity->position.x);
    evt_set_variable(script, *args++, entity->position.y);
    evt_set_variable(script, *args++, entity->position.z);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetPyroclastPos)) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    EffectInstance* effect = script->varTablePtr[0xE];

    effect->data.unk_65->pos.x = x;
    effect->data.unk_65->pos.y = y;
    effect->data.unk_65->pos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AllowCameraInterpY)) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    camera->moveFlags &= ~CAMERA_MOVE_IGNORE_PLAYER_Y;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AnimateChestSize)) {
    Entity* entity = get_entity_by_index(script->varTable[0xA]);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 60;
    }

    entity->scale.x = script->functionTemp[1] / 60.0f;
    entity->scale.y = script->functionTemp[1] / 60.0f;
    entity->scale.z = script->functionTemp[1] / 60.0f;

    entity->rotation.y = (1.0f - cos_rad(entity->scale.y * PI)) * 990.0 / 2.0;

    script->functionTemp[1]--;
    if (~script->functionTemp[1] == 0) { //TODO remove ~ optimization
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

const char* N(exit_str_0) = "jan_04";
