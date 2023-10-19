#include "common.h"

SHIFT_BSS CamConfiguration gCurrentCamConfiguration;
SHIFT_BSS f32 D_800A08DC;
SHIFT_BSS f32 D_800A08E0;
SHIFT_BSS f32 D_800A08E4;
SHIFT_BSS f32 D_800A08E8;
SHIFT_BSS f32 D_800A08EC;

void cam_interp_lookat_pos(Camera* camera, f32 arg1, f32 arg2, s16 arg3);
void func_8003034C(Camera* camera);

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

enum CameraSettingsPtrType {
    CAMERA_SETTINGS_PTR_MINUS_2     = -2,
    CAMERA_SETTINGS_PTR_MINUS_1     = -1,
    CAMERA_SETTINGS_PTR_NULL        = 0,
};

void update_camera_from_controller(
    Camera* camera,
    CamConfiguration* oldConfiguration, CameraControlSettings** prevController,
    CamConfiguration* newConfiguration, CameraControlSettings** newController,
    f32 x1, f32 y1, f32 z1,
    f32 tX, f32 tY, f32 tZ, s32 changingMap,
    f32* interpAlpha, s32 changingZone)
{
    CameraControlSettings* prevSettings;
    CameraControlSettings* controller;
    CamConfiguration* configuration;

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

    f32 x, y, z;

    configuration = oldConfiguration;
    controller = *prevController;
    x = x1;
    y = y1;
    z = z1;

    if ((s32)controller != CAMERA_SETTINGS_PTR_MINUS_2 && (s32)controller != CAMERA_SETTINGS_PTR_MINUS_1) {
        if (controller == CAMERA_SETTINGS_PTR_NULL) {
            configuration->targetPos.x = x;
            configuration->targetPos.y = y;
            configuration->targetPos.z = z;
        } else {
            switch (controller->type) {
                case CAM_CONTROL_FIXED_ORIENTATION:
                    if (controller->flag != 0) {
                        f32 temp_f10 = -(controller->points.two.Az - controller->points.two.Bz) + controller->points.two.Bx;
                        f32 temp_f6 = (controller->points.two.Ax - controller->points.two.Bx) + controller->points.two.Bz;

                        f32 temp_f8 = controller->points.two.Bx - temp_f10;
                        f32 temp_f12_2 = controller->points.two.Bz - temp_f6;

                        f32 temp_f4 = (SQ(temp_f8) + SQ(temp_f12_2));
                        temp_f4 = (((x - temp_f10) * temp_f8) + ((z - temp_f6) * temp_f12_2)) / temp_f4;

                        configuration->targetPos.x = temp_f4 * temp_f8 + temp_f10;
                        configuration->targetPos.y = y;
                        configuration->targetPos.z = temp_f4 * temp_f12_2 + temp_f6;
                    } else {
                        configuration->targetPos.x = x;
                        configuration->targetPos.y = y;
                        configuration->targetPos.z = z;
                    }
                    break;
                case CAM_CONTROL_CONSTAIN_BETWEEN_POINTS:
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
                        configuration->targetPos.x = var_f16;
                        configuration->targetPos.y = y;
                        configuration->targetPos.z = var_f10;
                    }
                    break;
                case CAM_CONTROL_LOOK_AT_POINT:
                    if (controller->flag != 0) {
                        dx = x - controller->points.two.Ax;
                        dz = z - controller->points.two.Az;
                        f24 = SQ(dx) + SQ(dz);
                        if (f24 != 0.0f) {
                            f24 = 1.0f / sqrtf(f24);
                            temp_f2 = sqrtf(SQ(controller->points.two.Bx - controller->points.two.Ax) + SQ(controller->points.two.Bz - controller->points.two.Az));
                            temp_f2_2 = dx * temp_f2 * f24;
                            temp_f4_4 = dz * temp_f2 * f24;
                            configuration->targetPos.x = controller->points.two.Ax + temp_f2_2;
                            configuration->targetPos.y = y;
                            configuration->targetPos.z = controller->points.two.Az + temp_f4_4;
                        }
                    } else {
                        configuration->targetPos.x = x;
                        configuration->targetPos.y = y;
                        configuration->targetPos.z = z;
                    }
                    break;
                case CAM_CONTROL_CONSTRAIN_TO_LINE:
                case CAM_CONTROL_LOOK_AT_POINT_CONSTAIN_TO_LINE:
                    *prevController = (CameraControlSettings*) CAMERA_SETTINGS_PTR_MINUS_1;
                    break;
                case CAM_CONTROL_FOLLOW_PLAYER:
                    configuration->targetPos.x = x;
                    configuration->targetPos.y = y;
                    configuration->targetPos.z = z;
                    break;
                case CAM_CONTROL_FIXED_POS_AND_ORIENTATION:
                    break;
            }
        }
    }

    configuration = newConfiguration;
    controller = *newController;
    x = tX;
    y = tY;
    z = tZ;

    if (controller == NULL) {
        configuration->targetPos.x = x;
        configuration->targetPos.y = y;
        configuration->targetPos.z = z;
    } else {
        switch (controller->type) {
            case CAM_CONTROL_FIXED_ORIENTATION:
                dx = controller->points.two.Bx - controller->points.two.Ax;
                dz = controller->points.two.Bz - controller->points.two.Az;
                configuration->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                boomLength = controller->boomLength;
                if (boomLength < 0.0f) {
                    boomLength = -boomLength;
                }
                configuration->boomLength = boomLength;
                configuration->boomPitch = controller->boomPitch;
                configuration->viewPitch = controller->viewPitch;
                if (controller->flag) {
                    f32 ABx = controller->points.two.Ax - controller->points.two.Bx;
                    f32 ABz = controller->points.two.Az - controller->points.two.Bz;
                    f32 temp_f10 = -ABz + controller->points.two.Bx;
                    f32 temp_f6 = ABx + controller->points.two.Bz;

                    f32 temp_f8 = controller->points.two.Bx - temp_f10;
                    f32 temp_f12_2 = controller->points.two.Bz - temp_f6;

                    f32 temp_f4 = SQ(temp_f8) + SQ(temp_f12_2);
                    temp_f4 = (((x - temp_f10) * temp_f8) + ((z - temp_f6) * temp_f12_2)) / temp_f4;

                    configuration->targetPos.x = temp_f4 * temp_f8 + temp_f10;
                    configuration->targetPos.y = y;
                    configuration->targetPos.z = temp_f4 * temp_f12_2 + temp_f6;
                } else {
                    configuration->targetPos.x = x;
                    configuration->targetPos.y = y;
                    configuration->targetPos.z = z;
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
            case CAM_CONTROL_CONSTAIN_BETWEEN_POINTS:
                dx = controller->points.two.Bx - controller->points.two.Ax;
                dz = controller->points.two.Bz - controller->points.two.Az;
                configuration->boomYaw = atan2(0.0f, 0.0f, dz, -dx);
                boomLength = controller->boomLength;
                if (boomLength < 0.0f) {
                    boomLength = -boomLength;
                }
                configuration->boomLength = boomLength;
                configuration->boomPitch = controller->boomPitch;
                configuration->viewPitch = controller->viewPitch;
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
                    configuration->targetPos.x = var_f16;
                    configuration->targetPos.y = y;
                    configuration->targetPos.z = var_f10;
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
            case CAM_CONTROL_LOOK_AT_POINT:
                if (controller->boomLength < 0.0f) {
                    // negative boom length means look *away* from point
                    dx = x - controller->points.two.Ax;
                    dz = z - controller->points.two.Az;
                    configuration->boomLength = -controller->boomLength;
                } else {
                    dx = controller->points.two.Ax - x;
                    dz = controller->points.two.Az - z;
                    configuration->boomLength = controller->boomLength;
                }
                configuration->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                configuration->boomPitch = controller->boomPitch;
                configuration->viewPitch = controller->viewPitch;
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
                        configuration->targetPos.x = controller->points.two.Ax + temp_f2_4;
                        configuration->targetPos.y = y;
                        configuration->targetPos.z = controller->points.two.Az + temp_f4_9;
                    }
                } else {
                    configuration->targetPos.x = x;
                    configuration->targetPos.y = y;
                    configuration->targetPos.z = z;
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
            case CAM_CONTROL_CONSTRAIN_TO_LINE:
                if (controller->flag == 0) {
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
                    configuration->targetPos.x = Tx;
                    configuration->targetPos.y = y;
                    configuration->targetPos.z = Tz;

                    if (changingMap) {
                        dx = controller->points.two.Bx - controller->points.two.Ax;
                        dz = controller->points.two.Bz - controller->points.two.Az;
                        configuration->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                        boomLength = controller->boomLength;
                        if (boomLength < 0.0f) {
                            boomLength = -boomLength;
                        }
                        configuration->boomLength = boomLength;
                        configuration->boomPitch = controller->boomPitch;
                        configuration->viewPitch = controller->viewPitch;
                    }
                } else {
                    if (changingMap) {
                        dx = controller->points.two.Bx - controller->points.two.Ax;
                        dz = controller->points.two.Bz - controller->points.two.Az;
                        configuration->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                        boomLength = controller->boomLength;
                        if (boomLength < 0.0f) {
                            boomLength = -boomLength;
                        }
                        configuration->boomLength = boomLength;
                        configuration->boomPitch = controller->boomPitch;
                        configuration->viewPitch = controller->viewPitch;
                        configuration->targetPos.x = controller->points.two.Bx;
                        configuration->targetPos.z = controller->points.two.Bz;
                    } else if (changingZone) {
                        configuration->targetPos.x = oldConfiguration->targetPos.x;
                        configuration->targetPos.z = oldConfiguration->targetPos.z;
                    }
                    configuration->targetPos.y = y;
                }
                *prevController = (CameraControlSettings*) CAMERA_SETTINGS_PTR_MINUS_1;
                break;
            case CAM_CONTROL_LOOK_AT_POINT_CONSTAIN_TO_LINE:
                if (controller->flag == 0) {
                    f32 var3 = x - controller->points.three.Cx;
                    f32 var4 = z - controller->points.three.Cz;
                    f32 var1 = controller->points.three.Bx - controller->points.three.Cx;
                    f32 var2 = controller->points.three.Bz - controller->points.three.Cz;
                    temp_f4_13 = SQ(var1) + SQ(var2);
                    temp_f4_13 = (var3 * var1 + var4 * var2) / temp_f4_13;
                    temp_f2_7 = temp_f4_13 * var1 + controller->points.three.Cx;
                    temp_f4_14 = temp_f4_13 * var2 + controller->points.three.Cz;

                    configuration->targetPos.x = temp_f2_7;
                    configuration->targetPos.y = y;
                    configuration->targetPos.z = temp_f4_14;

                    if (controller->boomLength < 0.0f) {
                        dx = temp_f2_7 - controller->points.three.Ax;
                        dz = temp_f4_14 - controller->points.three.Az;
                        configuration->boomLength = -controller->boomLength;
                    } else {
                        dx = controller->points.three.Ax - temp_f2_7;
                        dz = controller->points.three.Az - temp_f4_14;
                        configuration->boomLength = controller->boomLength;
                    }
                    configuration->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                    configuration->boomPitch = controller->boomPitch;
                    configuration->viewPitch = controller->viewPitch;
                } else {
                    if (changingMap) {
                        if (controller->boomLength < 0.0f) {
                            dx = controller->points.three.Bx - controller->points.three.Ax;
                            dz = controller->points.three.Bz - controller->points.three.Az;
                            configuration->boomLength = -controller->boomLength;
                        } else {
                            dx = controller->points.three.Ax - controller->points.three.Bx;
                            dz = controller->points.three.Az - controller->points.three.Bz;
                            configuration->boomLength = controller->boomLength;
                        }
                        configuration->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                        configuration->boomPitch = controller->boomPitch;
                        configuration->viewPitch = controller->viewPitch;
                        configuration->targetPos.x = controller->points.three.Bx;
                        configuration->targetPos.z = controller->points.three.Bz;
                    } else if (changingZone) {
                        configuration->targetPos.x = controller->points.three.Bx;
                        configuration->targetPos.z = controller->points.three.Bz;
                    }
                    configuration->targetPos.y = y;
                }
                *prevController = (CameraControlSettings*) CAMERA_SETTINGS_PTR_MINUS_1;
                break;
            case CAM_CONTROL_FOLLOW_PLAYER:
                configuration->targetPos.x = x;
                configuration->targetPos.y = y;
                configuration->targetPos.z = z;
                break;
            case CAM_CONTROL_FIXED_POS_AND_ORIENTATION:
                do {
                dx = controller->points.two.Bx - controller->points.two.Ax;
                dz = controller->points.two.Bz - controller->points.two.Az;

                configuration->boomYaw = atan2(0.0f, 0.0f, dx, dz);
                } while (0);
                boomLength = controller->boomLength;
                if (boomLength < 0.0f) {
                    boomLength = -boomLength;
                }
                configuration->boomLength = boomLength;
                configuration->boomPitch = controller->boomPitch;
                configuration->viewPitch = controller->viewPitch;
                configuration->targetPos.x = controller->points.two.Bx;
                configuration->targetPos.y = controller->points.two.By;
                configuration->targetPos.z = controller->points.two.Bz;
                *prevController = (CameraControlSettings*) CAMERA_SETTINGS_PTR_MINUS_2;
                break;
        }

        if (changingZone
            && ((controller->type == CAM_CONTROL_LOOK_AT_POINT_CONSTAIN_TO_LINE) || (oldConfiguration->boomYaw != newConfiguration->boomYaw))
            && (fabsf(oldConfiguration->boomYaw - newConfiguration->boomYaw) < 3.0f)
            && (fabsf(oldConfiguration->boomLength - newConfiguration->boomLength) < 10.0f)
            && (fabsf(oldConfiguration->boomPitch - newConfiguration->boomPitch) < 1.0f)
            && (fabsf(oldConfiguration->viewPitch - newConfiguration->viewPitch) < 1.0f)
            && (fabsf(oldConfiguration->targetPos.x - newConfiguration->targetPos.x) < 10.0f)
            && (fabsf(oldConfiguration->targetPos.y - newConfiguration->targetPos.y) < 10.0f)
            && (fabsf(oldConfiguration->targetPos.z - newConfiguration->targetPos.z) < 10.0f)
        ) {
            *interpAlpha = 1.0f;
        }
    }

    if (*prevController == (CameraControlSettings*) CAMERA_SETTINGS_PTR_MINUS_1) {
        if (changingZone) {
            D_800A08E4 = oldConfiguration->targetPos.x - newConfiguration->targetPos.x;
            D_800A08E8 = oldConfiguration->targetPos.y - newConfiguration->targetPos.y;
            D_800A08EC = oldConfiguration->targetPos.z - newConfiguration->targetPos.z;
        }
        oldConfiguration->targetPos.x = newConfiguration->targetPos.x + D_800A08E4;
        oldConfiguration->targetPos.y = newConfiguration->targetPos.y + D_800A08E8;
        oldConfiguration->targetPos.z = newConfiguration->targetPos.z + D_800A08EC;
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
    f32 maxDelta;
    f32 delta;
    f32 deltaSqSum;
    f32 panPhase;
    f32 temp_f20_2;
    f32 panRad;
    f32 cosAngle;
    f32 sinAngle;
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
        camera->curController = NULL;
        camera->prevController = NULL;
        camera->linearInterp = 0.0f;
        camera->yinterpGoal = 0.0f;
        camera->yinterpCur = targetY;
        camera->unk_98 = 0;
        camera->unk_9C = 0;
        camera->prevTargetPos.x = 0.0f;
        camera->prevTargetPos.y = 0.0f;
        camera->prevTargetPos.z = 0.0f;
        camera->prevPrevFollowPlayer = FALSE;
        camera->prevFollowPlayer = FALSE;
        camera->panPhase = 0.0f;
        D_800A08DC = 0.0f;
        D_800A08E0 = 0.0f;
        camera->interpAlpha = 1.0f;
        camera->yinterpAlpha = 1.0f;
        camera->linearInterpScale = 1.0f;
    }
    tempX = targetX;
    if (camera->moveFlags & CAMERA_MOVE_IGNORE_PLAYER_Y) {
        camera->yinterpAlpha = 0.0f;
    } else if (camera->yinterpGoal != targetY) {
        camera->yinterpGoal = targetY;
        camera->yinterpAlpha = 0.0f;
    }

    // always follow player moving down with no interp
    if (targetY < camera->yinterpGoal && targetY <= camera->yinterpCur) {
        camera->yinterpGoal = targetY;
        camera->yinterpAlpha = 1.0f;
    }

    camera->yinterpAlpha += (1.01 - camera->yinterpAlpha) / camera->yinterpRate;

    if (camera->yinterpAlpha > 1.0) {
        camera->yinterpAlpha = 1.0f;
    }

    if (camera->moveFlags & CAMERA_MOVE_ACCEL_INTERP_Y) {
        camera->yinterpAlpha += 0.3;
        if (camera->yinterpAlpha >= 1.0) {
            camera->yinterpAlpha = 1.0f;
        }
    }

    if (!(camera->moveFlags & CAMERA_MOVE_NO_INTERP_Y)) {
        camera->yinterpCur += (camera->yinterpGoal - camera->yinterpCur) * camera->yinterpAlpha;
    }

    tempZ = targetZ;
    if (camera->panActive
        || camera->prevTargetPos.x != targetX
        || camera->prevTargetPos.y != targetY
        || camera->prevTargetPos.z != targetZ
        || camera->isChangingMap
    ) {

        if (camera->followPlayer) {
            cs = &camera->controlSettings;
        } else {
            cs = test_ray_zone_aabb(targetX, targetY + 10.0f, targetZ);
        }

        cond2 = FALSE;
        cs2 = cs;
        currentController = camera->curController;
        if (cs != NULL
            && currentController != NULL
            && cs->type == currentController->type
            && cs->flag == currentController->flag
            && cs->boomLength == currentController->boomLength
            && cs->boomPitch == currentController->boomPitch
            && cs->viewPitch == currentController->viewPitch
        ) {
            switch (cs->type) {
                case CAM_CONTROL_FIXED_ORIENTATION:
                    if (cs->points.two.Ax == currentController->points.two.Ax
                        && cs->points.two.Az == currentController->points.two.Az
                        && cs->points.two.Bx == currentController->points.two.Bx
                        && cs->points.two.Bz == currentController->points.two.Bz
                    ) {
                        cond2 = TRUE;
                    }
                    break;
                case CAM_CONTROL_LOOK_AT_POINT:
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
                camera->prevController = camera->curController;
            } else {
                camera->prevController = (CameraControlSettings*) CAMERA_SETTINGS_PTR_MINUS_1;
            }
            changingZone = TRUE;
            camera->prevConfiguration = gCurrentCamConfiguration;
            camera->curController = cs;
            camera->interpAlpha = 0.0f;
            camera->linearInterp = 0.0f;
            camera->panActive = FALSE;
            camera->linearInterpScale = camera->moveSpeed;
            camera->prevPrevFollowPlayer = camera->prevFollowPlayer;
            camera->prevFollowPlayer = camera->followPlayer;
            camera->prevPrevMovePos.x = camera->prevMovePos.x;
            camera->prevPrevMovePos.y = camera->prevMovePos.y;
            camera->prevPrevMovePos.z = camera->prevMovePos.z;
            camera->prevMovePos.x = camera->movePos.x;
            camera->prevMovePos.y = camera->movePos.y;
            camera->prevMovePos.z = camera->movePos.z;
        }
    }

    if (camera->prevPrevFollowPlayer) {
        posX = camera->prevPrevMovePos.x;
        posY = camera->prevPrevMovePos.y;
        posZ = camera->prevPrevMovePos.z;
    } else {
        posX = tempX;
        posY = camera->yinterpCur;
        posZ = tempZ;
    }

    if (camera->prevFollowPlayer) {
        camera->yinterpCur = camera->prevMovePos.y;
        tX = camera->prevMovePos.x;
        tY = camera->yinterpCur;
        tZ = camera->prevMovePos.z;
    } else {
        tX = tempX;
        tY = camera->yinterpCur;
        tZ = tempZ;
    }

    update_camera_from_controller(camera, &camera->prevConfiguration, &camera->prevController,
                                  &camera->goalConfiguration, &camera->curController, posX, posY, posZ, tX, tY, tZ,
                                  camera->isChangingMap, &camera->interpAlpha, changingZone);

    if (camera->isChangingMap) {
        camera->prevConfiguration = camera->goalConfiguration;
        camera->isChangingMap = FALSE;
        camera->interpAlpha = 1.0f;
    }

    if (camera->prevConfiguration.boomYaw - camera->goalConfiguration.boomYaw > 180.0f) {
        camera->prevConfiguration.boomYaw -= 360.0f;
    }
    if (camera->prevConfiguration.boomYaw - camera->goalConfiguration.boomYaw < -180.0f) {
        camera->prevConfiguration.boomYaw += 360.0f;
    }

    delta = camera->prevConfiguration.boomYaw - camera->goalConfiguration.boomYaw;
    if (delta < 0.0f) {
        delta = -delta;
    }
    if (delta > 180.0f) {
        delta = 360.0f - delta;
    }
    maxDelta = delta;

    delta = camera->prevConfiguration.boomPitch - camera->goalConfiguration.boomPitch;
    if (delta < 0.0f) {
        delta = -delta;
    }
    if (delta > 180.0f) {
        delta = 360.0f - delta;
    }
    if (maxDelta < delta) {
        maxDelta = delta;
    }

    delta = camera->prevConfiguration.viewPitch - camera->goalConfiguration.viewPitch;
    if (delta < 0.0f) {
        delta = -delta;
    }
    if (delta > 180.0f) {
        delta = 360.0f - delta;
    }
    if (maxDelta < delta) {
        maxDelta = delta;
    }

    delta = camera->prevConfiguration.boomLength - camera->goalConfiguration.boomLength;
    if (delta < 0.0f) {
        delta = -delta;
    }
    if (maxDelta < delta) {
        maxDelta = delta;
    }

    deltaX = camera->prevConfiguration.targetPos.x - camera->goalConfiguration.targetPos.x;
    deltaY = camera->prevConfiguration.targetPos.y - camera->goalConfiguration.targetPos.y;
    deltaZ = camera->prevConfiguration.targetPos.z - camera->goalConfiguration.targetPos.z;
    delta = SQ(deltaX);
    delta += SQ(deltaY);
    delta += SQ(deltaZ);

    if (delta != 0.0f) {
        delta = sqrtf(delta) * 0.2;
    }

    if (maxDelta < delta) {
        maxDelta = delta;
        delta++;
        delta--;
    }
    if (maxDelta > 90.0f) {
        maxDelta = 90.0f;
    }
    if (maxDelta < 20.0f) {
        maxDelta = 20.0f;
    }

    if (maxDelta != 0.0f) {
        camera->linearInterp += (1.0f / maxDelta) * camera->linearInterpScale;
        if (camera->linearInterp > 1.0f) {
            camera->linearInterp = 1.0f;
        }
    }

    if (camera->interpAlpha < 1.0) {
        panPhase = camera->panPhase;
        panRad = panPhase * PI_D;
        temp_f24 = 2.0f / (cos_rad(panRad) + 1.0f);
        temp_f22_2 = cos_rad((camera->linearInterp * PI_D * (1.0f - panPhase)) + panRad);
        cosAngle = (temp_f22_2 + (1.0 - cos_rad(panRad)) * 0.5) * temp_f24;
        cosAngle = (2.0f - (cosAngle + 1.0f)) * 0.5001;
        camera->interpAlpha = cosAngle;
    }

    if (camera->interpAlpha >= 1.0f) {
        camera->interpAlpha = 1.0f;
        camera->linearInterp = 0.0f;
    }

    camera->prevTargetPos.x = targetX;
    camera->prevTargetPos.y = targetY;
    camera->prevTargetPos.z = targetZ;

    interpAlpha = camera->interpAlpha;
    interpAlphaInv = 1.0f - interpAlpha;
    gCurrentCamConfiguration.boomYaw = (camera->prevConfiguration.boomYaw * interpAlphaInv) + (camera->goalConfiguration.boomYaw * interpAlpha);
    gCurrentCamConfiguration.boomLength = (camera->prevConfiguration.boomLength * interpAlphaInv) + (camera->goalConfiguration.boomLength * interpAlpha);
    gCurrentCamConfiguration.boomPitch = (camera->prevConfiguration.boomPitch * interpAlphaInv) + (camera->goalConfiguration.boomPitch * interpAlpha);
    gCurrentCamConfiguration.viewPitch = (camera->prevConfiguration.viewPitch * interpAlphaInv) + (camera->goalConfiguration.viewPitch * interpAlpha);
    gCurrentCamConfiguration.targetPos.x = (camera->prevConfiguration.targetPos.x * interpAlphaInv) + (camera->goalConfiguration.targetPos.x * interpAlpha);
    gCurrentCamConfiguration.targetPos.y = (camera->prevConfiguration.targetPos.y * interpAlphaInv) + (camera->goalConfiguration.targetPos.y * interpAlpha);
    gCurrentCamConfiguration.targetPos.z = (camera->prevConfiguration.targetPos.z * interpAlphaInv) + (camera->goalConfiguration.targetPos.z * interpAlpha);
    gCurrentCamConfiguration.boomLength *= camera->zoomPercent;
    gCurrentCamConfiguration.boomLength *= 0.01;

    func_80030450(camera);
    temp_f20_2 = gCurrentCamConfiguration.boomYaw + D_800A08E0;
    temp_f26 = sin_deg(temp_f20_2);
    temp_f24_2 = -cos_deg(temp_f20_2);
    cosAngle = cos_deg(gCurrentCamConfiguration.boomPitch + D_800A08DC);
    sinAngle = sin_deg(gCurrentCamConfiguration.boomPitch + D_800A08DC);

    if (!(camera->moveFlags & CAMERA_MOVE_NO_INTERP_Y)) {
        camera->lookAt_eye.y = gCurrentCamConfiguration.targetPos.y + (gCurrentCamConfiguration.boomLength * sinAngle);
    }

    camera->lookAt_eye.x = gCurrentCamConfiguration.targetPos.x - (temp_f26 * gCurrentCamConfiguration.boomLength * cosAngle);
    camera->lookAt_eye.z = gCurrentCamConfiguration.targetPos.z - (temp_f24_2 * gCurrentCamConfiguration.boomLength * cosAngle);
    cosAngle = cos_deg(-gCurrentCamConfiguration.viewPitch);
    sinAngle = sin_deg(-gCurrentCamConfiguration.viewPitch);

    if (camera->lookAt_eye.x == gCurrentCamConfiguration.targetPos.x && camera->lookAt_eye.z == gCurrentCamConfiguration.targetPos.z) {
        dist = 0.0f;
    } else {
        dist = dist2D(camera->lookAt_eye.x, camera->lookAt_eye.z, gCurrentCamConfiguration.targetPos.x, gCurrentCamConfiguration.targetPos.z);
    }

    temp_f8_2 = gCurrentCamConfiguration.targetPos.y - camera->lookAt_eye.y;
    if (!(camera->moveFlags & CAMERA_MOVE_NO_INTERP_Y)) {
        camera->lookAt_obj.y = camera->lookAt_eye.y + ((dist * sinAngle) + (temp_f8_2 * cosAngle));
    }
    temp_f4_4 = (dist * cosAngle) - (temp_f8_2 * sinAngle);
    camera->lookAt_obj.x = camera->lookAt_eye.x + (temp_f26 * temp_f4_4);
    camera->lookAt_obj.z = camera->lookAt_eye.z + (temp_f24_2 * temp_f4_4);
    camera->curYaw = gCurrentCamConfiguration.boomYaw + D_800A08E0;
    camera->trueRot.x = camera->curYaw;
    camera->curBoomLength = gCurrentCamConfiguration.boomLength;
    camera->curBlendedYawNegated = -gCurrentCamConfiguration.boomYaw;
    camera->curPitch = -gCurrentCamConfiguration.boomPitch - gCurrentCamConfiguration.viewPitch;
    camera->lookAt_obj_target.x = camera->lookAt_obj.x;
    camera->lookAt_obj_target.y = camera->lookAt_obj.y;
    camera->lookAt_obj_target.z = camera->lookAt_obj.z;
    camera->curYOffset = 0.0f;
}
