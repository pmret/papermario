#include "common.h"
#include "npc.h"

s32 N(ProjectileHitbox_GetUsableProjectileID)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Camera* camera = &gCameras[gCurrentCamID];
    Npc* npc = get_npc_unsafe(enemy->npcID);
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);
    f32 facingAngle;
    f32 angleToPlayer;
    f32 deltaAngle;
    s32 i;

    if (ai_check_player_dist(enemy, 0, aiSettings->chaseRadius, aiSettings->unkChase)) {
        if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
            facingAngle = 90.0f;
        } else {
            facingAngle = 270.0f;
        }

        angleToPlayer = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        deltaAngle = get_clamped_angle_diff(facingAngle, angleToPlayer);
        if (fabsf(deltaAngle) > 75.0 || (2.0 * npc->collisionHeight <= fabsf(npc->pos.y - gPlayerStatusPtr->position.y))) {
           return -1;
        }
        if (gPartnerActionStatus.actingPartner == PARTNER_BOW) {
            return -1;
        }
        if (gPartnerActionStatus.actingPartner == PARTNER_SUSHIE) {
            return -1;
        }

        // choose the first idle projectile hitbox
        for (i = 0; i < enemy->VAR_PROJECTILE_COUNT; i++) {
            s32 projectileNpcID = enemy->npcID + i + 1;
            Enemy* projectileEnemy = get_enemy(projectileNpcID);

            get_npc_unsafe(projectileNpcID);

            if (projectileEnemy->VAR_PROJECTILE_HITBOX_STATE == 0) {
                return projectileNpcID;
            }
        }
    }
    return -1;
}
