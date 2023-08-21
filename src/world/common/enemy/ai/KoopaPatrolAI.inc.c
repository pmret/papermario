#include "common.h"
#include "npc.h"
#include "effects.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

#include "world/common/enemy/ai/States_TackleAI.inc.c"

API_CALLABLE(N(KoopaPatrolAI_Main)) {
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
        enemy->aiFlags |= ENEMY_AI_FLAG_8;
    }

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND)) {
        npc->duration = 0;
        script->functionTemp[0] = 0;
        enemy->hitboxIsActive = FALSE;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->flags &= ~NPC_FLAG_JUMPING;
        npc->collisionHeight = enemy->varTable[6];
        enemy->instigatorValue = 0;
        enemy->varTable[8] = 0;

        if (!enemy->territory->patrol.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_FLYING;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_FLYING;
        }

        if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
            EffectInstance* emoteTemp;

            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 40, &emoteTemp);
            enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        } else if (enemy->flags & ENEMY_FLAG_BEGIN_WITH_CHASING) {
            script->functionTemp[0] = AI_STATE_CHASE_INIT;
            enemy->flags &= ~ENEMY_FLAG_BEGIN_WITH_CHASING;
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
