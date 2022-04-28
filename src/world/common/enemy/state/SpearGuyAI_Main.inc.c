#include "common.h"
#include "npc.h"

ApiStatus N(SpearGuyAI_Main)(Evt *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        script->AI_TEMP_STATE = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
        npc->flags &= ~0x800;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->AI_TEMP_STATE = 99;
            script->functionTemp[1] = 0;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->AI_TEMP_STATE < 30) && (enemy->varTable[0] == 0) && N(MeleeHitbox_CanSeePlayer)(script)) {
        script->AI_TEMP_STATE = 30;
    }

    switch (script->AI_TEMP_STATE) {
        case 0:
            basic_ai_wander_init(script, npcAISettings, territoryPtr);
        case 1:
            basic_ai_wander(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(SpearGuyAI_02)(script, npcAISettings, territoryPtr);
        case 3:
            N(SpearGuyAI_03)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            basic_ai_found_player_jump_init(script, npcAISettings, territoryPtr);
        case 11:
            basic_ai_found_player_jump(script, npcAISettings, territoryPtr);
            break;
        case 12:
            basic_ai_chase_init(script, npcAISettings, territoryPtr);
        case 13:
            basic_ai_chase(script, npcAISettings, territoryPtr);
            break;
        case 14:
            basic_ai_lose_player(script, npcAISettings, territoryPtr);
            break;
        case 30:
            N(MeleeHitbox_30)(script);
        case 31:
            N(MeleeHitbox_31)(script);
            if (script->AI_TEMP_STATE != 32) {
                break;
            }
        case 32:
            N(MeleeHitbox_32)(script);
            if (script->AI_TEMP_STATE != 33) {
                break;
            }
        case 33:
            N(MeleeHitbox_33)(script);
            break;
        case 99:
            basic_ai_suspend(script);
    }

    return ApiStatus_BLOCK;
}
