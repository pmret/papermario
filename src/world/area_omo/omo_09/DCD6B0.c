#include "omo_09.h"

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_802409E0_DCD6B0);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80240A50_DCD720);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80240B20_DCD7F0);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80240BB8_DCD888);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80240C18_DCD8E8);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80240F4C_DCDC1C);
/*
s32 N(func_80240F4C_DCDC1C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    f32 ret;
    f32 max;
    f32 posX;
    f32 posZ;
    s32 i;
    s32 j;

    script->functionTemp[1].s = 0;
    max = 32767.0f;
    posX = npc->pos.x;
    posZ = npc->pos.z;
    script->functionTemp[2].s = 0;

    for (i = 0, j = 0; i < enemy->territory->patrol.numPoints; i++, j++) {
        ret = dist2D(posX, posZ, i[enemy->territory->patrol.points].x, i[enemy->territory->patrol.points].z);
        if (ret < max) {
            max = ret;
            script->functionTemp[2].s = j;
        }
    }

    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }

    script->functionTemp[0].s = 1;
    return 1;
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_802410A4_DCDD74);
/*
void N(func_802410A4_DCDD74)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, z;
    s32 var;

    if (aiSettings->unk_14 >= 0) {
        if (script->functionTemp[1].s <= 0) {
            script->functionTemp[1].s = aiSettings->unk_14;
            if (func_800490B4(shape, enemy, aiSettings->alertRadius, aiSettings->unk_10.s, 0)) {
                fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
                func_800494C0(npc, 0x2F4, 0x200000);
                if (enemy->npcSettings->unk_2A & 1) {
                    script->functionTemp[0].s = 10;
                } else {
                    script->functionTemp[0].s = 12;
                }
                return;
            }
        }
        script->functionTemp[1].s--;
    }

    if (npc->unk_8C == 0) {
        if (npc->moveSpeed < 4.0) {
            func_8003D660(npc, 0);
        } else {
            func_8003D660(npc, 1);
        }
        
        x = script->functionTemp[2].s[enemy->territory->patrol.points].x;
        z = script->functionTemp[2].s[enemy->territory->patrol.points].z;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, x, z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (dist2D(npc->pos.x, npc->pos.z, x, z) <= npc->moveSpeed) {
            script->functionTemp[0].s = 2;
            script->functionTemp[1].s = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->moveTime <= 0) || 
                (aiSettings->waitTime <= 0) || (script->functionTemp[1].s == 0)) {
                script->functionTemp[0].s = 4;
            }
            if (rand_int(10000) % 100 < aiSettings->moveTime) {
                script->functionTemp[0].s = 4;
            }
        }
    }
}
*/

#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_8024140C_DCE0DC);
/*
void N(func_8024140C_DCE0DC)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if ((aiSettings->unk_14 >= 0) && func_800490B4(shape, enemy, aiSettings->chaseRadius, aiSettings->unk_28.s, 0)) {
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        func_800494C0(npc, 0x2F4, 0x200000);
        if (!(enemy->npcSettings->unk_2A & 1)) {
            script->functionTemp[0].s = 12;
        } else {
            script->functionTemp[0].s = 10;
        }
    } else if (npc->unk_8C == 0) {
        npc->duration--;
        if (npc->duration == 0) {
            script->functionTemp[1].s--;
            if (script->functionTemp[1].s != 0) {
                if (!(enemy->npcSettings->unk_2A & 0x10)) {
                    npc->yaw = clamp_angle(npc->yaw + 180.0f);
                }
                npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
            } else {
                script->functionTemp[0].s = 4;
            }
        }
    }
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_802415C8_DCE298);
/*
s32 N(func_802415C8_DCE298)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    script->functionTemp[2].s++;
    if (script->functionTemp[2].s >= enemy->territory->patrol.numPoints) {
        script->functionTemp[2].s = 0;
    }
    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }
    script->functionTemp[0].s = 1;
    return 1;
}
*/

#include "world/common/NpcJumpFunc2.inc.c"

# include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80241898_DCE568);
/*
s32 N(func_80241898_DCE568)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (!func_800490B4(shape, enemy, aiSettings->chaseRadius, aiSettings->unk_28.s, 1)) {
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
        npc->currentAnim = enemy->animList[0];
        npc->duration = 25;
        script->functionTemp[0].s = 14;
    } else {
        func_8003D660(npc, 1);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (npc->duration > 0) {
            npc->duration--;
        } else {
            script->functionTemp[0].s = 12;
        }
    }
}
*/

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80241A20_DCE6F0);
/*
void N(func_80241A20_DCE6F0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 i;

    for (i = script->functionTemp[2].s; i < enemy->territory->patrol.numPoints; i++) {
        if (i[enemy->territory->patrol.points].y <= npc->pos.y) {
            script->functionTemp[2].s = i;
            break;
        }
    }

    npc->moveSpeed = aiSettings->moveSpeed;
    npc->currentAnim = enemy->animList[1];
    script->functionTemp[1].s = 0;
    script->functionTemp[0].s = 1;
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80241AE0_DCE7B0);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80241DDC_DCEAAC);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80241E4C_DCEB1C);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80241F1C_DCEBEC);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80241FB4_DCEC84);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80242014_DCECE4);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80242358_DCF028);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80242548_DCF218);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_8024268C_DCF35C);

#include "world/common/UnkSetDurationFunc.inc.c"

#include "world/common/UnkNpcAIFunc9.inc.c"

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_802428B4_DCF584);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_80242DF0_DCFAC0);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_8024324C_DCFF1C);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_8024356C_DD023C);

#include "world/common/GetEncounterEnemyIsOwner.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_802435B8_DD0288);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_802435CC_DD029C);

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCD6B0", func_802435E8_DD02B8);