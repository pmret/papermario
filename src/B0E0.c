#include "common.h"

void func_80030210(Camera* camera, f32 arg1, f32 arg2, s32 arg3);

void update_camera_mode_unused(Camera* camera);
// Issues with zero float temp?
#ifdef NON_MATCHING
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

void func_80030450(void) {
}

s32 test_ray_zone_aabb(f32 x, f32 y, f32 z) {
    f32 hitX, hitY, hitZ;
    f32 hitDepth = 32767.0f;
    f32 nx, ny, nz;
    s32 zoneID = test_ray_zones(x, y, z, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &nx, &ny, &nz);

    if (zoneID < 0) {
        return 0;
    }

    return D_800D91D4[zoneID].unk_10;
}

INCLUDE_ASM(s32, "B0E0", update_camera_from_controller);

void update_camera_zone_interp(Camera* camera);
INCLUDE_ASM(s32, "B0E0", update_camera_zone_interp);
// void update_camera_from_controller(Camera*, CamPosSettings*, CameraControlSettings**, CamPosSettings*, CameraControlSettings**, f32, f32, f32, f32, f32, f32, s32, f32*, s32); // extern
// extern CamPosSettings blendedCamSettings;
// extern f32 D_800A08DC;
// extern f32 D_800A08E0;

// void update_camera_zone_interp(Camera* camera) {
//     f32 targetX;
//     f32 targetY;
//     f32 targetZ;
//     CameraControlSettings* zone;
//     f32 deltaX;
//     f32 deltaY;
//     f32 deltaZ;
//     f32 dist;
//     f32 sinViewPitch;
//     f32 cosViewPitch;
//     s32 cond;
//     f32 deltaBoomYaw;
//     f32 deltaBoomPitch;
//     f32 deltaViewPitch;
//     f32 deltaBoomLength;
//     f32 deltaSqs;
//     f32 theta1;
//     f32 p3;

//     f32 temp_f22_3;
//     f32 temp_f22_4;
//     f32 temp_f24;
//     f32 temp_f24_2;
//     f32 temp_f26;
//     f32 temp_f4_4;
//     f32 temp_f6;
//     f32 temp_f8;
//     f32 temp_f8_2;
//     f64 temp_f22_2;
//     s32 temp_a1;
//     s32 temp_a2;
//     CameraControlSettings* phi_a0;
//     f32 phi_f10;
//     f32 phi_f8;
//     f32 phi_f6;
//     f32 phi_f4;
//     f32 phi_f0_2;
//     f32 phi_f2_2;
//     s32 phi_s0;

//     targetX = camera->targetPos.x;
//     targetY = camera->targetPos.y;
//     targetZ = camera->targetPos.z;
//     phi_s0 = 0;
//     if (camera->unk_08 != 0) {
//         camera->currentZone = NULL;
//         camera->prevController = NULL;
//         camera->linearInterp = 0.0f;
//         camera->unk_494 = NULL;
//         camera->savedTargetY = targetY;
//         camera->unk_98 = 0;
//         camera->unk_9C = 0;
//         camera->unk_4A4 = 0.0f;
//         camera->unk_4A8 = 0.0f;
//         camera->unk_4AC = 0.0f;
//         camera->prevPrevFollowFlags = 0;
//         camera->prevFollowFlags = 0;
//         camera->panPhase = 0.0f;
//         D_800A08DC = 0.0f;
//         D_800A08E0 = 0.0f;
//         camera->interpAlpha = 1.0f;
//         camera->unk_498 = 1.0f;
//         camera->linearInterpScale = 1.0f;
//     }

//     if ((camera->moveFlags & 1)) {
//         camera->unk_498 = 0.0f;

//     } else if (camera->unk_494 != targetY) {
//         camera->unk_494 = targetY;
//         camera->unk_498 = 0.0f;
//     }

//     if (targetY < camera->unk_494 && targetY <= camera->savedTargetY) {
//         camera->unk_494 = targetY;
//         camera->unk_498 = 1.0f;
//     }
//     camera->unk_498 += (1.01 - camera->unk_498) / camera->unk_49C;
//     dist = 0.0f;
//     if (camera->unk_498 > 1.0) {
//         camera->unk_498 = 1.0f;
//     }
//     if (((u16) camera->moveFlags & 4) != 0) {
//         camera->unk_498 += 0.3;
//         if (camera->unk_498 >= 1.0) {
//             camera->unk_498 = 1.0f;
//         }
//     }
//     if (((u16) camera->moveFlags & 2) == 0) {
//         camera->savedTargetY = (camera->savedTargetY + ((camera->unk_494 - camera->savedTargetY) * camera->unk_498));
//     }
//     if ((camera->unk_506 != 0) || (camera->unk_4A4 != targetX) || (camera->unk_4A8 != targetY) || (camera->unk_4AC != targetZ) || (camera->unk_08 != 0)) {
//         phi_a0 = (CameraControlSettings* ) &camera->controllerType;
//         if ((u16) camera->followPlayer == 0) {
//             phi_a0 = test_ray_zone_aabb(targetX, targetY + 10.0f, targetZ);
//         }
//         zone = camera->currentZone;
//         cond = FALSE;
//         if ((phi_a0 != 0) && (zone != 0)) {
//             temp_a1 = phi_a0->type;
//             if (temp_a1 == zone->type) {
//                 temp_a2 = phi_a0->flag;
//                 if ((temp_a2 == zone->flag) && (phi_a0->boomLength == zone->boomLength) && (phi_a0->boomPitch == zone->boomPitch) && (phi_a0->viewPitch == zone->viewPitch)) {
//                     if (temp_a1 != 0) {
//                         if (temp_a1 != 1) {
//                             if ((phi_a0->pos[0] == zone->pos[0]) && (phi_a0->pos[2] == zone->pos[2]) && (phi_a0->pos[1] == zone->pos[1]) && (phi_a0->pos[4] == zone->pos[4]) && (phi_a0->pos[3] == zone->pos[3])) {
//                                 if (phi_a0->pos[5] == zone->pos[5]) {
//                                     cond = TRUE;
//                                 }
//                             }
//                         } else if (temp_a2 != 0) {
//                             if (temp_a2 != temp_a1) {

//                             } else if ((phi_a0->pos[0] == zone->pos[0]) && (phi_a0->pos[2] == zone->pos[2]) && (phi_a0->pos[3] == zone->pos[3])) {
//                                 if (phi_a0->pos[5] == zone->pos[5]) {
//                                     cond = TRUE;
//                                 }
//                             }
//                         } else if (phi_a0->pos[0] == zone->pos[0]) {
//                             if (phi_a0->pos[2] == zone->pos[2]) {
//                                 cond = TRUE;
//                             }
//                         }
//                     } else if ((phi_a0->pos[0] == zone->pos[0]) && (phi_a0->pos[2] == zone->pos[2]) && (phi_a0->pos[3] == zone->pos[3])) {
//                         if (phi_a0->pos[5] == zone->pos[5]) {
//                             cond = TRUE;
//                         }
//                     }
//                 }
//             }
//         }
//         if ((camera->unk_506 != 0) || (!cond && (phi_a0 != zone))) {
//             if (camera->interpAlpha == 1.0f) {
//                 camera->prevController = camera->currentZone;
//             } else {
//                 camera->prevController = (CameraControlSettings* )-1;
//             }
//             camera->oldCameraSettings.boomYaw = blendedCamSettings.boomYaw;
//             camera->oldCameraSettings.boomLength = blendedCamSettings.boomLength;
//             camera->oldCameraSettings.boomPitch = blendedCamSettings.boomPitch;
//             camera->oldCameraSettings.viewPitch = blendedCamSettings.viewPitch;
//             camera->oldCameraSettings.position.x = blendedCamSettings.position.x;
//             camera->oldCameraSettings.position.y = blendedCamSettings.position.y;
//             camera->oldCameraSettings.position.z = blendedCamSettings.position.z;
//             camera->currentZone = phi_a0;
//             camera->interpAlpha = 0.0f;
//             camera->linearInterp = 0.0f;
//             camera->unk_506 = 0;
//             camera->linearInterpScale = camera->moveSpeed;
//             camera->prevPrevFollowFlags = camera->prevFollowFlags;
//             camera->prevFollowFlags = camera->followPlayer;
//             camera->prevPrevMovePos = camera->prevMovePos;
//             camera->unk_4C0 = camera->unk_4CC;
//             camera->unk_4C4 = camera->unk_4D0;
//             camera->prevMovePos = camera->movePos.x;
//             camera->unk_4CC = camera->movePos.y;
//             camera->unk_4D0 = camera->movePos.z;
//             phi_s0 = 1;
//         }
//     }

//     phi_f10 = targetX;
//     if (camera->prevPrevFollowFlags != 0) {
//         phi_f10 = camera->prevPrevMovePos;
//         phi_f8 = camera->unk_4C0;
//         phi_f6 = camera->unk_4C4;
//     } else {
//         phi_f8 = camera->savedTargetY;
//         phi_f6 = targetZ;
//     }

//     phi_f4 = targetX;
//     if (camera->prevFollowFlags != 0) {
//         camera->savedTargetY = camera->unk_4CC;
//         phi_f4 = camera->prevMovePos;
//         phi_f0_2 = camera->savedTargetY;
//         phi_f2_2 = camera->unk_4D0;
//     } else {
//         phi_f0_2 = camera->savedTargetY;
//         phi_f2_2 = targetZ;
//     }

//     update_camera_from_controller(camera, &camera->oldCameraSettings, &camera->prevController, &camera->newCameraSettings, &camera->currentZone, phi_f10, phi_f8, phi_f6, phi_f4, phi_f0_2, phi_f2_2, (s32) camera->unk_08, &camera->interpAlpha, phi_s0);
//     if (camera->unk_08 != 0) {
//         camera->unk_08 = 0;
//         camera->oldCameraSettings.boomYaw = camera->newCameraSettings.boomYaw;
//         camera->oldCameraSettings.boomLength = camera->newCameraSettings.boomLength;
//         camera->oldCameraSettings.boomPitch = camera->newCameraSettings.boomPitch;
//         camera->oldCameraSettings.viewPitch = camera->newCameraSettings.viewPitch;
//         camera->oldCameraSettings.position.x = camera->newCameraSettings.position.x;
//         camera->oldCameraSettings.position.y = camera->newCameraSettings.position.y;
//         camera->oldCameraSettings.position.z = camera->newCameraSettings.position.z;
//         camera->interpAlpha = 1.0f;
//     }

//     if (camera->oldCameraSettings.boomYaw - camera->newCameraSettings.boomYaw > 180.0f) {
//         camera->oldCameraSettings.boomYaw = camera->oldCameraSettings.boomYaw - 360.0f;
//     }
//     if (camera->oldCameraSettings.boomYaw - camera->newCameraSettings.boomYaw < -180.0f) {
//         camera->oldCameraSettings.boomYaw = camera->oldCameraSettings.boomYaw + 360.0f;
//     }

//     deltaBoomYaw = camera->oldCameraSettings.boomYaw - camera->newCameraSettings.boomYaw;
//     if (deltaBoomYaw < 0.0f) {
//         deltaBoomYaw = -deltaBoomYaw;
//     }
//     if (deltaBoomYaw > 180.0f) {
//         deltaBoomYaw = 360.0f - deltaBoomYaw;
//     }

//     deltaBoomPitch = camera->oldCameraSettings.boomPitch - camera->newCameraSettings.boomPitch;
//     if (deltaBoomPitch < 0.0f) {
//         deltaBoomPitch = -deltaBoomPitch;
//     }
//     if (deltaBoomPitch > 180.0f) {
//         deltaBoomPitch = 360.0f - deltaBoomPitch;
//     }
//     if (deltaBoomYaw < deltaBoomPitch) {
//         deltaBoomYaw = deltaBoomPitch;
//     }

//     deltaViewPitch = camera->oldCameraSettings.viewPitch - camera->newCameraSettings.viewPitch;
//     if (deltaViewPitch < 0.0f) {
//         deltaViewPitch = -deltaViewPitch;
//     }
//     if (deltaViewPitch > 180.0f) {
//         deltaViewPitch = 360.0f - deltaViewPitch;
//     }
//     if (deltaBoomYaw < deltaViewPitch) {
//         deltaBoomYaw = deltaViewPitch;
//     }

//     deltaBoomLength = camera->oldCameraSettings.boomLength - camera->newCameraSettings.boomLength;
//     if (deltaBoomLength < 0.0f) {
//         deltaBoomLength = -deltaBoomLength;
//     }
//     if (deltaBoomYaw < deltaBoomLength) {
//         deltaBoomYaw = deltaBoomLength;
//     }

//     deltaX = camera->oldCameraSettings.position.x - camera->newCameraSettings.position.x;
//     deltaY = camera->oldCameraSettings.position.y - camera->newCameraSettings.position.y;
//     deltaZ = camera->oldCameraSettings.position.z - camera->newCameraSettings.position.z;
//     deltaSqs = SQ(deltaX) + SQ(deltaY) + SQ(deltaZ);

//     if (deltaSqs != 0.0f) {
//         deltaSqs = sqrtf(deltaSqs) * 0.2;
//     }

//     if (deltaBoomYaw < deltaSqs) {
//         deltaBoomYaw = deltaSqs;
//     }

//     if (deltaBoomYaw > 90.0f) {
//         deltaBoomYaw = 90.0f;
//     }

//     if (deltaBoomYaw < 20.0f) {
//         deltaBoomYaw = 20.0f;
//     }

//     if (deltaBoomYaw != 0.0f) {
//         camera->linearInterp += (1.0f / deltaBoomYaw) * camera->linearInterpScale;
//         if (camera->linearInterp > 1.0f) {
//             camera->linearInterp = 1.0f;
//         }
//     }

//     if (camera->interpAlpha < 1.0) {
//         p3 = camera->panPhase * PI_D;
//         temp_f24 = 2.0f / (cos_rad(p3) + 1.0f);
//         temp_f22_2 = cos_rad((camera->linearInterp * PI_D * (1.0f - camera->panPhase)) + p3);
//         camera->interpAlpha = (2.0f - ((f32) ((temp_f22_2 + ((1.0 - cos_rad(p3)) * 0.5)) * temp_f24) + 1.0f)) * 0.5001;
//     }

//     if (camera->interpAlpha >= 1.0f) {
//         camera->interpAlpha = 1.0f;
//         camera->linearInterp = 0.0f;
//     }

//     temp_f6 = camera->interpAlpha;
//     temp_f8 = 1.0f - temp_f6;
//     camera->unk_4A4 = targetX;
//     camera->unk_4A8 = targetY;
//     camera->unk_4AC = targetZ;
//     blendedCamSettings.boomYaw = (camera->oldCameraSettings.boomYaw * temp_f8) + (camera->newCameraSettings.boomYaw * temp_f6);
//     blendedCamSettings.boomLength = (camera->oldCameraSettings.boomLength * temp_f8) + (camera->newCameraSettings.boomLength * temp_f6);
//     blendedCamSettings.boomPitch = (camera->oldCameraSettings.boomPitch * temp_f8) + (camera->newCameraSettings.boomPitch * temp_f6);
//     blendedCamSettings.viewPitch = (camera->oldCameraSettings.viewPitch * temp_f8) + (camera->newCameraSettings.viewPitch * temp_f6);
//     blendedCamSettings.position.x = (camera->oldCameraSettings.position.x * temp_f8) + (camera->newCameraSettings.position.x * temp_f6);
//     blendedCamSettings.position.y = (camera->oldCameraSettings.position.y * temp_f8) + (camera->newCameraSettings.position.y * temp_f6);
//     blendedCamSettings.position.z = (camera->oldCameraSettings.position.z * temp_f8) + (camera->newCameraSettings.position.z * temp_f6);
//     blendedCamSettings.boomLength = (blendedCamSettings.boomLength * camera->zoomPercent) * 0.01;
//     func_80030450();
//     theta1 = blendedCamSettings.boomYaw + D_800A08E0;
//     temp_f26 = sin_deg(theta1);
//     temp_f24_2 = -cos_deg(theta1);
//     temp_f22_4 = sin_deg(blendedCamSettings.boomPitch + D_800A08DC);
//     temp_f22_3 = cos_deg(blendedCamSettings.boomPitch + D_800A08DC);

//     if (!(camera->moveFlags & 2)) {
//         camera->lookAt_eye.y = blendedCamSettings.position.y + (blendedCamSettings.boomLength * temp_f22_4);
//     }
//     camera->lookAt_eye.x = blendedCamSettings.position.x - (temp_f26 * blendedCamSettings.boomLength * temp_f22_3);
//     camera->lookAt_eye.z = blendedCamSettings.position.z - (temp_f24_2 * blendedCamSettings.boomLength * temp_f22_3);

//     cosViewPitch = cos_deg(-blendedCamSettings.viewPitch);
//     sinViewPitch = sin_deg(-blendedCamSettings.viewPitch);

//     if ((camera->lookAt_eye.x == blendedCamSettings.position.x) && (camera->lookAt_eye.z == blendedCamSettings.position.z)) {

//     } else {
//         dist = dist2D(camera->lookAt_eye.x, camera->lookAt_eye.z, blendedCamSettings.position.x, blendedCamSettings.position.z);
//     }

//     temp_f8_2 = blendedCamSettings.position.y - camera->lookAt_eye.y;
//     if (!(camera->moveFlags & 2)) {
//         camera->lookAt_obj.y = camera->lookAt_eye.y + ((dist * sinViewPitch) + (temp_f8_2 * cosViewPitch));
//     }

//     temp_f4_4 = (dist * cosViewPitch) - (temp_f8_2 * sinViewPitch);
//     camera->lookAt_obj.x = camera->lookAt_eye.x + (temp_f26 * temp_f4_4);
//     camera->lookAt_obj.z = camera->lookAt_eye.z + (temp_f24_2 * temp_f4_4);
//     camera->currentYaw = blendedCamSettings.boomYaw + D_800A08E0;
//     camera->trueRotation.x = camera->currentYaw;
//     camera->currentBlendedYawNegated = -blendedCamSettings.boomYaw;
//     camera->currentBoomLength = blendedCamSettings.boomLength;
//     camera->unk_54 = camera->lookAt_obj.x;
//     camera->unk_58 = camera->lookAt_obj.y;
//     camera->unk_5C = camera->lookAt_obj.z;
//     camera->currentPitch = -blendedCamSettings.boomPitch - blendedCamSettings.viewPitch;
//     camera->currentYOffset = 0.0f;
// }
