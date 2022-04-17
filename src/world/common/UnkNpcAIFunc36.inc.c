#include "common.h"
#include "npc.h"
#include "effects.h"

void N(UnkNpcAIFunc36)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z;

    basic_ai_wander_init(script, aiSettings, territory);
    npc->flags |= NPC_FLAG_JUMPING;
    npc->jumpVelocity = (rand_int(45) / 10.0) + 8.0;
    npc->jumpScale = 1.5f;
    ai_enemy_play_sound(npc, 0xB0000017, 0);
    
    if (is_point_within_region(enemy->territory->wander.wanderShape, 
                               enemy->territory->wander.point.x, 
                               enemy->territory->wander.point.z, 
                               npc->pos.x, npc->pos.z, 
                               enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ) != 0) 
    {
        s32 i;

        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        x = npc->pos.x;
        y = npc->pos.y;
        z = npc->pos.z;

        for (i = 0; i < 6; i++) {
            if (npc_test_move_simple_with_slipping(npc->collisionChannel, &x, &y, &z, 25.0f, 
                                                   npc->yaw, npc->collisionHeight, npc->collisionRadius)) 
            {
                npc->yaw += 30.0;
            } else {
                break;
            }
        }
    } else {
        npc->yaw = clamp_angle(npc->yaw + rand_int(60) - 30.0f);
    }
}
