#include "tik_04.h"
#include "model.h"

API_CALLABLE(N(CreatePlatformShadows)) {
    Model* model;

    model = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_erb1));
    script->array[0] = create_shadow_type(SHADOW_VARYING_SQUARE, model->center.x, model->center.y - 100.0f, model->center.z);
    model = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_erb2));
    script->array[1] = create_shadow_type(SHADOW_VARYING_SQUARE, model->center.x, model->center.y - 100.0f, model->center.z);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpdatePlatformShadows)) {
    Model* model;
    Shadow* shadow;
    f32 x, y, z;
    f32 hitYaw, hitPitch, hitLength;

    shadow = get_shadow_by_index(script->array[0]);
    model = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_erb1));
    x = model->center.x;
    y = model->center.y;
    z = model->center.z;
    hitLength = 1000.0f;
    entity_raycast_down(&x, &y, &z, &hitYaw, &hitPitch, &hitLength);
    set_standard_shadow_scale(shadow, hitLength);
    shadow->pos.x = x;
    shadow->pos.y = y;
    shadow->pos.z = z;
    shadow->rot.x = hitYaw;
    shadow->rot.y = 0.0f;
    shadow->rot.z = hitPitch;
    shadow->scale.x *= 4.5f;
    shadow->scale.z *= 4.5f;

    shadow = get_shadow_by_index(script->array[1]);
    model = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_erb2));
    x = model->center.x;
    y = model->center.y;
    z = model->center.z;
    hitLength = 1000.0f;
    entity_raycast_down(&x, &y, &z, &hitYaw, &hitPitch, &hitLength);
    set_standard_shadow_scale(shadow, hitLength);
    shadow->pos.x = x;
    shadow->pos.y = y;
    shadow->pos.z = z;
    shadow->rot.x = hitYaw;
    shadow->rot.y = 0.0f;
    shadow->rot.z = hitPitch;
    shadow->scale.x *= 4.5f;
    shadow->scale.z *= 4.5f;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetFloorCollider)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gCollisionStatus.curFloor);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(PausePlatformsDuringPound)) {
    PlayerStatus* player = &gPlayerStatus;

    if (gCollisionStatus.curFloor == COLLIDER_erb1 || gCollisionStatus.curFloor == COLLIDER_erb2) {
        if (player->actionState == ACTION_STATE_SPIN_POUND || player->actionState == ACTION_STATE_TORNADO_POUND) {
            return ApiStatus_BLOCK;
        }
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdatePlatforms) = {
    EVT_CALL(N(GetFloorCollider), LVarA)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LABEL(0)
        EVT_CALL(N(PausePlatformsDuringPound))
        EVT_CALL(TranslateModel, LVar1, 10, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, LVar3)
        EVT_SETF(LVar5, LVar0)
        EVT_MULF(LVar5, EVT_FLOAT(-1.0))
        EVT_ADDF(LVar5, EVT_FLOAT(30.0))
        EVT_CALL(TranslateModel, LVar2, -10, LVar5, 0)
        EVT_CALL(UpdateColliderTransform, LVar4)
        EVT_SUBF(LVar0, EVT_FLOAT(0.5))
        EVT_IF_LT(LVar0, EVT_FLOAT(-120.0))
            EVT_ADDF(LVar0, EVT_FLOAT(0.5))
        EVT_END_IF
        EVT_USE_ARRAY(MV_Unk_00)
        EVT_CALL(N(UpdatePlatformShadows))
        EVT_WAIT(1)
        EVT_CALL(N(GetFloorCollider), LVarB)
        EVT_CALL(GetPlayerActionState, LVarC)
        EVT_IF_EQ(LVarB, LVar3)
            EVT_IF_NE(LVarC, ACTION_STATE_JUMP)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
    EVT_LABEL(1)
        EVT_CALL(N(PausePlatformsDuringPound))
        EVT_ADDF(LVar0, EVT_FLOAT(0.5))
        EVT_CALL(TranslateModel, LVar1, 10, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, LVar3)
        EVT_SETF(LVar5, LVar0)
        EVT_MULF(LVar5, EVT_FLOAT(-1.0))
        EVT_ADDF(LVar5, EVT_FLOAT(30.0))
        EVT_CALL(TranslateModel, LVar2, -10, LVar5, 0)
        EVT_CALL(UpdateColliderTransform, LVar4)
        EVT_USE_ARRAY(MV_Unk_00)
        EVT_CALL(N(UpdatePlatformShadows))
        EVT_WAIT(1)
        EVT_CALL(N(GetFloorCollider), LVarB)
        EVT_CALL(GetPlayerActionState, LVarC)
        EVT_IF_EQ(LVarB, LVar3)
            EVT_IF_NE(LVarC, ACTION_STATE_JUMP)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_LT(LVar0, 0)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouchPlatform) = {
    EVT_SET(LVar1, MODEL_erb1)
    EVT_SET(LVar2, MODEL_erb2)
    EVT_SET(LVar3, COLLIDER_erb1)
    EVT_SET(LVar4, COLLIDER_erb2)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatforms))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupPlatforms) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_erb1, MODEL_erb1)
    EVT_CALL(ParentColliderToModel, COLLIDER_erb2, MODEL_erb2)
    EVT_CALL(TranslateModel, MODEL_erb1, 10, 0, 0)
    EVT_CALL(TranslateModel, MODEL_erb2, -10, 30, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_erb1)
    EVT_CALL(UpdateColliderTransform, COLLIDER_erb2)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouchPlatform)), TRIGGER_FLOOR_TOUCH, COLLIDER_erb1, 1, 0)
    EVT_MALLOC_ARRAY(2, MV_Unk_00)
    EVT_USE_ARRAY(MV_Unk_00)
    EVT_CALL(N(CreatePlatformShadows))
    EVT_CALL(N(UpdatePlatformShadows))
    EVT_RETURN
    EVT_END
};
