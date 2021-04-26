#include "kpa_61.h"

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_8024038C_A6E76C);
/*
void N(func_8024038C_A6E76C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
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

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_802406A4_A6EA84);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80240AE4_A6EEC4);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80240CB4_A6F094);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_802411C4_A6F5A4);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241200_A6F5E0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_8024138C_A6F76C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_8024177C_A6FB5C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241870_A6FC50);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241AB4_A6FE94);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241AF0_A6FED0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241CBC_A7009C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241D28_A70108);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241E5C_A7023C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241F4C_A7032C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", update_heroes_start_turn_A70404);

#include "world/common/GetEncounterEnemyIsOwner.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_802422F0_A706D0);
