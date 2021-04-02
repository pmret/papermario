#include "dgb_16.h"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_dgb/dgb_16/C52540", func_80240208_C52748);

INCLUDE_ASM(s32, "world/area_dgb/dgb_16/C52540", update_starpoints_display_C528FC);

INCLUDE_ASM(s32, "world/area_dgb/dgb_16/C52540", func_8024061C_C52B5C);

INCLUDE_ASM(s32, "world/area_dgb/dgb_16/C52540", func_802406A4_C52BE4);

INCLUDE_ASM(s32, "world/area_dgb/dgb_16/C52540", func_8024095C_C52E9C);

INCLUDE_ASM(s32, "world/area_dgb/dgb_16/C52540", func_802409C0_C52F00);

INCLUDE_ASM(s32, "world/area_dgb/dgb_16/C52540", func_80240A68_C52FA8);

INCLUDE_ASM(s32, "world/area_dgb/dgb_16/C52540", func_80240BA0_C530E0);
/*
void N(func_80240BA0_C530E0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
        script->functionTemp[0].s = 0x29;
    }
}
*/

INCLUDE_ASM(s32, "world/area_dgb/dgb_16/C52540", func_80240C4C_C5318C);

INCLUDE_ASM(s32, "world/area_dgb/dgb_16/C52540", func_80240DC4_C53304);

INCLUDE_ASM(s32, "world/area_dgb/dgb_16/C52540", func_80240E20_C53360);

INCLUDE_ASM(s32, "world/area_dgb/dgb_16/C52540", func_80241170_C536B0);
