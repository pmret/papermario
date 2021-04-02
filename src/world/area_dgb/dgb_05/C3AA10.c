#include "dgb_05.h"

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_80240000_C3AA10);

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_80240030_C3AA40);

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_80240268_C3AC78);

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_8024041C_C3AE2C);

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_8024067C_C3B08C);

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_80240704_C3B114);

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_802409BC_C3B3CC);

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_80240A20_C3B430);

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_80240AC8_C3B4D8);

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_80240C00_C3B610);
/*
void N(func_80240C00_C3B610)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_80240CAC_C3B6BC);

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_80240E24_C3B834);

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_80240E80_C3B890);

INCLUDE_ASM(s32, "world/area_dgb/dgb_05/C3AA10", func_802411D0_C3BBE0);
