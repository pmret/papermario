#include "kpa_50.h"

INCLUDE_ASM(s32, "world/area_kpa/kpa_50/A609D0", func_80240000_A609D0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_50/A609D0", func_802401F0_A60BC0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_50/A609D0", func_80240334_A60D04);

#include "world/common/UnkSetDurationFunc.inc.c"

#include "world/common/UnkNpcAIFunc9.inc.c"

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_50/A609D0", func_8024055C_A60F2C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_50/A609D0", func_80240A98_A61468);

INCLUDE_ASM(s32, "world/area_kpa/kpa_50/A609D0", func_80240EF4_A618C4);

#include "world/common/GetEncounterEnemyIsOwner.inc.c"

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_50/A609D0", func_802412C8_A61C98);
/*
void N(func_802412C8_A61C98)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
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

INCLUDE_ASM(s32, "world/area_kpa/kpa_50/A609D0", func_802415E0_A61FB0);
