#include "common.h"
#include "npc.h"

void N(Unk4AI_12)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 tempAngle;
    f32 angleDiff;

    npc->duration = (aiSettings->playerSearchInterval / 2) + rand_int(aiSettings->playerSearchInterval / 2 + 1);
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_CHASE];
    npc->moveSpeed = aiSettings->alertRadius;

    tempAngle = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    angleDiff = get_clamped_angle_diff(npc->yaw, tempAngle);

    if (aiSettings->alertOffsetDist.s < fabsf(angleDiff)) {
        tempAngle = npc->yaw;

        if (angleDiff < 0.0f) {
            tempAngle += -aiSettings->alertOffsetDist.s;
        } else {
            tempAngle += aiSettings->alertOffsetDist.s;
        }
    }

    npc->yaw = clamp_angle(tempAngle);
    script->functionTemp[0] = 13;
}
