#include "common.h"

void sin_cos_rad(f32, f32*, f32*);
f32 func_800E34D8(void);
f32 player_check_collision_below(f32 length, s32* hitColliderID); // player_check_collision_below
s32 get_collider_type_by_id(s32 colliderID);

extern f32 D_802B6240; // bss? angle to lastGoodPosition

// Float problems near get_xz_dist_to_player; almost matching otherwise
#ifndef NON_MATCHING
INCLUDE_ASM(void, "world/action/16", func_802B6000_E287F0, void);
#else
void func_802B6000_E287F0(void) {
    f32 dx;
    f32 dy;
    f32 speed;
    f32 angleRad;

    if (gPlayerStatus.flags & 0x80000000) {
        Camera* cameras = gCameras;

        gPlayerStatus.flags &= ~0x80000000;

        suggest_player_anim_setUnkFlag(0x10017);

        cameras[0].moveFlags |= 1;

        gPlayerStatus.fallState = 0;
        gPlayerStatus.gravityIntegrator[0] = 18.3473f;
        gPlayerStatus.gravityIntegrator[1] = -3.738f;
        gPlayerStatus.gravityIntegrator[2] = 0.8059f;
        gPlayerStatus.gravityIntegrator[3] = -0.0987f;
        gPlayerStatus.flags |= 8;

        D_802B6240 = atan2(gPlayerStatus.position.x, gPlayerStatus.position.z, gPlayerStatus.lastGoodPosition.x,
                           gPlayerStatus.lastGoodPosition.z);
        gPlayerStatus.currentSpeed = get_xz_dist_to_player(gPlayerStatus.lastGoodPosition.x, gPlayerStatus.lastGoodPosition.z) / 18.0f;
    }

    angleRad = (D_802B6240 * TAU) / 360.0f;
    sin_cos_rad(angleRad, &dx, &dy);

    speed = gPlayerStatus.currentSpeed;

    if (gPlayerStatus.flags & 0x40000) {
        speed *= 0.5f;
    }

    gPlayerStatus.position.x += speed * dx;
    gPlayerStatus.position.z -= speed * dy;

    if (gPlayerStatus.fallState == 0) {
        integrate_gravity();

        gPlayerStatus.position.y += gPlayerStatus.gravityIntegrator[0];

        if (gPlayerStatus.gravityIntegrator[0] < 0.0f) {
            gPlayerStatus.fallState = 1; // Now start checking for floor
            gPlayerStatus.flags |= 4;
        }
    } else {
        s32 colliderID;

        gPlayerStatus.position.y = player_check_collision_below(func_800E34D8(), &colliderID);

        if (colliderID >= 0) {
            colliderID = get_collider_type_by_id(colliderID); // what
            set_action_state(ACTION_STATE_LAND);
        }
    }
}
#endif
