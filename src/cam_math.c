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

s32 calculate_segment_intersection(f32 A1x, f32 A1z, f32 A2x, f32 A2z, f32 B1x, f32 B1z, f32 B2x, f32 B2z, f32* interX, f32* interZ, f32* squared_dist) {
    f32 dx14;
    f32 dx13;
    f32 dz;
    f32 dz12;
    f32 dx34;
    f32 dx12;
    f32 dx;
    f32 alpha;
    f32 minus_dz12;
    f32 B2_side;
    f32 x;
    f32 B1_side;
    f32 z;
    f32 dx12_copy;
    f32 dz13;
    f32 dz14;
    f32 dz34;
    f32 B1_side_;

    dx12_copy = A2x - A1x;
    dx12 = dx12_copy;
    dz12 = A2z - A1z;
    dx13 = B1x - A1x;
    dz13 = B1z - A1z;
    dx14 = B2x - A1x;
    dz14 = B2z - A1z;
    minus_dz12 = -dz12;
    dx34 = B2x - B1x;
    dz34 = B2z - B1z;

    // if distance between points on the line is 0
    if (dx12_copy == 0.0f && dz12 == 0.0f) {
        return FALSE;
    }
    // if length of second segment is 0
    if (dx34 == 0.0f && dz34 == 0.0f) {
        return FALSE;
    }

    B1_side_ = minus_dz12 * dx13 + dx12_copy * dz13;
    if (B1_side_ < 0.0f) {
        B1_side = -1.0f;
    } else if (B1_side_ > 0.0f) {
        B1_side = 1.0f;
    } else {
        B1_side = 0.0f;
    }
    B1_side_ = B1_side;

    dx = minus_dz12 * dx14 + dx12_copy * dz14;
    if (dx < 0.0f) {
        B2_side = -1.0f;
    } else if (dx > 0.0f) {
        B2_side = 1.0f;
    } else {
        B2_side = 0.0f;
    }

    // B1 and B2 are on the same side relative to the line: no intersection
    if (B1_side_ == B2_side) {
        return FALSE;
    }

    if (fabsf(dx12) > fabsf(dx34)) {
        /*
        We represent intersection point P as P = B1 + alpha * (B2 - B1)
        and solve the equation (P - A1) x (A2 - A1) = 0, where 'x' is cross product, A1 and A2 are points on the line
        and B1 and B2 are the ends of the segment.
        So, (B1 - A1 + alpha * (B2 - B1)) x (A2 - A1) = 0,
        alpha = [-(B1 - A1) x (A2 - A1)] / [(B2 - B1) x (A2 - A1)]
        */
        // same as -(B1 - A1) x (A2 - A1)
        alpha = A1x * dz12 - A1z * dx12 + dx12 * B1z - dz12 * B1x;
        // divide by (B2 - B1) x (A2 - A1)
        alpha /= dz12 * dx34 - dx12 * dz34;
        /*
            Now we represent P as P = A1 + beta * (A2 - A1), and we are to find beta.
            B1 + alpha * (B2 - B1) = A1 + beta * (A2 - A1)
            beta * (A2 - A1) = B1 + alpha * (B2 - B1) - A1
            We use only 'x' part of this equation to find beta.

            Actually this step could be omitted and we calculate intersection directly as B1 + alpha * (B2 - B1).
            Don't know why it's done this way.
        */
        alpha = (B1x + dx34 * alpha - A1x) / dx12;
        x = A1x + dx12 * alpha;
        z = A1z + dz12 * alpha;
    } else {
        /*
        We represent intersection point P as P = A1 + alpha * (A2 - A1)
        and solve the equation (B2 - B1) x (P - B1) = 0
        */
        // same as (B2 - B1) x (B1 - A1)
        alpha = B1z * dx34 + A1x * dz34 - B1z * dz34 - A1z * dx34;
        // divide by (B2 - B1) x (A2 - A1)
        alpha /= dz12 * dx34 - dx12 * dz34;
        // Now we represent P as P = B1 + beta * (B2 - B1) and find beta
        alpha = (A1x + dx12 * alpha - B1x) / dx34;
        x = B1x + dx34 * alpha;
        z = B1z + dz34 * alpha;
    }
    // (P - A1) * (P - A2) > 0 when P is outside of segment A1-A2
    if ((x - A1x) * (x - A2x) + (z - A1z) * (z - A2z) > 0.0f) {
        return FALSE;
    }

    dx = x - B1x;
    dz = z - B1z;
    *interX = x;
    *interZ = z;
    // distance between P and B1
    *squared_dist = SQ(dx) + SQ(dz);
    return TRUE;
}

s32 calculate_line_segment_intersection(f32 A1x, f32 A1z, f32 A2x, f32 A2z, f32 B1x, f32 B1z, f32 B2x, f32 B2z, f32* interX, f32* interZ, f32* squared_dist) {
    f32 dx14;
    f32 dx13;
    f32 dz;
    f32 dz12;
    f32 dx34;
    f32 dx12;
    f32 dx;
    f32 alpha;
    f32 minus_dz12;
    f32 B2_side;
    f32 x;
    f32 B1_side;
    f32 z;
    f32 dx12_copy;
    f32 dz13;
    f32 dz14;
    f32 dz34;
    f32 B1_side_;

    dx12_copy = A2x - A1x;
    dx12 = dx12_copy;
    dz12 = A2z - A1z;
    dx13 = B1x - A1x;
    dz13 = B1z - A1z;
    dx14 = B2x - A1x;
    dz14 = B2z - A1z;
    minus_dz12 = -dz12;
    dx34 = B2x - B1x;
    dz34 = B2z - B1z;

    if (dx12_copy == 0.0f && dz12 == 0.0f) {
        return FALSE;
    }
    if (dx34 == 0.0f && dz34 == 0.0f) {
        return FALSE;
    }

    B1_side_ = minus_dz12 * dx13 + dx12_copy * dz13;
    if (B1_side_ < 0.0f) {
        B1_side = -1.0f;
    } else if (B1_side_ > 0.0f) {
        B1_side = 1.0f;
    } else {
        B1_side = 0.0f;
    }
    B1_side_ = B1_side;

    dx = minus_dz12 * dx14 + dx12_copy * dz14;
    if (dx < 0.0f) {
        B2_side = -1.0f;
    } else if (dx > 0.0f) {
        B2_side = 1.0f;
    } else {
        B2_side = 0.0f;
    }

    if (B1_side_ == B2_side) {
        return FALSE;
    }

    if (fabsf(dx12) > fabsf(dx34)) {
        alpha = A1x * dz12 - A1z * dx12 + dx12 * B1z - dz12 * B1x;
        alpha /= dz12 * dx34 - dx12 * dz34;
        alpha = (B1x + dx34 * alpha - A1x) / dx12;
        x = A1x + dx12 * alpha;
        z = A1z + dz12 * alpha;
    } else {
        alpha = B1z * dx34 + A1x * dz34 - B1z * dz34 - A1z * dx34;
        alpha /= dz12 * dx34 - dx12 * dz34;
        alpha = (A1x + dx12 * alpha - B1x) / dx34;
        x = B1x + dx34 * alpha;
        z = B1z + dz34 * alpha;
    }

    dx = x - B1x;
    dz = z - B1z;
    *interX = x;
    *interZ = z;
    *squared_dist = SQ(dx) + SQ(dz);
    return TRUE;
}

s32 func_800328A4(CameraControlSettings* camSettings, f32 Px, f32 Pz) {
    f32 product1, product2;
    f32 delta, dot1x, dot1z, dot2x, dot2z;

    if (camSettings == NULL) {
        return 0;
    }
    if (camSettings->type != CAM_CONTROL_CONSTAIN_BETWEEN_POINTS) {
        return 0;
    }

    // dot product of AB and AP
    delta = Px - camSettings->points.two.Ax;
    dot1x = (camSettings->points.two.Bx - camSettings->points.two.Ax) * delta;
    delta = Pz - camSettings->points.two.Az;
    dot1z = (camSettings->points.two.Bz - camSettings->points.two.Az) * delta;

    // dot product of AB and BP
    delta = Px - camSettings->points.two.Bx;
    dot2x = (camSettings->points.two.Bx - camSettings->points.two.Ax) * delta;
    delta = Pz - camSettings->points.two.Bz;
    dot2z = (camSettings->points.two.Bz - camSettings->points.two.Az) * delta;

    product1 = dot1x + dot1z;
    product2 = dot2x + dot2z;

    if (product1 < 0 && product2 < 0) {
        return -1;
    }
    if (product1 > 0 && product2 > 0) {
        return 1;
    }
    return 0;
}

void update_camera_lead_amount(Camera* camera, f32 candidateLeadAmount) {
    f32 stickX;
    f32 deltaLeadAmount;
    s32 flags = camera->flags & CAMERA_FLAG_SUPRESS_LEADING;
    s32 ignoreStickInput = flags != 0;

    if (camera->curController != NULL && camera->curController->type == CAM_CONTROL_FIXED_POS_AND_ORIENTATION) {
        ignoreStickInput = TRUE;
    }

    if (ignoreStickInput) {
        stickX = 0.0f;
        camera->increasingLeadInterp = TRUE;
        camera->leadInterpAlpha = 1.0f;
        camera->targetLeadAmount = 0.0f;
    } else {
        if (gPlayerStatusPtr->animFlags & PA_FLAG_RIDING_PARTNER) {
            stickX = gPartnerStatus.stickX;
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
            if (camera->accumulatedStickLead > 0.0f) {
                // reversing direction
                camera->accumulatedStickLead = stickX;
            } else {
                camera->accumulatedStickLead += stickX;
            }
            if (camera->accumulatedStickLead <= -300.0f) {
                // max accumulation
                camera->increasingLeadInterp = TRUE;
                if (camera->targetLeadAmount > 0.0f) {
                    camera->leadInterpAlpha = 0.0f;
                }
                camera->targetLeadAmount = -candidateLeadAmount;
                camera->accumulatedStickLead = -300.0f;
            }
        } else {
            if (camera->accumulatedStickLead < 0.0f) {
                // reversing direction
                camera->accumulatedStickLead = stickX;
            } else {
                camera->accumulatedStickLead += stickX;
            }
            if (camera->accumulatedStickLead >= 300.0f) {
                // max accumulation
                camera->increasingLeadInterp = TRUE;
                if (camera->targetLeadAmount < 0.0f) {
                    camera->leadInterpAlpha = 0.0f;
                }
                camera->targetLeadAmount = candidateLeadAmount;
                camera->accumulatedStickLead = 300.0f;
            }
        }
    }

    if (camera->increasingLeadInterp) {
        camera->leadInterpAlpha += 0.01f;
        if (camera->leadInterpAlpha > 1.0f) {
            camera->leadInterpAlpha = 1.0f;
        }
    }

    // determine ratio to interp leadAmount by
    if (camera->targetLeadAmount - camera->leadAmount == 0.0f) {
        camera->leadInterpAlpha = 0.0f;
        camera->increasingLeadInterp = FALSE;
    }

    deltaLeadAmount = (camera->targetLeadAmount - camera->leadAmount) * camera->leadInterpAlpha;
    if (camera->targetLeadAmount - camera->leadAmount > 0.0f) {
        // snap small changes
        if (camera->targetLeadAmount - camera->leadAmount < 0.1) {
            deltaLeadAmount = camera->targetLeadAmount - camera->leadAmount;
        }
        // clamp large changes to 3.0
        if (deltaLeadAmount > 3.0f) {
            deltaLeadAmount = 3.0f;
        }
    } else {
        // snap small changes
        if (camera->targetLeadAmount - camera->leadAmount > -0.1) {
            deltaLeadAmount = camera->targetLeadAmount - camera->leadAmount;
        }
        // clamp large changes to -3.0
        if (deltaLeadAmount < -3.0f) {
            deltaLeadAmount = -3.0f;
        }
    }

    if (stickX != 0.0f || ignoreStickInput) {
        camera->leadAmount += deltaLeadAmount;
    } else {
        camera->leadInterpAlpha = 0.0f;
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
    f32 newPosX, newPosY, newPosZ;
    Collider* zone;
    s32 constrainToZoneTriangles;
    f32 minDistSq;
    f32 intX, intZ, intDistSq;
    f32 deltaPosX, deltaPosZ;
    f32 f24, f22, cosYaw, sinYaw;

    rotationRad = camera->trueRot.x / 180.0f * PI;
    leadAmount = camera->leadAmount;

    newPosX = camera->targetPos.x + leadAmount * cos_rad(rotationRad);
    newPosZ = camera->targetPos.z + leadAmount * sin_rad(rotationRad);
    newPosY = camera->targetPos.y + 10.0f;
    settings3 = settings = test_ray_zone(camera->targetPos.x, newPosY, camera->targetPos.z, NULL);

    s2 = 0;
    if (settings != NULL) {
        if (settings->type == CAM_CONTROL_CONSTRAIN_TO_LINE
            || settings->type == CAM_CONTROL_LOOK_AT_POINT_CONSTAIN_TO_LINE
            || (s2 = func_800328A4(settings, camera->targetPos.x, camera->targetPos.z)) != 0
        ) {
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
                camera->unk_530 = FALSE;
            } else {
                CameraControlSettings* leadSettings = camera->leadControlSettings;

                if (leadSettings == NULL
                    || !(leadSettings->type == CAM_CONTROL_CONSTRAIN_TO_LINE
                        || leadSettings->type == CAM_CONTROL_LOOK_AT_POINT_CONSTAIN_TO_LINE
                        || func_800328A4(settings, camera->leadUnkX, camera->leadUnkZ) != 0)) {
                    if (leadSettings != NULL && s2 != 0) {
                        camera->unk_52C = s2;
                    } else {
                        f24 = cosYaw = camera->targetPos.x - camera->leadUnkX;
                        f22 = camera->targetPos.z - camera->leadUnkZ;
                        cosYaw = -cos_deg(camera->curYaw);
                        sinYaw = -sin_deg(camera->curYaw);
                        product = f24 * cosYaw + f22 * sinYaw;
                        camera->unk_52C = (product > 0) ? -1 : (product < 0) ? 1 : 0;
                    }
                }
            }

            if (leadAmount > 0.0f && camera->unk_52C > 0 || leadAmount < 0.0f && camera->unk_52C < 0) {
                camera->leadInterpAlpha = 0.0f;
                camera->leadAmount = 0.0f;
            }
            camera->leadControlSettings = settings3;
            camera->leadUnkX = camera->targetPos.x;
            camera->leadUnkZ = camera->targetPos.z;
            return;
        }
    }

    camera->unk_52C = 0;
    camera->leadControlSettings = settings3;
    camera->leadUnkX = camera->targetPos.x;
    camera->leadUnkZ = camera->targetPos.z;
    newPosX = camera->targetPos.x + leadAmount * cos_rad(rotationRad);
    newPosZ = camera->targetPos.z + leadAmount * sin_rad(rotationRad);
    newPosY = camera->targetPos.y + 10.0f;
    settings = test_ray_zone(newPosX, newPosY, newPosZ, &zone);
    if (settings != NULL) {
        if (settings->type == CAM_CONTROL_CONSTRAIN_TO_LINE
            || settings->type == CAM_CONTROL_LOOK_AT_POINT_CONSTAIN_TO_LINE
            || func_800328A4(camera->leadControlSettings, newPosX, newPosZ) != 0
        ) {
            constrainToZoneTriangles = TRUE;
            minDistSq = SQ(1000.0f);

            // clamp lead amount to the points when using CAM_CONTROL_CONSTAIN_BETWEEN_POINTS
            if (camera->leadControlSettings != NULL && camera->leadControlSettings->type == CAM_CONTROL_CONSTAIN_BETWEEN_POINTS) {
                settings2 = camera->leadControlSettings;
                constrainToZoneTriangles = FALSE;

                deltaPosX = settings2->points.two.Bx - settings2->points.two.Ax;
                deltaPosZ = settings2->points.two.Bz - settings2->points.two.Az;

                if (calculate_line_segment_intersection(settings2->points.two.Ax, settings2->points.two.Az,
                        settings2->points.two.Ax - deltaPosZ, settings2->points.two.Az + deltaPosX,
                        camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &intX, &intZ, &intDistSq)
                    && intDistSq < minDistSq
                ) {
                    minDistSq = intDistSq;
                }
                do {
                    if (calculate_line_segment_intersection(settings2->points.two.Bx, settings2->points.two.Bz,
                            settings2->points.two.Bx - deltaPosZ, settings2->points.two.Bz + deltaPosX,
                            camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &intX, &intZ, &intDistSq)
                        && intDistSq < minDistSq
                    ) {
                        minDistSq = intDistSq;
                    }
                } while (0); // TODO find better match
            }
            if (constrainToZoneTriangles) {
                for (i = 0; i < zone->numTriangles; i++) {
                    if (calculate_segment_intersection(zone->triangleTable[i].v1->x, zone->triangleTable[i].v1->z,
                            zone->triangleTable[i].v2->x, zone->triangleTable[i].v2->z,
                            camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &intX, &intZ, &intDistSq)
                        && intDistSq < minDistSq
                    ) {
                        minDistSq = intDistSq;
                    }
                    if (calculate_segment_intersection(zone->triangleTable[i].v2->x, zone->triangleTable[i].v2->z,
                            zone->triangleTable[i].v3->x, zone->triangleTable[i].v3->z,
                            camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &intX, &intZ, &intDistSq)
                        && intDistSq < minDistSq
                    ) {
                        minDistSq = intDistSq;
                    }
                    if (calculate_segment_intersection(zone->triangleTable[i].v3->x, zone->triangleTable[i].v3->z,
                            zone->triangleTable[i].v1->x, zone->triangleTable[i].v1->z,
                            camera->targetPos.x, camera->targetPos.z, newPosX, newPosZ, &intX, &intZ, &intDistSq)
                        && intDistSq < minDistSq
                    ) {
                        minDistSq = intDistSq;
                    }
                }
            }

            if (minDistSq == SQ(1000.0f) || minDistSq == 0.0f) {
                camera->leadAmount = 0.0f;
            } else {
                camera->leadAmount = abs(camera->leadAmount > 0.0f) ? sqrtf(minDistSq) : -sqrtf(minDistSq);
            }
            camera->leadInterpAlpha = 0.0f;
        }
    }
}

void create_camera_leadplayer_matrix(Camera* camera) {
    f32 dx = camera->lookAt_eye.x - camera->lookAt_obj.x;
    f32 dy = camera->lookAt_eye.y - camera->lookAt_obj.y;
    f32 dz = camera->lookAt_eye.z - camera->lookAt_obj.z;
    f32 dist = sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
    f32 theta = ((camera->vfov * 0.5f) / 180.0f) * PI;
    f32 distTanTheta = dist * sin_rad(theta);
    distTanTheta /= cos_rad(theta);

    update_camera_lead_amount(camera, (distTanTheta * camera->viewportW / camera->viewportH) * camera->unk_520);
    func_80032C64(camera);
    guTranslateF(camera->viewMtxLeading, -camera->leadAmount, 0.0f, 0.0f);
}

void func_800334E8(void) {
}
