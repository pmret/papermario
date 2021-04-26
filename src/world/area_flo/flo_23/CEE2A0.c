#include "flo_23.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_23/CEE2A0", func_8024026C_CEE4CC);
/*
ApiStatus N(func_8024026C_CEE4CC)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_8024130C_CEF56C) = FALSE;
    }

    if (N(D_8024130C_CEF56C)) {
        N(D_8024130C_CEF56C) = FALSE;
        set_variable(script, *args, N(D_80241310_CEF570));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_23/CEE2A0", func_802402C0_CEE520);
/*
ApiStatus N(func_802402C0_CEE520)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80241310_CEF570) = get_variable(script, *args);
    N(D_8024130C_CEF56C) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_23/CEE2A0", func_802402F8_CEE558);
/*
ApiStatus N(func_802402F8_CEE558)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[0x70] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_flo/flo_23/CEE2A0", func_80240410_CEE670);
/*
void N(func_80240410_CEE670)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
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

INCLUDE_ASM(s32, "world/area_flo/flo_23/CEE2A0", func_80240728_CEE988);

INCLUDE_ASM(s32, "world/area_flo/flo_23/CEE2A0", func_80240B68_CEEDC8);
/*
ApiStatus N(func_80240B68_CEEDC8)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemIdx = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    ItemEntity* item = get_item_entity(itemIdx);

    item->position.x = var1;
    item->position.y = var2;
    item->position.z = var3;

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_23/CEE2A0", func_80240C2C_CEEE8C);
/*
ApiStatus N(func_80240C2C_CEEE8C)(ScriptInstance *script, s32 isInitialCall) {
    s32 itemId = get_variable(script, *script->ptrReadPos);
    StaticItem* item = &gItemTable[itemId];

    if (itemId == ITEM_YUMMY_MEAL) {
        script->varTable[9] = 2;
    } else if (item->typeFlags & 0x80) {
        script->varTable[9] = 1;
    } else {
        script->varTable[9] = 0;
    }

    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_flo/flo_23/CEE2A0", func_80240C9C_CEEEFC);
/*
ApiStatus N(func_80240C9C_CEEEFC)(ScriptInstance *script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i < 0x5B; i++) {
        N(D_802429B8)[i] = 0x80 + i;
    }

    N(D_802429BC) = 0;
    return ApiStatus_DONE2;
}
*/
