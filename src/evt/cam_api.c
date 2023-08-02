#include "common.h"
#include "camera.h"

EvtScript ShakeCam1 = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(ShakeCam, LVar0, LVar1, LVar2, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript ShakeCamX = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(ShakeCam, LVar0, LVar1, LVar2, LVar3)
    EVT_RETURN
    EVT_END
};

ApiStatus SetCamEnabled(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    s32 enabled = evt_get_variable(script, *args++);

    if (!enabled) {
        gCameras[id].flags |= CAMERA_FLAG_DISABLED;
    } else {
        gCameras[id].flags &= ~CAMERA_FLAG_DISABLED;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetCamFlag80(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    s32 enabled = evt_get_variable(script, *args++);

    if (!enabled) {
        gCameras[id].flags |= CAMERA_FLAG_80;
    } else {
        gCameras[id].flags &= ~CAMERA_FLAG_80;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetCamPerspective(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    s16 mode = evt_get_variable(script, *args++);
    f32 vfov = evt_get_float_variable(script, *args++);
    s16 nearClip = evt_get_variable(script, *args++);
    s16 farClip = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];

    camera->updateMode = mode;
    camera->needsInit = TRUE;
    camera->isChangingMap = TRUE;

    camera->vfov = vfov;
    camera->farClip = farClip;
    camera->nearClip = nearClip;
    return ApiStatus_DONE2;
}

ApiStatus func_802CA90C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    s16 mode = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];

    camera->updateMode = mode;
    camera->needsInit = FALSE;
    return ApiStatus_DONE2;
}

ApiStatus func_802CA988(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode id = evt_get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Bytecode outVar3 = *args++;
    Bytecode outVar4 = *args++;
    f32 dx, dy, dz;

    gCameras[id].updateMode = CAM_UPDATE_MODE_2;
    gCameras[id].needsInit = FALSE;
    gCameras[id].auxPitch = -round(gCameras[id].curPitch);
    gCameras[id].auxBoomLength = -gCameras[id].curBlendedYawNegated;

    dx = gCameras[id].lookAt_obj.x - gCameras[id].lookAt_eye.x;
    dy = gCameras[id].lookAt_obj.y - gCameras[id].lookAt_eye.y;
    dz = gCameras[id].lookAt_obj.z - gCameras[id].lookAt_eye.z;

    gCameras[id].lookAt_dist = round(sqrtf(SQ(dx) + SQ(dy) + SQ(dz)));
    gCameras[id].auxBoomPitch = 0;
    gCameras[id].lookAt_obj_target.x = gCameras[id].lookAt_obj.x;
    gCameras[id].lookAt_obj_target.y = gCameras[id].lookAt_obj.y;
    gCameras[id].lookAt_obj_target.z = gCameras[id].lookAt_obj.z;

    evt_set_variable(script, outVar1, gCameras[id].auxPitch);
    evt_set_variable(script, outVar2, gCameras[id].auxBoomLength);
    evt_set_variable(script, outVar3, gCameras[id].lookAt_dist);
    evt_set_variable(script, outVar4, gCameras[id].auxBoomPitch);
    return ApiStatus_DONE2;
}

ApiStatus SetCamViewport(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s16 width = evt_get_variable(script, *args++);
    s16 height = evt_get_variable(script, *args++);

    set_cam_viewport(id, x, y, width, height);
    return ApiStatus_DONE2;
}

ApiStatus func_802CABE8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    s16 value1 = evt_get_variable(script, *args++);
    s32 value2 = evt_get_variable(script, *args++);
    s32 value3 = evt_get_variable(script, *args++);
    s16 value4 = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];

    camera->auxBoomPitch = value4;
    camera->auxPitch = value1;
    camera->auxBoomLength = value2;
    camera->lookAt_dist = value3;
    return ApiStatus_DONE2;
}

ApiStatus func_802CACC0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    s16 value1 = evt_get_variable(script, *args++);
    s32 value2 = evt_get_variable(script, *args++);
    s32 value3 = evt_get_variable(script, *args++);
    s16 zoomPercent = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];

    camera->zoomPercent = zoomPercent;
    camera->auxBoomYaw = value1;
    camera->auxBoomZOffset = value2;
    camera->unk_28 = value3;
    return ApiStatus_DONE2;
}

ApiStatus SetCamBGColor(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    s16 r = evt_get_variable(script, *args++);
    s16 g = evt_get_variable(script, *args++);
    s16 b = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];

    camera->bgColor[0] = r;
    camera->bgColor[1] = g;
    camera->bgColor[2] = b;
    return ApiStatus_DONE2;
}

ApiStatus func_802CAE50(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    s32 value1 = evt_get_variable(script, *args++);
    s32 value2 = evt_get_variable(script, *args++);
    s32 value3 = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];

    camera->lookAt_obj_target.x = value1;
    camera->lookAt_obj_target.y = value2;
    camera->lookAt_obj_target.z = value3;
    return ApiStatus_DONE2;
}

ApiStatus SetCamTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];

    camera->targetPos.x = x;
    camera->targetPos.y = y;
    camera->targetPos.z = z;
    return ApiStatus_DONE2;
}

ApiStatus InterpCamTargetPos(Evt* script, s32 isInitialCall) {
    typedef struct CamInterpData {
        /* 0x00 */ Camera* cam;
        /* 0x04 */ s32 useTarget;
        /* 0x08 */ Vec3f vel;
        /* 0x14 */ s32 time;
    } CamInterpData; // size = 0x18

    Bytecode* args = script->ptrReadPos;
    CamInterpData* data;
    Camera* cam;

    if (isInitialCall) {
        s32 camID = evt_get_variable(script, *args++);
        s32 useTarget = evt_get_variable(script, *args++);
        s32 posX = evt_get_variable(script, *args++);
        s32 posY = evt_get_variable(script, *args++);
        s32 posZ = evt_get_variable(script, *args++);
        s32 time = evt_get_variable(script, *args++);

        data = heap_malloc(sizeof(*data));
        script->userData = data;
        cam = &gCameras[camID];
        data->cam = cam;
        data->useTarget = useTarget;
        data->time = time;

        switch (data->useTarget) {
            case 0:
                data->vel.x = (posX - cam->lookAt_obj_target.x) / data->time;
                data->vel.y = (posY - cam->lookAt_obj_target.y) / data->time;
                data->vel.z = (posZ - cam->lookAt_obj_target.z) / data->time;
                break;
            case 1:
                data->vel.x = (posX - cam->targetPos.x) / data->time;
                data->vel.y = (posY - cam->targetPos.y) / data->time;
                data->vel.z = (posZ - cam->targetPos.z) / data->time;
                break;
        }
    }

    data = script->userData;
    cam = data->cam;
    switch (data->useTarget) {
        case 0:
            cam->lookAt_obj_target.x += data->vel.x;
            cam->lookAt_obj_target.y += data->vel.y;
            cam->lookAt_obj_target.z += data->vel.z;
            break;
        case 1:
            cam->targetPos.x += data->vel.x;
            cam->targetPos.y += data->vel.y;
            cam->targetPos.z += data->vel.z;
            break;
    }

    data->time--;
    if (data->time == 0) {
        heap_free(script->userData);
        script->userData = NULL;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus ShakeCam(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 camIndex = evt_get_variable(script, *args++);
    s32 shakeMode = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    f32 magnitude = 2.0f * evt_get_float_variable(script, *args++);
    Camera* camera = &gCameras[camIndex];
    f32 scale;
    f32 rumbleMagnitude;
    s32 rumbleDuration;

    if (isInitialCall) {
        switch (shakeMode){
            case CAM_SHAKE_CONSTANT_VERTICAL:
            case CAM_SHAKE_ANGULAR_HORIZONTAL:
                break;
            case CAM_SHAKE_DECAYING_VERTICAL:
                duration *= 4;
                break;
        }

        *(f32*)&script->functionTemp[3] = 1.0f; //TODO functionTempF ?
        script->functionTemp[1] = duration;

        if (!gGameStatusPtr->isBattle) {
            if (magnitude > 10.0f) {
                magnitude = 10.0f;
            }

            rumbleMagnitude = magnitude;
            if (rumbleMagnitude > 6.0f) {
                rumbleMagnitude = 6.0f;
            }
            rumbleMagnitude = rumbleMagnitude * 32.0f + 64.0f;

            rumbleDuration = duration;

            if (rumbleDuration < 5) {
                rumbleDuration = 5;
            }
            start_rumble(rumbleMagnitude, (rumbleDuration & 0xFFFF) * 2);
        }
    }

    camera->flags |= CAMERA_FLAG_SHAKING;
    scale = script->functionTempF[3];
    switch (shakeMode) {
        case CAM_SHAKE_CONSTANT_VERTICAL:
            guTranslateF(camera->viewMtxShaking, 0.0f, -scale * magnitude, 0.0f);
            script->functionTempF[3] = -script->functionTempF[3];
            break;
        case CAM_SHAKE_ANGULAR_HORIZONTAL:
            guRotateF(camera->viewMtxShaking, scale * magnitude, 0.0f, 0.0f, 1.0f);
            script->functionTempF[3] = -script->functionTempF[3];
            break;
        case CAM_SHAKE_DECAYING_VERTICAL:
            guTranslateF(camera->viewMtxShaking, 0.0f, -scale * magnitude, 0.0f);
            if ((script->functionTemp[1] < (duration * 2)) && (duration < script->functionTemp[1])) {
                script->functionTempF[3] = script->functionTempF[3] * -0.8;
            } else {
                script->functionTempF[3] = -script->functionTempF[3];
            }
            break;
    }

    if (script->functionTemp[1] == 0) {
        camera->flags &= ~CAMERA_FLAG_SHAKING;
        return ApiStatus_DONE2;
    }
    script->functionTemp[1]--;
    return ApiStatus_BLOCK;
}

void exec_ShakeCam1(s32 camID, s32 mode, s32 duration) {
    Evt* script;

    script = start_script_in_group(&ShakeCam1, EVT_PRIORITY_1, 0, EVT_GROUP_04);
    script->varTable[0] = camID;
    script->varTable[1] = mode;
    script->varTable[2] = duration;
}

void exec_ShakeCamX(s32 camID, s32 mode, s32 duration, f32 magnitude) {
    Evt* script;

    script = start_script_in_group(&ShakeCamX, EVT_PRIORITY_1, 0, EVT_GROUP_04);
    evt_set_variable(script, LVar0, camID);
    evt_set_variable(script, LVar1, mode);
    evt_set_variable(script, LVar2, duration);
    evt_set_float_variable(script, LVar3, magnitude);
}

ApiStatus SetCamLeadPlayer(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    s32 enabled = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];

    if (enabled) {
        camera->flags |= CAMERA_FLAG_LEAD_PLAYER;
    } else {
        camera->flags &= ~CAMERA_FLAG_LEAD_PLAYER;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802CB710(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    f32 value = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];

    camera->unk_520 = (value / 100.0f);
    return ApiStatus_DONE2;
}

ApiStatus PanToTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    f32 panPhase = evt_get_float_variable(script, *args++);
    s32 targetType = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];

    camera->panActive = TRUE;
    if (targetType != 0) {
        camera->followPlayer = TRUE;
        camera->panPhase = panPhase;
    } else {
        camera->followPlayer = FALSE;
        camera->panPhase = 0.0f;
        camera->moveSpeed = 1.0f;
    }
    return ApiStatus_DONE2;
}

ApiStatus UseSettingsFrom(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];
    f32 startX = evt_get_float_variable(script, *args++);
    f32 startY = evt_get_float_variable(script, *args++);
    f32 startZ = evt_get_float_variable(script, *args++);
    f32 hitX, hitY, hitZ;
    f32 hitDepth = 32767.0f;
    f32 nx, ny, nz;
    s32 hitID = test_ray_zones(startX, startY + 10.0f, startZ, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth,
                               &nx, &ny, &nz);

    if (hitID >= 0) {
        camera->controlSettings = *gZoneCollisionData.colliderList[hitID].camSettings;
    }
    return ApiStatus_DONE2;
}

ApiStatus LoadSettings(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];
    CameraControlSettings* settings = (CameraControlSettings*) evt_get_variable(script, *args++);

    camera->controlSettings = *settings;
    return ApiStatus_DONE2;
}

ApiStatus SetCamType(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];
    s32 controllerType = evt_get_variable(script, *args++);
    s32 enabled = evt_get_variable(script, *args++);

    camera->controlSettings.flag = enabled;
    camera->controlSettings.type = controllerType;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPitch(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];
    f32 boomPitch = evt_get_float_variable(script, *args++);
    f32 viewPitch = evt_get_float_variable(script, *args++);

    camera->controlSettings.boomPitch = boomPitch;
    camera->controlSettings.viewPitch = viewPitch;
    return ApiStatus_DONE2;
}

ApiStatus SetCamDistance(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];
    f32 boomLength = evt_get_float_variable(script, *args++);

    camera->controlSettings.boomLength = boomLength;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPosA(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];
    f32 x = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    camera->controlSettings.points.two.Ax = x;
    camera->controlSettings.points.two.Az = z;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPosB(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];
    f32 x = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    camera->controlSettings.points.two.Bx = x;
    camera->controlSettings.points.two.Bz = z;
    return ApiStatus_DONE2;
}

ApiStatus SetCamPosC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];
    f32 y1 = evt_get_float_variable(script, *args++);
    f32 y2 = evt_get_float_variable(script, *args++);

    camera->controlSettings.points.two.Ay = y1;
    camera->controlSettings.points.two.By = y2;
    return ApiStatus_DONE2;
}

ApiStatus SetPanTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    camera->movePos.x = x;
    camera->movePos.y = y;
    camera->movePos.z = z;
    camera->panActive = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus SetCamSpeed(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    f32 speed = evt_get_float_variable(script, *args++);
    Camera* camera = &gCameras[id];

    camera->moveSpeed = speed;
    return ApiStatus_DONE2;
}

ApiStatus GetCamType(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* camera = &gCameras[id];

    evt_set_variable(script, outVar1, camera->controlSettings.type);
    evt_set_variable(script, outVar2, camera->controlSettings.flag);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPitch(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* camera = &gCameras[id];

    evt_set_float_variable(script, outVar1, camera->controlSettings.boomPitch);
    evt_set_float_variable(script, outVar2, camera->controlSettings.viewPitch);
    return ApiStatus_DONE2;
}

ApiStatus GetCamDistance(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Camera* camera = &gCameras[id];

    evt_set_float_variable(script, outVar1, camera->controlSettings.boomLength);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosA(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* camera = &gCameras[id];

    evt_set_float_variable(script, outVar1, camera->controlSettings.points.two.Ax);
    evt_set_float_variable(script, outVar2, camera->controlSettings.points.two.Az);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosB(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* camera = &gCameras[id];

    evt_set_float_variable(script, outVar1, camera->controlSettings.points.two.Bx);
    evt_set_float_variable(script, outVar2, camera->controlSettings.points.two.Bz);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Camera* camera = &gCameras[id];

    evt_set_float_variable(script, outVar1, camera->controlSettings.points.two.Ay);
    evt_set_float_variable(script, outVar2, camera->controlSettings.points.two.By);
    return ApiStatus_DONE2;
}

ApiStatus GetCamPosition(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Bytecode outVar1 = *args++;
    Bytecode outVar2 = *args++;
    Bytecode outVar3 = *args++;
    Camera* camera = &gCameras[id];

    evt_set_float_variable(script, outVar1, camera->movePos.x);
    evt_set_float_variable(script, outVar2, camera->movePos.y);
    evt_set_float_variable(script, outVar3, camera->movePos.z);
    return ApiStatus_DONE2;
}

ApiStatus WaitForCam(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, args[0]);
    f32 endInterpValue = evt_get_float_variable(script, args[1]);
    Camera* camera = &gCameras[id];

    if (isInitialCall || !(endInterpValue <= camera->interpAlpha)) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetCamProperties(Evt* script, s32 isInitialCall) {
    f32 hitX, hitY, hitZ, hitDepth, nX, nY, nZ;
    s32 zoneID;
    Bytecode* args = script->ptrReadPos;
    Camera* camera = &gCameras[evt_get_variable(script, *args++)];
    f32 moveSpeed = evt_get_float_variable(script, *args++);
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    f32 boomLength = evt_get_float_variable(script, *args++);
    f32 boomPitch = evt_get_float_variable(script, *args++);
    f32 viewPitch = evt_get_float_variable(script, *args++);

    if (isInitialCall) {
        hitDepth = 32767.0f;
        zoneID = test_ray_zones(posX, posY + 10.0f, posZ, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &nX, &nY, &nZ);
        if (zoneID >= 0) {
            camera->controlSettings = *gZoneCollisionData.colliderList[zoneID].camSettings;
        }

        camera->movePos.x = posX;
        camera->movePos.y = posY;
        camera->movePos.z = posZ;
        camera->controlSettings.boomLength = boomLength;
        camera->controlSettings.boomPitch = boomPitch;
        camera->controlSettings.viewPitch = viewPitch;
        camera->moveSpeed = moveSpeed;
        camera->panActive = TRUE;
        camera->followPlayer = TRUE;
        camera->panPhase = 0.0f;
        return ApiStatus_BLOCK;
    }

    if (camera->interpAlpha >= 1.0f) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus AdjustCam(Evt* script, s32 isInitialCall) {
    f32 hitX, hitY, hitZ, hitDepth, nX, nY, nZ;
    f32 posX, posY, posZ;
    s32 zoneID;
    Bytecode* args = script->ptrReadPos;
    Camera* camera = &gCameras[evt_get_variable(script, *args++)];
    f32 moveSpeed = evt_get_float_variable(script, *args++);
    f32 deltaPosX = evt_get_float_variable(script, *args++);
    f32 boomLength = evt_get_float_variable(script, *args++);
    f32 boomPitch = evt_get_float_variable(script, *args++);
    f32 viewPitch = evt_get_float_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        hitDepth = 32767.0f;
        posX = playerStatus->pos.x;
        posY = playerStatus->pos.y;
        posZ = playerStatus->pos.z;
        zoneID = test_ray_zones(posX, posY + 10.0f, posZ, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &nX, &nY, &nZ);
        if (zoneID >= 0) {
            camera->controlSettings = *gZoneCollisionData.colliderList[zoneID].camSettings;
        }

        camera->movePos.x = posX + deltaPosX;
        camera->movePos.y = posY;
        camera->movePos.z = posZ;
        camera->controlSettings.boomLength = boomLength;
        camera->controlSettings.boomPitch = boomPitch;
        camera->controlSettings.viewPitch = viewPitch;
        camera->moveSpeed = moveSpeed;
        camera->panActive = TRUE;
        camera->followPlayer = TRUE;
        camera->panPhase = 0.0f;
        return ApiStatus_BLOCK;
    }

    if (camera->interpAlpha >= 1.0f) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus ResetCam(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 id = evt_get_variable(script, *args++);
    Camera* camera = &gCameras[id];
    f32 moveSpeed = evt_get_float_variable(script, *args++);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        f32 x = playerStatus->pos.x;
        f32 y = playerStatus->pos.y;
        f32 z = playerStatus->pos.z;
        f32 hitX, hitY, hitZ;
        f32 hitDepth = 32767.0f;
        f32 nx, ny, nz;
        s32 hitID;

        hitID = test_ray_zones(x, y + 10.0f, z, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth,
                               &nx, &ny, &nz);

        if (hitID >= 0) {
            camera->controlSettings = *gZoneCollisionData.colliderList[hitID].camSettings;
        }

        camera->movePos.x = x;
        camera->movePos.y = y;
        camera->movePos.z = z;
        camera->moveSpeed = moveSpeed;
        camera->panActive = TRUE;
        camera->followPlayer = TRUE;
        camera->panPhase = 0.0f;
        return ApiStatus_BLOCK;
    }

    if (camera->interpAlpha >= 1.0f) {
        camera->panActive = TRUE;
        camera->followPlayer = FALSE;
        camera->moveSpeed = 1.0f;
        camera->panPhase = 0.0f;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
