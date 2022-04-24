#include "common.h"
#include "npc.h"

// selects the next patrol point
void N(PatrolAI_MoveInit)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 ret;
    f32 max;
    f32 posX;
    f32 posZ;
    s32 i;
    s32 j;
    s32 x, z;

    script->functionTemp[1] = 0;
    max = 32767.0f;
    posX = npc->pos.x;
    posZ = npc->pos.z;
    script->AI_PATROL_GOAL_INDEX = 0;

    for (i = 0, j = 0; i < enemy->territory->patrol.numPoints; i++, j++) {
        //TODO strange match -- index and array are backwards!
        x = i[enemy->territory->patrol.points].x;
        z = i[enemy->territory->patrol.points].z;
        ret = dist2D(posX, posZ, x, z);
        if (ret < max) {
            max = ret;
            script->AI_PATROL_GOAL_INDEX = j;
        }
    }

    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_WALK];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }

    script->AI_TEMP_STATE = AI_STATE_PATROL;
}
