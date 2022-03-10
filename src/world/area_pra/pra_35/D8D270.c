#include "pra_35.h"

#include "world/common/reflection.inc.c"

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

#include "world/common/UnkNpcAIMainFunc.inc.c"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

#include "world/common/UnkNpcAIFunc26.inc.c"

#include "world/common/UnkFunc7.inc.c"

// Requires data migration
#ifdef NON_MATCHING
ApiStatus func_802423CC_D8F61C(Evt *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->functionTemp[0] < 30) && (enemy->varTable[0] == 0) && N(UnkNpcAIFunc26)(script)) {
        script->functionTemp[0] = 30;
    }

    switch (script->functionTemp[0]) {
        case 0:
            pra_35_UnkNpcAIFunc24(script, npcAISettings, territoryPtr);
            // fallthrough
        case 1:
            pra_35_UnkFunc13(script, npcAISettings, territoryPtr);
            break;
        case 2:
            pra_35_UnkNpcAIFunc1(script, npcAISettings, territoryPtr);
            // fallthrough
        case 3:
            pra_35_UnkFunc14(script, npcAISettings, territoryPtr);
            break;
        case 7:
            pra_35_UnkNpcAIFunc25(script, npcAISettings, territoryPtr);
            break;
        case 5:
            pra_35_NpcJumpFunc2(script, npcAISettings, territoryPtr);
            // fallthrough
        case 11:
            pra_35_NpcJumpFunc(script, npcAISettings, territoryPtr);
            break;
        case 12:
            pra_35_UnkNpcAIFunc13(script, npcAISettings, territoryPtr);
            // fallthrough
        case 13:
            pra_35_UnkFunc15(script, npcAISettings, territoryPtr);
            break;
        case 14:
            pra_35_UnkNpcDurationFlagFunc(script, npcAISettings, territoryPtr);
            break;
        case 30:
            pra_35_UnkNpcAIFunc6(script);
            // fallthrough
        case 31:
            pra_35_UnkNpcAIFunc7(script);
            if (script->functionTemp[0] != 32) {
                break;
            }
            // fallthrough
        case 32:
            pra_35_UnkNpcAIFunc8(script);
            if (script->functionTemp[0] != 33) {
                break;
            }
            // fallthrough
        case 33:
            pra_35_UnkNpcAIFunc5(script);
            break;
        case 99:
            func_8004A73C(script);
            break;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_pra/pra_35/D8D270", func_802423CC_D8F61C);
#endif

#include "world/common/UnkNpcAIFunc27.inc.c"
