#include "common.h"

extern CamPosSettings blendedCamSettings;
extern f32 D_800A08DC;
extern f32 D_800A08E0;
extern f32 D_800A08E4;
extern f32 D_800A08E8;
extern f32 D_800A08EC;

void cam_interp_lookat_pos(Camera* camera, f32 arg1, f32 arg2, s16 arg3);
void func_8003034C(Camera* camera);

void update_camera_mode_unused(Camera* camera) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sinBoom;
    f32 cosBoom;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;
    f32 deltaX2;
    f32 deltaY2;
    f32 deltaZ2;
    f32 boomYaw;

    if (camera->unk_06 || camera->isChangingMap) {
        camera->unk_06 = FALSE;
        camera->isChangingMap = FALSE;
        camera->auxPitch = 0;
        camera->auxBoomLength = 100;
        camera->lookAt_dist = 100;
        camera->auxBoomPitch = 0;
        camera->auxBoomYaw = 0;
        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;
    }

    if (!(playerStatus->flags & (PS_FLAG_FALLING | PS_FLAG_JUMPING))) {
        camera->lookAt_obj_target.y = playerStatus->position.y + 60.0f;
    }
    camera->lookAt_obj_target.x = playerStatus->position.x;
    camera->lookAt_obj_target.z = playerStatus->position.z + 400.0f;

    if (camera->auxPitch == 0) {
        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;
        camera->trueRotation.x = camera->auxBoomYaw;
        camera->currentBoomYaw = camera->auxBoomPitch;
        camera->currentBoomLength = camera->auxBoomLength;
        camera->vfov = (10000 / camera->lookAt_dist) / 4;
        boomYaw = DEG_TO_RAD(camera->currentBoomYaw);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);
        deltaX = 0.0f;
        deltaY = 0.0f;
        deltaZ = camera->currentBoomLength;
        deltaX2 = deltaX;
        deltaY2 = deltaY;
        boomYaw = deltaX = -deltaY2;
        deltaZ2 = deltaZ;
        deltaX = deltaX2;
        deltaY = cosBoom * deltaY2 + deltaZ2 * sinBoom;
        deltaZ = sinBoom * boomYaw + deltaZ2 * cosBoom;
        boomYaw = DEG_TO_RAD(camera->trueRotation.x);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);
        deltaZ2 = cosBoom * deltaX - deltaZ * sinBoom;
        deltaX2 = cosBoom * deltaX - deltaZ * sinBoom;
        deltaY2 = deltaY;
        deltaZ2 = sinBoom * deltaX + deltaZ * cosBoom;
        camera->lookAt_eye.x = camera->lookAt_obj.x + deltaX2;
        camera->lookAt_eye.y = camera->lookAt_obj.y + deltaY2;
        camera->lookAt_eye.z = camera->lookAt_obj.z + deltaZ2;
    }
    camera->currentYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    deltaX = camera->lookAt_obj.x - camera->lookAt_eye.x;
    deltaY = camera->lookAt_obj.y - camera->lookAt_eye.y;
    deltaZ = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->currentBlendedYawNegated = -atan2(0.0f, 0.0f, deltaX, deltaZ);
    camera->currentPitch = atan2(0.0f, 0.0f, deltaY, -sqrtf(SQ(deltaX) + SQ(deltaZ)));
}

void update_camera_mode_5(Camera* camera) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 lookXDelta, lookYDelta, lookZDelta;

    camera->currentBoomYaw = 18.0f;
    camera->currentBoomLength = 690.0f;
    camera->currentYOffset = 47.0f;

    if (camera->unk_06) {
        camera->unk_550 = 0.0f;
        camera->unk_70 = 0.0f;
        camera->trueRotation.x = 0.0f;
        camera->unk_06 = FALSE;
        camera->unk_554 = 0;
        camera->lookAt_obj.x = camera->targetPos.x;
        camera->lookAt_obj.y = camera->targetPos.y + camera->currentYOffset;
        camera->lookAt_obj.z = camera->targetPos.z;
        cam_interp_lookat_pos(camera, 0.0f, 0.0f, FALSE);
    } else {
        f32 maxInterpSpeed = (playerStatus->currentSpeed * 1.5f) + 1.0f;
        f32 interpRate = (playerStatus->currentSpeed * 0.05f) + 0.05f;

        camera->lookAt_obj_target.x = camera->targetPos.x + camera->unk_550;
        camera->lookAt_obj_target.y = camera->targetPos.y + camera->currentYOffset;
        camera->lookAt_obj_target.z = camera->targetPos.z;
        func_8003034C(camera);
        if (!(camera->moveFlags & CAMERA_MOVE_IGNORE_PLAYER_Y)) {
            cam_interp_lookat_pos(camera, interpRate, maxInterpSpeed, FALSE);
        } else {
            lookXDelta = maxInterpSpeed; // needed to match

            cam_interp_lookat_pos(camera, interpRate, lookXDelta, TRUE);
        }
    }

    camera->currentYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    lookXDelta = camera->lookAt_obj.x - camera->lookAt_eye.x;
    lookYDelta = camera->lookAt_obj.y - camera->lookAt_eye.y;
    lookZDelta = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->currentBlendedYawNegated = -atan2(0.0f, 0.0f, lookXDelta, lookZDelta);
    camera->currentPitch = atan2(0.0f, 0.0f, lookYDelta, -sqrtf(SQ(lookXDelta) + SQ(lookZDelta)));
}

void cam_interp_lookat_pos(Camera* camera, f32 interpAmtXZ, f32 maxDeltaXZ, s16 lockPosY) {
    f32 xDelta = (camera->lookAt_obj_target.x - camera->lookAt_obj.x) * interpAmtXZ;
    f32 theta;
    f32 cosTheta;
    f32 sinTheta;

    if (xDelta < -maxDeltaXZ) {
        xDelta = -maxDeltaXZ;
    }
    if (xDelta > maxDeltaXZ) {
        xDelta = maxDeltaXZ;
    }

    camera->lookAt_obj.x = camera->lookAt_eye.x = camera->lookAt_obj.x + xDelta;

    theta = DEG_TO_RAD(camera->currentBoomYaw);
    cosTheta = cos_rad(DEG_TO_RAD(camera->currentBoomYaw));
    camera->lookAt_obj.z += (camera->lookAt_obj_target.z - camera->lookAt_obj.z) * interpAmtXZ;
    camera->lookAt_eye.z = camera->lookAt_obj.z + (camera->currentBoomLength * cosTheta);

    if (!lockPosY) {
        sinTheta = sin_rad(theta);
        camera->lookAt_obj.y += (camera->lookAt_obj_target.y - camera->lookAt_obj.y) * 0.125f;
        camera->lookAt_eye.y = camera->lookAt_obj.y + (camera->currentBoomLength * sinTheta);
    }
}

void func_8003034C(Camera* camera) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (fabsf(get_clamped_angle_diff(playerStatus->currentYaw, 90.0f)) < 45.0f) {
        if (camera->unk_556 == 0) {
            if (camera->unk_554 <= 0) {
                camera->unk_550 = 35.0f;
            } else {
                camera->unk_554--;
            }
        } else {
            camera->unk_554 = 15;
            camera->unk_556 = 0;
        }
    } else if (fabsf(get_clamped_angle_diff(playerStatus->currentYaw, 270.0f)) < 45.0f) {
        if (camera->unk_556 == 1) {
            if (camera->unk_554 <= 0) {
                camera->unk_550 = -35.0f;
            } else {
                camera->unk_554--;
            }
        } else {
            camera->unk_554 = 15;
            camera->unk_556 = 1;
        }
    }
}

void func_80030450(Camera* camera) {
}

CameraControlSettings* test_ray_zone_aabb(f32 x, f32 y, f32 z) {
    f32 hitX, hitY, hitZ;
    f32 hitDepth = 32767.0f;
    f32 nx, ny, nz;
    s32 zoneID = test_ray_zones(x, y, z, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &nx, &ny, &nz);

    if (zoneID < 0) {
        return NULL;
    }

    return gZoneCollisionData.colliderList[zoneID].camSettings;
}

void update_camera_from_controller(
    Camera* camera,
    CamPosSettings* oldSettings, CameraControlSettings** prevController,
    CamPosSettings* newSettings, CameraControlSettings** newController,
    f32 x1, f32 y1, f32 z1,
    f32 tX, f32 tY, f32 tZ, s32 changingMap,
    f32* interpAlpha, s32 changingZone)
{
    CameraControlSettings* prevSettings;
    CameraControlSettings* controller;
    CamPosSettings* camPos;
    f32 posAx;
    f32 posAz;
    f32 posBx;
    f32 posBz;
    f32 boomLength;

    f32 temp_f18;
    f32 f24;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_7;
    f32 temp_f4;
    f32 temp_f4_13;
    f32 temp_f4_14;
    f32 temp_f4_4;
    f32 temp_f4_9;
    f32 temp_f6;
    f32 temp_f8;
    f32 var_f10;
    f32 var_f16;
    f32 dz;
    f32 dx;

    f32 sp10;
    f32 sp20;

    f32 x, y, z;
    f32 f4_1;
    f32 f22_1;
    f32 f14_1;
    f32 f4_2;
    f32 f12_1;
    
    camPos = oldSettings;
    controller = *prevController;
    x = x1;
    y = y1;
    z = z1;
    
    if ((s32)controller != CAMERA_SETTINGS_PTR_MINUS_2 && (s32)controller != CAMERA_SETTINGS_PTR_MINUS_1) {
        if (controller == CAMERA_SETTINGS_PTR_NULL) {
            camPos->pos.x = x;
            camPos->pos.y = y;
            camPos->pos.z = z;
        } else {
            switch (controller->type) {
                case 0:
                    if (controller->flag != 0) {
                        f32 temp_f10 = -(controller->points.two.Az - controller->points.two.Bz) + controller->points.two.Bx;
                        f32 temp_f6 = (controller->points.two.Ax - controller->points.two.Bx) + controller->points.two.Bz;
                        
                        f32 temp_f8 = controller->points.two.Bx - temp_f10;
                        f32 temp_f12_2 = controller->points.two.Bz - temp_f6;

                        f32 temp_f4 = (SQ(temp_f8) + SQ(temp_f12_2));
                        temp_f4 = (((x - temp_f10) * temp_f8) + ((z - temp_f6) * temp_f12_2)) / temp_f4;
                        
                        camPos->pos.x = temp_f4 * temp_f8 + temp_f10;
                        camPos->pos.y = y;
                        camPos->pos.z = temp_f4 * temp_f12_2 + temp_f6;
                    } else {
                        camPos->pos.x = x;
                        camPos->pos.y = y;
                        camPos->pos.z = z;
                    }
                    break;
                case 6:
                    {
                        f32 ax, az, bx, bz, temp_f8_2, temp_f6_2;
                        f32 f22_1, f4_2, sp10, sp20, f14_1, f12_1;
                        f32 temp_f20, temp_f18;
                        f32 var1, var2;
                        f32 f4_1;
                        f32 var_f16, var_f10, temp_f8_3, temp_f6_3;
                        ax = controller->points.two.Ax;
                        az = controller->points.two.Az;
                        bx = controller->points.two.Bx;
                        bz = controller->points.two.Bz;
                        temp_f8_2 = bx - ax;
                        temp_f6_2 = bz - az;
                        var1 = x - ax;
                        var2 = z - az;
                                                
                        temp_f20 = SQ(temp_f8_2);
                        temp_f18 = SQ(temp_f6_2);
                        
                        f4_1 = temp_f20 + temp_f18;
                        f4_1 = (var1 * temp_f8_2 + var2 * temp_f6_2) / f4_1;
                        
                        var_f16 = f4_1 * temp_f8_2 + ax;
                        var_f10 = f4_1 * temp_f6_2 + az;      

                        f22_1 = controller->points.two.Ax;
                        f4_2 = controller->points.two.Az;
                        sp10 = controller->points.two.Bx;
                        sp20 = controller->points.two.Bz;
                        
                        ax = sp10 - f22_1;
                        az = sp20 - f4_2;
                        
                        temp_f8_2 = var_f16 - f22_1;
                        temp_f6_2 = var_f10 - f4_2;
                        
                        temp_f20 = x - var_f16;
                        temp_f18 = z - var_f10;                    
                        
                        if (ax * temp_f8_2 + az * temp_f6_2 < 0.0f) {
                            var_f16 = f22_1;
                            var_f10 = f4_2;
                        } else if (SQ(temp_f8_2) + SQ(temp_f6_2) > SQ(ax) + SQ(az)) {
                            var_f16 = sp10;
                            var_f10 = sp20;
                        }
                        if (controller->flag == 0) {
                            var_f16 += temp_f20;
                            var_f10 += temp_f18;
                        }
                        camPos->pos.x = var_f16;
                        camPos->pos.y = y;
                        camPos->pos.z = var_f10;
                    }
                    break;
                case 1:
                    if (controller->flag != 0) {
                        dx = x - controller->points.two.Ax;
                        dz = z - controller->points.two.Az;
                        f24 = SQ(dx) + SQ(dz);
                        if (f24 != 0.0f) {
                            f24 = 1.0f / sqrtf(f24);                            
                            temp_f2 = sqrtf(SQ(controller->points.two.Bx - controller->points.two.Ax) + SQ(controller->points.two.Bz - controller->points.two.Az));
                            temp_f2_2 = dx * temp_f2 * f24;
                            temp_f4_4 = dz * temp_f2 * f24;
                            camPos->pos.x = controller->points.two.Ax + temp_f2_2;
                            camPos->pos.y = y;
                            camPos->pos.z = controller->points.two.Az + temp_f4_4;
                        }
                    } else {
                        camPos->pos.x = x;
                        camPos->pos.y = y;
                        camPos->pos.z = z;
                    }
                    break;
                case 2:
                case 5:
                    *prevController = (CameraControlSettings*) CAMERA_SETTINGS_PTR_MINUS_1;
                    break;
                case 3:
                    camPos->pos.x = x;
                    camPos->pos.y = y;
                    camPos->pos.z = z;
                    break;
                case 4:
                    break;
            }
        }
    }
    
    camPos = newSettings;
    controller = *newController;
    x = tX;
    y = tY;
    z = tZ;
    
    if (controller == NULL) {
        camPos->pos.x = x;
        camPos->pos.y = y;
        camPos->pos.z = z;
    } else {
        switch (controller->type) {
            case 0:
                dx = controller->points.two.Bx - controller->points.two.Ax;
                dz = controller->points.two.Bz - controller->points.two.Az;
                camPos->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                boomLength = controller->boomLength;
                if (boomLength < 0.0f) {
                    boomLength = -boomLength;
                }
                camPos->boomLength = boomLength;
                camPos->boomPitch = controller->boomPitch;
                camPos->viewPitch = controller->viewPitch;
                if (controller->flag != 0) {
                    f32 temp_f10 = -(controller->points.two.Az - controller->points.two.Bz) + controller->points.two.Bx;
                    f32 temp_f6 = (controller->points.two.Ax - controller->points.two.Bx) + controller->points.two.Bz;
                    
                    f32 temp_f8 = controller->points.two.Bx - temp_f10;
                    f32 temp_f12_2 = controller->points.two.Bz - temp_f6;

                    f32 temp_f4 = (SQ(temp_f8) + SQ(temp_f12_2));
                    temp_f4 = (((x - temp_f10) * temp_f8) + ((z - temp_f6) * temp_f12_2)) / temp_f4;
                    
                    camPos->pos.x = temp_f4 * temp_f8 + temp_f10;
                    camPos->pos.y = y;
                    camPos->pos.z = temp_f4 * temp_f12_2 + temp_f6;
                } else {
                    camPos->pos.x = x;
                    camPos->pos.y = y;
                    camPos->pos.z = z;
                }

                if (changingZone && *interpAlpha != 1.0f) {
                    prevSettings = *prevController;
                    if (((s32)prevSettings != CAMERA_SETTINGS_PTR_MINUS_2
                            && (s32)prevSettings != CAMERA_SETTINGS_PTR_MINUS_1
                            && (s32)prevSettings != CAMERA_SETTINGS_PTR_NULL)
                        && prevSettings->type == controller->type
                        && prevSettings->boomLength == controller->boomLength
                        && prevSettings->boomPitch == controller->boomPitch
                        && prevSettings->viewPitch == controller->viewPitch
                        && prevSettings->flag != controller->flag
                    ) {
                        *interpAlpha = 1.0f;
                    }
                }
                break;
            case 6:
                dx = controller->points.two.Bx - controller->points.two.Ax;
                dz = controller->points.two.Bz - controller->points.two.Az;
                camPos->boomYaw = atan2(0.0f, 0.0f, dz, -dx);
                boomLength = controller->boomLength;
                if (boomLength < 0.0f) {
                    boomLength = -boomLength;
                }
                camPos->boomLength = boomLength;
                camPos->boomPitch = controller->boomPitch;
                camPos->viewPitch = controller->viewPitch;
                {
                    f32 ax, az, bx, bz, temp_f8_2, temp_f6_2;
                    f32 f22_1, f4_2, sp10, sp20, f14_1, f12_1;
                    f32 temp_f20, temp_f18;
                    f32 var1, var2;
                    f32 f4_1;
                    f32 var_f16, var_f10, temp_f8_3, temp_f6_3;
                    ax = controller->points.two.Ax;
                    az = controller->points.two.Az;
                    bx = controller->points.two.Bx;
                    bz = controller->points.two.Bz;
                    temp_f8_2 = bx - ax;
                    temp_f6_2 = bz - az;
                    var1 = x - ax;
                    var2 = z - az;
                                            
                    temp_f20 = temp_f8_2 * temp_f8_2;
                    temp_f18 = temp_f6_2 * temp_f6_2;
                    
                    f4_1 = temp_f20 + temp_f18;
                    f4_1 = (var1 * temp_f8_2 + var2 * temp_f6_2) / f4_1;
                    
                    var_f16 = f4_1 * temp_f8_2 + ax;
                    var_f10 = f4_1 * temp_f6_2 + az;      

                    f22_1 = controller->points.two.Ax;
                    f4_2 = controller->points.two.Az;
                    sp10 = controller->points.two.Bx;
                    sp20 = controller->points.two.Bz;
                    
                    ax = sp10 - f22_1;
                    az = sp20 - f4_2;
                    
                    temp_f8_2 = var_f16 - f22_1;
                    temp_f6_2 = var_f10 - f4_2;
                    
                    temp_f20 = x - var_f16;
                    temp_f18 = z - var_f10;                    
                    
                    if (ax * temp_f8_2 + az * temp_f6_2 < 0.0f) {
                        var_f16 = f22_1;
                        var_f10 = f4_2;
                    } else if (SQ(temp_f8_2) + SQ(temp_f6_2) > SQ(ax) + SQ(az)) {
                        var_f16 = sp10;
                        var_f10 = sp20;
                    }
                    if (controller->flag == 0) {
                        var_f16 += temp_f20;
                        var_f10 += temp_f18;
                    }
                    camPos->pos.x = var_f16;
                    camPos->pos.y = y;
                    camPos->pos.z = var_f10;
                }
                if (changingZone) {
                    if (*interpAlpha != 1.0f) {
                        prevSettings = *prevController;
                        if (((s32)prevSettings != CAMERA_SETTINGS_PTR_MINUS_2
                                && (s32)prevSettings != CAMERA_SETTINGS_PTR_MINUS_1
                                && (s32)prevSettings != CAMERA_SETTINGS_PTR_NULL) 
                            && (prevSettings->type == controller->type) 
                            && (prevSettings->boomLength == controller->boomLength) 
                            && (prevSettings->boomPitch == controller->boomPitch) 
                            && (prevSettings->viewPitch == controller->viewPitch)
                            && (prevSettings->flag != controller->flag)
                        ) {
                            *interpAlpha = 1.0f;
                        }
                    }
                }
                break;
            case 1:
                // Camera faces toward or away from point A with the player in the center of the frame
                if (controller->boomLength < 0.0f) {
                    // negative boom length means look *away* from point
                    dx = x - controller->points.two.Ax;
                    dz = z - controller->points.two.Az;
                    camPos->boomLength = -controller->boomLength;
                } else {
                    dx = controller->points.two.Ax - x;
                    dz = controller->points.two.Az - z;
                    camPos->boomLength = controller->boomLength;
                }
                camPos->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                camPos->boomPitch = controller->boomPitch;
                camPos->viewPitch = controller->viewPitch;
                if (controller->flag != 0) {
                    // constrain to fixed radius
                    dx = x - controller->points.two.Ax;
                    dz = z - controller->points.two.Az;
                    f24 = SQ(dx) + SQ(dz);
                    if (f24 != 0.0f) {
                        f24 = 1.0f / sqrtf(f24);
                        temp_f2_3 = sqrtf(SQ(controller->points.two.Bx - controller->points.two.Ax) + SQ(controller->points.two.Bz - controller->points.two.Az));
                        temp_f2_4 = dx * temp_f2_3 * f24;
                        temp_f4_9 = dz * temp_f2_3 * f24;
                        camPos->pos.x = controller->points.two.Ax + temp_f2_4;
                        camPos->pos.y = y;
                        camPos->pos.z = controller->points.two.Az + temp_f4_9;
                    }
                } else {
                    camPos->pos.x = x;
                    camPos->pos.y = y;
                    camPos->pos.z = z;
                }

                if (changingZone) {
                    if (*interpAlpha != 1.0f) {
                        prevSettings = *prevController;
                        if (((s32)prevSettings != CAMERA_SETTINGS_PTR_MINUS_2
                                && (s32)prevSettings != CAMERA_SETTINGS_PTR_MINUS_1
                                && (s32)prevSettings != CAMERA_SETTINGS_PTR_NULL)
                            && (prevSettings->type == controller->type) 
                            && (prevSettings->boomLength == controller->boomLength) 
                            && (prevSettings->boomPitch == controller->boomPitch) 
                            && (prevSettings->viewPitch == controller->viewPitch) 
                            && (prevSettings->flag != controller->flag) 
                            && (prevSettings->points.two.Ax == controller->points.two.Ax) 
                            && (prevSettings->points.two.Az == controller->points.two.Az)
                        ) {
                            *interpAlpha = 1.0f;
                        }
                    }
                    break;
                }
                break;
            case 2:
                if (controller->flag == 0) {
                    // Camera is contrained to a point along the line segment BC.
                    // The target position is found by projecting player position onto BC along a
                    // line orthogonal to AB. If posA == posB, the projection axis will be along
                    // BC, i.e., the projection will be along a line orthogonal to BC.
                    f32 posAx;
                    f32 posBx;
                    f32 posCx;
                    f32 posCz;
                    f32 posAz;
                    f32 posBz;
                    f32 Tx, Tz;

                    posAx = controller->points.three.Ax;
                    posAz = controller->points.three.Az;
                    
                    posBx = controller->points.three.Bx;
                    posBz = controller->points.three.Bz;
                    
                    posCx = controller->points.three.Cx;
                    posCz = controller->points.three.Cz;                    

                    if (posAx == posBx && posAz == posBz) {
                        posAx = posCx;
                        posAz = posCz;
                    }
                    
                    if ((posBx - posCx) == 0.0f) {
                        f32 BAx = posBx - posAx;
                        f32 BCx = posBx - posCx;
                        f32 BCz = posBz - posCz;
                        f32 ABz = posAz - posBz;                        
                        f32 Q = BCx * BAx / BCz - ABz;
                        f32 V = (x - posBx) + (posBz - z) * BCx / BCz;
                        
                        Tx = ABz * V / Q + x;
                        Tz = BAx * V / Q + z;
                    } else {
                        f32 BAx = posBx - posAx;
                        f32 ABz = posAz - posBz;
                        f32 BCx = posBx - posCx;
                        f32 BCz = posBz - posCz;
                        f32 Q = ABz * BCz / BCx - BAx;
                        f32 V = (z - posBz) + (posBx - x) * BCz / BCx;
                        
                        Tx = ABz * V / Q + x;
                        Tz = BAx * V / Q + z;
                    }
                    camPos->pos.x = Tx;
                    camPos->pos.y = y;                    
                    camPos->pos.z = Tz;

                    if (changingMap) {
                        dx = controller->points.two.Bx - controller->points.two.Ax;
                        dz = controller->points.two.Bz - controller->points.two.Az;
                        camPos->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                        boomLength = controller->boomLength;
                        if (boomLength < 0.0f) {
                            boomLength = -boomLength;
                        }
                        camPos->boomLength = boomLength;
                        camPos->boomPitch = controller->boomPitch;
                        camPos->viewPitch = controller->viewPitch;
                    }
                } else {
                    if (changingMap) {
                        dx = controller->points.two.Bx - controller->points.two.Ax;
                        dz = controller->points.two.Bz - controller->points.two.Az;
                        camPos->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                        boomLength = controller->boomLength;
                        if (boomLength < 0.0f) {
                            boomLength = -boomLength;
                        }
                        camPos->boomLength = boomLength;
                        camPos->boomPitch = controller->boomPitch;
                        camPos->viewPitch = controller->viewPitch;
                        camPos->pos.x = controller->points.two.Bx;
                        camPos->pos.z = controller->points.two.Bz;
                    } else if (changingZone) {
                        camPos->pos.x = oldSettings->pos.x;
                        camPos->pos.z = oldSettings->pos.z;
                    }
                    camPos->pos.y = y;
                }
                *prevController = (CameraControlSettings*) CAMERA_SETTINGS_PTR_MINUS_1;
                break;
            case 5:
                if (controller->flag == 0) {
                    f32 var3 = x - controller->points.three.Cx;
                    f32 var4 = z - controller->points.three.Cz;
                    f32 var1 = controller->points.three.Bx - controller->points.three.Cx;
                    f32 var2 = controller->points.three.Bz - controller->points.three.Cz;
                    temp_f4_13 = SQ(var1) + SQ(var2);
                    temp_f4_13 = (var3 * var1 + var4 * var2) / temp_f4_13;
                    temp_f2_7 = temp_f4_13 * var1 + controller->points.three.Cx;
                    temp_f4_14 = temp_f4_13 * var2 + controller->points.three.Cz;
                    
                    camPos->pos.x = temp_f2_7;
                    camPos->pos.y = y;                    
                    camPos->pos.z = temp_f4_14;
                    
                    if (controller->boomLength < 0.0f) {
                        dx = temp_f2_7 - controller->points.three.Ax;
                        dz = temp_f4_14 - controller->points.three.Az;
                        camPos->boomLength = -controller->boomLength;
                    } else {
                        dx = controller->points.three.Ax - temp_f2_7;
                        dz = controller->points.three.Az - temp_f4_14;
                        camPos->boomLength = controller->boomLength;
                    }
                    camPos->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                    camPos->boomPitch = controller->boomPitch;
                    camPos->viewPitch = controller->viewPitch;
                } else {
                    if (changingMap) {
                        if (controller->boomLength < 0.0f) {
                            dx = controller->points.three.Bx - controller->points.three.Ax;
                            dz = controller->points.three.Bz - controller->points.three.Az;
                            camPos->boomLength = -controller->boomLength;
                        } else {
                            dx = controller->points.three.Ax - controller->points.three.Bx;
                            dz = controller->points.three.Az - controller->points.three.Bz;
                            camPos->boomLength = controller->boomLength;
                        }
                        camPos->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                        camPos->boomPitch = controller->boomPitch;
                        camPos->viewPitch = controller->viewPitch;
                        camPos->pos.x = controller->points.three.Bx;
                        camPos->pos.z = controller->points.three.Bz;
                    } else if (changingZone) {
                        camPos->pos.x = controller->points.three.Bx;
                        camPos->pos.z = controller->points.three.Bz;
                    }
                    camPos->pos.y = y;
                }
                *prevController = (CameraControlSettings*) CAMERA_SETTINGS_PTR_MINUS_1;
                break;
            case 3:
                camPos->pos.x = x;
                camPos->pos.y = y;
                camPos->pos.z = z;
                break;
            case 4:
                do {
                dx = controller->points.two.Bx - controller->points.two.Ax;
                dz = controller->points.two.Bz - controller->points.two.Az;
                
                camPos->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                } while (0);
                boomLength = controller->boomLength;
                if (boomLength < 0.0f) {
                    boomLength = -boomLength;
                }
                camPos->boomLength = boomLength;
                camPos->boomPitch = controller->boomPitch;
                camPos->viewPitch = controller->viewPitch;
                camPos->pos.x = controller->points.two.Bx;
                camPos->pos.y = controller->points.two.By;
                camPos->pos.z = controller->points.two.Bz;
                *prevController = (CameraControlSettings*) CAMERA_SETTINGS_PTR_MINUS_2;
                break;
        }

        if (changingZone
            && ((controller->type == 5) || (oldSettings->boomYaw != newSettings->boomYaw))
            && (fabsf(oldSettings->boomYaw - newSettings->boomYaw) < 3.0f)
            && (fabsf(oldSettings->boomLength - newSettings->boomLength) < 10.0f)
            && (fabsf(oldSettings->boomPitch - newSettings->boomPitch) < 1.0f)
            && (fabsf(oldSettings->viewPitch - newSettings->viewPitch) < 1.0f)
            && (fabsf(oldSettings->pos.x - newSettings->pos.x) < 10.0f)
            && (fabsf(oldSettings->pos.y - newSettings->pos.y) < 10.0f)
            && (fabsf(oldSettings->pos.z - newSettings->pos.z) < 10.0f)
        ) {
            *interpAlpha = 1.0f;
        }
    }

    if (*prevController == (CameraControlSettings*) CAMERA_SETTINGS_PTR_MINUS_1) {
        if (changingZone) {
            D_800A08E4 = oldSettings->pos.x - newSettings->pos.x;
            D_800A08E8 = oldSettings->pos.y - newSettings->pos.y;
            D_800A08EC = oldSettings->pos.z - newSettings->pos.z;
        }
        oldSettings->pos.x = newSettings->pos.x + D_800A08E4;
        oldSettings->pos.y = newSettings->pos.y + D_800A08E8;
        oldSettings->pos.z = newSettings->pos.z + D_800A08EC;
    }
}

void update_camera_zone_interp(Camera* camera) {
    CameraControlSettings* currentController;
    CameraControlSettings* cs;
    CameraControlSettings* cs2;
    f32 targetX;
    f32 targetY;
    f32 targetZ;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;
    f32 boomYawDiff;
    f32 settingDiff;
    f32 deltaSqSum;
    f32 panPhase;
    f32 temp_f20_2;
    f32 panRad;
    f32 cosViewPitch;
    f32 sinViewPitch;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f26;
    f32 temp_f4_4;
    f32 interpAlpha;
    f32 interpAlphaInv;
    f32 temp_f8_2;
    f64 temp_f22_2;
    s32 cond2;
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 tX;
    f32 tY;
    f32 tZ;
    s32 changingZone;
    f32 dist;
    f32 tempX;
    f32 tempZ;

    targetX = camera->targetPos.x;
    targetY = camera->targetPos.y;
    targetZ = camera->targetPos.z;
    changingZone = FALSE;

    if (camera->isChangingMap) {
        camera->currentController = NULL;
        camera->prevController = NULL;
        camera->linearInterp = 0.0f;
        camera->unk_494 = 0.0f;
        camera->savedTargetY = targetY;
        camera->unk_98 = 0;
        camera->unk_9C = 0;
        camera->unk_4A4 = 0.0f;
        camera->unk_4A8 = 0.0f;
        camera->unk_4AC = 0.0f;
        camera->prevPrevFollowFlags = 0;
        camera->prevFollowFlags = 0;
        camera->panPhase = 0.0f;
        D_800A08DC = 0.0f;
        D_800A08E0 = 0.0f;
        camera->interpAlpha = 1.0f;
        camera->unk_498 = 1.0f;
        camera->linearInterpScale = 1.0f;
    }
    tempX = targetX;
    if (camera->moveFlags & CAMERA_MOVE_IGNORE_PLAYER_Y) {
        camera->unk_498 = 0.0f;
    } else if (camera->unk_494 != targetY) {
        camera->unk_494 = targetY;
        camera->unk_498 = 0.0f;
    }

    if (targetY < camera->unk_494 && targetY <= camera->savedTargetY) {
        camera->unk_494 = targetY;
        camera->unk_498 = 1.0f;
    }

    camera->unk_498 += (1.01 - camera->unk_498) / camera->unk_49C;

    if (camera->unk_498 > 1.0) {
        camera->unk_498 = 1.0f;
    }

    if (camera->moveFlags & CAMERA_MOVE_FLAG_4) {
        camera->unk_498 += 0.3;
        if (camera->unk_498 >= 1.0) {
            camera->unk_498 = 1.0f;
        }
    }

    if (!(camera->moveFlags & CAMERA_MOVE_FLAG_2)) {
        camera->savedTargetY += (camera->unk_494 - camera->savedTargetY) * camera->unk_498;
    }

    tempZ = targetZ;
    if (camera->panActive || camera->unk_4A4 != targetX || camera->unk_4A8 != targetY ||
        camera->unk_4AC != targetZ || camera->isChangingMap) {

        if (camera->followPlayer) {
            cs = &camera->controlSettings;
        } else {
            cs = test_ray_zone_aabb(targetX, targetY + 10.0f, targetZ);
        }

        cond2 = FALSE;
        cs2 = cs;
        currentController = camera->currentController;
        if (cs != NULL
            && currentController != NULL
            && cs->type == currentController->type
            && cs->flag == currentController->flag
            && cs->boomLength == currentController->boomLength
            && cs->boomPitch == currentController->boomPitch
            && cs->viewPitch == currentController->viewPitch
        ) {
            switch (cs->type) {
                case 0:
                    if (cs->points.two.Ax == currentController->points.two.Ax
                        && cs->points.two.Az == currentController->points.two.Az
                        && cs->points.two.Bx == currentController->points.two.Bx
                        && cs->points.two.Bz == currentController->points.two.Bz
                    ) {
                        cond2 = TRUE;
                    }
                    break;
                case 1:
                    switch (cs->flag){
                        case 0:
                            if (cs->points.two.Ax == currentController->points.two.Ax
                                && cs->points.two.Az == currentController->points.two.Az
                            ) {
                                cond2 = TRUE;
                            }
                            break;
                        case 1:
                            if (cs->points.two.Ax == currentController->points.two.Ax
                                && cs->points.two.Az == currentController->points.two.Az
                                && cs->points.two.Bx == currentController->points.two.Bx
                                && cs->points.two.Bz == currentController->points.two.Bz
                            ) {
                                cond2 = TRUE;
                            }
                            break;
                    }
                    break;
                default:
                    if (cs2->points.two.Ax == currentController->points.two.Ax 
                        && cs2->points.two.Az == currentController->points.two.Az 
                        && cs2->points.two.Ay == currentController->points.two.Ay 
                        && cs2->points.two.By == currentController->points.two.By 
                        && cs2->points.two.Bx == currentController->points.two.Bx 
                        && cs2->points.two.Bz == currentController->points.two.Bz
                    ) {
                        cond2 = TRUE;
                    }
                    break;
            }
        }

        if (camera->panActive || (!cond2 && cs2 != currentController)) {
            if (camera->interpAlpha == 1.0f) {
                camera->prevController = camera->currentController;
            } else {
                camera->prevController = (CameraControlSettings*) CAMERA_SETTINGS_PTR_MINUS_1;
            }

            camera->oldCameraSettings = blendedCamSettings;
            changingZone = TRUE;
            camera->currentController = cs;
            camera->interpAlpha = 0.0f;
            camera->linearInterp = 0.0f;
            camera->panActive = FALSE;
            camera->linearInterpScale = camera->moveSpeed;
            camera->prevPrevFollowFlags = camera->prevFollowFlags;
            camera->prevFollowFlags = camera->followPlayer;
            camera->prevPrevMovePos.x = camera->prevMovePos.x;
            camera->prevPrevMovePos.y = camera->prevMovePos.y;
            camera->prevPrevMovePos.z = camera->prevMovePos.z;
            camera->prevMovePos.x = camera->movePos.x;
            camera->prevMovePos.y = camera->movePos.y;
            camera->prevMovePos.z = camera->movePos.z;
        }
    }

    
    if (camera->prevPrevFollowFlags) {
        posX = camera->prevPrevMovePos.x;
        posY = camera->prevPrevMovePos.y;
        posZ = camera->prevPrevMovePos.z;
    } else {
        posX = tempX;
        posY = camera->savedTargetY;
        posZ = tempZ;
    }

    if (camera->prevFollowFlags) {
        camera->savedTargetY = camera->prevMovePos.y;
        tX = camera->prevMovePos.x;
        tY = camera->savedTargetY;
        tZ = camera->prevMovePos.z;
    } else {
        tX = tempX;
        tY = camera->savedTargetY;
        tZ = tempZ;
    }

    update_camera_from_controller(camera, &camera->oldCameraSettings, &camera->prevController,
                                  &camera->newCameraSettings, &camera->currentController, posX, posY, posZ, tX, tY, tZ,
                                  camera->isChangingMap, &camera->interpAlpha, changingZone);

    if (camera->isChangingMap) {
        camera->oldCameraSettings = camera->newCameraSettings;
        camera->isChangingMap = FALSE;
        camera->interpAlpha = 1.0f;
    }

    if (camera->oldCameraSettings.boomYaw - camera->newCameraSettings.boomYaw > 180.0f) {
        camera->oldCameraSettings.boomYaw -= 360.0f;
    }
    if (camera->oldCameraSettings.boomYaw - camera->newCameraSettings.boomYaw < -180.0f) {
        camera->oldCameraSettings.boomYaw += 360.0f;
    }

    settingDiff = camera->oldCameraSettings.boomYaw - camera->newCameraSettings.boomYaw;
    if (settingDiff < 0.0f) {
        settingDiff = -settingDiff;
    }
    if (settingDiff > 180.0f) {
        settingDiff = 360.0f - settingDiff;
    }

    boomYawDiff = settingDiff;
    settingDiff = camera->oldCameraSettings.boomPitch - camera->newCameraSettings.boomPitch;
    if (settingDiff < 0.0f) {
        settingDiff = -settingDiff;
    }
    if (settingDiff > 180.0f) {
        settingDiff = 360.0f - settingDiff;
    }
    if (boomYawDiff < settingDiff) {
        boomYawDiff = settingDiff;
    }

    settingDiff = camera->oldCameraSettings.viewPitch - camera->newCameraSettings.viewPitch;
    if (settingDiff < 0.0f) {
        settingDiff = -settingDiff;
    }
    if (settingDiff > 180.0f) {
        settingDiff = 360.0f - settingDiff;
    }
    if (boomYawDiff < settingDiff) {
        boomYawDiff = settingDiff;
    }

    settingDiff = camera->oldCameraSettings.boomLength - camera->newCameraSettings.boomLength;
    if (settingDiff < 0.0f) {
        settingDiff = -settingDiff;
    }
    if (boomYawDiff < settingDiff) {
        boomYawDiff = settingDiff;
    }

    deltaX = camera->oldCameraSettings.pos.x - camera->newCameraSettings.pos.x;
    deltaY = camera->oldCameraSettings.pos.y - camera->newCameraSettings.pos.y;
    deltaZ = camera->oldCameraSettings.pos.z - camera->newCameraSettings.pos.z;
    settingDiff = SQ(deltaX);
    settingDiff += SQ(deltaY);
    settingDiff += SQ(deltaZ);

    if (settingDiff != 0.0f) {
        settingDiff = sqrtf(settingDiff) * 0.2;
    }

    if (boomYawDiff < settingDiff) {
        boomYawDiff = settingDiff;
        settingDiff++;
        settingDiff--;
    }
    if (boomYawDiff > 90.0f) {
        boomYawDiff = 90.0f;
    }
    if (boomYawDiff < 20.0f) {
        boomYawDiff = 20.0f;
    }

    if (boomYawDiff != 0.0f) {
        camera->linearInterp += (1.0f / boomYawDiff) * camera->linearInterpScale;
        if (camera->linearInterp > 1.0f) {
            camera->linearInterp = 1.0f;
        }
    }

    if (camera->interpAlpha < 1.0) {
        panPhase = camera->panPhase;
        panRad = panPhase * PI_D;
        temp_f24 = 2.0f / (cos_rad(panRad) + 1.0f);
        temp_f22_2 = cos_rad((camera->linearInterp * PI_D * (1.0f - panPhase)) + panRad);
        cosViewPitch = (temp_f22_2 + (1.0 - cos_rad(panRad)) * 0.5) * temp_f24;
        cosViewPitch = (2.0f - (cosViewPitch + 1.0f)) * 0.5001;
        camera->interpAlpha = cosViewPitch;
    }

    if (camera->interpAlpha >= 1.0f) {
        camera->interpAlpha = 1.0f;
        camera->linearInterp = 0.0f;
    }

    interpAlpha = camera->interpAlpha;
    interpAlphaInv = 1.0f - interpAlpha;
    camera->unk_4A4 = targetX;
    camera->unk_4A8 = targetY;
    camera->unk_4AC = targetZ;
    blendedCamSettings.boomYaw = (camera->oldCameraSettings.boomYaw * interpAlphaInv) + (camera->newCameraSettings.boomYaw * interpAlpha);
    blendedCamSettings.boomLength = (camera->oldCameraSettings.boomLength * interpAlphaInv) + (camera->newCameraSettings.boomLength * interpAlpha);
    blendedCamSettings.boomPitch = (camera->oldCameraSettings.boomPitch * interpAlphaInv) + (camera->newCameraSettings.boomPitch * interpAlpha);
    blendedCamSettings.viewPitch = (camera->oldCameraSettings.viewPitch * interpAlphaInv) + (camera->newCameraSettings.viewPitch * interpAlpha);
    blendedCamSettings.pos.x = (camera->oldCameraSettings.pos.x * interpAlphaInv) + (camera->newCameraSettings.pos.x * interpAlpha);
    blendedCamSettings.pos.y = (camera->oldCameraSettings.pos.y * interpAlphaInv) + (camera->newCameraSettings.pos.y * interpAlpha);
    blendedCamSettings.pos.z = (camera->oldCameraSettings.pos.z * interpAlphaInv) + (camera->newCameraSettings.pos.z * interpAlpha);
    blendedCamSettings.boomLength *= camera->zoomPercent;
    blendedCamSettings.boomLength *= 0.01;

    func_80030450(camera);
    temp_f20_2 = blendedCamSettings.boomYaw + D_800A08E0;
    temp_f26 = sin_deg(temp_f20_2);
    temp_f24_2 = -cos_deg(temp_f20_2);
    cosViewPitch = cos_deg(blendedCamSettings.boomPitch + D_800A08DC);
    sinViewPitch = sin_deg(blendedCamSettings.boomPitch + D_800A08DC);

    if (!(camera->moveFlags & CAMERA_MOVE_FLAG_2)) {
        camera->lookAt_eye.y = blendedCamSettings.pos.y + (blendedCamSettings.boomLength * sinViewPitch);
    }

    camera->lookAt_eye.x = blendedCamSettings.pos.x - (temp_f26 * blendedCamSettings.boomLength * cosViewPitch);
    camera->lookAt_eye.z = blendedCamSettings.pos.z - (temp_f24_2 * blendedCamSettings.boomLength * cosViewPitch);
    cosViewPitch = cos_deg(-blendedCamSettings.viewPitch);
    sinViewPitch = sin_deg(-blendedCamSettings.viewPitch);

    if (camera->lookAt_eye.x == blendedCamSettings.pos.x && camera->lookAt_eye.z == blendedCamSettings.pos.z) {
        dist = 0.0f;
    } else {
        dist = dist2D(camera->lookAt_eye.x, camera->lookAt_eye.z, blendedCamSettings.pos.x, blendedCamSettings.pos.z);
    }

    temp_f8_2 = blendedCamSettings.pos.y - camera->lookAt_eye.y;
    if (!(camera->moveFlags & CAMERA_MOVE_FLAG_2)) {
        camera->lookAt_obj.y = camera->lookAt_eye.y + ((dist * sinViewPitch) + (temp_f8_2 * cosViewPitch));
    }
    temp_f4_4 = (dist * cosViewPitch) - (temp_f8_2 * sinViewPitch);
    camera->lookAt_obj.x = camera->lookAt_eye.x + (temp_f26 * temp_f4_4);
    camera->lookAt_obj.z = camera->lookAt_eye.z + (temp_f24_2 * temp_f4_4);
    camera->currentYaw = blendedCamSettings.boomYaw + D_800A08E0;
    camera->trueRotation.x = camera->currentYaw;
    camera->currentBoomLength = blendedCamSettings.boomLength;
    camera->currentBlendedYawNegated = -blendedCamSettings.boomYaw;
    camera->currentPitch = -blendedCamSettings.boomPitch - blendedCamSettings.viewPitch;
    camera->lookAt_obj_target.x = camera->lookAt_obj.x;
    camera->lookAt_obj_target.y = camera->lookAt_obj.y;
    camera->lookAt_obj_target.z = camera->lookAt_obj.z;
    camera->currentYOffset = 0.0f;
}
