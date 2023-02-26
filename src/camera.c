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

s32 calculate_segment_intersection(f32 x1, f32 z1, f32 x2, f32 z2, f32 x3, f32 z3, f32 x4, f32 z4, f32* interX, f32* interZ, f32* squared_dist) {
    f32 dx14;
    f32 dx13;
    f32 dz;
    f32 dz12;
    f32 dx34;
    f32 dx12;
    f32 dx;
    f32 alpha;
    f32 minus_dz12;
    f32 p4_side;
    f32 x;
    f32 p3_side;
    f32 z;
    f32 dx12_copy;
    f32 dz13;
    f32 dz14;
    f32 dz34;
    f32 p3_side_;

    dx12_copy = x2 - x1;
    dx12 = dx12_copy;
    dz12 = z2 - z1;
    dx13 = x3 - x1;
    dz13 = z3 - z1;
    dx14 = x4 - x1;
    dz14 = z4 - z1;
    minus_dz12 = -dz12;
    dx34 = x4 - x3;
    dz34 = z4 - z3;

    // if distance between points on the line is 0
    if (dx12_copy == 0.0f && dz12 == 0.0f) {
        return FALSE;
    }
    // if length of second segment is 0
    if (dx34 == 0.0f && dz34 == 0.0f) {
        return FALSE;
    }

    p3_side_ = minus_dz12 * dx13 + dx12_copy * dz13;
    if (p3_side_ < 0.0f) {
        p3_side = -1.0f;
    } else if (p3_side_ > 0.0f) {
        p3_side = 1.0f;
    } else {
        p3_side = 0.0f;
    }
    p3_side_ = p3_side;

    dx = minus_dz12 * dx14 + dx12_copy * dz14;
    if (dx < 0.0f) {
        p4_side = -1.0f;
    } else if (dx > 0.0f) {
        p4_side = 1.0f;
    } else {
        p4_side = 0.0f;
    }

    // P3 and P4 are on the same side relative to the line: no intersection
    if (p3_side_ == p4_side) {
        return FALSE;
    }

    if (fabsf(dx12) > fabsf(dx34)) {
        /*
        We represent intersection point P as P = P3 + alpha * (P4 - P3)
        and solve the equation (P - P1) x (P2 - P1) = 0, where 'x' is cross product, P1 and P2 are points on the line
        and P3 and P4 are the ends of the segment.
        So, (P3 - P1 + alpha * (P4 - P3)) x (P2 - P1) = 0,
        alpha = [-(P3 - P1) x (P2 - P1)] / [(P4 - P3) x (P2 - P1)]
        */
        // same as -(P3 - P1) x (P2 - P1)
        alpha = x1 * dz12 - z1 * dx12 + dx12 * z3 - dz12 * x3;
        // divide by (P4 - P3) x (P2 - P1)
        alpha /= dz12 * dx34 - dx12 * dz34;
        /*
            Now we represent P as P = P1 + beta * (P2 - P1), and we are to find beta.
            P3 + alpha * (P4 - P3) = P1 + beta * (P2 - P1)
            beta * (P2 - P1) = P3 + alpha * (P4 - P3) - P1
            We use only 'x' part of this equation to find beta.

            Actually this step could be omitted and we calculate intersection directly as P3 + alpha * (P4 - P3).
            Don't know why it's done this way.
        */
        alpha = (x3 + dx34 * alpha - x1) / dx12;
        x = x1 + dx12 * alpha;
        z = z1 + dz12 * alpha;
    } else {
        /*
        We represent intersection point P as P = P1 + alpha * (P2 - P1)
        and solve the equation (P4 - P3) x (P - P3) = 0
        */
        // same as (P4 - P3) x (P3 - P1)
        alpha = z3 * dx34 + x1 * dz34 - z3 * dz34 - z1 * dx34;
        // divide by (P4 - P3) x (P2 - P1)
        alpha /= dz12 * dx34 - dx12 * dz34;
        // Now we represent P as P = P3 + beta * (P4 - P3) and find beta
        alpha = (x1 + dx12 * alpha - x3) / dx34;
        x = x3 + dx34 * alpha;
        z = z3 + dz34 * alpha;
    }
    // (P - P1) * (P - P2) > 0 when P is outside of segment P1-P2
    if ((x - x1) * (x - x2) + (z - z1) * (z - z2) > 0.0f) {
        return FALSE;
    }

    dx = x - x3;
    dz = z - z3;
    *interX = x;
    *interZ = z;
    // distance between P and P3
    *squared_dist = SQ(dx) + SQ(dz);
    return TRUE;
}

s32 calculate_line_segment_intersection(f32 x1, f32 z1, f32 x2, f32 z2, f32 x3, f32 z3, f32 x4, f32 z4, f32* interX, f32* interZ, f32* squared_dist) {
    f32 dx14;
    f32 dx13;
    f32 dz;
    f32 dz12;
    f32 dx34;
    f32 dx12;
    f32 dx;
    f32 alpha;
    f32 minus_dz12;
    f32 p4_side;
    f32 x;
    f32 p3_side;
    f32 z;
    f32 dx12_copy;
    f32 dz13;
    f32 dz14;
    f32 dz34;
    f32 p3_side_;

    dx12_copy = x2 - x1;
    dx12 = dx12_copy;
    dz12 = z2 - z1;
    dx13 = x3 - x1;
    dz13 = z3 - z1;
    dx14 = x4 - x1;
    dz14 = z4 - z1;
    minus_dz12 = -dz12;
    dx34 = x4 - x3;
    dz34 = z4 - z3;

    if (dx12_copy == 0.0f && dz12 == 0.0f) {
        return FALSE;
    }
    if (dx34 == 0.0f && dz34 == 0.0f) {
        return FALSE;
    }

    p3_side_ = minus_dz12 * dx13 + dx12_copy * dz13;
    if (p3_side_ < 0.0f) {
        p3_side = -1.0f;
    } else if (p3_side_ > 0.0f) {
        p3_side = 1.0f;
    } else {
        p3_side = 0.0f;
    }
    p3_side_ = p3_side;

    dx = minus_dz12 * dx14 + dx12_copy * dz14;
    if (dx < 0.0f) {
        p4_side = -1.0f;
    } else if (dx > 0.0f) {
        p4_side = 1.0f;
    } else {
        p4_side = 0.0f;
    }

    if (p3_side_ == p4_side) {
        return FALSE;
    }

    if (fabsf(dx12) > fabsf(dx34)) {
        alpha = x1 * dz12 - z1 * dx12 + dx12 * z3 - dz12 * x3;
        alpha /= dz12 * dx34 - dx12 * dz34;
        alpha = (x3 + dx34 * alpha - x1) / dx12;
        x = x1 + dx12 * alpha;
        z = z1 + dz12 * alpha;
    } else {
        alpha = z3 * dx34 + x1 * dz34 - z3 * dz34 - z1 * dx34;
        alpha /= dz12 * dx34 - dx12 * dz34;
        alpha = (x1 + dx12 * alpha - x3) / dx34;
        x = x3 + dx34 * alpha;
        z = z3 + dz34 * alpha;
    }

    dx = x - x3;
    dz = z - z3;
    *interX = x;
    *interZ = z;
    *squared_dist = SQ(dx) + SQ(dz);
    return TRUE;
}


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
    s32 flags = camera->flags & CAMERA_FLAG_1000;
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
        if (gPlayerStatusPtr->animFlags & PA_FLAG_RIDING_PARTNER) {
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
    f32 X, Y, Z, W;
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
                                1.0f, &X, &Y, &Z, &W);
                if (W == 0.0f) {
                    W = 1.0f;
                }
                W = 1.0f / W;
                X *= W;
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

                if (calculate_line_segment_intersection(settings2->posA.x, settings2->posA.z, settings2->posA.x - deltaPosZ, settings2->posA.z + deltaPosX,
                                  camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &sp44, &sp48, &sp4C) && sp4C < 1000000.0f) {
                    dist = sp4C;
                }
                do {
                    if (calculate_line_segment_intersection(settings2->posB.x, settings2->posB.z, settings2->posB.x - deltaPosZ, settings2->posB.z + deltaPosX,
                                  camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &sp44, &sp48, &sp4C) && sp4C < dist) {
                        dist = sp4C;
                    }
                } while (0); // TODO find better match
            }
            if (cond) {
                for (i = 0; i < zone->numTriangles; i++) {
                    if (calculate_segment_intersection(zone->triangleTable[i].v1->x, zone->triangleTable[i].v1->z,
                                      zone->triangleTable[i].v2->x, zone->triangleTable[i].v2->z,
                                      camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &sp44, &sp48, &sp4C) && sp4C < dist) {
                        dist = sp4C;
                    }
                    if (calculate_segment_intersection(zone->triangleTable[i].v2->x, zone->triangleTable[i].v2->z,
                                      zone->triangleTable[i].v3->x, zone->triangleTable[i].v3->z,
                                      camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &sp44, &sp48, &sp4C) && sp4C < dist) {
                        dist = sp4C;
                    }
                    if (calculate_segment_intersection(zone->triangleTable[i].v3->x, zone->triangleTable[i].v3->z,
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
