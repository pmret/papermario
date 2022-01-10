#include "mim_01.h"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

#include "world/common/UnkNpcAIFunc26.inc.c"

#include "world/common/UnkFunc7.inc.c"

#include "world/common/UnkNpcAIFunc27.inc.c"

#include "world/common/UnkNpcAIFunc31.inc.c"

#include "world/common/UnkNpcAIFunc32.inc.c"

#include "world/common/UnkNpcAIFunc46.inc.c"

#include "world/common/UnkNpcDurationFlagFunc3.inc.c"

#include "world/common/UnkNpcAIFunc33.inc.c"

#include "world/common/UnkNpcDurationFlagFunc2.inc.c"

#include "world/common/UnkNpcAIFunc30.inc.c"

ApiStatus func_80241C54_B95094(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;    
    NpcAISettings* settings = evt_get_variable(script, *script->ptrReadPos);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 200.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        enemy->varTable[0] = 0;

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc31)(script, settings, territoryPtr);
            /* fallthrough */
        case 1:
            N(UnkNpcAIFunc32)(script, settings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc46)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 11) {
                break;
            }
        case 11:
            N(UnkNpcDurationFlagFunc3)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 12) {
                break;
            }
        case 12:
            N(UnkNpcAIFunc33)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 13) {
                break;
            }
        case 13:
            N(UnkNpcDurationFlagFunc2)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 14) {
                break;
            }
        case 14:
            N(UnkNpcAIFunc30)(script, settings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
            break;
    }

    return ApiStatus_BLOCK;
}
