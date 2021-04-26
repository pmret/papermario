#include "flo_17.h"

INCLUDE_ASM(s32, "world/area_flo/flo_17/CD7350", func_80240070_CD7350);
/*
void N(func_80240070_CD7350)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = aiSettings->moveTime / 2 + rand_int(aiSettings->moveTime / 2 + 1);
    if (is_point_within_region(enemy->territory->wander.wanderShape,
            enemy->territory->wander.point.x, enemy->territory->wander.point.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    } else {
        npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    }
    npc->currentAnim = enemy->animList[1];
    script->functionTemp[1].s = 0;
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[0].s = 1;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_17/CD7350", func_80240220_CD7500);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_17/CD7350", func_80240CC4_CD7FA4);
/*
void N(func_80240CC4_CD7FA4)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_8024440C_CDB6EC)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0].s = 12;
    }
}
*/

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_17/CD7350", func_8024137C_CD865C);
/*
ApiStatus N(func_8024137C_CD865C)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(func_80241258_CD8538)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240070_CD7350)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80240220_CD7500)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_80240908_CD7BE8)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80240CC4_CD7FA4)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_80240EC8_CD81A8)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_17/CD7350", func_80241568_CD8848);

INCLUDE_ASM(s32, "world/area_flo/flo_17/CD7350", func_802415B0_CD8890);
/*
void N(func_802415B0_CD8890)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    s32 var;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 var1 = enemy->varTable[4];
    f32 var2 = enemy->varTable[3];
    f32 var3;

    temp_f22 = var1 / 100.0;
    temp_f24 = var2 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var3 = enemy->varTable[1];
    temp_f20 = var3 / 100.0;

    x = npc->pos.x;
    y = npc->pos.y;
    z = npc->pos.z;
    w = 1000.0f;

    func_800DCB7C(npc->unk_80, &x, &y, &z, &w);
    npc->pos.y = y + temp_f24 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 0xC);

    if (aiSettings->unk_14 >= 0) {
        if (script->functionTemp[1].s <= 0) {
            script->functionTemp[1].s = aiSettings->unk_14;
            if (func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0) != 0) {
                fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
                func_800494C0(npc, 0x2F4, 0x200000);
                x = npc->pos.x;
                y = npc->pos.y;
                z = npc->pos.z;
                w = 1000.0f;
                func_800DCB7C(npc->unk_80, &x, &y, &z, &w);
                npc->moveToPos.y = y + temp_f24;
                script->functionTemp[0].s = 12;
                return;
            }
        }
        script->functionTemp[1].s--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape, enemy->territory->wander.point.x, enemy->territory->wander.point.z, npc->pos.x, npc->pos.z, enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ) != 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    }

    if (npc->turnAroundYawAdjustment == 0) {
        if (npc->duration > 0) {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (enemy->varTable[0] & 1) {
                x = npc->pos.x;
                y = temp_f22;
                z = npc->pos.z;
                w = 1000.0f;
                func_800DCB7C(npc->unk_80, &x, &y, &z, &w);
                y += temp_f24;
                w = y - temp_f22;
                if (w > 2.0) {
                    temp_f22 += 2.0;
                } else if (w < -2.0) {
                    temp_f22 -= 2.0;
                } else {
                    temp_f22 = y;
                }
                enemy->varTable[4] = (temp_f22 * 100.0);
            }
            if (npc->duration > 0) {
                return;
            }
        }
        script->functionTemp[0].s = 2;
        script->functionTemp[1].s = (rand_int(1000) % 3) + 2;
        if ((aiSettings->unk_2C <= 0) || (aiSettings->moveTime <= 0) || (script->functionTemp[1].s == 0)) {
            script->functionTemp[0].s = 0;
        }
    }
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_17/CD7350", func_80241A14_CD8CF4);
/*
void N(func_80241A14_CD8CF4)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    s32 var;
    f32 var1 = enemy->varTable[3];
    f32 var2;
    f32 temp_f20;
    f32 temp_f22;

    temp_f22 = var1 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var2 = enemy->varTable[1];
    temp_f20 = var2 / 100.0;

    x = npc->pos.x;
    y = npc->pos.y;
    z = npc->pos.z;
    w = 1000.0f;

    func_800DCB7C(npc->unk_80, &x, &y, &z, &w);
    npc->pos.y = y + temp_f22 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 0xC);
    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1) != 0) {
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
        func_800494C0(npc, 0x2F4, 0x200000);
        script->functionTemp[0].s = 12;
        return;
    }

    if ((npc->turnAroundYawAdjustment == 0) && (npc->duration <= 0)) {
        script->functionTemp[1].s--;
        if (script->functionTemp[1].s > 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = (rand_int(1000) % 11) + 5;
            return;
        }
        script->functionTemp[0].s = 0;
    }
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_17/CD7350", func_80241C64_CD8F44);
/*
// enemy2 is being copied to a0
#ifdef NON_MATCHING
ApiStatus N(func_80241C64_CD8F44)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);
    f32 temp_f4;
    f32 dist;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, aiSettings);
        script->functionTemp[0].s = 0;
    }
    npc->unk_AB = -3;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }


    switch (script->functionTemp[0].s) {
        case 0:
            N(func_802401C4_CC39D4)(script, aiSettings, territoryPtr);

        case 1:
            N(func_80241704_CC4F14)(script, aiSettings, territoryPtr);
            break;

        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);

        case 3:
            N(func_80241B68_CC5378)(script, aiSettings, territoryPtr);
            break;
    }

    if (script->functionTemp[0].s == 12) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        enemy->varTable[4] = N(func_802416BC_CC4ECC)();
        if (enemy->varTable[4] >= 0) {
            Enemy* enemy2 = get_enemy(enemy->varTable[4]);
            enemy2->varTable[10] = 1;
            enemy2->varTable[11] = enemy->npcID;
            npc->duration = 15;
            npc->currentAnim = 0x490014;
            script->functionTemp[0].s = 30;
        }
    }

    switch (script->functionTemp[0].s) {
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);

        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;

        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            break;
    }

    switch (script->functionTemp[0].s) {
        case 30:
            npc->duration--;
            if (npc->duration <= 0) {
                get_enemy(enemy->varTable[4])->varTable[10] = 2;
                npc->duration = 5;
                script->functionTemp[0].s = 31;
            }

        case 31:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->currentAnim = 0x490015;
                get_enemy(enemy->varTable[4])->varTable[10] = 3;
                npc->duration = 10;
                script->functionTemp[0].s = 32;
            }

        case 32:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->duration = 3;
                script->functionTemp[0].s = 33;
            }

        case 33:
            npc->duration--;
            if (npc->duration <= 0) {
                script->functionTemp[0].s = 0;
            }
            break;
    }

    if (((u32)script->functionTemp[0].s - 30) < 2) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        dist = dist2D(gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z, npc->pos.x, npc->pos.z);
        if (!is_point_within_region(territoryPtr->shape, territoryPtr->pointX, territoryPtr->pointZ, npc->pos.x, npc->pos.z, territoryPtr->sizeX, territoryPtr->sizeZ)) {
            if ((dist > 30.0) && (npc->turnAroundYawAdjustment == 0)) {
                temp_f4 = dist - 20.0;
                if (temp_f4 < 0.0) {
                    temp_f4 = 0.0f;
                }
                if (temp_f4 > 200.0) {
                    temp_f4 = 200.0f;
                }
                npc->moveSpeed = update_lerp(0, aiSettings->moveSpeed, aiSettings->chaseSpeed, temp_f4, 200);
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            }
        }
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(ApiStatus, "world/area_flo/flo_17/CD7350", flo_17_func_80241C64_CD8F44, ScriptInstance *script, s32 isInitialCall);
#endif
*/

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_17/CD7350", func_802421C0_CD94A0);
/*
void N(func_802421C0_CD94A0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if ((npc->duration <= 0) || (--npc->duration <= 0)) {
        if (npc->turnAroundYawAdjustment == 0) {
            npc->currentAnim = enemy->animList[9];
            npc->moveSpeed = aiSettings->chaseSpeed;
            if ((enemy->varTable[7] == 5) || (enemy->varTable[7] == 0) || (enemy->varTable[7] == 1)) {
                npc->collisionHeight = enemy->varTable[6] / 2;
            }
            npc->duration = (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) / npc->moveSpeed) + 0.8;
            if (npc->duration < enemy->varTable[3]) {
                npc->duration = enemy->varTable[3];
            }
            enemy->varTable[4] = npc->duration;
            script->functionTemp[0].s = 14;
        }
    }
}
*/

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_17/CD7350", func_802424D8_CD97B8);

INCLUDE_ASM(s32, "world/area_flo/flo_17/CD7350", func_80242918_CD9BF8);
/*
ApiStatus N(func_80242918_CD9BF8)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);
    s32 var;
    u32 x, y, z;
    f32 x2, y2, z2, w2;
    Npc* npc2;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->unk_B0 |= 8;
    }

    if (isInitialCall || (enemy->varTable[10] == 100)) {
        script->functionTemp[0].s = 100;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        enemy->flags |= 0x200000;
        npc->flags = (npc->flags & ~0x200) | 8;
        enemy->varTable[10] = 0;
        enemy->varTable[11] = -1;
        npc->pos.x = 0.0f;
        npc->pos.y = -1000.0f;
        npc->pos.z = 0.0f;
    }

    if (enemy->unk_B0 & 4) {
        npc->duration = 0;
        npc->collisionHeight = enemy->varTable[6];
        enemy->unk_B0 &= ~4;
        if (npc->flags & 0x800) {
            npc->currentAnim = 0x4A0018;
            npc->moveSpeed = 0.0f;
            npc->jumpVelocity = 0.0f;
            npc->jumpScale = 1.0f;
            script->functionTemp[0].s = 102;
        } else {
            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0x28, &var);
            npc->currentAnim = enemy->animList[0];
            script->functionTemp[1].s = 0;
            script->functionTemp[0].s = 200;
        }
    }
    get_screen_coords(0, npc->pos.x, npc->pos.y, npc->pos.z, &x, &y, &z);
    if ((script->functionTemp[0].s < 100) && ((x + 50) >= 421)) {
        script->functionTemp[0].s = 110;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            func_800495A0(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
            if (enemy->varTable[13] != 0) {
                if (npc->pos.y <= 0.0) {
                    npc->flags = (npc->flags & ~0x200) | 8;
                } else {
                    npc->flags = (npc->flags | 0x200) & ~8;
                }
            }
            func_800496B8(script, aiSettings, territoryPtr);
            break;

        case 1:
            func_800496B8(script, aiSettings, territoryPtr);
            break;

        case 2:
            base_UnkNpcAIFunc1(script, aiSettings, territoryPtr);

        case 3:
            func_80049C04(script, aiSettings, territoryPtr);
            break;

        case 12:
            N(set_script_owner_npc_anim)(script, aiSettings, territoryPtr);
        
        case 13:
            N(func_802421C0_CD94A0)(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
            break;

        case 14:
            N(UnkNpcAIFunc12)(script, aiSettings, territoryPtr);
            break;

        case 15:
            N(set_script_owner_npc_col_height)(script, aiSettings, territoryPtr);
            break;

        case 100:
            if (enemy->varTable[10] != 2) {
                break;
            }
            npc2 = get_npc_unsafe(get_enemy(enemy->varTable[11])->npcID);
            if (npc2->yaw < 180.0) {
                npc->pos.x = npc2->pos.x + 12.0;
            } else {
                npc->pos.x = npc2->pos.x - 12.0;
            }
            npc->pos.y = npc2->pos.y + 25.0;
            npc->pos.z = npc2->pos.z + 1.0;
            npc->rotation.y = 0.0f;
            npc->flags |= 8;
            npc->flags &= ~2;
            npc->flags &= ~0x200;
            npc->renderYaw = 0.0f;
            npc->currentAnim = 0x4A0018;
            script->functionTemp[0].s = 101;

        case 101:
            if (enemy->varTable[10] != 3) {
                break;
            }
            enemy->varTable[10] = 4;
            npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
            npc->moveSpeed = 2.5f;
            npc->jumpVelocity = 8.0f;
            npc->jumpScale = 0.8f;
            npc->flags |= 0x800;
            script->functionTemp[0].s = 102;

        case 102:
            if (npc->moveSpeed > 0.0) {
                x2 = npc->pos.x;
                y2 = npc->pos.y;
                z2 = npc->pos.z;
                if (func_800DDC44(npc->unk_80, &x2, &y2, &z2, npc->moveSpeed, npc->yaw, npc->collisionHeight, npc->collisionRadius) == 0) {
                    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
                } else {
                    npc->moveSpeed = 0.0f;
                }
            }
            

            if (npc->jumpVelocity < 0.0) {
                x2 = npc->pos.x;
                y2 = npc->pos.y + 13.0;
                z2 = npc->pos.z;
                w2 = fabsf(npc->jumpVelocity) + 16.0;
                if ((func_800DCB7C(npc->unk_80, &x2, &y2, &z2, &w2) != 0) && (w2 <= (fabsf(npc->jumpVelocity) + 13.0))) {
                    npc->pos.y = y2;
                    enemy->territory->wander.point.x = npc->pos.x;
                    enemy->territory->wander.point.y = npc->pos.y;
                    enemy->territory->wander.point.z = npc->pos.z;
                    enemy->territory->wander.detect.x = npc->pos.x;
                    enemy->territory->wander.detect.y = npc->pos.y;
                    enemy->territory->wander.detect.z = npc->pos.z;
                    enemy->varTable[10] = 5;
                    if (enemy->varTable[13] != 0) {
                        if (npc->pos.y <= 0.0) {
                            npc->flags = (npc->flags & ~0x200) | 8;
                        } else {
                            npc->flags = (npc->flags | 0x200) & ~8;
                        }
                    } else if (!enemy->territory->wander.isFlying) {
                        npc->flags = (npc->flags | 0x200) & ~8;
                    } else {
                        npc->flags = (npc->flags & ~0x200) | 8;
                    }
                    npc->flags = (npc->flags | 0x40000) & ~0x800;
                    npc->jumpVelocity = 0.0f;
                    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                    npc->currentAnim = 0x4A001A;
                    npc->duration = 3;
                    script->functionTemp[0].s = 103;
                    break;
                }
            }
            npc->pos.y += npc->jumpVelocity;
            npc->jumpVelocity -= npc->jumpScale;
            break;

        case 103:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->flags &= 0xFFFBFFFF;
                npc->currentAnim = 0x4A0001;
                script->functionTemp[0].s = 0;
            }
            break;

        case 110:
            npc->duration = 30;
            npc->pos.x = 0.0f;
            npc->pos.z = 0.0f;
            npc->pos.y = -1000.0f;
            npc->flags = (npc->flags | 0xA) & ~0x200;
            script->functionTemp[0].s = 111;

        case 111:
            npc->duration--;
            if (npc->duration <= 0) {
                enemy->varTable[10] = 0;
                script->functionTemp[0].s = 100;
            }
            break;

        case 200:
            func_8004A73C(script);
            break;

    }
    return ApiStatus_BLOCK;
}
*/
