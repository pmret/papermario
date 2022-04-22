#include "common.h"
#include "npc.h"
#include "dead_structs.h"

ApiStatus N(DeadUnkNpcAIMainFunc)(Evt* script, s32 isInitialCall) {
    DeadEnemy* enemy = (DeadEnemy*)script->owner1.enemy;
    Npc* npc = dead_get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.halfHeight = 65.0f;
    territory.unk_1C = 0;

    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.0001f;
    enemy->unk_118 = 0.0001f;

    if (isInitialCall || enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }
    
    switch (script->functionTemp[0]) {
    case 0x0:
        N(PatrolAI_MoveInit)(script, npcAISettings, territoryPtr);
        /* fallthrough */
    case 0x1:
        N(PatrolAI_Move)(script, npcAISettings, territoryPtr);
        break;
    case 0x2:
        N(PatrolAI_LoiterInit)(script, npcAISettings, territoryPtr);
        /* fallthrough */
    case 0x3:
        N(PatrolAI_Loiter)(script, npcAISettings, territoryPtr);
        break;
    case 0x4:
        N(PatrolAI_PostLoiter)(script, npcAISettings, territoryPtr);
        break;
    case 0xA:
        N(PatrolAI_JumpInit)(script, npcAISettings, territoryPtr);
        /* fallthrough */
    case 0xB:
        N(PatrolAI_Jump)(script, npcAISettings, territoryPtr);
        break;
    case 0xC:
        N(FlyingNoFirstStrikeAI_12)(script, npcAISettings, territoryPtr);
        /* fallthrough */
    case 0xD:
        N(PatrolAI_Chase)(script, npcAISettings, territoryPtr);
        break;
    case 0xE:
        N(PatrolAI_LosePlayer)(script, npcAISettings, territoryPtr);
        break;
    case 0xF:
        N(UnkFunc16)(script, npcAISettings, territoryPtr);
        break;
    case 0x63:
        dead_basic_ai_suspend(script);
        break;
    }
    return 0;
}
