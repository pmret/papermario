#include "iwa_02.h"

static char* N(exit_str_0) = "iwa_01";
static char* N(exit_str_1) = "iwa_04";

INCLUDE_ASM(s32, "world/area_iwa/iwa_02/915D70", func_80240000_915D70);

#include "world/common/UnkNpcAIFunc18.inc.c"

INCLUDE_ASM(s32, "world/area_iwa/iwa_02/915D70", func_802401D4_915F44);
/*
void N(func_802401D4_915F44)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = aiSettings->unk_14;
        if (func_800490B4(territory, enemy, aiSettings->alertRadius * 0.85, aiSettings->unk_10.f, 0)) {
            npc->currentAnim = enemy->animList[9];
            fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
            ai_enemy_play_sound(npc, 0x2F4, 0x200000);
            npc->duration = 12;
            script->functionTemp[0] = 2;
        }
    }

    script->functionTemp[1]--;
}
*/

#include "world/common/UnkNpcAIFunc21.inc.c"

#include "world/common/UnkNpcAIFunc20.inc.c"

#include "world/common/UnkNpcAIFunc22.inc.c"

#include "world/common/UnkFunc8.inc.c"

#include "world/common/UnkNpcAIFunc16.inc.c"

INCLUDE_ASM(s32, "world/area_iwa/iwa_02/915D70", func_80240694_916404);
/*
void N(func_80240694_916404)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    PlayerStatus** playerStatus = &gPlayerStatusPtr;

    npc->yaw = atan2(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z);
    if (npc->duration % 3 == 0) {
        fx_walk(2, npc->pos.x, npc->pos.y, npc->pos.z + 2.0f, 0, 0);
    }

    npc->duration--;
    if (npc->duration <= 0) {
        playerStatus = &gPlayerStatusPtr;

        enemy->unk_10.x = npc->pos.x;
        enemy->unk_10.y = npc->pos.y;
        enemy->unk_10.z = npc->pos.z;
        enemy->unk_07 = 1;
        npc->moveSpeed = aiSettings->chaseSpeed;
        npc->duration = dist2D(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z) / npc->moveSpeed + 0.9;
        if (npc->duration < 15) {
            npc->duration = 15;
        }
        script->functionTemp[0] = 0x16;
    }
}
*/

#include "world/common/UnkFunc10.inc.c"

INCLUDE_ASM(s32, "world/area_iwa/iwa_02/915D70", func_80240984_9166F4);
/*
void N(func_80240984_9166F4)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->currentAnim = enemy->animList[1];
        if (enemy->territory->wander.moveSpeedOverride < 0) {
            npc->moveSpeed = aiSettings->moveSpeed;
        } else {
            npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
        }
        script->functionTemp[0] = 0x29;
    }
}
*/

#include "world/common/UnkFunc9.inc.c"

#include "world/common/UnkNpcAIFunc19.inc.c"

#include "world/common/UnkNpcAIFunc17.inc.c"

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_iwa/iwa_02/915D70", func_80240C90_916A00);

INCLUDE_ASM(s32, "world/area_iwa/iwa_02/915D70", func_80240FE0_916D50);
/*
ApiStatus N(func_80240FE0_916D50)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80241DA8_917B18) == NULL) {
        N(D_80241DA8_917B18) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80241DA8_917B18)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80241DA8_917B18)[i];
        }
        heap_free(N(D_80241DA8_917B18));
        N(D_80241DA8_917B18) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"
