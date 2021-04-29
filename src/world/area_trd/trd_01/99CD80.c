#include "trd_01.h"

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_trd/trd_01/99CD80", func_8024046C_99CDFC);
/*
void N(func_8024046C_99CDFC)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
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

INCLUDE_ASM(s32, "world/area_trd/trd_01/99CD80", func_80240784_99D114);

INCLUDE_ASM(s32, "world/area_trd/trd_01/99CD80", func_80240BC4_99D554);

INCLUDE_ASM(s32, "world/area_trd/trd_01/99CD80", func_80240C78_99D608);

#include "world/common/NpcJumpFunc3.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13_2.inc.c"

#include "world/common/UnkNpcAIFunc11.inc.c"

#include "world/common/UnkNpcAIFunc10.inc.c"

INCLUDE_ASM(s32, "world/area_trd/trd_01/99CD80", func_80241104_99DA94);

INCLUDE_ASM(s32, "world/area_trd/trd_01/99CD80", func_802411B0_99DB40);

INCLUDE_ASM(s32, "world/area_trd/trd_01/99CD80", func_802413B8_99DD48);

INCLUDE_ASM(s32, "world/area_trd/trd_01/99CD80", func_80241630_99DFC0);
