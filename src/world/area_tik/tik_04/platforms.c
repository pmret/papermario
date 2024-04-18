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
    Call(N(GetFloorCollider), LVarA)
    SetF(LVar0, Float(0.0))
    Label(0)
        Call(N(PausePlatformsDuringPound))
        Call(TranslateModel, LVar1, 10, LVar0, 0)
        Call(UpdateColliderTransform, LVar3)
        SetF(LVar5, LVar0)
        MulF(LVar5, Float(-1.0))
        AddF(LVar5, Float(30.0))
        Call(TranslateModel, LVar2, -10, LVar5, 0)
        Call(UpdateColliderTransform, LVar4)
        SubF(LVar0, Float(0.5))
        IfLt(LVar0, Float(-120.0))
            AddF(LVar0, Float(0.5))
        EndIf
        UseArray(MV_Unk_00)
        Call(N(UpdatePlatformShadows))
        Wait(1)
        Call(N(GetFloorCollider), LVarB)
        Call(GetPlayerActionState, LVarC)
        IfEq(LVarB, LVar3)
            IfNe(LVarC, ACTION_STATE_JUMP)
                Goto(0)
            EndIf
        EndIf
    Label(1)
        Call(N(PausePlatformsDuringPound))
        AddF(LVar0, Float(0.5))
        Call(TranslateModel, LVar1, 10, LVar0, 0)
        Call(UpdateColliderTransform, LVar3)
        SetF(LVar5, LVar0)
        MulF(LVar5, Float(-1.0))
        AddF(LVar5, Float(30.0))
        Call(TranslateModel, LVar2, -10, LVar5, 0)
        Call(UpdateColliderTransform, LVar4)
        UseArray(MV_Unk_00)
        Call(N(UpdatePlatformShadows))
        Wait(1)
        Call(N(GetFloorCollider), LVarB)
        Call(GetPlayerActionState, LVarC)
        IfEq(LVarB, LVar3)
            IfNe(LVarC, ACTION_STATE_JUMP)
                Goto(0)
            EndIf
        EndIf
        IfLt(LVar0, 0)
            Goto(1)
        EndIf
    Return
    End
};

EvtScript N(EVS_OnTouchPlatform) = {
    Set(LVar1, MODEL_erb1)
    Set(LVar2, MODEL_erb2)
    Set(LVar3, COLLIDER_erb1)
    Set(LVar4, COLLIDER_erb2)
    ExecWait(N(EVS_UpdatePlatforms))
    Return
    End
};

EvtScript N(EVS_SetupPlatforms) = {
    Call(ParentColliderToModel, COLLIDER_erb1, MODEL_erb1)
    Call(ParentColliderToModel, COLLIDER_erb2, MODEL_erb2)
    Call(TranslateModel, MODEL_erb1, 10, 0, 0)
    Call(TranslateModel, MODEL_erb2, -10, 30, 0)
    Call(UpdateColliderTransform, COLLIDER_erb1)
    Call(UpdateColliderTransform, COLLIDER_erb2)
    BindTrigger(Ref(N(EVS_OnTouchPlatform)), TRIGGER_FLOOR_TOUCH, COLLIDER_erb1, 1, 0)
    MallocArray(2, MV_Unk_00)
    UseArray(MV_Unk_00)
    Call(N(CreatePlatformShadows))
    Call(N(UpdatePlatformShadows))
    Return
    End
};
