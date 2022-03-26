#include "common.h"

s32 gCurrentCameraID = CAM_DEFAULT;

CameraControlSettings* test_ray_zone(f32 posX, f32 posY, f32 posZ, Collider** zone) {
    f32 hitX, hitY, hitZ, hitDepth, nX, nY, nZ;
    s32 zoneID;

    hitDepth = 32767;
    zoneID = test_ray_zones(posX, posY, posZ, 0, -1, 0, &hitX, &hitY, &hitZ, &hitDepth, &nX, &nY, &nZ);
    if (zoneID >= 0) {
        if (zone) {
            *zone = &gZoneCollisionData.colliderList[zoneID];
        }
        return gZoneCollisionData.colliderList[zoneID].camSettings;
    } else {
        return NULL;
    }
}

s32 func_800322DC(f32, f32, f32, f32, f32, f32, f32, f32, f32*, f32*, f32*);
INCLUDE_ASM(s32, "camera", func_800322DC);

s32 func_800325E4(f32, f32, f32, f32, f32, f32, f32, f32, f32*, f32*, f32*);
INCLUDE_ASM(s32, "camera", func_800325E4);
/*
s32 func_800325E4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32* arg8, f32* arg9, f32* argA) {
    f32 sp0, sp8;

    f32 f0, f2, f6, f8, f10, f12, f14, f16, f18, f30;
    f32 f0_2, f2_2, f4_2, f6_2, f8_2, f10_2, f12_2;
    f32 f0_3, f2_3, f4_3, f6_3;
    f32 f0_4, f2_4, f6_4;
    f32 f0_5, f2_5, f6_5;
    f32 f0_6, f2_6, f6_6;
    f32 f0_7, f2_7, f6_7;
    f32 f0_8, f2_8, f6_8;
    f32 f0_9, f2_9;
    f32 f0_10, f2_10;
    f32 f0_11;
    f32 f0_12;
    f32 f0_13;
    f32 f0_14;
    f32 v1, v2;

    f18 = arg2 - arg0;
    f12 = arg3 - arg1;
    f8 = -f12;
    sp0 = arg6 - arg0;
    sp8 = arg4 - arg0;
    f10 = f18;

    f14 = arg7 - arg5;
    f16 = arg6 - arg4;
    f30 = arg7 - arg1;
    f6 = arg5 - arg1;

    if (f18 == 0 && f12 == 0) {
        return 0;
    }

    if (f16 == 0 && f14 == 0) {
        return 0;
    }

    v1 = f8 * sp8 + f10 * f6;
    if (v1 < 0) {
        f4_2 = -1.0f;
    } else if (v1 > 0) {
        f4_2 = 1.0f;
    } else {
        f4_2 = 0;
    }

    f6_3 = f4_2;
    v2 = f8 * sp0 + f10 * f30;
    if (v2 < 0) {
        f0_4 = -1.0f;
    } else if (v2 > 0) {
        f0_4 = 1.0f;
    } else {
        f0_4 = 0;
    }

    if (f6_3 == f0_4) {
        return 0;
    }

    if (fabsf(f18) > fabsf(f16)) {
        f0_6 = arg0 * f12;
        f6_4 = arg1 * f18;
        f8_2 = f18 * arg5;
        f10_2 = f12 * arg4;
        f2_6 = f12 * f16;
        f4_3 = f18 * f14;

        f0_7 = f0_6 - f6_4;
        f2_7 = f2_6 - f4_3;
        f0_8 = f0_7 + f8_2;
        f6_5 = f0_8 - f10_2;
        f6_5 = f6_5 / f2_7;
        f0_9 = f16 * f6_5;
        f0_10 = arg4 + f0_9;
        f0_11 = f0_10 - arg0;
        f6_5 = f0_11 / f18;
        f0_12 = f18 * f6_5;
        f2_8 = f12 * f6_5;
        f12_2 = arg0 + f0_12;
        f6_8 = arg1 + f2_8;
    } else {
        f32 f0_6z, f6_4z, f8_2z, f10_2z, f2_6z, f4_3z, f0_7z, f2_7z, f0_8z, f6_5z, f6_6z, f0_9z, f0_10z, f0_11z, f6_7z, f0_12z, f2_8z;
        f0_6z = arg5 * f16;
        f6_4z = arg0 * f14;
        f8_2z = arg5 * f14;
        f10_2z = arg1 * f16;
        f2_6z = f12 * f16;
        f4_3z = f18 * f14;

        f0_7z = f0_6z + f6_4z;
        f2_7z = f2_6z - f4_3z;
        f0_8z = f0_7z - f8_2z;
        f6_5z = f0_8z - f10_2z;
        f6_5z = f6_5z / f2_7z;
        f0_9z = f18 * f6_5z;
        f0_10z = arg0 + f0_9z;
        f0_11z = f0_10z - arg4;
        f6_5z = f0_11z / f16;
        f0_12z = f16 * f6_5z;
        f2_8z = f14 * f6_5z;
        f12_2 = arg4 + f0_12z;
        f6_8 = arg5 + f2_8z;
    }

    f2_9 = f12_2 - arg4;
    //f2_10 = f2_9 * f2_9;
    f0_13 = f6_8 - arg5;
    //f0_14 = f0_13 * f0_13;

    *arg8 = f12_2;
    *arg9 = f6_8;
    *argA = SQ(f2_9) + SQ(f0_13);
    return 1;
}
*/

s32 func_800328A4(CameraControlSettings* camSettings, f32 arg1, f32 arg2) {
    f32 temp1, temp2;
    f32 d, p1, p2, p3, p4;

    if (!camSettings) {
        return 0;
    }
    if (camSettings->type != 6) {
        return 0;
    }
    d = arg1 - camSettings->posA.x;
    p1 = (camSettings->posB.x - camSettings->posA.x) * d;

    d = arg2 - camSettings->posA.z;
    p2 = (camSettings->posB.z - camSettings->posA.z) * d;

    d = arg1 - camSettings->posB.x;
    p3 = (camSettings->posB.x - camSettings->posA.x) * d;

    d = arg2 - camSettings->posB.z;
    p4 = (camSettings->posB.z - camSettings->posA.z) * d;

    temp1 = p1 + p2;
    temp2 = p3 + p4;


    if (temp1 < 0 && temp2 < 0) {
        return -1;
    }
    if (temp1 > 0 && temp2 > 0) {
        return 1;
    }
    return 0;
}

void func_80032970(Camera* camera, f32 arg1) {
    f32 stickX;
    f32 f4;
    f32 deltaLeadAmount;
    s32 flags = camera->flags & 0x1000;
    s32 a2 = flags != 0;

    if (camera->currentController && camera->currentController->type == 4) {
        a2 = TRUE;
    }

    if (a2) {
        stickX = 0;
        camera->unk_51C = 1;
        camera->unk_514 = 1;
        camera->unk_510 = 0;
    } else {
        if (gPlayerStatusPtr->animFlags & PLAYER_STATUS_ANIM_FLAGS_400000) {
            stickX = gPartnerActionStatus.stickX;
        } else {
            stickX = gPlayerStatusPtr->stickAxis[0];
        }
        if (stickX > 0) {
            stickX = 50;
        }
        if (stickX < 0) {
            stickX = -50;
        }
    }

    if (stickX != 0) {
        if (stickX < 0) {
            if (camera->unk_518 > 0) {
                camera->unk_518 = stickX;
            } else {
                camera->unk_518 += stickX;
            }
            if (camera->unk_518 <= -300) {
                camera->unk_51C = 1;
                if (camera->unk_510 > 0) {
                    camera->unk_514 = 0;
                }
                camera->unk_510 = -arg1;
                camera->unk_518 = -300;
            }
        } else {
            if (camera->unk_518 < 0) {
                camera->unk_518 = stickX;
            } else {
                camera->unk_518 += stickX;
            }
            if (camera->unk_518 >= 300) {
                camera->unk_51C = 1;
                if (camera->unk_510 < 0) {
                    camera->unk_514 = 0;
                }
                camera->unk_510 = arg1;
                camera->unk_518 = 300;
            }
        }
    }

    if (camera->unk_51C != 0) {
        camera->unk_514 += 0.01f;
        if (camera->unk_514 > 1) {
            camera->unk_514 = 1;
        }
    }

    if (camera->unk_510 - camera->leadAmount == 0) {
        camera->unk_514 = 0;
        camera->unk_51C = 0;
    }

    deltaLeadAmount = (camera->unk_510 - camera->leadAmount) * camera->unk_514;
    if (camera->unk_510 - camera->leadAmount > 0) {
        if (camera->unk_510 - camera->leadAmount < 0.1) {
            deltaLeadAmount = camera->unk_510 - camera->leadAmount;
        }
        if (deltaLeadAmount > 3.0f) {
            deltaLeadAmount = 3.0f;
        }
    } else {
        if (camera->unk_510 - camera->leadAmount > -0.1) {
            deltaLeadAmount = camera->unk_510 - camera->leadAmount;
        }
        if (deltaLeadAmount < -3.0f) {
            deltaLeadAmount = -3.0f;
        }
    }

    if (stickX != 0 || a2) {
        camera->leadAmount += deltaLeadAmount;
    } else {
        camera->unk_514 = 0;
    }
}

void func_80032C64(Camera* camera) {
    s32 i;
    f32 arg0;
    f32 arg1;
    CameraControlSettings* settings;
    CameraControlSettings* settings2;
    CameraControlSettings* settings3;
    s32 s2;
    f32 X, Y, Z, S;
    f32 arg5, arg4;
    f32 product;
    f32 newX, newZ;
    Collider* zone;
    s32 s22;
    f32 dist;
    f32 sp44, sp48, sp4C;
    f32 t1, t2;
    f32 f22_, f24_;

    arg0 = camera->trueRotation.x / 180 * PI;
    arg1 = camera->leadAmount;
    s2 = 0;
    cos_rad(arg0);
    sin_rad(arg0);
    settings3 = settings = test_ray_zone(camera->targetPos.x, camera->targetPos.y + 10.0f, camera->targetPos.z, NULL);

    if (settings) {
        if (settings->type == 2 || settings->type == 5 || (s2 = func_800328A4(settings, camera->targetPos.x, camera->targetPos.z))) {
            if (camera->unk_530) {
                guPerspectiveF(camera->perspectiveMatrix, &camera->perspNorm, camera->vfov,
                               (f32)camera->viewportW / (f32)camera->viewportH, camera->nearClip, camera->farClip, 1.0f);
                guMtxCatF(camera->viewMtxPlayer, camera->perspectiveMatrix, camera->perspectiveMatrix);
                transform_point(camera->perspectiveMatrix, camera->targetPos.x, camera->targetPos.y, camera->targetPos.z,
                                1.0f, &X, &Y, &Z, &S);
                if (S == 0.0f) {
                    S = 1.0f;
                }
                S = 1 / S;
                X *= S;
                camera->unk_52C = (X > 0) ? 1 : (X < 0) ? -1 : 0;
                camera->unk_530 = 0;
            } else {
                if (camera->aabbForZoneBelow) {
                    if (camera->aabbForZoneBelow->type != 2 &&
                        camera->aabbForZoneBelow->type != 5 &&
                        func_800328A4(settings, camera->unk_524, camera->unk_528) == 0) {
                        if (s2) {
                            camera->unk_52C = s2;
                        } else {
                            goto block_17;
                        }
                    }
                } else {
block_17:
                    arg5 = t1 = camera->targetPos.x - camera->unk_524; // needed to match
                    arg4 = camera->targetPos.z - camera->unk_528;
                    t1 = -cos_deg(camera->currentYaw);
                    t2 = -sin_deg(camera->currentYaw);
                    product = arg5 * t1 + arg4 * t2;
                    camera->unk_52C = (product > 0) ? -1 : (product < 0) ? 1 : 0;
                }
            }

            if (arg1 > 0 && camera->unk_52C > 0 || arg1 < 0 && camera->unk_52C < 0) {
                camera->unk_514 = 0;
                camera->leadAmount = 0;
            }
            camera->aabbForZoneBelow = settings3;
            camera->unk_524 = camera->targetPos.x;
            camera->unk_528 = camera->targetPos.z;
            return;
        }
    }

    camera->unk_52C = 0;
    camera->aabbForZoneBelow = settings3;
    camera->unk_524 = camera->targetPos.x;
    camera->unk_528 = camera->targetPos.z;
    newX = camera->targetPos.x + arg1 * cos_rad(arg0);
    newZ = camera->targetPos.z + arg1 * sin_rad(arg0);
    settings = test_ray_zone(newX, camera->targetPos.y + 10.0f, newZ, &zone);
    if (settings) {
        if (settings->type == 2 || settings->type == 5 || func_800328A4(camera->aabbForZoneBelow, newX, newZ)) {

            s22 = TRUE;
            dist = 1000000.0f;
            if (camera->aabbForZoneBelow && camera->aabbForZoneBelow->type == 6) {
                settings2 = camera->aabbForZoneBelow;
                s22 = FALSE;

                f22_ = settings2->posB.x - settings2->posA.x;
                f24_ = settings2->posB.z - settings2->posA.z;

                if (func_800325E4(settings2->posA.x, settings2->posA.z, settings2->posA.x - f24_, settings2->posA.z + f22_,
                                  camera->targetPos.x, camera->targetPos.z, newX, newZ, &sp44, &sp48, &sp4C) && sp4C < 1000000.0f) {
                    dist = sp4C;
                }
                do { if (func_800325E4(settings2->posB.x, settings2->posB.z, settings2->posB.x - f24_, settings2->posB.z + f22_,
                                  camera->targetPos.x, camera->targetPos.z, newX, newZ, &sp44, &sp48, &sp4C) && sp4C < dist) {
                    dist = sp4C;
                } } while (0);
            }
            if (s22) {
                for (i = 0; i < zone->numTriangles; i++) {
                    if (func_800322DC(zone->triangleTable[i].v1->x, zone->triangleTable[i].v1->z,
                                      zone->triangleTable[i].v2->x, zone->triangleTable[i].v2->z,
                                      camera->targetPos.x, camera->targetPos.z, newX, newZ, &sp44, &sp48, &sp4C) && sp4C < dist) {
                        dist = sp4C;
                    }
                    if (func_800322DC(zone->triangleTable[i].v2->x, zone->triangleTable[i].v2->z,
                                      zone->triangleTable[i].v3->x, zone->triangleTable[i].v3->z,
                                      camera->targetPos.x, camera->targetPos.z, newX, newZ, &sp44, &sp48, &sp4C) && sp4C < dist) {
                        dist = sp4C;
                    }
                    if (func_800322DC(zone->triangleTable[i].v3->x, zone->triangleTable[i].v3->z,
                                      zone->triangleTable[i].v1->x, zone->triangleTable[i].v1->z,
                                      camera->targetPos.x, camera->targetPos.z, newX, newZ, &sp44, &sp48, &sp4C) && sp4C < dist) {
                        dist = sp4C;
                    }
                }
            }

            if (dist == 1000000 || dist == 0) {
                camera->leadAmount = 0;
            } else {
                camera->leadAmount = (camera->leadAmount > 0) ? sqrtf(dist) : -sqrtf(dist);
            }
            camera->unk_514 = 0;
            return;
        }
    }
}


void create_camera_leadplayer_matrix(Camera* camera) {
    f32 xTemp = camera->lookAt_eye.x - camera->lookAt_obj.x;
    f32 yTemp = camera->lookAt_eye.y - camera->lookAt_obj.y;
    f32 zTemp = camera->lookAt_eye.z - camera->lookAt_obj.z;
    f32 dist = sqrtf(SQ(xTemp) + SQ(yTemp) + SQ(zTemp));
    f32 theta = ((camera->vfov * 0.5f) / 180.0f) * PI;
    f32 distSinTheta = dist * sin_rad(theta);

    func_80032970(camera, (((distSinTheta / cos_rad(theta)) * camera->viewportW) / camera->viewportH) * camera->unk_520);
    func_80032C64(camera);
    guTranslateF(camera->viewMtxLeading, -camera->leadAmount, 0.0f, 0.0f);
}

void func_800334E8(void) {
}
