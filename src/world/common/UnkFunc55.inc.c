#include "common.h"
#include "npc.h"
#include "effects.h"

ApiStatus N(UnkFunc55)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Camera* camera = &gCameras[gCurrentCamID];
    s32 phi_s4 = 0;
    Npc* npc;
    f32 x, y, z;
    f32 hitDepth;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f22;
    f32 yaw;
    s32 cond;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (get_enemy_safe(enemy->npcID) == NULL) {
        evt_set_variable(script, EVT_VAR(0), 0);
        return ApiStatus_DONE2;
    }
    if (enemy->varTable[0] == 5) {
        evt_set_variable(script, EVT_VAR(0), 0);
        return ApiStatus_DONE2;
    }
    if (get_enemy_safe(enemy->npcID) == NULL) {
        evt_set_variable(script, EVT_VAR(0), 0);
        return ApiStatus_DONE2;
    }

    npc = get_npc_unsafe(enemy->npcID);
    switch (script->functionTemp[0]) {
        case 0:
            fx_walking_dust(2, npc->pos.x, npc->pos.y, npc->pos.z, 0.0f, 0.0f);
            yaw = clamp_angle(camera->currentYaw);
            temp_f20_2 = clamp_angle(yaw + 180.0);
            temp_f22 = clamp_angle(yaw + 90.0);
            temp_f20_3 = clamp_angle(temp_f20_2 + 90.0);
            if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, gPlayerStatusPtr->currentYaw)) < 180.0) {
                npc->yaw = temp_f22;
            } else {
                npc->yaw = temp_f20_3;
            }
            npc->duration = 30;
            npc->jumpVelocity = 10.0f;
            npc->jumpScale = 0.9f;
            npc->moveSpeed *= 1.2;
            script->functionTemp[0] = 1;
            /* fallthrough */
        case 1:
            x = npc->pos.x;
            y = npc->pos.y;
            z = npc->pos.z;
            if (npc_test_move_simple_with_slipping(0, &x, &y, &z, npc->moveSpeed, npc->yaw, npc->collisionRadius,
                npc->collisionHeight) == 0)
            {
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            } else {
                phi_s4 = 1;
            }

            cond = FALSE;
            if (npc->jumpVelocity < 0.0) {
                x = npc->pos.x;
                y = npc->pos.y + 13.0;
                z = npc->pos.z;
                hitDepth = fabsf(npc->jumpVelocity) + 16.0;
                if ((npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &hitDepth) != 0) &&
                    (hitDepth <= (fabsf(npc->jumpVelocity) + 13.0)))
                {
                    cond = TRUE;
                }
            }

            if (!cond) {
                npc->pos.y += npc->jumpVelocity;
                npc->jumpVelocity -= npc->jumpScale;
            } else {
                phi_s4 = 10;
            }

            npc->duration--;
            if (npc->duration <= 0) {
                phi_s4 = 11;
            }

            if (phi_s4 != 0) {
                fx_walking_dust(2, npc->pos.x, npc->pos.y, npc->pos.z, 0, 0);
                enemy->varTable[0] = 0;
                npc->pos.x = 0.0f;
                npc->pos.z = 0.0f;
                npc->pos.y = -1000.0f;
                npc->flags |= NPC_FLAG_2;
                disable_npc_shadow(npc);
                npc->flags &= ~NPC_FLAG_JUMPING;
                enemy->flags |= ENEMY_FLAGS_10000000 | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_IGNORE_HAMMER |
                                ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_TOUCH;
                script->functionTemp[0] = 0;
                evt_set_variable(script, EVT_VAR(0), 1);
                return ApiStatus_DONE2;
            }
            if (enemy->varTable[1] & 1) {
                npc->rotation.z += 60.0;
            }
            break;
    }
    return ApiStatus_BLOCK;
}
