#include "mac_05.h"

#define UNK_ALPHA_FUNC_NPC 6

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_8024030C_85247C);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_8024047C_8525EC);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80240490_852600);
/*
s32 N(func_80240490_852600)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_802405E8_852758);
/*
void N(func_802405E8_852758)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80240950_852AC0);
/*
void N(func_80240950_852AC0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80240B0C_852C7C);
/*
s32 N(func_80240B0C_852C7C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80240DDC_852F4C);
/*
s32 N(func_80240DDC_852F4C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80240F64_8530D4);
/*
void N(func_80240F64_8530D4)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80241024_853194);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80241320_853490);
/*
s32 N(func_80241320_853490)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    s32** ptr = &D_80241C68_BE09F8;
    s32 i;
    s32* test;

    if (*ptr == NULL) {
        i = heap_malloc(16 * sizeof(s32));
        *ptr = i;
        for (i = 0, test = *ptr; i < 16; i++) {
            *test++ = script->varTable[i];
        }
    } else {
        for (i = 0, test = *ptr; i < 16; i++) {
            script->varTable[i] = *test++;
        }
        ptr = &D_80241C68_BE09F8;
        heap_free(*ptr);
        *ptr = NULL;
    }
    return 2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_8024145C_8535CC);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80241680_8537F0);

#include "world/common/GetNpcUnsafeOwner2.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_802416EC_85385C);

#include "world/common/UnkAlphaFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80241898_853A08);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80241A0C_853B7C);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80241A90_853C00);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80241CA8_853E18);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80241D5C_853ECC);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80241D90_853F00);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80241E10_853F80);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80241E28_853F98);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80241E44_853FB4);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242318_854488);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242384_8544F4);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_802425E0_854750);
/*
s32 N(func_802425E0_854750)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (aiSettings != NULL) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
    }

    ptr = &D_80241CCC_BE0A5C;
    if (*ptr != NULL) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
        set_variable(script, *args, D_80241CD0_BE0A60);
        return 2;
    }

    return 0;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242634_8547A4);
/*
s32 N(func_80242634_8547A4)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_8024266C_8547DC);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242708_854878);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242A20_854B90);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242A64_854BD4);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242A90_854C00);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242C78_854DE8);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80242E84_854FF4);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80243088_8551F8);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_802430B4_855224);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_802431B0_855320);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80243254_8553C4);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_8024335C_8554CC);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_80243380_8554F0);

INCLUDE_ASM(s32, "world/area_mac/mac_05/852170", func_802433BC_85552C);
