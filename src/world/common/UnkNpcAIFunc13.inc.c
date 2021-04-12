#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc13)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 tempAngle;
    f32 angleDiff;

    npc->duration = (aiSettings->unk_20 / 2) + rand_int(aiSettings->unk_20 / 2 + 1);
    npc->currentAnim = enemy->animList[3];
    npc->moveSpeed = aiSettings->chaseSpeed;

    tempAngle = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    angleDiff = get_clamped_angle_diff(npc->yaw, tempAngle);

    if (aiSettings->unk_1C.s < fabsf(angleDiff)) {
        tempAngle = npc->yaw;

        if (angleDiff < 0.0f) {
            tempAngle += -aiSettings->unk_1C.s;
        } else {
            tempAngle += aiSettings->unk_1C.s;
        }
    }

    npc->yaw = clamp_angle(tempAngle);
    script->functionTemp[0].s = 13;
}
