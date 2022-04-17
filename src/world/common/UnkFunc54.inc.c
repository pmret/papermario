#include "common.h"
#include "npc.h"
#include "effects.h"

typedef struct TempStuff {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ char unk_04[0x8];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
} TempStuff; // size = 0x??

ApiStatus N(UnkFunc54)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    s32 phi_s6 = 0;
    f32 x, y, z;
    f32 hitDepth;
    Npc* npc;
    Npc* npc2;
    TempStuff* temp_s5;
    u32 vt0;

    if (get_enemy_safe(enemy->npcID) != NULL) {
        if (enemy->varTable[0] != 5) {
            temp_s5 = (TempStuff*)evt_get_variable(script, *args++);
            npc = get_npc_unsafe(enemy->npcID);

            if (enemy->varTable[1] & 2) {
                npc->unk_AB = npc->collisionHeight / 2;
            }

            if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
                script->functionTemp[0] = 0;
                npc->duration = 0;
                npc->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_2;
                disable_npc_shadow(npc);
                npc->flags &= ~NPC_FLAG_JUMPING;
                enemy->varTable[0] = 0;
                enemy->flags |= ENEMY_FLAGS_10000000 | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_IGNORE_HAMMER |
                                ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_200000 |
                                ENEMY_FLAGS_100000 | ENEMY_FLAGS_40;
                if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
                    enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
                }
            }

            switch (script->functionTemp[0]) {
                default:
                    return 0;
                case 0:
                    npc->flags |= NPC_FLAG_2;
                    disable_npc_shadow(npc);
                    enemy->varTable[0] = 0;
                    script->functionTemp[0] = 1;
                    // fallthrough
                case 1:
                    vt0 = enemy->varTable[0];

                    if (enemy->varTable[0] == 1) {
                        enemy->varTable[0] = 2;
                        npc2 = get_npc_unsafe(enemy->varTable[4]);
                        npc->pos.x = npc2->pos.x;
                        npc->pos.z = npc2->pos.z;
                        add_vec2D_polar(&npc->pos.x, &npc->pos.z, enemy->varTable[3], 270.0f - npc2->renderYaw);
                        npc->pos.y = npc2->pos.y + enemy->varTable[2];
                        enemy->unk_07 = vt0;
                        enemy->unk_10.x = npc->pos.x;
                        enemy->unk_10.y = npc->pos.y;
                        enemy->unk_10.z = npc->pos.z;
                        npc->rotation.x = 0.0f;
                        npc->rotation.y = 0.0f;
                        npc->rotation.z = 0.0f;
                        npc->moveSpeed = temp_s5->unk_00;
                        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                        npc->jumpVelocity = temp_s5->unk_0C;
                        npc->jumpScale = temp_s5->unk_10;
                        npc->moveToPos.y = npc2->pos.y;
                        npc->flags &= ~NPC_FLAG_2;
                        enable_npc_shadow(npc);
                        npc->flags |= NPC_FLAG_JUMPING;
                        enemy->flags &= ~(ENEMY_FLAGS_10000000 | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_IGNORE_HAMMER |
                                          ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_TOUCH);
                        npc->duration = 90;
                        script->functionTemp[0] = 2;
                        break;
                    }
                    return 0;
                case 2:
                    break;
            }


            x = npc->pos.x;
            y = npc->pos.y + (npc->collisionHeight * 0.5);
            z = npc->pos.z;
            if (npc_test_move_taller_with_slipping(
                0, &x, &y, &z, npc->moveSpeed, npc->yaw, npc->collisionRadius, npc->collisionHeight) != 0)
            {
                phi_s6 = 1;
            }

            x = npc->pos.x;
            y = npc->pos.y;
            z = npc->pos.z;
            hitDepth = 1000.0f;
            if ((npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &hitDepth) != 0) &&
                (hitDepth < fabsf(npc->jumpVelocity)) &&
                (fabsf(y - npc->moveToPos.y) < 20.0))
            {
                npc->pos.y = y;
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
                phi_s6 = 10;
            }

            if (hitDepth < 1.0) {
                phi_s6 = 11;
            }
            npc->duration--;
            if (npc->duration <= 0) {
                phi_s6 = 20;
            }

            if (phi_s6 == 0) {
                if (enemy->varTable[1] & 1) {
                    npc->rotation.z += 40.0;
                }
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
                npc->pos.y += npc->jumpVelocity;
                npc->jumpVelocity -= npc->jumpScale;
            } else {
                fx_walking_dust(2, npc->pos.x, npc->pos.y, npc->pos.z, 0, 0);
                enemy->varTable[0] = 0;
                npc->pos.x = 0.0f;
                npc->pos.y = -1000.0f;
                npc->pos.z = 0.0f;
                npc->jumpVelocity = 0.0f;
                npc->flags |= NPC_FLAG_2;
                disable_npc_shadow(npc);
                npc->flags &= ~NPC_FLAG_JUMPING;
                enemy->flags |= ENEMY_FLAGS_10000000 | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_IGNORE_HAMMER |
                                ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_TOUCH;
                script->functionTemp[0] = 0;
            }
        }
    }
    return ApiStatus_BLOCK;
}
