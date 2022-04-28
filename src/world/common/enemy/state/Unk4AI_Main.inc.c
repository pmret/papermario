#include "common.h"
#include "npc.h"

ApiStatus N(Unk4AI_Main)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);

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
        enemy->varTable[0] = npc->yaw;
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
        npc->flags &= ~NPC_FLAG_JUMPING;

        if (!(enemy->territory->wander.isFlying)) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }

        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->AI_TEMP_STATE = 99;
            script->functionTemp[1] = 15;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->AI_TEMP_STATE = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    switch (script->AI_TEMP_STATE) {
        case 0:
            N(Unk4AI_00)(script, aiSettings, territoryPtr);
        case 1:
            N(Unk4AI_01)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(Unk4AI_10)(script, aiSettings, territoryPtr);
        case 11:
            N(Unk4AI_11)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(Unk4AI_12)(script, aiSettings, territoryPtr);
        case 13:
            N(Unk4AI_13)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(Unk4AI_14)(script, aiSettings, territoryPtr);
            break;
        case 15:
            N(Unk4AI_15)(script, aiSettings, territoryPtr);
        case 16:
            N(Unk4AI_16)(script, aiSettings, territoryPtr);
            break;
        case 99:
            basic_ai_suspend(script);
            break;
    }
    return ApiStatus_BLOCK;
}
