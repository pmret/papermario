#include "common.h"
#include "camera.h"

void update_camera_mode_4(Camera* camera) {
    f32 sinBoom;
    f32 cosBoom;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;
    f32 deltaX2;
    f32 deltaY2;
    f32 deltaZ2;
    f32 boomYaw;
    f32 boomLength;
    f32 f0;
    f32 f4;
    f32 new_var;

    f0 = camera->targetPos.x;
    deltaX = camera->auxPitch;
    if (f0 > deltaX) {
        f0 = deltaX;
    }
    if (f0 < -deltaX) {
        f0 = -deltaX;
    }
    camera->lookAt_obj_target.x = f0;
    f4 = camera->targetPos.z;
    deltaZ = camera->auxBoomLength;
    if (f4 > deltaZ) {
        f4 = deltaZ;
    }
    if (f4 < -deltaZ) {
        f4 = -deltaZ;
    }
    camera->lookAt_obj_target.z = f4;
    camera->unk_70 = 0.0f;
    camera->curBoomYaw = 0.0f;
    camera->trueRot.x = camera->unk_70;
    camera->curBoomLength = camera->lookAt_dist * D_8009A5EC;
    camera->curYOffset = camera->auxBoomPitch * D_8009A5EC;
    if (camera->needsInit) {
        camera->needsInit = FALSE;
        camera->unk_98 = 0.0f;
        camera->unk_9C = 0.0f;
        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y + camera->curYOffset;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;
        boomYaw = DEG_TO_RAD(camera->curBoomYaw);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);
        deltaX = 0.0f;
        deltaY = 0.0f;
        deltaZ = camera->curBoomLength;
        deltaX2 = deltaX;
        deltaY2 = deltaY;
        boomYaw = deltaX = -deltaY2;
        deltaZ2 = deltaZ;
        new_var = boomYaw;
        deltaX = deltaX2;
        deltaY = cosBoom * deltaY2 + deltaZ2 * sinBoom;
        deltaZ = sinBoom * new_var + deltaZ2 * cosBoom;
        boomYaw = DEG_TO_RAD(camera->unk_70);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);
        deltaX2 = cosBoom * deltaX - deltaZ * sinBoom;
        deltaY2 = deltaY;
        deltaZ2 = sinBoom * deltaX + deltaZ * cosBoom;
        camera->lookAt_eye.x = camera->lookAt_obj.x + deltaX2;
        camera->lookAt_eye.y = camera->lookAt_obj.y + deltaY2;
        camera->lookAt_eye.z = camera->lookAt_obj.z + deltaZ2;
    }
    camera->lookAt_obj.x = camera->lookAt_obj_target.x;
    camera->lookAt_obj.y = camera->lookAt_obj_target.y + camera->curYOffset;
    camera->lookAt_obj.z = camera->lookAt_obj_target.z;
    boomYaw = DEG_TO_RAD(camera->curBoomYaw);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);
    deltaX = 0.0f;
    deltaY = 0.0f;
    deltaZ = camera->curBoomLength;
    deltaX2 = deltaX;
    deltaY2 = deltaY;
    boomYaw = deltaX = -deltaY2;
    deltaZ2 = deltaZ;
    new_var = boomYaw;
    deltaX = deltaX2;
    deltaY = cosBoom * deltaY2 + deltaZ2 * sinBoom;
    deltaZ = sinBoom * new_var + deltaZ2 * cosBoom;
    boomYaw = DEG_TO_RAD(camera->unk_70);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);
    deltaX2 = cosBoom * deltaX - deltaZ * sinBoom;
    deltaY2 = deltaY;
    deltaZ2 = sinBoom * deltaX + deltaZ * cosBoom;
    camera->lookAt_eye.x = camera->lookAt_obj.x + deltaX2;
    camera->lookAt_eye.y = camera->lookAt_obj.y + deltaY2;
    camera->lookAt_eye.z = camera->lookAt_obj.z + deltaZ2;
    camera->curYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    deltaX = camera->lookAt_obj.x - camera->lookAt_eye.x;
    deltaY = camera->lookAt_obj.y - camera->lookAt_eye.y;
    deltaZ = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->curBlendedYawNegated = -atan2(0.0f, 0.0f, deltaX, deltaZ);
    camera->curPitch = atan2(0.0f, 0.0f, deltaY, -sqrtf(SQ(deltaX) + SQ(deltaZ)));
}

void update_camera_mode_2(Camera *camera) {
    f32 cosBoom;
    f32 sinBoom;
    f32 boomYaw;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;
    f32 deltaX2;
    f32 deltaY2;
    f32 deltaZ2;
    f32 deltaX3;
    f32 deltaY3;
    f32 deltaZ3;
    f32 tmp;

    camera->unk_70 = camera->auxBoomLength;
    camera->curBoomLength = camera->lookAt_dist * D_8009A5EC;
    camera->curYOffset = camera->auxBoomPitch * D_8009A5EC;
    camera->curBoomYaw = camera->auxPitch;
    camera->trueRot.x = camera->unk_70;
    if (camera->needsInit) {
        camera->needsInit = FALSE;
        camera->unk_98 = 0.0f;
        camera->unk_9C = 0.0f;

        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y + camera->curYOffset;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;

        boomYaw = DEG_TO_RAD(camera->curBoomYaw);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);

        deltaX = 0.0f;
        deltaY = 0.0f;
        deltaZ = camera->curBoomLength;

        deltaX3 = deltaX;
        deltaY3 = -deltaY;
        tmp = -0.0f; //required to match
        deltaZ3 = deltaZ;

        deltaX = deltaX3;
        deltaY = cosBoom * -deltaY3 + deltaZ3 * sinBoom;
        deltaZ = sinBoom * deltaY3 + deltaZ3 * cosBoom;

        boomYaw = DEG_TO_RAD(camera->unk_70);
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);

        deltaX3 = cosBoom * deltaX - deltaZ * sinBoom;
        deltaY3 = deltaY;
        deltaZ3 = sinBoom * deltaX + deltaZ * cosBoom;

        deltaX2 = camera->lookAt_obj.x + deltaX3;
        deltaY2 = camera->lookAt_obj.y + deltaY3;
        deltaZ2 = camera->lookAt_obj.z + deltaZ3;

        camera->lookAt_eye.x = deltaX2;
        camera->lookAt_eye.y = deltaY2;
        camera->lookAt_eye.z = deltaZ2;
    }

    deltaX2 = camera->lookAt_obj_target.x - camera->lookAt_obj.x;
    deltaY2 = (camera->lookAt_obj_target.y + camera->curYOffset) - camera->lookAt_obj.y;
    deltaZ2 = camera->lookAt_obj_target.z - camera->lookAt_obj.z;

    if (fabsf(deltaX2) > 16.0f) {
        if (deltaX2 < 0.0f) {
            deltaX2 = -16.0f;
        } else {
            deltaX2 = 16.0f;
        }
    }
    if (fabsf(deltaY2) > 16.0f) {
        if (deltaY2 < 0.0f) {
            deltaY2 = -16.0f;
        } else {
            deltaY2 = 16.0f;
        }
    }
    if (fabsf(deltaZ2) > 16.0f) {
        if (deltaZ2 < 0.0f) {
            deltaZ2 = -16.0f;
        } else {
            deltaZ2 = 16.0f;
        }
    }

    camera->lookAt_obj.x += deltaX2 * 0.5f;
    camera->lookAt_obj.y += deltaY2 * 0.5f;
    camera->lookAt_obj.z += deltaZ2 * 0.5f;

    boomYaw = DEG_TO_RAD(camera->curBoomYaw);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);

    deltaX = 0.0f;
    deltaY = 0.0f;
    deltaZ = camera->curBoomLength;

    deltaX3 = deltaX;
    deltaY3 = -deltaY;
    deltaZ3 = deltaZ;

    deltaX = deltaX3;
    deltaY = cosBoom * -deltaY3 + deltaZ3 * sinBoom;
    deltaZ = sinBoom * deltaY3 + deltaZ3 * cosBoom;

    boomYaw = DEG_TO_RAD(camera->unk_70);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);

    deltaX3 = cosBoom * deltaX - deltaZ * sinBoom;
    deltaY3 = deltaY;
    deltaZ3 = sinBoom * deltaX + deltaZ * cosBoom;

    deltaX2 = camera->lookAt_obj.x + deltaX3;
    deltaY2 = camera->lookAt_obj.y + deltaY3;
    deltaZ2 = camera->lookAt_obj.z + deltaZ3;

    deltaX2 = (deltaX2 - camera->lookAt_eye.x) * 0.5f;
    deltaY2 = (deltaY2 - camera->lookAt_eye.y) * 0.5f;
    deltaZ2 = (deltaZ2 - camera->lookAt_eye.z) * 0.5f;

    tmp = 0.0f; //required to match

    if (fabsf(deltaX2) > 16.0f) {
        if (deltaX2 < 0.0f) {
            deltaX2 = -16.0f;
        } else {
            deltaX2 = 16.0f;
        }
    }
    if (fabsf(deltaY2) > 16.0f) {
        if (deltaY2 < 0.0f) {
            deltaY2 = -16.0f;
        } else {
            deltaY2 = 16.0f;
        }
    }
    if (fabsf(deltaZ2) > 16.0f) {
        if (deltaZ2 < 0.0f) {
            deltaZ2 = -16.0f;
        } else {
            deltaZ2 = 16.0f;
        }
    }

    camera->lookAt_eye.x += deltaX2;
    camera->lookAt_eye.y += deltaY2;
    camera->lookAt_eye.z += deltaZ2;

    camera->curYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);

    deltaX = camera->lookAt_obj.x - camera->lookAt_eye.x;
    deltaY = camera->lookAt_obj.y - camera->lookAt_eye.y;
    deltaZ = camera->lookAt_obj.z - camera->lookAt_eye.z;

    camera->curBlendedYawNegated = -atan2(0.0f, 0.0f, deltaX, deltaZ);
    camera->curPitch = atan2(0.0f, 0.0f, deltaY, -sqrtf(SQ(deltaX) + SQ(deltaZ)));
}

void update_camera_mode_1(Camera* camera) {
    f32 sinBoom, cosBoom;
    f32 f20;
    f32 boomYaw;
    f32 deltaX, deltaY, deltaZ;
    f32 deltaX2, deltaY2, deltaZ2;
    f32 x3, y3, z3;
    f32 x2, y2, z2;
    f32 new_var2;
    f32 tmp1;

    if (camera->needsInit) {
        camera->needsInit = FALSE;

        deltaX = camera->lookAt_obj_target.x;
        deltaZ2 = camera->lookAt_obj_target.z;

        deltaX2 = camera->targetPos.x;
        deltaZ = camera->targetPos.z;

        camera->curBoomYaw = camera->auxPitch;
        camera->curBoomLength = camera->lookAt_dist * 100 / D_8009A5EC;
        camera->curYOffset = camera->auxBoomPitch * 20 / D_8009A5EC;

        f20 = atan2(deltaX, deltaZ2, deltaX2, deltaZ);
        if ((dist2D(deltaX, deltaZ2, deltaX2, deltaZ) < camera->auxBoomLength * 100 / D_8009A5EC)) {
            f20 = camera->trueRot.x;
            camera->trueRot.x = f20;
        } else {
            camera->trueRot.x = f20;
        }
        camera->trueRot.y = f20;

        camera->lookAt_obj.x = camera->lookAt_obj_target.x;
        camera->lookAt_obj.y = camera->lookAt_obj_target.y + camera->curYOffset;
        camera->lookAt_obj.z = camera->lookAt_obj_target.z;

        boomYaw = DEG_TO_RAD(camera->curBoomYaw);
        sinBoom = sin_rad(boomYaw);

        deltaX = 0.0f;
        deltaY = 0.0f;
        new_var2 = -deltaY;
        cosBoom = cos_rad(boomYaw);
        boomYaw = new_var2;
        deltaZ = camera->curBoomLength;

        deltaX2 = deltaX;
        deltaY2 = new_var2;
        deltaZ2 = deltaZ;

        deltaX = deltaX2;
        deltaY = cosBoom * -deltaY2 + deltaZ2 * sinBoom;
        deltaZ = sinBoom * deltaY2 + deltaZ2 * cosBoom;

        boomYaw = DEG_TO_RAD(f20);
        deltaZ2 = deltaZ;
        sinBoom = sin_rad(boomYaw);
        cosBoom = cos_rad(boomYaw);

        deltaX2 = cosBoom * deltaX - deltaZ * sinBoom;
        deltaY2 = deltaY;
        deltaZ = sinBoom * deltaX + deltaZ * cosBoom;

        camera->lookAt_eye.x = camera->lookAt_obj.x + deltaX2;
        camera->lookAt_eye.y = camera->lookAt_obj.y + deltaY2;
        camera->lookAt_eye.z = camera->lookAt_obj.z + deltaZ;
    }
    tmp1 = camera->lookAt_obj_target.y;

    x3 = camera->lookAt_obj_target.x;
    y3 = tmp1;
    z3 = camera->lookAt_obj_target.z;

    camera->curBoomYaw = camera->auxPitch;
    camera->curBoomLength = camera->lookAt_dist * 100 / D_8009A5EC;
    camera->curYOffset = camera->auxBoomPitch * 20 / D_8009A5EC;

    y3 += camera->curYOffset;

    x3 -= camera->lookAt_obj.x;
    y3 -= camera->lookAt_obj.y;
    z3 -= camera->lookAt_obj.z;

    deltaX = camera->lookAt_obj_target.x;
    deltaY = camera->lookAt_obj_target.y;
    deltaZ2 = camera->lookAt_obj_target.z;

    deltaX2 = camera->targetPos.x;
    deltaY2 = camera->targetPos.y;
    deltaZ = camera->targetPos.z;

    camera->lookAt_obj.x += x3 * 0.5f;
    camera->lookAt_obj.y += y3 / 10.0f;
    camera->lookAt_obj.z += z3 * 0.5f;

    f20 = atan2(deltaX, deltaZ2, deltaX2, deltaZ);
    if ((dist2D(deltaX, deltaZ2, deltaX2, deltaZ) < camera->auxBoomLength * 100 / D_8009A5EC)) {
        f20 = camera->trueRot.x;
    } else {
        camera->trueRot.x = f20;
    }
    camera->trueRot.y -= get_clamped_angle_diff(f20, camera->trueRot.y) / 10.0f;
    f20 = camera->trueRot.y;

    boomYaw = DEG_TO_RAD(camera->curBoomYaw);
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);

    deltaX = 0.0f;
    deltaY = 0.0f;
    deltaZ = camera->curBoomLength;

    deltaX2 = deltaX;
    deltaY2 = -deltaY;
    deltaZ2 = deltaZ;

    deltaX = deltaX2;
    deltaY = -deltaY2;
    deltaY = (cosBoom * deltaY) + (deltaZ2 * sinBoom);
    deltaZ = sinBoom * deltaY2 + deltaZ2 * cosBoom;
    deltaY2 = deltaY;

    boomYaw = DEG_TO_RAD((f20));
    deltaZ2 = deltaZ;
    sinBoom = sin_rad(boomYaw);
    cosBoom = cos_rad(boomYaw);

    deltaX2 = cosBoom * deltaX - deltaZ * sinBoom;
    deltaZ = sinBoom * deltaX + deltaZ * cosBoom;

    camera->lookAt_eye.x = camera->lookAt_obj.x + deltaX2;
    camera->lookAt_eye.y = camera->lookAt_obj.y + deltaY2;
    camera->lookAt_eye.z = camera->lookAt_obj.z + deltaZ;

    camera->curYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);

    deltaX = camera->lookAt_obj.x - camera->lookAt_eye.x;
    deltaY = camera->lookAt_obj.y - camera->lookAt_eye.y;
    deltaZ2 = camera->lookAt_obj.z - camera->lookAt_eye.z;

    camera->curBlendedYawNegated = -atan2(0.0f, 0.0f, deltaX, deltaZ2);
    camera->curPitch = atan2(0.0f, 0.0f, deltaY, -sqrtf((deltaX * deltaX) + (deltaZ2 * deltaZ2)));
}

void update_camera_mode_0(Camera* camera) {
    f32 dx;
    f32 dy;
    f32 dz;

    if (camera->needsInit) {
        camera->lookAt_obj.x = 0.0f;
        camera->lookAt_obj.y = 0.0f;
        camera->lookAt_obj.z = 0.0f;
        camera->needsInit = FALSE;
        camera->lookAt_eye.x = camera->lookAt_obj.x;
        camera->lookAt_eye.y = camera->lookAt_obj.y;
        camera->lookAt_eye.z = camera->lookAt_obj.z - (1000.0f / D_8009A5EC);
    }

    camera->curYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    dx = camera->lookAt_obj.x - camera->lookAt_eye.x;
    dy = camera->lookAt_obj.y - camera->lookAt_eye.y;
    dz = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->curBlendedYawNegated = -atan2(0.0f, 0.0f, dx, dz);
    dx = -sqrtf(SQ(dx) + SQ(dz));
    camera->curPitch = atan2(0.0f, 0.0f, dy, dx);
}
