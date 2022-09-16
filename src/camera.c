#include "common.h"
#include "camera.h"

s32 gCurrentCameraID = CAM_DEFAULT;

CameraControlSettings* test_ray_zone(f32 posX, f32 posY, f32 posZ, Collider** zone) {
    f32 hitX, hitY, hitZ, hitDepth, nX, nY, nZ;
    s32 zoneID;

    hitDepth = 32767.0f;
    zoneID = test_ray_zones(posX, posY, posZ, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &nX, &nY, &nZ);
    if (zoneID >= 0) {
        if (zone != NULL) {
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

s32 func_800328A4(CameraControlSettings* camSettings, f32 x, f32 z) {
    f32 product1, product2;
    f32 delta, p1, p2, p3, p4;

    if (camSettings == NULL) {
        return 0;
    }
    if (camSettings->type != CAMERA_SETTINGS_TYPE_6) {
        return 0;
    }
    delta = x - camSettings->posA.x;
    p1 = (camSettings->posB.x - camSettings->posA.x) * delta;

    delta = z - camSettings->posA.z;
    p2 = (camSettings->posB.z - camSettings->posA.z) * delta;

    delta = x - camSettings->posB.x;
    p3 = (camSettings->posB.x - camSettings->posA.x) * delta;

    delta = z - camSettings->posB.z;
    p4 = (camSettings->posB.z - camSettings->posA.z) * delta;

    product1 = p1 + p2;
    product2 = p3 + p4;


    if (product1 < 0 && product2 < 0) {
        return -1;
    }
    if (product1 > 0 && product2 > 0) {
        return 1;
    }
    return 0;
}

void func_80032970(Camera* camera, f32 arg1) {
    f32 stickX;
    f32 deltaLeadAmount;
    s32 flags = camera->flags & CAM_FLAG_1000;
    s32 a2 = flags != 0;

    if (camera->currentController != NULL && camera->currentController->type == CAMERA_SETTINGS_TYPE_4) {
        a2 = TRUE;
    }

    if (a2) {
        stickX = 0.0f;
        camera->unk_51C = TRUE;
        camera->unk_514 = 1.0f;
        camera->unk_510 = 0.0f;
    } else {
        if (gPlayerStatusPtr->animFlags & PA_FLAGS_400000) {
            stickX = gPartnerActionStatus.stickX;
        } else {
            stickX = gPlayerStatusPtr->stickAxis[0];
        }
        if (stickX > 0.0f) {
            stickX = 50.0f;
        }
        if (stickX < 0.0f) {
            stickX = -50.0f;
        }
    }

    if (stickX != 0.0f) {
        if (stickX < 0.0f) {
            if (camera->unk_518 > 0.0f) {
                camera->unk_518 = stickX;
            } else {
                camera->unk_518 += stickX;
            }
            if (camera->unk_518 <= -300.0f) {
                camera->unk_51C = TRUE;
                if (camera->unk_510 > 0.0f) {
                    camera->unk_514 = 0.0f;
                }
                camera->unk_510 = -arg1;
                camera->unk_518 = -300.0f;
            }
        } else {
            if (camera->unk_518 < 0.0f) {
                camera->unk_518 = stickX;
            } else {
                camera->unk_518 += stickX;
            }
            if (camera->unk_518 >= 300.0f) {
                camera->unk_51C = TRUE;
                if (camera->unk_510 < 0.0f) {
                    camera->unk_514 = 0.0f;
                }
                camera->unk_510 = arg1;
                camera->unk_518 = 300.0f;
            }
        }
    }

    if (camera->unk_51C) {
        camera->unk_514 += 0.01f;
        if (camera->unk_514 > 1.0f) {
            camera->unk_514 = 1.0f;
        }
    }

    if (camera->unk_510 - camera->leadAmount == 0.0f) {
        camera->unk_514 = 0.0f;
        camera->unk_51C = FALSE;
    }

    deltaLeadAmount = (camera->unk_510 - camera->leadAmount) * camera->unk_514;
    if (camera->unk_510 - camera->leadAmount > 0.0f) {
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

    if (stickX != 0.0f || a2) {
        camera->leadAmount += deltaLeadAmount;
    } else {
        camera->unk_514 = 0.0f;
    }
}

void func_80032C64(Camera* camera) {
    s32 i;
    f32 rotationRad;
    f32 leadAmount;
    CameraControlSettings* settings;
    CameraControlSettings* settings2;
    CameraControlSettings* settings3;
    s32 s2;
    f32 X, Y, Z, S;
    f32 product;
    f32 newPosX, newPosZ;
    Collider* zone;
    s32 cond;
    f32 dist;
    f32 sp44, sp48, sp4C;
    f32 deltaPosX, deltaPosZ;
    f32 f24, f22, cosYaw, sinYaw;

    rotationRad = camera->trueRotation.x / 180.0f * PI;
    leadAmount = camera->leadAmount;
    s2 = 0;
    cos_rad(rotationRad);
    sin_rad(rotationRad);
    settings3 = settings = test_ray_zone(camera->targetPos.x, camera->targetPos.y + 10.0f, camera->targetPos.z, NULL);

    if (settings != NULL) {
        if (settings->type == CAMERA_SETTINGS_TYPE_2 || settings->type == CAMERA_SETTINGS_TYPE_5 || (s2 = func_800328A4(settings, camera->targetPos.x, camera->targetPos.z))) {
            if (camera->unk_530) {
                guPerspectiveF(camera->perspectiveMatrix, &camera->perspNorm, camera->vfov,
                               (f32)camera->viewportW / (f32)camera->viewportH, camera->nearClip, camera->farClip, 1.0f);
                guMtxCatF(camera->viewMtxPlayer, camera->perspectiveMatrix, camera->perspectiveMatrix);
                transform_point(camera->perspectiveMatrix, camera->targetPos.x, camera->targetPos.y, camera->targetPos.z,
                                1.0f, &X, &Y, &Z, &S);
                if (S == 0.0f) {
                    S = 1.0f;
                }
                S = 1.0f / S;
                X *= S;
                camera->unk_52C = (X > 0.0f) ? 1 : (X < 0.0f) ? -1 : 0;
                camera->unk_530 = 0;
            } else {
                CameraControlSettings* aabbForZoneBelow = camera->aabbForZoneBelow;

                if (!(aabbForZoneBelow != NULL && (aabbForZoneBelow->type == CAMERA_SETTINGS_TYPE_2 || aabbForZoneBelow->type == CAMERA_SETTINGS_TYPE_5 || func_800328A4(settings, camera->unk_524, camera->unk_528) != 0))) {
                    if (aabbForZoneBelow != NULL && s2 != 0) {
                        camera->unk_52C = s2;
                    } else {
                        f24 = cosYaw = camera->targetPos.x - camera->unk_524;
                        f22 = camera->targetPos.z - camera->unk_528;
                        cosYaw = -cos_deg(camera->currentYaw);
                        sinYaw = -sin_deg(camera->currentYaw);
                        product = f24 * cosYaw + f22 * sinYaw;
                        camera->unk_52C = (product > 0) ? -1 : (product < 0) ? 1 : 0;
                    }
                }
            }

            if (leadAmount > 0.0f && camera->unk_52C > 0 || leadAmount < 0.0f && camera->unk_52C < 0) {
                camera->unk_514 = 0.0f;
                camera->leadAmount = 0.0f;
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
    newPosX = camera->targetPos.x + leadAmount * cos_rad(rotationRad);
    newPosZ = camera->targetPos.z + leadAmount * sin_rad(rotationRad);
    settings = test_ray_zone(newPosX, camera->targetPos.y + 10.0f, newPosZ, &zone);
    if (settings != NULL) {
        if (settings->type == CAMERA_SETTINGS_TYPE_2 || settings->type == CAMERA_SETTINGS_TYPE_5 || func_800328A4(camera->aabbForZoneBelow, newPosX, newPosZ) != 0) {
            cond = TRUE;
            dist = 1000000.0f;
            if (camera->aabbForZoneBelow != NULL && camera->aabbForZoneBelow->type == CAMERA_SETTINGS_TYPE_6) {
                settings2 = camera->aabbForZoneBelow;
                cond = FALSE;

                deltaPosX = settings2->posB.x - settings2->posA.x;
                deltaPosZ = settings2->posB.z - settings2->posA.z;

                if (func_800325E4(settings2->posA.x, settings2->posA.z, settings2->posA.x - deltaPosZ, settings2->posA.z + deltaPosX,
                                  camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &sp44, &sp48, &sp4C) && sp4C < 1000000.0f) {
                    dist = sp4C;
                }
                do {
                    if (func_800325E4(settings2->posB.x, settings2->posB.z, settings2->posB.x - deltaPosZ, settings2->posB.z + deltaPosX,
                                  camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &sp44, &sp48, &sp4C) && sp4C < dist) {
                        dist = sp4C;
                    }
                } while (0); // TODO find better match
            }
            if (cond) {
                for (i = 0; i < zone->numTriangles; i++) {
                    if (func_800322DC(zone->triangleTable[i].v1->x, zone->triangleTable[i].v1->z,
                                      zone->triangleTable[i].v2->x, zone->triangleTable[i].v2->z,
                                      camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &sp44, &sp48, &sp4C) && sp4C < dist) {
                        dist = sp4C;
                    }
                    if (func_800322DC(zone->triangleTable[i].v2->x, zone->triangleTable[i].v2->z,
                                      zone->triangleTable[i].v3->x, zone->triangleTable[i].v3->z,
                                      camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &sp44, &sp48, &sp4C) && sp4C < dist) {
                        dist = sp4C;
                    }
                    if (func_800322DC(zone->triangleTable[i].v3->x, zone->triangleTable[i].v3->z,
                                      zone->triangleTable[i].v1->x, zone->triangleTable[i].v1->z,
                                      camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &sp44, &sp48, &sp4C) && sp4C < dist) {
                        dist = sp4C;
                    }
                }
            }

            if (dist == 1000000.0f || dist == 0) {
                camera->leadAmount = 0.0f;
            } else {
                camera->leadAmount = (camera->leadAmount > 0.0f) ? sqrtf(dist) : -sqrtf(dist);
            }
            camera->unk_514 = 0.0f;
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
