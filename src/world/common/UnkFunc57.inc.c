#include "common.h"
#include "effects.h"

ApiStatus N(UnkFunc57)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc sp20;
    Npc* sp20Ptr = &sp20;
    s32 timer = 0;
    Npc* npc1 = get_npc_unsafe(enemy->npcID);
    Npc* npc2 = get_npc_unsafe(get_enemy(enemy->npcID - 1)->npcID);
    f32 t1;
    f32 t2;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc1->duration = 0;
        npc1->flags |= NPC_FLAG_200000 | NPC_FLAG_40000 | NPC_FLAG_100 |  NPC_FLAG_2;
        enemy->flags |= ENEMY_FLAGS_10000000 | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_IGNORE_JUMP |
                        ENEMY_FLAGS_200000 | ENEMY_FLAGS_40;
        npc1->scale.x = 0.4f;
        npc1->scale.y = 0.4f;
        if (enemy->unk_B0 & 4) {
            enemy->unk_B0 &= ~4;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            enemy->varTable[3] = NULL;
            npc1->collisionRadius = 20;
            npc1->collisionHeight = 20;
            npc1->pos.x = 0.0f;
            npc1->pos.z = 0.0f;
            npc1->pos.y = -1000.0f;
            enemy->varTable[0] = 0;
            script->functionTemp[0] = 1;
            /* fallthrough */
        case 1:
            if (enemy->varTable[0] == 1) {
                s32 duration;

                enemy->varTable[0] = 2;
                sp20Ptr->pos.x = npc2->pos.x;
                sp20Ptr->pos.y = npc2->pos.y;
                sp20Ptr->pos.z = npc2->pos.z;
                npc_move_heading(sp20Ptr, enemy->varTable[2], 270.0f - npc2->renderYaw);
                npc1->pos.x = sp20Ptr->pos.x;
                npc1->pos.y = npc2->pos.y + enemy->varTable[1];
                npc1->pos.z = sp20Ptr->pos.z;
                enemy->unk_07 = 1;
                enemy->unk_10.x = npc1->pos.x;
                enemy->unk_10.y = npc1->pos.y;
                enemy->unk_10.z = npc1->pos.z;
                npc1->moveSpeed = 3.6f;

                t1 = fabsf(npc1->pos.x - gPlayerStatusPtr->position.x);
                t2 = atan2(0.0f, npc1->pos.y, t1, (gPlayerStatusPtr->position.y + 10.0)) - 90.0;
                npc1->jumpVelocity = cosine(t2) * npc1->moveSpeed;
                npc1->yaw = atan2(npc1->pos.x, npc1->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                duration = dist3D(npc1->pos.x, npc1->pos.y, npc1->pos.z,
                                  gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.y + 10.0,
                                  gPlayerStatusPtr->position.z) / npc1->moveSpeed;
                if (duration <= 0) {
                    duration = 1;
                }
                enemy->varTable[3] = (s32)fx_shape_spell(0, npc1->pos.x, npc1->pos.y + 14.0f, npc1->pos.z,
                                                    gPlayerStatusPtr->position.x,
                                                    gPlayerStatusPtr->position.y + 10.0f + 14.0f,
                                                    gPlayerStatusPtr->position.z, duration);
                npc1->duration = duration;
                script->functionTemp[0] = 2;
            }
            break;
        case 2:
            npc1->duration--;
            if (npc1->duration <= 0) {
                timer = 20;
            }
            if (timer == 0) {
                npc_move_heading(npc1, npc1->moveSpeed, npc1->yaw);
                npc1->pos.y += npc1->jumpVelocity;
                break;
            }
            /* fallthrough */
        case 3:
            npc1->jumpVelocity = 0.0f;
            npc1->moveSpeed = 0.0f;
            npc1->pos.y -= npc1->collisionHeight * 0.5;
            enemy->varTable[0] = 3;
            npc1->duration = 0;
            script->functionTemp[0] = 4;
            break;
        case 4:
            npc1->duration++;
            if (npc1->duration < 7) {
                npc1->pos.y -= 3.5;
                npc1->collisionRadius = ((f32) npc1->duration * 7.0) + 20.0;
                npc1->collisionHeight = ((f32) npc1->duration * 7.0) + 20.0;
            } else if (npc1->duration == 7) {
                npc1->pos.x = 0.0f;
                npc1->pos.z = 0.0f;
                npc1->collisionRadius = 20;
                npc1->collisionHeight = 20;
                npc1->pos.y = -1000.0f;
            } else if (npc1->duration >= 16) {
                enemy->varTable[0] = 0;
                script->functionTemp[0] = 0;
            }
            break;
    }
    return ApiStatus_BLOCK;
}
