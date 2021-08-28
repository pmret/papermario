#include "common.h"
#include "camera.h"

EvtSource ShakeCam1 = SCRIPT({
    group 0;
    ShakeCam(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1.0);
});

EvtSource ShakeCamX = SCRIPT({
    group 0;
    ShakeCam(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
});

ApiStatus SetCamEnabled(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);

    if (!enabled) {
        gCameras[id].flags |= CAM_FLAG_ENABLED;
    } else {
        gCameras[id].flags &= ~CAM_FLAG_ENABLED;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetCamFlag80(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);

    if (!enabled) {
        gCameras[id].flags |= CAM_FLAG_80;
    } else {
        gCameras[id].flags &= ~CAM_FLAG_80;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetCamPerspective(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s16 mode = get_variable(script, *args++);
    f32 vfov = get_float_variable(script, *args++);
    s16 nearClip = get_variable(script, *args++);
    s16 farClip = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->farClip = farClip;
    camera->mode = mode;
    camera->unk_06 = 1;
    camera->unk_08 = 1;
    camera->vfov = vfov;
    camera->nearClip = nearClip;
    return ApiStatus_DONE2;
}

ApiStatus func_802CA90C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s16 mode = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->mode = mode;
    camera->unk_06 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802CA988(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Bytecode outVar3 = *args++;
    Bytecode outVar4 = *args++;
    f32 temp1, temp2, temp3;

    gCameras[id].mode = 2;
    gCameras[id].unk_06 = 0;
    gCameras[id].unk_1C = -round(gCameras[id].currentPitch);
    gCameras[id].unk_1E = -gCameras[id].currentBlendedYawNegated;

    temp1 = gCameras[id].lookAt_obj.x - gCameras[id].lookAt_eye.x;
    temp2 = gCameras[id].lookAt_obj.y - gCameras[id].lookAt_eye.y;
    temp3 = gCameras[id].lookAt_obj.z - gCameras[id].lookAt_eye.z;

    gCameras[id].unk_20 = round(sqrtf(SQ(temp1) + SQ(temp2) + SQ(temp3)));
    gCameras[id].unk_22 = 0;
    gCameras[id].unk_54 = gCameras[id].lookAt_obj.x;
    gCameras[id].unk_58 = gCameras[id].lookAt_obj.y;
    gCameras[id].unk_5C = gCameras[id].lookAt_obj.z;

    set_variable(script, outVar1, gCameras[id].unk_1C);
    set_variable(script, outVar2, gCameras[id].unk_1E);
    set_variable(script, outVar3, gCameras[id].unk_20);
    set_variable(script, outVar4, gCameras[id].unk_22);
    return ApiStatus_DONE2;
}

ApiStatus SetCamViewport(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 x = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s16 width = get_variable(script, *args++);
    s16 height = get_variable(script, *args++);

    set_cam_viewport(id, x, y, width, height);
    return ApiStatus_DONE2;
}

ApiStatus func_802CABE8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s16 value1 = get_variable(script, *args++);
    s32 value2 = get_variable(script, *args++);
    s32 value3 = get_variable(script, *args++);
    s16 value4 = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->unk_22 = value4;
    camera->unk_1C = value1;
    camera->unk_1E = value2;
    camera->unk_20 = value3;
    return ApiStatus_DONE2;
}

ApiStatus func_802CACC0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s16 value1 = get_variable(script, *args++);
    s32 value2 = get_variable(script, *args++);
    s32 value3 = get_variable(script, *args++);
    s16 zoomPercent = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->zoomPercent = zoomPercent;
    camera->unk_24 = value1;
    camera->unk_26 = value2;
    camera->unk_28 = value3;
    return ApiStatus_DONE2;
}

ApiStatus SetCamBGColor(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s16 r = get_variable(script, *args++);
    s16 g = get_variable(script, *args++);
    s16 b = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->bgColor[0] = r;
    camera->bgColor[1] = g;
    camera->bgColor[2] = b;
    return ApiStatus_DONE2;
}

ApiStatus func_802CAE50(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 value1 = get_variable(script, *args++);
    s32 value2 = get_variable(script, *args++);
    s32 value3 = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->unk_54 = value1;
    camera->unk_58 = value2;
    camera->unk_5C = value3;
    return ApiStatus_DONE2;
}

ApiStatus SetCamTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 x = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s32 z = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->targetPos.x = x;
    camera->targetPos.y = y;
    camera->targetPos.z = z;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/cam_api", func_802CB008, Evt* script, s32 isInitialCall);

INCLUDE_ASM(s32, "evt/cam_api", ShakeCam, Evt* script, s32 isInitialCall);

void exec_ShakeCam1(s32 arg0, s32 arg1, s32 arg2) {
    Evt* script;

    script = start_script_in_group(&ShakeCam1, 1, 0, 4);
    script->varTable[0] = arg0;
    script->varTable[1] = arg1;
    script->varTable[2] = arg2;
}

void exec_ShakeCamX(s32 arg0, s32 arg1, s32 arg2, f32 arg3) {
    Evt* script;

    script = start_script_in_group(&ShakeCamX, 1, 0, 4);
    set_variable(script, EVT_VAR(0), arg0);
    set_variable(script, EVT_VAR(1), arg1);
    set_variable(script, EVT_VAR(2), arg2);
    set_float_variable(script, EVT_VAR(3), arg3);
}

ApiStatus SetCamLeadPlayer(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    if (enabled) {
        camera->flags |= CAM_FLAG_LEAD_PLAYER;
    } else {
        camera->flags &= ~CAM_FLAG_LEAD_PLAYER;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802CB710(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    f32 value = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->unk_520 = (value / 100.0f);
    return ApiStatus_DONE2;
}

ApiStatus PanToTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    f32 panPhase = get_float_variable(script, *args++);
    s32 targetType = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->unk_506 = 1;
    if (targetType != 0) {
        camera->boolTargetPlayer = 1;
        camera->panPhase = panPhase;
    } else {
        camera->boolTargetPlayer = 0;
        camera->panPhase = 0.0f;
        camera->moveSpeed = 1.0f;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/cam_api", UseSettingsFrom, Evt* script, s32 isInitialCall);

INCLUDE_ASM(s32, "evt/cam_api", LoadSettings, Evt* script, s32 isInitialCall);

ApiStatus SetCamType(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    s32 controllerType = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);

    camera->unk_500 = enabled;
    camera->controllerType = controllerType;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPitch(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 boomPitch = get_float_variable(script, *args++);
    f32 viewPitch = get_float_variable(script, *args++);

    camera->controllerBoomPitch = boomPitch;
    camera->controllerViewPitch = viewPitch;
    return ApiStatus_DONE2;
}

ApiStatus SetCamDistance(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 boomLength = get_float_variable(script, *args++);

    camera->controllerBoomLen = boomLength;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPosA(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 x = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);

    camera->posA.x = x;
    camera->posA.z = z;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPosB(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 x = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);

    camera->posB.x = x;
    camera->posB.z = z;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPosC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 y1 = get_float_variable(script, *args++);
    f32 y2 = get_float_variable(script, *args++);

    camera->posA.y = y1;
    camera->posB.y = y2;
    return ApiStatus_DONE2;
}

ApiStatus SetPanTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);

    camera->movePos.x = x;
    camera->movePos.y = y;
    camera->movePos.z = z;
    camera->unk_506 = 1;
    return ApiStatus_DONE2;
}

ApiStatus SetCamSpeed(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    f32 speed = get_float_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->moveSpeed = speed;
    return ApiStatus_DONE2;
}

ApiStatus GetCamType(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_variable(script, outVar1, camera->controllerType);
    set_variable(script, outVar2, camera->unk_500);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPitch(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->controllerBoomPitch);
    set_float_variable(script, outVar2, camera->controllerViewPitch);
    return ApiStatus_DONE2;
}

ApiStatus GetCamDistance(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->controllerBoomLen);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosA(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->posA.x);
    set_float_variable(script, outVar2, camera->posA.z);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosB(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->posB.x);
    set_float_variable(script, outVar2, camera->posB.z);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->posA.y);
    set_float_variable(script, outVar2, camera->posB.y);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosition(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Bytecode outVar3 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->movePos.x);
    set_float_variable(script, outVar2, camera->movePos.y);
    set_float_variable(script, outVar3, camera->movePos.z);
    return ApiStatus_DONE2;
}

ApiStatus WaitForCam(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, args[0]);
    f32 endInterpValue = get_float_variable(script, args[1]);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    if (isInitialCall || !(endInterpValue <= camera->sinInterpAlpha)) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/cam_api", SetCamProperties, Evt* script, s32 isInitialCall);

INCLUDE_ASM(s32, "evt/cam_api", AdjustCam, Evt* script, s32 isInitialCall);

INCLUDE_ASM(s32, "evt/cam_api", ResetCam, Evt* script, s32 isInitialCall);

void update_animated_models(void) {
    s32 i;

    for (i = 0; i < MAX_ANIMATED_MODELS; i++) {
        AnimatedModel* anim = (*gCurrentMeshAnimationListPtr)[i];

        if (anim->animModelID >= 0) {
            func_8011EA54(anim->animModelID, &anim->mtx);
        }
    }
}

INCLUDE_ASM(s32, "evt/cam_api", render_animated_models);

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
    s32 index = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
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
    s32 index = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
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
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->currentAnimData = var2;
    play_model_animation(model->animModelID, var2);

    return ApiStatus_DONE2;
}

ApiStatus PlayModelAnimationStartingFrom(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->currentAnimData = var2;
    play_model_animation_starting_from(model->animModelID, var2, var3);

    return ApiStatus_DONE2;
}

ApiStatus ChangeModelAnimation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
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
    s32 index = get_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->pos.x = x;
    model->pos.y = y;
    model->pos.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetAnimatedModelRootPosition(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 outX = *args++;
    s32 outY = *args++;
    s32 outZ = *args++;
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    set_float_variable(script, outX, model->pos.x);
    set_float_variable(script, outY, model->pos.y);
    set_float_variable(script, outZ, model->pos.z);

    return ApiStatus_DONE2;
}

ApiStatus AddAnimatedModelRootPosition(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->pos.x += x;
    model->pos.y += y;
    model->pos.z += z;

    return ApiStatus_DONE2;
}

ApiStatus SetAnimatedModelRootRotation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->rot.x = x;
    model->rot.y = y;
    model->rot.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetAnimatedModelRootScale(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    f32 x = get_float_variable(script, *args++);
    f32 y = get_float_variable(script, *args++);
    f32 z = get_float_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->scale.x = x;
    model->scale.y = y;
    model->scale.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetAnimatedModelRenderMode(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 renderMode = get_float_variable(script, *args++);

    get_animator_by_index((*gCurrentMeshAnimationListPtr)[index]->animModelID)->renderMode = renderMode;
    return ApiStatus_DONE2;
}

ApiStatus DeleteAnimatedModel(Evt* script, s32 isInitialCall) {
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[get_variable(script, *script->ptrReadPos)];

    delete_model_animator(get_animator_by_index(model->animModelID));
    model->animModelID = -1;
    return ApiStatus_DONE2;
}

ApiStatus SetAnimatorFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 a1 = *args++;
    s32 enable = get_variable(script, *args++);
    AnimatedMesh* animMesh = get_animator_by_index((*gCurrentMeshAnimationListPtr)[index]->animModelID);

    if (enable) {
        animMesh->flags |= a1;
    } else {
        animMesh->flags &= ~a1;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/cam_api", reset_model_animators);

void init_model_animators(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentMeshAnimationListPtr = &gWorldMeshAnimationList;
    } else {
        gCurrentMeshAnimationListPtr = &gBattleMeshAnimationList;
    }
}

INCLUDE_ASM(s32, "evt/cam_api", GetAnimatedNodePosition);

INCLUDE_ASM(s32, "evt/cam_api", GetAnimatedNodeRotation);

INCLUDE_ASM(s32, "evt/cam_api", GetAnimatedPositionByTreeIndex);

INCLUDE_ASM(s32, "evt/cam_api", GetAnimatedRotationByTreeIndex);

INCLUDE_ASM(s32, "evt/cam_api", SetAnimatedNodeFlags);
