#include "kpa_03.h"

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_802401DC_A4879C);
/*
void N(func_802401DC_A4879C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
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

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_802404F4_A48AB4);

#include "world/common/AwaitPlayerNearNpc.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80240A48_A49008);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80240C18_A491D8);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241128_A496E8);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_8024119C_A4975C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_802412C8_A49888);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241368_A49928);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_802413CC_A4998C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_8024150C_A49ACC);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_802416B0_A49C70);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_802416EC_A49CAC);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_802418AC_A49E6C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241918_A49ED8);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241A4C_A4A00C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241AB4_A4A074);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241D20_A4A2E0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241D6C_A4A32C);

#include "world/common/GetEncounterEnemyIsOwner.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_03/A48720", func_80241DFC_A4A3BC);
