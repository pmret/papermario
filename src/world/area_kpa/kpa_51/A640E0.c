#include "kpa_51.h"

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80240050_A640E0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80240220_A642B0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80240730_A647C0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_802407A4_A64834);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_802408D0_A64960);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80240970_A64A00);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_802409D4_A64A64);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80240B14_A64BA4);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80240CB8_A64D48);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80240CF4_A64D84);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80240EB4_A64F44);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80240F20_A64FB0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80241054_A650E4);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_802410BC_A6514C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80241328_A653B8);

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80241374_A65404);

#include "world/common/GetEncounterEnemyIsOwner.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_80241404_A65494);

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_802414C8_A65558);
/*
void N(func_802414C8_A65558)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
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

INCLUDE_ASM(s32, "world/area_kpa/kpa_51/A640E0", func_802417E0_A65870);
