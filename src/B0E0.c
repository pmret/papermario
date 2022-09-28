#include "common.h"

extern CamPosSettings blendedCamSettings;
extern f32 D_800A08DC;
extern f32 D_800A08E0;
extern f32 D_800A08E4;
extern f32 D_800A08E8;
extern f32 D_800A08EC;

void func_80030210(Camera* camera, f32 arg1, f32 arg2, s32 arg3);
void func_8003034C(Camera* camera);

void update_camera_mode_unused(Camera* camera);
// Issues with zero float temp?
#ifdef NON_EQUIVALENT
void update_camera_mode_unused(Camera* camera) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 temp_f30;
    f32 temp_f24_2;
    f32 theta;
    f32 sinTheta1;
    f32 cosTheta1;
    f32 sinTheta2;
    f32 cosTheta2;
    f32 lookXDelta;
    f32 lookYDelta;
    f32 lookZDelta;

    if (camera->unk_06 != 0 || camera->unk_08 != 0) {
        camera->unk_06 = 0;
        camera->unk_08 = 0;
        camera->unk_1C = 0;
        camera->unk_1E = 100;
        camera->unk_20 = 100;
        camera->unk_22 = 0;
        camera->unk_24 = 0;
        camera->lookAt_obj.x = camera->unk_54;
        camera->lookAt_obj.y = camera->unk_58;
        camera->lookAt_obj.z = camera->unk_5C;
    }

    if (!(playerStatus->flags & 6)) {
        camera->unk_58 = playerStatus->position.y + 60.0f;
    }

    camera->unk_54 = playerStatus->position.x;
    camera->unk_5C = playerStatus->position.z + 400.0f;

    if (camera->unk_1C == 0) {
        s32 fovTemp = 10000 / camera->unk_20;

        camera->lookAt_obj.x = camera->unk_54;
        camera->lookAt_obj.y = camera->unk_58;
        camera->lookAt_obj.z = camera->unk_5C;
        camera->trueRotation.x = (f32) camera->unk_24;
        camera->currentBoomYaw = (f32) camera->unk_22;
        camera->currentBoomLength = (f32) camera->unk_1E;

        if (fovTemp < 0) {
            fovTemp += 3;
        }
        camera->vfov = fovTemp >> 2;

        theta = DEG_TO_RAD(camera->currentBoomYaw);
        sinTheta1 = sin_rad(theta);
        cosTheta1 = cos_rad(theta);
        temp_f30 = (cosTheta1 * 0.0f) + (camera->currentBoomLength * sinTheta1);
        temp_f24_2 = (sinTheta1 * -0.0f) + (camera->currentBoomLength * cosTheta1);

        theta = DEG_TO_RAD(camera->trueRotation.x);
        sinTheta2 = sin_rad(theta);
        cosTheta2 = cos_rad(theta);
        camera->lookAt_eye.x = camera->lookAt_obj.x + ((cosTheta2 * 0.0f) - (temp_f24_2 * sinTheta2));
        camera->lookAt_eye.y = camera->lookAt_obj.y + temp_f30;
        camera->lookAt_eye.z = camera->lookAt_obj.z + ((sinTheta2 * 0.0f) + (temp_f24_2 * cosTheta2));
    }

    camera->currentYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    lookXDelta = camera->lookAt_obj.x - camera->lookAt_eye.x;
    lookYDelta = camera->lookAt_obj.y - camera->lookAt_eye.y;
    lookZDelta = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->currentBlendedYawNegated = -atan2(0.0f, 0.0f, lookXDelta, lookZDelta);
    camera->currentPitch = atan2(0.0f, 0.0f, lookYDelta, -sqrtf(SQ(lookXDelta) + SQ(lookZDelta)));
}
#else
INCLUDE_ASM(void, "B0E0", update_camera_mode_unused, Camera* camera);
#endif

void update_camera_mode_5(Camera* camera) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 lookXDelta, lookYDelta, lookZDelta;

    camera->currentBoomYaw = 18.0f;
    camera->currentBoomLength = 690.0f;
    camera->currentYOffset = 47.0f;

    if (camera->unk_06 != 0) {
        camera->unk_550 = 0.0f;
        camera->unk_70 = 0.0f;
        camera->trueRotation.x = 0.0f;
        camera->unk_06 = 0;
        camera->unk_554 = 0;
        camera->lookAt_obj.x = camera->targetPos.x;
        camera->lookAt_obj.y = camera->targetPos.y + camera->currentYOffset;
        camera->lookAt_obj.z = camera->targetPos.z;
        func_80030210(camera, 0.0f, 0.0f, 0);
    } else {
        f32 temp_f22 = (playerStatus->currentSpeed * 1.5f) + 1.0f;
        f32 temp_f20 = (playerStatus->currentSpeed * 0.05f) + 0.05f;

        camera->auxPos.x = camera->targetPos.x + camera->unk_550;
        camera->auxPos.y = camera->targetPos.y + camera->currentYOffset;
        camera->auxPos.z = camera->targetPos.z;
        func_8003034C(camera);
        if (!(camera->moveFlags & CAMERA_MOVE_FLAGS_1)) {
            func_80030210(camera, temp_f20, temp_f22, 0);
        } else {
            lookXDelta = temp_f22; // needed to match

            func_80030210(camera, temp_f20, lookXDelta, 1);
        }
    }

    camera->currentYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    lookXDelta = camera->lookAt_obj.x - camera->lookAt_eye.x;
    lookYDelta = camera->lookAt_obj.y - camera->lookAt_eye.y;
    lookZDelta = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->currentBlendedYawNegated = -atan2(0.0f, 0.0f, lookXDelta, lookZDelta);
    camera->currentPitch = atan2(0.0f, 0.0f, lookYDelta, -sqrtf(SQ(lookXDelta) + SQ(lookZDelta)));
}

void func_80030210(Camera* camera, f32 arg1, f32 arg2, s32 arg3) {
    f32 xDelta = (camera->auxPos.x - camera->lookAt_obj.x) * arg1;
    f32 theta;
    f32 cosTheta;
    f32 sinTheta;

    if (xDelta < -arg2) {
        xDelta = -arg2;
    }
    if (xDelta > arg2) {
        xDelta = arg2;
    }

    camera->lookAt_obj.x = camera->lookAt_eye.x = camera->lookAt_obj.x + xDelta;
    theta = DEG_TO_RAD(camera->currentBoomYaw);

    cosTheta = cos_rad(theta);
    camera->lookAt_obj.z += (camera->auxPos.z - camera->lookAt_obj.z) * arg1;
    camera->lookAt_eye.z = camera->lookAt_obj.z + (camera->currentBoomLength * cosTheta);

    if (arg3 << 16 == 0) {
        sinTheta = sin_rad(theta);
        camera->lookAt_obj.y += (camera->auxPos.y - camera->lookAt_obj.y) * 0.125f;
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

void update_camera_from_controller(Camera*, CamPosSettings*, CameraControlSettings**, CamPosSettings*, CameraControlSettings**, f32, f32, f32, f32, f32, f32, s32, f32*, s32);
// WIP - needs a lot of work
#ifdef NON_EQUIVALENT
void update_camera_from_controller(
    Camera* camera,
    CamPosSettings* oldSettings, CameraControlSettings** prevController,
    CamPosSettings* newSettings, CameraControlSettings** newController,
    f32 x, f32 y, f32 z,
    f32 tX, f32 tY, f32 tZ, s32 changingMap,
    f32* interpAlpha, s32 changingZone)
{
    CameraControlSettings* prevSettings;
    CameraControlSettings* settings;
    f32 posAx;
    f32 posAz;
    f32 posAy;
    f32 posBy;
    f32 posBx;
    f32 posBz;
    f32 boomLength;

    f32 temp_f0_2;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f10;
    f32 temp_f10_2;
    f32 temp_f10_3;
    f32 temp_f12_2;
    f32 temp_f12_5;
    f32 temp_f18;
    f32 temp_f18_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f24_3;
    f32 temp_f24_4;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 temp_f4;
    f32 temp_f4_11;
    f32 temp_f4_12;
    f32 temp_f4_13;
    f32 temp_f4_14;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    f32 temp_f4_5;
    f32 temp_f4_6;
    f32 temp_f4_8;
    f32 temp_f4_9;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f6_3;
    f32 temp_f6_4;
    f32 temp_f6_5;
    f32 temp_f6_6;
    f32 temp_f6_7;
    f32 temp_f6_8;
    f32 temp_f6_9;
    f32 temp_f8;
    f32 temp_f8_2;
    f32 temp_f8_3;
    f32 temp_f8_4;
    f32 temp_f8_5;
    f32 temp_f8_6;
    f32 temp_f8_7;
    f32 temp_f8_8;
    f32 temp_f8_9;
    f32 var_f0_3;
    f32 var_f10;
    f32 var_f10_2;
    f32 var_f16;
    f32 var_f16_2;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f20_3;
    f32 var_f22;
    f32 var_f22_2;
    f32 var_f22_3;
    f32 var_f6;
    f32 var_f6_2;
    f32 var_f8;

    settings = *prevController;
    if ((u32) (settings) + 2 >= 2U) {
        if (settings == NULL) {
            oldSettings->position.x = x;
            oldSettings->position.y = y;
            oldSettings->position.z = z;
        } else {
            switch (settings->type) {
                case 0:
                    if (settings->flag != 0) {
                        posBx = settings->posB.x;
                        posBz = settings->posB.z;
                        temp_f10 = -(settings->posA.z - posBz) + posBx;
                        temp_f8 = posBx - temp_f10;
                        temp_f6 = (settings->posA.x - posBx) + posBz;
                        temp_f12_2 = posBz - temp_f6;
                        temp_f4 = (((x - temp_f10) * temp_f8) + ((z - temp_f6) * temp_f12_2)) / (SQ(temp_f8) + SQ(temp_f12_2));
                        oldSettings->position.x = (temp_f4 * temp_f8) + temp_f10;
                        oldSettings->position.y = y;
                        oldSettings->position.z = (temp_f4 * temp_f12_2) + temp_f6;
                        break;
                    }
                    oldSettings->position.x = x;
                    oldSettings->position.y = y;
                    oldSettings->position.z = z;
                    break;
                case 6:
                    posAx = settings->posA.x;
                    posBx = settings->posB.x;
                    temp_f8_2 = posBx - posAx;
                    posAz = settings->posA.z;
                    posBz = settings->posB.z;
                    temp_f6_2 = posBz - posAz;
                    temp_f4_2 = (((x - posAx) * temp_f8_2) + ((z - posAz) * temp_f6_2)) / ((temp_f8_2 * temp_f8_2) + (temp_f6_2 * temp_f6_2));
                    var_f16 = (temp_f4_2 * temp_f8_2) + posAx;
                    temp_f8_3 = var_f16 - posAx;
                    var_f10 = (temp_f4_2 * temp_f6_2) + posAz;
                    temp_f6_3 = var_f10 - posAz;
                    temp_f20 = x - var_f16;
                    temp_f18 = z - var_f10;
                    if (((temp_f8_2 * temp_f8_3) + (temp_f6_2 * temp_f6_3)) < 0.0f) {
                        var_f16 = posAx;
                        var_f10 = posAz;
                    } else if (((temp_f8_2 * temp_f8_2) + (temp_f6_2 * temp_f6_2)) < ((temp_f8_3 * temp_f8_3) + (temp_f6_3 * temp_f6_3))) {
                        var_f16 = posBx;
                        var_f10 = posBz;
                    }
                    if (settings->flag == 0) {
                        var_f16 += temp_f20;
                        var_f10 += temp_f18;
                    }
                    oldSettings->position.x = var_f16;
                    oldSettings->position.y = y;
                    oldSettings->position.z = var_f10;
                    break;
                case 1:
                    if (settings->flag != 0) {
                        temp_f22 = x - settings->posA.x;
                        temp_f20_2 = z - settings->posA.z;
                        temp_f24 = (temp_f22 * temp_f22) + (temp_f20_2 * temp_f20_2);
                        if (temp_f24 != 0.0f) {
                            var_f6 = sqrtf(temp_f24);
                            temp_f4_3 = settings->posB.x - settings->posA.x;
                            temp_f0_2 = settings->posB.z - settings->posA.z;
                            temp_f24_2 = 1.0f / var_f6;
                            temp_f2 = sqrtf(SQ(temp_f4_3) + SQ(temp_f0_2));
                            temp_f2_2 = settings->posA.x + (temp_f22 * temp_f2 * temp_f24_2);
                            temp_f4_4 = temp_f20_2 * temp_f2 * temp_f24_2;
                            oldSettings->position.x = temp_f2_2;
                            oldSettings->position.y = y;
                            oldSettings->position.z = settings->posA.z + temp_f4_4;
                        }
                    } else {
                        oldSettings->position.x = x;
                        oldSettings->position.y = y;
                        oldSettings->position.z = z;
                    }
                    break;
                case 2:
                case 5:
                    *prevController = (CameraControlSettings* )-1;
                    break;
                case 3:
                    oldSettings->position.x = x;
                    oldSettings->position.y = y;
                    oldSettings->position.z = z;
                    break;
            }
        }
    }

    settings = *newController;
    if (settings == NULL) {
        newSettings->position.x = tX;
        newSettings->position.y = tY;
        newSettings->position.z = tZ;
    } else {
        switch (settings->type) {
            case 0:
                newSettings->boomYaw = atan2(0.0f, 0.0f, settings->posB.x - settings->posA.x, settings->posB.z - settings->posA.z);
                boomLength = settings->boomLength;
                if (boomLength < 0.0f) {
                    boomLength = -boomLength;
                }
                newSettings->boomLength = boomLength;
                newSettings->boomPitch = settings->boomPitch;
                newSettings->viewPitch = settings->viewPitch;
                if (settings->flag != 0) {
                    posBz = settings->posB.z;
                    posBx = settings->posB.x;
                    temp_f10_2 = -(settings->posA.z - posBz) + posBx;
                    temp_f8_4 = posBx - temp_f10_2;
                    temp_f6_4 = (settings->posA.x - posBx) + posBz;
                    temp_f12_5 = posBz - temp_f6_4;
                    temp_f4_5 = (((tX - temp_f10_2) * temp_f8_4) + ((tZ - temp_f6_4) * temp_f12_5)) / ((temp_f8_4 * temp_f8_4) + (temp_f12_5 * temp_f12_5));
                    newSettings->position.y = tY;
                    newSettings->position.x = (temp_f4_5 * temp_f8_4) + temp_f10_2;
                    newSettings->position.z = (temp_f4_5 * temp_f12_5) + temp_f6_4;
                } else {
                    newSettings->position.x = tX;
                    newSettings->position.y = tY;
                    newSettings->position.z = tZ;
                }

                if (changingZone) {
                    if (*interpAlpha != 1.0f) {
                        prevSettings = *prevController;
                        if (((u32) (prevSettings + 2) >= 3U) &&
                            prevSettings->type == settings->type &&
                            prevSettings->boomLength == settings->boomLength &&
                            prevSettings->boomPitch == settings->boomPitch &&
                            prevSettings->viewPitch == settings->viewPitch &&
                            prevSettings->flag != settings->flag)
                        {
                            *interpAlpha = 1.0f;
                        }
                    }
                }
                break;
            case 6:
                newSettings->boomYaw = atan2(0.0f, 0.0f, settings->posB.z - settings->posA.z, -(settings->posB.x - settings->posA.x));
                boomLength = settings->boomLength;
                if (boomLength < 0.0f) {
                    boomLength = -boomLength;
                }
                newSettings->boomLength = boomLength;
                newSettings->boomPitch = settings->boomPitch;
                newSettings->viewPitch = settings->viewPitch;
                posAx = settings->posA.x;
                posBx = settings->posB.x;
                temp_f8_5 = posBx - posAx;
                posAz = settings->posA.z;
                posBz = settings->posB.z;
                temp_f6_5 = posBz - posAz;
                temp_f4_6 = (((tX - posAx) * temp_f8_5) + ((tZ - posAz) * temp_f6_5)) / ((temp_f8_5 * temp_f8_5) + (temp_f6_5 * temp_f6_5));
                var_f16_2 = (temp_f4_6 * temp_f8_5) + posAx;
                temp_f8_6 = var_f16_2 - posAx;
                var_f10_2 = (temp_f4_6 * temp_f6_5) + posAz;
                temp_f6_6 = var_f10_2 - posAz;
                temp_f20_3 = tX - var_f16_2;
                temp_f18_2 = tZ - var_f10_2;
                if (((temp_f8_5 * temp_f8_6) + (temp_f6_5 * temp_f6_6)) < 0.0f) {
                    var_f16_2 = posAx;
                    var_f10_2 = posAz;
                } else if (((temp_f8_5 * temp_f8_5) + SQ(temp_f6_5)) < (SQ(temp_f8_6) + SQ(temp_f6_6))) {
                    var_f16_2 = posBx;
                    var_f10_2 = posBz;
                }
                if (settings->flag == 0) {
                    var_f16_2 += temp_f20_3;
                    var_f10_2 += temp_f18_2;
                }
                newSettings->position.x = var_f16_2;
                newSettings->position.y = tY;
                newSettings->position.z = var_f10_2;
                if (changingZone) {
                    if (*interpAlpha != 1.0f) {
                        prevSettings = *prevController;
                        if (((u32) (prevSettings + 2) >= 3U) &&
                            (prevSettings->type == settings->type) &&
                            (prevSettings->boomLength == settings->boomLength) &&
                            (prevSettings->boomPitch == settings->boomPitch) &&
                            (prevSettings->viewPitch == settings->viewPitch) &&
                            (prevSettings->flag != settings->flag))
                        {
                            *interpAlpha = 1.0f;
                        }
                    }
                }
                break;
            case 1:
                if (settings->boomLength < 0.0f) {
                    var_f22 = tX - settings->posA.x;
                    newSettings->boomLength = -settings->boomLength;
                    var_f20 = tZ - settings->posA.z;
                } else {
                    var_f22 = settings->posA.x - tX;
                    newSettings->boomLength = settings->boomLength;
                    var_f20 = settings->posA.z - tZ;
                }
                newSettings->boomYaw = atan2(0.0f, 0.0f, var_f22, var_f20);
                newSettings->boomPitch = settings->boomPitch;
                newSettings->viewPitch = settings->viewPitch;
                if (settings->flag != 0) {
                    temp_f22_2 = tX - settings->posA.x;
                    temp_f20_4 = tZ - settings->posA.z;
                    temp_f24_3 = SQ(temp_f22_2) + SQ(temp_f20_4);
                    if (temp_f24_3 != 0.0f) {
                        var_f6_2 = sqrtf(temp_f24_3);
                        temp_f4_8 = settings->posB.x - settings->posA.x;
                        temp_f0_4 = settings->posB.z - settings->posA.z;
                        temp_f24_4 = 1.0f / var_f6_2;
                        temp_f2_3 = sqrtf((temp_f4_8 * temp_f4_8) + (temp_f0_4 * temp_f0_4));
                        temp_f2_4 = settings->posA.x + (temp_f22_2 * temp_f2_3 * temp_f24_4);
                        temp_f4_9 = temp_f20_4 * temp_f2_3 * temp_f24_4;
                        newSettings->position.y = tY;
                        newSettings->position.x = temp_f2_4;
                        newSettings->position.z = settings->posA.z + temp_f4_9;
                    }
                } else {
                    newSettings->position.x = tX;
                    newSettings->position.y = tY;
                    newSettings->position.z = tZ;
                }

                if (changingZone) {
                    if (*interpAlpha != 1.0f) {
                        prevSettings = *prevController;
                        if (((u32) (prevSettings + 2) >= 3U) &&
                            (prevSettings->type == settings->type) &&
                            (prevSettings->boomLength == settings->boomLength) &&
                            (prevSettings->boomPitch == settings->boomPitch) &&
                            (prevSettings->viewPitch == settings->viewPitch) &&
                            (prevSettings->flag != settings->flag) &&
                            (prevSettings->posA.x == settings->posA.x) &&
                            (prevSettings->posA.z == settings->posA.z))
                        {
                            *interpAlpha = 1.0f;
                        }
                    }
                    break;
                }
                break;
            case 2:
                if (settings->flag == 0) {
                    posAx = settings->posA.x;
                    posBx = settings->posB.x;
                    posAz = settings->posA.z;
                    posBz = settings->posB.z;
                    posAy = settings->posA.y;
                    posBy = settings->posB.y;
                    temp_f8_7 = posBx - posAy;
                    if ((posAx == posBx) && (posAz == posBz)) {
                        posAx = posAy;
                        posAz = posBy;
                    }
                    if (temp_f8_7 != 0.0f) {
                        temp_f6_7 = posAz - posBz;
                        temp_f2_5 = posBz - posBy;
                        temp_f2_6 = (tZ - posBz) + (((posBx - tX) * temp_f2_5) / temp_f8_7);
                        temp_f0_5 = posBx - posAx;
                        temp_f4_11 = ((temp_f6_7 * temp_f2_5) / temp_f8_7) - temp_f0_5;
                        var_f8 = ((temp_f6_7 * temp_f2_6) / temp_f4_11) + tX;
                        var_f0_3 = ((temp_f0_5 * temp_f2_6) / temp_f4_11) + tZ;
                    } else {
                        temp_f6_8 = posBx - posAx;
                        temp_f10_3 = posAz - posBz;
                        temp_f8_8 = posBz - posBy;
                        temp_f0_6 = (tX - posBx) + (((posBz - tZ) * temp_f8_7) / temp_f8_8);
                        temp_f4_12 = ((temp_f8_7 * temp_f6_8) / temp_f8_8) - temp_f10_3;
                        var_f8 = ((temp_f10_3 * temp_f0_6) / temp_f4_12) + tX;
                        var_f0_3 = ((temp_f6_8 * temp_f0_6) / temp_f4_12) + tZ;
                    }
                    newSettings->position.x = var_f8;
                    newSettings->position.y = tY;
                    newSettings->position.z = var_f0_3;

                    if (changingMap) {
                        newSettings->boomYaw = atan2(0.0f, 0.0f, settings->posB.x - settings->posA.x, settings->posB.z - settings->posA.z);
                        boomLength = settings->boomLength;
                        if (boomLength < 0.0f) {
                            boomLength = -boomLength;
                        }
                        newSettings->boomLength = boomLength;
                        newSettings->boomPitch = settings->boomPitch;
                        newSettings->viewPitch = settings->viewPitch;
                    }
                } else {
                    if (changingMap) {
                        newSettings->boomYaw = atan2(0.0f, 0.0f, settings->posB.x - settings->posA.x, settings->posB.z - settings->posA.z);
                        boomLength = settings->boomLength;
                        if (boomLength < 0.0f) {
                            boomLength = -boomLength;
                        }
                        newSettings->boomLength = boomLength;
                        newSettings->boomPitch = settings->boomPitch;
                        newSettings->viewPitch = settings->viewPitch;
                        newSettings->position.x = settings->posB.x;
                        newSettings->position.z = settings->posB.z;
                    } else if (changingZone) {
                        newSettings->position.x = oldSettings->position.x;
                        newSettings->position.z = oldSettings->position.z;
                    }
                    newSettings->position.y = tY;
                }
                *prevController = (CameraControlSettings*) -1;
                break;
            case 5:
                if (settings->flag == 0) {
                    posAy = settings->posA.y;
                    temp_f6_9 = settings->posB.x - posAy;
                    posBy = settings->posB.y;
                    temp_f8_9 = settings->posB.z - posBy;
                    temp_f4_13 = (((tX - posAy) * temp_f6_9) + ((tZ - posBy) * temp_f8_9)) / ((temp_f6_9 * temp_f6_9) + (temp_f8_9 * temp_f8_9));
                    temp_f2_7 = (temp_f4_13 * temp_f6_9) + posAy;
                    temp_f4_14 = (temp_f4_13 * temp_f8_9) + posBy;
                    newSettings->position.y = tY;
                    newSettings->position.x = temp_f2_7;
                    newSettings->position.z = temp_f4_14;
                    if (settings->boomLength < 0.0f) {
                        var_f22_2 = temp_f2_7 - settings->posA.x;
                        newSettings->boomLength = -settings->boomLength;
                        var_f20_2 = temp_f4_14 - settings->posA.z;
                    } else {
                        var_f22_2 = settings->posA.x - temp_f2_7;
                        newSettings->boomLength = settings->boomLength;
                        var_f20_2 = settings->posA.z - temp_f4_14;
                    }
                    newSettings->boomYaw = atan2(0.0f, 0.0f, var_f22_2, var_f20_2);
                    newSettings->boomPitch = settings->boomPitch;
                    newSettings->viewPitch = settings->viewPitch;
                } else {
                    if (changingMap) {
                        if (settings->boomLength < 0.0f) {
                            var_f22_3 = settings->posB.x - settings->posA.x;
                            newSettings->boomLength = -settings->boomLength;
                            var_f20_3 = settings->posB.z - settings->posA.z;
                        } else {
                            var_f22_3 = settings->posA.x - settings->posB.x;
                            newSettings->boomLength = settings->boomLength;
                            var_f20_3 = settings->posA.z - settings->posB.z;
                        }
                        newSettings->boomYaw = atan2(0.0f, 0.0f, var_f22_3, var_f20_3);
                        newSettings->boomPitch = settings->boomPitch;
                        newSettings->viewPitch = settings->viewPitch;
                        newSettings->position.x = settings->posB.x;
                        newSettings->position.z = settings->posB.z;
                    } else if (changingZone) {
                        newSettings->position.x = settings->posB.x;
                        newSettings->position.z = settings->posB.z;
                    }
                    newSettings->position.y = tY;
                }
                *prevController = (CameraControlSettings*) -1;
                break;
            case 3:
                newSettings->position.x = tX;
                newSettings->position.y = tY;
                newSettings->position.z = tZ;
                break;
            case 4:
                newSettings->boomYaw = atan2(0.0f, 0.0f, settings->posB.x - settings->posA.x, settings->posB.z - settings->posA.z);
                boomLength = settings->boomLength;
                if (boomLength < 0.0f) {
                    boomLength = -boomLength;
                }
                newSettings->boomLength = boomLength;
                newSettings->boomPitch = settings->boomPitch;
                newSettings->viewPitch = settings->viewPitch;
                newSettings->position.x = settings->posB.x;
                newSettings->position.y = settings->posB.y;
                newSettings->position.z = settings->posB.z;
                *prevController = (CameraControlSettings*) -2;
                break;
        }

        if (changingZone &&
            ((settings->type == 5) || (oldSettings->boomYaw != newSettings->boomYaw)) &&
            (fabsf(oldSettings->boomYaw - newSettings->boomYaw) < 3.0f) &&
            (fabsf(oldSettings->boomLength - newSettings->boomLength) < 10.0f) &&
            (fabsf(oldSettings->boomPitch - newSettings->boomPitch) < 1.0f) &&
            (fabsf(oldSettings->viewPitch - newSettings->viewPitch) < 1.0f) &&
            (fabsf(oldSettings->position.x - newSettings->position.x) < 10.0f) &&
            (fabsf(oldSettings->position.y - newSettings->position.y) < 10.0f) &&
            (fabsf(oldSettings->position.z - newSettings->position.z) < 10.0f))
        {
            *interpAlpha = 1.0f;
        }
    }

    if (*prevController == (CameraControlSettings* )-1) {
        if (changingZone) {
            D_800A08E4 = oldSettings->position.x - newSettings->position.x;
            D_800A08E8 = oldSettings->position.y - newSettings->position.y;
            D_800A08EC = oldSettings->position.z - newSettings->position.z;
        }
        oldSettings->position.x = newSettings->position.x + D_800A08E4;
        oldSettings->position.y = newSettings->position.y + D_800A08E8;
        oldSettings->position.z = newSettings->position.z + D_800A08EC;
    }
}
#else
INCLUDE_ASM(s32, "B0E0", update_camera_from_controller);
#endif

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
    f32 temp;
    f32 temp2;

    targetX = camera->targetPos.x;
    targetY = camera->targetPos.y;
    targetZ = camera->targetPos.z;
    changingZone = FALSE;

    if (camera->changingMap) {
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
    temp = targetX;
    if (camera->moveFlags & CAMERA_MOVE_FLAGS_1) {
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

    if (camera->moveFlags & CAMERA_MOVE_FLAGS_4) {
        camera->unk_498 += 0.3;
        if (camera->unk_498 >= 1.0) {
            camera->unk_498 = 1.0f;
        }
    }

    if (!(camera->moveFlags & CAMERA_MOVE_FLAGS_2)) {
        camera->savedTargetY += (camera->unk_494 - camera->savedTargetY) * camera->unk_498;
    }

    temp2 = targetZ;
    if (camera->unk_506 != 0 || camera->unk_4A4 != targetX || camera->unk_4A8 != targetY ||
        camera->unk_4AC != targetZ || camera->changingMap) {

        if (camera->followPlayer) {
            cs = &camera->controlSettings;
        } else {
            cs = test_ray_zone_aabb(targetX, targetY + 10.0f, targetZ);
        }

        cond2 = FALSE;
        cs2 = cs;
        currentController = camera->currentController;
        if (cs != NULL && currentController != NULL && cs->type == currentController->type &&
            cs->flag == currentController->flag && cs->boomLength == currentController->boomLength &&
            cs->boomPitch == currentController->boomPitch &&
            cs->viewPitch == currentController->viewPitch) {

            switch (cs->type) {
                case 0:
                    if (cs->posA.x == currentController->posA.x &&
                        cs->posA.z == currentController->posA.z &&
                        cs->posB.x == currentController->posB.x &&
                        cs->posB.z == currentController->posB.z) {

                        cond2 = TRUE;
                    }
                    break;
                case 1:
                    switch (cs->flag){
                        case 0:
                            if (cs->posA.x == currentController->posA.x &&
                                cs->posA.z == currentController->posA.z) {
                                cond2 = TRUE;
                            }
                            break;
                        case 1:
                            if (cs->posA.x == currentController->posA.x &&
                                cs->posA.z == currentController->posA.z &&
                                cs->posB.x == currentController->posB.x &&
                                cs->posB.z == currentController->posB.z) {
                                cond2 = TRUE;
                            }
                            break;
                    }
                    break;
                default:
                    if (cs2->posA.x == currentController->posA.x &&
                        cs2->posA.z == currentController->posA.z &&
                        cs2->posA.y == currentController->posA.y &&
                        cs2->posB.y == currentController->posB.y &&
                        cs2->posB.x == currentController->posB.x &&
                        cs2->posB.z == currentController->posB.z) {

                        cond2 = TRUE;
                    }
                    break;
            }
        }

        if (camera->unk_506 != 0 || (!cond2 && cs2 != currentController)) {
            if (camera->interpAlpha == 1.0f) {
                camera->prevController = camera->currentController;
            } else {
                camera->prevController = (CameraControlSettings*)-1;
            }

            camera->oldCameraSettings = blendedCamSettings;
            changingZone = TRUE;
            camera->currentController = cs;
            camera->interpAlpha = 0.0f;
            camera->linearInterp = 0.0f;
            camera->unk_506 = 0;
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

    posX = temp;
    if (camera->prevPrevFollowFlags) {
        posX = camera->prevPrevMovePos.x;
        posY = camera->prevPrevMovePos.y;
        posZ = camera->prevPrevMovePos.z;
    } else {
        posY = camera->savedTargetY;
        posZ = temp2;
    }

    tX = temp;
    if (camera->prevFollowFlags) {
        camera->savedTargetY = camera->prevMovePos.y;
        tX = camera->prevMovePos.x;
        tY = camera->savedTargetY;
        tZ = camera->prevMovePos.z;
    } else {
        tY = camera->savedTargetY;
        tZ = temp2;
    }

    update_camera_from_controller(camera, &camera->oldCameraSettings, &camera->prevController,
                                  &camera->newCameraSettings, &camera->currentController, posX, posY, posZ, tX, tY, tZ,
                                  camera->changingMap, &camera->interpAlpha, changingZone);

    if (camera->changingMap) {
        camera->oldCameraSettings = camera->newCameraSettings;
        camera->changingMap = FALSE;
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

    deltaX = camera->oldCameraSettings.position.x - camera->newCameraSettings.position.x;
    deltaY = camera->oldCameraSettings.position.y - camera->newCameraSettings.position.y;
    deltaZ = camera->oldCameraSettings.position.z - camera->newCameraSettings.position.z;
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
    blendedCamSettings.position.x = (camera->oldCameraSettings.position.x * interpAlphaInv) + (camera->newCameraSettings.position.x * interpAlpha);
    blendedCamSettings.position.y = (camera->oldCameraSettings.position.y * interpAlphaInv) + (camera->newCameraSettings.position.y * interpAlpha);
    blendedCamSettings.position.z = (camera->oldCameraSettings.position.z * interpAlphaInv) + (camera->newCameraSettings.position.z * interpAlpha);
    blendedCamSettings.boomLength *= camera->zoomPercent;
    blendedCamSettings.boomLength *= 0.01;

    func_80030450(camera);
    temp_f20_2 = blendedCamSettings.boomYaw + D_800A08E0;
    temp_f26 = sin_deg(temp_f20_2);
    temp_f24_2 = -cos_deg(temp_f20_2);
    cosViewPitch = cos_deg(blendedCamSettings.boomPitch + D_800A08DC);
    sinViewPitch = sin_deg(blendedCamSettings.boomPitch + D_800A08DC);

    if (!(camera->moveFlags & CAMERA_MOVE_FLAGS_2)) {
        camera->lookAt_eye.y = blendedCamSettings.position.y + (blendedCamSettings.boomLength * sinViewPitch);
    }

    camera->lookAt_eye.x = blendedCamSettings.position.x - (temp_f26 * blendedCamSettings.boomLength * cosViewPitch);
    camera->lookAt_eye.z = blendedCamSettings.position.z - (temp_f24_2 * blendedCamSettings.boomLength * cosViewPitch);
    cosViewPitch = cos_deg(-blendedCamSettings.viewPitch);
    sinViewPitch = sin_deg(-blendedCamSettings.viewPitch);

    if (camera->lookAt_eye.x == blendedCamSettings.position.x && camera->lookAt_eye.z == blendedCamSettings.position.z) {
        dist = 0.0f;
    } else {
        dist = dist2D(camera->lookAt_eye.x, camera->lookAt_eye.z, blendedCamSettings.position.x, blendedCamSettings.position.z);
    }

    temp_f8_2 = blendedCamSettings.position.y - camera->lookAt_eye.y;
    if (!(camera->moveFlags & CAMERA_MOVE_FLAGS_2)) {
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
    camera->auxPos.x = camera->lookAt_obj.x;
    camera->auxPos.y = camera->lookAt_obj.y;
    camera->auxPos.z = camera->lookAt_obj.z;
    camera->currentYOffset = 0.0f;
}
