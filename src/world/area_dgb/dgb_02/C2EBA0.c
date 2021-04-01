#include "dgb_02.h"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_dgb/dgb_02/C2EBA0", func_80240208_C2EDA8);

INCLUDE_ASM(s32, "world/area_dgb/dgb_02/C2EBA0", update_starpoints_display_C2EF5C);

INCLUDE_ASM(s32, "world/area_dgb/dgb_02/C2EBA0", func_8024061C_C2F1BC);

INCLUDE_ASM(s32, "world/area_dgb/dgb_02/C2EBA0", func_802408D0_C2F470);

INCLUDE_ASM(s32, "world/area_dgb/dgb_02/C2EBA0", func_80240958_C2F4F8);

INCLUDE_ASM(s32, "world/area_dgb/dgb_02/C2EBA0", func_80240C10_C2F7B0);

INCLUDE_ASM(s32, "world/area_dgb/dgb_02/C2EBA0", func_80240C74_C2F814);

INCLUDE_ASM(s32, "world/area_dgb/dgb_02/C2EBA0", func_80240D1C_C2F8BC);

INCLUDE_ASM(s32, "world/area_dgb/dgb_02/C2EBA0", func_80240E54_C2F9F4);
/*
void N(func_80240E54_C2F9F4)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
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

INCLUDE_ASM(s32, "world/area_dgb/dgb_02/C2EBA0", func_80240F00_C2FAA0);

INCLUDE_ASM(s32, "world/area_dgb/dgb_02/C2EBA0", func_80241078_C2FC18);

INCLUDE_ASM(s32, "world/area_dgb/dgb_02/C2EBA0", func_802410D4_C2FC74);