#include "common.h"

void interp_lookat_pos(Camera* camera, f32 arg1, f32 arg2, s16 arg3);
void update_unused_lead_amt(Camera* camera);

// implementation for CAM_UPDATE_UNUSED_5
void update_camera_unused_leading(Camera* camera) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 lookXDelta, lookYDelta, lookZDelta;

    camera->curBoomYaw = 18.0f;
    camera->curBoomLength = 690.0f;
    camera->curYOffset = 47.0f;

    if (camera->needsInit) {
        camera->unusedLeadAmt = 0.0f;
        camera->interpYaw = 0.0f;
        camera->trueRot.x = 0.0f;
        camera->needsInit = FALSE;
        camera->unusedLeadCounter = 0;
        camera->lookAt_obj.x = camera->targetPos.x;
        camera->lookAt_obj.y = camera->targetPos.y + camera->curYOffset;
        camera->lookAt_obj.z = camera->targetPos.z;
        interp_lookat_pos(camera, 0.0f, 0.0f, FALSE);
    } else {
        f32 maxInterpSpeed = (playerStatus->curSpeed * 1.5f) + 1.0f;
        f32 interpRate = (playerStatus->curSpeed * 0.05f) + 0.05f;

        camera->lookAt_obj_target.x = camera->targetPos.x + camera->unusedLeadAmt;
        camera->lookAt_obj_target.y = camera->targetPos.y + camera->curYOffset;
        camera->lookAt_obj_target.z = camera->targetPos.z;
        update_unused_lead_amt(camera);
        if (!(camera->moveFlags & CAMERA_MOVE_IGNORE_PLAYER_Y)) {
            interp_lookat_pos(camera, interpRate, maxInterpSpeed, FALSE);
        } else {
            lookXDelta = maxInterpSpeed; // needed to match

            interp_lookat_pos(camera, interpRate, lookXDelta, TRUE);
        }
    }

    camera->curYaw = atan2(camera->lookAt_eye.x, camera->lookAt_eye.z, camera->lookAt_obj.x, camera->lookAt_obj.z);
    lookXDelta = camera->lookAt_obj.x - camera->lookAt_eye.x;
    lookYDelta = camera->lookAt_obj.y - camera->lookAt_eye.y;
    lookZDelta = camera->lookAt_obj.z - camera->lookAt_eye.z;
    camera->curBlendedYawNegated = -atan2(0.0f, 0.0f, lookXDelta, lookZDelta);
    camera->curPitch = atan2(0.0f, 0.0f, lookYDelta, -sqrtf(SQ(lookXDelta) + SQ(lookZDelta)));
}

void interp_lookat_pos(Camera* camera, f32 interpAmtXZ, f32 maxDeltaXZ, s16 lockPosY) {
    f32 xDelta = (camera->lookAt_obj_target.x - camera->lookAt_obj.x) * interpAmtXZ;
    f32 theta;
    f32 cosTheta;
    f32 sinTheta;

    if (xDelta < -maxDeltaXZ) {
        xDelta = -maxDeltaXZ;
    }
    if (xDelta > maxDeltaXZ) {
        xDelta = maxDeltaXZ;
    }

    camera->lookAt_obj.x = camera->lookAt_eye.x = camera->lookAt_obj.x + xDelta;

    theta = DEG_TO_RAD(camera->curBoomYaw);
    cosTheta = cos_rad(DEG_TO_RAD(camera->curBoomYaw));
    camera->lookAt_obj.z += (camera->lookAt_obj_target.z - camera->lookAt_obj.z) * interpAmtXZ;
    camera->lookAt_eye.z = camera->lookAt_obj.z + (camera->curBoomLength * cosTheta);

    if (!lockPosY) {
        sinTheta = sin_rad(theta);
        camera->lookAt_obj.y += (camera->lookAt_obj_target.y - camera->lookAt_obj.y) * 0.125f;
        camera->lookAt_eye.y = camera->lookAt_obj.y + (camera->curBoomLength * sinTheta);
    }
}

void update_unused_lead_amt(Camera* camera) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (fabsf(get_clamped_angle_diff(playerStatus->curYaw, 90.0f)) < 45.0f) {
        if (camera->unusedLeadDir == 0) {
            if (camera->unusedLeadCounter <= 0) {
                camera->unusedLeadAmt = 35.0f;
            } else {
                camera->unusedLeadCounter--;
            }
        } else {
            camera->unusedLeadCounter = 15;
            camera->unusedLeadDir = 0;
        }
    } else if (fabsf(get_clamped_angle_diff(playerStatus->curYaw, 270.0f)) < 45.0f) {
        if (camera->unusedLeadDir == 1) {
            if (camera->unusedLeadCounter <= 0) {
                camera->unusedLeadAmt = -35.0f;
            } else {
                camera->unusedLeadCounter--;
            }
        } else {
            camera->unusedLeadCounter = 15;
            camera->unusedLeadDir = 1;
        }
    }
}
