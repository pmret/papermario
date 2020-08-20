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

INCLUDE_API_ASM("code_ef070_len_3400", SetCamViewport);

INCLUDE_API_ASM("code_ef070_len_3400", SetCamBGColor);

INCLUDE_API_ASM("code_ef070_len_3400", SetCamTarget);

INCLUDE_API_ASM("code_ef070_len_3400", ShakeCam);

INCLUDE_ASM("code_ef070_len_3400", exec_ShakeCam1);

INCLUDE_ASM("code_ef070_len_3400", exec_ShakeCamX);

INCLUDE_API_ASM("code_ef070_len_3400", SetCamLeadPlayer);

INCLUDE_API_ASM("code_ef070_len_3400", PanToTarget);

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

INCLUDE_API_ASM("code_ef070_len_3400", SetCamPitch);

INCLUDE_API_ASM("code_ef070_len_3400", SetCamDistance);

INCLUDE_API_ASM("code_ef070_len_3400", SetCamPosA);

INCLUDE_API_ASM("code_ef070_len_3400", SetCamPosB);

INCLUDE_API_ASM("code_ef070_len_3400", SetCamPosC);

INCLUDE_API_ASM("code_ef070_len_3400", SetPanTarget);

INCLUDE_API_ASM("code_ef070_len_3400", SetCamSpeed);

INCLUDE_API_ASM("code_ef070_len_3400", GetCamType);

INCLUDE_API_ASM("code_ef070_len_3400", GetCamPitch);

INCLUDE_API_ASM("code_ef070_len_3400", GetCamDistance);

INCLUDE_API_ASM("code_ef070_len_3400", GetCamPosA);

INCLUDE_API_ASM("code_ef070_len_3400", GetCamPosB);

INCLUDE_API_ASM("code_ef070_len_3400", GetCamPosC);

INCLUDE_API_ASM("code_ef070_len_3400", GetCamPosition);

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
