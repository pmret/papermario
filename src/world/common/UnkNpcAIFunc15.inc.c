#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc15)(ScriptInstance* script, NpcAISettings* aiSettings, s32 arg2) {
    Npc* enemy = get_npc_unsafe(script->owner1.enemy->npcID);

    func_80049F7C(script, aiSettings, arg2);
    enemy->flags = enemy->flags | 0x800;
    enemy->jumpVelocity = rand_int(5) + 10.0;
    enemy->jumpScale = 1.5f;
    enemy->yaw = atan2(enemy->pos.x, enemy->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    enemy->moveSpeed = aiSettings->chaseSpeed;
    script->functionTemp[0] = 13;
    ai_enemy_play_sound(enemy, 0xB0000017, 0);
}
