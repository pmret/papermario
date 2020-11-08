#include "common.h"

ApiStatus SetCamEnabled(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);

    if (!enabled) {
        CAM(id)->flags |= 0x2;
    } else {
        CAM(id)->flags &= ~0x2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetCamFlag80(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);

    if (!enabled) {
        CAM(id)->flags |= 0x80;
    } else {
        CAM(id)->flags &= ~0x80;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetCamPerspective(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus func_802CA90C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s16 mode = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->mode = mode;
    camera->unk_06 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802CA988(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Bytecode outVar3 = *args++;
    Bytecode outVar4 = *args++;
    f32 temp1, temp2, temp3;

    CAM(id)->mode = 2;
    CAM(id)->unk_06 = 0;
    CAM(id)->unk_1C = -round(CAM(id)->currentPitch);
    CAM(id)->unk_1E = -CAM(id)->currentBlendedYawNegated;

    temp1 = CAM(id)->lookAt_obj.x - CAM(id)->lookAt_eye[0];
    temp2 = CAM(id)->lookAt_obj.y - CAM(id)->lookAt_eye[1];
    temp3 = CAM(id)->lookAt_obj.z - CAM(id)->lookAt_eye[2];

    CAM(id)->unk_20 = round(sqrtf(SQ(temp1) + SQ(temp2) + SQ(temp3)));
    CAM(id)->unk_22 = 0;
    CAM(id)->unk_54 = CAM(id)->lookAt_obj.x;
    CAM(id)->unk_58 = CAM(id)->lookAt_obj.y;
    CAM(id)->unk_5C = CAM(id)->lookAt_obj.z;

    set_variable(script, outVar1, CAM(id)->unk_1C);
    set_variable(script, outVar2, CAM(id)->unk_1E);
    set_variable(script, outVar3, CAM(id)->unk_20);
    set_variable(script, outVar4, CAM(id)->unk_22);
    return ApiStatus_DONE2;
}

ApiStatus SetCamViewport(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 x = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s16 width = get_variable(script, *args++);
    s16 height = get_variable(script, *args++);

    set_cam_viewport(id, x, y, width, height);
    return ApiStatus_DONE2;
}

ApiStatus func_802CABE8(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus func_802CACC0(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus SetCamBGColor(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s16 r = get_variable(script, *args++);
    s16 g = get_variable(script, *args++);
    s16 b = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->backgroundColor[0] = r;
    camera->backgroundColor[1] = g;
    camera->backgroundColor[2] = b;
    return ApiStatus_DONE2;
}

ApiStatus func_802CAE50(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus SetCamTarget(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "code_ef070_len_3400", func_802CB008, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_ef070_len_3400", ShakeCam, ScriptInstance* script, s32 isInitialCall);

void exec_ShakeCam1(s32 arg0, s32 arg1, s32 arg2) {
    ScriptInstance* script;

    script = start_script_in_group(&ShakeCam1, 1, 0, 4);
    script->varTable[0] = arg0;
    script->varTable[1] = arg1;
    script->varTable[2] = arg2;
}

void exec_ShakeCamX(s32 arg0, s32 arg1, s32 arg2, f32 arg3) {
    ScriptInstance* script;

    script = start_script_in_group(&ShakeCamX, 1, 0, 4);
    set_variable(script, SI_VAR(0), arg0);
    set_variable(script, SI_VAR(1), arg1);
    set_variable(script, SI_VAR(2), arg2);
    set_float_variable(script, SI_VAR(3), arg3);
}

ApiStatus SetCamLeadPlayer(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    if (enabled) {
        camera->flags |= 0x4;
    } else {
        camera->flags &= ~0x4;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802CB710(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    f32 value = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->unk_520 = (value / 100.0f);
    return ApiStatus_DONE2;
}

ApiStatus PanToTarget(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "code_ef070_len_3400", UseSettingsFrom, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_ef070_len_3400", LoadSettings, ScriptInstance* script, s32 isInitialCall);

ApiStatus SetCamType(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus SetCamPitch(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus SetCamDistance(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];
    f32 boomLength = get_float_variable(script, *args++);

    camera->controllerBoomLen = boomLength;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPosA(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus SetCamPosB(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus SetCamPosC(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus SetPanTarget(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus SetCamSpeed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    f32 speed = get_float_variable(script, *args++);
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    camera->moveSpeed = speed;
    return ApiStatus_DONE2;
}

ApiStatus GetCamType(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus GetCamPitch(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus GetCamDistance(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Camera* cameras = gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->controllerBoomLen);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosA(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus GetCamPosB(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus GetCamPosC(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus GetCamPosition(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus WaitForCam(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "code_ef070_len_3400", SetCamProperties, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_ef070_len_3400", AdjustCam, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_ef070_len_3400", ResetCam, ScriptInstance* script, s32 isInitialCall);

void func_802CCAC0(void) {
    s32 i;

    for (i = 0; i < MAX_ANIMATED_MODELS; i++) {
        AnimatedModel* anim = (*gCurrentMeshAnimationListPtr)[i];

        if (anim->animModelID >= 0) {
            func_8011EA54(anim->animModelID, &anim->mtx);
        }
    }
}

INCLUDE_ASM(s32, "code_ef070_len_3400", draw_anim_models);

ApiStatus func_802CCCB0(ScriptInstance* script, s32 isInitialCall) {
    if (!GAME_STATUS->isBattle) {
        gCurrentMeshAnimationListPtr = &gWorldMeshAnimationList;
    } else {
        gCurrentMeshAnimationListPtr = &gBattleMeshAnimationList;
    }

    return ApiStatus_DONE2;
}

ApiStatus LoadModelAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    AnimatedModel* animModel = (*gCurrentMeshAnimationListPtr)[index];
    s32 animModelID = func_8011E4B8(0);

    func_801203AC(animModelID, var1);
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

ApiStatus func_802CCDAC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    AnimatedModel* animModel = (*gCurrentMeshAnimationListPtr)[index];
    s32 animModelID = func_8011E4B8(0);

    func_80120474(animModelID, var1);
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

ApiStatus PlayModelAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->currentAnimData = var2;
    play_model_animation(model->animModelID, var2);

    return ApiStatus_DONE2;
}

ApiStatus func_802CCEDC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[index];

    model->currentAnimData = var2;
    func_80120198(model->animModelID, var2, var3);

    return ApiStatus_DONE2;
}

ApiStatus ChangeModelAnimation(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus SetAnimModelPosition(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus GetAnimModelPosition(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus AddAnimModelPosition(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus SetAnimModelRotation(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus SetAnimModelScale(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus func_802CD348(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 renderMode = get_float_variable(script, *args++);

    get_anim_mesh((*gCurrentMeshAnimationListPtr)[index]->animModelID)->renderMode = renderMode;
    return ApiStatus_DONE2;
}

ApiStatus func_802CD3C0(ScriptInstance* script, s32 isInitialCall) {
    AnimatedModel* model = (*gCurrentMeshAnimationListPtr)[get_variable(script, *script->ptrReadPos)];

    func_8011E438(get_anim_mesh(model->animModelID));
    model->animModelID = -1;
    return ApiStatus_DONE2;
}

ApiStatus func_802CD418(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = get_variable(script, *args++);
    s32 a1 = *args++;
    s32 var2 = get_variable(script, *args++);
    AnimatedMesh* animMesh = get_anim_mesh((*gCurrentMeshAnimationListPtr)[index]->animModelID);

    if (var2) {
        animMesh->flags |= a1;
    } else {
        animMesh->flags &= ~a1;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_ef070_len_3400", func_802CD4B4);

void func_802CD57C(void) {
    if (!GAME_STATUS->isBattle) {
        gCurrentMeshAnimationListPtr = &gWorldMeshAnimationList;
    } else {
        gCurrentMeshAnimationListPtr = &gBattleMeshAnimationList;
    }
}

INCLUDE_ASM(s32, "code_ef070_len_3400", func_802CD5C0);

INCLUDE_ASM(s32, "code_ef070_len_3400", func_802CD6E0);

INCLUDE_ASM(s32, "code_ef070_len_3400", func_802CD7D8);

INCLUDE_ASM(s32, "code_ef070_len_3400", func_802CD8F8);

INCLUDE_ASM(s32, "code_ef070_len_3400", func_802CD9F0);
