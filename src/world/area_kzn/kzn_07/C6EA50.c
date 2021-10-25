#include "kzn_07.h"

INCLUDE_ASM(s32, "world/area_kzn/kzn_07/C6EA50", func_80240720_C6EA50);

INCLUDE_ASM(s32, "world/area_kzn/kzn_07/C6EA50", func_802407F4_C6EB24);

#include "world/common/UnkNpcAIFunc23.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_07/C6EA50", func_802409D0_C6ED00);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_07/C6EA50", func_80241474_C6F7A4);
/*
void N(func_80241474_C6F7A4)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80242B90_C70EC0)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}
*/

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_07/C6EA50", func_80241B2C_C6FE5C);
/*
ApiStatus N(func_80241B2C_C6FE5C)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = evt_get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(func_80241A08_C6FD38)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0]) {
        case 0:
#include "world/common/UnkNpcAIFunc23.inc.c"
        case 1:
            N(func_802409D0_C6ED00)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_802410B8_C6F3E8)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80241474_C6F7A4)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_80241678_C6F9A8)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
*/

#include "world/common/UnkNpcAIFunc13.inc.c"


INCLUDE_ASM(s32, "world/area_kzn/kzn_07/C6EA50", func_80241E48_C70178);
//#include "world/common/UnkNpcAIFunc34.inc.c"

#include "world/common/UnkFunc45.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_07/C6EA50", func_80242124_C70454);
