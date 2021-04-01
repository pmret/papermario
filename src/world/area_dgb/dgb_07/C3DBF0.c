#include "dgb_07.h"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_dgb/dgb_07/C3DBF0", func_80240208_C3DDF8);

INCLUDE_ASM(s32, "world/area_dgb/dgb_07/C3DBF0", update_starpoints_display_C3DFAC);

INCLUDE_ASM(s32, "world/area_dgb/dgb_07/C3DBF0", func_8024061C_C3E20C);

INCLUDE_ASM(s32, "world/area_dgb/dgb_07/C3DBF0", func_802406A4_C3E294);

INCLUDE_ASM(s32, "world/area_dgb/dgb_07/C3DBF0", func_8024095C_C3E54C);

INCLUDE_ASM(s32, "world/area_dgb/dgb_07/C3DBF0", func_802409C0_C3E5B0);

INCLUDE_ASM(s32, "world/area_dgb/dgb_07/C3DBF0", func_80240A68_C3E658);

INCLUDE_ASM(s32, "world/area_dgb/dgb_07/C3DBF0", func_80240BA0_C3E790);
/*
void N(func_80240BA0_C3E790)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing* shape) {
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

INCLUDE_ASM(s32, "world/area_dgb/dgb_07/C3DBF0", func_80240C4C_C3E83C);

INCLUDE_ASM(s32, "world/area_dgb/dgb_07/C3DBF0", func_80240DC4_C3E9B4);

INCLUDE_ASM(s32, "world/area_dgb/dgb_07/C3DBF0", func_80240E20_C3EA10);

INCLUDE_ASM(s32, "world/area_dgb/dgb_07/C3DBF0", func_80241170_C3ED60);