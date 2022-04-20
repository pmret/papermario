#include "pra_35.h"

#include "world/common/atomic/Reflection.inc.c"

#include "world/common/atomic/enemy/UnkAI_1.inc.c"

#include "world/common/MeleeHitbox_30.inc.c"

#include "world/common/MeleeHitbox_31.inc.c"

#include "world/common/MeleeHitbox_32.inc.c"

#include "world/common/MeleeHitbox_33.inc.c"

#include "world/common/MeleeHitbox_CanSeePlayer.inc.c"

#include "world/common/MeleeHitbox_Control.inc.c"

// Requires data migration
#ifdef NON_MATCHING
ApiStatus func_802423CC_D8F61C(Evt *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.halfHeight = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }
        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->functionTemp[0] < 30) && (enemy->varTable[0] == 0) && N(MeleeHitbox_CanSeePlayer)(script)) {
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
            pra_35_FlyingAI_12(script, npcAISettings, territoryPtr);
            // fallthrough
        case 13:
            pra_35_UnkFunc15(script, npcAISettings, territoryPtr);
            break;
        case 14:
            pra_35_UnkNpcDurationFlagFunc(script, npcAISettings, territoryPtr);
            break;
        case 30:
            pra_35_MeleeHitbox_30(script);
            // fallthrough
        case 31:
            pra_35_MeleeHitbox_31(script);
            if (script->functionTemp[0] != 32) {
                break;
            }
            // fallthrough
        case 32:
            pra_35_MeleeHitbox_32(script);
            if (script->functionTemp[0] != 33) {
                break;
            }
            // fallthrough
        case 33:
            pra_35_MeleeHitbox_33(script);
            break;
        case 99:
            basic_ai_suspend(script);
            break;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_pra/pra_35/D8D270", func_802423CC_D8F61C);
#endif

#include "world/common/MeleeHitbox_Main.inc.c"
