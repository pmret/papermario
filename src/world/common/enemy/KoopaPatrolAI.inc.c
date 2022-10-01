#include "common.h"
#include "npc.h"
#include "effects.h"

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

#include "world/common/enemy/States_TackleAI.inc.c"

ApiStatus N(KoopaPatrolAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* settings = (MobileAISettings*) evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detectPos.x;
    territory.pointZ = enemy->territory->patrol.detectPos.z;
    territory.sizeX = enemy->territory->patrol.detectSize.x;
    territory.sizeZ = enemy->territory->patrol.detectSize.z;
    territory.halfHeight = 100.0f;
    territory.detectFlags = 0;

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->aiFlags |= ENEMY_AI_FLAGS_8;
    }

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        npc->duration = 0;
        script->functionTemp[0] = 0;
        enemy->unk_07 = 0;
        npc->currentAnim = enemy->animList[ENEMY_ANIM_IDLE];
        npc->flags &= ~NPC_FLAG_JUMPING;
        npc->collisionHeight = enemy->varTable[6];
        enemy->unk_B5 = 0;
        enemy->varTable[8] = 0;

        if (!enemy->territory->patrol.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }

        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            s32 emoteTemp;

            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 40, &emoteTemp);
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(PatrolAI_MoveInit)(script, settings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
            // fallthrough
        case 1:
            N(PatrolAI_Move)(script, settings, territoryPtr);
            break;
        case 2:
            N(PatrolAI_LoiterInit)(script, settings, territoryPtr);
             // fallthrough
        case 3:
            N(PatrolAI_Loiter)(script, settings, territoryPtr);
            break;
        case 4:
            N(PatrolAI_PostLoiter)(script, settings, territoryPtr);
            break;
        case 12:
            N(set_script_owner_npc_anim)(script, settings, territoryPtr);
             // fallthrough
        case 13:
            N(UnkDistFunc)(script, settings, territoryPtr);
            break;
        case 14:
            N(UnkNpcAIFunc12)(script, settings, territoryPtr);
            break;
        case 15:
            N(set_script_owner_npc_col_height)(script, settings, territoryPtr);
            break;
        case 99:
            basic_ai_suspend(script);
            break;
    }
    return ApiStatus_BLOCK;
}
