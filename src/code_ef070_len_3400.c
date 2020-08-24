#include "common.h"

ApiStatus SetCamEnabled(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);

    if (!enabled) {
        (&gCameras[id])->flags |= 0x2;
    } else {
        (&gCameras[id])->flags &= ~0x2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetCamFlag80(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);

    if (!enabled) {
        (&gCameras[id])->flags |= 0x80;
    } else {
        (&gCameras[id])->flags &= ~0x80;
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
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
    Camera* camera = &cameras[id];

    camera->mode = mode;
    camera->unk_06 = 0;
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_ef070_len_3400", func_802CA988);
/*
ApiStatus func_802CA988(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    Bytecode id = get_variable(script, *ptrReadPos++);
    Bytecode outVar1 = *ptrReadPos++;
    Bytecode outVar2 = *ptrReadPos++;
    Bytecode outVar3 = *ptrReadPos++;
    Bytecode outVar4 = *ptrReadPos++;
    f32 temp1, temp2, temp3;
    f32 tempSqrt;

    (&gCameras[id])->mode = 2;
    (&gCameras[id])->unk_1C = -1 * round((&gCameras[id])->currentPitch);
    (&gCameras[id])->unk_1E = -1 * (&gCameras[id])->currentBlendedYawNegated;
    (&gCameras[id])->unk_06 = 0;

    temp1 = (&gCameras[id])->lookAt_obj[0] - (&gCameras[id])->lookAt_eye[0];
    temp2 = (&gCameras[id])->lookAt_obj[1] - (&gCameras[id])->lookAt_eye[1];
    temp3 = (&gCameras[id])->lookAt_obj[2] - (&gCameras[id])->lookAt_eye[2];

    tempSqrt = sqrtf((temp1 * temp1) + (temp2 * temp2) + (temp3 * temp3));
    if (tempSqrt != tempSqrt) {
        (&gCameras[id])->unk_20 = round(tempSqrt);
    }

    (&gCameras[id])->unk_22 = 0;
    (&gCameras[id])->unk_54 = (&gCameras[id])->lookAt_obj[0];
    (&gCameras[id])->unk_58 = (&gCameras[id])->lookAt_obj[1];
    (&gCameras[id])->unk_5C = (&gCameras[id])->lookAt_obj[2];

    set_variable(script, outVar1, (&gCameras[id])->unk_1C);
    set_variable(script, outVar2, (&gCameras[id])->unk_1E);
    set_variable(script, outVar3, (&gCameras[id])->unk_20);
    set_variable(script, outVar4, (&gCameras[id])->unk_22);
    return ApiStatus_DONE2;
}
*/

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
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
    Camera* camera = &cameras[id];

    camera->targetPos.x = x;
    camera->targetPos.y = y;
    camera->targetPos.z = z;
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_ef070_len_3400", func_802CB008);

INCLUDE_API_ASM("code_ef070_len_3400", ShakeCam);

INCLUDE_ASM("code_ef070_len_3400", exec_ShakeCam1);

INCLUDE_ASM("code_ef070_len_3400", exec_ShakeCamX);

ApiStatus SetCamLeadPlayer(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    s32 enabled = get_variable(script, *args++);
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
    Camera* camera = &cameras[id];

    camera->unk_520 = (value / 100.0f);
    return ApiStatus_DONE2;
}

ApiStatus PanToTarget(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    f32 panPhase = get_float_variable(script, *args++);
    s32 targetType = get_variable(script, *args++);
    Camera* cameras = &gCameras;
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

INCLUDE_API_ASM("code_ef070_len_3400", UseSettingsFrom);

INCLUDE_API_ASM("code_ef070_len_3400", LoadSettings);

ApiStatus SetCamType(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
    Camera* camera = &cameras[id];
    f32 boomLength = get_float_variable(script, *args++);

    camera->controllerBoomLen = boomLength;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPosA(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
    Camera* camera = &cameras[id];

    camera->moveSpeed = speed;
    return ApiStatus_DONE2;
}

ApiStatus GetCamType(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->controllerBoomPitch);
    set_float_variable(script, outVar2, camera->controllerViewPitch);
    return ApiStatus_DONE2;
}

ApiStatus GetCamDistance(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Camera* cameras = &gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->controllerBoomLen);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosA(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
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
    Camera* cameras = &gCameras;
    Camera* camera = &cameras[id];

    set_float_variable(script, outVar1, camera->movePos.x);
    set_float_variable(script, outVar2, camera->movePos.y);
    set_float_variable(script, outVar3, camera->movePos.z);
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_ef070_len_3400", WaitForCam);

INCLUDE_API_ASM("code_ef070_len_3400", SetCamProperties);

INCLUDE_API_ASM("code_ef070_len_3400", AdjustCam);

INCLUDE_API_ASM("code_ef070_len_3400", ResetCam);

INCLUDE_ASM("code_ef070_len_3400", draw_anim_models);

INCLUDE_API_ASM("code_ef070_len_3400", LoadModelAnimation);

INCLUDE_API_ASM("code_ef070_len_3400", PlayModelAnimation);

INCLUDE_API_ASM("code_ef070_len_3400", ChangeModelAnimation);

INCLUDE_API_ASM("code_ef070_len_3400", SetAnimModelPosition);

INCLUDE_API_ASM("code_ef070_len_3400", GetAnimModelPosition);

INCLUDE_API_ASM("code_ef070_len_3400", AddAnimModelPosition);

INCLUDE_API_ASM("code_ef070_len_3400", SetAnimModelRotation);

INCLUDE_API_ASM("code_ef070_len_3400", SetAnimModelScale);

INCLUDE_ASM("code_ef070_len_3400", func_802CD4B4);

INCLUDE_ASM("code_ef070_len_3400", func_802CD57C);
