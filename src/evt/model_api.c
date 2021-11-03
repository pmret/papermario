#include "common.h"
#include "model.h"

void update_animated_models(void) {
    s32 i;

    for (i = 0; i < MAX_ANIMATED_MODELS; i++) {
        AnimatedModel* anim = (*gCurrentMeshAnimationListPtr)[i];

        if (anim->animModelID >= 0) {
            update_model_animator_with_transform(anim->animModelID, &anim->mtx);
        }
    }
}

INCLUDE_ASM(s32, "evt/model_api", render_animated_models);

// split here?

ApiStatus InitAnimatedModels(Evt* script, s32 isInitialCall) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentMeshAnimationListPtr = &gWorldMeshAnimationList;
    } else {
        gCurrentMeshAnimationListPtr = &gBattleMeshAnimationList;
    }

    return ApiStatus_DONE2;
}

ApiStatus LoadAnimatedModel(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    AnimatedModel* animModel = (*gCurrentMeshAnimationListPtr)[index];
    s32 animModelID = create_model_animator(0);

    load_model_animator_tree(animModelID, var1);
    animModel->animModelID = animModelID;
    animModel->pos.x = 0;
    animModel->pos.y = 0;
    animModel->pos.z = 0;
    animModel->rot.x = 0;
    animModel->rot.y = 0;
    animModel->rot.z = 0;
    animModel->scale.x = 1.0f;
    animModel->scale.y = 1.0f;
    animModel->scale.z = 1.0f;
    animModel->currentAnimData = NULL;
    guMtxIdent(&animModel->mtx);

    return ApiStatus_DONE2;
}

ApiStatus LoadAnimatedMesh(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    AnimatedModel* animModel = (*gCurrentMeshAnimationListPtr)[index];
    s32 animModelID = create_model_animator(0);

    load_mesh_animator_tree(animModelID, var1);
    animModel->animModelID = animModelID;
    animModel->pos.x = 0;
    animModel->pos.y = 0;
    animModel->pos.z = 0;
    animModel->rot.x = 0;
    animModel->rot.y = 0;
    animModel->rot.z = 0;
    animModel->scale.x = 1.0f;
    animModel->scale.y = 1.0f;
    animModel->scale.z = 1.0f;
    animModel->currentAnimData = NULL;
    guMtxIdent(&animModel->mtx);

    return ApiStatus_DONE2;
}

ApiStatus PlayModelAnimation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->currentAnimData = var2;
    play_model_animation(model->animModelID, var2);

    return ApiStatus_DONE2;
}

ApiStatus PlayModelAnimationStartingFrom(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->currentAnimData = var2;
    play_model_animation_starting_from(model->animModelID, var2, var3);

    return ApiStatus_DONE2;
}

ApiStatus ChangeModelAnimation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    if (model->currentAnimData == var2) {
        return ApiStatus_DONE2;
    }

    model->currentAnimData = var2;
    play_model_animation(model->animModelID, var2);
    return ApiStatus_DONE2;
}

ApiStatus SetAnimatedModelRootPosition(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->pos.x = x;
    model->pos.y = y;
    model->pos.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetAnimatedModelRootPosition(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 outX = *args++;
    s32 outY = *args++;
    s32 outZ = *args++;
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    evt_set_float_variable(script, outX, model->pos.x);
    evt_set_float_variable(script, outY, model->pos.y);
    evt_set_float_variable(script, outZ, model->pos.z);

    return ApiStatus_DONE2;
}

ApiStatus AddAnimatedModelRootPosition(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->pos.x += x;
    model->pos.y += y;
    model->pos.z += z;

    return ApiStatus_DONE2;
}

ApiStatus SetAnimatedModelRootRotation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->rot.x = x;
    model->rot.y = y;
    model->rot.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetAnimatedModelRootScale(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->scale.x = x;
    model->scale.y = y;
    model->scale.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetAnimatedModelRenderMode(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 renderMode = evt_get_float_variable(script, *args++);

    get_animator_by_index((*gCurrentMeshAnimationListPtr)[index]->animModelID)->renderMode = renderMode;
    return ApiStatus_DONE2;
}

ApiStatus DeleteAnimatedModel(Evt* script, s32 isInitialCall) {
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[evt_get_variable(script, *script->ptrReadPos)];

    delete_model_animator(get_animator_by_index(model->animModelID));
    model->animModelID = -1;
    return ApiStatus_DONE2;
}

ApiStatus SetAnimatorFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 a1 = *args++;
    s32 enable = evt_get_variable(script, *args++);
    ModelAnimator* animMesh = get_animator_by_index((*gCurrentMeshAnimationListPtr)[index]->animModelID);

    if (enable) {
        animMesh->flags |= a1;
    } else {
        animMesh->flags &= ~a1;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/model_api", reset_model_animators);

void init_model_animators(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentMeshAnimationListPtr = &gWorldMeshAnimationList;
    } else {
        gCurrentMeshAnimationListPtr = &gBattleMeshAnimationList;
    }
}

INCLUDE_ASM(s32, "evt/model_api", GetAnimatedNodePosition);

INCLUDE_ASM(s32, "evt/model_api", GetAnimatedNodeRotation);

INCLUDE_ASM(s32, "evt/model_api", GetAnimatedPositionByTreeIndex);

INCLUDE_ASM(s32, "evt/model_api", GetAnimatedRotationByTreeIndex);

INCLUDE_ASM(s32, "evt/model_api", SetAnimatedNodeFlags);
