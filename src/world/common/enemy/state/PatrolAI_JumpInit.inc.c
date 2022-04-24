#include "common.h"
#include "npc.h"

void N(PatrolAI_JumpInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_JUMP];
    npc->jumpVelocity = 10.0f;
    npc->jumpScale = 2.0f;
    npc->moveToPos.y = npc->pos.y;
    npc->flags |= NPC_FLAG_JUMPING;
    script->functionTemp[0] = AI_STATE_JUMP;
}
