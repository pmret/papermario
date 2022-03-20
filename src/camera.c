#include "common.h"

s32 gCurrentCameraID = CAM_DEFAULT;

s32 func_800328A4(Camera* camera, f32 arg1, f32 arg2);
s32 func_80032970(Camera* camera, f32 arg1);
void create_camera_leadplayer_matrix(Camera* camera);

CameraControlSettings* test_ray_zone(f32 posX, f32 posY, f32 posZ, TempSetZoneEnabled** zone) {
    f32 hitX, hitY, hitZ, hitDepth, nX, nY, nZ;
    s32 zoneID;

    hitDepth = 32767;
    zoneID = test_ray_zones(posX, posY, posZ, 0, -1, 0, &hitX, &hitY, &hitZ, &hitDepth, &nX, &nY, &nZ);
    if (zoneID >= 0) {
        if (zone) {
            *zone = &D_800D91D4[zoneID];
        }
        return D_800D91D4[zoneID].unk_10;
    } else {
        return NULL;
    }
}

INCLUDE_ASM(s32, "camera", func_800322DC);

INCLUDE_ASM(s32, "camera", func_800325E4);

INCLUDE_ASM(s32, "camera", func_800328A4, Camera* camera, f32 arg1, f32 arg2);

INCLUDE_ASM(s32, "camera", func_80032970, Camera* camera, f32 arg1);

INCLUDE_ASM(s32, "camera", func_80032C64);
/*
s32 func_80032C64(Camera* camera) {
    f32 f20;
    f32 f26;
    CameraControlSettings* settings;
    s32 s2;
    f32 X, Y, Z, S;

    f20 = camera->trueRotation.x / 180 * PI;
    f26 = camera->leadAmount;
    cos_rad(f20);
    sin_rad(f20);
    settings = test_ray_zone(camera->targetPos.x, camera->targetPos.y, camera->targetPos.z, NULL);

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
                if (X > 0) {
                    camera->unk_52C = 1;
                } else if (X == 0) {
                    camera->unk_52C = 0;
                } else {
                    camera->unk_52C = -1;
                }
                camera->unk_530 = 0;
            } else {

            }
        }
    }
}*/


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
