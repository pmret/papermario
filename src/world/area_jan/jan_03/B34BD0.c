#include "jan_03.h"

#define UNK_ALPHA_FUNC_NPC 17

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80240034_B34C04);

#include "world/common/GetEntryPos.inc.c"

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802405EC_B351BC);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80240620_B351F0);
/*
s32 N(func_80240620_B351F0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80240778_B35348);
/*
void N(func_80240778_B35348)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80240AE0_B356B0);
/*
void N(func_80240AE0_B356B0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80240C9C_B3586C);
/*
s32 N(func_80240C9C_B3586C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80240F6C_B35B3C);
/*
s32 N(func_80240F6C_B35B3C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802410F4_B35CC4);
/*
void N(func_802410F4_B35CC4)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802411B4_B35D84);

#include "world/common/Call800E9894.inc.c"

#include "world/common/Call800E98C4SyncStatusMenu.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802414F8_B360C8);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241574_B36144);

#include "world/common/AwaitScriptComplete.inc.c"

#include "world/common/PartnerToggleAbilityScript.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241670_B36240);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802416C4_B36294);

#include "world/common/GetPartnerCall800EB168.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802417A4_B36374);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802419D8_B365A8);
/*
s32 N(func_802419D8_B365A8)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241A2C_B365FC);
/*
s32 N(func_80241A2C_B365FC)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241A64_B36634);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241B00_B366D0);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241B9C_B3676C);
/*
s32 N(func_80241B9C_B3676C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241CD8_B368A8);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241EFC_B36ACC);

#include "world/common/GetNpcUnsafeOwner2.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80241F68_B36B38);

#include "world/common/UnkAlphaFunc.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242114_B36CE4);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242288_B36E58);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_8024230C_B36EDC);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242524_B370F4);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802425D8_B371A8);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_8024260C_B371DC);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_8024268C_B3725C);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802426A4_B37274);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_802426C0_B37290);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242B94_B37764);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242C00_B377D0);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242EAC_B37A7C);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242EF0_B37AC0);

INCLUDE_ASM(s32, "world/area_jan/jan_03/B34BD0", func_80242F1C_B37AEC);
