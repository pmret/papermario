#include "common.h"
#include "npc.h"

void N(HoppingAI_ChaseInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Npc* enemy = get_npc_unsafe(script->owner1.enemy->npcID);

    basic_ai_chase_init(script, aiSettings, territory);
    enemy->flags |= ENEMY_FLAGS_800;
    enemy->jumpVelocity = rand_int(5) + 10.0;
    enemy->jumpScale = 1.5f;
    enemy->yaw = atan2(enemy->pos.x, enemy->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    enemy->moveSpeed = aiSettings->chaseSpeed;
    script->AI_TEMP_STATE = 13;
    ai_enemy_play_sound(enemy, SOUND_B0000017, 0);
}
