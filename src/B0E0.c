#include "common.h"

extern CamPosSettings blendedCamSettings;
extern f32 D_800A08DC;
extern f32 D_800A08E0;

void func_80030210(Camera* camera, f32 arg1, f32 arg2, s32 arg3);


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

        theta = (camera->currentBoomYaw * TAU) / 360.0f;
        sinTheta1 = sin_rad(theta);
        cosTheta1 = cos_rad(theta);
        temp_f30 = (cosTheta1 * 0.0f) + (camera->currentBoomLength * sinTheta1);
        temp_f24_2 = (sinTheta1 * -0.0f) + (camera->currentBoomLength * cosTheta1);

        theta = (camera->trueRotation.x * TAU) / 360.0f;
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

        camera->unk_54 = camera->targetPos.x + camera->unk_550;
        camera->unk_58 = camera->targetPos.y + camera->currentYOffset;
        camera->unk_5C = camera->targetPos.z;
        func_8003034C(camera);
        if (!(camera->moveFlags & 1)) {
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
    f32 xDelta = (camera->unk_54 - camera->lookAt_obj.x) * arg1;
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
    theta = (camera->currentBoomYaw * TAU) / 360.0f;

    cosTheta = cos_rad(theta);
    camera->lookAt_obj.z += (camera->unk_5C - camera->lookAt_obj.z) * arg1;
    camera->lookAt_eye.z = camera->lookAt_obj.z + (camera->currentBoomLength * cosTheta);

    if (arg3 << 16 == 0) {
        sinTheta = sin_rad(theta);
        camera->lookAt_obj.y += (camera->unk_58 - camera->lookAt_obj.y) * 0.125f;
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

    return D_800D91D4[zoneID].unk_10;
}

void update_camera_from_controller(Camera*, CamPosSettings*, CameraControlSettings**, CamPosSettings*, CameraControlSettings**, f32, f32, f32, f32, f32, f32, s32, f32*, s32); // extern
INCLUDE_ASM(s32, "B0E0", update_camera_from_controller);

void update_camera_zone_interp(Camera* camera);
// Mostly issues with the switch
#ifdef NON_EQUIVALENT
void update_camera_zone_interp(Camera* camera) {
    CameraControlSettings* cs;
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
    f32 temp_f22;
    f32 temp_f22_3;
    f32 temp_f22_4;
    f32 cosNegViewPitch;
    f32 sinNegViewPitch;
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

    if (camera->moveFlags & 1) {
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

    if (camera->moveFlags & 4) {
        camera->unk_498 += 0.3;
        if (camera->unk_498 >= 1.0) {
            camera->unk_498 = 1.0f;
        }
    }

    if (!(camera->moveFlags & 2)) {
        camera->savedTargetY += (camera->unk_494 - camera->savedTargetY) * camera->unk_498;
    }

    if (camera->unk_506 != 0 || camera->unk_4A4 != targetX || camera->unk_4A8 != targetY ||
        camera->unk_4AC != targetZ || camera->changingMap) {

        if (camera->followPlayer) {
            cs = &camera->controlSettings;
        } else {
            cs = test_ray_zone_aabb(targetX, targetY + 10.0f, targetZ);
        }

        cond2 = FALSE;

        if (cs != NULL && camera->currentController != NULL && cs->type == camera->currentController->type &&
            cs->flag == camera->currentController->flag && cs->boomLength == camera->currentController->boomLength &&
            cs->boomPitch == camera->currentController->boomPitch &&
            cs->viewPitch == camera->currentController->viewPitch) {

            switch (cs->type) {
                case 0:
                    if (cs->posA.x == camera->currentController->posA.x &&
                        cs->posA.z == camera->currentController->posA.z &&
                        cs->posB.x == camera->currentController->posB.x &&
                        cs->posB.z == camera->currentController->posB.z) {

                        cond2 = TRUE;
                    }
                    break;
                case 1:
                    if (!cs->flag) {
                        if (cs->posA.x == camera->currentController->posA.x &&
                            cs->posA.z == camera->currentController->posA.z) {

                            cond2 = TRUE;
                        }
                    } else {
                        if (cs->posA.x == camera->currentController->posA.x &&
                            cs->posA.z == camera->currentController->posA.z &&
                            cs->posB.x == camera->currentController->posB.x &&
                            cs->posB.z == camera->currentController->posB.z) {

                            cond2 = TRUE;
                        }
                    }
                    break;
                default:
                    if (cs->posA.x == camera->currentController->posA.x &&
                        cs->posA.z == camera->currentController->posA.z &&
                        cs->posA.y == camera->currentController->posA.y &&
                        cs->posB.y == camera->currentController->posB.y &&
                        cs->posB.x == camera->currentController->posB.x &&
                        cs->posB.z == camera->currentController->posB.z) {

                        cond2 = TRUE;
                    }
                    break;
            }
        }

        if (camera->unk_506 != 0 || (!cond2 && cs != camera->currentController)) {
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

    posX = targetX;
    if (camera->prevPrevFollowFlags) {
        posX = camera->prevPrevMovePos.x;
        posY = camera->prevPrevMovePos.y;
        posZ = camera->prevPrevMovePos.z;
    } else {
        posY = camera->savedTargetY;
        posZ = targetZ;
    }

    tX = targetX;
    if (camera->prevFollowFlags) {
        camera->savedTargetY = camera->prevMovePos.y;
        tX = camera->prevMovePos.x;
        tY = camera->savedTargetY;
        tZ = camera->prevMovePos.z;
    } else {
        tY = camera->savedTargetY;
        tZ = targetZ;
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

    boomYawDiff = camera->oldCameraSettings.boomYaw - camera->newCameraSettings.boomYaw;
    if (boomYawDiff < 0.0f) {
        boomYawDiff = -boomYawDiff;
    }
    if (boomYawDiff > 180.0f) {
        boomYawDiff = 360.0f - boomYawDiff;
    }

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
    deltaSqSum = SQ(deltaX) + SQ(deltaY) + SQ(deltaZ);

    if (deltaSqSum != 0.0f) {
        deltaSqSum = sqrtf(deltaSqSum) * 0.2;
    }

    if (boomYawDiff < deltaSqSum) {
        boomYawDiff = deltaSqSum;
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
        temp_f22 = panPhase * PI_D;
        temp_f24 = 2.0f / (cos_rad(temp_f22) + 1.0f);
        temp_f22_2 = cos_rad((camera->linearInterp * PI_D * (1.0f - panPhase)) + temp_f22);
        camera->interpAlpha = (2.0f - ((f32) ((temp_f22_2 + ((1.0 - cos_rad(temp_f22)) * 0.5)) * temp_f24) + 1.0f)) * 0.5001;
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
    temp_f22_3 = cos_deg(blendedCamSettings.boomPitch + D_800A08DC);
    temp_f22_4 = sin_deg(blendedCamSettings.boomPitch + D_800A08DC);

    if (!(camera->moveFlags & 2)) {
        camera->lookAt_eye.y = blendedCamSettings.position.y + (blendedCamSettings.boomLength * temp_f22_4);
    }

    camera->lookAt_eye.x = blendedCamSettings.position.x - (temp_f26 * blendedCamSettings.boomLength * temp_f22_3);
    camera->lookAt_eye.z = blendedCamSettings.position.z - (temp_f24_2 * blendedCamSettings.boomLength * temp_f22_3);
    cosNegViewPitch = cos_deg(-blendedCamSettings.viewPitch);
    sinNegViewPitch = sin_deg(-blendedCamSettings.viewPitch);

    if (camera->lookAt_eye.x == blendedCamSettings.position.x && camera->lookAt_eye.z == blendedCamSettings.position.z) {
        dist = 0.0f;
    } else {
        dist = dist2D(camera->lookAt_eye.x, camera->lookAt_eye.z, blendedCamSettings.position.x, blendedCamSettings.position.z);
    }

    temp_f8_2 = blendedCamSettings.position.y - camera->lookAt_eye.y;
    if (!(camera->moveFlags & 2)) {
        camera->lookAt_obj.y = camera->lookAt_eye.y + ((dist * sinNegViewPitch) + (temp_f8_2 * cosNegViewPitch));
    }
    temp_f4_4 = (dist * cosNegViewPitch) - (temp_f8_2 * sinNegViewPitch);
    camera->lookAt_obj.x = camera->lookAt_eye.x + (temp_f26 * temp_f4_4);
    camera->lookAt_obj.z = camera->lookAt_eye.z + (temp_f24_2 * temp_f4_4);
    camera->currentYaw = blendedCamSettings.boomYaw + D_800A08E0;
    camera->trueRotation.x = camera->currentYaw;
    camera->currentBoomLength = blendedCamSettings.boomLength;
    camera->currentBlendedYawNegated = -blendedCamSettings.boomYaw;
    camera->currentPitch = -blendedCamSettings.boomPitch - blendedCamSettings.viewPitch;
    camera->unk_54 = camera->lookAt_obj.x;
    camera->unk_58 = camera->lookAt_obj.y;
    camera->unk_5C = camera->lookAt_obj.z;
    camera->currentYOffset = 0.0f;
}
#else
INCLUDE_ASM(s32, "B0E0", update_camera_zone_interp);
#endif
