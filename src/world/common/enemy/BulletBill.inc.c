#include "common.h"
#include "effects.h"

ApiStatus N(BulletBill_Think)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *script->ptrReadPos);
    s32 hitDetected = FALSE;
    s32 done = FALSE;
    
    Npc* launcher;
    f32 nextX;
    f32 nextZ;
    f32 deltaY;
    
    if (isInitialCall || enemy->varTable[0] == 0x64) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        enemy->aiFlags |= ENEMY_AI_FLAGS_8;
        enemy->flags |= 0x200000;
        npc->flags |= 0x40000;
        enemy->varTable[0] = 0;
        enemy->varTable[1] = -1;
    }
    
    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->unk_B4 != 0) {
            return 0;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }

    switch (script->functionTemp[0]) {
        case 0:
            npc->pos.x = 0.0f;
            npc->pos.y = -1000.0f;
            npc->pos.z = 0.0f;
            npc->rotation.y = 0.0f;
            npc->duration = 0;
            npc->flags |= 2;
            npc->flags &= ~0x400;
            disable_npc_shadow(npc);
            enemy->varTable[0] = 0;
            script->functionTemp[0] = 1;
            // fallthrough
        case 1:
            if (enemy->varTable[0] != 2) {
                break;
            }
            enemy->varTable[0] = 3;
            launcher = get_npc_unsafe(get_enemy(enemy->varTable[1])->npcID);
            npc->flags &= -3;
            npc->pos.x = launcher->pos.x;
            npc->pos.y = launcher->pos.y + 11.0;
            npc->pos.z = launcher->pos.z + 1.0;
            npc->yaw = launcher->yaw;
            npc->moveSpeed = aiSettings->chaseSpeed;
            npc->currentAnim.w = enemy->animList[2];
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 25.0f, npc->yaw);
            if (npc->yaw < 180.0f) {
                npc->renderYaw = 180.0f;
            } else {
                npc->renderYaw = 0.0f;
            }
            npc->currentAnim.w = enemy->animList[3];
            npc->duration = 300;
            npc->flags |= 0x10400;
            enable_npc_shadow(npc);
            script->functionTemp[0] = 2;
            // fallthrough
        case 2:
            deltaY = (npc->pos.y - gPlayerStatusPtr->position.y);
            if (!(deltaY > 190.0) && !(deltaY < -120.0)) {
                nextX = npc->pos.x;
                nextZ = npc->pos.z;
                add_vec2D_polar(&nextX, &nextZ, npc->moveSpeed, npc->yaw);
                
                if (npc->yaw < 180.0f) {
                    if (enemy->varTable[2] <= nextX) {
                        hitDetected = TRUE;
                    }
                } else {
                    if (nextX <= enemy->varTable[2]) {
                        hitDetected = TRUE;
                    }
                }
                
                if (hitDetected) {
                    npc->currentAnim.w = enemy->animList[7];
                    ai_enemy_play_sound(npc, 0xB0000018, 0);
                    fx_ring_blast(0, npc->pos.x, npc->pos.y + 5.0f, npc->pos.z + 1.0f, 0.05f, 0x14);
                    fx_smoke_burst(0, npc->pos.x, npc->pos.y + 5.0f, npc->pos.z + 0.0f, 1.2f, 0x19);
                    npc->duration = 1;
                    script->functionTemp[0] = 3;
                } else {
                    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
                }
                if (script->functionTemp[0] == 3) {
                    npc->duration--;
                    if (npc->duration <= 0) {
                        done = TRUE;
                    }
                }
            } else {
                done = TRUE;
            }
            break;

        case 3:
            npc->duration--;
            if (npc->duration <= 0) {
                done = TRUE;
            }
            break;
    }
    if (done != 0) {
        enemy->varTable[0] = 0x64;
    }

    return ApiStatus_BLOCK;
}
