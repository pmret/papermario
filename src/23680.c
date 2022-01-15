#include "common.h"
#include "npc.h"
#include "effects.h"

INCLUDE_ASM(s32, "23680", spawn_drops);

s32 get_coin_drop_amount(Enemy* enemy) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    EnemyDrops* enemyDrops = enemy->drops;
    s32 maxCoinBonus = enemyDrops->maxCoinBonus;
    s32 amt = enemyDrops->minCoinBonus;
    s32 minTemp = enemyDrops->minCoinBonus;

    if (maxCoinBonus < amt) {
        amt = enemyDrops->maxCoinBonus;
        maxCoinBonus = enemyDrops->minCoinBonus;
    }

    minTemp = maxCoinBonus - amt;
    if ((amt < 0) || (minTemp != 0)) {
        amt = rand_int(minTemp) - -amt;
    }

    if (amt < 0) {
        amt = 0;
    }

    if (is_ability_active(ABILITY_PAY_OFF)) {
        amt += currentEncounter->damageTaken / 2;
    }

    if (currentEncounter->merleeCoinBonus) {
        amt *= 3;
    }

    if (is_ability_active(ABILITY_MONEY_MONEY)) {
        amt *= 2;
    }

    amt += currentEncounter->coinsEarned;

    if (enemy->flags & (ENEMY_FLAGS_800000 | ENEMY_FLAGS_40000)) {
        amt = 0;
    }

    if (amt > 20) {
        amt = 20;
    }

    return amt;
}

void func_80048E34(Enemy* enemy, s32 arg1, s32 arg2) {
    Evt* newScript;

    if (enemy->aiScript != NULL) {
        kill_script_by_ID(enemy->aiScriptID);
        enemy->aiScript = NULL;
    }

    if (enemy->unk_BC != 0) {
        kill_script_by_ID(enemy->unk_C0);
        enemy->unk_BC = NULL;
    }

    if (enemy->aiBytecode != NULL) {
        enemy->unk_C8 = arg2;
        newScript = start_script(enemy->aiBytecode, 10, 0x20);
        enemy->aiScript = newScript;
        enemy->aiScriptID = newScript->id;
        newScript->owner2.npcID = enemy->npcID;
        newScript->owner1.enemy = enemy;
    }

    if (enemy->unk_B8 != NULL) {
        enemy->unk_C4 = arg1;
        newScript = start_script(enemy->unk_B8, 10, 0x20);
        enemy->unk_BC = newScript;
        enemy->unk_C0 = newScript->id;
        newScript->owner2.npcID = enemy->npcID;
        newScript->owner1.enemy = enemy;
    }
}

s32 func_80048F0C(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounter->numEncounters; i++) {
        Encounter* encounter = currentEncounter->encounterList[i];

        if (encounter != NULL) {
            for (j = 0; j < encounter->count; j++) {
                Enemy* enemy = encounter->enemy[j];

                if (enemy != NULL && !(enemy->flags & ENEMY_FLAGS_20)) {
                    get_npc_unsafe(enemy->npcID);
                }
            }
        }
    }

    return 0;
}

s32 is_point_within_region(s32 shape, f32 pointX, f32 pointY, f32 centerX, f32 centerY, f32 sizeX, f32 sizeZ) {
    f32 dist1;
    f32 dist2;

    switch (shape) {
        case 0:
            dist1 = dist2D(pointX, pointY, centerX, centerY);
            return (sizeX < dist1);
        case 1:
            dist1 = dist2D(pointX, 0, centerX, 0);
            dist2 = dist2D(0, pointY, 0, centerY);
            return ((sizeX < dist1) || (sizeZ < dist2));
        default:
            return FALSE;
    }
}

INCLUDE_ASM(s32, "23680", func_800490B4, EnemyTerritoryThing* arg0, Enemy* arg1, f32 arg2, f32 arg3, s32 arg4);

s32 func_800493EC(Enemy* enemy, s32 arg1, f32 arg2, f32 arg3) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (arg1 >= 0) {
        s32 temp;

        if (arg1 != 0) {
            temp = rand_int(arg1 + 1);
        } else {
            temp = 0;
        }

        if (temp == 0) {
            f32 f1 = npc->pos.x;
            f32 f2 = npc->pos.z;

            add_vec2D_polar(&f1, &f2, arg3, 270.0f - npc->renderYaw);

            if (dist2D(f1, f2, playerStatus->position.x, playerStatus->position.z) <= arg2) {
                return 1;
            }
        }
    }

    return 0;
}

void ai_enemy_play_sound(Npc* npc, s32 arg1, s32 arg2) {
    Enemy* enemy = get_enemy(npc->npcID);
    s32 value2 = (arg2 & 0xFFFF0000) | 2;

    if (arg2 & 1) {
        value2 |= 0x10000;
    }

    if (enemy->npcSettings->unk_2A & 0x20) {
        value2 |= 0x20000;
    }

    sfx_play_sound_at_position(arg1, value2, npc->pos.x, npc->pos.y, npc->pos.z);
}

void func_80049550(Evt* script, s32 arg1) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = arg1;
    }
}

void func_800495A0(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = (npcAISettings->moveTime / 2) + rand_int((npcAISettings->moveTime / 2) + 1);
    npc->yaw = clamp_angle(npc->yaw + rand_int(60) - 30.0f);
    npc->currentAnim.w = enemy->animList[1];
    script->functionTemp[1] = 0;

    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = npcAISettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }

    enemy->unk_B0 &= ~0x40;
    enemy->unk_B0 &= ~0x20;
    script->functionTemp[0] = 1;
}

INCLUDE_ASM(s32, "23680", func_800496B8);

#define NAMESPACE base
#include "world/common/UnkNpcAIFunc1.inc.c"

void func_80049C04(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z;
    f32 yaw;
    s32 sp34;

    if (aiSettings->unk_14 >= 0 && func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        x = npc->pos.x;
        y = npc->pos.y;
        z = npc->pos.z;
        yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        if (!npc_test_move_simple_with_slipping(npc->collisionChannel, &x, &y, &z, aiSettings->chaseSpeed, yaw, npc->collisionHeight, npc->collisionRadius)) {
            npc->yaw = yaw;
            ai_enemy_play_sound(npc, 0x2F4, 0x200000);
            fx_emote(0, npc, 0, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &sp34);
            if (enemy->npcSettings->unk_2A & 1) {
                script->functionTemp[0] = 10;
            } else {
                script->functionTemp[0] = 12;
            }
            return;
        }
    }
    if (npc->turnAroundYawAdjustment == 0) {
        npc->duration--;
        if (npc->duration <= 0) {
            script->functionTemp[1]--;
            if (script->functionTemp[1]) {
                if (!(enemy->npcSettings->unk_2A & 0x10)) {
                    npc->yaw = clamp_angle(npc->yaw + 180.0f);
                }
                npc->duration = (aiSettings->waitTime / 2) + rand_int(aiSettings->waitTime / 2 + 1);
                return;
            }
            script->functionTemp[0] = 0;
        }
    }
}

void func_80049E3C(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    ai_enemy_play_sound(npc, 0x3E1, 0);
    npc->currentAnim.w = enemy->animList[4];
    npc->jumpVelocity = 10.0f;
    npc->jumpScale = 2.5f;
    npc->moveToPos.y = npc->pos.y;
    npc->flags |= 0x800;
    script->functionTemp[0] = 11;
}

void func_80049ECC(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    s32 flag = FALSE;

    if (npc->jumpVelocity <= 0.0) {
        if (npc->pos.y <= npc->moveToPos.y) {
            npc->pos.y = npc->moveToPos.y;
            flag = TRUE;
        }
    }

    if (!flag) {
        npc->pos.y += npc->jumpVelocity;
        npc->jumpVelocity -= npc->jumpScale;
    } else {
        npc->jumpVelocity = 0.0f;
        npc->flags &= ~0x800;
        script->functionTemp[0] = 12;
    }
}

void func_80049F7C(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 cond = FALSE;

    if ((gPlayerStatusPtr->actionState == ACTION_STATE_JUMP || gPlayerStatusPtr->actionState == ACTION_STATE_BOUNCE ||
        gPlayerStatusPtr->actionState == ACTION_STATE_HOP || gPlayerStatusPtr->actionState == ACTION_STATE_FALLING) &&
        (f64)dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) < npc->collisionRadius)
    {
        cond = TRUE;
    }

    if (!cond) {
        f32 yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        f32 angleDiff = get_clamped_angle_diff(npc->yaw, yaw);
        s32 temp_f4 = npcAISettings->unk_1C.s;

        if (temp_f4 < fabsf(angleDiff)) {
            yaw = npc->yaw;
            if (angleDiff < 0.0f) {
                yaw += -npcAISettings->unk_1C.s;
            } else {
                yaw += temp_f4;
            }
        }
        npc->yaw = clamp_angle(yaw);
        npc->duration = (npcAISettings->unk_20 / 2) + rand_int((npcAISettings->unk_20 / 2) + 1);
    } else {
        npc->duration = 0;
    }

    npc->currentAnim.w = enemy->animList[3];
    npc->moveSpeed = npcAISettings->chaseSpeed;
    script->functionTemp[0] = 13;
}

void func_8004A124(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 sp28;
    f32 x, y, z;

    if (!func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        fx_emote(2, npc, 0, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &sp28);
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = 20;
        script->functionTemp[0] = 14;
        return;
    }

    if (enemy->npcSettings->unk_2A & 4) {
        if (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) > (npc->moveSpeed * 5.0)) {
            x = npc->pos.x;
            y = npc->pos.y;
            z = npc->pos.z;
            if (npc_test_move_simple_with_slipping(npc->collisionChannel, &x, &y, &z, 1.0f, npc->yaw, npc->collisionHeight, npc->collisionRadius)) {
                fx_emote(2, npc, 0, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xC, &sp28);
                npc->currentAnim.w = enemy->animList[0];
                npc->duration = 15;
                script->functionTemp[0] = 14;
                return;
            }
        }
    }

    func_8003D660(npc, 1);
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    if (npc->moveSpeed > 8.0 && !(gGameStatusPtr->frameCounter % 5)) {
        ai_enemy_play_sound(npc, 0x20C1, 0);
    }

    if (npc->duration > 0) {
        npc->duration--;
    } else {
        script->functionTemp[0] = 12;
    }
}

void func_8004A3E8(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        npc->yaw = clamp_angle(atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x,
                                     enemy->territory->wander.point.z));
        script->functionTemp[0] = 0;
    }
}

ApiStatus DoBasicAI(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* pTerritory = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*) evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;


    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;

        npc->currentAnim.w = enemy->animList[0];

        npc->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;
        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
        }

        enemy->unk_B0 &= ~4;
        enemy->flags &= ~ENEMY_FLAGS_40000000;
    }

    switch (script->functionTemp[0]) {
        case 0x0:
            func_800495A0(script, aiSettings, pTerritory);
            /* fallthrough */
        case 0x1:
            func_800496B8(script, aiSettings, pTerritory);
            break;
        case 0x2:
            base_UnkNpcAIFunc1(script, aiSettings, pTerritory);
            /* fallthrough */
        case 0x3:
            func_80049C04(script, aiSettings, pTerritory);
            break;
        case 0xA:
            func_80049E3C(script, aiSettings, pTerritory);
            /* fallthrough */
        case 0xB:
            func_80049ECC(script, aiSettings, pTerritory);
            break;
        case 0xC:
            func_80049F7C(script, aiSettings, pTerritory);
            /* fallthrough */
        case 0xD:
            func_8004A124(script, aiSettings, pTerritory);
            if (script->functionTemp[0] != 0xE) {
                break;
            }
            /* fallthrough */
        case 0xE:
            func_8004A3E8(script, aiSettings, pTerritory);
            break;
        case 0x63:
            func_8004A73C(script);
            break;
    }
    return ApiStatus_BLOCK;
}
