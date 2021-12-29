#include "common.h"
#include "npc.h"
#include "effects.h"

void N(UnkNpcAIFunc35)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 cond = FALSE;
    f32 vt7 = (f32)enemy->varTable[7] / 100.0;
    f32 vt3 = (f32)enemy->varTable[3] / 100.0;
    f32 vt4 = (f32)enemy->varTable[4] / 100.0;
    f32 vt1 = (f32)enemy->varTable[1] / 100.0;
    f32 posX, posY, posZ, posW;
    f32 temp_f24;
    
    enemy->varTable[4] = npc->pos.y * 100.0;
    
    temp_f24 = vt3 + vt7;

    if ((enemy->varTable[0] & 0x11) == 1) {
        if (npc->flags & 8) {
            if (vt1 < temp_f24 - npc->pos.y) {
                enemy->varTable[0] |= 0x10;
            }
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
            if (vt1 < (vt3 - posW)) {
                enemy->varTable[0] |= 0x10;
            }
        }
    }
    
    if ((enemy->varTable[0] & 0x11) == 0x11) {
        f64 test;
        f32 yTemp;

        do {
            if (npc->flags & 8) {
                yTemp = temp_f24;
                test = vt4 + ((temp_f24 - vt4) * 0.09);
                npc->pos.y = test;
            } else {
                posX = npc->pos.x;
                posY = vt4;
                posZ = npc->pos.z;
                posW = 1000.0f;
                npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);

                yTemp = posY;
                yTemp += vt3;
                test = vt4 + ((yTemp - vt4) * 0.09);
                npc->pos.y = test;
            }

            if (fabsf(yTemp - npc->pos.y) < 1.0) {
                npc->pos.y = yTemp;
                enemy->varTable[0] &= ~0x10;
            }
        } while (0); // required to match
    } else {
        f32 vt1temp = vt1; // required to match

        if (enemy->varTable[1] > 0) {
            f32 sinTemp = sin_deg(enemy->varTable[2]);
            s32 hit;

            if (npc->flags & 8) {
                hit = FALSE;
            } else {
                posX = npc->pos.x;
                posY = npc->pos.y;
                posZ = npc->pos.z;
                posW = 1000.0f;
                hit = npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
            }

            if (hit) {
                npc->pos.y = posY + vt3 + (sinTemp * vt1temp);
            } else {
                npc->pos.y = temp_f24 + (sinTemp * vt1temp);
            }

            enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
        }
    }

    if (enemy->varTable[9] <= 0) {
        if (aiSettings->unk_14 >= 0) {
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[1] = aiSettings->unk_14;
                if (gPlayerStatusPtr->position.y < (npc->pos.y + npc->collisionHeight) + 10.0 && 
                    func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0) != 0) 
                {
                    s32 emoteTemp;

                    fx_emote(0, npc, 0, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xC, &emoteTemp);
                    npc->moveToPos.y = npc->pos.y;
                    ai_enemy_play_sound(npc, 0x2F4, 0x200000);
                    
                    if (enemy->npcSettings->unk_2A & 1) {
                        script->functionTemp[0] = 10;
                    } else {
                        script->functionTemp[0] = 12;
                    }
                    return;
                }
            }
            script->functionTemp[1]--;
        }
    } else {
        enemy->varTable[9]--;
    }
    
    if (is_point_within_region(enemy->territory->wander.wanderShape, 
                               enemy->territory->wander.point.x, 
                               enemy->territory->wander.point.z,
                               npc->pos.x, npc->pos.z,
                               enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        posW = dist2D(enemy->territory->wander.point.x, enemy->territory->wander.point.z, npc->pos.x, npc->pos.z);
        if (npc->moveSpeed < posW) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
            cond = TRUE;
        }
    }

    if (enemy->territory->wander.wanderSizeX | enemy->territory->wander.wanderSizeZ | cond) {
        if (npc->turnAroundYawAdjustment != 0) {
            return;
        }
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }

    enemy->varTable[4] = npc->pos.y * 100.0;
    if (aiSettings->moveTime > 0) {
        if ((npc->duration <= 0) || (--npc->duration <= 0)) {
            script->functionTemp[0] = 2;
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            if (aiSettings->unk_2C <= 0 || aiSettings->waitTime <= 0 || script->functionTemp[1] < 3) {
                script->functionTemp[0] = 0;
            }
        }
    }
}
